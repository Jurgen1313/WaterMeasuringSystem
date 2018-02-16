/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_UART_RS_485_H)
#define CY_SCB_PVT_UART_RS_485_H

#include "UART_RS_485.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_RS_485_SetI2CExtClkInterruptMode(interruptMask) UART_RS_485_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_RS_485_ClearI2CExtClkInterruptSource(interruptMask) UART_RS_485_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_RS_485_GetI2CExtClkInterruptSource()                (UART_RS_485_INTR_I2C_EC_REG)
#define UART_RS_485_GetI2CExtClkInterruptMode()                  (UART_RS_485_INTR_I2C_EC_MASK_REG)
#define UART_RS_485_GetI2CExtClkInterruptSourceMasked()          (UART_RS_485_INTR_I2C_EC_MASKED_REG)

#if (!UART_RS_485_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define UART_RS_485_SetSpiExtClkInterruptMode(interruptMask) \
                                                                UART_RS_485_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define UART_RS_485_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                UART_RS_485_CLEAR_INTR_SPI_EC(interruptMask)
    #define UART_RS_485_GetExtSpiClkInterruptSource()                 (UART_RS_485_INTR_SPI_EC_REG)
    #define UART_RS_485_GetExtSpiClkInterruptMode()                   (UART_RS_485_INTR_SPI_EC_MASK_REG)
    #define UART_RS_485_GetExtSpiClkInterruptSourceMasked()           (UART_RS_485_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_RS_485_CY_SCBIP_V1) */

#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_RS_485_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (UART_RS_485_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UART_RS_485_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_RS_485_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_RS_485_CUSTOM_INTR_HANDLER) */
#endif /* (UART_RS_485_SCB_IRQ_INTERNAL) */

extern UART_RS_485_BACKUP_STRUCT UART_RS_485_backup;

#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 UART_RS_485_scbMode;
    extern uint8 UART_RS_485_scbEnableWake;
    extern uint8 UART_RS_485_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 UART_RS_485_mode;
    extern uint8 UART_RS_485_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * UART_RS_485_rxBuffer;
    extern uint8   UART_RS_485_rxDataBits;
    extern uint32  UART_RS_485_rxBufferSize;

    extern volatile uint8 * UART_RS_485_txBuffer;
    extern uint8   UART_RS_485_txDataBits;
    extern uint32  UART_RS_485_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 UART_RS_485_numberOfAddr;
    extern uint8 UART_RS_485_subAddrSize;
#endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (UART_RS_485_SCB_MODE_I2C_CONST_CFG || \
        UART_RS_485_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 UART_RS_485_IntrTxMask;
#endif /* (! (UART_RS_485_SCB_MODE_I2C_CONST_CFG || \
              UART_RS_485_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define UART_RS_485_SCB_MODE_I2C_RUNTM_CFG     (UART_RS_485_SCB_MODE_I2C      == UART_RS_485_scbMode)
    #define UART_RS_485_SCB_MODE_SPI_RUNTM_CFG     (UART_RS_485_SCB_MODE_SPI      == UART_RS_485_scbMode)
    #define UART_RS_485_SCB_MODE_UART_RUNTM_CFG    (UART_RS_485_SCB_MODE_UART     == UART_RS_485_scbMode)
    #define UART_RS_485_SCB_MODE_EZI2C_RUNTM_CFG   (UART_RS_485_SCB_MODE_EZI2C    == UART_RS_485_scbMode)
    #define UART_RS_485_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_RS_485_SCB_MODE_UNCONFIG == UART_RS_485_scbMode)

    /* Defines wakeup enable */
    #define UART_RS_485_SCB_WAKE_ENABLE_CHECK       (0u != UART_RS_485_scbEnableWake)
#endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!UART_RS_485_CY_SCBIP_V1)
    #define UART_RS_485_SCB_PINS_NUMBER    (7u)
#else
    #define UART_RS_485_SCB_PINS_NUMBER    (2u)
#endif /* (!UART_RS_485_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_UART_RS_485_H) */


/* [] END OF FILE */
