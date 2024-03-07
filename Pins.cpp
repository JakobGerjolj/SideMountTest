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

}

void Pins::getFaultyPins(Pin * arrPin)
{

   // Pin temp[numberOfBadPins()];
    int tempIndex = 0;
    for (int x = 0; x < 6; x++)
    {

        if (m_pins[x].isOK == false)
        {
            arrPin[tempIndex] = m_pins[x];
           // temp[tempIndex] = m_pins[x];
            tempIndex++;
        }
    }

    
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
