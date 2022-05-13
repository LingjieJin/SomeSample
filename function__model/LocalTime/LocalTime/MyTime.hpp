//
//  MyTime.hpp
//  LocalTime
//
//  Created by kIng_martin on 2019/8/1.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#ifndef MyTime_hpp
#define MyTime_hpp

#include <stdio.h>
//#include <time.h>
#include <ctime>

/*
 function : gmtime
 将日历时间转化为世界标准时间（即格林尼治时间）
 //
 struct tm
 {
 int tm_sec;       秒 – 取值区间为[0,59]
 int tm_min;        分 - 取值区间为[0,59]
 int tm_hour;       时 - 取值区间为[0,23]
 int tm_mday;       一个月中的日期 - 取值区间为[1,31]
 int tm_mon;        月份（从一月开始，0代表一月） - 取值区间为[0,11]
 int tm_year;       年份，其值等于实际年份减去1900
 int tm_wday;       星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推
 int tm_yday;       从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推
 int tm_isdst;      夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。
 };
 */
void gmtime_tostring();

/*
 function : localtime localtime()
 函数是将日历时间转化为本地时间
 */
void localtime_tostring();

/*
 func : char * asctime(const struct tm * timeptr);
 将时间和日期以字符串的格式表示。
 星期几 月份 日期 时:分:秒 年\n\0
 */
void asctime_tostring();

/*
 func : char * ctime(const time_t *timer);
 将日期和时间以字符串的格式表示。
 星期几 月份 日期 时:分:秒 年\n\0
 */
void ctime_tostring();

/*
 function : clock_t clock( void );
 “开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数
 */
void clock_tostring();

/*
 function : time_t mktime(struct tm * timeptr);
 
 */
void mktime_tostring();


/*
 function : strftime（）
 函数将时间格式化为我们想要的格式
 //
 %a 星期几的简写
 %A 星期几的全称
 %b 月分的简写
 %B 月份的全称
 %c 标准的日期的时间串
 %C 年份的后两位数字
 %d 十进制表示的每月的第几天
 %D 月/天/年
 %e 在两字符域中，十进制表示的每月的第几天
 %F 年-月-日
 %g 年份的后两位数字，使用基于周的年
 %G 年分，使用基于周的年
 %h 简写的月份名
 %H 24小时制的小时
 %I 12小时制的小时
 %j 十进制表示的每年的第几天
 %m 十进制表示的月份
 %M 十时制表示的分钟数
 %n 新行符
 %p 本地的AM或PM的等价显示
 %r 12小时的时间
 %R 显示小时和分钟：hh:mm
 %S 十进制的秒数
 %t 水平制表符
 %T 显示时分秒：hh:mm:ss
 %u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）
 %U 第年的第几周，把星期日做为第一天（值从0到53）
 %V 每年的第几周，使用基于周的年
 %w 十进制表示的星期几（值从0到6，星期天为0）
 %W 每年的第几周，把星期一做为第一天（值从0到53）
 %x 标准的日期串
 %X 标准的时间串
 %y 不带世纪的十进制年份（值从0到99）
 %Y 带世纪部分的十制年份
 %z %Z 时区名称，如果不能得到时区名称则返回空字符。
 %% 百分号
 */
void strftime_tostring();

#endif /* MyTime_hpp */
