/**
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
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
==================================================================================================*/

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
* @section Spi_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required.
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Reg_eSys_LPspi.h"
#include "Reg_eSys_FlexIOSPI.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_MODULE_ID_C                        83
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_VENDOR_ID_C                        43
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_AR_RELEASE_MINOR_VERSION_C         3
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_PBCFG_AR_RELEASE_REVISION_VERSION_C      1
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_SW_MAJOR_VERSION_C                 1
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_SW_MINOR_VERSION_C                 0
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_PBCFG_SW_PATCH_VERSION_C                 4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and SPI header file are of the same vendor */
#if (SPI_PBCFG_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_PBCFG_AR_RELEASE_MINOR_VERSION_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_PBCFG_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_PBCFG_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_PBCFG_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_PBCFG_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Reg_eSys_LPspi.h file are of the same vendor */
#if (SPI_PBCFG_VENDOR_ID_C != REG_ESYS_LPSPI_VENDOR_ID_REGFLEX)
    #error "Spi_PBCfg.c and Reg_eSys_LPspi.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Autosar version */
#if ((SPI_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_LPSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_LPSPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPSPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Software version */
#if ((SPI_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_LPSPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_LPSPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_LPSPI_SW_PATCH_VERSION_REGFLEX))
    #error "Software Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif

/* Check if current file and Reg_eSys_FLEXIOSPI.h file are of the same vendor */
#if (SPI_PBCFG_VENDOR_ID_C != REG_ESYS_FLEXIOSPI_VENDOR_ID_REGFLEX)
    #error "Spi_PBCfg.c and Reg_eSys_FLEXIOSPI.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLEXIOSPI.h file are of the same Autosar version */
#if ((SPI_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FLEXIOSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FLEXIOSPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FLEXIOSPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Reg_eSys_FLEXIOSPI.h are different"
#endif
/* Check if current file and Reg_eSys_FLEXIOSPI.h file are of the same Software version */
#if ((SPI_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_FLEXIOSPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_FLEXIOSPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_FLEXIOSPI_SW_PATCH_VERSION_REGFLEX))
    #error "Software Version Numbers of Spi_PBCfg.c and Reg_eSys_FLEXIOSPI.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h file are of the same Autosar version */
    #if ((SPI_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_PBCFG_AR_RELEASE_MINOR_VERSION_C    != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
    #endif
    #endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
#endif  


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Notification(void); /* End Notification for Job 'SpiJob_0' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Notification(void); /* End Notification for Job 'SpiJob_1' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Notification(void); /* End Notification for Job 'SpiJob_2' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Notification(void); /* End Notification for Job 'SpiJob_3' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Seq_End(void); /* End Notification for Sequence 'SpiSequence_0' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Seq_End(void); /* End Notification for Sequence 'SpiSequence_1' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Seq_End(void); /* End Notification for Sequence 'SpiSequence_2' */
/*
* @violates @ref Spi_PBcfg_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void SPI_Seq_End(void); /* End Notification for Sequence 'SpiSequence_3' */



#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */    
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/*  Buffers Descriptors for EB Channels (if any) */
/* Allocate Buffers for IB Channels (if any) */
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBCH0[1];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBCH0[1];
/* Allocate Buffers for IB Channels (if any) */
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBCH1[4];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBCH1[4];
/* Allocate Buffers for IB Channels (if any) */
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBCH2[500];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBCH2[500];
/* Allocate Buffers for IB Channels (if any) */
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PBCH3[2];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PBCH3[2];


