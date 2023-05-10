#ifndef IT_INITS_H
#define IT_INITS_H

void Gpt_Interrupt_Init(void);

void Lpit_Interrupt_Init (void);

void Icu_Interrupt_Init (void);

void Port_Interrupt_Init (void);

void SysTick_Init(void);

void uS10_Delay(uint32);

uint64 mS_GetTick(void);

#endif

