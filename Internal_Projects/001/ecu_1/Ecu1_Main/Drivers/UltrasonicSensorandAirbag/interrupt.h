/*
 * interrupt.h
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "device_registers.h"
#include "Platform_Types.h"
#include "interrupt.h"
#include "S32K144.h"

/*MCAL Files*/
#include "Gpt.h"
#include "Icu.h"
#include "Gpt_Ftm.h"
#include "Gpt_Irq.h"
#include "Icu_Ftm.h"
#include "Icu_Irq.h"

void Gpt_Interrupt_Init(void);
void Icu_Interrupt_Init (void);
void FTM0_Ch0_Ch1_IRQHandler (void);
void FTM1_Ch0_Ch1_IRQHandler (void);
void FTM3_Ch0_Ch1_IRQHandler (void);


#endif /* INTERRUPT_H_ */
