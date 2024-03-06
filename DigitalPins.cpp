#pragma once
#include "DigitalPins.h"


void DigitalPins::init(){
    pinMode(Pin3_3,INPUT);
    pinMode(Pin_4, INPUT);

}

bool DigitalPins::is3_3OK()
{
    if(digitalRead(Pin3_3)==HIGH){
        return true;

    }else return false;
    
}

bool DigitalPins::is4OK()
{
    if(digitalRead(Pin_4)==HIGH){
        return true;

    }else return false;
}

bool DigitalPins::isPinOk(PinsEnum pins)
{
    switch (pins)
    {
    case pin3_3V:
        return is3_3OK();
        break;
    
    case pin4V:
        return is4OK();
        break;
    default:
        break;
    }



    return false;
}

bool DigitalPins::isAllPinsOK()
{
    if(DigitalPins::is3_3OK() && DigitalPins::is4OK()){
    return true;
    }else return false;
}
