#pragma once
#include <Arduino.h>
#include "PinHelpers.h"


class AnalogPins{
public:
    static bool getPinStatus(PinsEnum pins);
    static bool is3_3OK();
    static bool is5OK();
    static bool is12OK();
    static bool is44OK();
    static float GetValueFromPin(PinsEnum pin);
    static int Get3_3PIN();
    static int Get5PIN();
    static int Get12PIN();
    static int Get44PIN();
    static bool isAllPinsOK();

private:
    static const uint16_t Val3_3 = 682;   
    static const uint16_t Val5 = 516;     
    static const uint16_t Val12 = 225;    
    static const uint16_t Val44 = 954; 
    static const uint16_t napaka = 41; 
     static const int Pin4= A0;
    static const int Pin3_3= A1;
    static const int Pin5= A2;
    static const int Pin12= A3;
   

};