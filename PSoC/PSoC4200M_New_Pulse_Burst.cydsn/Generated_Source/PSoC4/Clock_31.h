/*******************************************************************************
* File Name: Clock_31.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_31_H)
#define CY_CLOCK_Clock_31_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock_31_StartEx(uint32 alignClkDiv);
#define Clock_31_Start() \
    Clock_31_StartEx(Clock_31__PA_DIV_ID)

#else

void Clock_31_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock_31_Stop(void);

void Clock_31_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock_31_GetDividerRegister(void);
uint8  Clock_31_GetFractionalDividerRegister(void);

#define Clock_31_Enable()                         Clock_31_Start()
#define Clock_31_Disable()                        Clock_31_Stop()
#define Clock_31_SetDividerRegister(clkDivider, reset)  \
    Clock_31_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock_31_SetDivider(clkDivider)           Clock_31_SetDividerRegister((clkDivider), 1u)
#define Clock_31_SetDividerValue(clkDivider)      Clock_31_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock_31_DIV_ID     Clock_31__DIV_ID

#define Clock_31_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock_31_CTRL_REG   (*(reg32 *)Clock_31__CTRL_REGISTER)
#define Clock_31_DIV_REG    (*(reg32 *)Clock_31__DIV_REGISTER)

#define Clock_31_CMD_DIV_SHIFT          (0u)
#define Clock_31_CMD_PA_DIV_SHIFT       (8u)
#define Clock_31_CMD_DISABLE_SHIFT      (30u)
#define Clock_31_CMD_ENABLE_SHIFT       (31u)

#define Clock_31_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock_31_CMD_DISABLE_SHIFT))
#define Clock_31_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock_31_CMD_ENABLE_SHIFT))

#define Clock_31_DIV_FRAC_MASK  (0x000000F8u)
#define Clock_31_DIV_FRAC_SHIFT (3u)
#define Clock_31_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock_31_DIV_INT_SHIFT  (8u)

#else 

#define Clock_31_DIV_REG        (*(reg32 *)Clock_31__REGISTER)
#define Clock_31_ENABLE_REG     Clock_31_DIV_REG
#define Clock_31_DIV_FRAC_MASK  Clock_31__FRAC_MASK
#define Clock_31_DIV_FRAC_SHIFT (16u)
#define Clock_31_DIV_INT_MASK   Clock_31__DIVIDER_MASK
#define Clock_31_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock_31_H) */

/* [] END OF FILE */
