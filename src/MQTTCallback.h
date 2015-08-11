/**
 * Project TO52
 */


#ifndef _MQTTCallback_H
#define _MQTTCallback_H

#include <string>

using namespace std;

class MQTTCallback {
public: 
    
    virtual void callback(string topic, string payload) = 0;
};

#endif //_MQTTCallback_H
