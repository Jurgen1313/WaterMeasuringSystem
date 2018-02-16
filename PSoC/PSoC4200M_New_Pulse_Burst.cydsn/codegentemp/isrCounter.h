/*******************************************************************************
* File Name: isrCounter.h
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
#if !defined(CY_ISR_isrCounter_H)
#define CY_ISR_isrCounter_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrCounter_Start(void);
void isrCounter_StartEx(cyisraddress address);
void isrCounter_Stop(void);

CY_ISR_PROTO(isrCounter_Interrupt);

void isrCounter_SetVector(cyisraddress address);
cyisraddress isrCounter_GetVector(void);

void isrCounter_SetPriority(uint8 priority);
uint8 isrCounter_GetPriority(void);

void isrCounter_Enable(void);
uint8 isrCounter_GetState(void);
void isrCounter_Disable(void);

void isrCounter_SetPending(void);
void isrCounter_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrCounter ISR. */
#define isrCounter_INTC_VECTOR            ((reg32 *) isrCounter__INTC_VECT)

/* Address of the isrCounter ISR priority. */
#define isrCounter_INTC_PRIOR             ((reg32 *) isrCounter__INTC_PRIOR_REG)

/* Priority of the isrCounter interrupt. */
#define isrCounter_INTC_PRIOR_NUMBER      isrCounter__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrCounter interrupt. */
#define isrCounter_INTC_SET_EN            ((reg32 *) isrCounter__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrCounter interrupt. */
#define isrCounter_INTC_CLR_EN            ((reg32 *) isrCounter__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrCounter interrupt state to pending. */
#define isrCounter_INTC_SET_PD            ((reg32 *) isrCounter__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrCounter interrupt. */
#define isrCounter_INTC_CLR_PD            ((reg32 *) isrCounter__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrCounter_H */


/* [] END OF FILE */
