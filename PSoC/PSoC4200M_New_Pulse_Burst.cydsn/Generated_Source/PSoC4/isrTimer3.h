/*******************************************************************************
* File Name: isrTimer3.h
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
#if !defined(CY_ISR_isrTimer3_H)
#define CY_ISR_isrTimer3_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrTimer3_Start(void);
void isrTimer3_StartEx(cyisraddress address);
void isrTimer3_Stop(void);

CY_ISR_PROTO(isrTimer3_Interrupt);

void isrTimer3_SetVector(cyisraddress address);
cyisraddress isrTimer3_GetVector(void);

void isrTimer3_SetPriority(uint8 priority);
uint8 isrTimer3_GetPriority(void);

void isrTimer3_Enable(void);
uint8 isrTimer3_GetState(void);
void isrTimer3_Disable(void);

void isrTimer3_SetPending(void);
void isrTimer3_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrTimer3 ISR. */
#define isrTimer3_INTC_VECTOR            ((reg32 *) isrTimer3__INTC_VECT)

/* Address of the isrTimer3 ISR priority. */
#define isrTimer3_INTC_PRIOR             ((reg32 *) isrTimer3__INTC_PRIOR_REG)

/* Priority of the isrTimer3 interrupt. */
#define isrTimer3_INTC_PRIOR_NUMBER      isrTimer3__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrTimer3 interrupt. */
#define isrTimer3_INTC_SET_EN            ((reg32 *) isrTimer3__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrTimer3 interrupt. */
#define isrTimer3_INTC_CLR_EN            ((reg32 *) isrTimer3__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrTimer3 interrupt state to pending. */
#define isrTimer3_INTC_SET_PD            ((reg32 *) isrTimer3__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrTimer3 interrupt. */
#define isrTimer3_INTC_CLR_PD            ((reg32 *) isrTimer3__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrTimer3_H */


/* [] END OF FILE */
