#include "ILI9341.h"

volatile int isClearText = FALSE;

/*Fill screen with the global background color*/
FUNC(void, AUTOMATIC) FillScreen(void)
{
    SET_ADDRESS(0, 0, LCD_WIDTH, LCD_HEIGHT);
    DrawColorBurst(LCD_WIDTH * LCD_HEIGHT);
}

/*Print pixels on screen based on specified color*/
FUNC(void, AUTOMATIC) DrawColorBurst(uint32 size)
{
    uint32 BufferSize = 0;

    if ((size * 2) < BURST_MAX_SIZE)
    {
        BufferSize = size;
    }
    else
    {
        BufferSize = BURST_MAX_SIZE;
    }

    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DC, STD_HIGH);

    uint8 shift = GLOBAL_BG_COLOR;
    uint8 BurstBuffer[BufferSize];

    for (uint32 j = 0; j < BufferSize; j += 2)
    {
        BurstBuffer[j] = shift;
        BurstBuffer[j + 1] = GLOBAL_BG_COLOR;
    }

    uint32 SendingSize = size * 2;
    uint32 SendingInBlock = SendingSize / BufferSize;

    if (SendingInBlock != 0)
    {
        for (uint32 j = 0; j < (SendingInBlock); j++)
        {
            Spi_WriteIB(SpiConf_SpiChannel_CH2, BurstBuffer);
            Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_2);
        }
    }
}

FUNC(void, AUTOMATIC) DrawPixel(uint16 x, uint16 y)
{
    if ((x >= LCD_WIDTH) || (y >= LCD_HEIGHT)) return;

    uint8 bufferX[4] = {x >> 8, x, (x + 1) >> 8, (x + 1)};
    uint8 bufferY[4] = {y >> 8, y, (y + 1) >> 8, (y + 1)};
    uint8 bufferC[2] = {GLOBAL_FONT_COLOR, GLOBAL_FONT_COLOR};

    WRITE_COMMAND(0x2A);                    // ADDRESS
    WRITE_BUFFER(bufferX, ADDRESS_BUFFER);  // XDATA

    WRITE_COMMAND(0x2B);                    // ADDRESS
    WRITE_BUFFER(bufferY, ADDRESS_BUFFER);  // YDATA

    WRITE_COMMAND(0x2C);  // ADDRESS

    if (isClearText == TRUE)
    {
        uint8 bufferC[2] = {GLOBAL_BG_COLOR, GLOBAL_BG_COLOR};
        WRITE_BUFFER(bufferC, COLOR_BUFFER);  // COLOR
    }
    else
    {
        WRITE_BUFFER(bufferC, COLOR_BUFFER);  // COLOR;
    }
}

/*Draw rectangle*/
FUNC(void, AUTOMATIC)
DrawRectangle(uint16 x, uint16 y, uint16 width, uint16 height)
{
    if ((x >= LCD_WIDTH) || (y >= LCD_HEIGHT)) return;

    if ((x + width - 1) >= LCD_WIDTH)
    {
        width = LCD_WIDTH - x;
    }

    if ((y + height - 1) >= LCD_HEIGHT)
    {
        height = LCD_HEIGHT - y;
    }

    SET_ADDRESS(x, y, x + width - 1, y + height - 1);
    DrawColorBurst(height * width);
}

/*Draw Character*/
FUNC(void, AUTOMATIC)
DrawCharacter(char ch, const uint8 font[], uint16 X, uint16 Y)
{
    if ((ch < 31) || (ch > 127)) return;

    uint8 fOffset, fWidth, fHeight, fBPL;
    uint8 *tempChar;

    fOffset = font[0];
    fWidth = font[1];
    fHeight = font[2];
    fBPL = font[3];

    tempChar = (uint8 *)&font[((ch - 0x20) * fOffset) +
                              4]; /* Current Character = Meta + (Character Index
                                     * Offset) */

    /* Clear background first */
    DrawRectangle(X, Y, fWidth, fHeight);

    for (int j = 0; j < fHeight; j++)
    {
        for (int i = 0; i < fWidth; i++)
        {
            uint8 z = tempChar[fBPL * i + ((j & 0xF8) >> 3) +
                               1]; /* (j & 0xF8) >> 3, increase one by 8-bits */
            uint8 b = 1 << (j & 0x07);
            if ((z & b) != 0x00)
            {
                DrawPixel(X + i, Y + j);
            }
        }
    }
}

