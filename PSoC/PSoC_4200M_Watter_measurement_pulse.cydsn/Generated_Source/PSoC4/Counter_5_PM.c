/*******************************************************************************
* File Name: Counter_5_PM.c
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

#include "Counter_5.h"

static Counter_5_BACKUP_STRUCT Counter_5_backup;


/*******************************************************************************
* Function Name: Counter_5_SaveConfig
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
void Counter_5_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_5_Sleep
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
void Counter_5_Sleep(void)
{
    if(0u != (Counter_5_BLOCK_CONTROL_REG & Counter_5_MASK))
    {
        Counter_5_backup.enableState = 1u;
    }
    else
    {
        Counter_5_backup.enableState = 0u;
    }

    Counter_5_Stop();
    Counter_5_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_5_RestoreConfig
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
void Counter_5_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_5_Wakeup
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
void Counter_5_Wakeup(void)
{
    Counter_5_RestoreConfig();

    if(0u != Counter_5_backup.enableState)
    {
        Counter_5_Enable();
    }
}


/* [] END OF FILE */
