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
    if(millis()>=timer1+1000){
        digitalWrite(ledNFC,LOW);

    }

    if(millis()>=timer2+10){
        digitalWrite(ledZERO,LOW);

    }
}
