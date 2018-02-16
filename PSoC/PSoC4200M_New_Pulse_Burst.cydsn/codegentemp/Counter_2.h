/*******************************************************************************
* File Name: Counter_2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the Counter_2
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_Counter_2_H)
#define CY_TCPWM_Counter_2_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Counter_2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Counter_2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Counter_2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Counter_2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Counter_2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Counter_2_QUAD_ENCODING_MODES            (0lu)
#define Counter_2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define Counter_2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Counter_2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Counter_2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Counter_2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Counter_2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Counter_2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Counter_2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Counter_2_TC_RUN_MODE                    (1lu)
#define Counter_2_TC_COUNTER_MODE                (0lu)
#define Counter_2_TC_COMP_CAP_MODE               (2lu)
#define Counter_2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Counter_2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Counter_2_TC_COUNT_SIGNAL_MODE           (3lu)
#define Counter_2_TC_START_SIGNAL_MODE           (0lu)
#define Counter_2_TC_STOP_SIGNAL_MODE            (1lu)
#define Counter_2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_2_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Counter_2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Counter_2_TC_START_SIGNAL_PRESENT        (0lu)
#define Counter_2_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Counter_2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Counter_2_PWM_KILL_EVENT                 (0lu)
#define Counter_2_PWM_STOP_EVENT                 (0lu)
#define Counter_2_PWM_MODE                       (4lu)
#define Counter_2_PWM_OUT_N_INVERT               (0lu)
#define Counter_2_PWM_OUT_INVERT                 (0lu)
#define Counter_2_PWM_ALIGN                      (0lu)
#define Counter_2_PWM_RUN_MODE                   (0lu)
#define Counter_2_PWM_DEAD_TIME_CYCLE            (0lu)
#define Counter_2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Counter_2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Counter_2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Counter_2_PWM_START_SIGNAL_MODE          (0lu)
#define Counter_2_PWM_STOP_SIGNAL_MODE           (0lu)
#define Counter_2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Counter_2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Counter_2_PWM_START_SIGNAL_PRESENT       (0lu)
#define Counter_2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Counter_2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Counter_2_TC_PERIOD_VALUE                (65535lu)
#define Counter_2_TC_COMPARE_VALUE               (65535lu)
#define Counter_2_TC_COMPARE_BUF_VALUE           (65535lu)
#define Counter_2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Counter_2_PWM_PERIOD_VALUE               (65535lu)
#define Counter_2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Counter_2_PWM_PERIOD_SWAP                (0lu)
#define Counter_2_PWM_COMPARE_VALUE              (65535lu)
#define Counter_2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Counter_2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Counter_2__LEFT 0
#define Counter_2__RIGHT 1
#define Counter_2__CENTER 2
#define Counter_2__ASYMMETRIC 3

#define Counter_2__X1 0
#define Counter_2__X2 1
#define Counter_2__X4 2

#define Counter_2__PWM 4
#define Counter_2__PWM_DT 5
#define Counter_2__PWM_PR 6

#define Counter_2__INVERSE 1
#define Counter_2__DIRECT 0

#define Counter_2__CAPTURE 2
#define Counter_2__COMPARE 0

#define Counter_2__TRIG_LEVEL 3
#define Counter_2__TRIG_RISING 0
#define Counter_2__TRIG_FALLING 1
#define Counter_2__TRIG_BOTH 2

#define Counter_2__INTR_MASK_TC 1
#define Counter_2__INTR_MASK_CC_MATCH 2
#define Counter_2__INTR_MASK_NONE 0
#define Counter_2__INTR_MASK_TC_CC 3

#define Counter_2__UNCONFIG 8
#define Counter_2__TIMER 1
#define Counter_2__QUAD 3
#define Counter_2__PWM_SEL 7

#define Counter_2__COUNT_UP 0
#define Counter_2__COUNT_DOWN 1
#define Counter_2__COUNT_UPDOWN0 2
#define Counter_2__COUNT_UPDOWN1 3


/* Prescaler */
#define Counter_2_PRESCALE_DIVBY1                ((uint32)(0u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY2                ((uint32)(1u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY4                ((uint32)(2u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY8                ((uint32)(3u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY16               ((uint32)(4u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY32               ((uint32)(5u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY64               ((uint32)(6u << Counter_2_PRESCALER_SHIFT))
#define Counter_2_PRESCALE_DIVBY128              ((uint32)(7u << Counter_2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Counter_2_MODE_TIMER_COMPARE             ((uint32)(Counter_2__COMPARE         <<  \
                                                                  Counter_2_MODE_SHIFT))
