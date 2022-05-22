#include <stdio.h>

// 一个32bit数据的位、字节读取操作
#define GET_LOW_BYTEO(x) ((x >> 0) & 0x000000ff)  /*获取第0个字节*/
#define GET_LOW_BYTE1(x) ((x >> 8) & 0x000000ff)  /*获取第1个字节*/
#define GET_LOW_BYTE2(x) ((x >> 16) & 0x000000ff) /*获取第2个字节*/
#define GET_LOW_BYTE3(x) ((x >> 24) & 0x000000ff) /*获取第3个字节*/

// 获取某一位
#define GET_BIT(x, bit) ((x & (1 << bit)) >> bit) /*获取第bit位*/

// 一个32bit数据的位、字节清零操作 清零某个字节
#define CLEAR_LOW_BYTEO(x) (x &= 0xffffff00) /*清零第0个字节*/
#define CLEAR_LOW_BYTE1(x) (x &= 0xffff00ff) /*清零第1个字节*/
#define CLEAR_LOW_BYTE2(x) (x &= 0xff00ffff) /*清零第2个字节*/
#define CLEAR_LOW_BYTE3(x) (x &= 0x00ffffff) /*清零第3个字节*/

// 清零某一位
#define CLEAR_BIT(x, bit) (x &= ~(1 << bit)) /* 清零第bit位 */

int main(void)
{
    {
        unsigned int a = 0x12345678;

        printf("0x%x的第0个字节为：0x%x\n", a, GET_LOW_BYTEO(a));
        printf("0x%x的第1个字节为：0x%x\n", a, GET_LOW_BYTE1(a));
        printf("0x%x的第2个字节为：0x%x\n", a, GET_LOW_BYTE2(a));
        printf("0x%x的第3个字节为：0x%x\n", a, GET_LOW_BYTE3(a));
    }

    {
        /*
        BIT: 0110 1000
        */
        unsigned int a = 0x6868;

        for (size_t i = 0; i < 16; i++)
        {
            printf("0x%x的第%ld位为：%d\n", a, i, GET_BIT(a, i));
        }
        
    }

    {
        unsigned int a = 0x12345678;
        unsigned int b = 0x12345678;
        unsigned int c = 0x12345678;
        unsigned int d = 0x12345678;

        printf("0x12345678的第0个字节清零后的值为：%#.8x\n",CLEAR_LOW_BYTEO(a));
        printf("0x12345678的第1个字节清零后的值为：%#.8x\n",CLEAR_LOW_BYTE1(b));
        printf("0x12345678的第2个字节清零后的值为：%#.8x\n",CLEAR_LOW_BYTE2(c));
        printf("0x12345678的第3个字节清零后的值为：%#.8x\n",CLEAR_LOW_BYTE3(d));
    }

    {
        /*
        BIT: 0110 1000
        */
        unsigned int a = 0x68;

        printf("0x68的第3位清零后的值位:%#x\n", CLEAR_BIT(a, 3));
    }

    return 0;
}