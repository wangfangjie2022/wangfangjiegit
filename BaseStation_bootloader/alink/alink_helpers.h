#ifndef  _ALINK_HELPERS_H_
#define  _ALINK_HELPERS_H_

#include "string.h"
#include "checksum.h"
#include "alink_types.h"
#include "alink.h"
//#include "alink_conversions.h"

#ifndef ALINK_HELPER
#define ALINK_HELPER
#endif

/*
 * Internal function to give access to the channel status for each channel
 */
#ifndef ALINK_GET_CHANNEL_STATUS
ALINK_HELPER alink_status_t* alink_get_channel_status(uint8_t chan)
{
#ifdef ALINK_EXTERNAL_RX_STATUS
	// No m_alink_status array defined in function,
	// has to be defined externally
#else
	static alink_status_t m_alink_status[ALINK_COMM_NUM_BUFFERS];
#endif
	return &m_alink_status[chan];
}
#endif

/*
 * Internal function to give access to the channel buffer for each channel
 */
#ifndef ALINK_GET_CHANNEL_BUFFER
ALINK_HELPER alink_message_head_t* alink_get_channel_buffer(uint8_t chan)
{

#ifdef ALINK_EXTERNAL_RX_BUFFER
	// No m_alink_buffer array defined in function,
	// has to be defined externally
#else
	static alink_message_head_t m_alink_buffer[ALINK_COMM_NUM_BUFFERS];
#endif
	return &m_alink_buffer[chan];
}
#endif

/**
 * @brief Reset the status of a channel.
 */
ALINK_HELPER void alink_reset_channel_status(uint8_t chan)
{
	alink_status_t *status = alink_get_channel_status(chan);
	status->parse_state = ALINK_PARSE_STATE_IDLE;
}

/**
 * @brief Finalize a ALink message with channel assignment
 *
 * This function calculates the checksum and sets length and aircraft id correctly.
 * It assumes that the message id and the payload are already correctly set. This function
 * can also be used if the message header has already been written before (as in alink_msg_xxx_pack
 * instead of alink_msg_xxx_pack_headerless), it just introduces little extra overhead.
 *
 * @param msg Message to finalize
 * @param dest_id Id of the sending (this) system, 1-127
 * @param length Message length
 */
#if ALINK_CRC_EXTRA
ALINK_HELPER uint16_t alink_finalize_message_chan(alink_message_head_t* msg, uint8_t dest_id, uint8_t source_id,
						      uint8_t chan, uint16_t length, uint8_t crc_extra)
#else
ALINK_HELPER uint16_t alink_finalize_message_chan(alink_message_head_t* msg, uint8_t dest_id, uint8_t source_id,
						      uint8_t chan, uint16_t length)
#endif
{
	// This code part is the same for all messages;
	msg->magic = ALINK_STX;
	msg->checksum = ALINK_STX;
	msg->len_lo = length & 0xff;
	msg->checksum += msg->len_lo;
	msg->len_hi = (length >> 8) & 0xff;
	msg->checksum += msg->len_hi;
	msg->destid = dest_id;
	msg->checksum += msg->destid;
	msg->sourceid = source_id;
	msg->checksum += msg->sourceid;

	msg->len = length;

	// One sequence number per channel
	msg->seq = alink_get_channel_status(chan)->current_tx_seq[dest_id];
	msg->checksum += msg->seq;
	msg->checksum += msg->msgid;

	alink_get_channel_status(chan)->current_tx_seq[dest_id] = msg->seq + 1;
	msg->crc = crc_calculate(((const uint8_t*)(msg)) + 5, ALINK_CORE_HEADER_LEN);
	crc_accumulate_buffer(&msg->crc, _MAV_PAYLOAD(msg), msg->len);

#if ALINK_CRC_EXTRA
	crc_accumulate(crc_extra, &msg->crc);
#endif

	alink_ck_a(msg) = (uint8_t)(msg->crc & 0xFF);
	alink_ck_b(msg) = (uint8_t)(msg->crc >> 8);

	return length + ALINK_NUM_NON_PAYLOAD_BYTES;
}


