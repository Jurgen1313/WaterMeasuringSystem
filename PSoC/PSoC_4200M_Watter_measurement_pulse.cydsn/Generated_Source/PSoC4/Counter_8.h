/*******************************************************************************
* File Name: Counter_8.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the Counter_8
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

#if !defined(CY_TCPWM_Counter_8_H)
#define CY_TCPWM_Counter_8_H


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
} Counter_8_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Counter_8_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Counter_8_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Counter_8_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Counter_8_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Counter_8_QUAD_ENCODING_MODES            (0lu)
#define Counter_8_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define Counter_8_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Counter_8_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Counter_8_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Counter_8_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Counter_8_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Counter_8_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Counter_8_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Counter_8_TC_RUN_MODE                    (0lu)
#define Counter_8_TC_COUNTER_MODE                (0lu)
#define Counter_8_TC_COMP_CAP_MODE               (2lu)
#define Counter_8_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Counter_8_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Counter_8_TC_COUNT_SIGNAL_MODE           (1lu)
#define Counter_8_TC_START_SIGNAL_MODE           (0lu)
#define Counter_8_TC_STOP_SIGNAL_MODE            (1lu)
#define Counter_8_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_8_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Counter_8_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define Counter_8_TC_START_SIGNAL_PRESENT        (0lu)
#define Counter_8_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Counter_8_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_8_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define Counter_8_PWM_KILL_EVENT                 (0lu)
#define Counter_8_PWM_STOP_EVENT                 (0lu)
#define Counter_8_PWM_MODE                       (4lu)
#define Counter_8_PWM_OUT_N_INVERT               (0lu)
#define Counter_8_PWM_OUT_INVERT                 (0lu)
#define Counter_8_PWM_ALIGN                      (0lu)
#define Counter_8_PWM_RUN_MODE                   (0lu)
#define Counter_8_PWM_DEAD_TIME_CYCLE            (0lu)
#define Counter_8_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Counter_8_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Counter_8_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Counter_8_PWM_START_SIGNAL_MODE          (0lu)
#define Counter_8_PWM_STOP_SIGNAL_MODE           (0lu)
#define Counter_8_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_8_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Counter_8_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Counter_8_PWM_START_SIGNAL_PRESENT       (0lu)
#define Counter_8_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Counter_8_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_8_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Counter_8_TC_PERIOD_VALUE                (65535lu)
#define Counter_8_TC_COMPARE_VALUE               (65535lu)
#define Counter_8_TC_COMPARE_BUF_VALUE           (65535lu)
#define Counter_8_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Counter_8_PWM_PERIOD_VALUE               (65535lu)
#define Counter_8_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Counter_8_PWM_PERIOD_SWAP                (0lu)
#define Counter_8_PWM_COMPARE_VALUE              (65535lu)
#define Counter_8_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Counter_8_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Counter_8__LEFT 0
#define Counter_8__RIGHT 1
#define Counter_8__CENTER 2
#define Counter_8__ASYMMETRIC 3

#define Counter_8__X1 0
#define Counter_8__X2 1
#define Counter_8__X4 2

#define Counter_8__PWM 4
#define Counter_8__PWM_DT 5
#define Counter_8__PWM_PR 6

#define Counter_8__INVERSE 1
#define Counter_8__DIRECT 0

#define Counter_8__CAPTURE 2
#define Counter_8__COMPARE 0

#define Counter_8__TRIG_LEVEL 3
#define Counter_8__TRIG_RISING 0
#define Counter_8__TRIG_FALLING 1
#define Counter_8__TRIG_BOTH 2

#define Counter_8__INTR_MASK_TC 1
#define Counter_8__INTR_MASK_CC_MATCH 2
#define Counter_8__INTR_MASK_NONE 0
#define Counter_8__INTR_MASK_TC_CC 3

#define Counter_8__UNCONFIG 8
#define Counter_8__TIMER 1
#define Counter_8__QUAD 3
#define Counter_8__PWM_SEL 7

#define Counter_8__COUNT_UP 0
#define Counter_8__COUNT_DOWN 1
#define Counter_8__COUNT_UPDOWN0 2
#define Counter_8__COUNT_UPDOWN1 3


/* Prescaler */
#define Counter_8_PRESCALE_DIVBY1                ((uint32)(0u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY2                ((uint32)(1u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY4                ((uint32)(2u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY8                ((uint32)(3u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY16               ((uint32)(4u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY32               ((uint32)(5u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY64               ((uint32)(6u << Counter_8_PRESCALER_SHIFT))
#define Counter_8_PRESCALE_DIVBY128              ((uint32)(7u << Counter_8_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Counter_8_MODE_TIMER_COMPARE             ((uint32)(Counter_8__COMPARE         <<  \
                                                                  Counter_8_MODE_SHIFT))
