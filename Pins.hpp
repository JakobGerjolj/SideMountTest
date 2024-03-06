#pragma once
#include "AnalogPins.h"
#include "DigitalPins.h"
enum PinOK
{
    OK = 0,
    NOT_OK = 1
};

enum PinsEnum
{
    pin4V_SW = 0,
    pin3_3V_SW = 1,
    pin5V_SW = 2,
    pin12V = 3,
    pin3_3V = 4,
    pin4V = 5

};


class Pins
{
public:
    explicit Pins();
    void testPins();

private:
    PinOK m_pins[6];
};