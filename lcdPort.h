#include "DisplayPort.h"
#include "DisplayState.h"
#include <LiquidCrystal_I2C.h>
#include <string.h>

class lcdPort : public DisplayPort{
public:
    lcdPort();
    void lcdInit();
    void WriteStatus(Cscreen x);
    void lcdRefresher();
    void WriteStatusWithValue(Cscreen x, float y);
    void SetCurrentDiagnostis(StateOfDiagnostic x);
    StateOfDiagnostic GetCurrentDiagnostic();

    

private:
    int DigitalStateStatus;
    int AnalogStateStatus;
    StateOfDiagnostic CurrentDiagnostic;
    unsigned long timer1;
    LiquidCrystal_I2C lcd;
    Dstate CurrentDState;
    Cscreen CurrentScreen;
    Cscreen LastScreen;
    void showData(const char* data) override;
    void bothLines(String  x, String y);
    

};