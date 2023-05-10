#ifndef MAIN_H
#define MAIN_H

/* system includes */
#include "system.h"
#include "system_S32K144.h"

/* MCAL includes */
/* MCU first */
#include "Mcu.h"
/* other MCAL modules */
#include "Dio.h"
#include "Gpt.h"
#include "Port.h"
#include "Pwm.h"
#include "Spi.h"

/* driver includes */
#include "LM393_Speed_Sensor.h"
#include "Motor_Driver.h"
#include "RGB.h"
#include "Servo.h"
#include "ILI9341.h"
#include "printf.h"
#include "LPUART.h"
#include "Can.h"

/* macro definitions */
#define CAR_STOP 0x53746F7070702121
#define AVERAGE(X, Y) (((X) + (Y)) / (float32)(2.0))
#define SPIDISP_DRV_ON    1
#define CAN_DRV_ON        1
#define MOTORSERVO_DRV_ON 1
#define SW2_PRESSED    (Dio_ReadChannel(DioConf_DioChannel_SW2) == STD_HIGH)
#define SW3_PRESSED    (Dio_ReadChannel(DioConf_DioChannel_SW3) == STD_HIGH)
#define SpdUp_PRESSED  (Dio_ReadChannel(DioConf_DioChannel_SpdUp) == STD_HIGH)
#define SpdDwn_PRESSED (Dio_ReadChannel(DioConf_DioChannel_SpdDwn) == STD_HIGH)

/* local declarations */
extern CONST(MotorDriver_ConfigType, MOTORDRIVER_CONST) MotorDriverA_Config;
extern L298N_ConfigType MotorDriverA;
extern uint8 CANDATA;


#endif /* MAIN_H */
