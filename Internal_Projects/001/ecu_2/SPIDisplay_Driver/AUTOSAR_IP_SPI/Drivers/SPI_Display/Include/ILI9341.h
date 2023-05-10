#include "main.h"

#define ILI9341_SCREEN_HEIGHT 240
#define ILI9341_SCREEN_WIDTH 320

#define BURST_MAX_SIZE 500
#define BLACK 0x0000
#define WHITE 0xFFFF

#define GLOBAL_BG_COLOR (uint16) BLACK
#define GLOBAL_FONT_COLOR (uint16) WHITE

#define ADDRESS_BUFFER (uint8)1
#define BIG_BUFFER (uint8)2
#define COLOR_BUFFER (uint8)3

#define TRUE 1
#define FALSE 0