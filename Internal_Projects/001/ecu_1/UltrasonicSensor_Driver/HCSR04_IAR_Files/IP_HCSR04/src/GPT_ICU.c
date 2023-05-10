/*
 * GPT_ICU.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#include "GPT_ICU.h"

uint32 Distance_1;
uint32 Distance_2;
uint32 Distance_3;

void Gpt_NotificationFTM3_CH0(void)
{
  HCSR04_SendTrigger(DioConf_DioChannel_TRIG_PIN0);
  HCSR04_SendTrigger(DioConf_DioChannel_TRIG_PIN1);
  HCSR04_SendTrigger(DioConf_DioChannel_TRIG_PIN2);
}

void IcuNotification_FTM0_CH0(void)
{
	Distance_1 = HCSR04_ReadEcho(GptConf_GptChannelConfiguration_LPIT0_CH0);
}

void IcuNotification_FTM1_CH0(void)
{
	Distance_2 = HCSR04_ReadEcho(GptConf_GptChannelConfiguration_LPIT0_CH1);
}

void IcuNotification_FTM2_CH0(void)
{
	Distance_3 = HCSR04_ReadEcho(GptConf_GptChannelConfiguration_LPIT0_CH2);
}
