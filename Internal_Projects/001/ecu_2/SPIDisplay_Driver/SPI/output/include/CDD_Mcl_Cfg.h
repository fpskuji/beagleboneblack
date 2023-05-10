/**
*   @file CDD_Mcl_Cfg.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcl - contains the configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
*
*   @addtogroup MCL_MODULE
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









#ifndef CDD_MCL_CFG_H
#define CDD_MCL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif 
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*          contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
*          significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcl_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets or for a function define.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Mcl_EnvCfg.h"
#include "Mcal.h"
#include "modules.h"
#if ((USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON) || (USE_OCU_MODULE==STD_ON))

#if (USE_ICU_MODULE==STD_ON)
#include "Icu_Cfg.h"
#endif

#if (USE_PWM_MODULE==STD_ON)
#include "Pwm_Cfg.h"
#endif

#if (USE_OCU_MODULE==STD_ON)
#include "Ocu_Cfg.h"
#endif

#endif
    
    
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_VENDOR_ID_CFG                       43

#define MCL_AR_RELEASE_MAJOR_VERSION_CFG        4
#define MCL_AR_RELEASE_MINOR_VERSION_CFG        3
#define MCL_AR_RELEASE_REVISION_VERSION_CFG     1

#define MCL_SW_MAJOR_VERSION_CFG                1
#define MCL_SW_MINOR_VERSION_CFG                0
#define MCL_SW_PATCH_VERSION_CFG                4
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MCL_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Dem.h file are of the same Autosar version */

#if (MCL_VENDOR_ID_CFG != MCL_ENVCFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.h and Mcl_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same Autosar version */
#if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( MCL_AR_RELEASE_REVISION_VERSION_CFG !=  MCL_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION_CFG != MCL_ENVCFG_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_CFG != MCL_ENVCFG_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_CFG != MCL_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and modules header file are of the same Autosar version */
    #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MODULES_AR_RELEASE_MINOR_VERSION_H))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and modules.h are different"
    #endif
#endif
#if (USE_ICU_MODULE==STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Icu_Cfg header file are of the same Autosar version */
    #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
         ( MCL_AR_RELEASE_MINOR_VERSION_CFG != ICU_AR_RELEASE_MINOR_VERSION_CFG))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Icu_Cfg.h are different"
    #endif
