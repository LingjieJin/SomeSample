#include <stdio.h>

/*
* 
*/
int isLittleEndain()
{
    // C/C++：对于多字节数据，取地址是取的数据对象的第一个字节的地址，也就是数据的低地址
    unsigned int val = 'A';
    unsigned char *p = (unsigned char *)&val;
    
    return *p == 'A' ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (isLittleEndain()==1)
    {
        printf("small.\n");
    }
    else
    {
        printf("big.\n");
    }
    return 0;
}
