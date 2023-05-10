/*
 * Airbag_Logic.h
 *
 *  Created on: 25 Apr 2023
 *      Author: Angela.Depamallo
 */

#ifndef AIRBAG_LOGIC_H_
#define AIRBAG_LOGIC_H_

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

/*Threshold placeholder. Indicates that a change of 10cm/measurement is considered as a crash*/
/*10cm || 10cm || 10 cm*/
#define CRASH_THRESHOLD 583
#define CRASH_DISTANCE_THRESHOLD 583
#define STOPPING_DISTANCE 583

void FRONT_Crash_Detection( uint32 cur_distance, uint32 prev_distance );
void BACK_Crash_Detection( uint32 cur_distance, uint32 prev_distance );
boolean StopMotor (uint32 Distance_1, uint32 Distance_2);

#endif /* AIRBAG_LOGIC_H_ */
