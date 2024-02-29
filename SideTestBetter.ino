#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"

 CAN myCAN;

void setup() {
  myCAN.CANInit();
  Serial.begin(115200);
}




void loop() {
//Serial.print("MONALISA");
myCAN.ProccessCAN();
if(millis()%500==0){
Serial.println();
Serial.print("Temperatura 1: ");
Serial.println(myCAN.ReturnTemp1());
Serial.print("Temperatura 2: ");
Serial.println(myCAN.ReturnTemp2());
Serial.println("HAL: ");
Serial.println(myCAN.ReturnHAL());
Serial.println("ZERO: ");
Serial.println(myCAN.ReturnZERO());
Serial.println("LAST BUTTON PRESSED: ");
Serial.println(myCAN.ReturnLastButtonPressed());
Serial.println("VRNI NFC: ");
Serial.println(myCAN.ReturnNFC());
//delay(2000);
}

}
