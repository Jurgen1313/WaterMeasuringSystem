/*******************************************************************************
* File Name: Channel_8.c  
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
#include "Channel_8.h"

static Channel_8_BACKUP_STRUCT  Channel_8_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Channel_8_Sleep
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
*  \snippet Channel_8_SUT.c usage_Channel_8_Sleep_Wakeup
*******************************************************************************/
void Channel_8_Sleep(void)
{
    #if defined(Channel_8__PC)
        Channel_8_backup.pcState = Channel_8_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Channel_8_backup.usbState = Channel_8_CR1_REG;
            Channel_8_USB_POWER_REG |= Channel_8_USBIO_ENTER_SLEEP;
            Channel_8_CR1_REG &= Channel_8_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Channel_8__SIO)
        Channel_8_backup.sioState = Channel_8_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Channel_8_SIO_REG &= (uint32)(~Channel_8_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Channel_8_Wakeup
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
*  Refer to Channel_8_Sleep() for an example usage.
*******************************************************************************/
void Channel_8_Wakeup(void)
{
    #if defined(Channel_8__PC)
        Channel_8_PC = Channel_8_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Channel_8_USB_POWER_REG &= Channel_8_USBIO_EXIT_SLEEP_PH1;
            Channel_8_CR1_REG = Channel_8_backup.usbState;
            Channel_8_USB_POWER_REG &= Channel_8_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Channel_8__SIO)
        Channel_8_SIO_REG = Channel_8_backup.sioState;
    #endif
}


/* [] END OF FILE */
