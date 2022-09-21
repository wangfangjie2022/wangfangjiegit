#ifndef  _ALINK_PROTOCOL_H_
#define  _ALINK_PROTOCOL_H_

#include "string.h"
#include "alink_types.h"

/* 
   If you want MAVLink on a system that is native big-endian,
   you need to define NATIVE_BIG_ENDIAN
*/
#ifdef NATIVE_BIG_ENDIAN
# define ALINK_NEED_BYTE_SWAP (ALINK_ENDIAN == ALINK_LITTLE_ENDIAN)
#else
# define ALINK_NEED_BYTE_SWAP (ALINK_ENDIAN != ALINK_LITTLE_ENDIAN)
#endif

#ifndef ALINK_STACK_BUFFER
#define ALINK_STACK_BUFFER 0
#endif

#ifndef ALINK_AVOID_GCC_STACK_BUG
# define ALINK_AVOID_GCC_STACK_BUG defined(__GNUC__)
#endif

#ifndef ALINK_ASSERT
#define ALINK_ASSERT(x)
#endif

#ifndef ALINK_START_UART_SEND
#define ALINK_START_UART_SEND(chan, length)
#endif

#ifndef ALINK_END_UART_SEND
#define ALINK_END_UART_SEND(chan, length)
#endif

/* option to provide alternative implementation of alink_helpers.h */
#ifdef ALINK_SEPARATE_HELPERS

    #define ALINK_HELPER

    /* decls in sync with those in alink_helpers.h */
    #ifndef ALINK_GET_CHANNEL_STATUS
    ALINK_HELPER alink_status_t* alink_get_channel_status(uint8_t chan);
    #endif
    ALINK_HELPER void alink_reset_channel_status(uint8_t chan);
    #if ALINK_CRC_EXTRA
    ALINK_HELPER uint16_t alink_finalize_message_chan(alink_message_head_t* msg, uint8_t system_id, uint8_t component_id,
                                  uint8_t chan, uint16_t length, uint8_t crc_extra);
    ALINK_HELPER uint16_t alink_finalize_message(alink_message_head_t* msg, uint8_t system_id, uint8_t component_id,
                             uint16_t length, uint8_t crc_extra);
    #ifdef ALINK_USE_CONVENIENCE_FUNCTIONS
    ALINK_HELPER void _mav_finalize_message_chan_send(alink_channel_t chan, uint8_t msgid, const char *packet,
                                uint16_t length, uint8_t crc_extra);
    #endif
    #else
    ALINK_HELPER uint16_t alink_finalize_message_chan(alink_message_head_t* msg, uint8_t system_id, uint8_t component_id,
                                  uint8_t chan, uint16_t length);
    ALINK_HELPER uint16_t alink_finalize_message(alink_message_head_t* msg, uint8_t system_id, uint8_t component_id,
                             uint16_t length);
    #ifdef ALINK_USE_CONVENIENCE_FUNCTIONS
    ALINK_HELPER void _mav_finalize_message_chan_send(alink_channel_t chan, uint8_t msgid, const char *packet, uint16_t length);
    #endif
    #endif // ALINK_CRC_EXTRA
    ALINK_HELPER uint16_t alink_msg_to_send_buffer(uint8_t *buffer, const alink_message_head_t *msg);
    ALINK_HELPER void alink_start_checksum(alink_message_head_t* msg);
    ALINK_HELPER void alink_update_checksum(alink_message_head_t* msg, uint8_t c);
    ALINK_HELPER uint8_t alink_frame_char_buffer(alink_message_head_t* rxmsg, 
						     alink_status_t* status,
						     uint8_t c, 
						     alink_message_head_t* r_message, 
						     alink_status_t* r_alink_status);
    ALINK_HELPER uint8_t alink_frame_char(uint8_t chan, uint8_t c, alink_message_head_t* r_message, alink_status_t* r_alink_status);
    ALINK_HELPER uint8_t alink_parse_char(uint8_t chan, uint8_t c, alink_message_head_t* r_message, alink_status_t* r_alink_status);
    ALINK_HELPER uint8_t put_bitfield_n_by_index(int32_t b, uint8_t bits, uint8_t packet_index, uint8_t bit_index,
                               uint8_t* r_bit_index, uint8_t* buffer);
    #ifdef ALINK_USE_CONVENIENCE_FUNCTIONS
    ALINK_HELPER void _alink_send_uart(alink_channel_t chan, const char *buf, uint16_t len);
    ALINK_HELPER void _alink_resend_uart(alink_channel_t chan, const alink_message_head_t *msg);
    #endif

