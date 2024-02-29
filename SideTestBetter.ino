#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "State.h"

State state;

void setup() {

  Serial.begin(115200);
}




void loop() {


if(millis() % 1000 == 0) {
  Serial.println("STATE: ");
  Serial.println(state.getState());
  state.update();

  Serial.println("VALUES");
  Serial.println(AnalogPins::is3_3OK());
  Serial.println(AnalogPins::is5OK());
  Serial.println(AnalogPins::is12OK());
  Serial.println(AnalogPins::is44OK());
  Serial.println(DigitalPins::is3_3OK());
  Serial.println(DigitalPins::is4OK());
  
  }







}


