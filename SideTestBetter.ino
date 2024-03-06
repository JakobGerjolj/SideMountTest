#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "LED.h"
#include "Pins.hpp"
#include "PinHelpers.h"


CAN myCAN;
lcdPort myLCD;
LED myLED;
Pins pins;

unsigned long loopCount=0;
unsigned long start;
unsigned long end;

void setup() {
  DigitalPins::init();
  myLCD.lcdInit();
  myLED.Init();
  myCAN.CANInit();
  Serial.begin(115200);

}





void loop() {
//Serial.print("LOOPONJA");

auto allPinsOK = pins.testPins();


//Serial.println(allPinsOK);
if(allPinsOK != 0)
{
 
  auto faultyPins = pins.getFaultyPins();

  if(faultyPins==nullptr){
    Serial.println("I am null");
delay(500);
  }else Serial.println("I am not null PTR");
 //  Serial.println(faultyPins[0].pinName);
  for(int x=0;x<(sizeof(faultyPins)/sizeof(faultyPins[0]));x++){
    Serial.println("---------------------------------------------");
    Serial.print("Pin name:");
    Serial.println(faultyPins[x].pinName);
    Serial.print("Pin boolean:");
    Serial.println(faultyPins[x].isOK);
    Serial.print("Pin value: ");
    Serial.println(faultyPins[x].pinValue);
    Serial.println("---------------------------------------------");
    delay(2000);
  }

}







// start=millis();
// Pin Temp;
// if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
//   //myLCD.WriteStatus(AOKDOK);
//   myLCD.WriteStatus(SCAN); 
  
// }else{



  // if(myLCD.GetCurrentDiagnostic()==CANDig){
  //   myLCD.SetCurrentDiagnostis(ANALOG);

  // }

  // if(!AnalogPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==ANALOG){
    
  //   myLCD.WriteStatus(ANOTOK);
  //   if(AnalogPins::is44OK()){
  //     myLCD.WriteStatus(A0OK);

  //   }else {
  //     myLCD.WriteStatusWithValue(A0NA0V, AnalogPins::GetValueFromPin(AnalogPins::Get44PIN()));

  //   }

  //   if(AnalogPins::is3_3OK()){
  //     myLCD.WriteStatus(A1OK);

  //   }else{
  //     myLCD.WriteStatusWithValue(A1NA1V, AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN()));

  //   }

  //   if(AnalogPins::is5OK()){
  //     myLCD.WriteStatus(A2OK);

  //   }else {
  //     myLCD.WriteStatusWithValue(A2NA2V, AnalogPins::GetValueFromPin(AnalogPins::Get5PIN()));

  //   }

  //   if(AnalogPins::is12OK()){
  //     myLCD.WriteStatus(A3OK);
  //   }else{
  //     myLCD.WriteStatusWithValue(A3NA3V, AnalogPins::GetValueFromPin(AnalogPins::Get12PIN()));
  //   }

  // }else if(AnalogPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==ANALOG) {
  //   myLCD.WriteStatus(AOK);
  //   myLCD.SetCurrentDiagnostis(DIGITAL);
  //   }
  
  //  if(!DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL){ 
  //   myLCD.WriteStatus(DNOK); 
  //   if(DigitalPins::is3_3OK()){
  //     myLCD.WriteStatus(D1OK);

  //   }else {
  //     myLCD.WriteStatus(D1ND1V); 

  //   }

  //   if(DigitalPins::is4OK()){
  //     myLCD.WriteStatus(D2OK);
  //   }else {
  //     myLCD.WriteStatus(D2ND2V);
  //   }

  // }else if(DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL) {
  //   myLCD.SetCurrentDiagnostis(ANALOG);
  //   myLCD.WriteStatus(DOK);
  //   }
  

// }

// if(myLCD.GetCurrentDiagnostic()==CANDig){
//   myCAN.ProccessCAN();
//   myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed()); 

//   if(myCAN.ReturnZERO()){
//     myLED.turnONLEDZERO();

//   }
//   if(myCAN.ReturnNFC()){
//     myLED.turnONLEDNFC();

//   }

// }

//   myLCD.SetLoopCounter(loopCount);
//   myLCD.lcdRefresher();
//   if(myLCD.GetCurrentDiagnostic()==CANDig){
//   myCAN.ProccessCAN();
//   myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed()); 

//   if(myCAN.ReturnZERO()){
//     myLED.turnONLEDZERO();

//   }
//   if(myCAN.ReturnNFC()){
//     myLED.turnONLEDNFC();

//   }

// }
//   myLED.LEDrefresher();
//   end=millis();
//   if((end-start)<60){
//     delay(60-(end-start));
//   }
//   loopCount++;


delay(1000);
}


