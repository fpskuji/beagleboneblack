#ifndef FLEXCAN_H_
#define FLEXCAN_H_

#include "Can.h"

#define ECU0 0
#define ECU1 1
#define ECU2 2

// #define CAN_NODE (ECU0)
#define CAN_NODE (ECU1)
// #define CAN_NODE (ECU2)

#if(CAN_NODE == ECU1)
#define Can_Get_Distance1_Func_Id            (0x0100)
#define Can_Get_Distance2_Func_Id            (0x0101)
#define Can_Get_Distance3_Func_Id            (0x0102)

#define Can_Enable_RightTurnSignal_Func_Id   (0x0200)
#define Can_Enable_LeftTurnSignal_Func_Id    (0x0201)
#define Can_Enable_BrakeTurnSignal_Func_Id   (0x0202)
#define Can_Enable_HeadTurnSignal_Func_Id    (0x0203)
#define Can_Enable_ReverseTurnSignal_Func_Id (0x0204)

#define Can_Set_AirbagOff_Func_Id            (0x0300)
#endif /* CAN_NODE == ECU1 */

#if(CAN_NODE == ECU2)
#define Can_Set_SteeringAngle_Func_Id        (0x0400)
#define Can_Set_SteeringStraight_Func_Id     (0x0401)

#define Can_Set_Speed_Func_Id                (0x0500)
#define Can_Set_MotorDirection_Func_Id       (0x0501)
#define Can_Enable_Motor_Func_Id             (0x0502)

#define Can_Get_Speed_Func_Id                (0x0600)
#endif /* CAN_NODE == ECU2 */

#define CAN_FUNC_ID_SHIFT                    (3U)
#define CAN_FUNC_PARAM_SHIFT                 (3U)

#define Can_Func_Id(can_data)                (can_data >> CAN_FUNC_ID_SHIFT)
#define Can_Func_Param(can_data, func_id)    (can_data & (~func_id))

void Can_DriverInit(void);
void Can_SendData(uint32 id, uint8* btdata);
char Can_ConvertDatatoChar(void);

#endif /* FLEXCAN_H_ */