#include "LED.h"

void LED::Init()
{
<<<<<<< HEAD
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
    if(millis()>=timer1+2000){
        digitalWrite(ledNFC,LOW);

    }

    if(millis()>=timer2+2000){
        digitalWrite(ledZERO,LOW);

    }
}
=======
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
}
>>>>>>> 2fd1299 (Point before testing LEDs)
