#include "AnalogPins.h"

bool AnalogPins::is3_3OK(){
    if(analogRead(Pin3_3) < Val3_3 + napaka && analogRead(Pin3_3)  > Val3_3 - napaka)
        return true;
    else return false;

}

bool AnalogPins::is5OK(){
    if(analogRead(Pin5)  < Val5 + napaka && analogRead(Pin5)  > Val5 - napaka)
        return true;
    else return false;

}

bool AnalogPins::is12OK(){
    if(analogRead(Pin12)  < Val12 + napaka && analogRead(Pin12)  > Val12 - napaka)
        return true;
    else return false;

}

bool AnalogPins::is44OK(){
    if(analogRead(Pin4)  < Val44 + napaka && analogRead(Pin4) > Val44 - napaka)
        return true;
    else return false;
}

float AnalogPins::GetValueFromPin(int pin)
{

    return analogRead(pin) * (5.0 / 1023.0);

}
