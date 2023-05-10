/*******************************************************************************
 * @author      
 * @brief      LED Indication Drivers 
 * @date        
 * 
 ******************************************************************************/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "ledindication.h"


/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32 TimeDelay;


/*******************************************************************************
 * Code
 ******************************************************************************/
void Delay(uint32 nTime){
  /* nTime: specifies the delay time length*/
  TimeDelay = nTime;            /*TimeDelay must be declared as volatile*/
  while(TimeDelay != 0);	/*Busy wait*/
}

void LED_Signal_Left(){
  Dio_FlipChannel(DioConf_DioChannel_Front_SignalL);
  Dio_FlipChannel(DioConf_DioChannel_Rear_SignalL);
  Delay(200);
}

void LED_Signal_Right(){
  Dio_FlipChannel(DioConf_DioChannel_Front_SignalR);
  Dio_FlipChannel(DioConf_DioChannel_Rear_SignalR);
  Delay(200);
}

void LED_Break(){
  Dio_WriteChannel(DioConf_DioChannel_Brake_L, STD_HIGH);
  Dio_WriteChannel(DioConf_DioChannel_Brake_R, STD_HIGH);
}

void LED_Reverse(){
  Dio_FlipChannel(DioConf_DioChannel_Reverse_L);
  Dio_FlipChannel(DioConf_DioChannel_Reverse_R);
  Delay(200);
}

void LED_HeadLight(){
  Dio_WriteChannel(DioConf_DioChannel_Head_L, STD_HIGH);
  Dio_WriteChannel(DioConf_DioChannel_Head_R, STD_HIGH);
}

void LED_Control(uint16 Can_Data){
  if((Can_Data & FLAG_SIGNAL_LEFT_MASK) == 0x20u){ // Signal Left
    if((Can_Data & SIGNAL_LEFT_MASK) == 0x1u){
      LED_Signal_Left();
    } 
  } else {
     Dio_WriteChannel(DioConf_DioChannel_Front_SignalL, STD_LOW);
     Dio_WriteChannel(DioConf_DioChannel_Rear_SignalL, STD_LOW);
  }

  if((Can_Data & FLAG_SIGNAL_RIGHT_MASK) == 0x40u){ // Signal Right
    if((Can_Data & SIGNAL_RIGHT_MASK) == 0x2u){
      LED_Signal_Right();
    } 
  } else {
    Dio_WriteChannel(DioConf_DioChannel_Front_SignalR, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_Rear_SignalR, STD_LOW);
  }

  if((Can_Data & FLAG_REVERSE_MASK) == 0x100u){ // Reverse(Blinking)
    if((Can_Data & REVERSE_MASK) == 0x8u){
      LED_Reverse();
    } 
  } else {
    Dio_WriteChannel(DioConf_DioChannel_Reverse_L, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_Reverse_R, STD_LOW);
  }

  if((Can_Data & FLAG_BREAK_MASK) == 0x80u){ 
    if((Can_Data & BREAK_MASK) == 0x4u){ // Brake
      LED_Break();
    }
  } else {
    Dio_WriteChannel(DioConf_DioChannel_Brake_L, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_Brake_R, STD_LOW);
  }
  
  if((Can_Data & FLAG_HEADLIGHT_MASK) == 0x200u){ // Headlight
    if((Can_Data & HEADLIGHT_MASK) == 0x10u){
      LED_HeadLight();
    }
  } else {
    Dio_WriteChannel(DioConf_DioChannel_Head_L, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_Head_R, STD_LOW);
  }
}