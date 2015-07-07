/**
 * Project TO52
 */


#ifndef _MQTTCONNECTION_H
#define _MQTTCONNECTION_H

#include <functional>
#include <iostream>
#include <list>

#include "MQTT.h"
#include "MQTTCallback.h"

#define DEFAULT_QOS 1
#define DEFAULT_TIMEOUT 10000L

typedef struct {
    MQTTCallback *cb;
    string topic;
} MQTTCallback2D;

class MQTTConnection: public MQTT, public MQTTCallback {
public: 
    
    MQTTConnection(string clientID, string serverIP, int port);
    
    void connect();
    
    void disconnect();
    
    void reconnect();

    int getQOS();

    void setQOS(int qos);

    long getTimeout();

    void setTimeout(long timeout);

    void publish(string topic, string payload);

    void subscribe(string topic, MQTTCallback &cb);
    void subscribe(string topic);

    static int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);

    static void setHandler(MQTTCallback &c);

    virtual void callback(string topic, string payload);

    bool isConnected();

    void displayMQTTFrame(string topic, string payload);

private: 
    string clientID;
    string serverIP;
    int port;
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int qos = DEFAULT_QOS;
    long timeout = DEFAULT_TIMEOUT;

    list<MQTTCallback2D> listSubscribedTopic;
};

#endif //_MQTTCONNECTION_H
