#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void getTimeStamp(char *dest, int model)
{
    time_t t = time(NULL);

    struct tm *p_time;
    // 转换为本地时间
    p_time = localtime(&t);

    switch (model)
    {
    case 1:
    {
        sprintf(dest, "%04d-%02d-%02d %02d:%02d:%02d",
                p_time->tm_year + 1900,
                p_time->tm_mon + 1,
                p_time->tm_mday,
                p_time->tm_hour,
                p_time->tm_min,
                p_time->tm_sec);
        break;
    }
    case 2:
    {
        sprintf(dest, "%04d-%02d-%02d",
                p_time->tm_year + 1900,
                p_time->tm_mon + 1,
                p_time->tm_mday);
        break;
    }
    default:
        break;
    }

    /*
    char temp[50];
    strftime(temp, sizeof(temp), "%Y-%m-%d-%H:%M:%S", p_time);
    */
}

double getDeltaClock_sec(clock_t *ref)
{
    clock_t now = clock();
    return (double)(now - *ref) / CLOCKS_PER_SEC;
}