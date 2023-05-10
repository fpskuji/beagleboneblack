/**
 * @file Motor_Config.c

 * @brief Source file for 2-motor L298N motor driver.
 * @details This file contains the APIs for L298N motor driver to be used 
 * with two motors. As such, it can also be called L298Nx2.c/h. 

 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Motor_Config.h"



// L298N_ConfigType MotorDriverA;

/* ********************************************************************* */
/* ************************* Motor A Functions ************************* */
/* ********************************************************************* */

FUNC(void, MOTORX2_CODE) MotorA_Init(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, uint16 pinEN, uint16 pinIN1, uint16 pinIN2)
{
    Motor_Init(&(l298nDriver->MotorA), pinEN, pinIN1, pinIN2);
    stop(&(l298nDriver->MotorA));
    // setSpeedA(l298nDriver, l298nDriver->MotorB.pwmVal - DRIVERA_MOTORA_PWMVAL_OFFSET);
}

FUNC(void, MOTORX2_CODE) forwardA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    forward(&(l298nDriver->MotorA));
}

FUNC(void, MOTORX2_CODE) backwardA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    backward(&(l298nDriver->MotorA));
}

FUNC(void, MOTORX2_CODE) stopA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    stop(&(l298nDriver->MotorA));
}

FUNC(void, MOTORX1_CODE) setSpeedA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, VAR(uint16, AUTOMATIC) PwmDutyCyle)
{
    setSpeed(&(l298nDriver->MotorA), PwmDutyCyle);
}

FUNC(uint16, MOTORX2_CODE) getSpeedA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    return l298nDriver->MotorA.pwmVal;
}

/* ********************************************************************* */
/* ************************* Motor B Functions ************************* */
/* ********************************************************************* */

FUNC(void, MOTORX2_CODE) MotorB_Init(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, uint16 pinEN, uint16 pinIN1, uint16 pinIN2)
{
    Motor_Init(&(l298nDriver->MotorB), pinEN, pinIN1, pinIN2);
    stop(&(l298nDriver->MotorB));
    // setSpeedA(l298nDriver, l298nDriver->MotorB.pwmVal - DRIVERA_MOTORA_PWMVAL_OFFSET);
    setSpeedB(l298nDriver, l298nDriver->MotorA.pwmVal - DRIVERA_MOTORA_PWMVAL_OFFSET);
}

FUNC(void, MOTORX2_CODE) forwardB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    forward(&(l298nDriver->MotorB));
}

FUNC(void, MOTORX2_CODE) backwardB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    backward(&(l298nDriver->MotorB));
}

FUNC(void, MOTORX2_CODE) stopB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    stop(&(l298nDriver->MotorB));
}

FUNC(void, MOTORX1_CODE) setSpeedB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, VAR(uint16, AUTOMATIC) PwmDutyCyle)
{
    setSpeed(&(l298nDriver->MotorB), PwmDutyCyle);
}

FUNC(uint16, MOTORX2_CODE) getSpeedB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver)
{
    return l298nDriver->MotorB.pwmVal;
}
