#include "FlexCAN.h"

Can_PduType Can_Data;

void Can_DriverInit(void)
{
    Can_Data.id = 0x011;                    // Identifier of the PDU
    // Can_Data.swPduHandle = 0x00;         // Handle of the PDU
    Can_Data.length = 1;                    // Data Length Code of the PDU
    // Can_Data.sdu = (uint8*)"Hellooo!";   // Data of the PDU
}

void Can_SendData(uint32 id, uint8* btdata)
{
    Can_Data.id = id;
    Can_Data.sdu = (uint8*)btdata;
    Can_Write(CanHardwareObject_1, &Can_Data);
    // Can_MainFunction_Write();
}