#define Counter_2_MODE_TIMER_CAPTURE             ((uint32)(Counter_2__CAPTURE         <<  \
                                                                  Counter_2_MODE_SHIFT))
#define Counter_2_MODE_QUAD                      ((uint32)(Counter_2__QUAD            <<  \
                                                                  Counter_2_MODE_SHIFT))
#define Counter_2_MODE_PWM                       ((uint32)(Counter_2__PWM             <<  \
                                                                  Counter_2_MODE_SHIFT))
#define Counter_2_MODE_PWM_DT                    ((uint32)(Counter_2__PWM_DT          <<  \
                                                                  Counter_2_MODE_SHIFT))
#define Counter_2_MODE_PWM_PR                    ((uint32)(Counter_2__PWM_PR          <<  \
                                                                  Counter_2_MODE_SHIFT))

/* Quad Modes */
#define Counter_2_MODE_X1                        ((uint32)(Counter_2__X1              <<  \
                                                                  Counter_2_QUAD_MODE_SHIFT))
#define Counter_2_MODE_X2                        ((uint32)(Counter_2__X2              <<  \
                                                                  Counter_2_QUAD_MODE_SHIFT))
#define Counter_2_MODE_X4                        ((uint32)(Counter_2__X4              <<  \
                                                                  Counter_2_QUAD_MODE_SHIFT))

/* Counter modes */
#define Counter_2_COUNT_UP                       ((uint32)(Counter_2__COUNT_UP        <<  \
                                                                  Counter_2_UPDOWN_SHIFT))
#define Counter_2_COUNT_DOWN                     ((uint32)(Counter_2__COUNT_DOWN      <<  \
                                                                  Counter_2_UPDOWN_SHIFT))
#define Counter_2_COUNT_UPDOWN0                  ((uint32)(Counter_2__COUNT_UPDOWN0   <<  \
                                                                  Counter_2_UPDOWN_SHIFT))
#define Counter_2_COUNT_UPDOWN1                  ((uint32)(Counter_2__COUNT_UPDOWN1   <<  \
                                                                  Counter_2_UPDOWN_SHIFT))

/* PWM output invert */
#define Counter_2_INVERT_LINE                    ((uint32)(Counter_2__INVERSE         <<  \
                                                                  Counter_2_INV_OUT_SHIFT))
#define Counter_2_INVERT_LINE_N                  ((uint32)(Counter_2__INVERSE         <<  \
                                                                  Counter_2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Counter_2_TRIG_RISING                    ((uint32)Counter_2__TRIG_RISING)
#define Counter_2_TRIG_FALLING                   ((uint32)Counter_2__TRIG_FALLING)
#define Counter_2_TRIG_BOTH                      ((uint32)Counter_2__TRIG_BOTH)
#define Counter_2_TRIG_LEVEL                     ((uint32)Counter_2__TRIG_LEVEL)

/* Interrupt mask */
#define Counter_2_INTR_MASK_TC                   ((uint32)Counter_2__INTR_MASK_TC)
#define Counter_2_INTR_MASK_CC_MATCH             ((uint32)Counter_2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Counter_2_CC_MATCH_SET                   (0x00u)
#define Counter_2_CC_MATCH_CLEAR                 (0x01u)
#define Counter_2_CC_MATCH_INVERT                (0x02u)
#define Counter_2_CC_MATCH_NO_CHANGE             (0x03u)
#define Counter_2_OVERLOW_SET                    (0x00u)
#define Counter_2_OVERLOW_CLEAR                  (0x04u)
#define Counter_2_OVERLOW_INVERT                 (0x08u)
#define Counter_2_OVERLOW_NO_CHANGE              (0x0Cu)
#define Counter_2_UNDERFLOW_SET                  (0x00u)
#define Counter_2_UNDERFLOW_CLEAR                (0x10u)
#define Counter_2_UNDERFLOW_INVERT               (0x20u)
#define Counter_2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Counter_2_PWM_MODE_LEFT                  (Counter_2_CC_MATCH_CLEAR        |   \
                                                         Counter_2_OVERLOW_SET           |   \
                                                         Counter_2_UNDERFLOW_NO_CHANGE)
#define Counter_2_PWM_MODE_RIGHT                 (Counter_2_CC_MATCH_SET          |   \
                                                         Counter_2_OVERLOW_NO_CHANGE     |   \
                                                         Counter_2_UNDERFLOW_CLEAR)
#define Counter_2_PWM_MODE_ASYM                  (Counter_2_CC_MATCH_INVERT       |   \
                                                         Counter_2_OVERLOW_SET           |   \
                                                         Counter_2_UNDERFLOW_CLEAR)

