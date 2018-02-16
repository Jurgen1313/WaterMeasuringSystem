/*******************************************************************************
* File Name: PWM_Output_Exemplary.h  
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

#if !defined(CY_PINS_PWM_Output_Exemplary_H) /* Pins PWM_Output_Exemplary_H */
#define CY_PINS_PWM_Output_Exemplary_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PWM_Output_Exemplary_aliases.h"


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
} PWM_Output_Exemplary_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PWM_Output_Exemplary_Read(void);
void    PWM_Output_Exemplary_Write(uint8 value);
uint8   PWM_Output_Exemplary_ReadDataReg(void);
#if defined(PWM_Output_Exemplary__PC) || (CY_PSOC4_4200L) 
    void    PWM_Output_Exemplary_SetDriveMode(uint8 mode);
#endif
void    PWM_Output_Exemplary_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWM_Output_Exemplary_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PWM_Output_Exemplary_Sleep(void); 
void PWM_Output_Exemplary_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PWM_Output_Exemplary__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PWM_Output_Exemplary_DRIVE_MODE_BITS        (3)
    #define PWM_Output_Exemplary_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PWM_Output_Exemplary_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PWM_Output_Exemplary_SetDriveMode() function.
         *  @{
         */
        #define PWM_Output_Exemplary_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PWM_Output_Exemplary_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PWM_Output_Exemplary_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PWM_Output_Exemplary_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PWM_Output_Exemplary_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PWM_Output_Exemplary_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PWM_Output_Exemplary_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PWM_Output_Exemplary_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PWM_Output_Exemplary_MASK               PWM_Output_Exemplary__MASK
#define PWM_Output_Exemplary_SHIFT              PWM_Output_Exemplary__SHIFT
#define PWM_Output_Exemplary_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWM_Output_Exemplary_SetInterruptMode() function.
     *  @{
     */
        #define PWM_Output_Exemplary_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PWM_Output_Exemplary_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PWM_Output_Exemplary_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PWM_Output_Exemplary_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PWM_Output_Exemplary__SIO)
    #define PWM_Output_Exemplary_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PWM_Output_Exemplary__PC) && (CY_PSOC4_4200L)
    #define PWM_Output_Exemplary_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PWM_Output_Exemplary_USBIO_DISABLE              ((uint32)(~PWM_Output_Exemplary_USBIO_ENABLE))
    #define PWM_Output_Exemplary_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PWM_Output_Exemplary_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PWM_Output_Exemplary_USBIO_ENTER_SLEEP          ((uint32)((1u << PWM_Output_Exemplary_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PWM_Output_Exemplary_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWM_Output_Exemplary_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PWM_Output_Exemplary_USBIO_SUSPEND_SHIFT)))
    #define PWM_Output_Exemplary_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PWM_Output_Exemplary_USBIO_SUSPEND_DEL_SHIFT)))
    #define PWM_Output_Exemplary_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PWM_Output_Exemplary__PC)
    /* Port Configuration */
    #define PWM_Output_Exemplary_PC                 (* (reg32 *) PWM_Output_Exemplary__PC)
#endif
/* Pin State */
#define PWM_Output_Exemplary_PS                     (* (reg32 *) PWM_Output_Exemplary__PS)
/* Data Register */
#define PWM_Output_Exemplary_DR                     (* (reg32 *) PWM_Output_Exemplary__DR)
/* Input Buffer Disable Override */
#define PWM_Output_Exemplary_INP_DIS                (* (reg32 *) PWM_Output_Exemplary__PC2)

/* Interrupt configuration Registers */
#define PWM_Output_Exemplary_INTCFG                 (* (reg32 *) PWM_Output_Exemplary__INTCFG)
#define PWM_Output_Exemplary_INTSTAT                (* (reg32 *) PWM_Output_Exemplary__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PWM_Output_Exemplary_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PWM_Output_Exemplary__SIO)
    #define PWM_Output_Exemplary_SIO_REG            (* (reg32 *) PWM_Output_Exemplary__SIO)
#endif /* (PWM_Output_Exemplary__SIO_CFG) */

/* USBIO registers */
#if !defined(PWM_Output_Exemplary__PC) && (CY_PSOC4_4200L)
    #define PWM_Output_Exemplary_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PWM_Output_Exemplary_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PWM_Output_Exemplary_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PWM_Output_Exemplary_DRIVE_MODE_SHIFT       (0x00u)
#define PWM_Output_Exemplary_DRIVE_MODE_MASK        (0x07u << PWM_Output_Exemplary_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PWM_Output_Exemplary_H */


/* [] END OF FILE */
