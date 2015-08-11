/**
 * Project TO52
 */


#ifndef _IO_H
#define _IO_H

class IO {
public: 
    
    /**
     * @param pin
     * @param mode
     */
    void pinMode(int pin, int mode);
    
    /**
     * @param pin
     * @param value
     */
    void digitalWrite(int pin, int value);
    
    /**
     * @param pin
     */
    void digitalRead(int pin);
};

#endif //_IO_H