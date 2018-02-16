/*******************************************************************************
* File Name: AddrPin.h  
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

#if !defined(CY_PINS_AddrPin_H) /* Pins AddrPin_H */
#define CY_PINS_AddrPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AddrPin_aliases.h"


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
} AddrPin_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   AddrPin_Read(void);
void    AddrPin_Write(uint8 value);
uint8   AddrPin_ReadDataReg(void);
#if defined(AddrPin__PC) || (CY_PSOC4_4200L) 
    void    AddrPin_SetDriveMode(uint8 mode);
#endif
void    AddrPin_SetInterruptMode(uint16 position, uint16 mode);
uint8   AddrPin_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void AddrPin_Sleep(void); 
void AddrPin_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(AddrPin__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define AddrPin_DRIVE_MODE_BITS        (3)
    #define AddrPin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AddrPin_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the AddrPin_SetDriveMode() function.
         *  @{
         */
        #define AddrPin_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define AddrPin_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define AddrPin_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define AddrPin_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define AddrPin_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define AddrPin_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define AddrPin_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define AddrPin_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define AddrPin_MASK               AddrPin__MASK
#define AddrPin_SHIFT              AddrPin__SHIFT
#define AddrPin_WIDTH              4u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AddrPin_SetInterruptMode() function.
     *  @{
     */
        #define AddrPin_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define AddrPin_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define AddrPin_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define AddrPin_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(AddrPin__SIO)
    #define AddrPin_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(AddrPin__PC) && (CY_PSOC4_4200L)
    #define AddrPin_USBIO_ENABLE               ((uint32)0x80000000u)
    #define AddrPin_USBIO_DISABLE              ((uint32)(~AddrPin_USBIO_ENABLE))
    #define AddrPin_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define AddrPin_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define AddrPin_USBIO_ENTER_SLEEP          ((uint32)((1u << AddrPin_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << AddrPin_USBIO_SUSPEND_DEL_SHIFT)))
    #define AddrPin_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << AddrPin_USBIO_SUSPEND_SHIFT)))
    #define AddrPin_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << AddrPin_USBIO_SUSPEND_DEL_SHIFT)))
    #define AddrPin_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(AddrPin__PC)
    /* Port Configuration */
    #define AddrPin_PC                 (* (reg32 *) AddrPin__PC)
#endif
/* Pin State */
#define AddrPin_PS                     (* (reg32 *) AddrPin__PS)
/* Data Register */
#define AddrPin_DR                     (* (reg32 *) AddrPin__DR)
/* Input Buffer Disable Override */
#define AddrPin_INP_DIS                (* (reg32 *) AddrPin__PC2)

/* Interrupt configuration Registers */
#define AddrPin_INTCFG                 (* (reg32 *) AddrPin__INTCFG)
#define AddrPin_INTSTAT                (* (reg32 *) AddrPin__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define AddrPin_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(AddrPin__SIO)
    #define AddrPin_SIO_REG            (* (reg32 *) AddrPin__SIO)
#endif /* (AddrPin__SIO_CFG) */

/* USBIO registers */
#if !defined(AddrPin__PC) && (CY_PSOC4_4200L)
    #define AddrPin_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define AddrPin_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define AddrPin_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define AddrPin_DRIVE_MODE_SHIFT       (0x00u)
#define AddrPin_DRIVE_MODE_MASK        (0x07u << AddrPin_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins AddrPin_H */


/* [] END OF FILE */
