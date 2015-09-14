/**
 * Project TO52
 */


#ifndef _RING_H
#define _RING_H

#include <iostream>
#include <string>
#include <wiringPi.h>

#include "IO.h"

using namespace std;

class Ring: public IO {
public: 
	Ring();
    void play();
};

#endif //_RING_H