/*Draw text on screen*/
FUNC(void, AUTOMATIC)
DrawText(const char *str, const uint8 font[], uint16 X, uint16 Y)
{
    isClearText = FALSE;

    uint8 charWidth;         /* Width of character */
    uint8 fOffset = font[0]; /* Offset of character */
    uint8 fWidth = font[1];  /* Width of font */

    while (*str)
    {
        DrawCharacter(*str, font, X, Y);

        /* Check character width and calculate proper position */
        uint8 *tempChar = (uint8 *)&font[((*str - 0x20) * fOffset) + 4];
        charWidth = tempChar[0];

        if (charWidth + 2 < fWidth)
        {
            /* If character width is smaller than font width */
            X += (charWidth + 2);
        }
        else
        {
            X += fWidth;
        }

        str++;
    }
}

/*Clear Text function*/
FUNC(void, AUTOMATIC)
ClearText(const char *str, const uint8 font[], uint16 X, uint16 Y)
{
    isClearText = TRUE;

    uint8 charWidth;         /* Width of character */
    uint8 fOffset = font[0]; /* Offset of character */
    uint8 fWidth = font[1];  /* Width of font */

    while (*str)
    {
        DrawCharacter(*str, font, X, Y);

        /* Check character width and calculate proper position */
        uint8 *tempChar = (uint8 *)&font[((*str - 0x20) * fOffset) + 4];
        charWidth = tempChar[0];

        if (charWidth + 2 < fWidth)
        {
            /* If character width is smaller than font width */
            X += (charWidth + 2);
        }
        else
        {
            X += fWidth;
        }

        str++;
    }
}

/*Send Command*/
FUNC(void, AUTOMATIC) WRITE_COMMAND(uint8 Send_Command)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DC, STD_LOW);
    Spi_WriteIB(SpiConf_SpiChannel_CH0, &Send_Command);
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
}

/*Send Data*/
FUNC(void, AUTOMATIC) WRITE_DATA(uint8 Send_Data)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DC, STD_HIGH);
    Spi_WriteIB(SpiConf_SpiChannel_CH0, &Send_Data);
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
}

/*Set coordinates on screen*/
FUNC(void, AUTOMATIC) SET_ADDRESS(uint16 x1, uint16 y1, uint16 x2, uint16 y2)
{
    uint8 buffer[4];
    buffer[0] = x1 >> 8;
    buffer[1] = x1;
    buffer[2] = x2 >> 8;
    buffer[3] = x2;

    WRITE_COMMAND(0x2A);
    WRITE_BUFFER(buffer, ADDRESS_BUFFER);

    buffer[0] = y1 >> 8;
    buffer[1] = y1;
    buffer[2] = y2 >> 8;
    buffer[3] = y2;

    WRITE_COMMAND(0x2B);
    WRITE_BUFFER(buffer, ADDRESS_BUFFER);
    WRITE_COMMAND(0x2C);
}

/*Write to specific buffer size and transmit*/
FUNC(void, AUTOMATIC) WRITE_BUFFER(uint8 *buffer, uint8 bufferType)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_DC, STD_HIGH);

    if (bufferType == ADDRESS_BUFFER)
    {
        Spi_WriteIB(SpiConf_SpiChannel_CH1, buffer);
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_1);
    }
    else if (bufferType == BIG_BUFFER)
    {
        Spi_WriteIB(SpiConf_SpiChannel_CH2, buffer);
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_2);
    }
    else if (bufferType == COLOR_BUFFER)
    {
        Spi_WriteIB(SpiConf_SpiChannel_CH3, buffer);
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_3);
    }
    else
    {
        ;
    }
}

/*Reset Display*/
FUNC(void, AUTOMATIC) RESET_DISPLAY(void)
{
    /* uint8 Null_Data = 0x00; */
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_RST, STD_LOW);
    Spi_WriteIB(SpiConf_SpiChannel_CH0, NULL_PTR);
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_RST, STD_HIGH);
}

/*Enable display*/
FUNC(void, AUTOMATIC) EN_DISPLAY(void)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_RST, STD_HIGH);
}

