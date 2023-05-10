#include "main.h"

#define HUNDRED_MS(X) ((uint32)(62500*((float)(X)/10.0)))

extern uint32 Distance_1;
extern uint32 Distance_2;
extern uint32 Distance_3;

int main()
{
  /* Initializations */
  Mcu_Init(&Mcu_Config);
  (void)Mcu_InitClock(McuClockSettingConfig_0);
  Port_Init(&Port_Config);
  Gpt_Init(&Gpt_Config);
  Icu_Init(&Icu_Config);

  /* Enable the Interrupts */
  Gpt_Interrupt_Init();
  Icu_Interrupt_Init();
//  SysTick_Init();

  /* Enable Notification for Icu and Gpt */
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM3_CH0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm1_Ch0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm2_Ch0);

  /* Enable Edge detection for Icu channels */
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm1_Ch0);
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm2_Ch0);

  /* Start the Timer for FTM3_Ch0 */
  Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM3_CH0, HUNDRED_MS(2));


  while( 1 )
  {
    if (Distance_3 <= 50 && Distance_3 !=0)
    {
    	GREEN_ON();
    }

    else
    {
    	RED_ON();
    }

  }
}



