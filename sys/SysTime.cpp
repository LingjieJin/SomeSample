#include "SysTime.hpp"


/*******************************************************************/

TSysTimer::TSysTimer(/* args */)
{
}

TSysTimer::~TSysTimer()
{
}

/*
获取系统 tick
return: 当前tick
*/
uint32_t TSysTimer::getSysTick_in_ms()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t) ( ts.tv_sec * 1000 ) + ( ts.tv_nsec / 1000000 );
}

void TSysTimer::SysSleep(uint32_t delay_ms)
{
    struct timespec ts;
    ts.tv_sec = (time_t)(delay_ms / 1000);
    ts.tv_nsec = (long) ((delay_ms - ts.tv_sec) * 1000000 );
    nanosleep(&ts, (struct timespec *)0);
}

uint32_t TSysTimer::DeltaTime(uint32_t &elapsed)
{
    uint32_t now;
    now = getSysTick_in_ms();

    if (now < elapsed)
    {
        elapsed =0;
    }
    return now - elapsed;
}



/*
获取clock差值，返回值以秒为单位
*/
double TSysTimer::getDeltaClock_in_s(clock_t &ref)
{
    clock_t now = clock();
    double duration = (double)(now - ref) / CLOCKS_PER_SEC;
    return duration;
}


/*
get localtime
return time string in YYYY-MM-DD hh:mm:ss
*/
string TSysTimer::getTimeStamp_YYYY_MM_DD_HH_MM_SS()
{
    time_t raw_time = time(NULL);
    
    struct tm *p_time;
    // 转换为本地时间
    p_time = localtime(&raw_time);

    char ret_time[20];
    sprintf(ret_time, "%04d-%02d-%02d %02d:%02d:%02d", \
                        p_time->tm_year + 1900, \
                        p_time->tm_mon +1, \
                        p_time->tm_mday, \
                        p_time->tm_hour, \
                        p_time->tm_min, \
                        p_time->tm_sec);
    /*
    char temp[50];
    strftime(temp, sizeof(temp), "%Y-%m-%d-%H:%M:%S", p_time);
    */

    string ret = ret_time;
    return ret;
}

/*
get localtime
return time string in YYYY-MM-DD
*/
string TSysTimer::getTimeStamp_YYYY_MM_DD()
{
    time_t raw_time = time(NULL);
    
    struct tm *p_time;
    // 转换为本地时间
    p_time = localtime(&raw_time);

    char ret_time[20];
    sprintf(ret_time, "%04d-%02d-%02d", \
                        p_time->tm_year + 1900, \
                        p_time->tm_mon +1, \
                        p_time->tm_mday);
    /*
    char temp[50];
    strftime(temp, sizeof(temp), "%Y-%m-%d-%H:%M:%S", p_time);
    */

    string ret = ret_time;
    return ret;
}


/**********************************************************************/
// sys time lib

uint32_t getTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


double getDeltaTime(struct timeval *ref_time)
{
    struct timeval now;
    gettimeofday(&now, NULL);

    double time_dif = now.tv_usec - ref_time->tv_usec;
    time_dif += 1000000 * (now.tv_sec - ref_time->tv_sec);

    time_dif = time_dif / 1000; // return ms

    return time_dif;
}


/***************************************************************/















