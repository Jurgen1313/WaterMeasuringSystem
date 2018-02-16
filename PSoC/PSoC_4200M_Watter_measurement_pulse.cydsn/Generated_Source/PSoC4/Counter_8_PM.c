/*******************************************************************************
* File Name: Counter_8_PM.c
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

#include "Counter_8.h"

static Counter_8_BACKUP_STRUCT Counter_8_backup;


/*******************************************************************************
* Function Name: Counter_8_SaveConfig
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
void Counter_8_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_8_Sleep
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
void Counter_8_Sleep(void)
{
    if(0u != (Counter_8_BLOCK_CONTROL_REG & Counter_8_MASK))
    {
        Counter_8_backup.enableState = 1u;
    }
    else
    {
        Counter_8_backup.enableState = 0u;
    }

    Counter_8_Stop();
    Counter_8_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_8_RestoreConfig
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
void Counter_8_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_8_Wakeup
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
void Counter_8_Wakeup(void)
{
    Counter_8_RestoreConfig();

    if(0u != Counter_8_backup.enableState)
    {
        Counter_8_Enable();
    }
}


/* [] END OF FILE */
