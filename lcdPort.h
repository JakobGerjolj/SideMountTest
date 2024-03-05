#include "DisplayPort.h"
#include "DisplayState.h"
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Arduino.h>  // for sprintf


class lcdPort : public DisplayPort{
public:
    lcdPort();
    void lcdInit();
    void WriteStatus(Cscreen x);
    void lcdRefresher();
    void WriteStatusWithValue(Cscreen x, float y);
    void SetCurrentDiagnostis(StateOfDiagnostic x);
    StateOfDiagnostic GetCurrentDiagnostic();
    void SetLoopCounter(unsigned long counter);
    void WriteCAN(Cscreen Scr, uint16_t HAL, uint16_t T1, uint16_t T2, char tipka, int counter);

    

private:
    int DigitalStateStatus;
    int AnalogStateStatus;
    StateOfDiagnostic CurrentDiagnostic;
    unsigned long timer1;
    LiquidCrystal_I2C lcd;
    Dstate CurrentDState;
    Cscreen CurrentScreen;
    Cscreen LastScreen;
    unsigned long loopCounter;
    void showData(const char* data) override;
    void bothLines(String  x, String y);

};