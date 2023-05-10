#ifndef MOTORX1_H
#define MOTORX1_H

#define MOTORX1_CODE

#include "Dio.h"
#include "Port.h"
#include "Pwm.h"

typedef enum
{
    FORWARD = 0,
    BACKWARD = 1,
    STOP = -1
} MotorDirection;

typedef struct
{
    uint16 pinEN;
    uint16 pinIN1;
    uint16 pinIN2;
    uint16 pwmVal;
    boolean canMove;
    boolean isMoving;
    MotorDirection direction;
} Motor_ConfigType;

FUNC(void, MOTORX1_CODE) Motor_Init(VAR(Motor_ConfigType, AUTOMATIC) *Motor, uint16 pinEN, uint16 pinIN1, uint16 pinIN2);

FUNC(void, MOTORX1_CODE) forward(VAR(Motor_ConfigType, AUTOMATIC) *Motor);

FUNC(void, MOTORX1_CODE) backward(VAR(Motor_ConfigType, AUTOMATIC) *Motor);

FUNC(void, MOTORX1_CODE) stop(VAR(Motor_ConfigType, AUTOMATIC) *Motor);

FUNC(void, MOTORX1_CODE) setSpeed(VAR(Motor_ConfigType, AUTOMATIC) *Motor, VAR(uint16, AUTOMATIC) PwmDutyCyle);

// FUNC(void, MOTORX1_CODE) run
#endif /* MOTORX1_H */