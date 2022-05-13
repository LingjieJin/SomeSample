#ifndef LOGGER_HPP
#define LOGGER_HPP


// my head file
#include "../sys/SysTime.hpp"


#define LOG_ERROR 0
#define LOG_WARING 1
#define LOG_INFO 2


class TLogger
{
public:
    string _folder_path;
    string _suffix;
public:
    TLogger(string folder_path, string suffix);
    virtual ~TLogger();

    string createLogSavePathWithTime();


    static string createLogSavePathWithTime(string folder_path, string suffix);
    static string createLogRecord(uint8_t log_level, string &content);
};



#endif