#if (Counter_2_CY_TCPWM_V2)
    #if(Counter_2_CY_TCPWM_4000)
        #define Counter_2_PWM_MODE_CENTER                (Counter_2_CC_MATCH_INVERT       |   \
                                                                 Counter_2_OVERLOW_NO_CHANGE     |   \
                                                                 Counter_2_UNDERFLOW_CLEAR)
    #else
        #define Counter_2_PWM_MODE_CENTER                (Counter_2_CC_MATCH_INVERT       |   \
                                                                 Counter_2_OVERLOW_SET           |   \
                                                                 Counter_2_UNDERFLOW_CLEAR)
    #endif /* (Counter_2_CY_TCPWM_4000) */
#else
    #define Counter_2_PWM_MODE_CENTER                (Counter_2_CC_MATCH_INVERT       |   \
                                                             Counter_2_OVERLOW_NO_CHANGE     |   \
                                                             Counter_2_UNDERFLOW_CLEAR)
#endif /* (Counter_2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Counter_2_CMD_CAPTURE                    (0u)
#define Counter_2_CMD_RELOAD                     (8u)
#define Counter_2_CMD_STOP                       (16u)
#define Counter_2_CMD_START                      (24u)

/* Status */
#define Counter_2_STATUS_DOWN                    (1u)
#define Counter_2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Counter_2_Init(void);
void   Counter_2_Enable(void);
void   Counter_2_Start(void);
void   Counter_2_Stop(void);

void   Counter_2_SetMode(uint32 mode);
void   Counter_2_SetCounterMode(uint32 counterMode);
void   Counter_2_SetPWMMode(uint32 modeMask);
void   Counter_2_SetQDMode(uint32 qdMode);

void   Counter_2_SetPrescaler(uint32 prescaler);
void   Counter_2_TriggerCommand(uint32 mask, uint32 command);
void   Counter_2_SetOneShot(uint32 oneShotEnable);
uint32 Counter_2_ReadStatus(void);

void   Counter_2_SetPWMSyncKill(uint32 syncKillEnable);
void   Counter_2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Counter_2_SetPWMDeadTime(uint32 deadTime);
void   Counter_2_SetPWMInvert(uint32 mask);

void   Counter_2_SetInterruptMode(uint32 interruptMask);
uint32 Counter_2_GetInterruptSourceMasked(void);
uint32 Counter_2_GetInterruptSource(void);
void   Counter_2_ClearInterrupt(uint32 interruptMask);
void   Counter_2_SetInterrupt(uint32 interruptMask);

void   Counter_2_WriteCounter(uint32 count);
uint32 Counter_2_ReadCounter(void);

uint32 Counter_2_ReadCapture(void);
uint32 Counter_2_ReadCaptureBuf(void);

void   Counter_2_WritePeriod(uint32 period);
uint32 Counter_2_ReadPeriod(void);
void   Counter_2_WritePeriodBuf(uint32 periodBuf);
uint32 Counter_2_ReadPeriodBuf(void);

void   Counter_2_WriteCompare(uint32 compare);
uint32 Counter_2_ReadCompare(void);
void   Counter_2_WriteCompareBuf(uint32 compareBuf);
uint32 Counter_2_ReadCompareBuf(void);

void   Counter_2_SetPeriodSwap(uint32 swapEnable);
void   Counter_2_SetCompareSwap(uint32 swapEnable);

void   Counter_2_SetCaptureMode(uint32 triggerMode);
void   Counter_2_SetReloadMode(uint32 triggerMode);
void   Counter_2_SetStartMode(uint32 triggerMode);
void   Counter_2_SetStopMode(uint32 triggerMode);
void   Counter_2_SetCountMode(uint32 triggerMode);