#else

    #define ALINK_HELPER static inline
    #include "alink_helpers.h"

#endif // ALINK_SEPARATE_HELPERS

/**
 * @brief Get the required buffer size for this message
 */
static inline uint16_t alink_msg_get_send_buffer_length(const alink_message_head_t* msg)
{
	return msg->len + ALINK_NUM_NON_PAYLOAD_BYTES;
}

#if ALINK_NEED_BYTE_SWAP
static inline void byte_swap_2(char *dst, const char *src)
{
	dst[0] = src[1];
	dst[1] = src[0];
}
static inline void byte_swap_4(char *dst, const char *src)
{
	dst[0] = src[3];
	dst[1] = src[2];
	dst[2] = src[1];
	dst[3] = src[0];
}
static inline void byte_swap_8(char *dst, const char *src)
{
	dst[0] = src[7];
	dst[1] = src[6];
	dst[2] = src[5];
	dst[3] = src[4];
	dst[4] = src[3];
	dst[5] = src[2];
	dst[6] = src[1];
	dst[7] = src[0];
}
#elif !ALINK_ALIGNED_FIELDS
static inline void byte_copy_2(char *dst, const char *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}
static inline void byte_copy_4(char *dst, const char *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
}
static inline void byte_copy_8(char *dst, const char *src)
{
	memcpy(dst, src, 8);
}
#endif

#define _mav_put_uint8_t(buf, wire_offset, b) buf[wire_offset] = (uint8_t)b
#define _mav_put_int8_t(buf, wire_offset, b)  buf[wire_offset] = (int8_t)b
#define _mav_put_char(buf, wire_offset, b)    buf[wire_offset] = b

#if ALINK_NEED_BYTE_SWAP
#define _mav_put_uint16_t(buf, wire_offset, b) byte_swap_2(&buf[wire_offset], (const char *)&b)
#define _mav_put_int16_t(buf, wire_offset, b)  byte_swap_2(&buf[wire_offset], (const char *)&b)
#define _mav_put_uint32_t(buf, wire_offset, b) byte_swap_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_int32_t(buf, wire_offset, b)  byte_swap_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_uint64_t(buf, wire_offset, b) byte_swap_8(&buf[wire_offset], (const char *)&b)
#define _mav_put_int64_t(buf, wire_offset, b)  byte_swap_8(&buf[wire_offset], (const char *)&b)
#define _mav_put_float(buf, wire_offset, b)    byte_swap_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_double(buf, wire_offset, b)   byte_swap_8(&buf[wire_offset], (const char *)&b)
#elif !ALINK_ALIGNED_FIELDS
#define _mav_put_uint16_t(buf, wire_offset, b) byte_copy_2(&buf[wire_offset], (const char *)&b)
#define _mav_put_int16_t(buf, wire_offset, b)  byte_copy_2(&buf[wire_offset], (const char *)&b)
#define _mav_put_uint32_t(buf, wire_offset, b) byte_copy_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_int32_t(buf, wire_offset, b)  byte_copy_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_uint64_t(buf, wire_offset, b) byte_copy_8(&buf[wire_offset], (const char *)&b)
#define _mav_put_int64_t(buf, wire_offset, b)  byte_copy_8(&buf[wire_offset], (const char *)&b)
#define _mav_put_float(buf, wire_offset, b)    byte_copy_4(&buf[wire_offset], (const char *)&b)
#define _mav_put_double(buf, wire_offset, b)   byte_copy_8(&buf[wire_offset], (const char *)&b)
#else
#define _mav_put_uint16_t(buf, wire_offset, b) *(uint16_t *)&buf[wire_offset] = b
#define _mav_put_int16_t(buf, wire_offset, b)  *(int16_t *)&buf[wire_offset] = b
#define _mav_put_uint32_t(buf, wire_offset, b) *(uint32_t *)&buf[wire_offset] = b
#define _mav_put_int32_t(buf, wire_offset, b)  *(int32_t *)&buf[wire_offset] = b
#define _mav_put_uint64_t(buf, wire_offset, b) *(uint64_t *)&buf[wire_offset] = b
#define _mav_put_int64_t(buf, wire_offset, b)  *(int64_t *)&buf[wire_offset] = b
#define _mav_put_float(buf, wire_offset, b)    *(float *)&buf[wire_offset] = b
#define _mav_put_double(buf, wire_offset, b)   *(double *)&buf[wire_offset] = b
#endif

