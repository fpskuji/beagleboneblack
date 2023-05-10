/*
 * Airbag_Logic.c
 *
 *  Created on: 25 Apr 2023
 *      Author: Angela.Depamallo
 */


#include "Airbag_Logic.h"

extern uint32 time_elapsed_1;
extern uint32 time_elapsed_2;
extern boolean StopMotor_Flag;
extern boolean Airbag_Flag;

volatile sint32 FRONT_Previous_Time;
volatile sint32 FRONT_Current_Time;
volatile sint32 BACK_Previous_Time;
volatile sint32 BACK_Current_Time;

void FRONT_Crash_Detection( uint32 cur_distance, uint32 prev_distance )
{
  FRONT_Current_Time = time_elapsed_1;

  sint32 Difference = prev_distance - cur_distance;

    if ( Difference > CRASH_THRESHOLD && cur_distance < CRASH_DISTANCE_THRESHOLD)
    {
        /*Front crash detected: TRIGGER AIRBAG*/
      RED_ON();
      StopMotor_Flag = TRUE;
      Airbag_Flag = TRUE;
    }

    FRONT_Previous_Time = cur_distance;
    
}

void BACK_Crash_Detection( uint32 cur_distance, uint32 prev_distance )
{
  BACK_Current_Time = time_elapsed_2;

  sint32 Difference = prev_distance - cur_distance;

    if ( Difference > CRASH_THRESHOLD && cur_distance < CRASH_DISTANCE_THRESHOLD)
    {
        /*Back crash detected: TRIGGER AIRBAG*/
      GREEN_ON();
      StopMotor_Flag = TRUE;
      Airbag_Flag = TRUE;
    }

    BACK_Previous_Time = cur_distance;
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
