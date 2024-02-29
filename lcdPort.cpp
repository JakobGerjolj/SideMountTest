#include "lcdPort.h"

lcdPort::lcdPort() : lcd(0x27,20,4)
{

}

void lcdPort::lcdInit()
{
    lcd.init();
    lcd.backlight();
    lcd.command(0xA6);
}

void lcdPort::WriteStatus(Cscreen x)
{
    if(x==AOKDOK){
        lcd.clear();
        bothLines("ANALOG OK", "DIGITAL OK");

    }else bothLines("NOO", "NOO");

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
