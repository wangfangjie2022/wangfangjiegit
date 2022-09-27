#ifndef ALINK_TYPES_H_
#define ALINK_TYPES_H_

// Visual Studio versions before 2010 don't have stdint.h, so we just error out.
#if (defined _MSC_VER) && (_MSC_VER < 1600)
#error "The C-ALink implementation requires Visual Studio 2017 or greater"
#endif

#include <stdint.h>

// Macro to define packed structures
#ifdef __GNUC__
  #define MAVPACKED( __Declaration__ ) __Declaration__ __attribute__((packed))
#else
  #define MAVPACKED( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )
#endif

#ifndef ALINK_MAX_PAYLOAD_LEN
// it is possible to override this, but be careful!
#define ALINK_MAX_PAYLOAD_LEN 1024 ///< Maximum payload length
#endif

#ifndef ALINK_MAX_PAYLOAD_LEN_EXT
// it is possible to override this, but be careful!
#define ALINK_MAX_PAYLOAD_LEN_EXT 4096 ///< Maximum payload length
#endif

#define ALINK_CORE_HEADER_LEN 7 ///< Length of core header (of the comm. layer): message length (2 byte) + message sequence (1 byte) + message destination id (1 byte) + message source id (1 byte) + message type id (1 byte) + checksum (1 byte)
#define ALINK_NUM_HEADER_BYTES (ALINK_CORE_HEADER_LEN + 1) ///< Length of all header bytes, including core and checksum
#define ALINK_NUM_CHECKSUM_BYTES 2
#define ALINK_NUM_NON_PAYLOAD_BYTES (ALINK_NUM_HEADER_BYTES + ALINK_NUM_CHECKSUM_BYTES)

#define ALINK_MAX_PACKET_LEN (ALINK_MAX_PAYLOAD_LEN + ALINK_NUM_NON_PAYLOAD_BYTES) ///< Maximum packet length

#ifndef ALINK_MAX_DEV_NUM
#define ALINK_MAX_DEV_NUM    256
#endif // ALINK_MAX_DEV_NUM

/**
 * Old-style 4 byte param union
 *
 * This struct is the data format to be used when sending
 * parameters. The parameter should be copied to the native
 * type (without type conversion)
 * and re-instanted on the receiving side using the
 * native type as well.
 */
MAVPACKED(
typedef struct param_union {
	union {
		float param_float;
		int32_t param_int32;
		uint32_t param_uint32;
		int16_t param_int16;
		uint16_t param_uint16;
		int8_t param_int8;
		uint8_t param_uint8;
		uint8_t bytes[4];
	};
	uint8_t type;
}) alink_param_union_t;


/**
 * New-style 8 byte param union
 * alink_param_union_double_t will be 8 bytes long, and treated as needing 8 byte alignment for the purposes of MAVLink 1.0 field ordering.
 * The alink_param_union_double_t will be treated as a little-endian structure.
 *
 * If is_double is 1 then the type is a double, and the remaining 63 bits are the double, with the lowest bit of the mantissa zero.
 * The intention is that by replacing the is_double bit with 0 the type can be directly used as a double (as the is_double bit corresponds to the
 * lowest mantissa bit of a double). If is_double is 0 then alink_type gives the type in the union.
 * The alink_types.h header will also need to have shifts/masks to define the bit boundaries in the above,
 * as bitfield ordering isn’t consistent between platforms. The above is intended to be for gcc on x86,
 * which should be the same as gcc on little-endian arm. When using shifts/masks the value will be treated as a 64 bit unsigned number,
 * and the bits pulled out using the shifts/masks.
*/
MAVPACKED(
typedef struct param_union_extended {
    union {
    struct {
        uint8_t is_double:1;
        uint8_t alink_type:7;
        union {
            char c;
            uint8_t uint8;
            int8_t int8;
            uint16_t uint16;
            int16_t int16;
            uint32_t uint32;
            int32_t int32;
            float f;
            uint8_t align[7];
        };
    };
    uint8_t data[8];
    };
}) alink_param_union_double_t;

