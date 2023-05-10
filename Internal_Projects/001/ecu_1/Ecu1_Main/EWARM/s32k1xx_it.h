#ifndef S32K1XX_IT_H
#define S32K1XX_IT_H

#include "device_registers.h"
#include "Platform_Types.h"
#include "Icu.h"
#include "Icu_Ftm.h"
#include "Gpt_Ftm.h"
#include "Gpt_Irq.h"

#define S32K144_IT

FUNC(void, S32K144_IT) NMI_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) HardFault_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) MemManage_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) BusFault_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) UsageFault_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) SVC_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) DebugMon_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) PendSV_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) SysTick_Handler(VAR(void, S32K144_IT));



void FTM2_Ch0_Ch1_IRQHandler(void);


#endif /* S32K1XX_IT_H */