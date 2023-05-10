#include "main.h"

extern uint32 time_elapsed_1;
extern uint32 time_elapsed_2;

extern sint32 FRONT_Previous_Time;
extern sint32 FRONT_Current_Time;
extern sint32 BACK_Previous_Time;
extern sint32 BACK_Current_Time;

boolean StopMotor_Flag = FALSE;
boolean Airbag_Flag = FALSE;

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
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM_3_CH_0);
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM_2_CH_0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm1_Ch0);

  /* Enable Edge detection for Icu channels */
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm0_Ch0);
  Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm1_Ch0);

  /* Start the Timer for FTM3_Ch0 */
  Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM_3_CH_0, ONE_MS);
  Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM_2_CH_0, ONE_MS);

    /*Initialization of distances*/
  FRONT_Previous_Time = time_elapsed_1;
  FRONT_Current_Time = FRONT_Previous_Time;
  BACK_Previous_Time = time_elapsed_2;
  BACK_Current_Time = BACK_Previous_Time;


  while(1)
  {
//    for (int i =0; i< 100000; i++)
//    {
//      ;
//    }
//    Dio_WriteChannel(DioConf_DioChannel_BLUE_LED, STD_LOW);
//    for (int i =0; i< 100000; i++)
//    {
//      ;
//    }
//    Dio_WriteChannel(DioConf_DioChannel_BLUE_LED, STD_HIGH);
  }
}

