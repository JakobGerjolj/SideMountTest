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
  auto allPinsOK = pins.testPins();

  Serial.println(allPinsOK);

  Serial.println("AVERAGE: ");
  Serial.println(calculateAverage(last100AVG, 10));

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
    myCAN.ProccessCAN();
    myLCD.WriteCAN(CANSCREEN, myCAN.ReturnHAL(), myCAN.ReturnTemp1(), myCAN.ReturnTemp2(), myCAN.ReturnLastButtonPressed(), myCAN.ReturnLastButtonsPressed());

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
}
