/**
*   @file    Spi_Cfg.h
*   @implements Spi_Cfg.h_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI,FLEXIO
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
the NULL option should be removed for TXdnl - DO NOT modify this M4 line!
==================================================================================================*/

#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, Names of new objects shall be checked in order to
* not cause confusion with standard object names.
*
* @section Spi_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, Precautions shall be taken in order for defines not
* leading to unexpected behaviour when substitution is made.
*
* @section Spi_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_MODULE_ID_CFG                       83
#define SPI_VENDOR_ID_CFG                       43
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_CFG        4
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_CFG        3
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_CFG     1
#define SPI_SW_MAJOR_VERSION_CFG                1
#define SPI_SW_MINOR_VERSION_CFG                0
#define SPI_SW_PATCH_VERSION_CFG                4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Switches the Development Error functionality ON or OFF.
* @details Switches the Development Error Detection and Notification ON or OFF.
* @implements SPI_DEV_ERROR_DETECT_define
*/
#define SPI_DEV_ERROR_DETECT           (STD_OFF)

/**
* @brief Switches the Version Information API functionality ON or OFF.
* @details Switches the Spi_GetVersionInfo function ON or OFF.
*/
#define SPI_VERSION_INFO_API           (STD_OFF)

/**
* @brief Switches the Interruptible Sequences handling functionality ON or OFF. 
* @details This parameter depends on SPI_LEVEL_DELIVERED value. 
*        It is only used for SPI_LEVEL_DELIVERED configured to 1 or 2.
* @implements SPI_INTERRUPTIBLE_SEQ_ALLOWED_define
*/
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED  (STD_OFF)

/**
* @brief Switches the Spi_GetHWUnitStatus function ON or OFF.
* @details Switches the Spi_GetHWUnitStatus function ON or OFF.
* @implements SPI_HW_STATUS_API_define
*/
#define SPI_HW_STATUS_API          (STD_ON)

/**
* @brief Switches the Spi_Cancel function ON or OFF.
* @details Switches the Spi_Cancel function ON or OFF. (see chapter 8.3.13)
* @implements SPI_CANCEL_API_define
*/
#define SPI_CANCEL_API             (STD_ON)

/* Only Internal Buffers are allowed in Handler Driver.*/
#define USAGE0                          0x00u

/* Only External Buffers are allowed in Handler Driver.*/
#define USAGE1                          0x01u

/* Both Buffer types are allowd in Handler Driver. */
#define USAGE2                          0x02u

/**
* @brief Selects the SPI Handler Driver Channel Buffers usage allowed and delivered.
* @details Selects the SPI Handler Driver Channel Buffers usage allowed and delivered.
*        (see chapter 7.2.1)
* @implements SPI_CHANNEL_BUFFERS_ALLOWED_define
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED    (USAGE0)

/* The LEVEL 0 Simple Synchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL0                          0x00u

/* The LEVEL 1 Basic Asynchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL1                          0x01u

/* The LEVEL 2 Enhanced SPI Handler Driver functionalities are selected. */
#define LEVEL2                          0x02u

/**
* @brief Selects the SPI Handler Driver level of scalable functionality.
* @details Selects the SPI Handler Driver level of scalable functionality that 
* is available and delivered. (see chapter 7.1)
* @implements SPI_LEVEL_DELIVERED_define
*/
#define SPI_LEVEL_DELIVERED            (LEVEL2)

/**
* @brief Defines the maximum number of supported channels.
* @details Defines the maximum number of supported channels
*     for all the driver configurations.
*/

/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiChannel_CH0    ((Spi_ChannelType)0)
#define SPI_MAX_CHANNEL  (1u)

/**
* @brief Total number of Jobs configured.
* @details Defines the maximum number of supported jobs
*     for all the driver configurations.
*/
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiJob_SpiJob_0   ((Spi_JobType)0)
#define SPI_MAX_JOB     (1u)

