/**
*   @file    CDD_Mcl_PBcfg.c
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcl - Data structures for the Mcl driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCL
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
*   Dependencies         : none
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


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_PBcfg_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file Mcl_MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
* 
* @section Mcl_PBcfg_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' Mcl_MemMap.h included after each section define in order to set the current memory section
*
* @section Mcl_PBcfg_REF_3
* Violates MISRA 2004 Required Rule 1.4, compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported external indetifier
* The used compilers use more than 31 chars for identifiers
*
* @section Mcl_PBcfg_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed 
* between a pointer to object type and a different pointer to object type.
*
* @section Mcl_PBcfg_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and 
* functions shall not be reused
*
* @section Mcl_PBcfg_REF_7
* Violates MISRA 2004 Required Rule 12.7, Bitwise operators shall not be applied to operands whose
* underlying type is signed.
*
* @section Mcl_PBcfg_REF_8
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
* @section Mcl_PBcfg_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope should have internal linkage unless external linkage is required.
*
* @section Mcl_PBcfg_REF_11
* Violates MISRA 2004 Required Rule 8.8, All external objects should be declared in one and only one
* file.
* The declaration used to import definition of user callback function.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl.h"
#include "Mcl_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file             CDD_Mcl_PBcfg.c
* @requirements     BSW00374, BSW00318
*/
#define MCL_PBCFG_VENDOR_ID_C                     43
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C      3
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C   1
#define MCL_PBCFG_SW_MAJOR_VERSION_C              1
#define MCL_PBCFG_SW_MINOR_VERSION_C              0
#define MCL_PBCFG_SW_PATCH_VERSION_C              4


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if config source file and MCL header file are of the same vendor */
#if (MCL_PBCFG_VENDOR_ID_C != MCL_VENDOR_ID)
#error "CDD_Mcl_PBcfg.c and CDD_Mcl.h have different vendor IDs"
#endif
/* Check if config source file and MCL header file are of the same Autosar version */
#if ((MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl_PBcfg.c and CDD_Mcl.h are different"
#endif
/* Check if config source file and MCL header file are of the same Software version */
#if ((MCL_PBCFG_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (MCL_PBCFG_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (MCL_PBCFG_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl_PBcfg.c and CDD_Mcl.h are different"
#endif


/* Check if config source file and Mcl_IPW header file are of the same vendor */
#if (MCL_PBCFG_VENDOR_ID_C != MCL_IPW_VENDOR_ID)
#error "CDD_Mcl_PBcfg.c and Mcl_IPW.h have different vendor IDs"
#endif
/* Check if config source file and Mcl_IPW header file are of the same version */
#if ((MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Mcl_PBcfg.c and Mcl_IPW.h are different"
#endif
/* Check if config source file and Mcl_IPW header file are of the same Software Version */
#if ((MCL_PBCFG_SW_MAJOR_VERSION_C != MCL_IPW_SW_MAJOR_VERSION) || \
     (MCL_PBCFG_SW_MINOR_VERSION_C != MCL_IPW_SW_MINOR_VERSION) || \
     (MCL_PBCFG_SW_PATCH_VERSION_C != MCL_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl_PBcfg.c and Mcl_IPW.h are different"
#endif

        





/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"






/**
* @brief            Flexio basic configuration.
* @details          Configuration for Flexio hw IP.
*                   The Flexio allows to route trigger sources to peripherals.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */

static CONST( Mcl_FlexioConfigType, MCL_CONST) Mcl_Flexio_Config =
{
    (FLEXIO_CTRL_DOZEN_DIS_U32) | \
    (FLEXIO_CTRL_DBGE_DIS_U32),
    0U
};


/**
* @brief            Mcl basic configuration.
* @details          Configuration for Mcl.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
CONST( Mcl_ConfigType, MCL_CONST) Mcl_Config =
{
    
    
       
        /** Configuration for the Flexio hardware IP */
        &Mcl_Flexio_Config
         
    
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

