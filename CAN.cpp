#include "CAN.h"

CAN::CAN() : mcp(10)
{

T1=0;
T2=0;
HAL=0;
ZERO=false;
LastButtonPressed='X';


}

void CAN::CANInit()
{
    mcp.reset();
    mcp.setBitrate(CAN_250KBPS, MCP_8MHZ);
    mcp.setNormalMode();
}

void CAN::ProccessCAN()
{
    if(ReadCAN()){

        if(canMsg.can_id==CANID){
                //printamo confirmation
                //ce dobimo <sendCAN> preko serialReada posljemo

        }

        if(canMsg.can_id == TempID){
            T1=(uint16_t)((canMsg.data[1] << 8) | canMsg.data[0]);
            T2=(uint16_t)((canMsg.data[3] << 8) | canMsg.data[2]);
        }

        if(canMsg.can_id == HALID){
                HAL=((uint16_t)canMsg.data[1] << 8) | (uint16_t)canMsg.data[0];
                if(canMsg.data[2]==0x01){
                    ZERO=true;
                }else ZERO=false;
        }

        if(canMsg.can_id == TipkaID){
            if(canMsg.data[2]==0x01){
                LastButtonPressed='4';

            }else if (canMsg.data[3]==0x01){
                LastButtonPressed= '3';

            }

            if(LastButtonPressed==CurrentButtonCounted){
                countLastButtonPressed++;

            }else {
                CurrentButtonCounted=LastButtonPressed;
                countLastButtonPressed=0+1;

             }


        }

        if(canMsg.can_id == NFCID){
            NFC=true;

        }else NFC=false;
        
      

    }

}

void CAN::SendCAN(can_frame canFrame)
{

mcp.sendMessage(&canFrame);


}

bool CAN::ReadCAN()
{

      if(mcp.readMessage(&canMsg) == MCP2515::ERROR_OK){
            return true;
        }else {
            return false;
        }

}

uint16_t CAN::ReturnTemp1()
{    
    return T1;
}

uint16_t CAN::ReturnTemp2()
{
    return T2;
}

uint16_t CAN::ReturnHAL()
{
    return HAL;
}

bool CAN::ReturnZERO()
{
    return ZERO;
}

char CAN::ReturnLastButtonPressed()
{
    return LastButtonPressed;
}

bool CAN::ReturnNFC()
{
    return NFC;
}

int CAN::ReturnLastButtonsPressed()
{
    return countLastButtonPressed;
}