/**
* @brief Total number of Sequences configured.
* @details Defines the maximum number of supported sequences
*     for all the driver configurations.
*/
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiSequence_SpiSequence_0   ((Spi_SequenceType)0)
#define SPI_MAX_SEQUENCE  (1u)


/**
* @brief Defines the Shifter and Timer offset
* @details Defines the Shifter and Timer offset
*/
#define Spi_FlexIO_Physical_Shifter_0  0u
#define Spi_FlexIO_Timer_0  0u
#define Spi_FlexIO_Physical_Shifter_1  1u
#define Spi_FlexIO_Timer_1  1u
#define Spi_FlexIO_Physical_Shifter_2  2u
#define Spi_FlexIO_Timer_2  2u
#define Spi_FlexIO_Physical_Shifter_3  3u
#define Spi_FlexIO_Timer_3  3u
#define Spi_FlexIO_NULL 0u

/**
* @brief Defines the peripherals used throughout the configuration(s).
* @details Defines the peripherals used throughout the configuration(s).
*/
#define CSIB0  ((uint8)0u)
#define SPI_MAX_HWUNIT   (1u)

/**
* @brief Physical HWUnits definition - as from resource manager.
* @details Physical HWUnits definition - as from resource manager.
*/

#define LPSPI_2_HWUNIT   (CSIB0)


/**
* @brief Physical HWUnits enabled/disabled
* @details Physical HWUnits enabled/disabled
*/
#define FLEXIOSPI_0_H        99u
#define FLEXIOSPI_1_H        99u


#define FLEXIOSPI_0_USED     (STD_OFF)

#define FLEXIOSPI_1_USED     (STD_OFF)

#define LPSPI_0_ENABLED  (STD_OFF)

#define LPSPI_1_ENABLED  (STD_OFF)

#define LPSPI_2_ENABLED  (STD_ON)

#define SPI_SLAVE_SUPPORT  ((STD_OFF))


#define LPSPI_2_OFFSET  2u

#define SPI_FIFO_SIZE_LPSPI   ((uint8)4u)

#define SPI_NUMBER_OF_UNITS   ((uint8)5u)
/**
* @brief Define HWUnit type
* @details Define HWUnit type
*/

#define LPSPI    0u

#define DSPI      1u

#define FLEXIOSPI    2u

/**
* @brief Defines the external devices the driver will use.
* @details Reference to the external device used by this job.
*/
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_SpiExternalDevice_0  ((Spi_ExternalDeviceType)0u)

/**
* @brief   Switches the Production Error Detection and Notification OFF
*
* @implements SPI_DISABLE_DEM_REPORT_ERROR_STATUS_define
* 
*/
#define SPI_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_ON ) /* STD_OFF: Enable Production Error Detection - STD_ON: Disable Production Error Detection */


/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Define values for Autosar configuration variants.
* @details Define values for Autosar configuration variants.
*/
#define SPI_VARIANT_PRECOMPILE  (0)
#define SPI_VARIANT_POSTBUILD   (1)
#define SPI_VARIANT_LINKTIME    (2)

/**
* @brief Defines the use of Pre-Compile(PC) support
* @details VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time" configu-ration are allowed 
*        in this variant.
*/
/* Pre-Compile(PC) Support. */
/**
* @implements SPI_CONFIG_VARIANT_define
*/

#define SPI_CONFIG_VARIANT      (SPI_VARIANT_PRECOMPILE)

/*
* @violates @ref Spi_Cfg_h_REF_3 Precautions shall be taken in order for
* defines not leading to unexpected behaviour when substitution is made.
*/

/**
* @brief Define precompile support.
* @details Define precompile support if VariantPreCompile or VariantLinkTime is selected and number of variant <=1.
*/
/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/

#define SPI_PRECOMPILE_SUPPORT      (STD_ON)

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
* @implements SPI_DMA_USED_define
*/
/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/

#define SPI_DMA_USED     (STD_OFF)

/**
* @brief Defines if transfers are made using FlexIO HW.
* @details Defines if transfers are made using FlexIO HW.
*/
/*
* @violates @ref Spi_Cfg_h_REF_1 A project should not contain unused macro declarations.
* Macros that are used in the code only in some configuration. 
*/
#define SPI_FLEXIO_USED     (STD_ON)

