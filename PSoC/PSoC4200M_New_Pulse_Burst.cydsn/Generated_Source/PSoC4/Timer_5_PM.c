/*******************************************************************************
* File Name: Timer_5_PM.c
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

#include "Timer_5.h"

static Timer_5_BACKUP_STRUCT Timer_5_backup;


/*******************************************************************************
* Function Name: Timer_5_SaveConfig
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
void Timer_5_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_5_Sleep
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
void Timer_5_Sleep(void)
{
    if(0u != (Timer_5_BLOCK_CONTROL_REG & Timer_5_MASK))
    {
        Timer_5_backup.enableState = 1u;
    }
    else
    {
        Timer_5_backup.enableState = 0u;
    }

    Timer_5_Stop();
    Timer_5_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_5_RestoreConfig
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
void Timer_5_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_5_Wakeup
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
void Timer_5_Wakeup(void)
{
    Timer_5_RestoreConfig();

    if(0u != Timer_5_backup.enableState)
    {
        Timer_5_Enable();
    }
}


/* [] END OF FILE */
