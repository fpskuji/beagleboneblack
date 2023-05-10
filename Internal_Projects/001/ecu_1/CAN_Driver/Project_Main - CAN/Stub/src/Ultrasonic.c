#include "Ultrasonic.h"
#include "IT_Controller.h"

boolean firstCapture = TRUE;

/* UltraSonic_Send */
void UltraSonic_Send(Dio_ChannelType ChannelId)
{
  /* Output 10us HIGH on TRIG pin */
  Dio_WriteChannel(ChannelId, STD_HIGH);
//  uS10_Delay(1);
  Dio_WriteChannel(ChannelId, STD_LOW);
}

/* UltraSonic_Read */
uint32 UltraSonic_Read(Gpt_ChannelType ChannelId)
{
  static Gpt_ValueType elapsedTime;
  static uint32 distanceCalculated;
  
  if(firstCapture)
  {
    Gpt_StartTimer(ChannelId, 4294967295);
    firstCapture = FALSE;
  }
  else
  {
    Gpt_StopTimer(ChannelId);
    elapsedTime = Gpt_GetTimeElapsed(ChannelId);
    distanceCalculated = (uint32)(( elapsedTime * 0.0343 )/2);
    firstCapture = TRUE;
  }
  
  return distanceCalculated;
}