/**
 * @brief Finalize a ALink message with ALINK_COMM_0 as default channel
 */
#if ALINK_CRC_EXTRA
ALINK_HELPER uint16_t alink_finalize_message(alink_message_head_t* msg, uint8_t dest_id, uint8_t source_id,
						 uint16_t length, uint8_t crc_extra)
{
	return alink_finalize_message_chan(msg, dest_id, source_id, ALINK_COMM_0, length, crc_extra);
}
#else
ALINK_HELPER uint16_t alink_finalize_message(alink_message_head_t* msg, uint8_t dest_id, uint8_t source_id,
						uint16_t length)
{
	return alink_finalize_message_chan(msg, dest_id, source_id, ALINK_COMM_0, length);
}
#endif

/**
 * @brief Pack a message to send it over a serial byte stream
 */
ALINK_HELPER uint16_t alink_msg_to_send_buffer(uint8_t *buffer, const alink_message_head_t *msg)
{
	memcpy(buffer, (const uint8_t *)&msg->magic, ALINK_NUM_HEADER_BYTES + (uint16_t)msg->len);

	uint8_t *ck = buffer + (ALINK_NUM_HEADER_BYTES + (uint16_t)msg->len);

	ck[0] = (uint8_t)(msg->crc & 0xFF);
	ck[1] = (uint8_t)(msg->crc >> 8);

	return ALINK_NUM_NON_PAYLOAD_BYTES + (uint16_t)msg->len;
}

union __alink_bitfield {
	uint8_t uint8;
	int8_t int8;
	uint16_t uint16;
	int16_t int16;
	uint32_t uint32;
	int32_t int32;
};


ALINK_HELPER void alink_start_crc(alink_message_head_t* msg)
{
	crc_init(&msg->crc);
}

ALINK_HELPER void alink_update_crc(alink_message_head_t* msg, uint8_t c)
{
	crc_accumulate(c, &msg->crc);
}

        /*
	  default message crc function. You can override this per-system to
	  put this data in a different memory segment
	*/
#if ALINK_CRC_EXTRA
#ifndef ALINK_MESSAGE_CRC
static const uint8_t alink_message_crcs[256] = ALINK_MESSAGE_CRCS;
#define ALINK_MESSAGE_CRC(msgid) alink_message_crcs[msgid]
#endif
#endif

/**
 * This is a varient of alink_frame_char() but with caller supplied
 * parsing buffers. It is useful when you want to create a ALink
 * parser in a library that doesn't use any global variables
 *
 * @param rxmsg    parsing message buffer
 * @param status   parsing starus buffer
 * @param c        The char to parse
 *
 * @param returnMsg NULL if no message could be decoded, the message data else
 * @param returnStats if a message was decoded, this is filled with the channel's stats
 * @return 0 if no message could be decoded, 1 on good message and CRC, 2 on bad CRC
 *
 * A typical use scenario of this function call is:
 *
 * @code
 * #include <mavlink.h>
 *
 * alink_message_head_t msg;
 * int chan = 0;
 *
 *
 * while(serial.bytesAvailable > 0)
 * {
 *   uint8_t byte = serial.getNextByte();
 *   if (alink_frame_char(chan, byte, &msg) != ALINK_FRAMING_INCOMPLETE)
 *     {
 *     printf("Received message with ID %d, sequence: %d from component %d of system %d", msg.msgid, msg.seq, msg.compid, msg.sysid);
 *     }
 * }
 *
 *
 * @endcode
 */
