/*******************************************************************************
* File Name: isrTimer7.h
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
#if !defined(CY_ISR_isrTimer7_H)
#define CY_ISR_isrTimer7_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrTimer7_Start(void);
void isrTimer7_StartEx(cyisraddress address);
void isrTimer7_Stop(void);

CY_ISR_PROTO(isrTimer7_Interrupt);

void isrTimer7_SetVector(cyisraddress address);
cyisraddress isrTimer7_GetVector(void);

void isrTimer7_SetPriority(uint8 priority);
uint8 isrTimer7_GetPriority(void);

void isrTimer7_Enable(void);
uint8 isrTimer7_GetState(void);
void isrTimer7_Disable(void);

void isrTimer7_SetPending(void);
void isrTimer7_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrTimer7 ISR. */
#define isrTimer7_INTC_VECTOR            ((reg32 *) isrTimer7__INTC_VECT)

/* Address of the isrTimer7 ISR priority. */
#define isrTimer7_INTC_PRIOR             ((reg32 *) isrTimer7__INTC_PRIOR_REG)

/* Priority of the isrTimer7 interrupt. */
#define isrTimer7_INTC_PRIOR_NUMBER      isrTimer7__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrTimer7 interrupt. */
#define isrTimer7_INTC_SET_EN            ((reg32 *) isrTimer7__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrTimer7 interrupt. */
#define isrTimer7_INTC_CLR_EN            ((reg32 *) isrTimer7__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrTimer7 interrupt state to pending. */
#define isrTimer7_INTC_SET_PD            ((reg32 *) isrTimer7__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrTimer7 interrupt. */
#define isrTimer7_INTC_CLR_PD            ((reg32 *) isrTimer7__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrTimer7_H */


/* [] END OF FILE */
