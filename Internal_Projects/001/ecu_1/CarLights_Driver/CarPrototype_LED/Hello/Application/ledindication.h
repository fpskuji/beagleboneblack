#ifndef LEDINDICATIONS_H_
#define LEDINDICATIONS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "S32K144.h"

#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SIGNAL_LEFT_MASK 0x0001u
#define FLAG_SIGNAL_LEFT_MASK 0x0020u
#define CLEAR_SIGNAL_LEFT_MASK 0xFEB5u

#define SIGNAL_RIGHT_MASK 0x0002u
#define FLAG_SIGNAL_RIGHT_MASK 0x0040u
#define CLEAR_SIGNAL_RIGHT_MASK 0xFED6u

#define BREAK_MASK 0x0004u
#define FLAG_BREAK_MASK 0x0080u

#define REVERSE_MASK 0x0008u
#define FLAG_REVERSE_MASK 0x0100u
#define CLEAR_REVERSE_MASK 0xFF9Cu

#define HEADLIGHT_MASK 0x0010u
#define FLAG_HEADLIGHT_MASK 0x0200u


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void Delay(uint32 nTime);
void LED_Signal_Left(void);
void LED_Signal_Right(void);
void LED_Break(void);
void LED_Reverse(void);
void LED_HeadLight(void);
void LED_Control(uint16 Can_Data);


#endif /* LEDINDICATIONS_H_ */