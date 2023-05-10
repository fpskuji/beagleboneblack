/*
 * GPT_ICU.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#include "GPT_ICU.h"

uint32 time_elapsed_1;
uint32 time_elapsed_2;

extern sint32 FRONT_Previous_Time;
extern sint32 FRONT_Current_Time;
extern sint32 BACK_Previous_Time;
extern sint32 BACK_Current_Time;

extern uint8 StopMotor_Flag;
extern uint8 Airbag_Flag;

void Gpt_NotificationFTM3_CH0(void)
{
  HCSR04_SendTrigger(DioConf_DioChannel_TRIG_PIN0);
  HCSR04_SendTrigger(DioConf_DioChannel_TRIG_PIN1);
}

void Gpt_NotificationFTM2_CH0(void)
{
    FRONT_Crash_Detection(FRONT_Current_Time, FRONT_Previous_Time);
    BACK_Crash_Detection(BACK_Current_Time, BACK_Previous_Time);
    
    StopMotor_Flag = StopMotor(time_elapsed_1, time_elapsed_2);
}

void IcuNotification_FTM0_CH0(void)
{
	time_elapsed_1 = HCSR04_ReadEcho1(GptConf_GptChannelConfiguration_LPIT_0_CH_0);
}

void IcuNotification_FTM1_CH0(void)
{
	time_elapsed_2 = HCSR04_ReadEcho2(GptConf_GptChannelConfiguration_LPIT_0_CH_1);
}