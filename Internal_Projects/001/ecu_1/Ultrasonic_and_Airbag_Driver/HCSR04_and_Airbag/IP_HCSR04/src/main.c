#include "main.h"

extern uint32 Distance_1;
extern uint32 Distance_2;

extern sint32 FRONT_Previous_Distance;
extern sint32 FRONT_Current_Distance;
extern sint32 BACK_Previous_Distance;
extern sint32 BACK_Current_Distance;

uint8 StopMotor_Flag;
uint8 Airbag_Flag;

int main()
{
  /* Initializations */
  Mcu_Init(&Mcu_Config);
  Mcu_InitClock(McuClockSettingConfig_0);
  Port_Init(&Port_Config);
  Gpt_Init(&Gpt_Config);
  Icu_Init(&Icu_Config);

  /* Enable the Interrupts */
  Gpt_Interrupt_Init();
  Icu_Interrupt_Init();

  /* Enable Notification for Icu and Gpt */
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM3_CH0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm1_Ch0);

  /* Enable Edge detection for Icu channels */
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm1_Ch0);

  /* Start the Timer for FTM3_Ch0 */
  Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM3_CH0, HUNDRED_MS(2));


  /*Initialization of distances*/
  FRONT_Previous_Distance = Distance_1;
  FRONT_Current_Distance = FRONT_Previous_Distance;
  BACK_Previous_Distance = Distance_2;
  BACK_Current_Distance = BACK_Previous_Distance;
  
  while(1)
  {
    FRONT_Crash_Detection(FRONT_Current_Distance, FRONT_Previous_Distance);
    BACK_Crash_Detection(BACK_Current_Distance, BACK_Previous_Distance);
    StopMotor_Flag = StopMotor (Distance_1, Distance_2);
  }
}

