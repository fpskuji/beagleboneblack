#include "Servo.h"

#define PWM_MAX  ((uint16)SERVO_NEG90_DUTYCYCLE)
#define PWM_MIN  ((uint16)SERVO_POS90_DUTYCYCLE)
#define ANGL_MAX ((uint16)180U)
#define ANGL_MIN ((uint16)0U)
// Servo_ConfigType Servo;

FUNC(void, SERVO_CODE) Servo_Init(VAR(Pwm_ChannelType, AUTOMATIC) ServoPwm_Channel)
{
    // Servo.PwmChannel_Servo = ServoPwm_Channel;
    // Servo.canMove = TRUE;
    // Servo.isTurning = FALSE;
    // Servo.direction = CENTER;
    // #if defined (SERVO_180)
    // Servo.pwmVal = 0x0000;
    Pwm_SetDutyCycle(PwmCh_Servo, SERVO_OFF_DUTYCYCLE);
    // #else
    // #define SERVO_360
    //     Servo.pwmVal = 0x999;
    //     Servo_Stop();
    // #endif
}
// #ifdef SERVO_180

FUNC(void, SERVO_CODE) Servo_TurnNeg90(VAR(void, AUTOMATIC))
{
    /* -90deg */
    Pwm_SetDutyCycle(PwmCh_Servo, SERVO_NEG90_DUTYCYCLE);
}

FUNC(void, SERVO_CODE) Servo_TurnPos90(VAR(void, AUTOMATIC))
{
    /* +90deg */
    Pwm_SetDutyCycle(PwmCh_Servo, SERVO_POS90_DUTYCYCLE);
}

FUNC(void, SERVO_CODE) Servo_TurnZeroDeg(VAR(void, AUTOMATIC))
{
    /* 0deg */
    Pwm_SetDutyCycle(PwmCh_Servo, SERVO_0DEG_DUTYCYCLE);
}

FUNC(void, SERVO_CODE) Servo_TurnNDeg(VAR(uint16, AUTOMATIC) angle)
{
    uint16 pwmVal = 0;
    // pwmVal = (((PWM_MAX - PWM_MIN) / (ANGL_MAX - ANGL_MIN)) * (angle - ANGL_MAX) + PWM_MAX);
    pwmVal = MAP(angle, ANGL_MAX, ANGL_MIN, PWM_MAX, PWM_MIN);
    Pwm_SetDutyCycle(PwmCh_Servo, pwmVal);
}
// #endif /* SERVO_180 */