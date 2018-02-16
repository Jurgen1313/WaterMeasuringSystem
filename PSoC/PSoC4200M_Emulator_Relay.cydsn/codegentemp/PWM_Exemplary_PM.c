/*******************************************************************************
* File Name: PWM_Exemplary_PM.c
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

#include "PWM_Exemplary.h"

static PWM_Exemplary_BACKUP_STRUCT PWM_Exemplary_backup;


/*******************************************************************************
* Function Name: PWM_Exemplary_SaveConfig
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
void PWM_Exemplary_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Exemplary_Sleep
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
void PWM_Exemplary_Sleep(void)
{
    if(0u != (PWM_Exemplary_BLOCK_CONTROL_REG & PWM_Exemplary_MASK))
    {
        PWM_Exemplary_backup.enableState = 1u;
    }
    else
    {
        PWM_Exemplary_backup.enableState = 0u;
    }

    PWM_Exemplary_Stop();
    PWM_Exemplary_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Exemplary_RestoreConfig
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
void PWM_Exemplary_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Exemplary_Wakeup
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
void PWM_Exemplary_Wakeup(void)
{
    PWM_Exemplary_RestoreConfig();

    if(0u != PWM_Exemplary_backup.enableState)
    {
        PWM_Exemplary_Enable();
    }
}


/* [] END OF FILE */