ALINK_HELPER uint8_t alink_frame_char_buffer(alink_message_head_t* rxmsg,
                                                 alink_status_t* status,
                                                 uint8_t c,
                                                 alink_message_head_t* r_message,
                                                 alink_status_t* r_alink_status)
{

	/* Enable this option to check the length of each message.
	   This allows invalid messages to be caught much sooner. Use if the transmission
	   medium is prone to missing (or extra) characters (e.g. a radio that fades in
	   and out). Only use if the channel will only contain messages types listed in
	   the headers.
	*/
#ifdef ALINK_CHECK_MESSAGE_LENGTH
#ifndef ALINK_MESSAGE_LENGTH
	static const uint8_t alink_message_lengths[256] = ALINK_MESSAGE_LENGTHS;
#define ALINK_MESSAGE_LENGTH(msgid) alink_message_lengths[msgid]
#endif
#endif

	int bufferIndex = 0;

	status->msg_received = ALINK_FRAMING_INCOMPLETE;

	switch (status->parse_state)
	{
	case ALINK_PARSE_STATE_UNINIT:
	case ALINK_PARSE_STATE_IDLE:
		if (c == ALINK_STX)
		{
			status->parse_state = ALINK_PARSE_STATE_GOT_STX;
			rxmsg->len = 0;
			rxmsg->magic = c;
			alink_start_crc(rxmsg);
			rxmsg->checksum = c;
		}
		break;

	case ALINK_PARSE_STATE_GOT_STX:
			if (status->msg_received
/* Support shorter buffers than the
   default maximum packet size */
#if (ALINK_MAX_PAYLOAD_LEN < 255)
				|| c > ALINK_MAX_PAYLOAD_LEN
#endif
				)
		{
			status->buffer_overrun++;
			status->parse_error++;
			status->msg_received = 0;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
		}
		else
		{
			// NOT counting STX, LENGTH, SEQ, SYSID, COMPID, MSGID, CRC1 and CRC2
			rxmsg->len_lo = c;
			status->packet_idx = 0;
			alink_update_crc(rxmsg, c);
			rxmsg->checksum += c;
			status->parse_state = ALINK_PARSE_STATE_GOT_LENGTH_LO;
		}
		break;
	case ALINK_PARSE_STATE_GOT_LENGTH_LO:
		rxmsg->len_hi = c;
		rxmsg->len = (rxmsg->len_hi << 8) + rxmsg->len_lo;
		if (rxmsg->len > ALINK_MAX_PAYLOAD_LEN) {
			status->parse_error++;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
			break;
		}
		alink_update_crc(rxmsg, c);
		rxmsg->checksum += c;
		status->parse_state = ALINK_PARSE_STATE_GOT_LENGTH_HI;
		break;

	case ALINK_PARSE_STATE_GOT_LENGTH_HI :
		rxmsg->seq = c;
		alink_update_crc(rxmsg, c);
		rxmsg->checksum += c;
		status->parse_state = ALINK_PARSE_STATE_GOT_SEQ;
		break;

	case ALINK_PARSE_STATE_GOT_SEQ:
		rxmsg->destid = c;
		alink_update_crc(rxmsg, c);
		rxmsg->checksum += c;
		status->parse_state = ALINK_PARSE_STATE_GOT_DESTID;
		break;

	case ALINK_PARSE_STATE_GOT_DESTID:
		rxmsg->sourceid = c;
		alink_update_crc(rxmsg, c);
		rxmsg->checksum += c;
		status->parse_state = ALINK_PARSE_STATE_GOT_SOURCEID;
		break;

	case ALINK_PARSE_STATE_GOT_SOURCEID:
#ifdef ALINK_CHECK_MESSAGE_LENGTH
	        if (rxmsg->len != ALINK_MESSAGE_LENGTH(c))
		{
			status->parse_error++;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
			break;
	    }
#endif
		rxmsg->msgid = c;
		alink_update_crc(rxmsg, c);
		rxmsg->checksum += c;
		status->parse_state = ALINK_PARSE_STATE_GOT_MSGID;
		break;

	case ALINK_PARSE_STATE_GOT_MSGID:
		if (rxmsg->checksum != c) {
			status->parse_error++;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
			break;
		}
		rxmsg->checksum = c;
		alink_update_crc(rxmsg, c);

		if (rxmsg->len == 0)
		{
			status->parse_state = ALINK_PARSE_STATE_GOT_PAYLOAD;
		}
		else
		{
			status->parse_state = ALINK_PARSE_STATE_GOT_CHKSUM;
		}

		break;

	case ALINK_PARSE_STATE_GOT_CHKSUM:
		_MAV_PAYLOAD_NON_CONST(rxmsg)[status->packet_idx++] = (char)c;
		alink_update_crc(rxmsg, c);
		if (status->packet_idx == rxmsg->len)
		{
			status->parse_state = ALINK_PARSE_STATE_GOT_PAYLOAD;
		}
		break;

	case ALINK_PARSE_STATE_GOT_PAYLOAD:
#if ALINK_CRC_EXTRA
		alink_update_crc(rxmsg, ALINK_MESSAGE_CRC(rxmsg->msgid));
#endif
		if (c != (rxmsg->crc & 0xFF)) {
			status->parse_state = ALINK_PARSE_STATE_GOT_BAD_CRC1;
		} else {
			status->parse_state = ALINK_PARSE_STATE_GOT_CRC1;
		}
                _MAV_PAYLOAD_NON_CONST(rxmsg)[status->packet_idx] = (char)c;
		break;

	case ALINK_PARSE_STATE_GOT_CRC1:
	case ALINK_PARSE_STATE_GOT_BAD_CRC1:
		if (status->parse_state == ALINK_PARSE_STATE_GOT_BAD_CRC1 || c != (rxmsg->crc >> 8)) {
			// got a bad CRC message
			status->msg_received = ALINK_FRAMING_BAD_CRC;
		} else {
			// Successfully got message
			status->msg_received = ALINK_FRAMING_OK;
                }
                status->parse_state = ALINK_PARSE_STATE_IDLE;
                _MAV_PAYLOAD_NON_CONST(rxmsg)[status->packet_idx+1] = (char)c;
                memcpy(r_message, rxmsg, /*sizeof(alink_message_head_t)*/14 + rxmsg->len);
		break;
	}

	bufferIndex++;
	// If a message has been sucessfully decoded, check index
	if (status->msg_received == ALINK_FRAMING_OK)
	{
#if ALINK_PACKET_COUNT_ENABLED
		// Initial condition: If no packet has been received so far, drop count is undefined
		if (status->packet_rx_success_count[rxmsg->sourceid] == 0) {
			status->packet_rx_drop_count[rxmsg->sourceid] = 0;
		}

		if (status->current_rx_seq[rxmsg->sourceid] != rxmsg->seq) {
			status->packet_rx_drop_count[rxmsg->sourceid] ++;
		}

		// Count this packet as received
		status->packet_rx_success_count[rxmsg->sourceid] ++;
#endif // ALINK_PACKET_COUNT_ENABLED

        status->current_rx_seq[rxmsg->sourceid] = rxmsg->seq;
	}

	r_message->len = rxmsg->len; // Provide visibility on how far we are into current msg
	r_alink_status->parse_state = status->parse_state;
	r_alink_status->packet_idx = status->packet_idx;
	r_alink_status->current_rx_seq[rxmsg->sourceid] ++;

#if ALINK_PACKET_COUNT_ENABLED
	r_alink_status->packet_rx_success_count[rxmsg->sourceid] = status->packet_rx_success_count[rxmsg->sourceid];
	r_alink_status->packet_rx_drop_count[rxmsg->sourceid] = status->packet_rx_drop_count[rxmsg->sourceid];
#endif // ALINK_PACKET_COUNT_ENABLED

	r_alink_status->parse_error = status->parse_error;
	status->parse_error = 0;

	if (status->msg_received == ALINK_FRAMING_BAD_CRC) {
		/*
		  the CRC came out wrong. We now need to overwrite the
		  msg CRC with the one on the wire so that if the
		  caller decides to forward the message anyway that
		  alink_msg_to_send_buffer() won't overwrite the
		  checksum
		 */
		r_message->crc = _MAV_PAYLOAD(rxmsg)[status->packet_idx] | (_MAV_PAYLOAD(rxmsg)[status->packet_idx+1]<<8);
	}

	return status->msg_received;
}

