#ifndef SERVO_H
#define SERVO_H

#define SERVO_CODE

/* Uncomment the line corresponding to the desired SERVO to be used */
#define SERVO180       /* servo is not continuous in turning */
/* #define SERVO360 */ /* servo is continuous in turning */

#ifdef SERVO180
#define SERVO_OFF_DUTYCYCLE ((uint16)0x0000U)

/* Uncomment the line corresponding to the desired SERVO to be used */
#define SERVO_SG90
/* #define SERVO_MG996R */

#ifdef SERVO_SG90
#define SERVO_NEG90_DUTYCYCLE ((uint16)0x1000U)
#define SERVO_POS90_DUTYCYCLE ((uint16)0x333U)
#define SERVO_0DEG_DUTYCYCLE  ((uint16)0x999U)
#endif /* SERVO_SG90 */

/**
 * @brief Values for Servo MG996R
 * @details These values are just offsets from SERVO_SG90.
 * Values from SERVO_SG90 works fine for MG996R servo, but the MG996R servo was
 * placed improperly in the car chasis.
 * So I'm just defining these offset values so as to avoid magic numbers, and to
 * make it portable for SG90 servo; you will not have to change the pwm dc values
 * in the Servo.c, you just have to comment/uncomment here.
 *
 */
#ifdef SERVO_MG996R
#define SERVO_NEG90_DUTYCYCLE ((uint16)0xF55U)
#define SERVO_POS90_DUTYCYCLE ((uint16)0x333U)
#define SERVO_0DEG_DUTYCYCLE  ((uint16)0x911U)
#endif /* SERVO_MG996R */

#endif /* SERVO180 */

// ((PWM_MAX - PWM_MIN) / (ANGL_MAX - ANGL_MIN)) * (angle - ANGL_MAX) + PWM_MAX
#define MAP(value, fromL, fromH, toL, toH) (((((toH) - (toL)) / ((fromH) - (fromL))) * ((value) - (fromL))) + (toL))

#include "Mcu.h"
// #include "Port.h"
#include "Pwm.h"
#include "system.h"

FUNC(void, SERVO_CODE) Servo_Init(VAR(Pwm_ChannelType, AUTOMATIC) ServoPwm_Channel);
// #ifdef SERVO_180
FUNC(void, SERVO_CODE) Servo_TurnNeg90(VAR(void, AUTOMATIC));
FUNC(void, SERVO_CODE) Servo_TurnPos90(VAR(void, AUTOMATIC));
FUNC(void, SERVO_CODE) Servo_TurnZeroDeg(VAR(void, AUTOMATIC));
FUNC(void, SERVO_CODE) Servo_TurnNDeg(VAR(uint16, AUTOMATIC) angle);
// #endif /* SERVO_180 */

#endif /* SERVO_H */