void   Counter_2_SaveConfig(void);
void   Counter_2_RestoreConfig(void);
void   Counter_2_Sleep(void);
void   Counter_2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Counter_2_BLOCK_CONTROL_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_2_BLOCK_CONTROL_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_2_COMMAND_REG                    (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_2_COMMAND_PTR                    ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_2_INTRRUPT_CAUSE_REG             (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_2_INTRRUPT_CAUSE_PTR             ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_2_CONTROL_REG                    (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__CTRL )
#define Counter_2_CONTROL_PTR                    ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__CTRL )
#define Counter_2_STATUS_REG                     (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__STATUS )
#define Counter_2_STATUS_PTR                     ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__STATUS )
#define Counter_2_COUNTER_REG                    (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_2_COUNTER_PTR                    ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_2_COMP_CAP_REG                   (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__CC )
#define Counter_2_COMP_CAP_PTR                   ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__CC )
#define Counter_2_COMP_CAP_BUF_REG               (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_2_COMP_CAP_BUF_PTR               ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_2_PERIOD_REG                     (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_2_PERIOD_PTR                     ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_2_PERIOD_BUF_REG                 (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_2_PERIOD_BUF_PTR                 ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_2_TRIG_CONTROL0_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_2_TRIG_CONTROL0_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_2_TRIG_CONTROL1_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_2_TRIG_CONTROL1_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_2_TRIG_CONTROL2_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_2_TRIG_CONTROL2_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_2_INTERRUPT_REQ_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR )
#define Counter_2_INTERRUPT_REQ_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR )
#define Counter_2_INTERRUPT_SET_REG              (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_2_INTERRUPT_SET_PTR              ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_2_INTERRUPT_MASK_REG             (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_2_INTERRUPT_MASK_PTR             ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_2_INTERRUPT_MASKED_REG           (*(reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Counter_2_INTERRUPT_MASKED_PTR           ( (reg32 *) Counter_2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Counter_2_MASK                           ((uint32)Counter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Counter_2_RELOAD_CC_SHIFT                (0u)
#define Counter_2_RELOAD_PERIOD_SHIFT            (1u)
#define Counter_2_PWM_SYNC_KILL_SHIFT            (2u)
#define Counter_2_PWM_STOP_KILL_SHIFT            (3u)
#define Counter_2_PRESCALER_SHIFT                (8u)
#define Counter_2_UPDOWN_SHIFT                   (16u)
#define Counter_2_ONESHOT_SHIFT                  (18u)
#define Counter_2_QUAD_MODE_SHIFT                (20u)
#define Counter_2_INV_OUT_SHIFT                  (20u)
#define Counter_2_INV_COMPL_OUT_SHIFT            (21u)
#define Counter_2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Counter_2_RELOAD_CC_MASK                 ((uint32)(Counter_2_1BIT_MASK        <<  \
                                                                            Counter_2_RELOAD_CC_SHIFT))
#define Counter_2_RELOAD_PERIOD_MASK             ((uint32)(Counter_2_1BIT_MASK        <<  \
                                                                            Counter_2_RELOAD_PERIOD_SHIFT))
#define Counter_2_PWM_SYNC_KILL_MASK             ((uint32)(Counter_2_1BIT_MASK        <<  \
                                                                            Counter_2_PWM_SYNC_KILL_SHIFT))
#define Counter_2_PWM_STOP_KILL_MASK             ((uint32)(Counter_2_1BIT_MASK        <<  \
                                                                            Counter_2_PWM_STOP_KILL_SHIFT))
#define Counter_2_PRESCALER_MASK                 ((uint32)(Counter_2_8BIT_MASK        <<  \
                                                                            Counter_2_PRESCALER_SHIFT))
#define Counter_2_UPDOWN_MASK                    ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                            Counter_2_UPDOWN_SHIFT))
#define Counter_2_ONESHOT_MASK                   ((uint32)(Counter_2_1BIT_MASK        <<  \
                                                                            Counter_2_ONESHOT_SHIFT))
#define Counter_2_QUAD_MODE_MASK                 ((uint32)(Counter_2_3BIT_MASK        <<  \
                                                                            Counter_2_QUAD_MODE_SHIFT))
#define Counter_2_INV_OUT_MASK                   ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                            Counter_2_INV_OUT_SHIFT))
#define Counter_2_MODE_MASK                      ((uint32)(Counter_2_3BIT_MASK        <<  \
                                                                            Counter_2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Counter_2_CAPTURE_SHIFT                  (0u)
#define Counter_2_COUNT_SHIFT                    (2u)
#define Counter_2_RELOAD_SHIFT                   (4u)
#define Counter_2_STOP_SHIFT                     (6u)
#define Counter_2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Counter_2_CAPTURE_MASK                   ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                  Counter_2_CAPTURE_SHIFT))
#define Counter_2_COUNT_MASK                     ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                  Counter_2_COUNT_SHIFT))
#define Counter_2_RELOAD_MASK                    ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                  Counter_2_RELOAD_SHIFT))
#define Counter_2_STOP_MASK                      ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                  Counter_2_STOP_SHIFT))
#define Counter_2_START_MASK                     ((uint32)(Counter_2_2BIT_MASK        <<  \
                                                                  Counter_2_START_SHIFT))

