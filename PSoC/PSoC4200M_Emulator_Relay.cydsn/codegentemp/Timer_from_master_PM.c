/*******************************************************************************
* File Name: Timer_from_master_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_from_master.h"

static Timer_from_master_backupStruct Timer_from_master_backup;


/*******************************************************************************
* Function Name: Timer_from_master_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_from_master_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_from_master_SaveConfig(void) 
{
    #if (!Timer_from_master_UsingFixedFunction)
        Timer_from_master_backup.TimerUdb = Timer_from_master_ReadCounter();
        Timer_from_master_backup.InterruptMaskValue = Timer_from_master_STATUS_MASK;
        #if (Timer_from_master_UsingHWCaptureCounter)
            Timer_from_master_backup.TimerCaptureCounter = Timer_from_master_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_from_master_UDB_CONTROL_REG_REMOVED)
            Timer_from_master_backup.TimerControlRegister = Timer_from_master_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_from_master_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_from_master_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_from_master_RestoreConfig(void) 
{   
    #if (!Timer_from_master_UsingFixedFunction)

        Timer_from_master_WriteCounter(Timer_from_master_backup.TimerUdb);
        Timer_from_master_STATUS_MASK =Timer_from_master_backup.InterruptMaskValue;
        #if (Timer_from_master_UsingHWCaptureCounter)
            Timer_from_master_SetCaptureCount(Timer_from_master_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_from_master_UDB_CONTROL_REG_REMOVED)
            Timer_from_master_WriteControlRegister(Timer_from_master_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_from_master_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_from_master_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_from_master_Sleep(void) 
{
    #if(!Timer_from_master_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_from_master_CTRL_ENABLE == (Timer_from_master_CONTROL & Timer_from_master_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_from_master_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_from_master_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_from_master_Stop();
    Timer_from_master_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_from_master_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_from_master_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_from_master_Wakeup(void) 
{
    Timer_from_master_RestoreConfig();
    #if(!Timer_from_master_UDB_CONTROL_REG_REMOVED)
        if(Timer_from_master_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_from_master_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
