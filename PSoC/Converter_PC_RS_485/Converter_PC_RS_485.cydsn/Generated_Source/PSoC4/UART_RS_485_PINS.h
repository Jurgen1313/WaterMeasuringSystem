/***************************************************************************//**
* \file UART_RS_485_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_UART_RS_485_H)
#define CY_SCB_PINS_UART_RS_485_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define UART_RS_485_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define UART_RS_485_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define UART_RS_485_REMOVE_TX_SDA_MISO_PIN      (1u)
#define UART_RS_485_REMOVE_SCLK_PIN      (1u)
#define UART_RS_485_REMOVE_SS0_PIN      (1u)
#define UART_RS_485_REMOVE_SS1_PIN                 (1u)
#define UART_RS_485_REMOVE_SS2_PIN                 (1u)
#define UART_RS_485_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define UART_RS_485_REMOVE_I2C_PINS                (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_PINS         (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define UART_RS_485_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define UART_RS_485_REMOVE_SPI_SLAVE_PINS          (1u)
#define UART_RS_485_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define UART_RS_485_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define UART_RS_485_REMOVE_UART_TX_PIN             (0u)
#define UART_RS_485_REMOVE_UART_RX_TX_PIN          (1u)
#define UART_RS_485_REMOVE_UART_RX_PIN             (0u)
#define UART_RS_485_REMOVE_UART_RX_WAKE_PIN        (1u)
#define UART_RS_485_REMOVE_UART_RTS_PIN            (1u)
#define UART_RS_485_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define UART_RS_485_RX_WAKE_SCL_MOSI_PIN (0u == UART_RS_485_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define UART_RS_485_RX_SCL_MOSI_PIN     (0u == UART_RS_485_REMOVE_RX_SCL_MOSI_PIN)
#define UART_RS_485_TX_SDA_MISO_PIN     (0u == UART_RS_485_REMOVE_TX_SDA_MISO_PIN)
#define UART_RS_485_SCLK_PIN     (0u == UART_RS_485_REMOVE_SCLK_PIN)
#define UART_RS_485_SS0_PIN     (0u == UART_RS_485_REMOVE_SS0_PIN)
#define UART_RS_485_SS1_PIN                (0u == UART_RS_485_REMOVE_SS1_PIN)
#define UART_RS_485_SS2_PIN                (0u == UART_RS_485_REMOVE_SS2_PIN)
#define UART_RS_485_SS3_PIN                (0u == UART_RS_485_REMOVE_SS3_PIN)

/* Mode defined pins */
#define UART_RS_485_I2C_PINS               (0u == UART_RS_485_REMOVE_I2C_PINS)
#define UART_RS_485_SPI_MASTER_PINS        (0u == UART_RS_485_REMOVE_SPI_MASTER_PINS)
#define UART_RS_485_SPI_MASTER_SCLK_PIN    (0u == UART_RS_485_REMOVE_SPI_MASTER_SCLK_PIN)
#define UART_RS_485_SPI_MASTER_MOSI_PIN    (0u == UART_RS_485_REMOVE_SPI_MASTER_MOSI_PIN)
#define UART_RS_485_SPI_MASTER_MISO_PIN    (0u == UART_RS_485_REMOVE_SPI_MASTER_MISO_PIN)
#define UART_RS_485_SPI_MASTER_SS0_PIN     (0u == UART_RS_485_REMOVE_SPI_MASTER_SS0_PIN)
#define UART_RS_485_SPI_MASTER_SS1_PIN     (0u == UART_RS_485_REMOVE_SPI_MASTER_SS1_PIN)
#define UART_RS_485_SPI_MASTER_SS2_PIN     (0u == UART_RS_485_REMOVE_SPI_MASTER_SS2_PIN)
#define UART_RS_485_SPI_MASTER_SS3_PIN     (0u == UART_RS_485_REMOVE_SPI_MASTER_SS3_PIN)
#define UART_RS_485_SPI_SLAVE_PINS         (0u == UART_RS_485_REMOVE_SPI_SLAVE_PINS)
#define UART_RS_485_SPI_SLAVE_MOSI_PIN     (0u == UART_RS_485_REMOVE_SPI_SLAVE_MOSI_PIN)
#define UART_RS_485_SPI_SLAVE_MISO_PIN     (0u == UART_RS_485_REMOVE_SPI_SLAVE_MISO_PIN)
#define UART_RS_485_UART_TX_PIN            (0u == UART_RS_485_REMOVE_UART_TX_PIN)
#define UART_RS_485_UART_RX_TX_PIN         (0u == UART_RS_485_REMOVE_UART_RX_TX_PIN)
#define UART_RS_485_UART_RX_PIN            (0u == UART_RS_485_REMOVE_UART_RX_PIN)
#define UART_RS_485_UART_RX_WAKE_PIN       (0u == UART_RS_485_REMOVE_UART_RX_WAKE_PIN)
#define UART_RS_485_UART_RTS_PIN           (0u == UART_RS_485_REMOVE_UART_RTS_PIN)
#define UART_RS_485_UART_CTS_PIN           (0u == UART_RS_485_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (UART_RS_485_RX_WAKE_SCL_MOSI_PIN)
    #include "UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (UART_RS_485_RX_SCL_MOSI) */

#if (UART_RS_485_RX_SCL_MOSI_PIN)
    #include "UART_RS_485_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (UART_RS_485_RX_SCL_MOSI) */

#if (UART_RS_485_TX_SDA_MISO_PIN)
    #include "UART_RS_485_uart_tx_i2c_sda_spi_miso.h"
#endif /* (UART_RS_485_TX_SDA_MISO) */

#if (UART_RS_485_SCLK_PIN)
    #include "UART_RS_485_spi_sclk.h"
#endif /* (UART_RS_485_SCLK) */

#if (UART_RS_485_SS0_PIN)
    #include "UART_RS_485_spi_ss0.h"
#endif /* (UART_RS_485_SS0_PIN) */

#if (UART_RS_485_SS1_PIN)
    #include "UART_RS_485_spi_ss1.h"
#endif /* (UART_RS_485_SS1_PIN) */

