#include "lcdPort.h"
#include "Arduino.h"

lcdPort::lcdPort() : lcd(0x27,20,4)
{
    CurrentScreen=NOSCREEN;
    LastScreen=NOSCREEN;
    AnalogStateStatus=1;
    DigitalStateStatus=1;
    lastcou=-1;
    CurrentDiagnostic=ANALOG;
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

    if(x==ANOTOK && CurrentScreen==NOSCREEN && LastScreen!=ANOTOK && AnalogStateStatus==1){
        lcd.clear();
        showData("ANALOG NOT OK");
        CurrentScreen=ANOTOK;
        AnalogStateStatus++;
        timer1=millis();
    }

    if(x==DOK && CurrentScreen==NOSCREEN && LastScreen!=DOK){
        lcd.clear();

        showData("DIGITAL OK");
        CurrentScreen=DOK;
        timer1=millis();
    }

    if(x==DNOK && CurrentScreen==NOSCREEN && LastScreen!=DNOK && DigitalStateStatus==1){
        lcd.clear();
        DigitalStateStatus++;
        showData("DIGITAL NOT OK");
        CurrentScreen=DNOK;
        timer1=millis();

    }

    if(x==A0OK && CurrentScreen==NOSCREEN && LastScreen!=A0OK && AnalogStateStatus==2){
        lcd.clear();
        showData("A0 (4.4V) OK");
         AnalogStateStatus++;
        CurrentScreen=A0OK;
        timer1=millis();

    }

    if(x==AOK && CurrentScreen==NOSCREEN && LastScreen!=A0OK){
        lcd.clear();
        showData("ANALOG OK");
        CurrentScreen=AOK;
        timer1=millis();
    }

    if(x==A1OK && CurrentScreen==NOSCREEN && LastScreen!=A0OK && AnalogStateStatus==3){
        lcd.clear();
        showData("A1 (3.3V) OK");
         AnalogStateStatus++;
        CurrentScreen=A1OK;
        timer1=millis();

    }

    if(x==A2OK && CurrentScreen==NOSCREEN && LastScreen!=A2OK && AnalogStateStatus==4){
        lcd.clear();
        showData("A2 (5V) OK");
         AnalogStateStatus++;
        CurrentScreen=A2OK;
        timer1=millis();

    }

    if(x==A3OK && CurrentScreen==NOSCREEN && LastScreen!=A3OK && AnalogStateStatus==5){
        lcd.clear();
        showData("A3 (12V) OK");
AnalogStateStatus++;
        CurrentScreen=A3OK;
        timer1=millis();

    }

    if(x==D1OK && CurrentScreen==NOSCREEN && LastScreen!=D1OK && DigitalStateStatus==2){
        lcd.clear();
        DigitalStateStatus++;
        showData("D1(7) OK");
        CurrentScreen=D1OK;
        timer1=millis();

    }

    if(x==D1ND1V && CurrentScreen==NOSCREEN && LastScreen!=D1ND1V && DigitalStateStatus==2){
        lcd.clear();
        DigitalStateStatus++;
        bothLines("D1(7) NOT OK", "D1 VALUE: LOW");
        CurrentScreen=D1ND1V;
        timer1=millis();

    }


    if(x==D2OK && CurrentScreen==NOSCREEN && LastScreen!=D2OK && DigitalStateStatus==3){
        lcd.clear();
        DigitalStateStatus++;
        showData("D2(6) OK");
        CurrentScreen=D2OK;
        timer1=millis();

    }

    if(x==D2ND2V && CurrentScreen==NOSCREEN && LastScreen!=D2ND2V && DigitalStateStatus==3){
        lcd.clear();
        DigitalStateStatus++;
        bothLines("D2(6) NOT OK", "D2 VALUE: LOW");
        CurrentScreen=D2ND2V;
        timer1=millis();

    }
}

void lcdPort::lcdRefresher()
{

        if(LastScreen==SCAN && CurrentDiagnostic!=CANDig){
            CurrentDiagnostic=ANALOG;
            LastScreen=NOSCREEN;
            
        }



    if(millis() >= (timer1 + 2000) && CurrentScreen != NOSCREEN && CurrentDiagnostic!=CANDig){
        lcd.clear();
        
        if(CurrentDiagnostic==ANALOG && AnalogStateStatus==6){
            AnalogStateStatus=1;
            CurrentDiagnostic=DIGITAL;

        }

        if(CurrentDiagnostic==DIGITAL && DigitalStateStatus==4){
            CurrentDiagnostic=ANALOG;
            DigitalStateStatus=1;

        }

        LastScreen=CurrentScreen;
        CurrentScreen=NOSCREEN;


    }

    if((loopCounter % 40==0) && CurrentScreen == CANSCREEN && CurrentDiagnostic== CANDig){
        lcd.clear();

    }
    if(CurrentScreen==CANSCREEN && CurrentDiagnostic!=CANDig){
        AnalogStateStatus=1;
        DigitalStateStatus=1;
        CurrentDiagnostic=ANALOG;
        //lcd.clear();


    }
  

}

void lcdPort::SetCurrentDiagnostis(StateOfDiagnostic x)
{
    CurrentDiagnostic=x;
}

StateOfDiagnostic lcdPort::GetCurrentDiagnostic()
{
    return CurrentDiagnostic;
}

void lcdPort::WriteCAN(Cscreen Scr, uint16_t HAL, uint16_t T1, uint16_t T2, char tipka, int counter)
{
 if(Scr==CANSCREEN){
    CurrentScreen=CANSCREEN;
    lcd.setCursor(0,0);
    lcd.print("TIPKA: ");
    lcd.setCursor(6,0);
    lcd.print(tipka);
    lcd.setCursor(7,0);
    lcd.print(".");
    lcd.print(counter);
    lcd.setCursor(9,0);
    lcd.print("T1:");
    lcd.print(T1);
    lcd.setCursor(0,1);
    lcd.print("HAL:");
    lcd.setCursor(4,1);
    lcd.print(HAL);
    lcd.setCursor(9,1);
    lcd.print("T2:");
    lcd.print(T2);

 }
}

void lcdPort::WriteNOTOK(String pin, Cscreen scr, float y, int cou, int size)
{
    if(scr==XNOT_OK_X_VALUE && CurrentScreen==NOSCREEN && cou!=lastcou && cou>lastcou){
        lcd.clear();
        
        lastcou=cou;
        if((size - 1)==lastcou) lastcou=-1;
        CurrentScreen=XNOT_OK_X_VALUE;
        timer1=millis();
        lcd.setCursor(0,0);
        lcd.print(pin);
        lcd.print("  NOK");
        lcd.setCursor(0,1);
        lcd.print(pin);
        lcd.setCursor(3,1);
        lcd.print(" VALUE: ");
        lcd.setCursor(11,1);
        lcd.print(y);

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

void lcdPort::SetLoopCounter(unsigned long counter){

loopCounter=counter;

}
