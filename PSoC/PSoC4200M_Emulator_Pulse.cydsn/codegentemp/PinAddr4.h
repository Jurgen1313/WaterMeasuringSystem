/*******************************************************************************
* File Name: PinAddr4.h  
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

#if !defined(CY_PINS_PinAddr4_H) /* Pins PinAddr4_H */
#define CY_PINS_PinAddr4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PinAddr4_aliases.h"


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
} PinAddr4_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PinAddr4_Read(void);
void    PinAddr4_Write(uint8 value);
uint8   PinAddr4_ReadDataReg(void);
#if defined(PinAddr4__PC) || (CY_PSOC4_4200L) 
    void    PinAddr4_SetDriveMode(uint8 mode);
#endif
void    PinAddr4_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinAddr4_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PinAddr4_Sleep(void); 
void PinAddr4_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PinAddr4__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PinAddr4_DRIVE_MODE_BITS        (3)
    #define PinAddr4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PinAddr4_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PinAddr4_SetDriveMode() function.
         *  @{
         */
        #define PinAddr4_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PinAddr4_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PinAddr4_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PinAddr4_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PinAddr4_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PinAddr4_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PinAddr4_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PinAddr4_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PinAddr4_MASK               PinAddr4__MASK
#define PinAddr4_SHIFT              PinAddr4__SHIFT
#define PinAddr4_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinAddr4_SetInterruptMode() function.
     *  @{
     */
        #define PinAddr4_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PinAddr4_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PinAddr4_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PinAddr4_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PinAddr4__SIO)
    #define PinAddr4_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PinAddr4__PC) && (CY_PSOC4_4200L)
    #define PinAddr4_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PinAddr4_USBIO_DISABLE              ((uint32)(~PinAddr4_USBIO_ENABLE))
    #define PinAddr4_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PinAddr4_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PinAddr4_USBIO_ENTER_SLEEP          ((uint32)((1u << PinAddr4_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PinAddr4_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinAddr4_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PinAddr4_USBIO_SUSPEND_SHIFT)))
    #define PinAddr4_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PinAddr4_USBIO_SUSPEND_DEL_SHIFT)))
    #define PinAddr4_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PinAddr4__PC)
    /* Port Configuration */
    #define PinAddr4_PC                 (* (reg32 *) PinAddr4__PC)
#endif
/* Pin State */
#define PinAddr4_PS                     (* (reg32 *) PinAddr4__PS)
/* Data Register */
#define PinAddr4_DR                     (* (reg32 *) PinAddr4__DR)
/* Input Buffer Disable Override */
#define PinAddr4_INP_DIS                (* (reg32 *) PinAddr4__PC2)

/* Interrupt configuration Registers */
#define PinAddr4_INTCFG                 (* (reg32 *) PinAddr4__INTCFG)
#define PinAddr4_INTSTAT                (* (reg32 *) PinAddr4__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PinAddr4_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PinAddr4__SIO)
    #define PinAddr4_SIO_REG            (* (reg32 *) PinAddr4__SIO)
#endif /* (PinAddr4__SIO_CFG) */

/* USBIO registers */
#if !defined(PinAddr4__PC) && (CY_PSOC4_4200L)
    #define PinAddr4_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PinAddr4_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PinAddr4_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PinAddr4_DRIVE_MODE_SHIFT       (0x00u)
#define PinAddr4_DRIVE_MODE_MASK        (0x07u << PinAddr4_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PinAddr4_H */


/* [] END OF FILE */
