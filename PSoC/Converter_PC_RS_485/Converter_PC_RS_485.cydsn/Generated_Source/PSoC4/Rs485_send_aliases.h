/*******************************************************************************
* File Name: Rs485_send.h  
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

#if !defined(CY_PINS_Rs485_send_ALIASES_H) /* Pins Rs485_send_ALIASES_H */
#define CY_PINS_Rs485_send_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Rs485_send_0			(Rs485_send__0__PC)
#define Rs485_send_0_PS		(Rs485_send__0__PS)
#define Rs485_send_0_PC		(Rs485_send__0__PC)
#define Rs485_send_0_DR		(Rs485_send__0__DR)
#define Rs485_send_0_SHIFT	(Rs485_send__0__SHIFT)
#define Rs485_send_0_INTR	((uint16)((uint16)0x0003u << (Rs485_send__0__SHIFT*2u)))

#define Rs485_send_INTR_ALL	 ((uint16)(Rs485_send_0_INTR))


#endif /* End Pins Rs485_send_ALIASES_H */


/* [] END OF FILE */
