/*******************************************************************************
* File Name: PWM_6_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_6.h"

static PWM_6_BACKUP_STRUCT PWM_6_backup;


/*******************************************************************************
* Function Name: PWM_6_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_6_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_6_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_6_Sleep(void)
{
    if(0u != (PWM_6_BLOCK_CONTROL_REG & PWM_6_MASK))
    {
        PWM_6_backup.enableState = 1u;
    }
    else
    {
        PWM_6_backup.enableState = 0u;
    }

    PWM_6_Stop();
    PWM_6_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_6_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_6_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_6_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_6_Wakeup(void)
{
    PWM_6_RestoreConfig();

    if(0u != PWM_6_backup.enableState)
    {
        PWM_6_Enable();
    }
}


/* [] END OF FILE */
