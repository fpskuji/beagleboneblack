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


void FTM2_Ch0_Ch1_IRQHandler(void)
{
    Icu_Ftm_ProcessInterrupt(FTM_2_CH_0);
}


