#include "lib/AnalogPins.h"
#include "lib/DigitalPins.h"
#include "lib/CAN.h"

CAN myCAN;

void setup() {
  Serial.begin(115200);
}




void loop() {
myCAN.ProccessCAN();
Serial.println();
Serial.print("Temperatura 1: ");
Serial.print(myCAN.ReturnTemp1());
Serial.println("Temperatura 2: ");
Serial.print(myCAN.ReturnTemp2());
Serial.println("HAL: ");
Serial.print(myCAN.ReturnHAL());
Serial.println("ZERO: ");
Serial.print(myCAN.ReturnZERO());
Serial.println("LAST BUTTON PRESSED: ");
Serial.print(myCAN.ReturnLastButtonPressed());
Serial.println("VRNI NFC: ");
Serial.print(myCAN.ReturnNFC());

delay(500);
}
