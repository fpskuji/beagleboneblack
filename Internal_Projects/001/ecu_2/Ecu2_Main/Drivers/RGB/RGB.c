#include "RGB.h"

FUNC(void, RGB_CODE) RGB_OFF(VAR(void, RGB_CODE))
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Red, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Green, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Blue, STD_HIGH);
}

FUNC(void, RGB_CODE) LEDRED_ON(VAR(void, RGB_CODE))
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Red, STD_LOW);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Green, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Blue, STD_HIGH);
}

FUNC(void, RGB_CODE) LEDGREEN_ON(VAR(void, RGB_CODE))
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Red, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Green, STD_LOW);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Blue, STD_HIGH);
}

FUNC(void, RGB_CODE) LEDBLUE_ON(VAR(void, RGB_CODE))
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Red, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Green, STD_HIGH);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Blue, STD_LOW);
}

FUNC(void, RGB_CODE) LEDYELLOW_ON(VAR(void, RGB_CODE))
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Red, STD_LOW);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Green, STD_LOW);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_Blue, STD_HIGH);
}