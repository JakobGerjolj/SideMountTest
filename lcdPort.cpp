#include "lcdPort.h"
#include "Arduino.h"

lcdPort::lcdPort() : lcd(0x27,20,4)
{
CurrentScreen=NOSCREEN;
}

void lcdPort::lcdInit()
{
    lcd.init();
    lcd.backlight();
    lcd.command(0xA6);
}

void lcdPort::WriteStatus(Cscreen x)
{
    if(x==AOKDOK && CurrentScreen==NOSCREEN){
        lcd.clear();
        
        bothLines("ANALOG OK", "DIGITAL OK");
        CurrentScreen=AOKDOK;
        timer1=millis();
    }
    // else if(millis() >= (timer1+2000) && CurrentScreen==AOKDOK){


    // }

}

void lcdPort::lcdRefresher()
{
    if(millis() >= timer1 + 2000 && CurrentScreen != NOSCREEN){
        lcd.clear();
        int tempEnu=CurrentScreen;
        tempEnu++;
        CurrentScreen=static_cast<Cscreen>(tempEnu);

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
