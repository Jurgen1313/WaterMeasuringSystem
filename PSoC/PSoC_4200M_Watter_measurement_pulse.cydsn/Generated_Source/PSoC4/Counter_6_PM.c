/*******************************************************************************
* File Name: Counter_6_PM.c
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

#include "Counter_6.h"

static Counter_6_BACKUP_STRUCT Counter_6_backup;


/*******************************************************************************
* Function Name: Counter_6_SaveConfig
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
void Counter_6_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_6_Sleep
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
void Counter_6_Sleep(void)
{
    if(0u != (Counter_6_BLOCK_CONTROL_REG & Counter_6_MASK))
    {
        Counter_6_backup.enableState = 1u;
    }
    else
    {
        Counter_6_backup.enableState = 0u;
    }

    Counter_6_Stop();
    Counter_6_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_6_RestoreConfig
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
void Counter_6_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_6_Wakeup
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
void Counter_6_Wakeup(void)
{
    Counter_6_RestoreConfig();

    if(0u != Counter_6_backup.enableState)
    {
        Counter_6_Enable();
    }
}


/* [] END OF FILE */
