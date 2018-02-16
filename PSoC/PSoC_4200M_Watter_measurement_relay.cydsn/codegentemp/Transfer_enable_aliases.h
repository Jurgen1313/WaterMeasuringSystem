/*******************************************************************************
* File Name: Transfer_enable.h  
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

#if !defined(CY_PINS_Transfer_enable_ALIASES_H) /* Pins Transfer_enable_ALIASES_H */
#define CY_PINS_Transfer_enable_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Transfer_enable_0			(Transfer_enable__0__PC)
#define Transfer_enable_0_PS		(Transfer_enable__0__PS)
#define Transfer_enable_0_PC		(Transfer_enable__0__PC)
#define Transfer_enable_0_DR		(Transfer_enable__0__DR)
#define Transfer_enable_0_SHIFT	(Transfer_enable__0__SHIFT)
#define Transfer_enable_0_INTR	((uint16)((uint16)0x0003u << (Transfer_enable__0__SHIFT*2u)))

#define Transfer_enable_INTR_ALL	 ((uint16)(Transfer_enable_0_INTR))


#endif /* End Pins Transfer_enable_ALIASES_H */


/* [] END OF FILE */
