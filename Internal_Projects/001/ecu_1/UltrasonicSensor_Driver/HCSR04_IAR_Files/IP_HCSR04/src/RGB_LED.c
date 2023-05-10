/*RGB_LED Functions*/
//*STD_LOW is for ON while STD_HIGH is for OFF*//

#include "RGB_LED.h"

void ALL_OFF(void)
{
	Dio_WriteChannel(DioConf_DioChannel_GREEN_LED, STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_RED_LED, STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_BLUE_LED, STD_HIGH);
}

void RED_ON(void)
{
	ALL_OFF();
	Dio_WriteChannel(DioConf_DioChannel_RED_LED, STD_LOW);
}

void BLUE_ON(void)
{
	ALL_OFF();
	Dio_WriteChannel(DioConf_DioChannel_BLUE_LED, STD_LOW);
}

void GREEN_ON(void)
{
	ALL_OFF();
	Dio_WriteChannel(DioConf_DioChannel_GREEN_LED, STD_LOW);
}

void PURPLE_ON(void)
{
	ALL_OFF();
	Dio_WriteChannel(DioConf_DioChannel_RED_LED, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_BLUE_LED, STD_LOW);
}


