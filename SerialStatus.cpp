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

void SerialStatus::sendToQt()
{
    bool good=true;

    for(int i=0;i<6;i++){
        if(pins[i].isOK==false){
            good=false;

        }
    }
    if(!good){

        Serial.print("<0,");
        for(int i=0;i<6;i++){
        Serial.print(pins[i].pinValue);
        if(i!=5)
        Serial.print(",");
        }
        Serial.println(">");

    }else{
        Serial.print("<1,");
        Serial.print(lastButton);
        Serial.print(",");
        Serial.print(counterButton);
        Serial.print(",");
        Serial.print(nfc);
        Serial.print(",");
        Serial.print(HAL);
        Serial.print(",");
        Serial.print(zero);
        Serial.println(">");


    }


}
