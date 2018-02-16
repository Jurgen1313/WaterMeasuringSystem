/*******************************************************************************
* File Name: isrTimer6.h
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
#if !defined(CY_ISR_isrTimer6_H)
#define CY_ISR_isrTimer6_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrTimer6_Start(void);
void isrTimer6_StartEx(cyisraddress address);
void isrTimer6_Stop(void);

CY_ISR_PROTO(isrTimer6_Interrupt);

void isrTimer6_SetVector(cyisraddress address);
cyisraddress isrTimer6_GetVector(void);

void isrTimer6_SetPriority(uint8 priority);
uint8 isrTimer6_GetPriority(void);

void isrTimer6_Enable(void);
uint8 isrTimer6_GetState(void);
void isrTimer6_Disable(void);

void isrTimer6_SetPending(void);
void isrTimer6_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrTimer6 ISR. */
#define isrTimer6_INTC_VECTOR            ((reg32 *) isrTimer6__INTC_VECT)

/* Address of the isrTimer6 ISR priority. */
#define isrTimer6_INTC_PRIOR             ((reg32 *) isrTimer6__INTC_PRIOR_REG)

/* Priority of the isrTimer6 interrupt. */
#define isrTimer6_INTC_PRIOR_NUMBER      isrTimer6__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrTimer6 interrupt. */
#define isrTimer6_INTC_SET_EN            ((reg32 *) isrTimer6__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrTimer6 interrupt. */
#define isrTimer6_INTC_CLR_EN            ((reg32 *) isrTimer6__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrTimer6 interrupt state to pending. */
#define isrTimer6_INTC_SET_PD            ((reg32 *) isrTimer6__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrTimer6 interrupt. */
#define isrTimer6_INTC_CLR_PD            ((reg32 *) isrTimer6__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrTimer6_H */


/* [] END OF FILE */