#if (UART_RS_485_SS2_PIN)
    #include "UART_RS_485_spi_ss2.h"
#endif /* (UART_RS_485_SS2_PIN) */

#if (UART_RS_485_SS3_PIN)
    #include "UART_RS_485_spi_ss3.h"
#endif /* (UART_RS_485_SS3_PIN) */

#if (UART_RS_485_I2C_PINS)
    #include "UART_RS_485_scl.h"
    #include "UART_RS_485_sda.h"
#endif /* (UART_RS_485_I2C_PINS) */

#if (UART_RS_485_SPI_MASTER_PINS)
#if (UART_RS_485_SPI_MASTER_SCLK_PIN)
    #include "UART_RS_485_sclk_m.h"
#endif /* (UART_RS_485_SPI_MASTER_SCLK_PIN) */

#if (UART_RS_485_SPI_MASTER_MOSI_PIN)
    #include "UART_RS_485_mosi_m.h"
#endif /* (UART_RS_485_SPI_MASTER_MOSI_PIN) */

#if (UART_RS_485_SPI_MASTER_MISO_PIN)
    #include "UART_RS_485_miso_m.h"
#endif /*(UART_RS_485_SPI_MASTER_MISO_PIN) */
#endif /* (UART_RS_485_SPI_MASTER_PINS) */

#if (UART_RS_485_SPI_SLAVE_PINS)
    #include "UART_RS_485_sclk_s.h"
    #include "UART_RS_485_ss_s.h"

#if (UART_RS_485_SPI_SLAVE_MOSI_PIN)
    #include "UART_RS_485_mosi_s.h"
#endif /* (UART_RS_485_SPI_SLAVE_MOSI_PIN) */

#if (UART_RS_485_SPI_SLAVE_MISO_PIN)
    #include "UART_RS_485_miso_s.h"
#endif /*(UART_RS_485_SPI_SLAVE_MISO_PIN) */
#endif /* (UART_RS_485_SPI_SLAVE_PINS) */

#if (UART_RS_485_SPI_MASTER_SS0_PIN)
    #include "UART_RS_485_ss0_m.h"
#endif /* (UART_RS_485_SPI_MASTER_SS0_PIN) */

#if (UART_RS_485_SPI_MASTER_SS1_PIN)
    #include "UART_RS_485_ss1_m.h"
#endif /* (UART_RS_485_SPI_MASTER_SS1_PIN) */

#if (UART_RS_485_SPI_MASTER_SS2_PIN)
    #include "UART_RS_485_ss2_m.h"
#endif /* (UART_RS_485_SPI_MASTER_SS2_PIN) */

#if (UART_RS_485_SPI_MASTER_SS3_PIN)
    #include "UART_RS_485_ss3_m.h"
#endif /* (UART_RS_485_SPI_MASTER_SS3_PIN) */

#if (UART_RS_485_UART_TX_PIN)
    #include "UART_RS_485_tx.h"
#endif /* (UART_RS_485_UART_TX_PIN) */

#if (UART_RS_485_UART_RX_TX_PIN)
    #include "UART_RS_485_rx_tx.h"
#endif /* (UART_RS_485_UART_RX_TX_PIN) */

#if (UART_RS_485_UART_RX_PIN)
    #include "UART_RS_485_rx.h"
#endif /* (UART_RS_485_UART_RX_PIN) */

#if (UART_RS_485_UART_RX_WAKE_PIN)
    #include "UART_RS_485_rx_wake.h"
#endif /* (UART_RS_485_UART_RX_WAKE_PIN) */

#if (UART_RS_485_UART_RTS_PIN)
    #include "UART_RS_485_rts.h"
#endif /* (UART_RS_485_UART_RTS_PIN) */

#if (UART_RS_485_UART_CTS_PIN)
    #include "UART_RS_485_cts.h"
#endif /* (UART_RS_485_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (UART_RS_485_RX_SCL_MOSI_PIN)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_MASK      (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_POS       (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_SEL_GPIO  (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_SEL_I2C   (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_SEL_SPI   (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define UART_RS_485_RX_SCL_MOSI_HSIOM_SEL_UART  (UART_RS_485_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (UART_RS_485_RX_WAKE_SCL_MOSI_PIN)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_MASK      (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_POS       (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define UART_RS_485_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define UART_RS_485_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) UART_RS_485_INTCFG_TYPE_MASK << \
                                                                           UART_RS_485_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins UART_RS_485_RX_SCL_MOSI_PIN or UART_RS_485_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (UART_RS_485_RX_SCL_MOSI_PIN) */

#if (UART_RS_485_TX_SDA_MISO_PIN)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define UART_RS_485_TX_SDA_MISO_HSIOM_MASK      (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_POS       (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_SEL_GPIO  (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_SEL_I2C   (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_SEL_SPI   (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define UART_RS_485_TX_SDA_MISO_HSIOM_SEL_UART  (UART_RS_485_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (UART_RS_485_TX_SDA_MISO_PIN) */

#if (UART_RS_485_SCLK_PIN)
    #define UART_RS_485_SCLK_HSIOM_REG   (*(reg32 *) UART_RS_485_spi_sclk__0__HSIOM)
    #define UART_RS_485_SCLK_HSIOM_PTR   ( (reg32 *) UART_RS_485_spi_sclk__0__HSIOM)
    
    #define UART_RS_485_SCLK_HSIOM_MASK      (UART_RS_485_spi_sclk__0__HSIOM_MASK)
    #define UART_RS_485_SCLK_HSIOM_POS       (UART_RS_485_spi_sclk__0__HSIOM_SHIFT)
    #define UART_RS_485_SCLK_HSIOM_SEL_GPIO  (UART_RS_485_spi_sclk__0__HSIOM_GPIO)
    #define UART_RS_485_SCLK_HSIOM_SEL_I2C   (UART_RS_485_spi_sclk__0__HSIOM_I2C)
    #define UART_RS_485_SCLK_HSIOM_SEL_SPI   (UART_RS_485_spi_sclk__0__HSIOM_SPI)
    #define UART_RS_485_SCLK_HSIOM_SEL_UART  (UART_RS_485_spi_sclk__0__HSIOM_UART)
