/**
 * Project TO52
 */


#ifndef _RING_H
#define _RING_H

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <wiringPi.h>

using namespace std;

class Ring {
public: 
	Ring();
    void play();
    void stop();
private:
	thread *t;

};

#endif //_RING_H
