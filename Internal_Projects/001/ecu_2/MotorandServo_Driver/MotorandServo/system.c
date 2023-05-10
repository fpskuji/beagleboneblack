#include "system.h"

// #define NVIC_Priority_Level_10  10
// #define PORTBtn_IRQ             61
// #define PORTBtn_IRQ_pos         (PORTBtn_IRQ % 32)
// #define NVIC_PORTBtn_IRQ_bfpos  (1 << PORTBtn_IRQ_pos)

// #define SW3_PIN 13

static __IO uint32_t P_ticks;

FUNC(void, SYSTEM_CODE) Systick_Init(FUNC(__IO uint32, SYSTEM_CODE) ticks)
{
    S32_SysTick->CSR = 0;
    S32_SysTick->RVR = ticks - 1u;
    S32_SysTick->CVR = 0;
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) |
                       S32_SysTick_CSR_TICKINT(1u) |
                       S32_SysTick_CSR_CLKSOURCE(1u);
}

FUNC(void, SYSTEM_CODE) PortClock_Enable(FUNC(void, SYSTEM_CODE))
{
    /* Enable clock for Port A */
    PCC->PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;
    /* Enable clock for Port B */
    PCC->PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK;
    /* Enable clock for Port C */
    PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
    /* Enable clock for Port D */
    PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
    /* Enable clock for Port E */
    PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
}

FUNC(void, SYSTEM_CODE) Ptick_Decrement(FUNC(void, SYSTEM_CODE))
{
    if (P_ticks != 0)
    {
        P_ticks--;
    }
}

FUNC(void, SYSTEM_CODE) delay_ms(uint32 delayTime_ms)
{
    P_ticks = delayTime_ms;
    while (P_ticks)
        ;
}

// FUNC(void, SYSTEM_CODE) NVIC_init_IRQs(FUNC(void, SYSTEM_CODE))
// {
//     /* Enable passive filter and interrupt on PORTC for SW_3 */
//     PORTC->PCR[SW3_PIN] |= (PORT_PCR_PFE(1) | PORT_PCR_IRQC(9));

//     /* IRQ61-PORTC: clr any pending IRQ*/
//     S32_NVIC->ICPR[1] = NVIC_PORTBtn_IRQ_bfpos;

//     /* IRQ61-PORTC: enable IRQ */
//     S32_NVIC->ISER[1] = NVIC_PORTBtn_IRQ_bfpos;

//     /* IRQ61-PORTC: priority 10 of 0-15*/
//     S32_NVIC->IP[PORTBtn_IRQ] = NVIC_Priority_Level_10;
// }