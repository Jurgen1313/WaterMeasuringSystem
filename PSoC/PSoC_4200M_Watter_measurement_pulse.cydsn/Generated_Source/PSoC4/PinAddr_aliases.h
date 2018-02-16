/*******************************************************************************
* File Name: PinAddr.h  
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

#if !defined(CY_PINS_PinAddr_ALIASES_H) /* Pins PinAddr_ALIASES_H */
#define CY_PINS_PinAddr_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinAddr_0			(PinAddr__0__PC)
#define PinAddr_0_PS		(PinAddr__0__PS)
#define PinAddr_0_PC		(PinAddr__0__PC)
#define PinAddr_0_DR		(PinAddr__0__DR)
#define PinAddr_0_SHIFT	(PinAddr__0__SHIFT)
#define PinAddr_0_INTR	((uint16)((uint16)0x0003u << (PinAddr__0__SHIFT*2u)))

#define PinAddr_1			(PinAddr__1__PC)
#define PinAddr_1_PS		(PinAddr__1__PS)
#define PinAddr_1_PC		(PinAddr__1__PC)
#define PinAddr_1_DR		(PinAddr__1__DR)
#define PinAddr_1_SHIFT	(PinAddr__1__SHIFT)
#define PinAddr_1_INTR	((uint16)((uint16)0x0003u << (PinAddr__1__SHIFT*2u)))

#define PinAddr_2			(PinAddr__2__PC)
#define PinAddr_2_PS		(PinAddr__2__PS)
#define PinAddr_2_PC		(PinAddr__2__PC)
#define PinAddr_2_DR		(PinAddr__2__DR)
#define PinAddr_2_SHIFT	(PinAddr__2__SHIFT)
#define PinAddr_2_INTR	((uint16)((uint16)0x0003u << (PinAddr__2__SHIFT*2u)))

#define PinAddr_3			(PinAddr__3__PC)
#define PinAddr_3_PS		(PinAddr__3__PS)
#define PinAddr_3_PC		(PinAddr__3__PC)
#define PinAddr_3_DR		(PinAddr__3__DR)
#define PinAddr_3_SHIFT	(PinAddr__3__SHIFT)
#define PinAddr_3_INTR	((uint16)((uint16)0x0003u << (PinAddr__3__SHIFT*2u)))

#define PinAddr_INTR_ALL	 ((uint16)(PinAddr_0_INTR| PinAddr_1_INTR| PinAddr_2_INTR| PinAddr_3_INTR))


#endif /* End Pins PinAddr_ALIASES_H */


/* [] END OF FILE */
