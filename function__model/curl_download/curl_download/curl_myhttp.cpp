//
//  curl_myhttp.cpp
//  mqtt_test
//
//  Created by kIng_martin on 2019/6/23.
//  Copyright © 2019 kIng_martin. All rights reserved.
//

#include "curl_myhttp.hpp"

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    if (userdata == NULL)
    {
        ERROR_LOG("write_callback userdata error");
        return -1;
    }
    
    curlDownload * download = (curlDownload *)userdata;
    size_t res = fwrite(ptr, size, nmemb, download->fp);
    if (res <= 0)
    {
        ERROR_LOG("[%s] write(%lld) faild@%s",download->szSourceUrl,download->llCurrentSize,strerror(errno));
        return -1;
    }
    
    download->llCurrentSize += res;
    return res;
}

int curlDownload::download(char * sourceUrl, char * saveFile)
{
    
    CURLcode res;
    int ret = -1;
    fp      = NULL;
    llCurrentSize = 0;
    llTotoalSize  = 0; //totalSize;
    
    memset(szSourceUrl,0,sizeof(szSourceUrl));
    memset(szSaveFile,0,sizeof(szSaveFile));
    
    memcpy(szSourceUrl, sourceUrl, strlen(sourceUrl));
    memcpy(szSaveFile, saveFile, strlen(saveFile));
    
    do
    {
        fp = fopen(szSaveFile,"wb");
        
        if (fp == NULL)
        {
            ERROR_LOG("[%s] open %s faild@%s",szSourceUrl, szSaveFile, strerror(errno));
            break;
        }
        
        /* get a curl handle */
        curl = curl_easy_init();
        
        if (!curl)
        {
            ERROR_LOG("[%s] curl_easy_init error@%s",szSourceUrl,curl_easy_strerror(res));
            break;
        }
        
        res = curl_easy_setopt(curl, CURLOPT_URL, szSourceUrl);
        
        if (CURLE_OK != res)
        {
            ERROR_LOG("[%s] CURLOPT_URL error@%s",szSourceUrl,curl_easy_strerror(res));
            break;
        }
        
        res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        if (CURLE_OK != res)
        {
            ERROR_LOG("[%s] CURLOPT_WRITEFUNCTION error@%s",szSourceUrl,curl_easy_strerror(res));
            break;
        }
        
        res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
        
        if (CURLE_OK != res)
        {
            ERROR_LOG("[%s] CURLOPT_WRITEDATA error@%s",szSourceUrl,curl_easy_strerror(res));
            break;
        }
        
        res = curl_easy_perform(curl);
        
        if (CURLE_OK != res)
        {
            ERROR_LOG("[%s] curl_easy_perform error@%s",szSourceUrl,curl_easy_strerror(res));
            break;
        }
        
        /* download succ */
        INFO_LOG("[%s] download succ and save as %s", szSourceUrl, szSaveFile);
        ret = 0;
        
    } while(0);
    
    if (fp == NULL)
    {
        return ret;
    }
    
    fclose(fp);
    fp = NULL;
    
    if (curl)
    {
        curl_easy_cleanup(curl);
        curl = NULL;
    }
    
    return ret;
    
}
