/***************************************************************************//**
* \file UART_RS_485_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_UART_RS_485_H)
#define CY_SCB_SPI_UART_PVT_UART_RS_485_H

#include "UART_RS_485_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (UART_RS_485_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UART_RS_485_rxBufferHead;
    extern volatile uint32  UART_RS_485_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   UART_RS_485_rxBufferOverflow;
    /** @} globals */
#endif /* (UART_RS_485_INTERNAL_RX_SW_BUFFER_CONST) */

#if (UART_RS_485_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UART_RS_485_txBufferHead;
    extern volatile uint32  UART_RS_485_txBufferTail;
#endif /* (UART_RS_485_INTERNAL_TX_SW_BUFFER_CONST) */

#if (UART_RS_485_INTERNAL_RX_SW_BUFFER)
    extern volatile uint16 UART_RS_485_rxBufferInternal[UART_RS_485_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UART_RS_485_INTERNAL_RX_SW_BUFFER) */

#if (UART_RS_485_INTERNAL_TX_SW_BUFFER)
    extern volatile uint16 UART_RS_485_txBufferInternal[UART_RS_485_TX_BUFFER_SIZE];
#endif /* (UART_RS_485_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void UART_RS_485_SpiPostEnable(void);
void UART_RS_485_SpiStop(void);

#if (UART_RS_485_SCB_MODE_SPI_CONST_CFG)
    void UART_RS_485_SpiInit(void);
#endif /* (UART_RS_485_SCB_MODE_SPI_CONST_CFG) */

#if (UART_RS_485_SPI_WAKE_ENABLE_CONST)
    void UART_RS_485_SpiSaveConfig(void);
    void UART_RS_485_SpiRestoreConfig(void);
#endif /* (UART_RS_485_SPI_WAKE_ENABLE_CONST) */

void UART_RS_485_UartPostEnable(void);
void UART_RS_485_UartStop(void);

#if (UART_RS_485_SCB_MODE_UART_CONST_CFG)
    void UART_RS_485_UartInit(void);
#endif /* (UART_RS_485_SCB_MODE_UART_CONST_CFG) */

#if (UART_RS_485_UART_WAKE_ENABLE_CONST)
    void UART_RS_485_UartSaveConfig(void);
    void UART_RS_485_UartRestoreConfig(void);
#endif /* (UART_RS_485_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in UART_RS_485_SetPins() */
#define UART_RS_485_UART_RX_PIN_ENABLE    (UART_RS_485_UART_RX)
#define UART_RS_485_UART_TX_PIN_ENABLE    (UART_RS_485_UART_TX)

/* UART RTS and CTS position to be used in  UART_RS_485_SetPins() */
#define UART_RS_485_UART_RTS_PIN_ENABLE    (0x10u)
#define UART_RS_485_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define UART_RS_485_SpiUartEnableIntRx(intSourceMask)  UART_RS_485_SetRxInterruptMode(intSourceMask)
#define UART_RS_485_SpiUartEnableIntTx(intSourceMask)  UART_RS_485_SetTxInterruptMode(intSourceMask)
uint32  UART_RS_485_SpiUartDisableIntRx(void);
uint32  UART_RS_485_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_UART_RS_485_H) */


/* [] END OF FILE */