#define Counter_8_MODE_TIMER_CAPTURE             ((uint32)(Counter_8__CAPTURE         <<  \
                                                                  Counter_8_MODE_SHIFT))
#define Counter_8_MODE_QUAD                      ((uint32)(Counter_8__QUAD            <<  \
                                                                  Counter_8_MODE_SHIFT))
#define Counter_8_MODE_PWM                       ((uint32)(Counter_8__PWM             <<  \
                                                                  Counter_8_MODE_SHIFT))
#define Counter_8_MODE_PWM_DT                    ((uint32)(Counter_8__PWM_DT          <<  \
                                                                  Counter_8_MODE_SHIFT))
#define Counter_8_MODE_PWM_PR                    ((uint32)(Counter_8__PWM_PR          <<  \
                                                                  Counter_8_MODE_SHIFT))

/* Quad Modes */
#define Counter_8_MODE_X1                        ((uint32)(Counter_8__X1              <<  \
                                                                  Counter_8_QUAD_MODE_SHIFT))
#define Counter_8_MODE_X2                        ((uint32)(Counter_8__X2              <<  \
                                                                  Counter_8_QUAD_MODE_SHIFT))
#define Counter_8_MODE_X4                        ((uint32)(Counter_8__X4              <<  \
                                                                  Counter_8_QUAD_MODE_SHIFT))

/* Counter modes */
#define Counter_8_COUNT_UP                       ((uint32)(Counter_8__COUNT_UP        <<  \
                                                                  Counter_8_UPDOWN_SHIFT))
#define Counter_8_COUNT_DOWN                     ((uint32)(Counter_8__COUNT_DOWN      <<  \
                                                                  Counter_8_UPDOWN_SHIFT))
#define Counter_8_COUNT_UPDOWN0                  ((uint32)(Counter_8__COUNT_UPDOWN0   <<  \
                                                                  Counter_8_UPDOWN_SHIFT))
#define Counter_8_COUNT_UPDOWN1                  ((uint32)(Counter_8__COUNT_UPDOWN1   <<  \
                                                                  Counter_8_UPDOWN_SHIFT))

/* PWM output invert */
#define Counter_8_INVERT_LINE                    ((uint32)(Counter_8__INVERSE         <<  \
                                                                  Counter_8_INV_OUT_SHIFT))
#define Counter_8_INVERT_LINE_N                  ((uint32)(Counter_8__INVERSE         <<  \
                                                                  Counter_8_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Counter_8_TRIG_RISING                    ((uint32)Counter_8__TRIG_RISING)
#define Counter_8_TRIG_FALLING                   ((uint32)Counter_8__TRIG_FALLING)
#define Counter_8_TRIG_BOTH                      ((uint32)Counter_8__TRIG_BOTH)
#define Counter_8_TRIG_LEVEL                     ((uint32)Counter_8__TRIG_LEVEL)

/* Interrupt mask */
#define Counter_8_INTR_MASK_TC                   ((uint32)Counter_8__INTR_MASK_TC)
#define Counter_8_INTR_MASK_CC_MATCH             ((uint32)Counter_8__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Counter_8_CC_MATCH_SET                   (0x00u)
#define Counter_8_CC_MATCH_CLEAR                 (0x01u)
#define Counter_8_CC_MATCH_INVERT                (0x02u)
#define Counter_8_CC_MATCH_NO_CHANGE             (0x03u)
#define Counter_8_OVERLOW_SET                    (0x00u)
#define Counter_8_OVERLOW_CLEAR                  (0x04u)
#define Counter_8_OVERLOW_INVERT                 (0x08u)
#define Counter_8_OVERLOW_NO_CHANGE              (0x0Cu)
#define Counter_8_UNDERFLOW_SET                  (0x00u)
#define Counter_8_UNDERFLOW_CLEAR                (0x10u)
#define Counter_8_UNDERFLOW_INVERT               (0x20u)
#define Counter_8_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Counter_8_PWM_MODE_LEFT                  (Counter_8_CC_MATCH_CLEAR        |   \
                                                         Counter_8_OVERLOW_SET           |   \
                                                         Counter_8_UNDERFLOW_NO_CHANGE)
#define Counter_8_PWM_MODE_RIGHT                 (Counter_8_CC_MATCH_SET          |   \
                                                         Counter_8_OVERLOW_NO_CHANGE     |   \
                                                         Counter_8_UNDERFLOW_CLEAR)
