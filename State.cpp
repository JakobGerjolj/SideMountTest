#include "State.h"
#include "Arduino.h"


state State::getState()
{
    return CurrentState;
}

void State::update()
{
    if(AnalogPins::is12OK && AnalogPins::is3_3OK && AnalogPins::is44OK && AnalogPins::is5OK && DigitalPins::is3_3OK && DigitalPins::is4OK){

        CurrentState=PINS;
        }else {

            CurrentState=CAN;
            
            }


}
