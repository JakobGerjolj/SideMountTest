#include "AnalogPins.h"
#include "DigitalPins.h"
#include "CAN.h"
#include "lcdPort.h"
#include "LED.h"
#include "Pins.hpp"
#include "PinHelpers.h"
#include "SerialStatus.hpp"

CAN myCAN;
lcdPort myLCD;
LED myLED;
Pins pins;
SerialStatus dataSender;

unsigned long loopCount = 0;
unsigned long start;
unsigned long end;
int arrayCounter = 0;

int last100AVG[10];

void setup()
{
  DigitalPins::init();
  myLCD.lcdInit();
  myLED.Init();
  myCAN.CANInit();
  Serial.begin(115200);
}

int calculateAverage(int array[], int size)
{
  int sum = 0;

  for (int i = 0; i < size; ++i)
  {
    sum += array[i];
  }

  return sum / size;
}

void loop()
{
  start = millis();

  dataSender.receiveSerial();
  myCAN.ProccessCAN();
  dataSender.getCANValue(myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed(), myCAN.ReturnNFC(), myCAN.ReturnHAL(), myCAN.ReturnZERO(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.getResponseGotten());
 
  auto allPinsOK = pins.testPins();


  dataSender.getPinsValue(pins.getAllPins());
  last100AVG[arrayCounter] = allPinsOK;
  arrayCounter++;

  if (arrayCounter % 10 == 0)
  {
    arrayCounter = 0;
  }
  if (allPinsOK != 0 && calculateAverage(last100AVG, 10) >= 1)
  {
    myLCD.SetCurrentDiagnostis(ANALOG);
    Pin faultyPins[allPinsOK];
    pins.getFaultyPins(faultyPins);

    for (int i = 0; i < (sizeof(faultyPins) / sizeof(faultyPins[0])); i++)
    {
     
      myLCD.WriteNOTOK(faultyPins[i].pinName, XNOT_OK_X_VALUE, faultyPins[i].pinValue, i, (sizeof(faultyPins) / sizeof(faultyPins[0])));
    }
  }
  else
  {

    myLCD.WriteStatus(AOKDOK);
    myLCD.SetCurrentDiagnostis(CANDig);
  }

  if (myLCD.GetCurrentDiagnostic() == CANDig)
  {
    
    myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed());
    if(dataSender.getReceived()){
     // Serial.println("GOT LED SIGNAL");
      myCAN.sendLEDSignal();
      dataSender.setSignalFalse();
      dataSender.clearBuffer();
    }


    if (myCAN.ReturnZERO())
    {
      myLED.turnONLEDZERO();
    }
    if (myCAN.ReturnNFC())
    {
      myLED.turnONLEDNFC();
    }
  }

  myLCD.SetLoopCounter(loopCount);
  myLCD.lcdRefresher();
  myLED.LEDrefresher();
  end = millis();
  if ((end - start) < 60)
  {
    delay(60 - (end - start));
  }
  loopCount++;

  if(loopCount==1000000){
    loopCount=0;

  }

   if(loopCount % 10 == 0){
    dataSender.sendToQt();

  }

  dataSender.nfcTimer();

}