#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))  
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
    * @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
    * signifiance and case sensitivity are supported for external identifiers.
    */
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/*  Buffers Descriptors for IB Channels (if any) */
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBCH0 =
{
    BufferTX_PBCH0,
    BufferRX_PBCH0
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBCH1 =
{
    BufferTX_PBCH1,
    BufferRX_PBCH1
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBCH2 =
{
    BufferTX_PBCH2,
    BufferRX_PBCH2
};
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PBCH3 =
{
    BufferTX_PBCH3,
    BufferRX_PBCH3
};


    



    
    
        



    
        

                                    
/* LPspiDeviceAttributesConfig_PB Device Attribute Configuration of Spi*/
static VAR(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR) LPspiDeviceAttributesConfig_PB[1] =
{
                
        {
                                                                                /* SpiExternalDevice_0 */
            
                
            (uint32)(LPSPI_TCR_CPOL_HIGH_U32 | /* Clock Polarity (Idle State) */
                            LPSPI_TCR_CPHA_LEADING_U32 | /* Clock Phase */  
            LPSPI_TCR_PRESCALE_1_U32 /* Baudrate: Should=6500000.0, Is=6666666, Error=2.56% */
          |  LPSPI_TCR_BYSW_DIS_U32 
          | 
                                                (uint32)(LPSPI_TCR_PCS3_EN_U32 | /* Chip Select Pin Via Peripheral Engine*/
                                    LPSPI_TCR_CONT_DIS_U32)/* Disable continuous chip select */
                                                            
) & LPSPI_TCR_RWBITS_MASK_U32,
            ( ((uint32)(39) << 24u) | /* TimeClk2Cs: Should=500ns, Is=500, Error=0.0% */
            ((uint32)(79) << 16u) | /* TimeCs2Clk: Should=1000ns, Is=1000, Error=0.0% */
            ((uint32)(79) << 8u) | /* TimeCs2Cs: Should=1000ns, Is=1000, Error=0.0% */
            ((uint32)(10))
            ),

/* CFG1 register configuration */
        (uint32)0u  /* Chip select polarity */
     | LPSPI_CFGR1_PINCFG_SIN_INPUT_SOUT_OUTPUT_U32 | LPSPI_CFGR1_MATCFG_DIS_U32 | LPSPI_CFGR1_MASTER_EN_U32


        }
                

};

        
    


#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define   SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include directives should only be preceded by other preprocessor
*        directives or comments
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent
*        the contents of a header file being included more than once.
*/
 #include "Spi_MemMap.h"


    

/* DeviceAttributesConfig_PB Device Attribute Configuration of Spi*/
static P2CONST(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) LPspiDeviceAttributesConfigArray_PB[1] =
{
                &LPspiDeviceAttributesConfig_PB[0]        
};

    

/* DeviceAttributesConfig_PB Device Attribute Configuration of Spi*/
static P2CONST(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) FlexIODeviceAttributesConfigArray_PB[1] =
{
                NULL_PTR
};





/* DSpiDeviceAttributesConfig_PB Device Attribute Configuration of Spi*/
static VAR(Spi_Ipw_DeviceAttributesConfigType, SPI_VAR) SpiExternalDeviceAttrsPB[1] =
{
        
        
        {
        &LPspiDeviceAttributesConfigArray_PB[SPI_SpiExternalDevice_0],
        NULL_PTR
        }
};
 
 #define   SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
 /*
* @violates @ref Spi_PBcfg_c_REF_1 #include directives should only be preceded by other preprocessor
*        directives or comments
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent
*        the contents of a header file being included more than once.
*/
 #include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"



/* SpiChannelConfig_PB Channel Configuration of Spi*/
static CONST(Spi_ChannelConfigType, SPI_CONST) SpiChannelConfig_PB[4] =
{
    {
        /* CH0*/
        IB,
        (uint32)0x55u,

        1U,
        &Buffer_PBCH0,
        &Spi_aSpiChannelState[0]
    },

    {
        /* CH1*/
        IB,
        (uint32)0x55u,

        4U,
        &Buffer_PBCH1,
        &Spi_aSpiChannelState[1]
    },

    {
        /* CH2*/
        IB,
        (uint32)0x55u,

        500U,
        &Buffer_PBCH2,
        &Spi_aSpiChannelState[2]
    },

    {
        /* CH3*/
        IB,
        (uint32)0x55u,

        2U,
        &Buffer_PBCH3,
        &Spi_aSpiChannelState[3]
    }


};



/* Channel to Job Assignment */

static CONST(Spi_ChannelType, SPI_CONST) SpiJob_0_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_CH0};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_1_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_CH1};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_2_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_CH2};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_3_ChannelAssignment_PB[1] = {SpiConf_SpiChannel_CH3};



/* SpiJobConfig_PB Job Configuration of Spi*/
static CONST(Spi_JobConfigType, SPI_CONST) SpiJobConfig_PB[4] =
{
    {


        /* SpiJob_0 */
        (Spi_ChannelType)1u,
        SpiJob_0_ChannelAssignment_PB, /* List of Channels */
        &SPI_Notification, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_1_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_SpiExternalDevice_0, /* External Device */
        &SpiExternalDeviceAttrsPB[SPI_SpiExternalDevice_0]
        
        
    },

    {


        /* SpiJob_1 */
        (Spi_ChannelType)1u,
        SpiJob_1_ChannelAssignment_PB, /* List of Channels */
        &SPI_Notification, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[1], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_1_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_SpiExternalDevice_0, /* External Device */
        &SpiExternalDeviceAttrsPB[SPI_SpiExternalDevice_0]
        
        
    },

    {


        /* SpiJob_2 */
        (Spi_ChannelType)1u,
        SpiJob_2_ChannelAssignment_PB, /* List of Channels */
        &SPI_Notification, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[2], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_1_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_SpiExternalDevice_0, /* External Device */
        &SpiExternalDeviceAttrsPB[SPI_SpiExternalDevice_0]
        
        
    },

    {


        /* SpiJob_3 */
        (Spi_ChannelType)1u,
        SpiJob_3_ChannelAssignment_PB, /* List of Channels */
        &SPI_Notification, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &Spi_aSpiJobState[3], /* JobState instance */
        CSIB0, /* HWUnit index */
        LPSPI_1_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
        
            SPI_SpiExternalDevice_0, /* External Device */
        &SpiExternalDeviceAttrsPB[SPI_SpiExternalDevice_0]
        
        
    }


};



