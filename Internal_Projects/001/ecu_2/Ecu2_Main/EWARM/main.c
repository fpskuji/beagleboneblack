#include "main.h"

char data = 'S', prevdata = 0;
uint8 speed = 10, prevspeed = 10;
boolean errorFlag_bool = false;

int main()
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Port_Init(&Port_Config);
    Pwm_Init(&Pwm_Config);
    Gpt_Init(&Gpt_Config);
    Spi_Init(&Spi_PBCfgVariantPredefined);
    Can_Init(&Can_Config);
    Can_SetControllerMode(CanConf_CanController_CanController_0, CAN_CS_STARTED);

    MotorDriver_Init(&MotorDriverA_Config, &MotorDriverA);
    Servo_Init(PwmCh_Servo);
    Systick_Init(SystemCoreClock / 1000);
    NVIC_EnableIRQ();

    Opt_Sensor_Init();

    INIT_DISPLAY();
    delay_ms(1);
    FillScreen();
    delay_ms(1);

    RGB_OFF();

    float32 first_rpm_reading = 0;
    float32 second_rpm_reading = 0;
    float32 first_kph_reading = 0;
    float32 second_kph_reading = 0;
    float32 ave_kph_reading = 0;

    DrawText("Internal Project", FONT4, 90, 20);
    DrawText("FPT.GAM", FONT2, 88, 50);
    delay_ms(1);
    DrawText("SPEED : ", FONT4, 10, 110);

    static char BufferText[10];

    DrawText("---", FONT4, 90, 110);

    while (!errorFlag_bool)
    {
        Can_MainFunction_Read();

        switch (CANDATA)
        {
            case 'F':
            {
                // LEDBLUE_ON();
                setCarSpeed(prevspeed);
                MoveForward();
                ClearText("REVERSE", FONT4, 110, 170);
                DrawText("FORWARD", FONT4, 110, 170);
                break;
            }
            case 'B':
            {
                // LEDGREEN_ON();
                setCarSpeed(prevspeed);
                MoveBackward();

                ClearText("FORWARD", FONT4, 110, 170);
                DrawText("REVERSE", FONT4, 110, 170);

                break;
            }
            case 'S':
            {
                // LEDRED_ON();
                TurnCarNDeg(90);
                StopMovement();
                setCarSpeed(prevspeed);

                ClearText("LEFT", FONT4, 10, 150);
                ClearText("RIGHT", FONT4, 260, 150);

                ClearText("REVERSE", FONT4, 110, 170);
                ClearText("FORWARD", FONT4, 110, 170);
                DrawText("STOP", FONT4, 110, 170);
                break;
            }
            case 'L':
            {
                TurnCarNDeg(120);
                ClearText("RIGHT", FONT4, 260, 150);
                DrawText("LEFT", FONT4, 10, 150);
                break;
            }
            case 'R':
            {
                TurnCarNDeg(60);
                ClearText("LEFT", FONT4, 10, 150);
                DrawText("RIGHT", FONT4, 260, 150);
                break;
            }
            case 'G':
            {
                /* Forward Left */
                TurnCarNDeg(120);
                MoveForward();

                ClearText("RIGHT", FONT4, 260, 150);
                DrawText("LEFT", FONT4, 10, 150);
                ClearText("REVERSE", FONT4, 110, 170);
                DrawText("FORWARD", FONT4, 110, 170);

                break;
            }
            case 'I':
            {
                /* Forward Right */
                TurnCarNDeg(60);
                MoveForward();

                ClearText("LEFT", FONT4, 10, 150);
                DrawText("RIGHT", FONT4, 260, 150);
                ClearText("REVERSE", FONT4, 110, 170);
                DrawText("FORWARD", FONT4, 110, 170);
                break;
            }
            case 'H':
            {
                /* Back Left */
                TurnCarNDeg(120);
                MoveBackward();
                ClearText("RIGHT", FONT4, 260, 150);
                DrawText("LEFT", FONT4, 10, 150);
                ClearText("FORWARD", FONT4, 110, 170);
                DrawText("REVERSE", FONT4, 110, 170);
                break;
            }
            case 'J':
            {
                /* Back Right */
                TurnCarNDeg(60);
                MoveBackward();
                ClearText("LEFT", FONT4, 10, 150);
                DrawText("RIGHT", FONT4, 260, 150);
                ClearText("FORWARD", FONT4, 110, 170);
                DrawText("REVERSE", FONT4, 110, 170);
                break;
            }
            case 'D':
            {
                LEDRED_ON();
                errorFlag_bool = TRUE;
                break;
            }
            default:
            {
                if ((data > 48) && (data <= 57))
                {
                    prevspeed = data - 48;
                    setCarSpeed(data - 48);
                    speed = data - 48;
                }
                else if (data == 48)
                {
                    prevspeed = data - 48;
                    StopMovement();
                    speed = 48;
                }
                else if (data == 'q')
                {
                    prevspeed = 10;
                    setCarSpeed(10);
                    speed = 10;
                }
                break;
            }
        }

        first_rpm_reading = Opt_Sensor_readData(RPM1);          /* reads the first RPM*/
        second_rpm_reading = Opt_Sensor_readData(RPM2);         /* reads the second RPM*/
        first_kph_reading = kphReading(first_rpm_reading);
        second_kph_reading = kphReading(second_rpm_reading);
        ave_kph_reading = AVERAGE(first_kph_reading, second_kph_reading);
        ave_kph_reading = (CANDATA == 'S' || CANDATA == 'D') ? 0.0 : ave_kph_reading;

        ClearText(BufferText, FONT4, 90, 110);
        sprintf(BufferText, "%.2f kph", ave_kph_reading);
        DrawText(BufferText, FONT4, 90, 110);
    }
    StopMovement();
    LEDRED_ON();
    return errorFlag_bool;
}