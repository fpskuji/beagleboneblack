#include "Airbag_Logic.h"

extern uint32 Distance_1;
extern uint32 Distance_2;
extern uint8 StopMotor_Flag;
extern uint8 Airbag_Flag;

volatile sint32 FRONT_Previous_Distance;
volatile sint32 FRONT_Current_Distance;
volatile sint32 BACK_Previous_Distance;
volatile sint32 BACK_Current_Distance;

void FRONT_Crash_Detection(uint32 cur_distance, uint32 prev_distance)
{
    FRONT_Current_Distance = Distance_1;
    sint32 Difference = prev_distance - cur_distance;

    if (Difference > CRASH_THRESHOLD && cur_distance < CRASH_DISTANCE_THRESHOLD)
    {
        /*Front crash detected: TRIGGER AIRBAG*/
        RED_ON();
        StopMotor_Flag = 1;
        Airbag_Flag = 1;
    }

    FRONT_Previous_Distance = cur_distance;
}

void BACK_Crash_Detection(uint32 cur_distance, uint32 prev_distance)
{
    BACK_Current_Distance = Distance_2;
    sint32 Difference = prev_distance - cur_distance;

    if (Difference > CRASH_THRESHOLD && cur_distance < CRASH_DISTANCE_THRESHOLD)
    {
        /*Back crash detected: TRIGGER AIRBAG*/
        GREEN_ON();
        StopMotor_Flag = 1;
        Airbag_Flag = 1;
    }

    BACK_Previous_Distance = cur_distance;
}

boolean StopMotor(uint32 Distance_1, uint32 Distance_2)
{
    if (Distance_1 < STOPPING_DISTANCE || Distance_2 < STOPPING_DISTANCE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}