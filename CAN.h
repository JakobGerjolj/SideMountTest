#include <SPI.h>
#include <mcp2515.h>

class CAN{
public:
    CAN();
    void ProccessCAN();
    uint16_t ReturnTemp1();
    uint16_t ReturnTemp2();
    uint16_t ReturnHAL();
    bool ReturnZERO();
    char ReturnLastButtonPressed();
    bool ReturnNFC();

private:
    bool ReadCAN();
    MCP2515 mcp;
    struct can_frame canMsg;
    uint16_t T1;
    uint16_t T2;
    uint16_t HAL;
    bool ZERO;
    char LastButtonPressed;
    bool NFC;
    static const uint8_t TempID= 0x13;
    static const uint8_t HALID= 0x11;
    static const uint8_t TipkaID= 0x12;
    static const uint8_t NFCID= 0x14;

};