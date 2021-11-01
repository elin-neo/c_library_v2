#pragma once
// MESSAGE PUMP PACKING

#define MAVLINK_MSG_ID_PUMP 199


typedef struct __mavlink_pump_t {
 uint32_t speed; /*<  Rotation speed*/
 uint32_t level; /*<  Level of liquid*/
 float amount; /*<  Liquid discharge rate (liters/second)*/
 uint8_t status; /*<  Pump status*/
} mavlink_pump_t;

#define MAVLINK_MSG_ID_PUMP_LEN 13
#define MAVLINK_MSG_ID_PUMP_MIN_LEN 13
#define MAVLINK_MSG_ID_199_LEN 13
#define MAVLINK_MSG_ID_199_MIN_LEN 13

#define MAVLINK_MSG_ID_PUMP_CRC 167
#define MAVLINK_MSG_ID_199_CRC 167



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PUMP { \
    199, \
    "PUMP", \
    4, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_pump_t, status) }, \
         { "speed", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_pump_t, speed) }, \
         { "level", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_pump_t, level) }, \
         { "amount", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pump_t, amount) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PUMP { \
    "PUMP", \
    4, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_pump_t, status) }, \
         { "speed", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_pump_t, speed) }, \
         { "level", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_pump_t, level) }, \
         { "amount", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pump_t, amount) }, \
         } \
}
#endif

/**
 * @brief Pack a pump message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  Pump status
 * @param speed  Rotation speed
 * @param level  Level of liquid
 * @param amount  Liquid discharge rate (liters/second)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pump_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t status, uint32_t speed, uint32_t level, float amount)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMP_LEN];
    _mav_put_uint32_t(buf, 0, speed);
    _mav_put_uint32_t(buf, 4, level);
    _mav_put_float(buf, 8, amount);
    _mav_put_uint8_t(buf, 12, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PUMP_LEN);
#else
    mavlink_pump_t packet;
    packet.speed = speed;
    packet.level = level;
    packet.amount = amount;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PUMP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PUMP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
}

/**
 * @brief Pack a pump message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  Pump status
 * @param speed  Rotation speed
 * @param level  Level of liquid
 * @param amount  Liquid discharge rate (liters/second)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pump_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t status,uint32_t speed,uint32_t level,float amount)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMP_LEN];
    _mav_put_uint32_t(buf, 0, speed);
    _mav_put_uint32_t(buf, 4, level);
    _mav_put_float(buf, 8, amount);
    _mav_put_uint8_t(buf, 12, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PUMP_LEN);
#else
    mavlink_pump_t packet;
    packet.speed = speed;
    packet.level = level;
    packet.amount = amount;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PUMP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PUMP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
}

/**
 * @brief Encode a pump struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pump C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pump_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pump_t* pump)
{
    return mavlink_msg_pump_pack(system_id, component_id, msg, pump->status, pump->speed, pump->level, pump->amount);
}

/**
 * @brief Encode a pump struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pump C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pump_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pump_t* pump)
{
    return mavlink_msg_pump_pack_chan(system_id, component_id, chan, msg, pump->status, pump->speed, pump->level, pump->amount);
}

/**
 * @brief Send a pump message
 * @param chan MAVLink channel to send the message
 *
 * @param status  Pump status
 * @param speed  Rotation speed
 * @param level  Level of liquid
 * @param amount  Liquid discharge rate (liters/second)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pump_send(mavlink_channel_t chan, uint8_t status, uint32_t speed, uint32_t level, float amount)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMP_LEN];
    _mav_put_uint32_t(buf, 0, speed);
    _mav_put_uint32_t(buf, 4, level);
    _mav_put_float(buf, 8, amount);
    _mav_put_uint8_t(buf, 12, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMP, buf, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
#else
    mavlink_pump_t packet;
    packet.speed = speed;
    packet.level = level;
    packet.amount = amount;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMP, (const char *)&packet, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
#endif
}

/**
 * @brief Send a pump message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pump_send_struct(mavlink_channel_t chan, const mavlink_pump_t* pump)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pump_send(chan, pump->status, pump->speed, pump->level, pump->amount);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMP, (const char *)pump, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
#endif
}

#if MAVLINK_MSG_ID_PUMP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pump_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t status, uint32_t speed, uint32_t level, float amount)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, speed);
    _mav_put_uint32_t(buf, 4, level);
    _mav_put_float(buf, 8, amount);
    _mav_put_uint8_t(buf, 12, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMP, buf, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
#else
    mavlink_pump_t *packet = (mavlink_pump_t *)msgbuf;
    packet->speed = speed;
    packet->level = level;
    packet->amount = amount;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMP, (const char *)packet, MAVLINK_MSG_ID_PUMP_MIN_LEN, MAVLINK_MSG_ID_PUMP_LEN, MAVLINK_MSG_ID_PUMP_CRC);
#endif
}
#endif

#endif

// MESSAGE PUMP UNPACKING


/**
 * @brief Get field status from pump message
 *
 * @return  Pump status
 */
static inline uint8_t mavlink_msg_pump_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field speed from pump message
 *
 * @return  Rotation speed
 */
static inline uint32_t mavlink_msg_pump_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field level from pump message
 *
 * @return  Level of liquid
 */
static inline uint32_t mavlink_msg_pump_get_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field amount from pump message
 *
 * @return  Liquid discharge rate (liters/second)
 */
static inline float mavlink_msg_pump_get_amount(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a pump message into a struct
 *
 * @param msg The message to decode
 * @param pump C-struct to decode the message contents into
 */
static inline void mavlink_msg_pump_decode(const mavlink_message_t* msg, mavlink_pump_t* pump)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pump->speed = mavlink_msg_pump_get_speed(msg);
    pump->level = mavlink_msg_pump_get_level(msg);
    pump->amount = mavlink_msg_pump_get_amount(msg);
    pump->status = mavlink_msg_pump_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PUMP_LEN? msg->len : MAVLINK_MSG_ID_PUMP_LEN;
        memset(pump, 0, MAVLINK_MSG_ID_PUMP_LEN);
    memcpy(pump, _MAV_PAYLOAD(msg), len);
#endif
}
