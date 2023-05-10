/**
*   @file    Os_counter_api.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Os - Os module interface
*   @details AUTOSAR Os module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
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
#include "Os.h"




/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define OS_COUNTER_API_VENDOR_ID_C                    43    /* Freescale AUTOSAR Vendor ID  */
#define OS_COUNTER_API_MODULE_ID_C                    0x01           /* OS Module ID                 */

#define OS_COUNTER_API_AR_RELEASE_MAJOR_VERSION_C     4   /* Major version number of AUTOSAR specification       */
#define OS_COUNTER_API_AR_RELEASE_MINOR_VERSION_C     3   /* Minor version number of AUTOSAR specification       */
#define OS_COUNTER_API_AR_RELEASE_REVISION_VERSION_C  1   /* Patch level version number of AUTOSAR specification */

#define OS_COUNTER_API_SW_MAJOR_VERSION_C             1   /* Major version number of the implementation   */
#define OS_COUNTER_API_SW_MINOR_VERSION_C             0   /* Minor version number of the implementation   */
#define OS_COUNTER_API_SW_PATCH_VERSION_C             4   /* Patch level version number of the implementation */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check current file version with Os.h file */
#if (OS_COUNTER_API_VENDOR_ID_C != OS_VENDOR_ID)
    #error "Os_counter_api.c and Os.h have different vendor ids"
#endif
#if ((OS_COUNTER_API_AR_RELEASE_MAJOR_VERSION_C    != OS_AR_RELEASE_MAJOR_VERSION) || \
     (OS_COUNTER_API_AR_RELEASE_MINOR_VERSION_C    != OS_AR_RELEASE_MINOR_VERSION) || \
     (OS_COUNTER_API_AR_RELEASE_REVISION_VERSION_C != OS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Os_counter_api.c and Os.h are different"
#endif
#if ((OS_COUNTER_API_SW_MAJOR_VERSION_C != OS_SW_MAJOR_VERSION) || \
     (OS_COUNTER_API_SW_MINOR_VERSION_C != OS_SW_MINOR_VERSION) || \
     (OS_COUNTER_API_SW_PATCH_VERSION_C != OS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Os_counter_api.c and Os.h are different"
#endif



/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
StatusType GetCounterValue (CounterType ctrId, TickRefType tickRef)
{
    return 0;
}

StatusType GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef)
{
    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */

