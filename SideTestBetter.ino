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
  
// if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
//   myLCD.WriteStatus(AOKDOK);
//   myLCD.WriteStatus(SCAN);

// }else if(!AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
//   myLCD.WriteStatus(DOK);
//   myLCD.WriteStatus(ANOTOK);
 
// }

// myLCD.lcdRefresher();
Serial.println(AnalogPins::is12OK());
Serial.println(AnalogPins::isAllPinsOK());
Serial.println(DigitalPins::isAllPinsOK());
delay(1000);
}


