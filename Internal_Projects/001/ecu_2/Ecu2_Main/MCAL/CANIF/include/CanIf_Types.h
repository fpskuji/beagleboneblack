/**
*   @file    CanIf_Types.h
*   @version 1.0.4
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
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
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_TYPES_VENDOR_ID                         43
#define CANIF_TPYES_MODULE_ID                         60
#define CANIF_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_TYPES_AR_RELEASE_MINOR_VERSION          3
#define CANIF_TYPES_AR_RELEASE_REVISION_VERSION       1
#define CANIF_TYPES_SW_MAJOR_VERSION                  1
#define CANIF_TYPES_SW_MINOR_VERSION                  0
#define CANIF_TYPES_SW_PATCH_VERSION                  4
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStack_Types.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and ComStack_Types.h are different"
    #endif
    /* Check if current file and Can_GeneralTypes.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and Can_GeneralTypes.h are different"
    #endif
#endif
/*=================================================================================================*/

/**
* @brief          CanIf_ControllerModeType
* @details        Operating modes of the CAN Controller and CAN Driver
*
*/
typedef enum
    {
        CANIF_CS_UNINIT = 0U,    /**< @brief UNINIT mode */
        CANIF_CS_SLEEP,         /**< @brief SLEEP mode */
        CANIF_CS_STARTED,        /**< @brief STARTED mode */
        CANIF_CS_STOPPED        /**< @brief STOPPED mode */
    } CanIf_ControllerModeType;
      
#ifdef __cplusplus
}
#endif

#endif 
