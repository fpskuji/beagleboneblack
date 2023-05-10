#ifndef TEST_LIB_H
#define TEST_LIB_H

#define TURN_DURATION	3000

// Send and receive
void ReceiveMessage (void);
void SendMessage (uint16_t CanID, uint8_t *CanData, uint8_t DLC);

// Test APIs
void TurnRight (void);///
void TurnBRight (void);///
void TurnLeft (void);///
void TurnBLeft (void);///
void SetStop (void);///
void SetForward (void);///
void SetMotorSpeed (void);
void StartMotor (void);
void ToggleHeadlightOn (void);
void ToggleHeadlightOff (void);
void SetBackward (void);//
void SignalReverseLightOn (void);
void SignalReverseLightOff (void);
void Shutdown (void);

// Internal Test APIs
static void CrashDetectionHandler (void);
static void GetDistanceHandler (void);
static void GetSpeedHandler (void);

#endif /* TEST_LIB_H */