/*
  like memcpy(), but if src is NULL, do a memset to zero
*/
static inline void mav_array_memcpy(void *dest, const void *src, size_t n)
{
	if (src == NULL) {
		memset(dest, 0, n);
	} else {
		memcpy(dest, src, n);
	}
}

/*
 * Place a char array into a buffer
 */
static inline void _mav_put_char_array(char *buf, uint16_t wire_offset, const char *b, uint16_t array_length)
{
	mav_array_memcpy(&buf[wire_offset], b, array_length);

}

/*
 * Place a uint8_t array into a buffer
 */
static inline void _mav_put_uint8_t_array(char *buf, uint16_t wire_offset, const uint8_t *b, uint16_t array_length)
{
	mav_array_memcpy(&buf[wire_offset], b, array_length);

}

/*
 * Place a int8_t array into a buffer
 */
static inline void _mav_put_int8_t_array(char *buf, uint16_t wire_offset, const int8_t *b, uint16_t array_length)
{
	mav_array_memcpy(&buf[wire_offset], b, array_length);

}

#if ALINK_NEED_BYTE_SWAP
#define _MAV_PUT_ARRAY(TYPE, V) \
static inline void _mav_put_ ## TYPE ##_array(char *buf, uint16_t wire_offset, const TYPE *b, uint16_t array_length) \
{ \
	if (b == NULL) { \
		memset(&buf[wire_offset], 0, array_length*sizeof(TYPE)); \
	} else { \
		uint16_t i; \
		for (i=0; i<array_length; i++) { \
			_mav_put_## TYPE (buf, wire_offset+(i*sizeof(TYPE)), b[i]); \
		} \
	} \
}
#else
#define _MAV_PUT_ARRAY(TYPE, V)					\
static inline void _mav_put_ ## TYPE ##_array(char *buf, uint16_t wire_offset, const TYPE *b, uint16_t array_length) \
{ \
	mav_array_memcpy(&buf[wire_offset], b, array_length*sizeof(TYPE)); \
}
#endif

_MAV_PUT_ARRAY(uint16_t, u16)
_MAV_PUT_ARRAY(uint32_t, u32)
_MAV_PUT_ARRAY(uint64_t, u64)
_MAV_PUT_ARRAY(int16_t,  i16)
_MAV_PUT_ARRAY(int32_t,  i32)
_MAV_PUT_ARRAY(int64_t,  i64)
_MAV_PUT_ARRAY(float,    f)
_MAV_PUT_ARRAY(double,   d)

#define _MAV_RETURN_char(msg, wire_offset)             (const char)_MAV_PAYLOAD(msg)[wire_offset]
#define _MAV_RETURN_int8_t(msg, wire_offset)   (const int8_t)_MAV_PAYLOAD(msg)[wire_offset]
#define _MAV_RETURN_uint8_t(msg, wire_offset) (const uint8_t)_MAV_PAYLOAD(msg)[wire_offset]

