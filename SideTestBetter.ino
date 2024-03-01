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
  
if(AnalogPins::isAllPinsOK() && DigitalPins::isAllPinsOK()){
  myLCD.SetCurrentDiagnostis(NONE);
  myLCD.WriteStatus(AOKDOK);
  myLCD.WriteStatus(SCAN); // mogoce premaknem kaseneje

}else{
  if(!AnalogPins::isAllPinsOK()){
    myLCD.SetCurrentDiagnostis(ANALOG);

  }else myLCD.SetCurrentDiagnostis(DIGITAL);

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

  }else if(AnalogPins::isAllPinsOK()) {
    myLCD.WriteStatus(AOK);
    myLCD.SetCurrentDiagnostis(DIGITAL);
    }
  
   if(!DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL){
    myLCD.WriteStatus(DNOK);
    if(DigitalPins::is3_3OK()){//7
      myLCD.WriteStatus(D1OK);

    }else myLCD.WriteStatus(D1ND1V);

    if(!DigitalPins::is4OK()){
      myLCD.WriteStatus(D2OK);

    }else myLCD.WriteStatus(D2ND2V);


  }else if(DigitalPins::isAllPinsOK()) {
    myLCD.SetCurrentDiagnostis(ANALOG);
    myLCD.WriteStatus(DOK);}
  

}

 myLCD.lcdRefresher();

}


