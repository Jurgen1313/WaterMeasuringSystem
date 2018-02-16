/*******************************************************************************
* File Name: PinAddr4.h  
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

#if !defined(CY_PINS_PinAddr4_ALIASES_H) /* Pins PinAddr4_ALIASES_H */
#define CY_PINS_PinAddr4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinAddr4_0			(PinAddr4__0__PC)
#define PinAddr4_0_PS		(PinAddr4__0__PS)
#define PinAddr4_0_PC		(PinAddr4__0__PC)
#define PinAddr4_0_DR		(PinAddr4__0__DR)
#define PinAddr4_0_SHIFT	(PinAddr4__0__SHIFT)
#define PinAddr4_0_INTR	((uint16)((uint16)0x0003u << (PinAddr4__0__SHIFT*2u)))

#define PinAddr4_INTR_ALL	 ((uint16)(PinAddr4_0_INTR))


#endif /* End Pins PinAddr4_ALIASES_H */


/* [] END OF FILE */
