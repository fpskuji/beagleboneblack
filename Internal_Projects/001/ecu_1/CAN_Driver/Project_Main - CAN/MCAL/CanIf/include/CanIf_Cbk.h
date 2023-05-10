/**
*   @file    CanIf.h
*   @version 1.0.4
*
*   @brief   AUTOSAR CanIf - CanIf Cbk module interface
*   @details AUTOSAR CanIf Cbk module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.4
*   Build Version        : S32K1XX_MCAL_1_0_4_RTM_ASR_REL_4_3_REV_0001_04-Apr-22
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2022 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CBK_VENDOR_ID                         43
#define CANIF_CBK_MODULE_ID                         60
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION          3
#define CANIF_CBK_AR_RELEASE_REVISION_VERSION       1
#define CANIF_CBK_SW_MAJOR_VERSION                  1
#define CANIF_CBK_SW_MINOR_VERSION                  0
#define CANIF_CBK_SW_PATCH_VERSION                  4
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CBK_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf_Cbk.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same module */
#if (CANIF_CBK_MODULE_ID != CANIF_TPYES_MODULE_ID)
#error "CanIf_Cbk.h and CanIf_Types.h have different module ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CBK_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CBK_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CBK_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf_Cbk.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_CBK_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_CBK_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_CBK_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf_Cbk.h and CanIf_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC (void, CANIF_CODE) CanIf_TxConfirmation(VAR(PduIdType, CANIF_VAR) CanTxPduId);

FUNC (void, CANIF_CODE) CanIf_RxIndication(P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr);

FUNC (void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, CANIF_VAR) Controller);

FUNC (void, CANIF_CODE) CanIf_ControllerModeIndication(VAR(uint8, CANIF_VAR) Controller, VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode);
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
FUNC (void, CANIF_CODE) CanIf_CurrentIcomConfiguration(VAR(uint8, CANIF_VAR) ControllerId, VAR(IcomConfigIdType, CANIF_VAR) ConfigurationId, VAR(IcomSwitch_ErrorType, CANIF_VAR) Error);
#endif
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
FUNC (Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit( PduIdType TxPduId,PduInfoType* PduInfoPtr );
#endif

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CBK_H */

/** @} */

