#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

/*
在C99中规定宏也可以像函数一样带可变的参数，如：
#define LOG(format, ...) fprintf(stdout, format, __VA_ARGS__)  
其中，...表示可变参数列表，__VA_ARGS__在预处理中，会被实际的参数集（实参列表）所替换。

同时gcc还支持带可以变参数名的方式（注意：VC不支持）：
#define LOG(format, args...) fprintf(stdout, format, args) 

同样，args在预处理过程中，会被实际的参数集所替换。其用法和上面的方式一样，只是参数的符号有变。
需要注意的是，上述两种方式的可变参数不能省略，尽管可以传一个空参数进去。说到这里，有必要提一下“##”连接符号的用法，“##”的作用是对token进行连接，上例中format，args，__VA_ARGS都可以看作是token，如果token为空，“##”则不进行连接，所以允许省略可变参数。对上述2个示例的改造：

#define LOG(format, ...) fprintf(stdout, format, ##__VA_ARGS__)  
#define LOG(format, args...) fprintf(stdout, format, ##args)  

！！！C++11编译时候，宏和字符串之间需要加空格区分！！！
*/

#ifdef DEBUG_SW
#define DPRINTF(fmt,...) (\
                            fprintf(stdout,"-D- File:<%s>, Function:[%s], Line:%05d ",__FILE__,__FUNCTION__,__LINE__),\
                            fprintf(stdout, fmt, ##__VA_ARGS__),\
                            fprintf(stdout, "\n")\
                            )

#ifdef GCC
#define PRINTF(fmt,args...) fprintf(stdout, fmt, args)
#else
#define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#endif

#ifdef CPP11
#define DEBUG1(format,...) fprintf(stdout, "File: " __FILE__ ", Line: %05d: " format "\n", __LINE__, ##__VA_ARGS__)
#endif

#else
#define DPRINTF(fmt,...)
#define PRINTF(format, ...)
#endif


#ifdef DEBUG_FUNCTION
#endif


#endif