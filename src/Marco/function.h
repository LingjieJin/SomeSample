#ifndef __FUNCTION_H__
#define __FUNCTION_H__

/**
 * UTILS FUNCTIONS
 **/

#define MODBUS_GET_HIGH_BYTE(data) (((data) >> 8) & 0xFF)
#define MODBUS_GET_LOW_BYTE(data) ((data)&0xFF)
#define MODBUS_GET_INT64_FROM_INT16(tab_int16, index) \
    (((int64_t)tab_int16[(index)] << 48) |            \
     ((int64_t)tab_int16[(index) + 1] << 32) |        \
     ((int64_t)tab_int16[(index) + 2] << 16) |        \
     (int64_t)tab_int16[(index) + 3])
#define MODBUS_GET_INT32_FROM_INT16(tab_int16, index) ((tab_int16[(index)] << 16) | tab_int16[(index) + 1])
#define MODBUS_GET_INT16_FROM_INT8(tab_int8, index) ((tab_int8[(index)] << 8) | tab_int8[(index) + 1])
#define MODBUS_SET_INT16_TO_INT8(tab_int8, index, value) \
    do                                                   \
    {                                                    \
        tab_int8[(index)] = (value) >> 8;                \
        tab_int8[(index) + 1] = (value)&0xFF;            \
    } while (0)
#define MODBUS_SET_INT32_TO_INT16(tab_int16, index, value) \
    do                                                     \
    {                                                      \
        tab_int16[(index)] = (value) >> 16;                \
        tab_int16[(index) + 1] = (value);                  \
    } while (0)
#define MODBUS_SET_INT64_TO_INT16(tab_int16, index, value) \
    do                                                     \
    {                                                      \
        tab_int16[(index)] = (value) >> 48;                \
        tab_int16[(index) + 1] = (value) >> 32;            \
        tab_int16[(index) + 2] = (value) >> 16;            \
        tab_int16[(index) + 3] = (value);                  \
    } while (0)

#endif