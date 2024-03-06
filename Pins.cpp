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
        
    }else{
        m_pins[pin4V_SW]=NOT_OK;
    }
     if(AnalogPins::is3_3OK()){
        m_pins[pin3_3V_SW]=OK;

    }else{
        m_pins[pin3_3V_SW]=NOT_OK;
    }
    if(AnalogPins::is5OK()){
        m_pins[pin5V_SW]=OK;

    }else{
        m_pins[pin5V_SW]=NOT_OK;
    }
     if(AnalogPins::is12OK()){
        m_pins[pin12V]=OK;

    }else{
        m_pins[pin12V]=NOT_OK;
    }


}