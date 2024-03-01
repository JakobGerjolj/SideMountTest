#include "lcdPort.h"
#include "Arduino.h"

lcdPort::lcdPort() : lcd(0x27,20,4)
{
CurrentScreen=NOSCREEN;
LastScreen=NOSCREEN;
}

void lcdPort::lcdInit()
{
    lcd.init();
    lcd.backlight();
    lcd.command(0xA6);
}

void lcdPort::WriteStatus(Cscreen x)
{
    if(x==AOKDOK && CurrentScreen==NOSCREEN && LastScreen!=AOKDOK){
        lcd.clear();    
        bothLines("ANALOG OK", "DIGITAL OK");
        CurrentScreen=AOKDOK;
        timer1=millis();
    }

    if(x==SCAN && CurrentScreen==NOSCREEN && LastScreen!=SCAN){
        lcd.clear();
        bothLines("AOK DOK", "STARTING CAN");
        CurrentScreen=SCAN;
        timer1=millis();

    }
}

void lcdPort::lcdRefresher()
{
    if(millis() >= (timer1 + 2000) && CurrentScreen != NOSCREEN){
        lcd.clear();
        LastScreen=CurrentScreen;
        CurrentScreen=NOSCREEN;


    }

}

void lcdPort::showData(const char *data)
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(data);

}

void lcdPort::bothLines(String x, String y)
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(x);
    lcd.setCursor(0,1);
    lcd.print(y);


}
