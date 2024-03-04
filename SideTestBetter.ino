#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "LED.h"

bool LEDTEST=false;

lcdPort myLCD;
LED myLED;
void setup() {
  myLCD.lcdInit();
  myLED.Init();
  Serial.begin(115200);
}




void loop() {
  if(!LEDTEST){
    myLED.turnONLEDNFC();
    myLED.turnONLEDZERO();
    LEDTEST=true;
  }

myLED.LEDrefresher();
}


