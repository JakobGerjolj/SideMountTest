#include "LED.h"

void LED::Init()
{
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> temp_branch
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
<<<<<<< HEAD
=======
=======
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
}
>>>>>>> 2fd1299 (Point before testing LEDs)
>>>>>>> temp_branch
