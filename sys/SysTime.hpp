#ifndef SYSTIME_HPP
#define SYSTIME_HPP

#include <stdio.h>
#include <stdint.h>

#include <ctime>

#include <string>
#include <cstring>

using std::string;

class TSysTimer
{
private:
    /* data */
public:
    TSysTimer(/* args */);
    ~TSysTimer();

    static uint32_t getSysTick_in_ms();
    static void SysSleep(uint32_t delay_ms);
    static uint32_t DeltaTime(uint32_t &elapsed);

    static double getElapseTime(struct times);
    static double getDeltaClock_in_s(clock_t &ref);

    static string getTimeStamp_YYYY_MM_DD_HH_MM_SS();
    static string getTimeStamp_YYYY_MM_DD();
};


#include <sys/time.h>

uint32_t getTime();

double getDeltaTime(struct timeval *ref_time);



#endif