#endif /* (UART_RS_485_SCLK_PIN) */

#if (UART_RS_485_SS0_PIN)
    #define UART_RS_485_SS0_HSIOM_REG   (*(reg32 *) UART_RS_485_spi_ss0__0__HSIOM)
    #define UART_RS_485_SS0_HSIOM_PTR   ( (reg32 *) UART_RS_485_spi_ss0__0__HSIOM)
    
    #define UART_RS_485_SS0_HSIOM_MASK      (UART_RS_485_spi_ss0__0__HSIOM_MASK)
    #define UART_RS_485_SS0_HSIOM_POS       (UART_RS_485_spi_ss0__0__HSIOM_SHIFT)
    #define UART_RS_485_SS0_HSIOM_SEL_GPIO  (UART_RS_485_spi_ss0__0__HSIOM_GPIO)
    #define UART_RS_485_SS0_HSIOM_SEL_I2C   (UART_RS_485_spi_ss0__0__HSIOM_I2C)
    #define UART_RS_485_SS0_HSIOM_SEL_SPI   (UART_RS_485_spi_ss0__0__HSIOM_SPI)
#if !(UART_RS_485_CY_SCBIP_V0 || UART_RS_485_CY_SCBIP_V1)
    #define UART_RS_485_SS0_HSIOM_SEL_UART  (UART_RS_485_spi_ss0__0__HSIOM_UART)
#endif /* !(UART_RS_485_CY_SCBIP_V0 || UART_RS_485_CY_SCBIP_V1) */
#endif /* (UART_RS_485_SS0_PIN) */

#if (UART_RS_485_SS1_PIN)
    #define UART_RS_485_SS1_HSIOM_REG  (*(reg32 *) UART_RS_485_spi_ss1__0__HSIOM)
    #define UART_RS_485_SS1_HSIOM_PTR  ( (reg32 *) UART_RS_485_spi_ss1__0__HSIOM)
    
    #define UART_RS_485_SS1_HSIOM_MASK     (UART_RS_485_spi_ss1__0__HSIOM_MASK)
    #define UART_RS_485_SS1_HSIOM_POS      (UART_RS_485_spi_ss1__0__HSIOM_SHIFT)
    #define UART_RS_485_SS1_HSIOM_SEL_GPIO (UART_RS_485_spi_ss1__0__HSIOM_GPIO)
    #define UART_RS_485_SS1_HSIOM_SEL_I2C  (UART_RS_485_spi_ss1__0__HSIOM_I2C)
    #define UART_RS_485_SS1_HSIOM_SEL_SPI  (UART_RS_485_spi_ss1__0__HSIOM_SPI)
#endif /* (UART_RS_485_SS1_PIN) */

#if (UART_RS_485_SS2_PIN)
    #define UART_RS_485_SS2_HSIOM_REG     (*(reg32 *) UART_RS_485_spi_ss2__0__HSIOM)
    #define UART_RS_485_SS2_HSIOM_PTR     ( (reg32 *) UART_RS_485_spi_ss2__0__HSIOM)
    
    #define UART_RS_485_SS2_HSIOM_MASK     (UART_RS_485_spi_ss2__0__HSIOM_MASK)
    #define UART_RS_485_SS2_HSIOM_POS      (UART_RS_485_spi_ss2__0__HSIOM_SHIFT)
    #define UART_RS_485_SS2_HSIOM_SEL_GPIO (UART_RS_485_spi_ss2__0__HSIOM_GPIO)
    #define UART_RS_485_SS2_HSIOM_SEL_I2C  (UART_RS_485_spi_ss2__0__HSIOM_I2C)
    #define UART_RS_485_SS2_HSIOM_SEL_SPI  (UART_RS_485_spi_ss2__0__HSIOM_SPI)
#endif /* (UART_RS_485_SS2_PIN) */

#if (UART_RS_485_SS3_PIN)
    #define UART_RS_485_SS3_HSIOM_REG     (*(reg32 *) UART_RS_485_spi_ss3__0__HSIOM)
    #define UART_RS_485_SS3_HSIOM_PTR     ( (reg32 *) UART_RS_485_spi_ss3__0__HSIOM)
    
    #define UART_RS_485_SS3_HSIOM_MASK     (UART_RS_485_spi_ss3__0__HSIOM_MASK)
    #define UART_RS_485_SS3_HSIOM_POS      (UART_RS_485_spi_ss3__0__HSIOM_SHIFT)
    #define UART_RS_485_SS3_HSIOM_SEL_GPIO (UART_RS_485_spi_ss3__0__HSIOM_GPIO)
    #define UART_RS_485_SS3_HSIOM_SEL_I2C  (UART_RS_485_spi_ss3__0__HSIOM_I2C)
    #define UART_RS_485_SS3_HSIOM_SEL_SPI  (UART_RS_485_spi_ss3__0__HSIOM_SPI)
#endif /* (UART_RS_485_SS3_PIN) */

#if (UART_RS_485_I2C_PINS)
    #define UART_RS_485_SCL_HSIOM_REG  (*(reg32 *) UART_RS_485_scl__0__HSIOM)
    #define UART_RS_485_SCL_HSIOM_PTR  ( (reg32 *) UART_RS_485_scl__0__HSIOM)
    
    #define UART_RS_485_SCL_HSIOM_MASK     (UART_RS_485_scl__0__HSIOM_MASK)
    #define UART_RS_485_SCL_HSIOM_POS      (UART_RS_485_scl__0__HSIOM_SHIFT)
    #define UART_RS_485_SCL_HSIOM_SEL_GPIO (UART_RS_485_sda__0__HSIOM_GPIO)
    #define UART_RS_485_SCL_HSIOM_SEL_I2C  (UART_RS_485_sda__0__HSIOM_I2C)
    
    #define UART_RS_485_SDA_HSIOM_REG  (*(reg32 *) UART_RS_485_sda__0__HSIOM)
    #define UART_RS_485_SDA_HSIOM_PTR  ( (reg32 *) UART_RS_485_sda__0__HSIOM)
    
    #define UART_RS_485_SDA_HSIOM_MASK     (UART_RS_485_sda__0__HSIOM_MASK)
    #define UART_RS_485_SDA_HSIOM_POS      (UART_RS_485_sda__0__HSIOM_SHIFT)
    #define UART_RS_485_SDA_HSIOM_SEL_GPIO (UART_RS_485_sda__0__HSIOM_GPIO)
    #define UART_RS_485_SDA_HSIOM_SEL_I2C  (UART_RS_485_sda__0__HSIOM_I2C)
