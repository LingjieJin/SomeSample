#include "mqtt_logwriter.hpp"


LogWriterWithMQTT::LogWriterWithMQTT(string mqtt_id, string folder_path, string suffix)
                    : TMqttClient(mqtt_id), TLogger(folder_path, suffix)
{

}

LogWriterWithMQTT::~LogWriterWithMQTT()
{
    
}

/*
成功连接到服务端
*/
void LogWriterWithMQTT::on_connect(int rc)
{
    string info = "success connect to host.";

    string time = TSysTimer::getTimeStamp_YYYY_MM_DD();
    string path = _folder_path + time + "." + _suffix ;

    string content = TLogger::createLogRecord(LOG_INFO, info);

    TFileEditer::writeLineToFileEnd(path, content);
}


/*
获取update的信息
*/
void LogWriterWithMQTT::on_message(const struct mosquitto_message *message)
{
    if(message->payloadlen)
    {
        string info =((char*)message->topic);
        info += ": ";
        info += ((char*)message->payload);
        std::cout << "Recv Message:" << info <<std::endl;
        
        string content = TLogger::createLogRecord(LOG_INFO, info);

        string time = TSysTimer::getTimeStamp_YYYY_MM_DD();
        string path = _folder_path + time + "." + _suffix ;
        TFileEditer::writeLineToFileEnd(path, content);
    }
}