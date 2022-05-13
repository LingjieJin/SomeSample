#ifndef TMQTTCLIENT_HPP
#define TMQTTCLIENT_HPP


#include <mosquittopp.h>

#include <string>

using std::string;

class TMqttClient : public mosqpp::mosquittopp
{
    public:
    
    public:
        /*
        function
        */
       TMqttClient();
        TMqttClient(string id);
        virtual ~TMqttClient();

        int connectToHost(string host, int port=1883, int keepalive=60);
        int publishToTopic(string &topic, string &payload);
        int publishToTopic(const char* topic, const char* payload);
        int subscribeTopic(string &topic);

       /*
       回调函数
       */
        virtual void on_connect(int rc);
		virtual void on_connect_with_flags(int rc, int flags);
        virtual void on_disconnect(int rc);
        virtual void on_publish(int mid);
        virtual void on_message(const struct mosquitto_message *message);
        virtual void on_subscribe(int mid, int qos_count, const int *granted_qos);
        virtual void on_unsubscribe(int mid);
        virtual void on_log(int level, const char * str);
        virtual void on_error();
};


#endif