#endif /* (UART_RS_485_I2C_PINS) */

#if (UART_RS_485_SPI_SLAVE_PINS)
    #define UART_RS_485_SCLK_S_HSIOM_REG   (*(reg32 *) UART_RS_485_sclk_s__0__HSIOM)
    #define UART_RS_485_SCLK_S_HSIOM_PTR   ( (reg32 *) UART_RS_485_sclk_s__0__HSIOM)
    
    #define UART_RS_485_SCLK_S_HSIOM_MASK      (UART_RS_485_sclk_s__0__HSIOM_MASK)
    #define UART_RS_485_SCLK_S_HSIOM_POS       (UART_RS_485_sclk_s__0__HSIOM_SHIFT)
    #define UART_RS_485_SCLK_S_HSIOM_SEL_GPIO  (UART_RS_485_sclk_s__0__HSIOM_GPIO)
    #define UART_RS_485_SCLK_S_HSIOM_SEL_SPI   (UART_RS_485_sclk_s__0__HSIOM_SPI)
    
    #define UART_RS_485_SS0_S_HSIOM_REG    (*(reg32 *) UART_RS_485_ss0_s__0__HSIOM)
    #define UART_RS_485_SS0_S_HSIOM_PTR    ( (reg32 *) UART_RS_485_ss0_s__0__HSIOM)
    
    #define UART_RS_485_SS0_S_HSIOM_MASK       (UART_RS_485_ss0_s__0__HSIOM_MASK)
    #define UART_RS_485_SS0_S_HSIOM_POS        (UART_RS_485_ss0_s__0__HSIOM_SHIFT)
    #define UART_RS_485_SS0_S_HSIOM_SEL_GPIO   (UART_RS_485_ss0_s__0__HSIOM_GPIO)  
    #define UART_RS_485_SS0_S_HSIOM_SEL_SPI    (UART_RS_485_ss0_s__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_SLAVE_PINS) */

#if (UART_RS_485_SPI_SLAVE_MOSI_PIN)
    #define UART_RS_485_MOSI_S_HSIOM_REG   (*(reg32 *) UART_RS_485_mosi_s__0__HSIOM)
    #define UART_RS_485_MOSI_S_HSIOM_PTR   ( (reg32 *) UART_RS_485_mosi_s__0__HSIOM)
    
    #define UART_RS_485_MOSI_S_HSIOM_MASK      (UART_RS_485_mosi_s__0__HSIOM_MASK)
    #define UART_RS_485_MOSI_S_HSIOM_POS       (UART_RS_485_mosi_s__0__HSIOM_SHIFT)
    #define UART_RS_485_MOSI_S_HSIOM_SEL_GPIO  (UART_RS_485_mosi_s__0__HSIOM_GPIO)
    #define UART_RS_485_MOSI_S_HSIOM_SEL_SPI   (UART_RS_485_mosi_s__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_SLAVE_MOSI_PIN) */

#if (UART_RS_485_SPI_SLAVE_MISO_PIN)
    #define UART_RS_485_MISO_S_HSIOM_REG   (*(reg32 *) UART_RS_485_miso_s__0__HSIOM)
    #define UART_RS_485_MISO_S_HSIOM_PTR   ( (reg32 *) UART_RS_485_miso_s__0__HSIOM)
    
    #define UART_RS_485_MISO_S_HSIOM_MASK      (UART_RS_485_miso_s__0__HSIOM_MASK)
    #define UART_RS_485_MISO_S_HSIOM_POS       (UART_RS_485_miso_s__0__HSIOM_SHIFT)
    #define UART_RS_485_MISO_S_HSIOM_SEL_GPIO  (UART_RS_485_miso_s__0__HSIOM_GPIO)
    #define UART_RS_485_MISO_S_HSIOM_SEL_SPI   (UART_RS_485_miso_s__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_SLAVE_MISO_PIN) */

#if (UART_RS_485_SPI_MASTER_MISO_PIN)
    #define UART_RS_485_MISO_M_HSIOM_REG   (*(reg32 *) UART_RS_485_miso_m__0__HSIOM)
    #define UART_RS_485_MISO_M_HSIOM_PTR   ( (reg32 *) UART_RS_485_miso_m__0__HSIOM)
    
    #define UART_RS_485_MISO_M_HSIOM_MASK      (UART_RS_485_miso_m__0__HSIOM_MASK)
    #define UART_RS_485_MISO_M_HSIOM_POS       (UART_RS_485_miso_m__0__HSIOM_SHIFT)
    #define UART_RS_485_MISO_M_HSIOM_SEL_GPIO  (UART_RS_485_miso_m__0__HSIOM_GPIO)
    #define UART_RS_485_MISO_M_HSIOM_SEL_SPI   (UART_RS_485_miso_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_MISO_PIN) */

#if (UART_RS_485_SPI_MASTER_MOSI_PIN)
    #define UART_RS_485_MOSI_M_HSIOM_REG   (*(reg32 *) UART_RS_485_mosi_m__0__HSIOM)
    #define UART_RS_485_MOSI_M_HSIOM_PTR   ( (reg32 *) UART_RS_485_mosi_m__0__HSIOM)
    
    #define UART_RS_485_MOSI_M_HSIOM_MASK      (UART_RS_485_mosi_m__0__HSIOM_MASK)
    #define UART_RS_485_MOSI_M_HSIOM_POS       (UART_RS_485_mosi_m__0__HSIOM_SHIFT)
    #define UART_RS_485_MOSI_M_HSIOM_SEL_GPIO  (UART_RS_485_mosi_m__0__HSIOM_GPIO)
    #define UART_RS_485_MOSI_M_HSIOM_SEL_SPI   (UART_RS_485_mosi_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_MOSI_PIN) */

