/*******************************************************************************
* File Name: Channel_8.h  
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

#if !defined(CY_PINS_Channel_8_ALIASES_H) /* Pins Channel_8_ALIASES_H */
#define CY_PINS_Channel_8_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Channel_8_0			(Channel_8__0__PC)
#define Channel_8_0_PS		(Channel_8__0__PS)
#define Channel_8_0_PC		(Channel_8__0__PC)
#define Channel_8_0_DR		(Channel_8__0__DR)
#define Channel_8_0_SHIFT	(Channel_8__0__SHIFT)
#define Channel_8_0_INTR	((uint16)((uint16)0x0003u << (Channel_8__0__SHIFT*2u)))

#define Channel_8_INTR_ALL	 ((uint16)(Channel_8_0_INTR))


#endif /* End Pins Channel_8_ALIASES_H */


/* [] END OF FILE */
