//
//  MyTime.cpp
//  LocalTime
//
//  Created by kIng_martin on 2019/8/1.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include "MyTime.hpp"

#include <time.h>
//
void gmtime_tostring()
{
    time_t t_val;
    time(&t_val);
    struct tm *p;
    p = gmtime(&t_val);
    printf("%d%d%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf("%s%d%;%d;%d .\n", p->tm_wday, p->tm_hour, p->tm_min, p->tm_sec);
}

//
void localtime_tostring()
{
    time_t t_val;
    
}

//
void asctime_tostring()
{
    time_t t_val;
    struct tm t;
    time(&t_val);
    t = *gmtime(&t_val);
    char * a = asctime(&t);
        //    printf("%s .\n",asctime(gmtime(&tv)));
}

//
void ctime_tostring()
{
    time_t t_val;
    time(&t_val);
    printf("%s .\n",ctime(&t_val));
}

//
void clock_tostring()
{
    long i = 10000000L;
    clock_t start, finish;
    double duration;
    /* 测量一个事件持续的时间*/
    printf( "Time to do %ld empty loops is ", i );
    start = clock();
    while( i-- )
        ;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
}

//
void difftime_tostring()
{
    time_t start,end;
    start = time(NULL);
//    system("pause");
    end = time(NULL);
    printf("The pause used %f seconds.\n",difftime(end,start));
//    system("pause");
}

//
void mktime_tostring()
{
    struct tm t;
    time_t t_of_day;
        //
    t.tm_year=1997-1900;
    t.tm_mon=6;
    t.tm_mday=1;
    t.tm_hour=0;
    t.tm_min=0;
    t.tm_sec=1;
    t.tm_isdst=0;
    t_of_day=mktime(&t);
        //
    printf("%s", ctime(&t_of_day));
}

//
void strftime_tostring()
{
    struct tm *ptr;
    time_t lt;
    char str[80];
    char tmpbuf[128];
        //
    lt=time(NULL);
    ptr=localtime(&lt);
        //
    strftime(str,100,"It is now %I %p",ptr);
    strftime(tmpbuf, 128, "Today is %A, day %d of %B in the year %Y.\n", ptr);
    printf("%s", str);
    printf("%s", tmpbuf);
}