/**
 * This structure is required to make the alink_send_xxx convenience functions
 * work, as it tells the library what the current system and component ID are.
 */
MAVPACKED(
typedef struct __alink_system {
    uint8_t sourceid;   ///< Used by the MAVLink message_xx_send() convenience function
    uint8_t destid;     ///< Used by the MAVLink message_xx_send() convenience function
}) alink_system_t;

MAVPACKED(
typedef struct __alink_message_head {
	uint16_t crc;          ///< sent at end of packet
    uint16_t len;          ///< Lenght of payload
	uint8_t magic;         ///< protocol magic marker
    uint8_t len_lo;        ///< Low byte of length of payload
	uint8_t len_hi;        ///< Hight byte of length of payload
	uint8_t seq;           ///< Sequence of packet
	uint8_t destid;        ///< ID of message destination
	uint8_t sourceid;      ///< ID of the message sounrce
	uint8_t msgid;         ///< ID of message in payload
    uint8_t checksum;      ///< Checksum of message header
	uint64_t payload64[(ALINK_MAX_PAYLOAD_LEN+ALINK_NUM_CHECKSUM_BYTES+7)/8];
}) alink_message_head_t;

MAVPACKED(
typedef struct __alink_message_head_ext {
	uint16_t crc;          ///< sent at end of packet
    uint16_t len;          ///< Lenght of payload
	uint8_t magic;         ///< protocol magic marker
    uint8_t len_lo;        ///< Low byte of length of payload
	uint8_t len_hi;        ///< Hight byte of length of payload
	uint8_t seq;           ///< Sequence of packet
	uint8_t destid;        ///< ID of message destination
	uint8_t sourceid;      ///< ID of the message sounrce
	uint8_t msgid;         ///< ID of message in payload
    uint8_t checksum;      ///< Checksum of message header
	uint64_t payload64[ALINK_MAX_PAYLOAD_LEN_EXT+ALINK_NUM_CHECKSUM_BYTES+7/8];
}) alink_message_head_ext_t;


typedef enum {
	ALINK_TYPE_CHAR     = 0,
	ALINK_TYPE_UINT8_T  = 1,
	ALINK_TYPE_INT8_T   = 2,
	ALINK_TYPE_UINT16_T = 3,
	ALINK_TYPE_INT16_T  = 4,
	ALINK_TYPE_UINT32_T = 5,
	ALINK_TYPE_INT32_T  = 6,
	ALINK_TYPE_UINT64_T = 7,
	ALINK_TYPE_INT64_T  = 8,
	ALINK_TYPE_FLOAT    = 9,
	ALINK_TYPE_DOUBLE   = 10
} alink_message_type_t;

#define ALINK_MAX_FIELDS 64

typedef struct __alink_field_info {
        const char *name;                 // name of this field
        const char *print_format;         // printing format hint, or NULL
        alink_message_type_t type;      // type of this field
        unsigned int array_length;        // if non-zero, field is an array
        unsigned int wire_offset;         // offset of each field in the payload
        unsigned int structure_offset;    // offset in a C structure
} alink_field_info_t;

// note that in this structure the order of fields is the order
// in the XML file, not necessary the wire order
typedef struct __alink_message_info {
	const char *name;                                      // name of the message
	unsigned num_fields;                                   // how many fields in this message
	alink_field_info_t fields[ALINK_MAX_FIELDS];       // field information
} alink_message_info_t;

#define _MAV_PAYLOAD(msg) ((const char *)(&((msg)->checksum)+1))
#define _MAV_PAYLOAD_NON_CONST(msg) ((char *)(&((msg)->checksum)+1))

// checksum is immediately after the payload bytes
#define alink_ck_a(msg) *((msg)->len + (uint8_t *)_MAV_PAYLOAD_NON_CONST(msg))
#define alink_ck_b(msg) *(((msg)->len+(uint16_t)1) + (uint8_t *)_MAV_PAYLOAD_NON_CONST(msg))