#define Counter_8_PWM_MODE_ASYM                  (Counter_8_CC_MATCH_INVERT       |   \
                                                         Counter_8_OVERLOW_SET           |   \
                                                         Counter_8_UNDERFLOW_CLEAR)

#if (Counter_8_CY_TCPWM_V2)
    #if(Counter_8_CY_TCPWM_4000)
        #define Counter_8_PWM_MODE_CENTER                (Counter_8_CC_MATCH_INVERT       |   \
                                                                 Counter_8_OVERLOW_NO_CHANGE     |   \
                                                                 Counter_8_UNDERFLOW_CLEAR)
    #else
        #define Counter_8_PWM_MODE_CENTER                (Counter_8_CC_MATCH_INVERT       |   \
                                                                 Counter_8_OVERLOW_SET           |   \
                                                                 Counter_8_UNDERFLOW_CLEAR)
    #endif /* (Counter_8_CY_TCPWM_4000) */
#else
    #define Counter_8_PWM_MODE_CENTER                (Counter_8_CC_MATCH_INVERT       |   \
                                                             Counter_8_OVERLOW_NO_CHANGE     |   \
                                                             Counter_8_UNDERFLOW_CLEAR)
#endif /* (Counter_8_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Counter_8_CMD_CAPTURE                    (0u)
#define Counter_8_CMD_RELOAD                     (8u)
#define Counter_8_CMD_STOP                       (16u)
#define Counter_8_CMD_START                      (24u)

/* Status */
#define Counter_8_STATUS_DOWN                    (1u)
#define Counter_8_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Counter_8_Init(void);
void   Counter_8_Enable(void);
void   Counter_8_Start(void);
void   Counter_8_Stop(void);

void   Counter_8_SetMode(uint32 mode);
void   Counter_8_SetCounterMode(uint32 counterMode);
void   Counter_8_SetPWMMode(uint32 modeMask);
void   Counter_8_SetQDMode(uint32 qdMode);

void   Counter_8_SetPrescaler(uint32 prescaler);
void   Counter_8_TriggerCommand(uint32 mask, uint32 command);
void   Counter_8_SetOneShot(uint32 oneShotEnable);
uint32 Counter_8_ReadStatus(void);

void   Counter_8_SetPWMSyncKill(uint32 syncKillEnable);
void   Counter_8_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Counter_8_SetPWMDeadTime(uint32 deadTime);
void   Counter_8_SetPWMInvert(uint32 mask);

void   Counter_8_SetInterruptMode(uint32 interruptMask);
uint32 Counter_8_GetInterruptSourceMasked(void);
uint32 Counter_8_GetInterruptSource(void);
void   Counter_8_ClearInterrupt(uint32 interruptMask);
void   Counter_8_SetInterrupt(uint32 interruptMask);

void   Counter_8_WriteCounter(uint32 count);
uint32 Counter_8_ReadCounter(void);

uint32 Counter_8_ReadCapture(void);
uint32 Counter_8_ReadCaptureBuf(void);

void   Counter_8_WritePeriod(uint32 period);
uint32 Counter_8_ReadPeriod(void);
void   Counter_8_WritePeriodBuf(uint32 periodBuf);
uint32 Counter_8_ReadPeriodBuf(void);

void   Counter_8_WriteCompare(uint32 compare);
uint32 Counter_8_ReadCompare(void);
void   Counter_8_WriteCompareBuf(uint32 compareBuf);
uint32 Counter_8_ReadCompareBuf(void);

void   Counter_8_SetPeriodSwap(uint32 swapEnable);
void   Counter_8_SetCompareSwap(uint32 swapEnable);

void   Counter_8_SetCaptureMode(uint32 triggerMode);
void   Counter_8_SetReloadMode(uint32 triggerMode);
void   Counter_8_SetStartMode(uint32 triggerMode);
void   Counter_8_SetStopMode(uint32 triggerMode);
void   Counter_8_SetCountMode(uint32 triggerMode);

