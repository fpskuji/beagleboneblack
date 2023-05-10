#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#define MOTORDRIVER_CODE
#define MOTORDRIVER_CONST
#define MOTORDRIVER_APPL_CONST
#define MOTORDRIVER_VAR

/* driver includes */
#include "Motor_Config.h"
#include "Servo.h"

typedef struct
{
    Pwm_ChannelType PwmCh_ENAPin;
    uint16 DioCh_IN1Pin;
    uint16 DioCh_IN2Pin;
    Pwm_ChannelType PwmCh_ENBPin;
    uint16 DioCh_IN3Pin;
    uint16 DioCh_IN4Pin;
}MotorDriver_ConfigType;


L298N_ConfigType MotorDriverA;
CONST(MotorDriver_ConfigType, MOTORDRIVER_CONST)
MotorDriverA_Config = {PwmCh_EnA, DioConf_DioChannel_IN1, DioConf_DioChannel_IN2,
                      PwmCh_EnB, DioConf_DioChannel_IN3, DioConf_DioChannel_IN4};


FUNC(void, MOTORDRIVER_CODE)
MotorDriver_Init(
    P2CONST(MotorDriver_ConfigType, AUTOMATIC, MOTORDRIVER_APPL_CONST) ConfigPtr,
    P2VAR(L298N_ConfigType, AUTOMATIC, MOTORDRIVER_VAR) MotorDriverPtr);

FUNC(void, MOTORDRIVER_CODE) MoveForward(VAR(void, AUTOMATIC));
FUNC(void, MOTORDRIVER_CODE) MoveBackward(VAR(void, AUTOMATIC));
FUNC(void, MOTORDRIVER_CODE) StopMovement(VAR(void, AUTOMATIC));
FUNC(void, MOTORDRIVER_CODE) TurnCarNDeg(VAR(uint16, AUTOMATIC) angle);
FUNC(void, MOTORDRIVER_CODE) StepUpSpeed(VAR(uint16, AUTOMATIC) pwmVal);
FUNC(void, MOTORDRIVER_CODE) StepDownSpeed(VAR(uint16, AUTOMATIC) pwmVal);

#endif /* MOTORDRIVER_H */