/* Job to Sequence Assignment */
static CONST(Spi_JobType, SPI_CONST) SpiSequence_0_JobAssignment_PB[1] = {SpiConf_SpiJob_SpiJob_0};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_1_JobAssignment_PB[1] = {SpiConf_SpiJob_SpiJob_1};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_2_JobAssignment_PB[1] = {SpiConf_SpiJob_SpiJob_2};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_3_JobAssignment_PB[1] = {SpiConf_SpiJob_SpiJob_3};



/* SpiSequenceConfig_PB Sequence Configuration of Spi*/
static CONST(Spi_SequenceConfigType, SPI_CONST) SpiSequenceConfig_PB[4] =
{
    {  /* SpiSequence_0 */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        SpiSequence_0_JobAssignment_PB, /* List of Jobs */
        &SPI_Seq_End, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* SpiSequence_1 */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        SpiSequence_1_JobAssignment_PB, /* List of Jobs */
        &SPI_Seq_End, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* SpiSequence_2 */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        SpiSequence_2_JobAssignment_PB, /* List of Jobs */
        &SPI_Seq_End, /* End Notification */
                (uint8)FALSE /* Interruptible */
    },

    {  /* SpiSequence_3 */
        LPSPI, /* HW type of sequences */ 
        (Spi_JobType)1u,
        SpiSequence_3_JobAssignment_PB, /* List of Jobs */
        &SPI_Seq_End, /* End Notification */
                (uint8)FALSE /* Interruptible */
    }


};







    
    
        





    
/* LPspiChannelAttributesConfig_PB Channel Attribute Configuration of Spi*/
/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Spi_Ipw_LPspiChannelAttributesConfigType, SPI_CONST) LPspiChannelAttributesConfig_PB[4] =
{
{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_MSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(7))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),
    /* u8DataWidth */
    SPI_DATA_ACCESSED_8
},

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_MSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(7))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),
    /* u8DataWidth */
    SPI_DATA_ACCESSED_8
},

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_MSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(7))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),
    /* u8DataWidth */
    SPI_DATA_ACCESSED_8
},

{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_MSB_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)(7))),
    /* FCR register attribution */
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),
    /* u8DataWidth */
    SPI_DATA_ACCESSED_8
}


};














    
    
        



/* SpiAttributesConfig_PB Attribute Configuration of MODULE-CONFIGURATION */
static CONST(Spi_Ipw_AttributesConfigType, SPI_CONST) SpiAttributesConfig_PB = {
    LPspiChannelAttributesConfig_PB,
    NULL_PTR,
    LPspiDeviceAttributesConfigArray_PB,
    FlexIODeviceAttributesConfigArray_PB
};



/* Array of LPspi Unit configurations */
static CONST(Spi_HWUnitConfigType, SPI_CONST) HWUnitConfig_PB[SPI_MAX_HWUNIT] =
{
  {
    LPSPI_1_OFFSET,
    LPSPI,
    (uint8)0u,
    SPI_MASTER,
    SPI_PHYUNIT_SYNC_U32
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    ,(uint16)FALSE
    ,0u
    ,0u
    ,0u
#endif
#endif
#ifdef SPI_FLEXIO_USED
#if (SPI_FLEXIO_USED == STD_ON)
    ,0u
    ,0u
    ,0u
    ,0u
#endif /*SPI_FLEXIO_USED == STD_ON*/
#endif /*SPI_FLEXIO_USED*/
  }
};


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/




/* @violates @ref Spi_PBcfg_c_REF_4 MISRA 2004 Required Rule 8.10, external linkage ... */
/* MODULE-CONFIGURATION Configuration */
CONST(Spi_ConfigType, SPI_CONST) Spi_PBCfgVariantPredefined =
{
    1u,
    3u,
    3u,
    3u,
    SpiChannelConfig_PB,
    SpiJobConfig_PB,
    SpiSequenceConfig_PB,
    &SpiAttributesConfig_PB,
    HWUnitConfig_PB
    /**
    * @brief   DEM error parameters
    */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    ,{ (uint32)STD_OFF, (uint32)0U} /* SPI_E_HARDWARE_ERROR parameters*/
    ,{ (uint32)STD_OFF, (uint32)0U} /* SPI_E_TIMEOUT_ERROR parameters*/
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
};


/*
* @violates @ref Spi_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_PBcfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_PBcfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

