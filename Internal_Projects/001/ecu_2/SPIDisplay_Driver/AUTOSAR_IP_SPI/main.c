#include "main.h"

int main()
{
    int isHazard = FALSE;

    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Port_Init(&Port_Config);
    Spi_Init(&Spi_PBCfgVariantPredefined);

    INIT_DISPLAY();
    FillScreen();

    DrawText("Internal Project", FONT4, 90, 20);
    DrawText("FPT.GAM Technology", FONT2, 88, 50);

    DrawText("SPEED : ", FONT4, 10, 110);

    static char BufferText[3];
    DrawText("---", FONT4, 90, 110);

    while (1)
    {
        if (Dio_ReadChannel((Dio_ChannelType)DioConf_DioChannel_Forward))
        {
            ClearText("STOP", FONT4, 130, 190);
            DrawText("FORWARD", FONT4, 110, 170);

            for (int i = 0; i <= 300; i++)
            {
                sprintf(BufferText, "%d ", i);
                DrawText(BufferText, FONT4, 90, 110);

                if (Dio_ReadChannel((Dio_ChannelType)DioConf_DioChannel_SW3))
                {
                    DrawText("LEFT", FONT4, 10, 150);
                    ClearText("LEFT", FONT4, 10, 150);
                }
                else if (Dio_ReadChannel(
                             (Dio_ChannelType)DioConf_DioChannel_SW2))
                {
                    DrawText("RIGHT", FONT4, 260, 150);
                    ClearText("RIGHT", FONT4, 260, 150);
                }
                else if (Dio_ReadChannel(
                             (Dio_ChannelType)DioConf_DioChannel_Reverse))
                {
                    ClearText("FORWARD", FONT4, 110, 170);
                    DrawText("STOP", FONT4, 130, 190);
                    break;
                }
                else if (Dio_ReadChannel(
                             (Dio_ChannelType)DioConf_DioChannel_Hazard))
                {
                    if (isHazard == FALSE)
                    {
                        DrawText("HAZARD", FONT4, 118, 150);
                        isHazard = TRUE;
                    }
                    else if (isHazard == TRUE)
                    {
                        ClearText("HAZARD", FONT4, 118, 150);
                        isHazard = FALSE;
                    }
                }
            }
        }
        else if (Dio_ReadChannel((Dio_ChannelType)DioConf_DioChannel_Hazard))
        {
            if (isHazard == FALSE)
            {
                ClearText("FORWARD", FONT4, 110, 170);
                DrawText("HAZARD", FONT4, 118, 150);
                isHazard = TRUE;
            }
            else if (isHazard == TRUE)
            {
                ClearText("HAZARD", FONT4, 118, 150);
                isHazard = FALSE;
            }
        }
        else
        {
            ;
        }
    }
}

void SPI_Seq_End(void)
{
    ;
}

void SPI_Notification(void)
{
    ;
}