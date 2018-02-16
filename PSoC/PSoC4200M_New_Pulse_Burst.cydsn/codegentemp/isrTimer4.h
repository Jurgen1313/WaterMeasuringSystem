/*******************************************************************************
* File Name: isrTimer4.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrTimer4_H)
#define CY_ISR_isrTimer4_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrTimer4_Start(void);
void isrTimer4_StartEx(cyisraddress address);
void isrTimer4_Stop(void);

CY_ISR_PROTO(isrTimer4_Interrupt);

void isrTimer4_SetVector(cyisraddress address);
cyisraddress isrTimer4_GetVector(void);

void isrTimer4_SetPriority(uint8 priority);
uint8 isrTimer4_GetPriority(void);

void isrTimer4_Enable(void);
uint8 isrTimer4_GetState(void);
void isrTimer4_Disable(void);

void isrTimer4_SetPending(void);
void isrTimer4_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrTimer4 ISR. */
#define isrTimer4_INTC_VECTOR            ((reg32 *) isrTimer4__INTC_VECT)

/* Address of the isrTimer4 ISR priority. */
#define isrTimer4_INTC_PRIOR             ((reg32 *) isrTimer4__INTC_PRIOR_REG)

/* Priority of the isrTimer4 interrupt. */
#define isrTimer4_INTC_PRIOR_NUMBER      isrTimer4__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrTimer4 interrupt. */
#define isrTimer4_INTC_SET_EN            ((reg32 *) isrTimer4__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrTimer4 interrupt. */
#define isrTimer4_INTC_CLR_EN            ((reg32 *) isrTimer4__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrTimer4 interrupt state to pending. */
#define isrTimer4_INTC_SET_PD            ((reg32 *) isrTimer4__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrTimer4 interrupt. */
#define isrTimer4_INTC_CLR_PD            ((reg32 *) isrTimer4__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrTimer4_H */


/* [] END OF FILE */