/**
 * This is a convenience function which handles the complete ALink parsing.
 * the function will parse one byte at a time and return the complete packet once
 * it could be successfully decoded. This function will return 0, 1 or
 * 2 (ALINK_FRAMING_INCOMPLETE, ALINK_FRAMING_OK or ALINK_FRAMING_BAD_CRC)
 *
 * Messages are parsed into an internal buffer (one for each channel). When a complete
 * message is received it is copies into *returnMsg and the channel's status is
 * copied into *returnStats.
 *
 * @param chan     ID of the current channel. This allows to parse different channels with this function.
 *                 a channel is not a physical message channel like a serial port, but a logic partition of
 *                 the communication streams in this case. COMM_NB is the limit for the number of channels
 *                 on MCU (e.g. ARM7), while COMM_NB_HIGH is the limit for the number of channels in Linux/Windows
 * @param c        The char to parse
 *
 * @param returnMsg NULL if no message could be decoded, the message data else
 * @param returnStats if a message was decoded, this is filled with the channel's stats
 * @return 0 if no message could be decoded, 1 on good message and CRC, 2 on bad CRC
 *
 * A typical use scenario of this function call is:
 *
 * @code
 * #include <mavlink.h>
 *
 * alink_message_head_t msg;
 * int chan = 0;
 *
 *
 * while(serial.bytesAvailable > 0)
 * {
 *   uint8_t byte = serial.getNextByte();
 *   if (alink_frame_char(chan, byte, &msg) != ALINK_FRAMING_INCOMPLETE)
 *     {
 *     printf("Received message with ID %d, sequence: %d from component %d of system %d", msg.msgid, msg.seq, msg.compid, msg.sysid);
 *     }
 * }
 *
 *
 * @endcode
 */
