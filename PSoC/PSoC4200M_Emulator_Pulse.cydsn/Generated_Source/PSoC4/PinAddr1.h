/*******************************************************************************
* File Name: PinAddr1.h  
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

#if !defined(CY_PINS_PinAddr1_H) /* Pins PinAddr1_H */
#define CY_PINS_PinAddr1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinAddr1_aliases.h"


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
} PinAddr1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinAddr1_Read(void);
void    PinAddr1_Write(uint8 value);
uint8   PinAddr1_ReadDataReg(void);
#if defined(PinAddr1__PC) || (CY_PSOC4_4200L) 
    void    PinAddr1_SetDriveMode(uint8 mode);
#endif
void    PinAddr1_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinAddr1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinAddr1_Sleep(void); 
void PinAddr1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinAddr1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinAddr1_DRIVE_MODE_BITS        (3)
    #define PinAddr1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinAddr1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinAddr1_SetDriveMode() function.
         *  @{
         */
        #define PinAddr1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinAddr1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinAddr1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinAddr1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinAddr1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinAddr1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinAddr1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinAddr1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinAddr1_MASK               PinAddr1__MASK
#define PinAddr1_SHIFT              PinAddr1__SHIFT
#define PinAddr1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinAddr1_SetInterruptMode() function.
     *  @{
     */
        #define PinAddr1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinAddr1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinAddr1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinAddr1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinAddr1__SIO)
    #define PinAddr1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinAddr1__PC) && (CY_PSOC4_4200L)
    #define PinAddr1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinAddr1_USBIO_DISABLE              ((uint32)(~PinAddr1_USBIO_ENABLE))
    #define PinAddr1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinAddr1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinAddr1_USBIO_ENTER_SLEEP          ((uint32)((1u << PinAddr1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinAddr1_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinAddr1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinAddr1_USBIO_SUSPEND_SHIFT)))
    #define PinAddr1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinAddr1_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinAddr1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinAddr1__PC)
    /* Port Configuration */
    #define PinAddr1_PC                 (* (reg32 *) PinAddr1__PC)
#endif
/* Pin State */
#define PinAddr1_PS                     (* (reg32 *) PinAddr1__PS)
/* Data Register */
#define PinAddr1_DR                     (* (reg32 *) PinAddr1__DR)
/* Input Buffer Disable Override */
#define PinAddr1_INP_DIS                (* (reg32 *) PinAddr1__PC2)

/* Interrupt configuration Registers */
#define PinAddr1_INTCFG                 (* (reg32 *) PinAddr1__INTCFG)
#define PinAddr1_INTSTAT                (* (reg32 *) PinAddr1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinAddr1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinAddr1__SIO)
    #define PinAddr1_SIO_REG            (* (reg32 *) PinAddr1__SIO)
#endif /* (PinAddr1__SIO_CFG) */

/* USBIO registers */
#if !defined(PinAddr1__PC) && (CY_PSOC4_4200L)
    #define PinAddr1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinAddr1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinAddr1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinAddr1_DRIVE_MODE_SHIFT       (0x00u)
#define PinAddr1_DRIVE_MODE_MASK        (0x07u << PinAddr1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinAddr1_H */


/* [] END OF FILE */
