#include "Pins.hpp"

Pins::Pins()
{

    m_pins[pin4V_SW]=NOT_OK;
    m_pins[pin3_3V_SW]=NOT_OK;
    m_pins[pin5V_SW]=NOT_OK;
    m_pins[pin12V]=NOT_OK;
    m_pins[pin3_3V]=NOT_OK;
    m_pins[pin4V]=NOT_OK;
}

void Pins::testPins(){


    if(AnalogPins::is44OK()){
        m_pins[pin4V_SW]=OK;
        m_values[pin4V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get44PIN());
        
    }else{
        m_pins[pin4V_SW]=NOT_OK;
        m_values[pin4V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get44PIN());
    }
     if(AnalogPins::is3_3OK()){
        m_pins[pin3_3V_SW]=OK;
        m_values[pin3_3V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN());

    }else{
        m_pins[pin3_3V_SW]=NOT_OK;
        m_values[pin3_3V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN());
    }
    if(AnalogPins::is5OK()){
        m_pins[pin5V_SW]=OK;
        m_values[pin5V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get5PIN());

    }else{
        m_pins[pin5V_SW]=NOT_OK;
        m_values[pin5V_SW]=AnalogPins::GetValueFromPin(AnalogPins::Get5PIN());
    }
     if(AnalogPins::is12OK()){
        m_pins[pin12V]=OK;
        m_values[pin12V]=AnalogPins::GetValueFromPin(AnalogPins::Get12PIN());
    }else{
        m_pins[pin12V]=NOT_OK;
        m_values[pin12V]=AnalogPins::GetValueFromPin(AnalogPins::Get12PIN());
    }
    if(DigitalPins::is3_3OK()){
        m_pins[pin3_3V]=OK;

    }else {
        m_pins[pin3_3V]=NOT_OK;

    }

    if(DigitalPins::is4OK()){
        m_pins[pin4V]=OK;
        m_values[pin4V] = 5;
    }else {
        m_pins[pin4V]=NOT_OK;
        m_values[pin4V]=0;

    }


}

PinOK Pins::GetMapElement(int index)
{


    return m_pins[index];
}

float Pins::GetValuesElement(int index)
{


    return m_values[index];
}