#if ALINK_NEED_BYTE_SWAP
#define _MAV_MSG_RETURN_TYPE(TYPE, SIZE) \
static inline TYPE _MAV_RETURN_## TYPE(const alink_message_head_t *msg, uint16_t ofs) \
{ TYPE r; byte_swap_## SIZE((char*)&r, &_MAV_PAYLOAD(msg)[ofs]); return r; }

_MAV_MSG_RETURN_TYPE(uint16_t, 2)
_MAV_MSG_RETURN_TYPE(int16_t,  2)
_MAV_MSG_RETURN_TYPE(uint32_t, 4)
_MAV_MSG_RETURN_TYPE(int32_t,  4)
_MAV_MSG_RETURN_TYPE(uint64_t, 8)
_MAV_MSG_RETURN_TYPE(int64_t,  8)
_MAV_MSG_RETURN_TYPE(float,    4)
_MAV_MSG_RETURN_TYPE(double,   8)

#elif !ALINK_ALIGNED_FIELDS
#define _MAV_MSG_RETURN_TYPE(TYPE, SIZE) \
static inline TYPE _MAV_RETURN_## TYPE(const alink_message_head_t *msg, uint16_t ofs) \
{ TYPE r; byte_copy_## SIZE((char*)&r, &_MAV_PAYLOAD(msg)[ofs]); return r; }

_MAV_MSG_RETURN_TYPE(uint16_t, 2)
_MAV_MSG_RETURN_TYPE(int16_t,  2)
_MAV_MSG_RETURN_TYPE(uint32_t, 4)
_MAV_MSG_RETURN_TYPE(int32_t,  4)
_MAV_MSG_RETURN_TYPE(uint64_t, 8)
_MAV_MSG_RETURN_TYPE(int64_t,  8)
_MAV_MSG_RETURN_TYPE(float,    4)
_MAV_MSG_RETURN_TYPE(double,   8)
#else // nicely aligned, no swap
#define _MAV_MSG_RETURN_TYPE(TYPE) \
static inline TYPE _MAV_RETURN_## TYPE(const alink_message_head_t *msg, uint16_t ofs) \
{ return *(const TYPE *)(&_MAV_PAYLOAD(msg)[ofs]);}

_MAV_MSG_RETURN_TYPE(uint16_t)
_MAV_MSG_RETURN_TYPE(int16_t)
_MAV_MSG_RETURN_TYPE(uint32_t)
_MAV_MSG_RETURN_TYPE(int32_t)
_MAV_MSG_RETURN_TYPE(uint64_t)
_MAV_MSG_RETURN_TYPE(int64_t)
_MAV_MSG_RETURN_TYPE(float)
_MAV_MSG_RETURN_TYPE(double)
#endif // ALINK_NEED_BYTE_SWAP

static inline uint16_t _MAV_RETURN_char_array(const alink_message_head_t *msg, char *value, 
						     uint16_t array_length, uint16_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

static inline uint16_t _MAV_RETURN_uint8_t_array(const alink_message_head_t *msg, uint8_t *value, 
							uint16_t array_length, uint16_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

static inline uint16_t _MAV_RETURN_int8_t_array(const alink_message_head_t *msg, int8_t *value, 
						       uint16_t array_length, uint16_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

#if ALINK_NEED_BYTE_SWAP
#define _MAV_RETURN_ARRAY(TYPE, V) \
static inline uint16_t _MAV_RETURN_## TYPE ##_array(const alink_message_head_t *msg, TYPE *value, \
							 uint16_t array_length, uint16_t wire_offset) \
{ \
	uint16_t i; \
	for (i=0; i<array_length; i++) { \
		value[i] = _MAV_RETURN_## TYPE (msg, wire_offset+(i*sizeof(value[0]))); \
	} \
	return array_length*sizeof(value[0]); \
}
#else
#define _MAV_RETURN_ARRAY(TYPE, V)					\
static inline uint16_t _MAV_RETURN_## TYPE ##_array(const alink_message_head_t *msg, TYPE *value, \
							 uint16_t array_length, uint16_t wire_offset) \
{ \
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length*sizeof(TYPE)); \
	return array_length*sizeof(TYPE); \
}
#endif

_MAV_RETURN_ARRAY(uint16_t, u16)
_MAV_RETURN_ARRAY(uint32_t, u32)
_MAV_RETURN_ARRAY(uint64_t, u64)
_MAV_RETURN_ARRAY(int16_t,  i16)
_MAV_RETURN_ARRAY(int32_t,  i32)
_MAV_RETURN_ARRAY(int64_t,  i64)
_MAV_RETURN_ARRAY(float,    f)
_MAV_RETURN_ARRAY(double,   d)

#endif // _ALINK_PROTOCOL_H_