#endif
#endif
#if (USE_PWM_MODULE==STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Pwm_Cfg header file are of the same Autosar version */
    #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
         ( MCL_AR_RELEASE_MINOR_VERSION_CFG != PWM_CFG_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Pwm_Cfg.h are different"
    #endif
#endif
#endif
#if (USE_OCU_MODULE==STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Ocu_Cfg header file are of the same Autosar version */
    #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != OCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
         ( MCL_AR_RELEASE_MINOR_VERSION_CFG != OCU_CFG_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Ocu_Cfg.h are different"
    #endif
#endif
#endif


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
    

#define MCL_PRECOMPILE_SUPPORT (STD_OFF)




/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_DEV_ERROR_DETECT                  (STD_OFF)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_GetVersionInfo() from the code.
*        STD_ON: Mcl_GetVersionInfo() can be used. STD_OFF: Mcl_GetVersionInfo() can not be used.
*   
*/
#define MCL_GET_VERSION_INFO_API              (STD_OFF)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DeInit() from the code.
*        STD_ON: Mcl_DeInit() can be used. STD_OFF: Mcl_DeInit() can not be used.
*   
*/
#define MCL_DEINIT_API                        (STD_OFF)

/**
* @brief      Switch to indicate that Mcl_SelectCommonTimebase API is supported
*           STD_ON: Mcl_SelectCommonTimebase() can be used. STD_OFF: Mcl_SelectCommonTimebase() can not be used.
*
*/
#define MCL_SELECT_COMMON_TIMEBASE_API        (STD_OFF)

/**
*   @brief   Switches DMA features initialization on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_ENABLE_DMA              (STD_OFF)

/**
*   @brief  Switches the TRGMUX initialization by MCL on or off
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_ENABLE_TRGMUX                   (STD_OFF)
/**
* @brief define number of trigger mux registers
*/
#define MCL_NUM_TRGMUX_REG                  (25U)
#define MCL_NUM_REG_MISSING_SEL_FIELD       (9U)
#define MCL_MAXIMUM_BIT_FIELD_TRIGGER_VALUE  (0x63U)

#define MCL_TRGMUX_DMAMUX0_AVAILABLE
#define MCL_TRGMUX_EXTOUT0_AVAILABLE
#define MCL_TRGMUX_EXTOUT1_AVAILABLE
#define MCL_TRGMUX_ADC0_AVAILABLE
#define MCL_TRGMUX_ADC1_AVAILABLE
#define MCL_TRGMUX_CMP0_AVAILABLE
#define MCL_TRGMUX_FTM0_AVAILABLE
#define MCL_TRGMUX_FTM1_AVAILABLE
#define MCL_TRGMUX_FTM2_AVAILABLE
#define MCL_TRGMUX_FTM3_AVAILABLE
#define MCL_TRGMUX_PDB0_AVAILABLE
#define MCL_TRGMUX_PDB1_AVAILABLE
#define MCL_TRGMUX_FLEXIO_AVAILABLE
#define MCL_TRGMUX_LPIT0_AVAILABLE
#define MCL_TRGMUX_LPUART0_AVAILABLE
#define MCL_TRGMUX_LPUART1_AVAILABLE
#define MCL_TRGMUX_LPI2C0_AVAILABLE
#define MCL_TRGMUX_LPSPI0_AVAILABLE
#define MCL_TRGMUX_LPSPI1_AVAILABLE
#define MCL_TRGMUX_LPTMR0_AVAILABLE


/*********************************** FLEXIO SECTION ********************************/
#define MCL_ENABLE_FLEXIO             (STD_ON)



/**
* @brief      This define specifies the number of FTM modules present on the derivative. It's used for the
*             Mcl_SelectCommonTimebase API
*
*/
#define MCL_FTM_CHANNEL_NO            ((uint32)4UL)



/**
* @brief            Support for User mode.
*                   STD_ON: the Mcl driver can be executed from both supervisor and user mode. 
*                   STD_OFF: the Mcl driver can be executed only from supervisor mode. 
*/
#define MCL_ENABLE_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_DMAMUX_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_AXBS_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_LMEM_USER_MODE_SUPPORT     (STD_ON)
#define MCL_TRGMUX_USER_MODE_SUPPORT     (STD_ON)
/**
* @brief            Protected Register in User mode
*                   Macro use to enable if IP hw need to configure Reg_Prot to access from user mode
*/

#define MCL_DMAMUX_REG_PROT_AVAILABLE (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mcl in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */


/*********************************** CACHE SECTION ***********************************/
/* Enable LMEM cache functionality */
#define MCL_LMEM_ENABLE_CACHE_API           (STD_OFF)

/* Enable the use of cache invalidate and flush calls in other drivers */
#define MCL_SYNCRONIZE_CACHE                (STD_OFF)

/* LMEM Cache operations timeout value */
#define MCL_LMEM_CACHE_TIMEOUT_VALUE        (2147483647UL)

/* LMEM Enable also Write Buffer alongside with Cache enable */
#define MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER  (STD_OFF)

/* PS Cache instance hardware availability */
#define MCL_LMEM_CACHE_PS_AVAILABLE         (STD_OFF)

/* PC cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PC_SIZE              ((uint32)4096UL)

/* PS cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PS_SIZE              ((uint32)0UL)

/* Cache line size, expressed in bytes */
#define MCL_LMEM_CACHE_LINE_SIZE            ((uint32)16UL)

/*********************************** CACHE SECTION ***********************************/



/** Variant aware structure.c file. */

/** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MCL_CONF_PB \
 extern CONST(Mcl_ConfigType, MCL_CONST) Mcl_Config;

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif    /* CDD_MCL_CFG_H */
/**@}*/


