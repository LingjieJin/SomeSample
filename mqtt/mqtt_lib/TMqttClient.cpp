#include "TMqttClient.hpp"

#include <cstring>

TMqttClient::TMqttClient()
{
}

TMqttClient::TMqttClient(string id)
{
    mosqpp::mosquittopp(id.c_str());
}

TMqttClient::~TMqttClient()
{

}


int TMqttClient::connectToHost(string host, int port, int keepalive)
{
    return connect(host.c_str(), port, keepalive);
}


int TMqttClient::publishToTopic(string &topic, string &payload)
{
    return publish(NULL, topic.c_str(), strlen(payload.c_str()), payload.c_str());
}

int TMqttClient::publishToTopic(const char* topic, const char* payload)
{
    return publish(NULL, topic, strlen(payload), payload);
}


int TMqttClient::subscribeTopic(string &topic)
{
    return subscribe(NULL, topic.c_str());
}



/*
回调函数
*/

void TMqttClient::on_connect(int rc)
{
    printf("connect with code %d .\n", rc);
    if (rc == 0)
    {
        printf("Connect succeeded.\n");
    }
}

void TMqttClient::on_connect_with_flags(int rc, int flags)
{
    return;
}

void TMqttClient::on_disconnect(int rc)
{
    printf("Disconnected with code %d.\n", rc);
    if (rc == 0)
    {
        printf("Disconnected succeeded.\n");
    }
}

void TMqttClient::on_publish(int mid)
{
    printf("Publication succeeded.\n");
    printf("Publisched (mid:%d).",mid);
}

void TMqttClient::on_message(const struct mosquitto_message *message)
{
    // local connect 仅用来进行本机间信息传递
    // on_message 仅负责接收 update信息
    // if (message->payloadlen)
    // {
    //     // 如果获取了 update 内容的信息
    //     if (!strcmp((char *)message->payload, "update ready"))
    //     {
    //         // image process 部分处理
    //         // 关闭程序 准备更新
    //     }
    //     else if (!strcmp((char *)message->payload, "update start"))
    //     {
    //         // update 部分处理
    //         // 确认 image process程序关闭?
    //         // 开始下载并重启
    //     }
    //     // ************** 输出 ***************************************
    //     printf("get the update message...\n");
    //     printf("%s\n%s\n", message->topic, message->payload);
    //     // ***********************************************************
    // }
    return ;
}

void TMqttClient::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    printf("Subscription succeeded.\n");
    int i;
    printf("Subscribed (mid:%d): %d",mid,granted_qos[0]);
    for (i=1; i<qos_count; i++)
    {
        printf(", %d",granted_qos[i]);
    }
    printf(".\n");
}

void TMqttClient::on_unsubscribe(int mid)
{
    return ;
}

void TMqttClient::on_log(int level, const char *str)
{
    /* Pring all log messages regardless of level. */
    printf("%s\n", str);
}

void TMqttClient::on_error()
{
    return ;
}