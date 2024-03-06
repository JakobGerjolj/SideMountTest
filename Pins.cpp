#include "Pins.hpp"

Pins::Pins()
{

    m_pins[pin4V_SW].pinName = "pin4V_SW";
    m_pins[pin3_3V_SW].pinName = "pin3_3V_SW";
    m_pins[pin5V_SW].pinName = "pin5V_SW";
    m_pins[pin12V].pinName = "pin12V";
    m_pins[pin3_3V].pinName = "pin3_3V";
    m_pins[pin4V].pinName = "pin4V";
}

int Pins::testPins()
{
    int faultyPins = 0;

    for (int x = 0; x < 4; x++)
    {
        m_pins[x].isOK = AnalogPins::getPinStatus(static_cast<PinsEnum>(x));
        m_pins[x].pinValue = AnalogPins::GetValueFromPin(static_cast<PinsEnum>(x));
        if (m_pins[x].isOK == false)
        {
            faultyPins++;
        }
    }

    for (int x = 4; x < 6; x++)
    {
        if (DigitalPins::isPinOk(static_cast<PinsEnum>(x)))
        {
            m_pins[x].isOK = true;
            m_pins[x].pinValue = 5;
        }
        else
        {
            m_pins[x].pinValue = 0;
            m_pins[x].isOK = false;
            faultyPins++;
        }
    }

    return faultyPins;

    // if(AnalogPins::getPinStatus(pin4V_SW)){
    //     m_pins[pin4V_SW].isOK = true;
    //     m_pins[pin4V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get44PIN());

    // }else{
    //     m_pins[pin4V_SW].isOK= false;
    //     m_pins[pin4V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get44PIN());
    //     isAllOK = false;

    // }

    // if(AnalogPins::is3_3OK()){
    //     m_pins[pin3_3V_SW].isOK=true;
    //     m_pins[pin3_3V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN());

    // }else{
    //     isAllOK = false;
    //     m_pins[pin3_3V_SW].isOK=false;
    //     m_pins[pin3_3V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN());
    // }
    // if(AnalogPins::is5OK()){
    //     m_pins[pin5V_SW].isOK=true;
    //     m_pins[pin5V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get5PIN());

    // }else{
    //     isAllOK = false;
    //     m_pins[pin5V_SW].isOK=false;
    //     m_pins[pin5V_SW].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get5PIN());
    // }
    //  if(AnalogPins::is12OK()){
    //     m_pins[pin12V].isOK=true;
    //     m_pins[pin12V].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get12PIN());
    // }else{
    //     isAllOK = false;
    //     m_pins[pin12V].isOK=false;
    //     m_pins[pin12V].pinValue=AnalogPins::GetValueFromPin(AnalogPins::Get12PIN());
    // }
    // if(DigitalPins::is3_3OK()){
    //     m_pins[pin3_3V].isOK=true;
    //     m_pins[pin3_3V].pinValue=5;

    // }else {
    //     isAllOK = false;
    //     m_pins[pin3_3V].isOK=false;
    //     m_pins[pin3_3V].pinValue=0;
    // }

    // if(DigitalPins::is4OK()){
    //     m_pins[pin4V].isOK=true;
    //     m_pins[pin4V].pinValue = 5;
    // }else {
    //     isAllOK = false;
    //     m_pins[pin4V].isOK=false;
    //     m_pins[pin4V].pinValue=0;

    // }
}

Pin* Pins::getFaultyPins()
{

    Pin temp[numberOfBadPins()];
    int tempIndex = 0;
    for (int x = 0; x < 6; x++)
    {

        if (m_pins[x].isOK == false)
        {
            temp[tempIndex] = m_pins[x];
            tempIndex++;
        }
    }

    return temp;
}

int Pins::numberOfBadPins()
{
    int temp = 0;

    for (int x = 0; x < 6; x++)
    {
        if (m_pins[x].isOK == false)
        {
            temp++;
        }
    }
    return temp;
}
