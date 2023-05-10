#include "main.h"
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern volatile uint32 TimeDelay;
extern uint8 CANDATA;

extern uint32 Distance_1;
extern uint32 Distance_2;

extern sint32 FRONT_Previous_Distance;
extern sint32 FRONT_Current_Distance;
extern sint32 BACK_Previous_Distance;
extern sint32 BACK_Current_Distance;

boolean StopMotor_Flag = FALSE;
uint8 Airbag_Flag;

// char command_Array[10] = {'L', 'R', 'F', 'G', 'I', 'B', 'H', 'J', 'S'};
/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{                      /*SysTick interrupt service routine*/
    if (TimeDelay > 0) /*Prevent it from being negative*/
        TimeDelay--;   /*TimeDelay is a global volatile variable*/

    Can_MainFunction_Write();
}

void SysTick_Initialize(uint32 ticks)
{
    S32_SysTick->CSR = 0;                                                                                        /* Disable SysTick */
    S32_SysTick->RVR = (uint32)(ticks - 1u);                                                                     /* Set reload register */
    S32_SysTick->CVR = 0u;                                                                                       /* Reset counter value */
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_CLKSOURCE(1u); /* Enable SysTick IRQ and Timer */
}

int main()
{
    // char bt_data = 'S', prev_bt_data = 'S';         /* data from bluetooth */
    uint16 CanData = 0x0000;
    // uint8 command;                                  /* command for car lights */
    uint8 flag_SignalLeft = 0;
    uint8 flag_SignalRight = 0;
    uint8 flag_Reverse = 0;
    uint8 flag_Head = 0;

    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Port_Init(&Port_Config);
    Gpt_Init(&Gpt_Config);
    Icu_Init(&Icu_Config);
    Can_Init(&Can_Config);
    Can_SetControllerMode(CanConf_CanController_CanController_0, CAN_CS_STARTED);

    Gpt_Interrupt_Init();
    Icu_Interrupt_Init();

    /* Enable Notification for Icu and Gpt */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_FTM3_CH0);
    Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm0_Ch0);
    Icu_EnableNotification(IcuConf_IcuChannel_IcuFtm1_Ch0);

    /* Enable Edge detection for Icu channels */
    Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm0_Ch0);
    Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuFtm1_Ch0);

    /* Start the Timer for FTM3_Ch0 */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_FTM3_CH0, HUNDRED_MS(2));

    SysTick_Initialize(48000000 / 1000);

    /*Initialization of distances*/
    FRONT_Previous_Distance = Distance_1;
    FRONT_Current_Distance = FRONT_Previous_Distance;
    BACK_Previous_Distance = Distance_2;
    BACK_Current_Distance = BACK_Previous_Distance;

    Can_DriverInit();
    LPUART1_init();

    while (!StopMotor_Flag)
    {
        LED_Control(CanData);

        Can_MainFunction_Read();

        switch (CANDATA)
        {
            case 'F':
            {
                // command = SignalHeadLight_Command;
                CanData = (CanData | value_4);
                flag_Head += 1;
                if (flag_Head > 1)
                {
                    CanData = (CanData & value_8);
                    flag_Head = 0;
                }
                Delay(100);
                break;
            }
            case 'L':               /* Left */
            case 'G':               /* Forward Left */
            {
                // command = SignalLeft_Command;
                CanData = ((CanData | value_1) & (CLEAR_SIGNAL_LEFT_MASK));
                flag_SignalLeft += 1;
                flag_SignalRight = 0;
                flag_Reverse = 0;
                if (flag_SignalLeft > 1)
                {
                    CanData = (CanData & value_5);
                    flag_SignalLeft = 0;
                }
                Delay(100);
                break;
            }
            case 'R':               /* Right */
            case 'I':               /* Forward Right */
            {
                // command = SignalRight_Command;
                CanData = ((CanData | value_2) & (CLEAR_SIGNAL_RIGHT_MASK));
                flag_SignalRight += 1;
                flag_SignalLeft = 0;
                flag_Reverse = 0;
                if (flag_SignalRight > 1)
                {
                    CanData = (CanData & value_6);
                    flag_SignalRight = 0;
                }
                Delay(100);
                break;
            }
            case 'B':               /* Reverse */
            case 'H':               /* Back Left */
            case 'J':               /* Back Right */
            {
                // command = SignalReverse_Command;
                CanData = ((CanData | value_3) & (CLEAR_REVERSE_MASK));
                flag_Reverse += 1;
                flag_SignalLeft = 0;
                flag_SignalRight = 0;
                if (flag_Reverse > 1)
                {
                    CanData = (CanData & value_7);
                    flag_Reverse = 0;
                }
                Delay(100);
                break;
            }
            case 'D':               /* BT disconnected */
            case 'S':               /* Stop/Break */
            {
                // command = Signal_BreakLightOn_Command;
                CanData = (CanData | command_value_2);  // Break
                break;
            }
            default:
            {
                // command = Signal_AllLedOff_Command;
                break;
            }
        }

        FRONT_Crash_Detection(FRONT_Current_Distance, FRONT_Previous_Distance);
        BACK_Crash_Detection(BACK_Current_Distance, BACK_Previous_Distance);

        StopMotor_Flag = StopMotor(Distance_1, Distance_2);
    }
    
    Can_SendData(0x000, "D");
    Delay(100);
    Can_SendData(0x022, "D");
    LED_Control(0);
    RED_ON();
}
