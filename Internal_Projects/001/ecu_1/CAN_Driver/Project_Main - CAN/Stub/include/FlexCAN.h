#ifndef FLEXCAN_H_
#define FLEXCAN_H_

#include "Platform_Types.h"

uint32 Check_MBFlag(void);
void FLEXCAN0_init (void);
void FLEXCAN0_transmit_msg (uint32);
void FLEXCAN0_receive_msg (void);

#endif /* FLEXCAN_H_ */