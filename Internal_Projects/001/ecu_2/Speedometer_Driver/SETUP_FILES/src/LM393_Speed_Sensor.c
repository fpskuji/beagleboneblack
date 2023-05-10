#include "LM393_Speed_Sensor.h"
#include "Gpt_Ftm.h"

float32 RPM_1;
uint32 read=0;
float32 RPM_2;
uint32 counter_1 = 0;
uint32 counter_2 = 0;
float32 time_interval;
float32 KPH;


void NVIC_EnableIRQ(void)
{
    NVIC_SetPriority(FTM2_Ch4_Ch5_IRQn, 0u); /** Initialize FTM Interrupt*/
    NVIC_SetPriority(PORTC_IRQn, 1u);
    NVIC_SetPriority(PORTD_IRQn, 2u);
    
    /* Initialize Interrupt for Port C Pin 15 ,ISF flag and Interrupt on
     * rising-edge*/
    PORTC->PCR[PTC15] |= PORT_PCR_IRQC(Interrupt_On_Rising_Edge);
    PORTD->PCR[PTD6] |= PORT_PCR_IRQC(Interrupt_On_Rising_Edge);

}

void Opt_Sensor_Init(void)
{
    Gpt_SetMode(GPT_MODE_NORMAL);
    Gpt_EnableNotification(Start_1);
    Opt_Sensor_SetInterval(interval);
   
}
/**
 * @brief Interval setting
 * 
 * @param interval_in_ms 
 */
void Opt_Sensor_SetInterval(uint32 interval_in_ms)
{
    time_interval = interval_in_ms;
    Gpt_StopTimer(Start_1);
    Gpt_StartTimer(Start_1,(uint32)((float32)interval_in_ms * conversion));
}

void PORTC_IRQHandler(void)
{
    /* Interrupts if the sensor equals to high and have a rising count*/
    counter_1++;
    CLEAR_FLAG_PORT_C;
}

void PORTD_IRQHandler(void)
{
    /* Interrupts if the sensor equals to high and have a rising count*/
    counter_2++;
    CLEAR_FLAG_PORT_D;
}

void FTM2_Ch4_Ch5_IRQHandler(void)
{
    Gpt_Ftm_ProcessCommonInterrupt(FTM_2_CH_5);
}

void Gpt_Notification_FTM_2_CH_5(void)
{
    /* Notification Function for FTM 20 Channel 5 */

    float32 rev_1= (float32)counter_1/2 / (float32)Holes_number;
    float32 rev_2= (float32)counter_2/2 / (float32)Holes_number;
    RPM_1 = (float32)(((float32)rev_1/(float32)time_interval)*second);
    RPM_2 = (float32)(((float32)rev_2/(float32)time_interval)*second);
    
    counter_1 = 0;
    counter_2 = 0; 

}

void NVIC_SetPriority(uint8 vector_number, uint8 priority)
{
    /* clr any pending IRQ */
    S32_NVIC->ICPR[vector_number / bit_width] = (1 << (vector_number % bit_width));
    /* enable IRQ */
    S32_NVIC->ISER[vector_number / bit_width] = (1 << (vector_number % bit_width));
    /* priority 0-15 */
    S32_NVIC->IP[vector_number] = (priority << 4);
}


float32 Opt_Sensor_readData(float32 sensor)
{
    switch ((uint32)sensor)
    {
        case RPM1:
            return (float32)RPM_1;
            break;
        case RPM2:
            return (float32)RPM_2;
            break;
        default:
            return 0;
            break;  
    }      
}

float32 kphReading(float32 rpm)
{
    KPH = (float32)((float32)factor*(rpm * mm));
    return KPH;
}