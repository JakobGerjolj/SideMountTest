#include "AnalogPins.h"
#include "DigitalPins.h"

bool s1=false;


void setup() {
  Serial.begin(115200);
}




void loop() {

  Serial.println("-----------------------------------------------");
  Serial.print("DIGITAL 33 value: ");
  Serial.print(DigitalPins::is3_3OK());
  Serial.println();

  Serial.print("DIGITAL 4 value: ");
  Serial.print(DigitalPins::is4OK());
  Serial.println();
  Serial.println("-----------------------------------------------");
  delay(1000);

}
