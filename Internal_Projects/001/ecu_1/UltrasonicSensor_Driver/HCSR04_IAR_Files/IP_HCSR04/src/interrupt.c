/*
 * interrupt.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */
#include "interrupt.h"

volatile uint32 TimeDelay;

void Gpt_Interrupt_Init(void)
{
  S32_NVIC->ICPR[3] = 1 << (117 % 32);           /* IRQ-FTM3_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (117 % 32);           /* IRQF-TM3_CH0_CH1: enable IRQ */

}

void Icu_Interrupt_Init (void)
{
  S32_NVIC->ICPR[3] = 1 << (99 % 32);           /* IRQ-FTM0_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (99 % 32);           /* IRQF-TM0_CH0_CH1: enable IRQ */

  S32_NVIC->ICPR[3] = 1 << (105 % 32);           /* IRQ-FTM1_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (105 % 32);           /* IRQ-FTM1_CH0_CH1: enable IRQ */

  S32_NVIC->ICPR[3] = 1 << (111 % 32);           /* IRQ-FTM2_CH0_CH1: clr any pending IRQ*/
  S32_NVIC->ISER[3] = 1 << (111 % 32);           /* IRQ-FTM2_CH0_CH1: enable IRQ */
}

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
