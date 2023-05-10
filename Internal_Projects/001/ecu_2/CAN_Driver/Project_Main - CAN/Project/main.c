#include "main.h"

#define NODE_A

#define HUNDRED_MS(X) ((uint32)(62500*((float)(X)/10.0)))
uint32 Distance;
uint32 rx_msg_count = 0; /*< Receive message counter */

extern boolean CanIf_bRxFlag;
extern uint8 CanIf_u8RxIndicationCnt;
extern uint32 RxDATA[2];
int main()
{
  Can_PduType Can_Data = 
  {
    .id = 0x7FF,                // Identifier of the PDU
    .swPduHandle = 0x00,         // Handle of the PDU
    .length = 8,                 // Data Length Code of the PDU
    .sdu = (uint8*) "Hellooo!"   // Data of the PDU
  };

  /* Initializations */
  Mcu_Init(&Mcu_Config);
  (void)Mcu_InitClock(McuClockSettingConfig_0);
  Port_Init(&Port_Config);
  Gpt_Init(&Gpt_Config);
  Icu_Init(&Icu_Config);
  Can_Init(&Can_Config);
  Can_SetControllerMode(CanConf_CanController_CanController_0, CAN_CS_STARTED);

  /* Enable the Interrupts */
  Gpt_Interrupt_Init();
  Icu_Interrupt_Init();
  
  /* Enable Notification for Icu and Gpt */
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM3_CH0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm1_Ch0);
  
  /* Enable Edge detection for Icu channels */
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm1_Ch0);
  
  /* Start the Timer for FTM3_Ch0 */
  Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM3_CH0, HUNDRED_MS(2));
  
  #ifdef NODE_A		   /* Node A transmits first; Node B transmits after reception */					 
  if(Can_Write(CanHardwareObject_1, &Can_Data) == E_OK)
  #endif
    
  while( 1 )
  {
    Can_MainFunction_Read();
  
  }
  
}
/* FTM3_CH0 Notification gets called every every Xmillisecond based on the value of HUNDRED_MS(X) of Gpt_StartTimer*/
void Gpt_NotificationFTM3_CH0(void)
{
  UltraSonic_Send(DioConf_DioChannel_TRIG_PIN1);
}

void IcuNotification_FTM0_CH0(void){}

void IcuNotification_FTM1_CH0(void)
{
  Distance = UltraSonic_Read(GptConf_GptChannelConfiguration_LPIT0_CH2);
}

void IcuNotification_FTM2_CH0(void){}


