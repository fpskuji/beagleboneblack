#ifndef MAIN_H
#define MAIN_H

/*System Files*/
#include "device_registers.h"
#include "system_S32K144.h"

/*MCAL Files*/
#include "MCAL.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Det.h"
#include "Icu.h"
#include "Can.h"

/*GPT Includes*/
#include "Gpt_Ftm.h"
#include "Gpt_Irq.h"

/*User-created Files*/
#include "RGB_LED.h"
#include "ledindication.h"
#include "GPT_ICU.h"
#include "HCSR04.h"
#include "Airbag_Logic.h"
#include "LPUART.h"
#include "Flexcan.h"

/* local macro definitions */
#define HUNDRED_MS(X) ((uint32)(62500 * ((float32)(X) / 10.0)))

#define COMMAND_40 (Dio_ReadChannel(DioConf_DioChannel_Sw_SignalL) == STD_HIGH)
#define COMMAND_20 (Dio_ReadChannel(DioConf_DioChannel_Sw_SignalR) == STD_HIGH)

/* local declarations */
void Gpt_Interrupt_Init(void);
void Icu_Interrupt_Init(void);

#define command_value_2 (0x84)
#define command_value_4 (0xFF7B)
#define value_1 (0x21)
#define value_2 (0x42)
#define value_3 (0x108)
#define value_4 (0x210)

#define value_5 (0xFFDF)
#define value_6 (0xFFBF)
#define value_7 (0xFEFF)
#define value_8 (0xFDEF)

void Gpt_NotificationFTM3_CH0(void);
void IcuNotification_FTM0_CH0(void);
void IcuNotification_FTM1_CH0(void);

#define Right_Signal      0x4652696768742121    /* FRight!! goods */
#define left_Signal       0x464C656674212121    /* FLeft!!! goods*/

#define Reverse_Signal    0x2152657665727365    /* !Reverse goods*/
#define Headlight_Signal  0x46486C6967687421    /* FHlight! */
#define turnoff_signal    0x215475726E6F6666    /* !Turnoff */
#define break_signal      0x46427265616B2121    /* FBreak!! goods*/

typedef enum
{
    SignalLeft_Command = 1, /*  */
    SignalRight_Command,
    SignalReverse_Command,
    SignalHeadLight_Command,
    Signal_AllLedOff_Command,
    Signal_BreakLightOn_Command,
} Command_Number_Types;

// extern Can_PduType Can_Data;

#endif /* MAIN_H */