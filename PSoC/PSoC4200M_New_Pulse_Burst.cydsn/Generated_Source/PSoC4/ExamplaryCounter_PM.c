/*******************************************************************************
* File Name: ExamplaryCounter_PM.c
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

#include "ExamplaryCounter.h"

static ExamplaryCounter_BACKUP_STRUCT ExamplaryCounter_backup;


/*******************************************************************************
* Function Name: ExamplaryCounter_SaveConfig
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
void ExamplaryCounter_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: ExamplaryCounter_Sleep
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
void ExamplaryCounter_Sleep(void)
{
    if(0u != (ExamplaryCounter_BLOCK_CONTROL_REG & ExamplaryCounter_MASK))
    {
        ExamplaryCounter_backup.enableState = 1u;
    }
    else
    {
        ExamplaryCounter_backup.enableState = 0u;
    }

    ExamplaryCounter_Stop();
    ExamplaryCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: ExamplaryCounter_RestoreConfig
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
void ExamplaryCounter_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: ExamplaryCounter_Wakeup
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
void ExamplaryCounter_Wakeup(void)
{
    ExamplaryCounter_RestoreConfig();

    if(0u != ExamplaryCounter_backup.enableState)
    {
        ExamplaryCounter_Enable();
    }
}


/* [] END OF FILE */
