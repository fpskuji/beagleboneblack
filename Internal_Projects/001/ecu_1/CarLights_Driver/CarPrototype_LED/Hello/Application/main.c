/*******************************************************************************
 * @author      
 * @brief      Test for LED Drivers 
 * @date        
 * 
 ******************************************************************************/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "device_registers.h"
#include "ledindication.h"
#include <stdio.h>


/*******************************************************************************
 * Variables
 ******************************************************************************/
extern volatile uint32 TimeDelay;


/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void){     /*SysTick interrupt service routine*/
    if (TimeDelay > 0) 	        /*Prevent it from being negative*/
	TimeDelay--; 		/*TimeDelay is a global volatile variable*/
}

void SysTick_Initialize(uint32 ticks){
  S32_SysTick->CSR = 0;			     /* Disable SysTick */
    S32_SysTick->RVR = (uint32)(ticks - 1u); /* Set reload register */
    S32_SysTick->CVR = 0u;		     /* Reset counter value */
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u)
            | S32_SysTick_CSR_CLKSOURCE(1u); /* Enable SysTick IRQ and Timer */
}

int main()
{
  uint16 Can_Data = 0x0000;
  uint8 command;
  uint8 flag_SignalLeft = 0;
  uint8 flag_SignalRight = 0;
  uint8 flag_Reverse = 0;
  uint8 flag_Head = 0;
  Mcu_Init(&Mcu_Config);
  Mcu_InitClock(McuClockSettingConfig_0);
  Port_Init(&Port_Config);
  
  SysTick_Initialize(48000000/1000);
  while(1)
  {
    /*
    if(Dio_ReadChannel(DioConf_DioChannel_Sw_SignalL) == STD_HIGH){
      scanf("%d", &command);
      printf("%d\n- \n", command);
    }
    */
    if(Dio_ReadChannel(DioConf_DioChannel_Sw_SignalL) == STD_HIGH){
      command = 4;
    }
    /*
    if(Dio_ReadChannel(DioConf_DioChannel_Sw_SignalR) == STD_HIGH){
      command = 2;
    }
    */
    if(Dio_ReadChannel(DioConf_DioChannel_Sw_SignalR) == STD_HIGH){
      Can_Data = (Can_Data | (1 << 2) | (1 << 7)); // Break
    } else {
      Can_Data = (Can_Data & 0xFF7B);
    }
    
    
    if(command == 1){ // Signal Left
      Can_Data = ((Can_Data | (1 << 0) | (1 << 5)) & (CLEAR_SIGNAL_LEFT_MASK));
      flag_SignalLeft += 1;
      flag_SignalRight = 0;
      flag_Reverse = 0;
      if(flag_SignalLeft > 1){
        Can_Data = (Can_Data & (0xFFDF));
        flag_SignalLeft = 0;
      }
      //printf("%hx\n", Can_Data); 
    }
    else if(command == 2){ // Signal Right
      Can_Data = ((Can_Data | (1 << 1) | (1 << 6)) & (CLEAR_SIGNAL_RIGHT_MASK));
      flag_SignalRight += 1;
      flag_SignalLeft = 0;
      flag_Reverse = 0;
      if(flag_SignalRight > 1){
        Can_Data = (Can_Data & (0xFFBF));
        flag_SignalRight = 0;
      }
      //printf("%hx\n", Can_Data); 
    }
    else if(command == 3){ // Reverse
      Can_Data = ((Can_Data | (1 << 3) | (1 << 8)) & (CLEAR_REVERSE_MASK));
      flag_Reverse += 1;
      flag_SignalLeft = 0;
      flag_SignalRight = 0;
      if(flag_Reverse > 1){
        Can_Data = (Can_Data & (0xFEFF));
        flag_Reverse = 0;
      }
      //printf("%hx\n", Can_Data); 
    }
    if(command == 4){ // Headlight
      Can_Data = (Can_Data | (1 << 4) | (1 << 9));
      flag_Head += 1;
      if(flag_Head > 1){
        Can_Data = (Can_Data & 0xFDEF);
        flag_Head = 0;
      }
    }
    
    LED_Control(Can_Data);
    command = 0;
  }
}