void   Counter_8_SaveConfig(void);
void   Counter_8_RestoreConfig(void);
void   Counter_8_Sleep(void);
void   Counter_8_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Counter_8_BLOCK_CONTROL_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_8_BLOCK_CONTROL_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_8_COMMAND_REG                    (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_8_COMMAND_PTR                    ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_8_INTRRUPT_CAUSE_REG             (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_8_INTRRUPT_CAUSE_PTR             ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_8_CONTROL_REG                    (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__CTRL )
#define Counter_8_CONTROL_PTR                    ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__CTRL )
#define Counter_8_STATUS_REG                     (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__STATUS )
#define Counter_8_STATUS_PTR                     ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__STATUS )
#define Counter_8_COUNTER_REG                    (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_8_COUNTER_PTR                    ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_8_COMP_CAP_REG                   (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__CC )
#define Counter_8_COMP_CAP_PTR                   ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__CC )
#define Counter_8_COMP_CAP_BUF_REG               (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_8_COMP_CAP_BUF_PTR               ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_8_PERIOD_REG                     (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_8_PERIOD_PTR                     ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_8_PERIOD_BUF_REG                 (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_8_PERIOD_BUF_PTR                 ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_8_TRIG_CONTROL0_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_8_TRIG_CONTROL0_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_8_TRIG_CONTROL1_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_8_TRIG_CONTROL1_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_8_TRIG_CONTROL2_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_8_TRIG_CONTROL2_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_8_INTERRUPT_REQ_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR )
#define Counter_8_INTERRUPT_REQ_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR )
#define Counter_8_INTERRUPT_SET_REG              (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_8_INTERRUPT_SET_PTR              ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_8_INTERRUPT_MASK_REG             (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_8_INTERRUPT_MASK_PTR             ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_8_INTERRUPT_MASKED_REG           (*(reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Counter_8_INTERRUPT_MASKED_PTR           ( (reg32 *) Counter_8_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Counter_8_MASK                           ((uint32)Counter_8_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Counter_8_RELOAD_CC_SHIFT                (0u)
#define Counter_8_RELOAD_PERIOD_SHIFT            (1u)
#define Counter_8_PWM_SYNC_KILL_SHIFT            (2u)
#define Counter_8_PWM_STOP_KILL_SHIFT            (3u)
#define Counter_8_PRESCALER_SHIFT                (8u)
#define Counter_8_UPDOWN_SHIFT                   (16u)
#define Counter_8_ONESHOT_SHIFT                  (18u)
#define Counter_8_QUAD_MODE_SHIFT                (20u)
#define Counter_8_INV_OUT_SHIFT                  (20u)
#define Counter_8_INV_COMPL_OUT_SHIFT            (21u)
#define Counter_8_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Counter_8_RELOAD_CC_MASK                 ((uint32)(Counter_8_1BIT_MASK        <<  \
                                                                            Counter_8_RELOAD_CC_SHIFT))
#define Counter_8_RELOAD_PERIOD_MASK             ((uint32)(Counter_8_1BIT_MASK        <<  \
                                                                            Counter_8_RELOAD_PERIOD_SHIFT))
#define Counter_8_PWM_SYNC_KILL_MASK             ((uint32)(Counter_8_1BIT_MASK        <<  \
                                                                            Counter_8_PWM_SYNC_KILL_SHIFT))
#define Counter_8_PWM_STOP_KILL_MASK             ((uint32)(Counter_8_1BIT_MASK        <<  \
                                                                            Counter_8_PWM_STOP_KILL_SHIFT))
#define Counter_8_PRESCALER_MASK                 ((uint32)(Counter_8_8BIT_MASK        <<  \
                                                                            Counter_8_PRESCALER_SHIFT))
#define Counter_8_UPDOWN_MASK                    ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                            Counter_8_UPDOWN_SHIFT))
#define Counter_8_ONESHOT_MASK                   ((uint32)(Counter_8_1BIT_MASK        <<  \
                                                                            Counter_8_ONESHOT_SHIFT))
#define Counter_8_QUAD_MODE_MASK                 ((uint32)(Counter_8_3BIT_MASK        <<  \
                                                                            Counter_8_QUAD_MODE_SHIFT))
#define Counter_8_INV_OUT_MASK                   ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                            Counter_8_INV_OUT_SHIFT))
#define Counter_8_MODE_MASK                      ((uint32)(Counter_8_3BIT_MASK        <<  \
                                                                            Counter_8_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Counter_8_CAPTURE_SHIFT                  (0u)
#define Counter_8_COUNT_SHIFT                    (2u)
#define Counter_8_RELOAD_SHIFT                   (4u)
#define Counter_8_STOP_SHIFT                     (6u)
#define Counter_8_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Counter_8_CAPTURE_MASK                   ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                  Counter_8_CAPTURE_SHIFT))
#define Counter_8_COUNT_MASK                     ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                  Counter_8_COUNT_SHIFT))
#define Counter_8_RELOAD_MASK                    ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                  Counter_8_RELOAD_SHIFT))
#define Counter_8_STOP_MASK                      ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                  Counter_8_STOP_SHIFT))
#define Counter_8_START_MASK                     ((uint32)(Counter_8_2BIT_MASK        <<  \
                                                                  Counter_8_START_SHIFT))