#if (UART_RS_485_SPI_MASTER_SCLK_PIN)
    #define UART_RS_485_SCLK_M_HSIOM_REG   (*(reg32 *) UART_RS_485_sclk_m__0__HSIOM)
    #define UART_RS_485_SCLK_M_HSIOM_PTR   ( (reg32 *) UART_RS_485_sclk_m__0__HSIOM)
    
    #define UART_RS_485_SCLK_M_HSIOM_MASK      (UART_RS_485_sclk_m__0__HSIOM_MASK)
    #define UART_RS_485_SCLK_M_HSIOM_POS       (UART_RS_485_sclk_m__0__HSIOM_SHIFT)
    #define UART_RS_485_SCLK_M_HSIOM_SEL_GPIO  (UART_RS_485_sclk_m__0__HSIOM_GPIO)
    #define UART_RS_485_SCLK_M_HSIOM_SEL_SPI   (UART_RS_485_sclk_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_SCLK_PIN) */

#if (UART_RS_485_SPI_MASTER_SS0_PIN)
    #define UART_RS_485_SS0_M_HSIOM_REG    (*(reg32 *) UART_RS_485_ss0_m__0__HSIOM)
    #define UART_RS_485_SS0_M_HSIOM_PTR    ( (reg32 *) UART_RS_485_ss0_m__0__HSIOM)
    
    #define UART_RS_485_SS0_M_HSIOM_MASK       (UART_RS_485_ss0_m__0__HSIOM_MASK)
    #define UART_RS_485_SS0_M_HSIOM_POS        (UART_RS_485_ss0_m__0__HSIOM_SHIFT)
    #define UART_RS_485_SS0_M_HSIOM_SEL_GPIO   (UART_RS_485_ss0_m__0__HSIOM_GPIO)
    #define UART_RS_485_SS0_M_HSIOM_SEL_SPI    (UART_RS_485_ss0_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_SS0_PIN) */

#if (UART_RS_485_SPI_MASTER_SS1_PIN)
    #define UART_RS_485_SS1_M_HSIOM_REG    (*(reg32 *) UART_RS_485_ss1_m__0__HSIOM)
    #define UART_RS_485_SS1_M_HSIOM_PTR    ( (reg32 *) UART_RS_485_ss1_m__0__HSIOM)
    
    #define UART_RS_485_SS1_M_HSIOM_MASK       (UART_RS_485_ss1_m__0__HSIOM_MASK)
    #define UART_RS_485_SS1_M_HSIOM_POS        (UART_RS_485_ss1_m__0__HSIOM_SHIFT)
    #define UART_RS_485_SS1_M_HSIOM_SEL_GPIO   (UART_RS_485_ss1_m__0__HSIOM_GPIO)
    #define UART_RS_485_SS1_M_HSIOM_SEL_SPI    (UART_RS_485_ss1_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_SS1_PIN) */

#if (UART_RS_485_SPI_MASTER_SS2_PIN)
    #define UART_RS_485_SS2_M_HSIOM_REG    (*(reg32 *) UART_RS_485_ss2_m__0__HSIOM)
    #define UART_RS_485_SS2_M_HSIOM_PTR    ( (reg32 *) UART_RS_485_ss2_m__0__HSIOM)
    
    #define UART_RS_485_SS2_M_HSIOM_MASK       (UART_RS_485_ss2_m__0__HSIOM_MASK)
    #define UART_RS_485_SS2_M_HSIOM_POS        (UART_RS_485_ss2_m__0__HSIOM_SHIFT)
    #define UART_RS_485_SS2_M_HSIOM_SEL_GPIO   (UART_RS_485_ss2_m__0__HSIOM_GPIO)
    #define UART_RS_485_SS2_M_HSIOM_SEL_SPI    (UART_RS_485_ss2_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_SS2_PIN) */

#if (UART_RS_485_SPI_MASTER_SS3_PIN)
    #define UART_RS_485_SS3_M_HSIOM_REG    (*(reg32 *) UART_RS_485_ss3_m__0__HSIOM)
    #define UART_RS_485_SS3_M_HSIOM_PTR    ( (reg32 *) UART_RS_485_ss3_m__0__HSIOM)
    
    #define UART_RS_485_SS3_M_HSIOM_MASK      (UART_RS_485_ss3_m__0__HSIOM_MASK)
    #define UART_RS_485_SS3_M_HSIOM_POS       (UART_RS_485_ss3_m__0__HSIOM_SHIFT)
    #define UART_RS_485_SS3_M_HSIOM_SEL_GPIO  (UART_RS_485_ss3_m__0__HSIOM_GPIO)
    #define UART_RS_485_SS3_M_HSIOM_SEL_SPI   (UART_RS_485_ss3_m__0__HSIOM_SPI)
#endif /* (UART_RS_485_SPI_MASTER_SS3_PIN) */

#if (UART_RS_485_UART_RX_PIN)
    #define UART_RS_485_RX_HSIOM_REG   (*(reg32 *) UART_RS_485_rx__0__HSIOM)
    #define UART_RS_485_RX_HSIOM_PTR   ( (reg32 *) UART_RS_485_rx__0__HSIOM)
    
    #define UART_RS_485_RX_HSIOM_MASK      (UART_RS_485_rx__0__HSIOM_MASK)
    #define UART_RS_485_RX_HSIOM_POS       (UART_RS_485_rx__0__HSIOM_SHIFT)
    #define UART_RS_485_RX_HSIOM_SEL_GPIO  (UART_RS_485_rx__0__HSIOM_GPIO)
    #define UART_RS_485_RX_HSIOM_SEL_UART  (UART_RS_485_rx__0__HSIOM_UART)
#endif /* (UART_RS_485_UART_RX_PIN) */

