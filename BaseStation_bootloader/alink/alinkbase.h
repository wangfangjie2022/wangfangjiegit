#pragma once
#ifndef alink_BASE_H
#define alink_BASE_H

#include "alink_types.h"
#include "xstar_2_0\alink.h"
#include "checksum.h"


template<uint16_t payload_size>
class CALinkBase
{
public:
	typedef struct __alink_message{
		alink_message_head_t head;
		uint8_t payload[payload_size];
	}alink_message_t;

public:
	CALinkBase(alink_system_t system);
	virtual ~CALinkBase();

	int  recv_message(uint8_t* msg, uint32_t len);

	int send_message(const uint8_t msgid, const void *msg, const uint16_t msglen);

	virtual void handle_message(const alink_message_head_t *msg) = 0;

	virtual int read(uint8_t *recv, int32_t recv_len) = 0;

	virtual int write(const uint8_t *send, int32_t send_len) = 0;

	uint8_t alink_parse_char(uint8_t c);
	
private:
	/**
	* This is a varient of alink_frame_char() but with caller supplied
	* parsing buffers. It is useful when you want to create a MAVLink
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
	* #include <alink.h>
	*
	* alink_message_t msg;
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
	uint8_t alink_frame_char_buffer(
		alink_message_head_t* rxmsg,
		alink_status_t* status,
		uint8_t c);

	inline void alink_start_crc(alink_message_head_t* msg)
	{
		crc_init(&msg->crc);
	}

	inline void alink_update_crc(alink_message_head_t* msg, uint8_t c)
	{
		crc_accumulate(c, &msg->crc);
	}

	inline void alink_start_checksum(alink_message_head_t* msg, uint8_t c)
	{
		msg->checksum = c;
	}

	inline void alink_update_checksum(alink_message_head_t* msg, uint8_t c)
	{
		msg->checksum += c;
	}

	alink_system_t  _system;
	
	alink_status_t	_rcv_status;

	alink_message_t	_rcv_msg;

public:
	uint8_t         _send_buf[sizeof(alink_message_t)];
};

//#if ALINK_CRC_EXTRA
//#ifndef ALINK_MESSAGE_CRC
//static const uint8_t alink_message_crcs[256] = ALINK_MESSAGE_CRCS;
//#define ALINK_MESSAGE_CRC(msgid) alink_message_crcs[msgid]
//#endif
//#endif


//#ifdef ALINK_CHECK_MESSAGE_LENGTH
//#ifndef ALINK_MESSAGE_LENGTH
//	static const uint8_t alink_message_lengths[256] = ALINK_MESSAGE_LENGTHS;
//#define ALINK_MESSAGE_LENGTH(msgid) alink_message_lengths[msgid]
//#endif
//#endif

template<uint16_t payload_size>
CALinkBase<payload_size>::CALinkBase(alink_system_t system) :
	_system(system),	
	_rcv_status{ 0 },	
	_rcv_msg{ 0 }
{

}

template<uint16_t payload_size>
CALinkBase<payload_size>::~CALinkBase()
{
}

template<uint16_t payload_size>
int CALinkBase<payload_size>::recv_message(uint8_t* msg, uint32_t len)
{
	uint8_t ret = -1;

	int count = read(msg, len);

	for (int i = 0; i < count; i++) {
		if (alink_parse_char(msg[i])) {

			handle_message((alink_message_head_t*)&_rcv_msg);

			ret = 0x01;
		}
	}

	return ret;
}



template<uint16_t payload_size>
uint8_t CALinkBase<payload_size>::alink_parse_char(uint8_t c)
{
	uint8_t msg_received = alink_frame_char_buffer((alink_message_head_t*)&_rcv_msg, &_rcv_status, c);
	if (msg_received == ALINK_FRAMING_BAD_CRC) {
		// we got a bad CRC. Treat as a parse failure		
		_rcv_status.parse_error++;
		_rcv_status.msg_received = ALINK_FRAMING_INCOMPLETE;
		_rcv_status.parse_state = ALINK_PARSE_STATE_IDLE;
		if (c == ALINK_STX)
		{
			_rcv_status.parse_state = ALINK_PARSE_STATE_GOT_STX;
			_rcv_msg.head.len = 0;
			alink_start_crc((alink_message_head_t*)&_rcv_msg);
		}
		return 0;
	}
	return msg_received;
}

template<uint16_t payload_size>
uint8_t CALinkBase<payload_size>::alink_frame_char_buffer(
		alink_message_head_t* rxmsg,
		alink_status_t* status,
		uint8_t c)
{

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
			alink_start_checksum(rxmsg, c);
		}
		break;

	case ALINK_PARSE_STATE_GOT_STX:
		if (status->msg_received
			/* Support shorter buffers than the
			default maximum packet size */
			)
		{
			status->buffer_overrun++;
			status->parse_error++;
			status->msg_received = 0;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
		}
		else
		{
			// NOT counting STX, LENGTH-LO, LENGTH-HI, SEQ, DESTID, SOURCEID, MSGID, CHECKSUM, CRC1 and CRC2
			rxmsg->len_lo = c;
			status->packet_idx = 0;
			alink_update_crc(rxmsg, c);
			alink_update_checksum(rxmsg, c);
			status->parse_state = ALINK_PARSE_STATE_GOT_LENGTH_LO;
		}
		break;

	case ALINK_PARSE_STATE_GOT_LENGTH_LO:
		rxmsg->len_hi = c;
		rxmsg->len = rxmsg->len_lo | (rxmsg->len_hi << 8);
		if (rxmsg->len  > payload_size) {
			status->parse_error++;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
			break;
		}

		alink_update_crc(rxmsg, c);
		alink_update_checksum(rxmsg, c);
		status->parse_state = ALINK_PARSE_STATE_GOT_LENGTH_HI;
		break;

	case ALINK_PARSE_STATE_GOT_LENGTH_HI:
		rxmsg->seq = c;
		alink_update_crc(rxmsg, c);
		alink_update_checksum(rxmsg, c);
		status->parse_state = ALINK_PARSE_STATE_GOT_SEQ;
		break;

	case ALINK_PARSE_STATE_GOT_SEQ:
		rxmsg->destid = c;
		alink_update_crc(rxmsg, c);
		alink_update_checksum(rxmsg, c);
		status->parse_state = ALINK_PARSE_STATE_GOT_DESTID;
		break;

	case ALINK_PARSE_STATE_GOT_DESTID:
		rxmsg->sourceid = c;
		alink_update_crc(rxmsg, c);
		alink_update_checksum(rxmsg, c);
		status->parse_state = ALINK_PARSE_STATE_GOT_SOURCEID;
		break;

	case ALINK_PARSE_STATE_GOT_SOURCEID:
		rxmsg->msgid = c;
		alink_update_crc(rxmsg, c);
		alink_update_checksum(rxmsg, c);
		status->parse_state = ALINK_PARSE_STATE_GOT_MSGID;
		break;

	case ALINK_PARSE_STATE_GOT_MSGID:		
		if (c != rxmsg->checksum)
		{
			status->parse_error++;
			status->parse_state = ALINK_PARSE_STATE_IDLE;
			break;
		}
	
		rxmsg->checksum = c;
		alink_update_crc(rxmsg, c);
	
		if (rxmsg->len == 0) {
			status->parse_state = ALINK_PARSE_STATE_GOT_PAYLOAD;
		}
		else {
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
		}
		else {
			status->parse_state = ALINK_PARSE_STATE_GOT_CRC1;
		}
		_MAV_PAYLOAD_NON_CONST(rxmsg)[status->packet_idx] = (char)c;
		break;

	case ALINK_PARSE_STATE_GOT_CRC1:
	case ALINK_PARSE_STATE_GOT_BAD_CRC1:
		if (status->parse_state == ALINK_PARSE_STATE_GOT_BAD_CRC1 || c != (rxmsg->crc >> 8)) {
			// got a bad CRC message
			status->msg_received = ALINK_FRAMING_BAD_CRC;
		}
		else {
			// Successfully got message
			status->msg_received = ALINK_FRAMING_OK;
		}
		status->parse_state = ALINK_PARSE_STATE_IDLE;
		_MAV_PAYLOAD_NON_CONST(rxmsg)[status->packet_idx + 1] = (char)c;
		//memcpy(r_message, rxmsg, sizeof(alink_message_head_t) + rxmsg->len + 2);
		break;
	}

	bufferIndex++;
	// If a message has been sucessfully decoded, check index
	if (status->msg_received == ALINK_FRAMING_OK)
	{
		status->current_rx_seq = rxmsg->seq;
		// Initial condition: If no packet has been received so far, drop count is undefined
		if (status->packet_rx_success_count == 0) status->packet_rx_drop_count = 0;
		// Count this packet as received
		status->packet_rx_success_count++;
	}

	//r_message->len = rxmsg->len; // Provide visibility on how far we are into current msg
	//r_status->parse_state = status->parse_state;
	//r_status->packet_idx = status->packet_idx;
	status->current_rx_seq = status->current_rx_seq + 1;
	//r_status->packet_rx_success_count = status->packet_rx_success_count;
	//r_status->packet_rx_drop_count = status->parse_error;

	//status->parse_error = 0;

	if (status->msg_received == ALINK_FRAMING_BAD_CRC) {
		/*
		the CRC came out wrong. We now need to overwrite the
		msg CRC with the one on the wire so that if the
		caller decides to forward the message anyway that
		alink_msg_to_send_buffer() won't overwrite the
		checksum
		*/
		rxmsg->crc = _MAV_PAYLOAD(rxmsg)[status->packet_idx] | (_MAV_PAYLOAD(rxmsg)[status->packet_idx + 1] << 8);
	}

	return status->msg_received;
}



