#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "LED.h"


CAN myCAN;
lcdPort myLCD;
LED myLED;
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


start=millis();

if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
  myLCD.WriteStatus(AOKDOK);
  myLCD.WriteStatus(SCAN); 
  
}else{

  if(myLCD.GetCurrentDiagnostic()==CANDig){
    myLCD.SetCurrentDiagnostis(ANALOG);

  }

  if(!AnalogPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==ANALOG){
    
    myLCD.WriteStatus(ANOTOK);
    if(AnalogPins::is44OK()){
      myLCD.WriteStatus(A0OK);

    }else {
      myLCD.WriteStatusWithValue(A0NA0V, AnalogPins::GetValueFromPin(AnalogPins::Get44PIN()));

    }

    if(AnalogPins::is3_3OK()){
      myLCD.WriteStatus(A1OK);

    }else{
      myLCD.WriteStatusWithValue(A1NA1V, AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN()));

    }

    if(AnalogPins::is5OK()){
      myLCD.WriteStatus(A2OK);

    }else {
      myLCD.WriteStatusWithValue(A2NA2V, AnalogPins::GetValueFromPin(AnalogPins::Get5PIN()));

    }

    if(AnalogPins::is12OK()){
      myLCD.WriteStatus(A3OK);
    }else{
      myLCD.WriteStatusWithValue(A3NA3V, AnalogPins::GetValueFromPin(AnalogPins::Get12PIN()));
    }

  }else if(AnalogPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==ANALOG) {
    myLCD.WriteStatus(AOK);
    myLCD.SetCurrentDiagnostis(DIGITAL);
    }
  
   if(!DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL){ 
    myLCD.WriteStatus(DNOK); 
    if(DigitalPins::is3_3OK()){
      myLCD.WriteStatus(D1OK);

    }else {
      myLCD.WriteStatus(D1ND1V); 

    }

    if(DigitalPins::is4OK()){
      myLCD.WriteStatus(D2OK);
    }else {
      myLCD.WriteStatus(D2ND2V);
    }

  }else if(DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL) {
    myLCD.SetCurrentDiagnostis(ANALOG);
    myLCD.WriteStatus(DOK);
    }
  

}

if(myLCD.GetCurrentDiagnostic()==CANDig){
  myCAN.ProccessCAN();
  myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed()); 

  if(myCAN.ReturnZERO()){
    myLED.turnONLEDZERO();

  }
  if(myCAN.ReturnNFC()){
    myLED.turnONLEDNFC();

  }

}

  myLCD.SetLoopCounter(loopCount);
  myLCD.lcdRefresher();
  if(myLCD.GetCurrentDiagnostic()==CANDig){
  myCAN.ProccessCAN();
  myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed()); 

  if(myCAN.ReturnZERO()){
    myLED.turnONLEDZERO();

  }
  if(myCAN.ReturnNFC()){
    myLED.turnONLEDNFC();

  }

}
  myLED.LEDrefresher();
  end=millis();
  if((end-start)<60){
    delay(60-(end-start));
  }
  loopCount++;


}


