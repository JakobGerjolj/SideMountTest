#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "State.h"


lcdPort myLCD;
void setup() {
  myLCD.lcdInit();
  Serial.begin(115200);
}




void loop() {
  
if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK() && millis()%2000==0){
  myLCD.WriteStatus(AOKDOK);
  

}


}


