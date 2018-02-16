/*******************************************************************************
* File Name: Rs485_send.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Rs485_send_H) /* Pins Rs485_send_H */
#define CY_PINS_Rs485_send_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Rs485_send_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Rs485_send_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Rs485_send_Read(void);
void    Rs485_send_Write(uint8 value);
uint8   Rs485_send_ReadDataReg(void);
#if defined(Rs485_send__PC) || (CY_PSOC4_4200L) 
    void    Rs485_send_SetDriveMode(uint8 mode);
#endif
void    Rs485_send_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rs485_send_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Rs485_send_Sleep(void); 
void Rs485_send_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Rs485_send__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Rs485_send_DRIVE_MODE_BITS        (3)
    #define Rs485_send_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Rs485_send_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Rs485_send_SetDriveMode() function.
         *  @{
         */
        #define Rs485_send_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Rs485_send_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Rs485_send_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Rs485_send_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Rs485_send_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Rs485_send_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Rs485_send_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Rs485_send_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Rs485_send_MASK               Rs485_send__MASK
#define Rs485_send_SHIFT              Rs485_send__SHIFT
#define Rs485_send_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rs485_send_SetInterruptMode() function.
     *  @{
     */
        #define Rs485_send_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Rs485_send_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Rs485_send_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Rs485_send_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Rs485_send__SIO)
    #define Rs485_send_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Rs485_send__PC) && (CY_PSOC4_4200L)
    #define Rs485_send_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Rs485_send_USBIO_DISABLE              ((uint32)(~Rs485_send_USBIO_ENABLE))
    #define Rs485_send_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Rs485_send_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Rs485_send_USBIO_ENTER_SLEEP          ((uint32)((1u << Rs485_send_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Rs485_send_USBIO_SUSPEND_DEL_SHIFT)))
    #define Rs485_send_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Rs485_send_USBIO_SUSPEND_SHIFT)))
    #define Rs485_send_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Rs485_send_USBIO_SUSPEND_DEL_SHIFT)))
    #define Rs485_send_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Rs485_send__PC)
    /* Port Configuration */
    #define Rs485_send_PC                 (* (reg32 *) Rs485_send__PC)
#endif
/* Pin State */
#define Rs485_send_PS                     (* (reg32 *) Rs485_send__PS)
/* Data Register */
#define Rs485_send_DR                     (* (reg32 *) Rs485_send__DR)
/* Input Buffer Disable Override */
#define Rs485_send_INP_DIS                (* (reg32 *) Rs485_send__PC2)

/* Interrupt configuration Registers */
#define Rs485_send_INTCFG                 (* (reg32 *) Rs485_send__INTCFG)
#define Rs485_send_INTSTAT                (* (reg32 *) Rs485_send__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Rs485_send_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Rs485_send__SIO)
    #define Rs485_send_SIO_REG            (* (reg32 *) Rs485_send__SIO)
#endif /* (Rs485_send__SIO_CFG) */

/* USBIO registers */
#if !defined(Rs485_send__PC) && (CY_PSOC4_4200L)
    #define Rs485_send_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Rs485_send_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Rs485_send_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Rs485_send_DRIVE_MODE_SHIFT       (0x00u)
#define Rs485_send_DRIVE_MODE_MASK        (0x07u << Rs485_send_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Rs485_send_H */


/* [] END OF FILE */
