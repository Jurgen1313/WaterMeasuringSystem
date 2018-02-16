/*******************************************************************************
* File Name: Rs485_send.c  
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
#include "Rs485_send.h"

static Rs485_send_BACKUP_STRUCT  Rs485_send_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Rs485_send_Sleep
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
*  \snippet Rs485_send_SUT.c usage_Rs485_send_Sleep_Wakeup
*******************************************************************************/
void Rs485_send_Sleep(void)
{
    #if defined(Rs485_send__PC)
        Rs485_send_backup.pcState = Rs485_send_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Rs485_send_backup.usbState = Rs485_send_CR1_REG;
            Rs485_send_USB_POWER_REG |= Rs485_send_USBIO_ENTER_SLEEP;
            Rs485_send_CR1_REG &= Rs485_send_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Rs485_send__SIO)
        Rs485_send_backup.sioState = Rs485_send_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Rs485_send_SIO_REG &= (uint32)(~Rs485_send_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Rs485_send_Wakeup
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
*  Refer to Rs485_send_Sleep() for an example usage.
*******************************************************************************/
void Rs485_send_Wakeup(void)
{
    #if defined(Rs485_send__PC)
        Rs485_send_PC = Rs485_send_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Rs485_send_USB_POWER_REG &= Rs485_send_USBIO_EXIT_SLEEP_PH1;
            Rs485_send_CR1_REG = Rs485_send_backup.usbState;
            Rs485_send_USB_POWER_REG &= Rs485_send_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Rs485_send__SIO)
        Rs485_send_SIO_REG = Rs485_send_backup.sioState;
    #endif
}


/* [] END OF FILE */