typedef enum {
    ALINK_COMM_0,
    ALINK_COMM_1,
    ALINK_COMM_2,
    ALINK_COMM_3
} alink_channel_t;

/*
 * applications can set ALINK_COMM_NUM_BUFFERS to the maximum number
 * of buffers they will use. If more are used, then the result will be
 * a stack overrun
 */
#ifndef ALINK_COMM_NUM_BUFFERS
#if (defined linux) | (defined __linux) | (defined  __MACH__) | (defined _WIN32)
# define ALINK_COMM_NUM_BUFFERS 16
#else
# define ALINK_COMM_NUM_BUFFERS 4
#endif
#endif

typedef enum {
    ALINK_PARSE_STATE_UNINIT=0,
    ALINK_PARSE_STATE_IDLE,
    ALINK_PARSE_STATE_GOT_STX,
    ALINK_PARSE_STATE_GOT_SEQ,
    ALINK_PARSE_STATE_GOT_LENGTH_LO,
    ALINK_PARSE_STATE_GOT_LENGTH_HI,
    ALINK_PARSE_STATE_GOT_DESTID,
    ALINK_PARSE_STATE_GOT_SOURCEID,
    ALINK_PARSE_STATE_GOT_MSGID,
    ALINK_PARSE_STATE_GOT_CHKSUM,
    ALINK_PARSE_STATE_GOT_PAYLOAD,
    ALINK_PARSE_STATE_GOT_CRC1,
    ALINK_PARSE_STATE_GOT_BAD_CRC1
} alink_parse_state_t; ///< The state machine for the comm parser

typedef enum {
    ALINK_FRAMING_INCOMPLETE=0,
    ALINK_FRAMING_OK=1,
    ALINK_FRAMING_BAD_CRC=2
} alink_framing_t;

typedef struct __alink_status {
    uint8_t msg_received;               ///< Number of received messages
    uint8_t buffer_overrun;             ///< Number of buffer overruns
    uint8_t parse_error;                ///< Number of parse errors
    alink_parse_state_t parse_state;    ///< Parsing state machine
    uint16_t packet_idx;                ///< Index in current packet
    uint8_t current_rx_seq[ALINK_MAX_DEV_NUM];             ///< Sequence number of last packet received
    uint8_t current_tx_seq[ALINK_MAX_DEV_NUM];             ///< Sequence number of last packet sent
#if ALINK_PACKET_COUNT_ENABLED
    uint32_t packet_rx_success_count[ALINK_MAX_DEV_NUM];   ///< Received packets
    uint32_t packet_rx_drop_count[ALINK_MAX_DEV_NUM];      ///< Number of packet drops
    uint32_t packet_tx_success_count[ALINK_MAX_DEV_NUM];   ///< Received packets
    uint32_t packet_tx_fail_count[ALINK_MAX_DEV_NUM];   ///< Received packets
#endif  // ALINK_PACKET_COUNT_ENABLED
} alink_status_t;

typedef struct {
    uint32_t rx_bytes;
    uint32_t rx_frames;
    uint32_t rx_msgs;
    uint32_t rx_crc_fails;
    uint32_t rx_len_fails;
    uint32_t rx_msg_fails;
    uint32_t rx_no_buf;
    uint32_t rx_dup_seq;
    uint32_t tx_bytes;
    uint32_t tx_frames;
    uint32_t tx_msgs;
    uint32_t tx_fails;
    uint32_t tx_no_buf;
    uint32_t tx_retry_fails;
    uint32_t self_fails;
    uint32_t relay_msgs;
    uint32_t relay_fails;
}
ST_AlinkStts;

#define ALINK_BIG_ENDIAN 0
#define ALINK_LITTLE_ENDIAN 1

#endif /* ALINK_TYPES_H_ */