#if (UART_RS_485_UART_RX_WAKE_PIN)
    #define UART_RS_485_RX_WAKE_HSIOM_REG   (*(reg32 *) UART_RS_485_rx_wake__0__HSIOM)
    #define UART_RS_485_RX_WAKE_HSIOM_PTR   ( (reg32 *) UART_RS_485_rx_wake__0__HSIOM)
    
    #define UART_RS_485_RX_WAKE_HSIOM_MASK      (UART_RS_485_rx_wake__0__HSIOM_MASK)
    #define UART_RS_485_RX_WAKE_HSIOM_POS       (UART_RS_485_rx_wake__0__HSIOM_SHIFT)
    #define UART_RS_485_RX_WAKE_HSIOM_SEL_GPIO  (UART_RS_485_rx_wake__0__HSIOM_GPIO)
    #define UART_RS_485_RX_WAKE_HSIOM_SEL_UART  (UART_RS_485_rx_wake__0__HSIOM_UART)
#endif /* (UART_RS_485_UART_WAKE_RX_PIN) */

#if (UART_RS_485_UART_CTS_PIN)
    #define UART_RS_485_CTS_HSIOM_REG   (*(reg32 *) UART_RS_485_cts__0__HSIOM)
    #define UART_RS_485_CTS_HSIOM_PTR   ( (reg32 *) UART_RS_485_cts__0__HSIOM)
    
    #define UART_RS_485_CTS_HSIOM_MASK      (UART_RS_485_cts__0__HSIOM_MASK)
    #define UART_RS_485_CTS_HSIOM_POS       (UART_RS_485_cts__0__HSIOM_SHIFT)
    #define UART_RS_485_CTS_HSIOM_SEL_GPIO  (UART_RS_485_cts__0__HSIOM_GPIO)
    #define UART_RS_485_CTS_HSIOM_SEL_UART  (UART_RS_485_cts__0__HSIOM_UART)
#endif /* (UART_RS_485_UART_CTS_PIN) */

#if (UART_RS_485_UART_TX_PIN)
    #define UART_RS_485_TX_HSIOM_REG   (*(reg32 *) UART_RS_485_tx__0__HSIOM)
    #define UART_RS_485_TX_HSIOM_PTR   ( (reg32 *) UART_RS_485_tx__0__HSIOM)
    
    #define UART_RS_485_TX_HSIOM_MASK      (UART_RS_485_tx__0__HSIOM_MASK)
    #define UART_RS_485_TX_HSIOM_POS       (UART_RS_485_tx__0__HSIOM_SHIFT)
    #define UART_RS_485_TX_HSIOM_SEL_GPIO  (UART_RS_485_tx__0__HSIOM_GPIO)
    #define UART_RS_485_TX_HSIOM_SEL_UART  (UART_RS_485_tx__0__HSIOM_UART)
#endif /* (UART_RS_485_UART_TX_PIN) */

#if (UART_RS_485_UART_RX_TX_PIN)
    #define UART_RS_485_RX_TX_HSIOM_REG   (*(reg32 *) UART_RS_485_rx_tx__0__HSIOM)
    #define UART_RS_485_RX_TX_HSIOM_PTR   ( (reg32 *) UART_RS_485_rx_tx__0__HSIOM)
    
    #define UART_RS_485_RX_TX_HSIOM_MASK      (UART_RS_485_rx_tx__0__HSIOM_MASK)
    #define UART_RS_485_RX_TX_HSIOM_POS       (UART_RS_485_rx_tx__0__HSIOM_SHIFT)
    #define UART_RS_485_RX_TX_HSIOM_SEL_GPIO  (UART_RS_485_rx_tx__0__HSIOM_GPIO)
    #define UART_RS_485_RX_TX_HSIOM_SEL_UART  (UART_RS_485_rx_tx__0__HSIOM_UART)
#endif /* (UART_RS_485_UART_RX_TX_PIN) */

#if (UART_RS_485_UART_RTS_PIN)
    #define UART_RS_485_RTS_HSIOM_REG      (*(reg32 *) UART_RS_485_rts__0__HSIOM)
    #define UART_RS_485_RTS_HSIOM_PTR      ( (reg32 *) UART_RS_485_rts__0__HSIOM)
    
    #define UART_RS_485_RTS_HSIOM_MASK     (UART_RS_485_rts__0__HSIOM_MASK)
    #define UART_RS_485_RTS_HSIOM_POS      (UART_RS_485_rts__0__HSIOM_SHIFT)    
    #define UART_RS_485_RTS_HSIOM_SEL_GPIO (UART_RS_485_rts__0__HSIOM_GPIO)
    #define UART_RS_485_RTS_HSIOM_SEL_UART (UART_RS_485_rts__0__HSIOM_UART)    
#endif /* (UART_RS_485_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define UART_RS_485_HSIOM_DEF_SEL      (0x00u)
#define UART_RS_485_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for UART_RS_485_CY_SCBIP_V0 
* and UART_RS_485_CY_SCBIP_V1. It is not recommended to use them for 
* UART_RS_485_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define UART_RS_485_HSIOM_UART_SEL     (0x09u)
#define UART_RS_485_HSIOM_I2C_SEL      (0x0Eu)
#define UART_RS_485_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define UART_RS_485_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define UART_RS_485_RX_SCL_MOSI_PIN_INDEX       (0u)
#define UART_RS_485_TX_SDA_MISO_PIN_INDEX       (1u)
#define UART_RS_485_SCLK_PIN_INDEX       (2u)
#define UART_RS_485_SS0_PIN_INDEX       (3u)
#define UART_RS_485_SS1_PIN_INDEX                  (4u)
#define UART_RS_485_SS2_PIN_INDEX                  (5u)
#define UART_RS_485_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define UART_RS_485_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << UART_RS_485_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define UART_RS_485_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << UART_RS_485_RX_SCL_MOSI_PIN_INDEX)
#define UART_RS_485_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << UART_RS_485_TX_SDA_MISO_PIN_INDEX)
#define UART_RS_485_SCLK_PIN_MASK     ((uint32) 0x01u << UART_RS_485_SCLK_PIN_INDEX)
#define UART_RS_485_SS0_PIN_MASK     ((uint32) 0x01u << UART_RS_485_SS0_PIN_INDEX)
#define UART_RS_485_SS1_PIN_MASK                ((uint32) 0x01u << UART_RS_485_SS1_PIN_INDEX)
#define UART_RS_485_SS2_PIN_MASK                ((uint32) 0x01u << UART_RS_485_SS2_PIN_INDEX)
#define UART_RS_485_SS3_PIN_MASK                ((uint32) 0x01u << UART_RS_485_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define UART_RS_485_INTCFG_TYPE_MASK           (0x03u)
#define UART_RS_485_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define UART_RS_485_PIN_DM_ALG_HIZ  (0u)
#define UART_RS_485_PIN_DM_DIG_HIZ  (1u)
#define UART_RS_485_PIN_DM_OD_LO    (4u)
#define UART_RS_485_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define UART_RS_485_DM_MASK    (0x7u)
#define UART_RS_485_DM_SIZE    (3u)
#define UART_RS_485_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) UART_RS_485_DM_MASK << (UART_RS_485_DM_SIZE * (pos)))) >> \
                                                              (UART_RS_485_DM_SIZE * (pos)) )

