#include "lcdPort.h"
#include "Arduino.h"

lcdPort::lcdPort() : lcd(0x27,20,4)
{
CurrentScreen=NOSCREEN;
LastScreen=NOSCREEN;
AnalogStateStatus=1;
DigitalStateStatus=1;
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

    if(x==DNOK && CurrentScreen==NOSCREEN && LastScreen!=DNOK){
        lcd.clear();
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

    if(x==D1OK && CurrentScreen==NOSCREEN && LastScreen!=D1OK){
        lcd.clear();
        showData("D1(7) OK");
        CurrentScreen=D1OK;
        timer1=millis();

    }

    if(x==D1ND1V && CurrentScreen==NOSCREEN && LastScreen!=D1ND1V){
        lcd.clear();
        bothLines("D1(7) NOT OK", "D1 VALUE: LOW");
        CurrentScreen=D1OK;
        timer1=millis();

    }


    if(x==D2OK && CurrentScreen==NOSCREEN && LastScreen!=D2OK){
        lcd.clear();
        showData("D2(6) OK");
        CurrentScreen=D2OK;
        timer1=millis();

    }

    if(x==D2ND2V && CurrentScreen==NOSCREEN && LastScreen!=D2ND2V){
        lcd.clear();
        bothLines("D2(6) NOT OK", "D2 VALUE: LOW");
        CurrentScreen=D1OK;
        timer1=millis();

    }
}

void lcdPort::lcdRefresher()
{
    if(millis() >= (timer1 + 2000) && CurrentScreen != NOSCREEN){
        lcd.clear();
        if(CurrentDiagnostic==ANALOG && AnalogStateStatus==6){
            AnalogStateStatus=1;
            CurrentDiagnostic=DIGITAL;

        }

        if(CurrentDiagnostic==DIGITAL && DigitalStateStatus==2){
            CurrentDiagnostic=DIGITAL;
            DigitalStateStatus=1;

        }

        LastScreen=CurrentScreen;
        CurrentScreen=NOSCREEN;


    }

  

}

void lcdPort::WriteStatusWithValue(Cscreen x, float y)
{

    if(x==A0NA0V && CurrentScreen==NOSCREEN && LastScreen!=A0NA0V && AnalogStateStatus==2){
        lcd.clear();
          CurrentScreen=A0NA0V;
        timer1=millis();
         AnalogStateStatus++;
       // char myString[16]="A0 VALUE: ";
       // char floatStr[20];
       // String st=String(y,2);
        //strcat(myString,st[0]);
       // bothLines("44V(A0) NOT OKAY",myString);
       // showData("44v(A0) NOT OKAY");
        lcd.setCursor(0,1);
        lcd.print("A0 VALUE: ");
        lcd.print(y);

    }

     if(x==A1NA1V && CurrentScreen==NOSCREEN && LastScreen!=A1NA1V && AnalogStateStatus==3){
        lcd.clear();
        CurrentScreen=A1NA1V;
        timer1=millis();
         AnalogStateStatus++;
        char myString[11]="A1 VALUE: ";
        char floatStr[5];//HERE LAST
        sprintf(floatStr, "%.2f", y);
        strcat(myString,floatStr);
        bothLines("33V(A1) NOT OKAY",myString);

    }

    if(x==A2NA2V && CurrentScreen==NOSCREEN && LastScreen!=A2NA2V && AnalogStateStatus==4){
        lcd.clear();
        CurrentScreen=A2NA2V;
        timer1=millis();
         AnalogStateStatus++;
        char myString[16]="A2 VALUE: ";
        char floatStr[3];
        sprintf(floatStr, "%.2f", y);
        strcat(myString,floatStr);
        bothLines("5V(A2) NOT OKAY",myString);

    }

        if(x==A3NA3V && CurrentScreen==NOSCREEN && LastScreen!=A3NA3V && AnalogStateStatus==5){
        lcd.clear();
        CurrentScreen=A3NA3V;
        timer1=millis();
        AnalogStateStatus++;
        char myString[16]="A3 VALUE: ";
        char floatStr[3];
        sprintf(floatStr, "%.2f", y);
        strcat(myString,floatStr);
        bothLines("12V(A3) NOT OKAY",myString);

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
