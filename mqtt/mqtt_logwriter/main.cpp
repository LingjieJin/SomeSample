#include <iostream>

#include "mqtt_logwriter.hpp"


int main(int argc, char* argv[])
{
    for(int i =0;i<argc;i++)
    {
        printf("%s.\n", argv[i]); 
    }

    string host;
    string topic;

    if(argc == 1)
    {
        host = "localhost";
        topic = "#";
    }
    else if( argc == 3)
    {
        host  = argv[1];
        topic = argv[2]; 
    }
    else
    {
        printf("请输入如下参数：./test localhost topic.\n");
        printf("默认./main打开 接受localhost所有的mqtt消息并保存在./LogFile/下.\n");
        return 0;
    }
    
    mosqpp::lib_init();

    LogWriterWithMQTT client = LogWriterWithMQTT("mqtt_loger", "./LogFile/", "txt");

    client.connectToHost(host);
    client.subscribeTopic(topic);

    client.loop_forever();

    mosqpp::lib_cleanup();

    return 0;
}