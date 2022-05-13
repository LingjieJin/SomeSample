#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>

typedef union UnionData_32 {
    uint32_t _uint32;
    float _float;
    void *_p;
} UData32_t;

typedef struct _Node_32_SP
{
    struct _Node_32_SP *next;
    UData32_t elemData;
} Node32_SP_t;

typedef struct _Node_32_DP
{
    struct _Node_32_DP *prev;
    struct _Node_32_DP *next;
    UData32_t elemData;
} Node32_DP_t;

#endif