/*Initialize Display*/
FUNC(void, AUTOMATIC)
INIT_DISPLAY(void)
{
    EN_DISPLAY();
    RESET_DISPLAY();

    /*Perform Software Reset*/
    WRITE_COMMAND(0x01);

    /*Power Control A*/
    WRITE_COMMAND(0xCB);
    WRITE_DATA(0x39);
    WRITE_DATA(0x2C);
    WRITE_DATA(0x00);
    WRITE_DATA(0x34);
    WRITE_DATA(0x02);

    /*Power Control B*/
    WRITE_COMMAND(0xCF);
    WRITE_DATA(0x00);
    WRITE_DATA(0xC1);
    WRITE_DATA(0x30);

    /*Driver Timing Control A*/
    WRITE_COMMAND(0xE8);
    WRITE_DATA(0x85);
    WRITE_DATA(0x00);
    WRITE_DATA(0x78);

    /*Driver Timing Control B*/
    WRITE_COMMAND(0xEA);
    WRITE_DATA(0x00);
    WRITE_DATA(0x00);

    /*Power On Sequence Control B*/
    WRITE_COMMAND(0xED);
    WRITE_DATA(0x64);
    WRITE_DATA(0x03);
    WRITE_DATA(0x12);
    WRITE_DATA(0x81);

    /*Pump Ratio Control*/
    WRITE_COMMAND(0xF7);
    WRITE_DATA(0x20);

    /*Power Control VRH[5:0]*/
    WRITE_COMMAND(0xC0);
    WRITE_DATA(0x23);

    /*Power Control SAP[2:0]; BT[3:0]*/
    WRITE_COMMAND(0xC1);
    WRITE_DATA(0x10);

    /*VCM CONTROL*/
    WRITE_COMMAND(0xC5);
    WRITE_DATA(0x3E);
    WRITE_DATA(0x28);

    /*VCM CONTROL 2*/
    WRITE_COMMAND(0xC7);
    WRITE_DATA(0x86);

    /*MEMORY ACCESS CONTROL*/
    WRITE_COMMAND(0x36);
    WRITE_DATA(0x48);

    /*Pixel Format*/
    WRITE_COMMAND(0x3A);
    WRITE_DATA(0x55);

    /*FRAME RATIO CONTROL, STANDARD RGB COLOR*/
    WRITE_COMMAND(0xB1);
    WRITE_DATA(0x00);
    WRITE_DATA(0x18);

    /*Display Function Control*/
    WRITE_COMMAND(0xB6);
    WRITE_DATA(0x08);
    WRITE_DATA(0x82);
    WRITE_DATA(0x27);

    /*3Gamma Function Disable*/
    WRITE_COMMAND(0xF2);
    WRITE_DATA(0x00);

    /*Gamma Curve Selected*/
    WRITE_COMMAND(0x26);
    WRITE_DATA(0x01);

    /*Positive Gamma Correction*/
    WRITE_COMMAND(0xE0);
    WRITE_DATA(0x0F);
    WRITE_DATA(0x31);
    WRITE_DATA(0x2B);
    WRITE_DATA(0x0C);
    WRITE_DATA(0x0E);
    WRITE_DATA(0x08);
    WRITE_DATA(0x4E);
    WRITE_DATA(0xF1);
    WRITE_DATA(0x37);
    WRITE_DATA(0x07);
    WRITE_DATA(0x10);
    WRITE_DATA(0x03);
    WRITE_DATA(0x0E);
    WRITE_DATA(0x89);
    WRITE_DATA(0x00);

    /*Negative Gamma Correction*/
    WRITE_COMMAND(0xE1);
    WRITE_DATA(0x00);
    WRITE_DATA(0x0E);
    WRITE_DATA(0x14);
    WRITE_DATA(0x03);
    WRITE_DATA(0x11);
    WRITE_DATA(0x07);
    WRITE_DATA(0x31);
    WRITE_DATA(0xC1);
    WRITE_DATA(0x48);
    WRITE_DATA(0x08);
    WRITE_DATA(0x0F);
    WRITE_DATA(0x0C);
    WRITE_DATA(0x31);
    WRITE_DATA(0x36);
    WRITE_DATA(0x0F);

    /*Exit Sleep*/
    WRITE_COMMAND(0x11);

    /*Turn On Display*/
    WRITE_COMMAND(0x29);

    /*Set Screen  Rotation*/
    //WRITE_DATA(0x40 | 0x08);
}