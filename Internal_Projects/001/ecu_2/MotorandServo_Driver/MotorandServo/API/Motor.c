/**
 * @file Motor.c
 * 
 * @brief Source file for one-motor L298N motor driver.
 * @details This file contains APIs for L298N motor driver to be used with one
 * motor only. As such, it can also be called, L298Nx1.c/h.
 * 
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Motor.h"

void Motor_Init(Motor_ConfigType *Motor, uint16 pinEN, uint16 pinIN1, uint16 pinIN2)
{
    Motor->pinEN = pinEN;
    Motor->pinIN1 = pinIN1;
    Motor->pinIN2 = pinIN2;
    Motor->pwmVal = 0x4000;
    Motor->canMove = TRUE;
    Motor->direction = STOP;
    Motor->isMoving = FALSE;
}

void forward(Motor_ConfigType *Motor)
{
    Dio_WriteChannel(Motor->pinIN1, STD_HIGH);
    Dio_WriteChannel(Motor->pinIN2, STD_LOW);
    Pwm_SetDutyCycle(Motor->pinEN, Motor->pwmVal);
    Motor->direction = FORWARD;
    Motor->isMoving = TRUE;
}

void backward(Motor_ConfigType *Motor)
{
    Dio_WriteChannel(Motor->pinIN1, STD_LOW);
    Dio_WriteChannel(Motor->pinIN2, STD_HIGH);
    Pwm_SetDutyCycle(Motor->pinEN, Motor->pwmVal);
    Motor->direction = BACKWARD;
    Motor->isMoving = TRUE;
}

void stop(Motor_ConfigType *Motor)
{
    Dio_WriteChannel(Motor->pinIN1, STD_HIGH);
    Dio_WriteChannel(Motor->pinIN2, STD_HIGH);
    Motor->direction = STOP;
    Motor->isMoving = FALSE;
}

FUNC(void, MOTORX1_CODE) setSpeed(VAR(Motor_ConfigType, AUTOMATIC) * Motor, VAR(uint16, AUTOMATIC) PwmDutyCyle)
{
    Motor->pwmVal = PwmDutyCyle;
    switch (Motor->direction)
    {
        case FORWARD:
        {
            forward(Motor);
            break;
        }
        case BACKWARD:
        {
            backward(Motor);
            break;
        }
        case STOP:
        {
            stop(Motor);
            break;
        }
    }
}