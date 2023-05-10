#ifndef ULTRASONIC_H
#define ULTRASONC_H

#include "Dio.h"
#include "Gpt.h"

void UltraSonic_Send(Dio_ChannelType);
uint32 UltraSonic_Read(Gpt_ChannelType);

#endif

