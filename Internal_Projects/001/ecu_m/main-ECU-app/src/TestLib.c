#include <stdint.h>
#include <stdio.h>
#include <linux/can.h>

#include "Defs.h"
#include "CanLib.h"
#include "TestLib.h"

void ReceiveMessage (void)
{
	struct can_frame Frame;
	uint16_t FunctionID = ZERO;
	
	if (CanRead(&Frame) != ERROR_OK) {
		printf("Failed Receive..\n");
	}
	
	// Filter CAN ID
	if (Frame.can_id == MAIN_CTRL_ID) {
		// FunctionID = (Frame.data[0] << BYTE_DATA_SHIFT)|(Frame.data[1]);
		FunctionID = Frame.data[0];
		switch (FunctionID) {
			case CRASH_DETECT_NOTIFY:
				printf("Notified a crash occurred\n");
				Shutdown();
				ShutDown = !ShutDown;
				break;
			default:
				printf("%x \t %x %x %x %x %x %x %x %x\n",
						Frame.can_id,
						Frame.data[7],
						Frame.data[6],
						Frame.data[5],
						Frame.data[4],
						Frame.data[3],
						Frame.data[2],
						Frame.data[1],
						Frame.data[0]
						);
				break;
		}
	}
}

void SendMessage (uint16_t CanID, uint8_t *CanData, uint8_t DLC)
{
	struct can_frame Frame;
	uint32_t cnt;
	
	Frame.can_id = CanID;
	Frame.can_dlc = DLC;
	
	for (cnt=ZERO;cnt<CAN_DATA_LENGTH;cnt++) {
		Frame.data[cnt] = CanData[cnt];
	}
	
	if (CanWrite(Frame) != ERROR_OK) {
		printf("Failed Send..\n");
	}
}

// Send CAN data to turn steering to right
void TurnRight (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	uint32_t cnt = ZERO;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'I';
	// CanData[0] = SERVO_BASE_ADDR;
	// CanData[1] = SET_STEERING_ANGLE;
	// CanData[2] = 0x28;	//40 degrees
	
	// while (cnt < TURN_DURATION) {
		SendMessage(ECU1_CAN_ID, CanData, DLC);
		SendMessage(ECU2_CAN_ID, CanData, DLC);
		// cnt++;
	// }
}

// Send CAN data to turn right signal
void TurnBRight (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU1_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'J';
	// CanData[0] = LED_BASE_ADDR;
	// CanData[1] = TOGGLE_R_TURN_SIGNAL_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
	SendMessage(ECU1_CAN_ID, CanData, DLC);
	SendMessage(ECU2_CAN_ID, CanData, DLC);
}

// Send CAN data 
void TurnLeft (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	uint32_t cnt = ZERO;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'G';
	// CanData[0] = SERVO_BASE_ADDR;
	// CanData[1] = SET_STEERING_ANGLE;
	// CanData[2] = 0x82;	//130 degrees
	
	// while (cnt < TURN_DURATION) {
		SendMessage(ECU1_CAN_ID, CanData, DLC);
		SendMessage(ECU2_CAN_ID, CanData, DLC);
		// cnt++;
	// }
}

// Send CAN data to turn left signal
void TurnBLeft (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU1_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'H';
	// CanData[0] = LED_BASE_ADDR;
	// CanData[1] = TOGGLE_L_TURN_SIGNAL_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
	SendMessage(ECU1_CAN_ID, CanData, DLC);
	SendMessage(ECU2_CAN_ID, CanData, DLC);
}
//temp
void SetStop (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'S';
	
	// SendMessage(CanID, CanData, DLC);
	SendMessage(ECU1_CAN_ID, CanData, DLC);
	SendMessage(ECU2_CAN_ID, CanData, DLC);
}

// Send CAN data to set speed motors forward
void SetForward (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'F';
	// CanData[0] = SPEED_MOTOR_BASE_ADDR;
	// CanData[1] = SET_MOTOR_DIRECTION;
	// CanData[2] = 0x01;
	
	// SendMessage(CanID, CanData, DLC);
	SendMessage(ECU1_CAN_ID, CanData, DLC);
	SendMessage(ECU2_CAN_ID, CanData, DLC);
}

// Send CAN data to set motor speed`
// void SetMotorSpeed (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU2_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = 8;
	// // CanData[0] = SPEED_MOTOR_BASE_ADDR;
	// // CanData[1] = SET_SPEED;
	// // CanData[2] = 0x70;
	
	// SendMessage(CanID, CanData, DLC);
// }

// Send CAN data to start the motor
// void StartMotor (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU2_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = SPEED_MOTOR_BASE_ADDR;
	// CanData[1] = ENABLE_MOTOR;
	
	// SendMessage(CanID, CanData, DLC);
// }

// Send CAN data to toggle headlights
// void ToggleHeadlightOn (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU1_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = 'W';
	// // CanData[0] = LED_BASE_ADDR;
	// // CanData[1] = TOGGLE_HEAD_LIGHT_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
// }

// void ToggleHeadlightOff (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU1_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = 'w';
	// // CanData[0] = LED_BASE_ADDR;
	// // CanData[1] = TOGGLE_HEAD_LIGHT_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
// }

// Send CAN data to set speed motors backward
void SetBackward (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'B';
	// CanData[0] = SPEED_MOTOR_BASE_ADDR;
	// CanData[1] = SET_MOTOR_DIRECTION;
	// CanData[2] = 0x02;
	
	// SendMessage(CanID, CanData, DLC);
	SendMessage(ECU1_CAN_ID, CanData, DLC);
	SendMessage(ECU2_CAN_ID, CanData, DLC);
}

// Send CAN data to set reverse lights
// void SignalReverseLightOn (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU1_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = 'U';
	// // CanData[0] = LED_BASE_ADDR;
	// // CanData[1] = TOGGLE_REVERSE_LIGHT_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
// }

// void SignalReverseLightOff (void)
// {
	// uint16_t CanID;
	// uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	// uint8_t DLC;
	
	// CanID = ECU1_CAN_ID;
	// DLC = CAN_DATA_LENGTH;
	// CanData[0] = 'u';
	// // CanData[0] = LED_BASE_ADDR;
	// // CanData[1] = TOGGLE_REVERSE_LIGHT_ADDR;
	
	// SendMessage(CanID, CanData, DLC);
// }

void Shutdown (void)
{
	uint16_t CanID;
	uint8_t CanData[CAN_DATA_LENGTH] = {ZERO};
	uint8_t DLC;
	
	CanID = ECU2_CAN_ID;
	DLC = CAN_DATA_LENGTH;
	CanData[0] = 'D';
	// CanData[0] = LED_BASE_ADDR;
	// CanData[1] = TOGGLE_REVERSE_LIGHT_ADDR;
	
	SendMessage(CanID, CanData, DLC);
}