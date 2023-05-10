
#include "Main.h"

float32 first_rpm_reading;
float32 second_rpm_reading;
float32 kph_reading;

int main(void)
{
    Mcu_Init(&Mcu_Config);                  /*Initializes MCU Driver */
    Mcu_InitClock(McuClockSettingConfig_0); /* Initialize MCU Clock */
    Port_Init(&Port_Config);                /*Initializes PORT Driver */
    Gpt_Init(&Gpt_Config);                  /*Initializes GPT Driver */
    NVIC_EnableIRQ();                       /*Initializes interrupts */
    Opt_Sensor_Init();         /*Initializes time for sensor reading */


    
    
    while (1)
    {
            first_rpm_reading = Opt_Sensor_readData(RPM1);    /* reads the first RPM*/
            second_rpm_reading = Opt_Sensor_readData(RPM2);    /* reads the second RPM*/
            kph_reading = kphReading(second_rpm_reading);  /*returns the kph*/
    }
}