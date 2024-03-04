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


  // if(!AnalogPins::isAllPinsOK()){
  //   myLCD.SetCurrentDiagnostis(ANALOG);
  // }else { 
  //   myLCD.SetCurrentDiagnostis(DIGITAL);
  // }

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
      //myLCD.SetCurrentDiagnostis(DIGITAL);
    }else{
      myLCD.WriteStatusWithValue(A3NA3V, AnalogPins::GetValueFromPin(AnalogPins::Get12PIN()));//5
     // myLCD.SetCurrentDiagnostis(DIGITAL);
    }

  }else if(AnalogPins::isAllPinsOK()) {
    myLCD.WriteStatus(AOK);
    myLCD.SetCurrentDiagnostis(DIGITAL);
    }
  
   if(!DigitalPins::isAllPinsOK() && myLCD.GetCurrentDiagnostic()==DIGITAL){
    myLCD.WriteStatus(DNOK);
    if(DigitalPins::is3_3OK()){//1
      myLCD.WriteStatus(D1OK);

    }else {
      myLCD.WriteStatus(D1ND1V); //1

    }

    if(!DigitalPins::is4OK()){
      myLCD.WriteStatus(D2OK);//2
      //myLCD.SetCurrentDiagnostis(ANALOG);
    }else {
      myLCD.WriteStatus(D2ND2V);//2
      //myLCD.SetCurrentDiagnostis(ANALOG);
    }

  }else if(DigitalPins::isAllPinsOK()) {
    myLCD.SetCurrentDiagnostis(ANALOG);
    myLCD.WriteStatus(DOK);
    }
  

}


 myLCD.lcdRefresher();

}


