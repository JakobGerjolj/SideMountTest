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

bool DigitalPins::isAllPinsOK()
{
    if(DigitalPins::is3_3OK() && DigitalPins::is4OK()){
    return true;
    }else return false;
}
