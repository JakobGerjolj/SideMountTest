#include "AnalogPins.h"

bool AnalogPins::getPinStatus(PinsEnum pins)
{
    bool result = false;

    switch (pins)
    {
    case pin4V_SW:
        result = is44OK();
        break;
    
    case pin3_3V_SW:
        result = is3_3OK();
        break;

    case pin5V_SW:
        result = is5OK();
        break;

    case pin12V:
        result = is12OK();
        break;

    default:
        break;
    }


    return false;
}

bool AnalogPins::is3_3OK()
{
    if(analogRead(Pin3_3) < Val3_3 + napaka && analogRead(Pin3_3)  > Val3_3 - napaka){
        return true;
    }
    else {
        return false;
    }
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

float AnalogPins::GetValueFromPin(PinsEnum pin)
{


    switch (pin)
    {
    case pin4V_SW:
        return analogRead(Pin4) * (5.0 / 1023.0);
        break;

    case pin3_3V_SW:
        return analogRead(Pin3_3) * (5.0 / 1023.0);
        break;

    case pin5V_SW:
        return analogRead(Pin5) * (5.0 / 1023.0);
        break;

    case pin12V:
        return analogRead(Pin12) * (5.0 / 1023.0);
        break;
    
    default:
        break;
    }

}

int AnalogPins::Get3_3PIN()
{
    return Pin3_3;
}

int AnalogPins::Get5PIN()
{
    return Pin5;
}

int AnalogPins::Get12PIN()
{
    return Pin12;
}

int AnalogPins::Get44PIN()
{
    return Pin4;
}

bool AnalogPins::isAllPinsOK()
{
    if(AnalogPins::is12OK() && AnalogPins::is3_3OK() && AnalogPins::is44OK() && AnalogPins::is5OK()){
        return true;

    }else return false;
}
