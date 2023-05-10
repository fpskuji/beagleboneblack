#ifndef SYSTEM_CONFIG
#define SYSTEM_CONFIG

/**
 * @brief SYSTEM memory class
 *
 */
#define SYSTEM_CODE

#include "Compiler.h"
#include "Platform_Types.h"
#include "device_registers.h"

FUNC(void, SYSTEM_CODE) PortClock_Enable(FUNC(void, SYSTEM_CODE));
FUNC(void, SYSTEM_CODE) Systick_Init(FUNC(__IO uint32, SYSTEM_CODE));
FUNC(void, SYSTEM_CODE) Ptick_Decrement(FUNC(void, SYSTEM_CODE));
FUNC(void, SYSTEM_CODE) delay_ms(uint32 delayTime_ms);

#endif /* SYSTEM_CONFIG */