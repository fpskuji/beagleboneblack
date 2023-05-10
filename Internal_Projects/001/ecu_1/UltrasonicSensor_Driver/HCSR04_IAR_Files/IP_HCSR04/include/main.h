/*
 * main.h
 *
 *  Created on: 11 Apr 2023
 *      Author: Angela.Depamallo
 */

#ifndef MAIN_H_
#define MAIN_H_

/*System Files*/
#include "device_registers.h"
#include "system_S32K144.h"

/*MCAL Files*/
#include "MCAL.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Det.h"
#include "Icu.h"

/*GPT Includes*/
#include "Gpt_Ftm.h"
#include "Gpt_Irq.h"

/*User-created Files*/
#include "RGB_LED.h"
#include "interrupt.h"
#include "GPT_ICU.h"
#include "HCSR04.h"

#define HUNDRED_MS(X) ((uint32)(62500*((float)(X)/10.0)))

extern uint8 TimeoutValue;
extern uint32 HCSR04_0_Distance;
extern uint32 HCSR04_1_Distance;
extern uint32 HCSR04_2_Distance;

void Gpt_NotificationFTM3_CH0(void);
void IcuNotification_FTM0_CH0(void);
void IcuNotification_FTM1_CH0(void);
void IcuNotification_FTM2_CH0(void);
#endif /* MAIN_H_ */
