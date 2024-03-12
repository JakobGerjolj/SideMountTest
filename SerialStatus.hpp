#include "Arduino.h"
#include "PinHelpers.h"
#include "Pins.hpp"



class SerialStatus {
public:
    SerialStatus();
    void getPinsValue(Pin* pins);
    void getCANValue(char lButt, int cButt, bool n, uint16_t H, bool z, uint16_t T1, uint16_t T2);
    void sendToQt();

private:
    Pin pins[6];
    char lastButton;
    int counterButton;
    bool nfc;
    uint16_t HAL;
    bool zero;
    uint16_t m_T1;
    uint16_t m_T2;

};