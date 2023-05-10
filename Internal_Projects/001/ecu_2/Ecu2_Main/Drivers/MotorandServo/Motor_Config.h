#ifndef MOTORX2_H
#define MOTORX2_H

#define MOTORX2_CODE
#define MOTORX2_CONST
#define MOTORX2_APPL_CONST
#define MOTORX2_VAR

#include "Motor.h"

typedef struct
{
    Motor_ConfigType MotorA;
    Motor_ConfigType MotorB;
} L298N_ConfigType;

#define DRIVERA_MOTORA_PWMVAL_OFFSET    (uint16)(2000U)       /* offset value for MotorA since it is observed that MotorA is faster than B.  */

FUNC(void, MOTORX2_CODE)
MotorA_Init(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, uint16 pinEN, uint16 pinIN1, uint16 pinIN2);
FUNC(void, MOTORX2_CODE) forwardA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX2_CODE) backwardA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX2_CODE) stopA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX1_CODE) setSpeedA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, VAR(uint16, AUTOMATIC) PwmDutyCyle);
FUNC(uint16, MOTORX2_CODE) getSpeedA(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);

FUNC(void, MOTORX2_CODE) MotorB_Init(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, uint16 pinEN, uint16 pinIN1, uint16 pinIN2);
FUNC(void, MOTORX2_CODE) forwardB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX2_CODE) backwardB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX2_CODE) stopB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);
FUNC(void, MOTORX1_CODE) setSpeedB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver, VAR(uint16, AUTOMATIC) PwmDutyCyle);
FUNC(uint16, MOTORX2_CODE) getSpeedB(P2VAR(L298N_ConfigType, AUTOMATIC, MOTORX2_VAR) l298nDriver);

#endif /* MOTORX2_H */