#include "Arduino.h"

class LED{
public:
    void Init();
    void turnONLEDNFC();
    void turnONLEDZERO();
    void LEDrefresher();
private:   
    int ledNFC=5;
    int ledZERO=3;
    unsigned long timer1;
    unsigned long timer2;


};