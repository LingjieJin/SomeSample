#include "Logger.hpp"


TLogger::TLogger(string folder_path, string suffix)
{
    _folder_path = folder_path;
    _suffix = suffix;
}

TLogger::~TLogger()
{
}

/*
使用Logger类的参数构造 返回一个如下文件名:
folder_path + time(YYYY-MMM-DD) + . + suffix
*/
string TLogger::createLogSavePathWithTime()
{
    string time = TSysTimer::getTimeStamp_YYYY_MM_DD();
    string ret = _folder_path + time + "." + _suffix;

    return ret;
}

/*
返回一个如下文件名:
folder_path + time(YYYY-MMM-DD) + . + suffix
*/
string TLogger::createLogSavePathWithTime(string folder_path, string suffix)
{
    string time = TSysTimer::getTimeStamp_YYYY_MM_DD();
    string ret = folder_path + time + "." + suffix;
    
    return ret;
}

/*
生成一条如下记录：
[log_lvl: YYYY-MM-DD hh:mm:ss] content
*/
string TLogger::createLogRecord(uint8_t log_level, string &content)
{
    string time = TSysTimer::getTimeStamp_YYYY_MM_DD_HH_MM_SS();
    int time_size = time.size();
    int content_size = content.size();

    char temp[time_size+content_size+50];
    switch (log_level)
    {
        case LOG_ERROR:
        {
            snprintf(temp, sizeof(temp), "[ERROR: %s] %s", time.c_str(), content.c_str());
            break;
        }
        case LOG_WARING:
        {
            snprintf(temp, sizeof(temp), "[WARING: %s] %s", time.c_str(), content.c_str());
            break;
        }
        case LOG_INFO:
        {
            snprintf(temp, sizeof(temp), "[INFO: %s] %s", time.c_str(), content.c_str());
            break;
        }
        default:
        {
            snprintf(temp, sizeof(temp), "[ERR: %s] ERROR INPUT LEVEL", time.c_str());
            break;
        }
    }

    return temp;
}

