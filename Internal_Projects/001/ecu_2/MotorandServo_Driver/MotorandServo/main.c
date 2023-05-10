#include "main.h"

#define SW2_PRESSED    (Dio_ReadChannel(DioConf_DioChannel_SW2) == STD_HIGH)
#define SW3_PRESSED    (Dio_ReadChannel(DioConf_DioChannel_SW3) == STD_HIGH)
#define SpdUp_PRESSED  (Dio_ReadChannel(DioConf_DioChannel_SpdUp) == STD_HIGH)
#define SpdDwn_PRESSED (Dio_ReadChannel(DioConf_DioChannel_SpdDwn) == STD_HIGH)

int main()
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Port_Init(&Port_Config);
    Pwm_Init(&Pwm_Config);

    Systick_Init(SystemCoreClock / 1000);
    MotorDriver_Init(&MotorDriverA_Config, &MotorDriverA);
    Servo_Init(PwmCh_Servo);
    RGB_OFF();
    /*
    1ms     left    0x666
    1.5ms   middle  0x999
    2ms     right   0xCCC

     */
    // pwm_dc = e^(rpm)
    // rpm = ln(pwm_dc)
    while (1)
    {
        if (SW2_PRESSED)
        {
            MoveForward();
        }
        else if (SW3_PRESSED)
        {
            MoveBackward();
        }
        else
        {
            ;
        }

        if (SpdUp_PRESSED)
        {
            LEDRED_ON();
            /* 180 = -90 */
            TurnCarNDeg(135);
            // Servo_TurnNDeg(135);
            // Servo_TurnNeg90();
        }
        else if (SpdDwn_PRESSED)
        {
            LEDGREEN_ON();
            /* 0 = +90 */
            TurnCarNDeg(45);
            // Servo_TurnNDeg(45);
            // Servo_TurnPos90();
        }
        else if (SW2_PRESSED)
        {
            LEDBLUE_ON();
            /* 90 = 0 */
            TurnCarNDeg(90);
            // Servo_TurnNDeg(90);
            // Servo_TurnZeroDeg();
        }
        else
        {
            TurnCarNDeg(90);
            RGB_OFF();
        }
    }
}
