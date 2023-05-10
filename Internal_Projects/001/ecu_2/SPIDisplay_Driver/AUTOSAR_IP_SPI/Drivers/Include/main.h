#include <stdio.h>

#include "Dio.h"
#include "Mcu.h"
#include "Port.h"
#include "Spi.h"
#include "device_registers.h"
#include "fonts.h"
#include "system_S32K144.h"

FUNC(void, AUTOMATIC) FillScreen(void);
FUNC(void, AUTOMATIC) DrawColorBurst(uint32 size);
FUNC(void, AUTOMATIC) DrawPixel(uint16 x, uint16 y);
FUNC(void, AUTOMATIC)
DrawRectangle(uint16 x, uint16 y, uint16 width, uint16 height);
FUNC(void, AUTOMATIC)
DrawCharacter(char ch, const uint8 font[], uint16 X, uint16 Y);
FUNC(void, AUTOMATIC)
DrawText(const char *str, const uint8 font[], uint16 X, uint16 Y);
FUNC(void, AUTOMATIC)
ClearText(const char *str, const uint8 font[], uint16 X, uint16 Y);
FUNC(void, AUTOMATIC) WRITE_COMMAND(uint8 Send_Command);
FUNC(void, AUTOMATIC) WRITE_DATA(uint8 Send_Data);
FUNC(void, AUTOMATIC) SET_ADDRESS(uint16 x1, uint16 y1, uint16 x2, uint16 y2);
FUNC(void, AUTOMATIC) WRITE_BUFFER(uint8 *buffer, uint8 bufferType);
FUNC(void, AUTOMATIC) RESET_DISPLAY(void);
FUNC(void, AUTOMATIC) EN_DISPLAY(void);
FUNC(void, AUTOMATIC) INIT_DISPLAY(void);