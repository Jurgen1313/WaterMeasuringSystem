/*******************************************************************************
* File Name: Trasmitter.h  
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

#if !defined(CY_PINS_Trasmitter_ALIASES_H) /* Pins Trasmitter_ALIASES_H */
#define CY_PINS_Trasmitter_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Trasmitter_0			(Trasmitter__0__PC)
#define Trasmitter_0_PS		(Trasmitter__0__PS)
#define Trasmitter_0_PC		(Trasmitter__0__PC)
#define Trasmitter_0_DR		(Trasmitter__0__DR)
#define Trasmitter_0_SHIFT	(Trasmitter__0__SHIFT)
#define Trasmitter_0_INTR	((uint16)((uint16)0x0003u << (Trasmitter__0__SHIFT*2u)))

#define Trasmitter_INTR_ALL	 ((uint16)(Trasmitter_0_INTR))


#endif /* End Pins Trasmitter_ALIASES_H */


/* [] END OF FILE */
