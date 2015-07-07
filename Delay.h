/**
 * Project TO52
 */


#ifndef _DELAY_H
#define _DELAY_H

#include <unistd.h>

class Delay {
public: 
    
    Delay();
    
    /**
     * @param s
     */
    Delay(int s);
    
    void play();
private: 
    int sDelay;
    int defaultDelay = 300;
};

#endif //_DELAY_H
