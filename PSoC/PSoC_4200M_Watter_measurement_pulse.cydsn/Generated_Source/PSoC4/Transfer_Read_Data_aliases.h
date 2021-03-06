/*******************************************************************************
* File Name: Transfer_Read_Data.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Transfer_Read_Data_ALIASES_H) /* Pins Transfer_Read_Data_ALIASES_H */
#define CY_PINS_Transfer_Read_Data_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Transfer_Read_Data_0			(Transfer_Read_Data__0__PC)
#define Transfer_Read_Data_0_PS		(Transfer_Read_Data__0__PS)
#define Transfer_Read_Data_0_PC		(Transfer_Read_Data__0__PC)
#define Transfer_Read_Data_0_DR		(Transfer_Read_Data__0__DR)
#define Transfer_Read_Data_0_SHIFT	(Transfer_Read_Data__0__SHIFT)
#define Transfer_Read_Data_0_INTR	((uint16)((uint16)0x0003u << (Transfer_Read_Data__0__SHIFT*2u)))

#define Transfer_Read_Data_INTR_ALL	 ((uint16)(Transfer_Read_Data_0_INTR))


#endif /* End Pins Transfer_Read_Data_ALIASES_H */


/* [] END OF FILE */
