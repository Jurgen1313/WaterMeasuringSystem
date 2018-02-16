/***************************************************************************//**
* \file UART_RS_485_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_UART_RS_485_H)
#define CY_SCB_BOOT_UART_RS_485_H

#include "UART_RS_485_PVT.h"

#if (UART_RS_485_SCB_MODE_I2C_INC)
    #include "UART_RS_485_I2C.h"
#endif /* (UART_RS_485_SCB_MODE_I2C_INC) */

#if (UART_RS_485_SCB_MODE_EZI2C_INC)
    #include "UART_RS_485_EZI2C.h"
#endif /* (UART_RS_485_SCB_MODE_EZI2C_INC) */

#if (UART_RS_485_SCB_MODE_SPI_INC || UART_RS_485_SCB_MODE_UART_INC)
    #include "UART_RS_485_SPI_UART.h"
#endif /* (UART_RS_485_SCB_MODE_SPI_INC || UART_RS_485_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define UART_RS_485_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_RS_485) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (UART_RS_485_SCB_MODE_I2C_INC)
    #define UART_RS_485_I2C_BTLDR_COMM_ENABLED     (UART_RS_485_BTLDR_COMM_ENABLED && \
                                                            (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             UART_RS_485_I2C_SLAVE_CONST))
#else
     #define UART_RS_485_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (UART_RS_485_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (UART_RS_485_SCB_MODE_EZI2C_INC)
    #define UART_RS_485_EZI2C_BTLDR_COMM_ENABLED   (UART_RS_485_BTLDR_COMM_ENABLED && \
                                                         UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define UART_RS_485_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (UART_RS_485_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (UART_RS_485_SCB_MODE_SPI_INC)
    #define UART_RS_485_SPI_BTLDR_COMM_ENABLED     (UART_RS_485_BTLDR_COMM_ENABLED && \
                                                            (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             UART_RS_485_SPI_SLAVE_CONST))
#else
        #define UART_RS_485_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (UART_RS_485_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (UART_RS_485_SCB_MODE_UART_INC)
       #define UART_RS_485_UART_BTLDR_COMM_ENABLED    (UART_RS_485_BTLDR_COMM_ENABLED && \
                                                            (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (UART_RS_485_UART_RX_DIRECTION && \
                                                              UART_RS_485_UART_TX_DIRECTION)))
#else
     #define UART_RS_485_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (UART_RS_485_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define UART_RS_485_BTLDR_COMM_MODE_ENABLED    (UART_RS_485_I2C_BTLDR_COMM_ENABLED   || \
                                                     UART_RS_485_SPI_BTLDR_COMM_ENABLED   || \
                                                     UART_RS_485_EZI2C_BTLDR_COMM_ENABLED || \
                                                     UART_RS_485_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void UART_RS_485_I2CCyBtldrCommStart(void);
    void UART_RS_485_I2CCyBtldrCommStop (void);
    void UART_RS_485_I2CCyBtldrCommReset(void);
    cystatus UART_RS_485_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_RS_485_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (UART_RS_485_SCB_MODE_I2C_CONST_CFG)
        #define UART_RS_485_CyBtldrCommStart   UART_RS_485_I2CCyBtldrCommStart
        #define UART_RS_485_CyBtldrCommStop    UART_RS_485_I2CCyBtldrCommStop
        #define UART_RS_485_CyBtldrCommReset   UART_RS_485_I2CCyBtldrCommReset
        #define UART_RS_485_CyBtldrCommRead    UART_RS_485_I2CCyBtldrCommRead
        #define UART_RS_485_CyBtldrCommWrite   UART_RS_485_I2CCyBtldrCommWrite
    #endif /* (UART_RS_485_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void UART_RS_485_EzI2CCyBtldrCommStart(void);
    void UART_RS_485_EzI2CCyBtldrCommStop (void);
    void UART_RS_485_EzI2CCyBtldrCommReset(void);
    cystatus UART_RS_485_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_RS_485_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (UART_RS_485_SCB_MODE_EZI2C_CONST_CFG)
        #define UART_RS_485_CyBtldrCommStart   UART_RS_485_EzI2CCyBtldrCommStart
        #define UART_RS_485_CyBtldrCommStop    UART_RS_485_EzI2CCyBtldrCommStop
        #define UART_RS_485_CyBtldrCommReset   UART_RS_485_EzI2CCyBtldrCommReset
        #define UART_RS_485_CyBtldrCommRead    UART_RS_485_EzI2CCyBtldrCommRead
        #define UART_RS_485_CyBtldrCommWrite   UART_RS_485_EzI2CCyBtldrCommWrite
    #endif /* (UART_RS_485_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void UART_RS_485_SpiCyBtldrCommStart(void);
    void UART_RS_485_SpiCyBtldrCommStop (void);
    void UART_RS_485_SpiCyBtldrCommReset(void);
    cystatus UART_RS_485_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_RS_485_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (UART_RS_485_SCB_MODE_SPI_CONST_CFG)
        #define UART_RS_485_CyBtldrCommStart   UART_RS_485_SpiCyBtldrCommStart
        #define UART_RS_485_CyBtldrCommStop    UART_RS_485_SpiCyBtldrCommStop
        #define UART_RS_485_CyBtldrCommReset   UART_RS_485_SpiCyBtldrCommReset
        #define UART_RS_485_CyBtldrCommRead    UART_RS_485_SpiCyBtldrCommRead
        #define UART_RS_485_CyBtldrCommWrite   UART_RS_485_SpiCyBtldrCommWrite
    #endif /* (UART_RS_485_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void UART_RS_485_UartCyBtldrCommStart(void);
    void UART_RS_485_UartCyBtldrCommStop (void);
    void UART_RS_485_UartCyBtldrCommReset(void);
    cystatus UART_RS_485_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_RS_485_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (UART_RS_485_SCB_MODE_UART_CONST_CFG)
        #define UART_RS_485_CyBtldrCommStart   UART_RS_485_UartCyBtldrCommStart
        #define UART_RS_485_CyBtldrCommStop    UART_RS_485_UartCyBtldrCommStop
        #define UART_RS_485_CyBtldrCommReset   UART_RS_485_UartCyBtldrCommReset
        #define UART_RS_485_CyBtldrCommRead    UART_RS_485_UartCyBtldrCommRead
        #define UART_RS_485_CyBtldrCommWrite   UART_RS_485_UartCyBtldrCommWrite
    #endif /* (UART_RS_485_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_BTLDR_COMM_ENABLED)
    #if (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void UART_RS_485_CyBtldrCommStart(void);
        void UART_RS_485_CyBtldrCommStop (void);
        void UART_RS_485_CyBtldrCommReset(void);
        cystatus UART_RS_485_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus UART_RS_485_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (UART_RS_485_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_RS_485)
        #define CyBtldrCommStart    UART_RS_485_CyBtldrCommStart
        #define CyBtldrCommStop     UART_RS_485_CyBtldrCommStop
        #define CyBtldrCommReset    UART_RS_485_CyBtldrCommReset
        #define CyBtldrCommWrite    UART_RS_485_CyBtldrCommWrite
        #define CyBtldrCommRead     UART_RS_485_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_RS_485) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_RS_485_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define UART_RS_485_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define UART_RS_485_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define UART_RS_485_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define UART_RS_485_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef UART_RS_485_SPI_BYTE_TO_BYTE
    #define UART_RS_485_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef UART_RS_485_UART_BYTE_TO_BYTE
    #define UART_RS_485_UART_BYTE_TO_BYTE  (380u)
#endif /* UART_RS_485_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_UART_RS_485_H) */


/* [] END OF FILE */
