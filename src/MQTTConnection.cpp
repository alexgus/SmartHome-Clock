/**
 * Project TO52
 */

#include "MQTTConnection.h"

/**
 * MQTTConnection implementation
 */

MQTTCallback *handler;

void recvHandler(string &topic, string &payload){
    handler->callback(topic,payload);
}

void MQTTConnection::setHandler(MQTTCallback &c){
    handler = &c;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

MQTTConnection::MQTTConnection(string clientID, string serverIP, int port){
    this->clientID = clientID;
    this->serverIP = serverIP;
    this->port = port;
    MQTTConnection::setHandler(*this);
}

void MQTTConnection::connect() {
    MQTTClient_create(&this->client, string(this->serverIP + string(":") + to_string(this->port)).c_str(), this->clientID.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL);

    this->conn_opts.keepAliveInterval = 20;
    this->conn_opts.cleansession = 1;
    
    MQTTClient_setCallbacks(this->client, NULL, connlost, MQTTConnection::msgarrvd, NULL);

    if(MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect\n");
        exit(-1);
    }
}

bool MQTTConnection::isConnected(){
     return MQTTClient_isConnected(this->client);
}

void MQTTConnection::disconnect() {
    MQTTClient_disconnect(this->client, 10000);
    MQTTClient_destroy(&this->client);
}

void MQTTConnection::reconnect() {
    this->disconnect();
    this->connect();
}

int MQTTConnection::getQOS(){
    return this->qos;
}

void MQTTConnection::setQOS(int qos){
    this->qos = qos;
}

long MQTTConnection::getTimeout(){
    return this->timeout;
}

void MQTTConnection::setTimeout(long timeout){
    this->timeout = timeout;
}

void MQTTConnection::publish(string topic, string payload){
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    pubmsg.payload = (void*) payload.c_str();
    pubmsg.payloadlen = payload.length();
    pubmsg.qos = this->qos;
    pubmsg.retained = 0;

    MQTTClient_publishMessage(this->client, topic.c_str(), &pubmsg, &token);

    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(this->timeout/1000), payload.c_str(), topic.c_str(), this->clientID.c_str());

    MQTTClient_waitForCompletion(this->client, token, this->timeout);

    printf("Message with delivery token %d delivered\n", token);
}

void MQTTConnection::subscribe(string topic, MQTTCallback &cb){
    MQTTClient_subscribe(this->client, topic.c_str(), this->qos);

    MQTTCallback2D store = { &cb , topic };

    listSubscribedTopic.push_back(store);
}

void MQTTConnection::subscribe(string topic){
    MQTTClient_subscribe(this->client, topic.c_str(), this->qos);
}

void MQTTConnection::callback(string topic, string payload){
    list<MQTTCallback2D>::iterator it = listSubscribedTopic.begin();
    while(it != listSubscribedTopic.end() && it->topic != topic)
        ++it;

    if(it == listSubscribedTopic.end())
        this->displayMQTTFrame(topic,payload);
    else{
        if(it->cb != this)
            it->cb->callback(topic,payload);
        else
            this->displayMQTTFrame(topic,payload);
    }
}

void MQTTConnection::displayMQTTFrame(string topic, string payload){
    cout << topic << " " << payload << endl;
}

int MQTTConnection::msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    recvHandler(*(new string(topicName)),*(new string((const char*)message->payload,(size_t) message->payloadlen)));

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

