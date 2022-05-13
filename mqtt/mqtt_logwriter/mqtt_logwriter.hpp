#include "../../src/mqtt_lib/TMqttClient.hpp"
#include "../../src/logger/Logger.hpp"

#include "../../src/file/FileEditer.hpp"

class LogWriterWithMQTT : public TMqttClient , public TLogger
{
public:
    LogWriterWithMQTT(string mqtt_id, string folder_path, string suffix);
    ~LogWriterWithMQTT();
    //
    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);

};


