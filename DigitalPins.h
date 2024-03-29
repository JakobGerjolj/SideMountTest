#pragma once
#include <Arduino.h>
#include "PinHelpers.h"


class DigitalPins{
public:
    static void init();
    static bool is3_3OK();
    static bool is4OK();
    static bool isPinOk(PinsEnum pins);
    static bool isAllPinsOK();

private:
    static const int Pin3_3=7;
    static const int Pin_4=6;

};