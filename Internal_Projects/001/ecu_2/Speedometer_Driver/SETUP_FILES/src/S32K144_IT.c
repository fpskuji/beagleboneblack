#include "S32K144_IT.h"
#include "Gpt_Ftm.h"

uint32_t RPM;
uint32 counter = 0;
uint32_t Interval_counter = 0;

void Gpt_Notification_FTM_2_CH_5(void)
{
    /* Notification Function for FTM 0 Channel 0 */

    RPM = (counter / 20) * 60;
}

void FTM2_Ch4_Ch5_IRQHandler(void)
{
    /* Interrupt process for FTM 0 Channel 0 */
    Gpt_Ftm_ProcessCommonInterrupt(FTM_0_CH_0);
    
     Interval_counter++;
    if (Interval_counter > 10)
    {
        Interval_counter = 0;
    }
    counter = 0;
}

void PORTC_IRQHandler(void)
{
    /* Interrupts if the sensor equals to high and have a rising count*/
    counter++;
    CLEAR_FLAG_PORT;
}