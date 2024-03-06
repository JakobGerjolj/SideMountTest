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
    void getFaultyPins(Pin * arrPin);

    
private:
    int numberOfBadPins();
    Pin m_pins[6];
};