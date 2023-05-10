#include "device_registers.h"
#include "Platform_Types.h"
#include "IT_Controller.h"

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

void Port_Interrupt_Init (void)
{
  PORTC->PCR[12] |= PORT_PCR_PFE(1) | PORT_PCR_IRQC(9);         /* Enable Passive Filter & Interrupt */
  PORTC->PCR[13] |= PORT_PCR_PFE(1) | PORT_PCR_IRQC(9);         /* Enable Passive Filter & Interrupt */
  S32_NVIC->ICPR[1] = 1<<(61 % 32);                             /* clr any pending IRQ*/
  S32_NVIC->ISER[1] = 1<<(61 % 32);                             /* enable IRQ */
  S32_NVIC->IP[61] = 0xB0;
}

void SysTick_Init(void)
{
  S32_SysTick->RVR = 0x1DF;            /* set SysTick timer reload value*/    
  S32_SysTick->CSR = 0x7;              /* start SysTick timer with Interrupt using core clock */
}

void SysTick_DeInit(void)
{   
  S32_SysTick->CSR = 0x0;              /* start SysTick timer with Interrupt using core clock */
}

void uS10_Delay(uint32 nTime)
{
  TimeDelay = nTime;
  while(TimeDelay != 0);
}

void Clear_Interrupt (void)
{
  PORTC->ISFR = PORT_ISFR_ISF_MASK;
}