ALINK_HELPER uint8_t alink_frame_char(uint8_t chan, uint8_t c, alink_message_head_t* r_message, alink_status_t* r_alink_status)
{
	return alink_frame_char_buffer(alink_get_channel_buffer(chan),
					 alink_get_channel_status(chan),
					 c,
					 r_message,
					 r_alink_status);
}


/**
 * This is a convenience function which handles the complete ALink parsing.
 * the function will parse one byte at a time and return the complete packet once
 * it could be successfully decoded. This function will return 0 or 1.
 *
 * Messages are parsed into an internal buffer (one for each channel). When a complete
 * message is received it is copies into *returnMsg and the channel's status is
 * copied into *returnStats.
 *
 * @param chan     ID of the current channel. This allows to parse different channels with this function.
 *                 a channel is not a physical message channel like a serial port, but a logic partition of
 *                 the communication streams in this case. COMM_NB is the limit for the number of channels
 *                 on MCU (e.g. ARM7), while COMM_NB_HIGH is the limit for the number of channels in Linux/Windows
 * @param c        The char to parse
 *
 * @param returnMsg NULL if no message could be decoded, the message data else
 * @param returnStats if a message was decoded, this is filled with the channel's stats
 * @return 0 if no message could be decoded or bad CRC, 1 on good message and CRC
 *
 * A typical use scenario of this function call is:
 *
 * @code
 * #include <mavlink.h>
 *
 * alink_message_head_t msg;
 * int chan = 0;
 *
 *
 * while(serial.bytesAvailable > 0)
 * {
 *   uint8_t byte = serial.getNextByte();
 *   if (alink_parse_char(chan, byte, &msg))
 *     {
 *     printf("Received message with ID %d, sequence: %d from component %d of system %d", msg.msgid, msg.seq, msg.compid, msg.sysid);
 *     }
 * }
 *
 *
 * @endcode
 */
