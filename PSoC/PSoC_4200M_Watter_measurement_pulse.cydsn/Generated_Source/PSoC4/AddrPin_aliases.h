/*******************************************************************************
* File Name: AddrPin.h  
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

#if !defined(CY_PINS_AddrPin_ALIASES_H) /* Pins AddrPin_ALIASES_H */
#define CY_PINS_AddrPin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define AddrPin_0			(AddrPin__0__PC)
#define AddrPin_0_PS		(AddrPin__0__PS)
#define AddrPin_0_PC		(AddrPin__0__PC)
#define AddrPin_0_DR		(AddrPin__0__DR)
#define AddrPin_0_SHIFT	(AddrPin__0__SHIFT)
#define AddrPin_0_INTR	((uint16)((uint16)0x0003u << (AddrPin__0__SHIFT*2u)))

#define AddrPin_1			(AddrPin__1__PC)
#define AddrPin_1_PS		(AddrPin__1__PS)
#define AddrPin_1_PC		(AddrPin__1__PC)
#define AddrPin_1_DR		(AddrPin__1__DR)
#define AddrPin_1_SHIFT	(AddrPin__1__SHIFT)
#define AddrPin_1_INTR	((uint16)((uint16)0x0003u << (AddrPin__1__SHIFT*2u)))

#define AddrPin_2			(AddrPin__2__PC)
#define AddrPin_2_PS		(AddrPin__2__PS)
#define AddrPin_2_PC		(AddrPin__2__PC)
#define AddrPin_2_DR		(AddrPin__2__DR)
#define AddrPin_2_SHIFT	(AddrPin__2__SHIFT)
#define AddrPin_2_INTR	((uint16)((uint16)0x0003u << (AddrPin__2__SHIFT*2u)))

#define AddrPin_3			(AddrPin__3__PC)
#define AddrPin_3_PS		(AddrPin__3__PS)
#define AddrPin_3_PC		(AddrPin__3__PC)
#define AddrPin_3_DR		(AddrPin__3__DR)
#define AddrPin_3_SHIFT	(AddrPin__3__SHIFT)
#define AddrPin_3_INTR	((uint16)((uint16)0x0003u << (AddrPin__3__SHIFT*2u)))

#define AddrPin_INTR_ALL	 ((uint16)(AddrPin_0_INTR| AddrPin_1_INTR| AddrPin_2_INTR| AddrPin_3_INTR))


#endif /* End Pins AddrPin_ALIASES_H */


/* [] END OF FILE */
