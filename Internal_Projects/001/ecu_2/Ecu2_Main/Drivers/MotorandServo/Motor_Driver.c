/**
 * @file Motor_Driver.c
 * 
 * @brief Motor Driver source file for L298N motor driver.
 * @details This file is an abstraction layer for L298N motor driver, which is the
 * Motor_config.c/.h file. This file contains APIs for the motor driver. As such,
 * it can also be called as the driver for the whole L298N motor driver.
 * 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Motor_Driver.h"

L298N_ConfigType MotorDriverA;
CONST(MotorDriver_ConfigType, MOTORDRIVER_CONST)
MotorDriverA_Config = {PwmCh_EnA, DioConf_DioChannel_IN1, DioConf_DioChannel_IN2,
                      PwmCh_EnB, DioConf_DioChannel_IN3, DioConf_DioChannel_IN4};

FUNC(void, MOTORDRIVER_CODE)
MotorDriver_Init(
    P2CONST(MotorDriver_ConfigType, AUTOMATIC, MOTORDRIVER_APPL_CONST) ConfigPtr,
    P2VAR(L298N_ConfigType, AUTOMATIC, MOTORDRIVER_VAR) MotorDriverPtr
)
{
    MotorA_Init(MotorDriverPtr, ConfigPtr->PwmCh_ENAPin, ConfigPtr->DioCh_IN1Pin, ConfigPtr->DioCh_IN2Pin);
    MotorB_Init(MotorDriverPtr, ConfigPtr->PwmCh_ENBPin, ConfigPtr->DioCh_IN3Pin, ConfigPtr->DioCh_IN4Pin);
    StopMovement();
}

FUNC(void, MOTORDRIVER_CODE) MoveForward(VAR(void, AUTOMATIC))
{
    forwardA(&MotorDriverA);
    forwardB(&MotorDriverA);
}

FUNC(void, MOTORDRIVER_CODE) MoveBackward(VAR(void, AUTOMATIC))
{
    backwardA(&MotorDriverA);
    backwardB(&MotorDriverA);
}

FUNC(void, MOTORDRIVER_CODE) StopMovement(VAR(void, AUTOMATIC))
{
    stopA(&MotorDriverA);
    stopB(&MotorDriverA);
}

FUNC(void, MOTORDRIVER_CODE) setCarSpeed(VAR(uint8, AUTOMATIC) speed)
{
    uint16 pwmVal = 0;
    pwmVal = (speed <= 0) ? 0 : MAP(speed, 1, 10, 0x4000, 0x8000);
    setSpeedA(&MotorDriverA, pwmVal);
    setSpeedB(&MotorDriverA, pwmVal);
}

FUNC(void, MOTORDRIVER_CODE) TurnCarNDeg(VAR(uint8, AUTOMATIC) angle)
{
    uint16 motorASpeed = getSpeedA(&MotorDriverA);
    uint16 motorBSpeed = getSpeedB(&MotorDriverA);

    Servo_TurnNDeg(angle);

    if (angle < 90)
    {
        motorBSpeed = MAP(angle,0, 90, 0, motorASpeed);
    }
    else if (angle > 90)
    {
        motorASpeed = MAP(angle, 90, 180, motorBSpeed, 0);
    }
    else if (angle == 90)
    {
        motorBSpeed = (motorBSpeed >= motorASpeed) ? motorBSpeed : motorASpeed;
        motorASpeed = motorBSpeed - DRIVERA_MOTORA_PWMVAL_OFFSET;
    }

    setSpeedA(&MotorDriverA, motorASpeed);
    setSpeedB(&MotorDriverA, motorBSpeed);
}