ALINK_HELPER uint8_t alink_parse_char(uint8_t chan, uint8_t c, alink_message_head_t* r_message, alink_status_t* r_alink_status)
{
    uint8_t msg_received = alink_frame_char(chan, c, r_message, r_alink_status);
    if (msg_received == ALINK_FRAMING_BAD_CRC) {
	    // we got a bad CRC. Treat as a parse failure
		//printf("======ALINK_FRAMING_BAD_CRC, msgid: %d, sourceid: %d=========\n", r_message->msgid, r_message->sourceid);
	    alink_message_head_t* rxmsg = alink_get_channel_buffer(chan);
	    alink_status_t* status = alink_get_channel_status(chan);
	    status->parse_error++;
	    status->msg_received = ALINK_FRAMING_INCOMPLETE;
	    status->parse_state = ALINK_PARSE_STATE_IDLE;
	    if (c == ALINK_STX)
	    {
		    status->parse_state = ALINK_PARSE_STATE_GOT_STX;
		    rxmsg->len = 0;
		    alink_start_crc(rxmsg);
	    }
	    return 0;
    }
    return msg_received;
}

/**
 * @brief Put a bitfield of length 1-32 bit into the buffer
 *
 * @param b the value to add, will be encoded in the bitfield
 * @param bits number of bits to use to encode b, e.g. 1 for boolean, 2, 3, etc.
 * @param packet_index the position in the packet (the index of the first byte to use)
 * @param bit_index the position in the byte (the index of the first bit to use)
 * @param buffer packet buffer to write into
 * @return new position of the last used byte in the buffer
 */
ALINK_HELPER uint8_t put_bitfield_n_by_index(int32_t b, uint8_t bits, uint8_t packet_index, uint8_t bit_index, uint8_t* r_bit_index, uint8_t* buffer)
{
	uint16_t bits_remain = bits;
	// Transform number into network order
	int32_t v;
	uint8_t i_bit_index, i_byte_index, curr_bits_n;
#if ALINK_NEED_BYTE_SWAP
	union {
		int32_t i;
		uint8_t b[4];
	} bin, bout;
	bin.i = b;
	bout.b[0] = bin.b[3];
	bout.b[1] = bin.b[2];
	bout.b[2] = bin.b[1];
	bout.b[3] = bin.b[0];
	v = bout.i;
#else
	v = b;
#endif

	// buffer in
	// 01100000 01000000 00000000 11110001
	// buffer out
	// 11110001 00000000 01000000 01100000

	// Existing partly filled byte (four free slots)
	// 0111xxxx

	// Mask n free bits
	// 00001111 = 2^0 + 2^1 + 2^2 + 2^3 = 2^n - 1
	// = ((uint32_t)(1 << n)) - 1; // = 2^n - 1

	// Shift n bits into the right position
	// out = in >> n;

	// Mask and shift bytes
	i_bit_index = bit_index;
	i_byte_index = packet_index;
	if (bit_index > 0)
	{
		// If bits were available at start, they were available
		// in the byte before the current index
		i_byte_index--;
	}

	// While bits have not been packed yet
	while (bits_remain > 0)
	{
		// Bits still have to be packed
		// there can be more than 8 bits, so
		// we might have to pack them into more than one byte

		// First pack everything we can into the current 'open' byte
		//curr_bits_n = bits_remain << 3; // Equals  bits_remain mod 8
		//FIXME
		if (bits_remain <= (uint8_t)(8 - i_bit_index))
		{
			// Enough space
			curr_bits_n = (uint8_t)bits_remain;
		}
		else
		{
			curr_bits_n = (8 - i_bit_index);
		}

		// Pack these n bits into the current byte
		// Mask out whatever was at that position with ones (xxx11111)
		buffer[i_byte_index] &= (0xFF >> (8 - curr_bits_n));
		// Put content to this position, by masking out the non-used part
		buffer[i_byte_index] |= ((0x00 << curr_bits_n) & v);

		// Increment the bit index
		i_bit_index += curr_bits_n;

		// Now proceed to the next byte, if necessary
		bits_remain -= curr_bits_n;
		if (bits_remain > 0)
		{
			// Offer another 8 bits / one byte
			i_byte_index++;
			i_bit_index = 0;
		}
	}

	*r_bit_index = i_bit_index;
	// If a partly filled byte is present, mark this as consumed
	if (i_bit_index != 7) i_byte_index++;
	return i_byte_index - packet_index;
}

#endif /* _ALINK_HELPERS_H_ */