template<uint16_t payload_size>
int CALinkBase<payload_size>::send_message(const uint8_t msgid, const void *msg, const uint16_t msglen)
{
	int ret = 0;

	uint16_t payload_len = msglen;//alink_message_lengths[msgid];
	unsigned packet_len = payload_len + ALINK_NUM_NON_PAYLOAD_BYTES;
	
	/* header */
	_send_buf[0] = ALINK_STX;
	_send_buf[7] = ALINK_STX;

	_send_buf[1] = payload_len & 0xff;
	_send_buf[7] += _send_buf[1];

	_send_buf[2] = (payload_len >> 8) & 0xff;
	_send_buf[7] += _send_buf[2];

	/* use alink's internal counter for the TX seq */
	_send_buf[3] = _rcv_status.current_tx_seq++;
	_send_buf[7] += _send_buf[3];

	_send_buf[4] = _system.destid;
	_send_buf[7] += _send_buf[4];

	_send_buf[5] = _system.sourceid;
	_send_buf[7] += _send_buf[5];

	_send_buf[6] = msgid;
	_send_buf[7] += _send_buf[6];
	
	/* payload */
	if(msg != nullptr)
		memcpy(&_send_buf[ALINK_NUM_HEADER_BYTES], msg, payload_len);

	/* checksum */
	uint16_t checksum;
	crc_init(&checksum);
	crc_accumulate_buffer(&checksum, (const char *)&_send_buf[1], ALINK_CORE_HEADER_LEN + payload_len);
	crc_accumulate(alink_message_crcs[msgid], &checksum);

	_send_buf[ALINK_NUM_HEADER_BYTES + payload_len] = (uint8_t)(checksum & 0xFF);
	_send_buf[ALINK_NUM_HEADER_BYTES + payload_len + 1] = (uint8_t)(checksum >> 8);

	ret = write(_send_buf, packet_len);
	if (ret != (int)packet_len) {
		ret = -1;
	}

	return ret;
}

#endif /* alink_BASE_H */


