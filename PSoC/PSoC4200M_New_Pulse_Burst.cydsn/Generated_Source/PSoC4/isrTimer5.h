/*******************************************************************************
* File Name: isrTimer5.h
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
#if !defined(CY_ISR_isrTimer5_H)
#define CY_ISR_isrTimer5_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrTimer5_Start(void);
void isrTimer5_StartEx(cyisraddress address);
void isrTimer5_Stop(void);

CY_ISR_PROTO(isrTimer5_Interrupt);

void isrTimer5_SetVector(cyisraddress address);
cyisraddress isrTimer5_GetVector(void);

void isrTimer5_SetPriority(uint8 priority);
uint8 isrTimer5_GetPriority(void);

void isrTimer5_Enable(void);
uint8 isrTimer5_GetState(void);
void isrTimer5_Disable(void);

void isrTimer5_SetPending(void);
void isrTimer5_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrTimer5 ISR. */
#define isrTimer5_INTC_VECTOR            ((reg32 *) isrTimer5__INTC_VECT)

/* Address of the isrTimer5 ISR priority. */
#define isrTimer5_INTC_PRIOR             ((reg32 *) isrTimer5__INTC_PRIOR_REG)

/* Priority of the isrTimer5 interrupt. */
#define isrTimer5_INTC_PRIOR_NUMBER      isrTimer5__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrTimer5 interrupt. */
#define isrTimer5_INTC_SET_EN            ((reg32 *) isrTimer5__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrTimer5 interrupt. */
#define isrTimer5_INTC_CLR_EN            ((reg32 *) isrTimer5__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrTimer5 interrupt state to pending. */
#define isrTimer5_INTC_SET_PD            ((reg32 *) isrTimer5__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrTimer5 interrupt. */
#define isrTimer5_INTC_CLR_PD            ((reg32 *) isrTimer5__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrTimer5_H */


/* [] END OF FILE */
