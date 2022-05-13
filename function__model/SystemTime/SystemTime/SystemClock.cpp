//
//  SystemClock.cpp
//  SystemTime
//
//  Created by kIng_martin on 2019/8/1.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include "SystemClock.hpp"

//
// 获取系统时间 精确到纳秒
int clock_gettime(int clk_id, struct timespec* t)
{
    struct timeval now;
    int rv = gettimeofday(&now, NULL);
    if (rv)
    {
        return rv;
    }
    // 将当前时间 赋值
    t->tv_sec = now.tv_sec; // s 秒
    t->tv_nsec = now.tv_usec * 1000; // ms e微秒-> ns 纳秒
    return 0;
}

//
// 获取系统当前的tick
long SysGetTick()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);    // 获取从系统启动这一刻起开始计时,不受系统时间被用户改变的影响
    return (long)(ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
}

//
// 系统睡眠
void SysSleep(long delay_ms)
{
    struct timespec ts;
    ts.tv_sec = (time_t)(delay_ms / 1000);
    ts.tv_nsec = (long)((delay_ms - ts.tv_sec) * 1000000);  // ms 毫秒
                                                            //
                                                            // nanosleep()函数会导致当前的线程将暂停执行,直到rqtp参数所指定的时间间隔。或者在指定时间间隔内有信号传递到当前线程，将引起当前线程调用信号捕获函数或终止该线程
                                                            // 如果rmtp参数不为空，它所引用的timespec结构更新为包含剩余时间的间隔量（请求的时间减去实际睡眠时间）
                                                            // rmtp参数为NULL，不返回的剩余时间
    nanosleep(&ts, (struct timespec *)0);
}

//
// 系统堵塞时间过渡
long DeltaTime(long &elapsed)
{
    long now_tick;
    now_tick = SysGetTick();
        // check for rollover
    if (now_tick < elapsed)
    {
        elapsed = 0;
    }
    return now_tick - elapsed;
}
