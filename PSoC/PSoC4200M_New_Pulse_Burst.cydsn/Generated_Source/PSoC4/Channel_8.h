/*******************************************************************************
* File Name: Channel_8.h  
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

#if !defined(CY_PINS_Channel_8_H) /* Pins Channel_8_H */
#define CY_PINS_Channel_8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Channel_8_aliases.h"


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
} Channel_8_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Channel_8_Read(void);
void    Channel_8_Write(uint8 value);
uint8   Channel_8_ReadDataReg(void);
#if defined(Channel_8__PC) || (CY_PSOC4_4200L) 
    void    Channel_8_SetDriveMode(uint8 mode);
#endif
void    Channel_8_SetInterruptMode(uint16 position, uint16 mode);
uint8   Channel_8_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Channel_8_Sleep(void); 
void Channel_8_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Channel_8__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Channel_8_DRIVE_MODE_BITS        (3)
    #define Channel_8_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Channel_8_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Channel_8_SetDriveMode() function.
         *  @{
         */
        #define Channel_8_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Channel_8_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Channel_8_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Channel_8_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Channel_8_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Channel_8_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Channel_8_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Channel_8_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Channel_8_MASK               Channel_8__MASK
#define Channel_8_SHIFT              Channel_8__SHIFT
#define Channel_8_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Channel_8_SetInterruptMode() function.
     *  @{
     */
        #define Channel_8_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Channel_8_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Channel_8_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Channel_8_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Channel_8__SIO)
    #define Channel_8_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Channel_8__PC) && (CY_PSOC4_4200L)
    #define Channel_8_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Channel_8_USBIO_DISABLE              ((uint32)(~Channel_8_USBIO_ENABLE))
    #define Channel_8_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Channel_8_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Channel_8_USBIO_ENTER_SLEEP          ((uint32)((1u << Channel_8_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Channel_8_USBIO_SUSPEND_DEL_SHIFT)))
    #define Channel_8_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Channel_8_USBIO_SUSPEND_SHIFT)))
    #define Channel_8_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Channel_8_USBIO_SUSPEND_DEL_SHIFT)))
    #define Channel_8_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Channel_8__PC)
    /* Port Configuration */
    #define Channel_8_PC                 (* (reg32 *) Channel_8__PC)
#endif
/* Pin State */
#define Channel_8_PS                     (* (reg32 *) Channel_8__PS)
/* Data Register */
#define Channel_8_DR                     (* (reg32 *) Channel_8__DR)
/* Input Buffer Disable Override */
#define Channel_8_INP_DIS                (* (reg32 *) Channel_8__PC2)

/* Interrupt configuration Registers */
#define Channel_8_INTCFG                 (* (reg32 *) Channel_8__INTCFG)
#define Channel_8_INTSTAT                (* (reg32 *) Channel_8__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Channel_8_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Channel_8__SIO)
    #define Channel_8_SIO_REG            (* (reg32 *) Channel_8__SIO)
#endif /* (Channel_8__SIO_CFG) */

/* USBIO registers */
#if !defined(Channel_8__PC) && (CY_PSOC4_4200L)
    #define Channel_8_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Channel_8_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Channel_8_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Channel_8_DRIVE_MODE_SHIFT       (0x00u)
#define Channel_8_DRIVE_MODE_MASK        (0x07u << Channel_8_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Channel_8_H */


/* [] END OF FILE */