/**
* @brief Defines if Spi driver optimization for sequences having only one job is activated or not.
* @details Defines if Spi driver optimization for sequences having only one job is activated or not.
*        If activated, additional RAM memory is required for internal data caching.
*/
#define SPI_ENABLE_FLEXIO (STD_OFF)
/**
* @brief Defines if Spi driver optimization for sequences having only one job is activated or not.
* @details Defines if Spi driver optimization for sequences having only one job is activated or not.
*        If activated, additional RAM memory is required for internal data caching.
*/
#define SPI_OPTIMIZE_ONE_JOB_SEQUENCES (STD_OFF)

/**
* @brief Number of CPU clock cycles consumed by a wait loop during the wait for TX/RX transmission to complete one frame in Spi_SyncTransmit().
* @details This value is set to the minimum measure retrieved for GHS, DIAB and CW compilers,
*       with all optimizations activated.
*/
#define SPI_WAIT_LOOP_TICKS       23u

/**
* @brief Defines the "Number of Loops" timeout.
* @details Defines the "Number of Loops" timeout used by Spi_SyncTransmit and Spi_AsyncTransmit
*        function during the wait on TX/RX transmission to complete one frame.
*        One timeout unit means that no TX or RX was executed(the IF statements are returning FALSE).
*/

#define SPI_TIMEOUT_COUNTER       ((sint32)((50000u) / SPI_WAIT_LOOP_TICKS))

/**
* @brief Allow simultaneous calls to Spi_SyncTransmit() for different threads.
* @details Two concurrent calls to Spi_SyncTransmit() will be allowed only if the related sequences
*       do not share HW units.
*/
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT    (STD_OFF)

/*==================================================================================================
 *                                           Non AUTOSAR DEFINES
==================================================================================================*/
/**
* @brief If enabled, the asyncronous operation mode (POLLING or INTERRUPT)
* @details If enabled, the asyncronous operation mode (POLLING or INTERRUPT) can
*       be defined independently for each HWUnit using Spi_SetHWUnitAsyncMode().
* @implements SPI_HWUNIT_ASYNC_MODE_define
*/
#define SPI_HWUNIT_ASYNC_MODE  (STD_OFF)

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
* @implements SPI_DUAL_CLOCK_MODE_define
*/
#define SPI_DUAL_CLOCK_MODE  (STD_OFF)

/**
* @brief If enabled, allows to configure more than 256 sequences, jobs and channels.
*/
#define SPI_ALLOW_BIGSIZE_COLLECTIONS (STD_OFF)

/**
* @brief If enabled, SpiDataType is declared as uint8 instead of uint16.
*/
#define SPI_DATA_ACCESSED_8  1u
#define SPI_DATA_ACCESSED_16 2u
#define SPI_DATA_ACCESSED_32 4u

/**
* @brief The below define to use for configure the number of bits can transfer per clock.
*/
/* Normal transfer */
#define SPI_TRANSFER_WIDTH_1    0u
/* QSPI transfer */
#define SPI_TRANSFER_WIDTH_2    1u
#define SPI_TRANSFER_WIDTH_4    2u

/**
* @brief If enabled, SPI_MAIN_FUNCTION_PERIOD defines the cycle time of the function Spi_MainFunction_Handling in seconds
*/
/* Number of Shifter and Timer registers have supported*/

#define NUM_SHIFTR_TIMR_SUPPORT 4u

/* Define the channel will be used on SPI */


/* Define the PINs will be used on SPI*/
#define SPI_FLEXIO_0_PIN_NULL_USED
#define SPI_FLEXIO_0_PIN_NULL_USED
#define SPI_FLEXIO_0_PIN_NULL_USED
#define SPI_FLEXIO_0_PIN_NULL_USED
#define SPI_FLEXIO_0_PIN_NULL_USED
#define SPI_FLEXIO_0_PIN_NULL_USED

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_CFG_H*/

/** @} */
