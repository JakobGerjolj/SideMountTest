#include "AnalogPins.h"


bool s1=false;


void setup() {
  Serial.begin(115200);
}




void loop() {
  Serial.print("-------------------------------");
  Serial.println();
  Serial.print("ANALOG 33: ");
  Serial.print(AnalogPins::is3_3OK());
  Serial.println();

  Serial.print("ANALOG 5: ");
  Serial.print(AnalogPins::is5OK());
  Serial.println();

  Serial.print("ANALOG 12: ");
  Serial.print(AnalogPins::is12OK());
  Serial.println();

  Serial.print("ANALOG 44: ");
  Serial.print(AnalogPins::is44OK());
  Serial.println("");
 Serial.print("-------------------------------");

  delay(1000);

}
