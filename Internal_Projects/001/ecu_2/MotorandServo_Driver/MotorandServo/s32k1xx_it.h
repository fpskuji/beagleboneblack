#ifndef S32K1XX_IT_H
#define S32K1XX_IT_H

#include "main.h"

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

FUNC(void, S32K144_IT) SysTick_Handler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) FTM3_Ch0_Ch1_IRQHandler(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) PWM_FTM_3_CH_0_ISR(VAR(void, S32K144_IT));
FUNC(void, S32K144_IT) PWM_FTM_3_CH_1_ISR(VAR(void, S32K144_IT));

#endif /* S32K1XX_IT_H */