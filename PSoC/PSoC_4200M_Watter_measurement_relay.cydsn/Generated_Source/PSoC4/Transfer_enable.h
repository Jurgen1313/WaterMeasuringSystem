/*******************************************************************************
* File Name: Transfer_enable.h  
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

#if !defined(CY_PINS_Transfer_enable_H) /* Pins Transfer_enable_H */
#define CY_PINS_Transfer_enable_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Transfer_enable_aliases.h"


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
} Transfer_enable_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Transfer_enable_Read(void);
void    Transfer_enable_Write(uint8 value);
uint8   Transfer_enable_ReadDataReg(void);
#if defined(Transfer_enable__PC) || (CY_PSOC4_4200L) 
    void    Transfer_enable_SetDriveMode(uint8 mode);
#endif
void    Transfer_enable_SetInterruptMode(uint16 position, uint16 mode);
uint8   Transfer_enable_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Transfer_enable_Sleep(void); 
void Transfer_enable_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Transfer_enable__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Transfer_enable_DRIVE_MODE_BITS        (3)
    #define Transfer_enable_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Transfer_enable_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Transfer_enable_SetDriveMode() function.
         *  @{
         */
        #define Transfer_enable_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Transfer_enable_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Transfer_enable_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Transfer_enable_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Transfer_enable_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Transfer_enable_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Transfer_enable_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Transfer_enable_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Transfer_enable_MASK               Transfer_enable__MASK
#define Transfer_enable_SHIFT              Transfer_enable__SHIFT
#define Transfer_enable_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Transfer_enable_SetInterruptMode() function.
     *  @{
     */
        #define Transfer_enable_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Transfer_enable_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Transfer_enable_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Transfer_enable_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Transfer_enable__SIO)
    #define Transfer_enable_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Transfer_enable__PC) && (CY_PSOC4_4200L)
    #define Transfer_enable_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Transfer_enable_USBIO_DISABLE              ((uint32)(~Transfer_enable_USBIO_ENABLE))
    #define Transfer_enable_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Transfer_enable_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Transfer_enable_USBIO_ENTER_SLEEP          ((uint32)((1u << Transfer_enable_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Transfer_enable_USBIO_SUSPEND_DEL_SHIFT)))
    #define Transfer_enable_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Transfer_enable_USBIO_SUSPEND_SHIFT)))
    #define Transfer_enable_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Transfer_enable_USBIO_SUSPEND_DEL_SHIFT)))
    #define Transfer_enable_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Transfer_enable__PC)
    /* Port Configuration */
    #define Transfer_enable_PC                 (* (reg32 *) Transfer_enable__PC)
#endif
/* Pin State */
#define Transfer_enable_PS                     (* (reg32 *) Transfer_enable__PS)
/* Data Register */
#define Transfer_enable_DR                     (* (reg32 *) Transfer_enable__DR)
/* Input Buffer Disable Override */
#define Transfer_enable_INP_DIS                (* (reg32 *) Transfer_enable__PC2)

/* Interrupt configuration Registers */
#define Transfer_enable_INTCFG                 (* (reg32 *) Transfer_enable__INTCFG)
#define Transfer_enable_INTSTAT                (* (reg32 *) Transfer_enable__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Transfer_enable_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Transfer_enable__SIO)
    #define Transfer_enable_SIO_REG            (* (reg32 *) Transfer_enable__SIO)
#endif /* (Transfer_enable__SIO_CFG) */

/* USBIO registers */
#if !defined(Transfer_enable__PC) && (CY_PSOC4_4200L)
    #define Transfer_enable_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Transfer_enable_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Transfer_enable_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Transfer_enable_DRIVE_MODE_SHIFT       (0x00u)
#define Transfer_enable_DRIVE_MODE_MASK        (0x07u << Transfer_enable_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Transfer_enable_H */


/* [] END OF FILE */
