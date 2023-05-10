#ifndef RGB_H
#define RGB_H

#define RGB_CODE

#include "Compiler.h"
#include "Dio.h"
#include "Platform_Types.h"
#include "Port.h"
#include "device_registers.h"

FUNC(void, RGB_CODE) RGB_OFF(FUNC(void, RGB_CODE));
FUNC(void, RGB_CODE) LEDRED_ON(FUNC(void, RGB_CODE));
FUNC(void, RGB_CODE) LEDGREEN_ON(FUNC(void, RGB_CODE));
FUNC(void, RGB_CODE) LEDBLUE_ON(FUNC(void, RGB_CODE));
FUNC(void, RGB_CODE) LEDYELLOW_ON(FUNC(void, RGB_CODE));

#endif /* RGB_H */