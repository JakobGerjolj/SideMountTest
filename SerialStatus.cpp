#include "SerialStatus.hpp"

SerialStatus::SerialStatus()
{

    for(int i=0;i<6;i++){
        pins[i].isOK=false;
        pins[i].pinName="NOPIN";
        pins[i].pinValue=0.0;
    }
    lastButton='X';
    counterButton=0;
    nfc=false;
    HAL=0;
    zero=false;

}

void SerialStatus::getPinsValue(Pin *pins1)
{

   for(int i=0;i<6;i++){
        pins[i]=pins1[i];

   }

}

void SerialStatus::getCANValue(char lButt, int cButt, bool n, uint16_t H, bool z)
{

lastButton=lButt;
counterButton=cButt;
nfc=n;
HAL=H;
zero=z;

}
