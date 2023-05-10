/* User Made */

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "CanIf.h"
#include "Can.h"

/******************************************************************************
*   VERSION CHECK
 *****************************************************************************/

/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/

/******************************************************************************
 *  EXTERN
 *****************************************************************************/

/******************************************************************************
 *  LOCAL TYPEDEFS
 *****************************************************************************/

/******************************************************************************
 *  LOCAL CONSTANTS
 *****************************************************************************/

/******************************************************************************
 *  LOCAL VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  GLOBAL VARIABLES
 *****************************************************************************/
uint8 CanIf_u8RxIndicationCnt = 0U;
boolean CanIf_bRxFlag = FALSE;
uint32 Rx_Id;
uint8 CANDATA = 'S';

/******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *****************************************************************************/

/******************************************************************************
 *  LOCAL FUNCTION
 ******************************************************************************/

/******************************************************************************
 *  GLOBAL FUNCTION
 *****************************************************************************/
FUNC (void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, CANIF_VAR) Controller)
{
}

FUNC (void, CANIF_CODE) CanIf_TxConfirmation(VAR(PduIdType, CANIF_VAR) CanTxPduId)
{
}

FUNC (void, CANIF_CODE) CanIf_RxIndication(P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr)
{
  CanIf_u8RxIndicationCnt++;
  CanIf_bRxFlag = TRUE;
  (void)Mailbox;
  Rx_Id = Mailbox->CanId;

  CANDATA = *(PduInfoPtr->SduDataPtr);
}



FUNC (void, CANIF_CODE) CanIf_ControllerModeIndication(VAR(uint8, CANIF_VAR) Controller, VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode)
{
}
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
FUNC (void, CANIF_CODE) CanIf_CurrentIcomConfiguration(VAR(uint8, CANIF_VAR) ControllerId, VAR(IcomConfigIdType, CANIF_VAR) ConfigurationId, VAR(IcomSwitch_ErrorType, CANIF_VAR) Error)
{ 
}
#endif
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
FUNC (Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit( PduIdType TxPduId,PduInfoType* PduInfoPtr )
{
}
#endif

#ifdef __cplusplus
}
#endif

   

/**
 * @}
 */