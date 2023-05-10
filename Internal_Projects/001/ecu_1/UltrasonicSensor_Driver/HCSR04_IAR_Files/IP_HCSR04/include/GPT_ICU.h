/*
 * GPT_ICU.h
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#ifndef GPT_ICU_H_
#define GPT_ICU_H_

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

/*User-created Files*/
#include "RGB_LED.h"
#include "HCSR04.h"

/*GPT Includes*/
#include "Gpt_Ftm.h"
#include "Gpt_Irq.h"

/*Function Prototypes*/
void Gpt_NotificationFTM3_CH0(void);
void IcuNotification_FTM0_CH0 (void);
void IcuNotification_FTM1_CH0 (void);
void IcuNotification_FTM2_CH0 (void);

#endif /* GPT_ICU_H_ */
