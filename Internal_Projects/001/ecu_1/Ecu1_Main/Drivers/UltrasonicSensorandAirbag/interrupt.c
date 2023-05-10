/*
 * interrupt.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */
#include "interrupt.h"


void Gpt_Interrupt_Init(void)
{
  S32_NVIC->ICPR[3] = 1 << (FTM3_Ch0_Ch1_IRQn % 32);           /* IRQ-FTM3_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (FTM3_Ch0_Ch1_IRQn % 32);           /* IRQF-TM3_CH0_CH1: enable IRQ */

}

void Icu_Interrupt_Init (void)
{
  S32_NVIC->ICPR[3] = 1 << (FTM0_Ch0_Ch1_IRQn % 32);           /* IRQ-FTM0_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (FTM0_Ch0_Ch1_IRQn % 32);           /* IRQF-TM0_CH0_CH1: enable IRQ */

  S32_NVIC->ICPR[3] = 1 << (FTM1_Ch0_Ch1_IRQn % 32);           /* IRQ-FTM1_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (FTM1_Ch0_Ch1_IRQn % 32);           /* IRQ-FTM1_CH0_CH1: enable IRQ */
}

void FTM0_Ch0_Ch1_IRQHandler (void)
{
  Icu_Ftm_ProcessInterrupt(FTM_0_CH_0);
}

void FTM1_Ch0_Ch1_IRQHandler (void)
{
  Icu_Ftm_ProcessInterrupt(FTM_1_CH_0);
}

void FTM3_Ch0_Ch1_IRQHandler (void)
{
  Gpt_Ftm_ProcessCommonInterrupt(FTM_3_CH_0);
}
