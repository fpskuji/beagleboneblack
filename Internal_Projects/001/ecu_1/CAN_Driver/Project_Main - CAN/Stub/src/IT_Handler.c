#include "main.h"

extern uint32 TimeDelay;

void FTM0_Ch0_Ch1_IRQHandler (void)
{
  Icu_Ftm_ProcessInterrupt(FTM_0_CH_0);  
}

void FTM1_Ch0_Ch1_IRQHandler (void)
{ 
  Icu_Ftm_ProcessInterrupt(FTM_1_CH_0);  
}

void FTM2_Ch0_Ch1_IRQHandler (void)
{ 
  Icu_Ftm_ProcessInterrupt(FTM_2_CH_0);  
}

void FTM3_Ch0_Ch1_IRQHandler (void)
{ 
  Gpt_Ftm_ProcessCommonInterrupt(FTM_3_CH_0);  
}


void SysTick_Handler(void ) 
{
  if(TimeDelay > 0)
    TimeDelay--;
}


