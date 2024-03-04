#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "LED.h"

CAN myCAN;
lcdPort myLCD;
LED myLED;
unsigned long start;
unsigned long end;
void setup() {
  myLCD.lcdInit();
  myLED.Init();
  myCAN.CANInit();
  Serial.begin(115200);

}




void loop() {
start=millis();
myCAN.ProccessCAN();
if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
  myLCD.SetCurrentDiagnostis(CANDig);
  myLCD.WriteStatus(AOKDOK);
  //myLCD.WriteStatus(SCAN); // mogoce premaknem kaseneje

}else{

  if(myLCD.GetCurrentDiagnostic()==CANDig){
    myLCD.SetCurrentDiagnostis(ANALOG);

  }

  if(!AnalogPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==ANALOG){
    
    myLCD.WriteStatus(ANOTOK); //1
    if(AnalogPins::is44OK()){
      myLCD.WriteStatus(A0OK); //2

    }else {
      myLCD.WriteStatusWithValue(A0NA0V, AnalogPins::GetValueFromPin(AnalogPins::Get44PIN()));//2

    }

    if(AnalogPins::is3_3OK()){
      myLCD.WriteStatus(A1OK);//3

    }else{
      myLCD.WriteStatusWithValue(A1NA1V, AnalogPins::GetValueFromPin(AnalogPins::Get3_3PIN()));//3

    }

    if(AnalogPins::is5OK()){
      myLCD.WriteStatus(A2OK);//4

    }else {
      myLCD.WriteStatusWithValue(A2NA2V, AnalogPins::GetValueFromPin(AnalogPins::Get5PIN()));//4

    }

    if(AnalogPins::is12OK()){
      myLCD.WriteStatus(A3OK);//5
    }else{
      myLCD.WriteStatusWithValue(A3NA3V, AnalogPins::GetValueFromPin(AnalogPins::Get12PIN()));//5
    }

  }else if(AnalogPins::isAllPinsOK()) {
    myLCD.WriteStatus(AOK);
    myLCD.SetCurrentDiagnostis(DIGITAL);
    }
  
   if(!DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL){ //instead of false status of digitalPINS
    myLCD.WriteStatus(DNOK); //1
    if(DigitalPins::is3_3OK()){// Status of Dpin1
      myLCD.WriteStatus(D1OK);//2

    }else {
      myLCD.WriteStatus(D1ND1V); //2

    }

    if(DigitalPins::is4OK()){// Status of Dpin2
      myLCD.WriteStatus(D2OK);//3
    }else {
      myLCD.WriteStatus(D2ND2V);//3
    }

  }else if(DigitalPins::isAllPinsOK()) {
    myLCD.SetCurrentDiagnostis(ANALOG);
    myLCD.WriteStatus(DOK);
    }
  

}

if(myLCD.GetCurrentDiagnostic()==CANDig){
  myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed()); // also add counter to button presses

  if(myCAN.ReturnZERO()){
    myLED.turnONLEDZERO();

  }
  if(myCAN.ReturnNFC()){
    myLED.turnONLEDNFC();

  }

}




myLCD.lcdRefresher();
myLED.LEDrefresher();

end=millis();
if((end-start)<60){
delay(60-(end-start));
}
}