/* MASK */
#define Counter_2_1BIT_MASK                      ((uint32)0x01u)
#define Counter_2_2BIT_MASK                      ((uint32)0x03u)
#define Counter_2_3BIT_MASK                      ((uint32)0x07u)
#define Counter_2_6BIT_MASK                      ((uint32)0x3Fu)
#define Counter_2_8BIT_MASK                      ((uint32)0xFFu)
#define Counter_2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Counter_2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Counter_2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Counter_2_QUAD_ENCODING_MODES     << Counter_2_QUAD_MODE_SHIFT))       |\
         ((uint32)(Counter_2_CONFIG                  << Counter_2_MODE_SHIFT)))

#define Counter_2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Counter_2_PWM_STOP_EVENT          << Counter_2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Counter_2_PWM_OUT_INVERT          << Counter_2_INV_OUT_SHIFT))         |\
         ((uint32)(Counter_2_PWM_OUT_N_INVERT        << Counter_2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Counter_2_PWM_MODE                << Counter_2_MODE_SHIFT)))

#define Counter_2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Counter_2_PWM_RUN_MODE         << Counter_2_ONESHOT_SHIFT))
            
#define Counter_2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Counter_2_PWM_ALIGN            << Counter_2_UPDOWN_SHIFT))

#define Counter_2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Counter_2_PWM_KILL_EVENT      << Counter_2_PWM_SYNC_KILL_SHIFT))

#define Counter_2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Counter_2_PWM_DEAD_TIME_CYCLE  << Counter_2_PRESCALER_SHIFT))

#define Counter_2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Counter_2_PWM_PRESCALER        << Counter_2_PRESCALER_SHIFT))

#define Counter_2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Counter_2_TC_PRESCALER            << Counter_2_PRESCALER_SHIFT))       |\
         ((uint32)(Counter_2_TC_COUNTER_MODE         << Counter_2_UPDOWN_SHIFT))          |\
         ((uint32)(Counter_2_TC_RUN_MODE             << Counter_2_ONESHOT_SHIFT))         |\
         ((uint32)(Counter_2_TC_COMP_CAP_MODE        << Counter_2_MODE_SHIFT)))
        
#define Counter_2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Counter_2_QUAD_PHIA_SIGNAL_MODE   << Counter_2_COUNT_SHIFT))           |\
         ((uint32)(Counter_2_QUAD_INDEX_SIGNAL_MODE  << Counter_2_RELOAD_SHIFT))          |\
         ((uint32)(Counter_2_QUAD_STOP_SIGNAL_MODE   << Counter_2_STOP_SHIFT))            |\
         ((uint32)(Counter_2_QUAD_PHIB_SIGNAL_MODE   << Counter_2_START_SHIFT)))

#define Counter_2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Counter_2_PWM_SWITCH_SIGNAL_MODE  << Counter_2_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_2_PWM_COUNT_SIGNAL_MODE   << Counter_2_COUNT_SHIFT))           |\
         ((uint32)(Counter_2_PWM_RELOAD_SIGNAL_MODE  << Counter_2_RELOAD_SHIFT))          |\
         ((uint32)(Counter_2_PWM_STOP_SIGNAL_MODE    << Counter_2_STOP_SHIFT))            |\
         ((uint32)(Counter_2_PWM_START_SIGNAL_MODE   << Counter_2_START_SHIFT)))

#define Counter_2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Counter_2_TC_CAPTURE_SIGNAL_MODE  << Counter_2_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_2_TC_COUNT_SIGNAL_MODE    << Counter_2_COUNT_SHIFT))           |\
         ((uint32)(Counter_2_TC_RELOAD_SIGNAL_MODE   << Counter_2_RELOAD_SHIFT))          |\
         ((uint32)(Counter_2_TC_STOP_SIGNAL_MODE     << Counter_2_STOP_SHIFT))            |\
         ((uint32)(Counter_2_TC_START_SIGNAL_MODE    << Counter_2_START_SHIFT)))
        
#define Counter_2_TIMER_UPDOWN_CNT_USED                                                          \
                ((Counter_2__COUNT_UPDOWN0 == Counter_2_TC_COUNTER_MODE)                  ||\
                 (Counter_2__COUNT_UPDOWN1 == Counter_2_TC_COUNTER_MODE))

#define Counter_2_PWM_UPDOWN_CNT_USED                                                            \
                ((Counter_2__CENTER == Counter_2_PWM_ALIGN)                               ||\
                 (Counter_2__ASYMMETRIC == Counter_2_PWM_ALIGN))               
        
#define Counter_2_PWM_PR_INIT_VALUE              (1u)
#define Counter_2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Counter_2_H */

/* [] END OF FILE */
