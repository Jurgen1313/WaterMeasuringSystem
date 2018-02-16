/*******************************************************************************
* File Name: Timer_6_PM.c
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

#include "Timer_6.h"

static Timer_6_BACKUP_STRUCT Timer_6_backup;


/*******************************************************************************
* Function Name: Timer_6_SaveConfig
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
void Timer_6_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_6_Sleep
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
void Timer_6_Sleep(void)
{
    if(0u != (Timer_6_BLOCK_CONTROL_REG & Timer_6_MASK))
    {
        Timer_6_backup.enableState = 1u;
    }
    else
    {
        Timer_6_backup.enableState = 0u;
    }

    Timer_6_Stop();
    Timer_6_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_6_RestoreConfig
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
void Timer_6_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_6_Wakeup
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
void Timer_6_Wakeup(void)
{
    Timer_6_RestoreConfig();

    if(0u != Timer_6_backup.enableState)
    {
        Timer_6_Enable();
    }
}


/* [] END OF FILE */
