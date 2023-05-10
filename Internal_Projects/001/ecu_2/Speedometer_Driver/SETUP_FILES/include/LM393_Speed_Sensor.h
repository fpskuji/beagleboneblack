/*
 *      LM393_Speed_Sensor.h
 *
 *      Created on: 21/2/2023
 *      Author: Mariano Q. Daga-ang Jr
 */

#ifndef User_Func_H
#define User_Func_H


#include "Main.h"


/** @brief Sensor Initialization
 * @retval none
 */
void Opt_Sensor_Init(void);

/** @brief NVIC Initialization
 * @retval none
 */
void NVIC_EnableIRQ(void);

/** @brief Interrupt Initialization and priority setting
 *  @retval none
 */
void NVIC_SetPriority(uint8 vector_number, uint8 priority);


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


float32 Opt_Sensor_readData(float32 sensor);

/**
 * @brief   Clear flag for Port C
 * 
 */
#define CLEAR_FLAG_PORT_C (PORTC->ISFR = PORT_ISFR_ISF_MASK)


/**
 * @brief   Clear flag for Port D
 * 
 */
#define CLEAR_FLAG_PORT_D (PORTD->ISFR = PORT_ISFR_ISF_MASK)


#define Start_1 GptConf_GptChannelConfiguration_GptChannelConfiguration_1
#define interval (1000)

#define Holes_number (float32)20
#define second (float32)60000
#define bit_width 32
#define mm (float32)65
#define pi 3.14159265359
#define factor (60*pi/1000000)
#define conversion ((float32)62.5)
#define PTC15 15
#define PTD6  6
#define Interrupt_On_Rising_Edge  9
void Gpt_Notification_FTM_3_CH_1(void);


float32 kphReading(float32 rpm);

void Opt_Sensor_SetInterval(uint32 interval_in_ms);


typedef enum Read_RPM_Type_t
{
    RPM1 = 1,
    RPM2
} Read_RPM_Type;


#endif
