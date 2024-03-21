#include "Arduino.h"
#include "PinHelpers.h"
#include "Pins.hpp"



class SerialStatus {
public:
    SerialStatus();
    void receiveSerial();
    void getPinsValue(Pin* pins);
    void getCANValue(char lButt, int cButt, bool n, uint16_t H, bool z, uint16_t T1, uint16_t T2, bool);
    void sendToQt();
    bool getReceived();
    void setSignalFalse();
    void clearBuffer();
    void nfcTimer();


private:
    bool responseGotten;
    bool prolongedNFC;
    unsigned long timer1;
    int nfcContinous{0};
    int incomingByte;
    char buffer[4];
    int currentBufferIndex=0;
    bool areWeIn=false; 
    char received[3];
    Pin pins[6];
    char lastButton;
    int counterButton;
    bool nfc;
    uint16_t HAL;
    bool zero;
    uint16_t m_T1;
    uint16_t m_T2;
    bool didWeGetSignal;

};