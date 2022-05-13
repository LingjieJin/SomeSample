//
//  curl_myhttp.hpp
//  mqtt_test
//
//  Created by kIng_martin on 2019/6/23.
//  Copyright © 2019 kIng_martin. All rights reserved.
//

#ifndef curl_myhttp_hpp
#define curl_myhttp_hpp

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ERROR_LOG(fmt,args...) {printf("\n[%s(line:%d)]:" fmt,__FILE__, __LINE__,##args);fflush(stdout);}
#define DEBUG_LOG(fmt,args...)  {printf("\n[%s(line:%d)%ld]:" fmt,__FILE__, __LINE__,time(NULL),##args);fflush(stdout);}
#define WARNING_LOG(fmt,args...)  {printf("\n[%s(line:%d)]:" fmt,__FILE__, __LINE__,##args);fflush(stdout);}
#define TRACE_LOG(fmt,args...)  {printf("\n[%s(line:%d)]:" fmt,__FILE__, __LINE__,##args);fflush(stdout);}
#define INFO_LOG(fmt,args...)  {printf("\n[%s(line:%d)]:" fmt,__FILE__, __LINE__,##args);fflush(stdout);}

#include <curl/curl.h>

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

class curlDownload
{
    
    friend size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
    
public:
    
    int download(char * sourceUrl, char * saveFile);
    
private:
    
    char szSourceUrl[1024];
    char szSaveFile[1024];
    
    FILE * fp;
    long long llCurrentSize;
    long long llTotoalSize;
    CURL *curl;
};

#endif /* curl_myhttp_hpp */
