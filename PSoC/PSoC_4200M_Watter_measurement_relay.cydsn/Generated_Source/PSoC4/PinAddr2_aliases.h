/*******************************************************************************
* File Name: PinAddr2.h  
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

#if !defined(CY_PINS_PinAddr2_ALIASES_H) /* Pins PinAddr2_ALIASES_H */
#define CY_PINS_PinAddr2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinAddr2_0			(PinAddr2__0__PC)
#define PinAddr2_0_PS		(PinAddr2__0__PS)
#define PinAddr2_0_PC		(PinAddr2__0__PC)
#define PinAddr2_0_DR		(PinAddr2__0__DR)
#define PinAddr2_0_SHIFT	(PinAddr2__0__SHIFT)
#define PinAddr2_0_INTR	((uint16)((uint16)0x0003u << (PinAddr2__0__SHIFT*2u)))

#define PinAddr2_INTR_ALL	 ((uint16)(PinAddr2_0_INTR))


#endif /* End Pins PinAddr2_ALIASES_H */


/* [] END OF FILE */
