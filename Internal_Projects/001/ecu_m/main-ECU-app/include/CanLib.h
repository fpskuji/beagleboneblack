#ifndef CAN_LIB_H
#define CAN_LIB_H

#define CAN_MIN_DLC		1
#define MAIN_CTRL_ID	0x000U
#define ECU1_CAN_ID		0x011U
#define ECU2_CAN_ID		0x022U

//Message definitions
//Main control
#define MAIN_CONTROL_BASE_ADDR		0x00U
#define CRASH_DETECT_NOTIFY			0x44U

//ECU 1
//Ultrasonic Sensors
#define	ULTRASONIC_BASE_ADDR		0x01U
#define GET_DISTANCE_1				0x00U
#define GET_DISTANCE_2				0x01U
#define GET_DISTANCE_3				0x02U

//LED lights
#define	LED_BASE_ADDR				0x02U
#define	TOGGLE_R_TURN_SIGNAL_ADDR	0x00U
#define	TOGGLE_L_TURN_SIGNAL_ADDR	0x01U
#define	TOGGLE_BRAKE_LIGHT_ADDR		0x02U
#define	TOGGLE_HEAD_LIGHT_ADDR		0x03U
#define	TOGGLE_REVERSE_LIGHT_ADDR	0x04U

//Airbag
#define	AIRBAG_BASE_ADDR			0x03U
#define	AIRBAG_SET_OFF				0x00U

//ECU 2
//Servo
#define SERVO_BASE_ADDR				0x04U
#define SET_STEERING_ANGLE			0x00U
#define	SET_STEERING_STRAIGHT		0x01U

//Speed Motors
#define	SPEED_MOTOR_BASE_ADDR		0x05U
#define	SET_SPEED					0x00U
#define	SET_MOTOR_DIRECTION			0x01U
#define	ENABLE_MOTOR				0x02U
//Speedometer
#define	SPEEDOMETER_BASE_ADDR		0x06U
#define GET_SPEED					0x00U

int32_t Socket;  /* Socket FD variable */

/* API list */
RET CanInit (const int8_t *CanIF);
RET CanRead (struct can_frame *Frame);
RET CanWrite (const struct can_frame Frame);

#endif /* CAN_LIB_H */