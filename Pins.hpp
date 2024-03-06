#pragma once
#include "AnalogPins.h"
#include "DigitalPins.h"
#include <string.h>

#include "PinHelpers.h"


struct Pin
{
    String pinName;
    float pinValue;
    bool isOK{false};

};





class Pins
{
public:
    explicit Pins();
    int testPins();
    Pin* getFaultyPins();

    
private:
    int numberOfBadPins();
    Pin m_pins[6];
};