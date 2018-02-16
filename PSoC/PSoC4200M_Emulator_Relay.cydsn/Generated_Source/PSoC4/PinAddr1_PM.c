/*******************************************************************************
* File Name: PinAddr1.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PinAddr1.h"

static PinAddr1_BACKUP_STRUCT  PinAddr1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PinAddr1_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet PinAddr1_SUT.c usage_PinAddr1_Sleep_Wakeup
*******************************************************************************/
void PinAddr1_Sleep(void)
{
    #if defined(PinAddr1__PC)
        PinAddr1_backup.pcState = PinAddr1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PinAddr1_backup.usbState = PinAddr1_CR1_REG;
            PinAddr1_USB_POWER_REG |= PinAddr1_USBIO_ENTER_SLEEP;
            PinAddr1_CR1_REG &= PinAddr1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PinAddr1__SIO)
        PinAddr1_backup.sioState = PinAddr1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PinAddr1_SIO_REG &= (uint32)(~PinAddr1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PinAddr1_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to PinAddr1_Sleep() for an example usage.
*******************************************************************************/
void PinAddr1_Wakeup(void)
{
    #if defined(PinAddr1__PC)
        PinAddr1_PC = PinAddr1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PinAddr1_USB_POWER_REG &= PinAddr1_USBIO_EXIT_SLEEP_PH1;
            PinAddr1_CR1_REG = PinAddr1_backup.usbState;
            PinAddr1_USB_POWER_REG &= PinAddr1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PinAddr1__SIO)
        PinAddr1_SIO_REG = PinAddr1_backup.sioState;
    #endif
}


/* [] END OF FILE */
