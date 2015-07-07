#include "MQTTConnection.h"

int main(void){
    
    MQTTConnection c("A","192.168.0.31",1883);

    c.connect();

    c.publish("/test","TO52");
    c.subscribe("/test");
    c.subscribe("/test2", c);
    c.subscribe("/test3", c);
    c.subscribe("/test4", c);

    while(c.isConnected());

    return 1;
}
