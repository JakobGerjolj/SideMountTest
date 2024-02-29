#include "DisplayPort.h"
#include "DisplayState.h"
#include <LiquidCrystal_I2C.h>
#include <string.h>

class lcdPort : public DisplayPort{
public:
    lcdPort();
    void lcdInit();
    void WriteStatus(Cscreen x);
    

private:
    LiquidCrystal_I2C lcd;
    Dstate CurrentDState;
    Cscreen CurrentScreen;
    void showData(const char* data) override;
    void bothLines(String  x, String y);

};