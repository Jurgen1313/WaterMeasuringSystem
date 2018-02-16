/***************************************************************************//**
* \file UART_RS_485_PM.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_RS_485.h"
#include "UART_RS_485_PVT.h"

#if(UART_RS_485_SCB_MODE_I2C_INC)
    #include "UART_RS_485_I2C_PVT.h"
#endif /* (UART_RS_485_SCB_MODE_I2C_INC) */

#if(UART_RS_485_SCB_MODE_EZI2C_INC)
    #include "UART_RS_485_EZI2C_PVT.h"
#endif /* (UART_RS_485_SCB_MODE_EZI2C_INC) */

#if(UART_RS_485_SCB_MODE_SPI_INC || UART_RS_485_SCB_MODE_UART_INC)
    #include "UART_RS_485_SPI_UART_PVT.h"
#endif /* (UART_RS_485_SCB_MODE_SPI_INC || UART_RS_485_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG || \
   (UART_RS_485_SCB_MODE_I2C_CONST_CFG   && (!UART_RS_485_I2C_WAKE_ENABLE_CONST))   || \
   (UART_RS_485_SCB_MODE_EZI2C_CONST_CFG && (!UART_RS_485_EZI2C_WAKE_ENABLE_CONST)) || \
   (UART_RS_485_SCB_MODE_SPI_CONST_CFG   && (!UART_RS_485_SPI_WAKE_ENABLE_CONST))   || \
   (UART_RS_485_SCB_MODE_UART_CONST_CFG  && (!UART_RS_485_UART_WAKE_ENABLE_CONST)))

    UART_RS_485_BACKUP_STRUCT UART_RS_485_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: UART_RS_485_Sleep
****************************************************************************//**
*
*  Prepares the UART_RS_485 component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the UART_RS_485_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void UART_RS_485_Sleep(void)
{
#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_RS_485_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_RS_485_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_RS_485_I2CSaveConfig();
        }
        else if(UART_RS_485_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_RS_485_EzI2CSaveConfig();
        }
    #if(!UART_RS_485_CY_SCBIP_V1)
        else if(UART_RS_485_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_RS_485_SpiSaveConfig();
        }
        else if(UART_RS_485_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_RS_485_UartSaveConfig();
        }
    #endif /* (!UART_RS_485_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        UART_RS_485_backup.enableState = (uint8) UART_RS_485_GET_CTRL_ENABLED;

        if(0u != UART_RS_485_backup.enableState)
        {
            UART_RS_485_Stop();
        }
    }

#else

    #if (UART_RS_485_SCB_MODE_I2C_CONST_CFG && UART_RS_485_I2C_WAKE_ENABLE_CONST)
        UART_RS_485_I2CSaveConfig();

    #elif (UART_RS_485_SCB_MODE_EZI2C_CONST_CFG && UART_RS_485_EZI2C_WAKE_ENABLE_CONST)
        UART_RS_485_EzI2CSaveConfig();

    #elif (UART_RS_485_SCB_MODE_SPI_CONST_CFG && UART_RS_485_SPI_WAKE_ENABLE_CONST)
        UART_RS_485_SpiSaveConfig();

    #elif (UART_RS_485_SCB_MODE_UART_CONST_CFG && UART_RS_485_UART_WAKE_ENABLE_CONST)
        UART_RS_485_UartSaveConfig();

    #else

        UART_RS_485_backup.enableState = (uint8) UART_RS_485_GET_CTRL_ENABLED;

        if(0u != UART_RS_485_backup.enableState)
        {
            UART_RS_485_Stop();
        }

    #endif /* defined (UART_RS_485_SCB_MODE_I2C_CONST_CFG) && (UART_RS_485_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_RS_485_Wakeup
****************************************************************************//**
*
*  Prepares the UART_RS_485 component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the UART_RS_485_Wakeup() function without first calling the 
*   UART_RS_485_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void UART_RS_485_Wakeup(void)
{
#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_RS_485_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_RS_485_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_RS_485_I2CRestoreConfig();
        }
        else if(UART_RS_485_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_RS_485_EzI2CRestoreConfig();
        }
    #if(!UART_RS_485_CY_SCBIP_V1)
        else if(UART_RS_485_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_RS_485_SpiRestoreConfig();
        }
        else if(UART_RS_485_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_RS_485_UartRestoreConfig();
        }
    #endif /* (!UART_RS_485_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != UART_RS_485_backup.enableState)
        {
            UART_RS_485_Enable();
        }
    }

#else

    #if (UART_RS_485_SCB_MODE_I2C_CONST_CFG  && UART_RS_485_I2C_WAKE_ENABLE_CONST)
        UART_RS_485_I2CRestoreConfig();

    #elif (UART_RS_485_SCB_MODE_EZI2C_CONST_CFG && UART_RS_485_EZI2C_WAKE_ENABLE_CONST)
        UART_RS_485_EzI2CRestoreConfig();

    #elif (UART_RS_485_SCB_MODE_SPI_CONST_CFG && UART_RS_485_SPI_WAKE_ENABLE_CONST)
        UART_RS_485_SpiRestoreConfig();

    #elif (UART_RS_485_SCB_MODE_UART_CONST_CFG && UART_RS_485_UART_WAKE_ENABLE_CONST)
        UART_RS_485_UartRestoreConfig();

    #else

        if(0u != UART_RS_485_backup.enableState)
        {
            UART_RS_485_Enable();
        }

    #endif /* (UART_RS_485_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
