#include "DisplayPort.h"
#include "DisplayState.h"
#include <LiquidCrystal_I2C.h>

class lcdPort : public DisplayPort{
public:
    lcdPort();
    void lcdInit();
    void showData(const char* data) override;

private:
    LiquidCrystal_I2C lcd;
    Dstate CurrentDState;
    Cscreen CurrentScreen;

};