/* MASK */
#define Counter_8_1BIT_MASK                      ((uint32)0x01u)
#define Counter_8_2BIT_MASK                      ((uint32)0x03u)
#define Counter_8_3BIT_MASK                      ((uint32)0x07u)
#define Counter_8_6BIT_MASK                      ((uint32)0x3Fu)
#define Counter_8_8BIT_MASK                      ((uint32)0xFFu)
#define Counter_8_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Counter_8_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Counter_8_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Counter_8_QUAD_ENCODING_MODES     << Counter_8_QUAD_MODE_SHIFT))       |\
         ((uint32)(Counter_8_CONFIG                  << Counter_8_MODE_SHIFT)))

#define Counter_8_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Counter_8_PWM_STOP_EVENT          << Counter_8_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Counter_8_PWM_OUT_INVERT          << Counter_8_INV_OUT_SHIFT))         |\
         ((uint32)(Counter_8_PWM_OUT_N_INVERT        << Counter_8_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Counter_8_PWM_MODE                << Counter_8_MODE_SHIFT)))

#define Counter_8_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Counter_8_PWM_RUN_MODE         << Counter_8_ONESHOT_SHIFT))
            
#define Counter_8_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Counter_8_PWM_ALIGN            << Counter_8_UPDOWN_SHIFT))

#define Counter_8_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Counter_8_PWM_KILL_EVENT      << Counter_8_PWM_SYNC_KILL_SHIFT))

#define Counter_8_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Counter_8_PWM_DEAD_TIME_CYCLE  << Counter_8_PRESCALER_SHIFT))

#define Counter_8_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Counter_8_PWM_PRESCALER        << Counter_8_PRESCALER_SHIFT))

#define Counter_8_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Counter_8_TC_PRESCALER            << Counter_8_PRESCALER_SHIFT))       |\
         ((uint32)(Counter_8_TC_COUNTER_MODE         << Counter_8_UPDOWN_SHIFT))          |\
         ((uint32)(Counter_8_TC_RUN_MODE             << Counter_8_ONESHOT_SHIFT))         |\
         ((uint32)(Counter_8_TC_COMP_CAP_MODE        << Counter_8_MODE_SHIFT)))
        
#define Counter_8_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Counter_8_QUAD_PHIA_SIGNAL_MODE   << Counter_8_COUNT_SHIFT))           |\
         ((uint32)(Counter_8_QUAD_INDEX_SIGNAL_MODE  << Counter_8_RELOAD_SHIFT))          |\
         ((uint32)(Counter_8_QUAD_STOP_SIGNAL_MODE   << Counter_8_STOP_SHIFT))            |\
         ((uint32)(Counter_8_QUAD_PHIB_SIGNAL_MODE   << Counter_8_START_SHIFT)))

#define Counter_8_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Counter_8_PWM_SWITCH_SIGNAL_MODE  << Counter_8_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_8_PWM_COUNT_SIGNAL_MODE   << Counter_8_COUNT_SHIFT))           |\
         ((uint32)(Counter_8_PWM_RELOAD_SIGNAL_MODE  << Counter_8_RELOAD_SHIFT))          |\
         ((uint32)(Counter_8_PWM_STOP_SIGNAL_MODE    << Counter_8_STOP_SHIFT))            |\
         ((uint32)(Counter_8_PWM_START_SIGNAL_MODE   << Counter_8_START_SHIFT)))

#define Counter_8_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Counter_8_TC_CAPTURE_SIGNAL_MODE  << Counter_8_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_8_TC_COUNT_SIGNAL_MODE    << Counter_8_COUNT_SHIFT))           |\
         ((uint32)(Counter_8_TC_RELOAD_SIGNAL_MODE   << Counter_8_RELOAD_SHIFT))          |\
         ((uint32)(Counter_8_TC_STOP_SIGNAL_MODE     << Counter_8_STOP_SHIFT))            |\
         ((uint32)(Counter_8_TC_START_SIGNAL_MODE    << Counter_8_START_SHIFT)))
        
#define Counter_8_TIMER_UPDOWN_CNT_USED                                                          \
                ((Counter_8__COUNT_UPDOWN0 == Counter_8_TC_COUNTER_MODE)                  ||\
                 (Counter_8__COUNT_UPDOWN1 == Counter_8_TC_COUNTER_MODE))

#define Counter_8_PWM_UPDOWN_CNT_USED                                                            \
                ((Counter_8__CENTER == Counter_8_PWM_ALIGN)                               ||\
                 (Counter_8__ASYMMETRIC == Counter_8_PWM_ALIGN))               
        
#define Counter_8_PWM_PR_INIT_VALUE              (1u)
#define Counter_8_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Counter_8_H */

/* [] END OF FILE */
