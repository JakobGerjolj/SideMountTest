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

void SerialStatus::receiveSerial()
{

char comp[4]="LED";

if(strcmp(buffer,"LED")==0) { //?
        didWeGetSignal=true;
       // Serial.print("INSIDESSSS");
      }
    //  Serial.println(didWeGetSignal);
    //  Serial.println(buffer);


    if(Serial.available()>0){
    incomingByte=Serial.read();


    }

    if((char)incomingByte=='<') {
      areWeIn=true;
      currentBufferIndex=-1;
    }

    if((char)incomingByte=='>') {
      areWeIn=false;
      currentBufferIndex=0;
      
    }

    if(areWeIn){
      if(currentBufferIndex!=-1){
      buffer[currentBufferIndex]=(char)incomingByte;
       currentBufferIndex++;
      }else currentBufferIndex++;

    }



}

void SerialStatus::getPinsValue(Pin *pins1)
{

   for(int i=0;i<6;i++){
        pins[i]=pins1[i];

   }

}

void SerialStatus::getCANValue(char lButt, int cButt, bool n, uint16_t H, bool z, uint16_t T1, uint16_t T2)
{

lastButton=lButt;
counterButton=cButt;

if(prolongedNFC==false){
nfc=n;
}
if(nfc==1 && prolongedNFC==false){
    prolongedNFC=true;
    timer1=millis();
}
if(prolongedNFC) {
    nfc=true;
}
//nfc=n;
HAL=H;
zero=z;
m_T1=T1;
m_T2=T2;
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

    }else{
        Serial.print("<1,");

    }
    for(int i=0;i<6;i++){
        Serial.print(pins[i].pinValue);
        
        Serial.print(",");
        }

    for(int i=0;i<6;i++){
            Serial.print(pins[i].isOK);
            
                Serial.print(",");
    }
    Serial.print(lastButton);
    Serial.print(",");
    Serial.print(counterButton);
    Serial.print(",");
    Serial.print(nfc); //Make nfc longer not just one packet
    Serial.print(","); //So we avoid delay on QT
    Serial.print(HAL);
    Serial.print(",");
    Serial.print(zero);
    Serial.print(",");
    Serial.print(m_T1);
    Serial.print(",");
    Serial.print(m_T2);
    Serial.println(">");
    

    // if(!good){

    //     Serial.print("<0,");
    //     for(int i=0;i<6;i++){
    //     Serial.print(pins[i].pinValue);
        
    //     Serial.print(",");
    //     }
        
        
    //     for(int i=0;i<6;i++){
    //         Serial.print(pins[i].isOK);
    //         if(i!=5){
    //             Serial.print(",");

    //         }

    //     }
    //     Serial.println(">");


    // }else{
    //     Serial.print("<1,");
    //     Serial.print(lastButton);
    //     Serial.print(",");
    //     Serial.print(counterButton);
    //     Serial.print(",");
    //     Serial.print(nfc); //myb make it 1 for longer so it works better in Qt
    //     Serial.print(",");
    //     Serial.print(HAL);
    //     Serial.print(",");
    //     Serial.print(zero);
    //     Serial.print(",");
    //     Serial.print(m_T1);
    //     Serial.print(",");
    //     Serial.print(m_T2);
    //     Serial.println(">");



     }

     bool SerialStatus::getReceived()
     {
        return didWeGetSignal;
     }

     void SerialStatus::setSignalFalse()
     {
        didWeGetSignal=false;
     }

     void SerialStatus::clearBuffer()
     {
        buffer[0]='x';
        buffer[1]='x';
        buffer[2]='x';

     }

     void SerialStatus::nfcTimer()
     {
        if(millis() > timer1 + 2000){
            nfc=0;
            prolongedNFC=false;
        }
     }
