/*
 * HCSR04.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Angela.Depamallo
 */

#include "HCSR04.h"

/*Variables*/
boolean first_capture=TRUE;
boolean first_capture2=TRUE;

void HCSR04_SendTrigger(Dio_ChannelType ChannelId)
{
	Dio_WriteChannel(ChannelId, STD_HIGH);
	Dio_WriteChannel(ChannelId, STD_LOW);
}

uint32 HCSR04_ReadEcho1(Dio_ChannelType ChannelId)
{
	static uint32 time_elapsed;
	static uint32 distance_measured;

	if (first_capture)
	{
		Gpt_StartTimer(ChannelId, MAX_TICK);
		first_capture = FALSE;
	}
	else
	{
		Gpt_StopTimer(ChannelId);
		time_elapsed = Gpt_GetTimeElapsed(ChannelId);
		distance_measured = (time_elapsed * DISTANCE_CONSTANT);
		first_capture = TRUE;
	}
	return distance_measured;
}

uint32 HCSR04_ReadEcho2(Dio_ChannelType ChannelId)
{
	static uint32 time_elapsed;
	static uint32 distance_measured;

	if (first_capture2)
	{
		Gpt_StartTimer(ChannelId, MAX_TICK);
		first_capture2 = FALSE;
	}
	else
	{
		Gpt_StopTimer(ChannelId);
		time_elapsed = Gpt_GetTimeElapsed(ChannelId);
		distance_measured = (time_elapsed * DISTANCE_CONSTANT);
		first_capture2 = TRUE;
	}
	return distance_measured;
}
