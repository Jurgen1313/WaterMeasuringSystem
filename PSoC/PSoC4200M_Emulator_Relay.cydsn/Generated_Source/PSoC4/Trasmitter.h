/*******************************************************************************
* File Name: Trasmitter.h  
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

#if !defined(CY_PINS_Trasmitter_H) /* Pins Trasmitter_H */
#define CY_PINS_Trasmitter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Trasmitter_aliases.h"


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
} Trasmitter_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Trasmitter_Read(void);
void    Trasmitter_Write(uint8 value);
uint8   Trasmitter_ReadDataReg(void);
#if defined(Trasmitter__PC) || (CY_PSOC4_4200L) 
    void    Trasmitter_SetDriveMode(uint8 mode);
#endif
void    Trasmitter_SetInterruptMode(uint16 position, uint16 mode);
uint8   Trasmitter_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Trasmitter_Sleep(void); 
void Trasmitter_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Trasmitter__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Trasmitter_DRIVE_MODE_BITS        (3)
    #define Trasmitter_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Trasmitter_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Trasmitter_SetDriveMode() function.
         *  @{
         */
        #define Trasmitter_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Trasmitter_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Trasmitter_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Trasmitter_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Trasmitter_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Trasmitter_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Trasmitter_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Trasmitter_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Trasmitter_MASK               Trasmitter__MASK
#define Trasmitter_SHIFT              Trasmitter__SHIFT
#define Trasmitter_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Trasmitter_SetInterruptMode() function.
     *  @{
     */
        #define Trasmitter_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Trasmitter_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Trasmitter_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Trasmitter_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Trasmitter__SIO)
    #define Trasmitter_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Trasmitter__PC) && (CY_PSOC4_4200L)
    #define Trasmitter_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Trasmitter_USBIO_DISABLE              ((uint32)(~Trasmitter_USBIO_ENABLE))
    #define Trasmitter_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Trasmitter_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Trasmitter_USBIO_ENTER_SLEEP          ((uint32)((1u << Trasmitter_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Trasmitter_USBIO_SUSPEND_DEL_SHIFT)))
    #define Trasmitter_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Trasmitter_USBIO_SUSPEND_SHIFT)))
    #define Trasmitter_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Trasmitter_USBIO_SUSPEND_DEL_SHIFT)))
    #define Trasmitter_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Trasmitter__PC)
    /* Port Configuration */
    #define Trasmitter_PC                 (* (reg32 *) Trasmitter__PC)
#endif
/* Pin State */
#define Trasmitter_PS                     (* (reg32 *) Trasmitter__PS)
/* Data Register */
#define Trasmitter_DR                     (* (reg32 *) Trasmitter__DR)
/* Input Buffer Disable Override */
#define Trasmitter_INP_DIS                (* (reg32 *) Trasmitter__PC2)

/* Interrupt configuration Registers */
#define Trasmitter_INTCFG                 (* (reg32 *) Trasmitter__INTCFG)
#define Trasmitter_INTSTAT                (* (reg32 *) Trasmitter__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Trasmitter_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Trasmitter__SIO)
    #define Trasmitter_SIO_REG            (* (reg32 *) Trasmitter__SIO)
#endif /* (Trasmitter__SIO_CFG) */

/* USBIO registers */
#if !defined(Trasmitter__PC) && (CY_PSOC4_4200L)
    #define Trasmitter_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Trasmitter_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Trasmitter_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Trasmitter_DRIVE_MODE_SHIFT       (0x00u)
#define Trasmitter_DRIVE_MODE_MASK        (0x07u << Trasmitter_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Trasmitter_H */


/* [] END OF FILE */
