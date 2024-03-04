#include "LED.h"

void LED::Init()
{
    pinMode(ledNFC,OUTPUT);
    pinMode(ledZERO,OUTPUT);
}

void LED::turnONLEDNFC()
{
    timer1=millis();
    digitalWrite(ledNFC,HIGH);
}

void LED::turnONLEDZERO()
{
    timer2=millis();
    digitalWrite(ledZERO,HIGH);
}

void LED::LEDrefresher()
{
    if(millis()>=timer1+10){
        digitalWrite(ledNFC,LOW);

    }

    if(millis()>=timer2+1500){
        digitalWrite(ledZERO,LOW);

    }
}
