/*
 * HCSR04.h
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#ifndef HCSR04_H_
#define HCSR04_H_

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

/*User-created Files*/
#include "RGB_LED.h"

/*User defines*/
#define MAX_TICK          (uint32)4294967295
#define DISTANCE_CONSTANT (float32)0.01715

/*Function Prototypes*/
void HCSR04_SendTrigger(Dio_ChannelType ChannelId);
uint32 HCSR04_ReadEcho1(Dio_ChannelType ChannelId);
uint32 HCSR04_ReadEcho2(Dio_ChannelType ChannelId);

#endif /* HCSR04_H_ */
