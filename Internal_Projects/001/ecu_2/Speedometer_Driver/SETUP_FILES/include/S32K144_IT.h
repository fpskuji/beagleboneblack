/*
 *      S32K144_IT.h
 *
 *      Created on: 21/2/2023
 *      Author: Mariano Q. Daga-ang Jr
 */

#ifndef User_Func_H
#define User_Func_H


#include "Main.h"




/** @brief  PORT C IRQ handler
 *  @retval none
 */
void PORTC_IRQHandler(void);

/** @brief GPT Notification
 *  @retval none
 */
void Gpt_Notification_FTM_2_CH_5(void);



/** @brief FTM2 Ch4 Ch5 IRQHandle
 *  @retval none
 */
void FTM2_Ch4_Ch5_IRQHandler(void);

/**
 * @brief   Clear flag for Port C
 * 
 */
#define CLEAR_FLAG_PORT (PORTC->ISFR = PORT_ISFR_ISF_MASK)



#endif
