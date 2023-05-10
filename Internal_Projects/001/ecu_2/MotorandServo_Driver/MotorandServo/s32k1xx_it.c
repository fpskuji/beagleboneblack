#include "s32k1xx_it.h"

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) NMI_Handler(FUNC(void, S32K144_IT)) {}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) HardFault_Handler(FUNC(void, S32K144_IT))
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) MemManage_Handler(FUNC(void, S32K144_IT))
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) BusFault_Handler(FUNC(void, S32K144_IT))
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) UsageFault_Handler(FUNC(void, S32K144_IT))
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) SVC_Handler(FUNC(void, S32K144_IT)) {}

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) DebugMon_Handler(FUNC(void, S32K144_IT)) {}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */
FUNC(void, S32K144_IT) PendSV_Handler(FUNC(void, S32K144_IT)) {}

/**
 * @brief This function handles SysTick Handler
 * @param None
 * @retval None
 *
 */
FUNC(void, S32K144_IT) SysTick_Handler(FUNC(void, S32K144_IT))
{
    Ptick_Decrement();
}

FUNC(void, S32K144_IT) FTM0_Ch2_Ch3_IRQHandler(VAR(void, S32K144_IT))
{
    // Gpt_Ftm_ProcessCommonInterrupt(ftm_3_c);
}

FUNC(void, S32K144_IT) PWM_FTM_3_CH_0_ISR(VAR(void, S32K144_IT))
{
    // Gpt_Ftm_ProcessCommonInterrupt(ftm_3_c);
}

FUNC(void, S32K144_IT) PWM_FTM_3_CH_1_ISR(VAR(void, S32K144_IT))
{
    // Gpt_Ftm_ProcessCommonInterrupt(ftm_3_c);
}