/*******************************************************************************
* File Name: Counter_1_PM.c
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

#include "Counter_1.h"

static Counter_1_BACKUP_STRUCT Counter_1_backup;


/*******************************************************************************
* Function Name: Counter_1_SaveConfig
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
void Counter_1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_1_Sleep
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
void Counter_1_Sleep(void)
{
    if(0u != (Counter_1_BLOCK_CONTROL_REG & Counter_1_MASK))
    {
        Counter_1_backup.enableState = 1u;
    }
    else
    {
        Counter_1_backup.enableState = 0u;
    }

    Counter_1_Stop();
    Counter_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_1_RestoreConfig
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
void Counter_1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Counter_1_Wakeup
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
void Counter_1_Wakeup(void)
{
    Counter_1_RestoreConfig();

    if(0u != Counter_1_backup.enableState)
    {
        Counter_1_Enable();
    }
}


/* [] END OF FILE */