#if (UART_RS_485_TX_SDA_MISO_PIN)
    #define UART_RS_485_CHECK_TX_SDA_MISO_PIN_USED \
                (UART_RS_485_PIN_DM_ALG_HIZ != \
                    UART_RS_485_GET_P4_PIN_DM(UART_RS_485_uart_tx_i2c_sda_spi_miso_PC, \
                                                   UART_RS_485_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (UART_RS_485_TX_SDA_MISO_PIN) */

#if (UART_RS_485_SS0_PIN)
    #define UART_RS_485_CHECK_SS0_PIN_USED \
                (UART_RS_485_PIN_DM_ALG_HIZ != \
                    UART_RS_485_GET_P4_PIN_DM(UART_RS_485_spi_ss0_PC, \
                                                   UART_RS_485_spi_ss0_SHIFT))
#endif /* (UART_RS_485_SS0_PIN) */

/* Set bits-mask in register */
#define UART_RS_485_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define UART_RS_485_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define UART_RS_485_SET_HSIOM_SEL(reg, mask, pos, sel) UART_RS_485_SET_REGISTER_BITS(reg, mask, pos, sel)
#define UART_RS_485_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        UART_RS_485_SET_REGISTER_BITS(reg, mask, pos, intType)
#define UART_RS_485_SET_INP_DIS(reg, mask, val) UART_RS_485_SET_REGISTER_BIT(reg, mask, val)

/* UART_RS_485_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  UART_RS_485_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (UART_RS_485_CY_SCBIP_V0)
#if (UART_RS_485_I2C_PINS)
    #define UART_RS_485_SET_I2C_SCL_DR(val) UART_RS_485_scl_Write(val)

    #define UART_RS_485_SET_I2C_SCL_HSIOM_SEL(sel) \
                          UART_RS_485_SET_HSIOM_SEL(UART_RS_485_SCL_HSIOM_REG,  \
                                                         UART_RS_485_SCL_HSIOM_MASK, \
                                                         UART_RS_485_SCL_HSIOM_POS,  \
                                                         (sel))
    #define UART_RS_485_WAIT_SCL_SET_HIGH  (0u == UART_RS_485_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (UART_RS_485_RX_WAKE_SCL_MOSI_PIN)
    #define UART_RS_485_SET_I2C_SCL_DR(val) \
                            UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define UART_RS_485_SET_I2C_SCL_HSIOM_SEL(sel) \
                    UART_RS_485_SET_HSIOM_SEL(UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define UART_RS_485_WAIT_SCL_SET_HIGH  (0u == UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (UART_RS_485_RX_SCL_MOSI_PIN)
    #define UART_RS_485_SET_I2C_SCL_DR(val) \
                            UART_RS_485_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define UART_RS_485_SET_I2C_SCL_HSIOM_SEL(sel) \
                            UART_RS_485_SET_HSIOM_SEL(UART_RS_485_RX_SCL_MOSI_HSIOM_REG,  \
                                                           UART_RS_485_RX_SCL_MOSI_HSIOM_MASK, \
                                                           UART_RS_485_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define UART_RS_485_WAIT_SCL_SET_HIGH  (0u == UART_RS_485_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define UART_RS_485_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define UART_RS_485_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define UART_RS_485_WAIT_SCL_SET_HIGH  (0u)
#endif /* (UART_RS_485_I2C_PINS) */

/* SCB I2C: sda signal */
#if (UART_RS_485_I2C_PINS)
    #define UART_RS_485_WAIT_SDA_SET_HIGH  (0u == UART_RS_485_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (UART_RS_485_TX_SDA_MISO_PIN)
    #define UART_RS_485_WAIT_SDA_SET_HIGH  (0u == UART_RS_485_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define UART_RS_485_WAIT_SDA_SET_HIGH  (0u)
#endif /* (UART_RS_485_MOSI_SCL_RX_PIN) */
#endif /* (UART_RS_485_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (UART_RS_485_RX_SCL_MOSI_PIN)
    #define UART_RS_485_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (UART_RS_485_RX_WAKE_SCL_MOSI_PIN)
    #define UART_RS_485_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) UART_RS_485_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(UART_RS_485_UART_RX_WAKE_PIN)
    #define UART_RS_485_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) UART_RS_485_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (UART_RS_485_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define UART_RS_485_REMOVE_MOSI_SCL_RX_WAKE_PIN    UART_RS_485_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define UART_RS_485_REMOVE_MOSI_SCL_RX_PIN         UART_RS_485_REMOVE_RX_SCL_MOSI_PIN
#define UART_RS_485_REMOVE_MISO_SDA_TX_PIN         UART_RS_485_REMOVE_TX_SDA_MISO_PIN
#ifndef UART_RS_485_REMOVE_SCLK_PIN
#define UART_RS_485_REMOVE_SCLK_PIN                UART_RS_485_REMOVE_SCLK_PIN
#endif /* UART_RS_485_REMOVE_SCLK_PIN */
#ifndef UART_RS_485_REMOVE_SS0_PIN
#define UART_RS_485_REMOVE_SS0_PIN                 UART_RS_485_REMOVE_SS0_PIN
#endif /* UART_RS_485_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define UART_RS_485_MOSI_SCL_RX_WAKE_PIN   UART_RS_485_RX_WAKE_SCL_MOSI_PIN
#define UART_RS_485_MOSI_SCL_RX_PIN        UART_RS_485_RX_SCL_MOSI_PIN
#define UART_RS_485_MISO_SDA_TX_PIN        UART_RS_485_TX_SDA_MISO_PIN
#ifndef UART_RS_485_SCLK_PIN
#define UART_RS_485_SCLK_PIN               UART_RS_485_SCLK_PIN
#endif /* UART_RS_485_SCLK_PIN */
#ifndef UART_RS_485_SS0_PIN
#define UART_RS_485_SS0_PIN                UART_RS_485_SS0_PIN
#endif /* UART_RS_485_SS0_PIN */

#if (UART_RS_485_MOSI_SCL_RX_WAKE_PIN)
    #define UART_RS_485_MOSI_SCL_RX_WAKE_HSIOM_REG     UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_WAKE_HSIOM_PTR     UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_WAKE_HSIOM_MASK    UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_WAKE_HSIOM_POS     UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define UART_RS_485_MOSI_SCL_RX_WAKE_INTCFG_REG    UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_WAKE_INTCFG_PTR    UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define UART_RS_485_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  UART_RS_485_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (UART_RS_485_RX_WAKE_SCL_MOSI_PIN) */

#if (UART_RS_485_MOSI_SCL_RX_PIN)
    #define UART_RS_485_MOSI_SCL_RX_HSIOM_REG      UART_RS_485_RX_SCL_MOSI_HSIOM_REG
    #define UART_RS_485_MOSI_SCL_RX_HSIOM_PTR      UART_RS_485_RX_SCL_MOSI_HSIOM_PTR
    #define UART_RS_485_MOSI_SCL_RX_HSIOM_MASK     UART_RS_485_RX_SCL_MOSI_HSIOM_MASK
    #define UART_RS_485_MOSI_SCL_RX_HSIOM_POS      UART_RS_485_RX_SCL_MOSI_HSIOM_POS
#endif /* (UART_RS_485_MOSI_SCL_RX_PIN) */

#if (UART_RS_485_MISO_SDA_TX_PIN)
    #define UART_RS_485_MISO_SDA_TX_HSIOM_REG      UART_RS_485_TX_SDA_MISO_HSIOM_REG
    #define UART_RS_485_MISO_SDA_TX_HSIOM_PTR      UART_RS_485_TX_SDA_MISO_HSIOM_REG
    #define UART_RS_485_MISO_SDA_TX_HSIOM_MASK     UART_RS_485_TX_SDA_MISO_HSIOM_REG
    #define UART_RS_485_MISO_SDA_TX_HSIOM_POS      UART_RS_485_TX_SDA_MISO_HSIOM_REG
#endif /* (UART_RS_485_MISO_SDA_TX_PIN_PIN) */

#if (UART_RS_485_SCLK_PIN)
    #ifndef UART_RS_485_SCLK_HSIOM_REG
    #define UART_RS_485_SCLK_HSIOM_REG     UART_RS_485_SCLK_HSIOM_REG
    #define UART_RS_485_SCLK_HSIOM_PTR     UART_RS_485_SCLK_HSIOM_PTR
    #define UART_RS_485_SCLK_HSIOM_MASK    UART_RS_485_SCLK_HSIOM_MASK
    #define UART_RS_485_SCLK_HSIOM_POS     UART_RS_485_SCLK_HSIOM_POS
    #endif /* UART_RS_485_SCLK_HSIOM_REG */
#endif /* (UART_RS_485_SCLK_PIN) */

#if (UART_RS_485_SS0_PIN)
    #ifndef UART_RS_485_SS0_HSIOM_REG
    #define UART_RS_485_SS0_HSIOM_REG      UART_RS_485_SS0_HSIOM_REG
    #define UART_RS_485_SS0_HSIOM_PTR      UART_RS_485_SS0_HSIOM_PTR
    #define UART_RS_485_SS0_HSIOM_MASK     UART_RS_485_SS0_HSIOM_MASK
    #define UART_RS_485_SS0_HSIOM_POS      UART_RS_485_SS0_HSIOM_POS
    #endif /* UART_RS_485_SS0_HSIOM_REG */
#endif /* (UART_RS_485_SS0_PIN) */

#define UART_RS_485_MOSI_SCL_RX_WAKE_PIN_INDEX UART_RS_485_RX_WAKE_SCL_MOSI_PIN_INDEX
#define UART_RS_485_MOSI_SCL_RX_PIN_INDEX      UART_RS_485_RX_SCL_MOSI_PIN_INDEX
#define UART_RS_485_MISO_SDA_TX_PIN_INDEX      UART_RS_485_TX_SDA_MISO_PIN_INDEX
#ifndef UART_RS_485_SCLK_PIN_INDEX
#define UART_RS_485_SCLK_PIN_INDEX             UART_RS_485_SCLK_PIN_INDEX
#endif /* UART_RS_485_SCLK_PIN_INDEX */
#ifndef UART_RS_485_SS0_PIN_INDEX
#define UART_RS_485_SS0_PIN_INDEX              UART_RS_485_SS0_PIN_INDEX
#endif /* UART_RS_485_SS0_PIN_INDEX */

#define UART_RS_485_MOSI_SCL_RX_WAKE_PIN_MASK UART_RS_485_RX_WAKE_SCL_MOSI_PIN_MASK
#define UART_RS_485_MOSI_SCL_RX_PIN_MASK      UART_RS_485_RX_SCL_MOSI_PIN_MASK
#define UART_RS_485_MISO_SDA_TX_PIN_MASK      UART_RS_485_TX_SDA_MISO_PIN_MASK
#ifndef UART_RS_485_SCLK_PIN_MASK
#define UART_RS_485_SCLK_PIN_MASK             UART_RS_485_SCLK_PIN_MASK
#endif /* UART_RS_485_SCLK_PIN_MASK */
#ifndef UART_RS_485_SS0_PIN_MASK
#define UART_RS_485_SS0_PIN_MASK              UART_RS_485_SS0_PIN_MASK
#endif /* UART_RS_485_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_UART_RS_485_H) */


/* [] END OF FILE */
