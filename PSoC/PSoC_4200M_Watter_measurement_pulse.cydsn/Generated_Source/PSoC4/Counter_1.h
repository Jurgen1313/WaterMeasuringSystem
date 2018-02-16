/*******************************************************************************
* File Name: Counter_1.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the Counter_1
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

#if !defined(CY_TCPWM_Counter_1_H)
#define CY_TCPWM_Counter_1_H


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
} Counter_1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Counter_1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Counter_1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Counter_1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Counter_1_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Counter_1_QUAD_ENCODING_MODES            (0lu)
#define Counter_1_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define Counter_1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Counter_1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Counter_1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Counter_1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Counter_1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Counter_1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Counter_1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Counter_1_TC_RUN_MODE                    (0lu)
#define Counter_1_TC_COUNTER_MODE                (1lu)
#define Counter_1_TC_COMP_CAP_MODE               (2lu)
#define Counter_1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Counter_1_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Counter_1_TC_COUNT_SIGNAL_MODE           (1lu)
#define Counter_1_TC_START_SIGNAL_MODE           (0lu)
#define Counter_1_TC_STOP_SIGNAL_MODE            (1lu)
#define Counter_1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Counter_1_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define Counter_1_TC_START_SIGNAL_PRESENT        (0lu)
#define Counter_1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Counter_1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Counter_1_PWM_KILL_EVENT                 (0lu)
#define Counter_1_PWM_STOP_EVENT                 (0lu)
#define Counter_1_PWM_MODE                       (4lu)
#define Counter_1_PWM_OUT_N_INVERT               (0lu)
#define Counter_1_PWM_OUT_INVERT                 (0lu)
#define Counter_1_PWM_ALIGN                      (0lu)
#define Counter_1_PWM_RUN_MODE                   (0lu)
#define Counter_1_PWM_DEAD_TIME_CYCLE            (0lu)
#define Counter_1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Counter_1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Counter_1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Counter_1_PWM_START_SIGNAL_MODE          (0lu)
#define Counter_1_PWM_STOP_SIGNAL_MODE           (0lu)
#define Counter_1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Counter_1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Counter_1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Counter_1_PWM_START_SIGNAL_PRESENT       (0lu)
#define Counter_1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Counter_1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Counter_1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Counter_1_TC_PERIOD_VALUE                (65534lu)
#define Counter_1_TC_COMPARE_VALUE               (65535lu)
#define Counter_1_TC_COMPARE_BUF_VALUE           (65535lu)
#define Counter_1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Counter_1_PWM_PERIOD_VALUE               (65535lu)
#define Counter_1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Counter_1_PWM_PERIOD_SWAP                (0lu)
#define Counter_1_PWM_COMPARE_VALUE              (65535lu)
#define Counter_1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Counter_1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Counter_1__LEFT 0
#define Counter_1__RIGHT 1
#define Counter_1__CENTER 2
#define Counter_1__ASYMMETRIC 3

#define Counter_1__X1 0
#define Counter_1__X2 1
#define Counter_1__X4 2

#define Counter_1__PWM 4
#define Counter_1__PWM_DT 5
#define Counter_1__PWM_PR 6

#define Counter_1__INVERSE 1
#define Counter_1__DIRECT 0

#define Counter_1__CAPTURE 2
#define Counter_1__COMPARE 0

#define Counter_1__TRIG_LEVEL 3
#define Counter_1__TRIG_RISING 0
#define Counter_1__TRIG_FALLING 1
#define Counter_1__TRIG_BOTH 2

#define Counter_1__INTR_MASK_TC 1
#define Counter_1__INTR_MASK_CC_MATCH 2
#define Counter_1__INTR_MASK_NONE 0
#define Counter_1__INTR_MASK_TC_CC 3

#define Counter_1__UNCONFIG 8
#define Counter_1__TIMER 1
#define Counter_1__QUAD 3
#define Counter_1__PWM_SEL 7

#define Counter_1__COUNT_UP 0
#define Counter_1__COUNT_DOWN 1
#define Counter_1__COUNT_UPDOWN0 2
#define Counter_1__COUNT_UPDOWN1 3


/* Prescaler */
#define Counter_1_PRESCALE_DIVBY1                ((uint32)(0u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY2                ((uint32)(1u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY4                ((uint32)(2u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY8                ((uint32)(3u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY16               ((uint32)(4u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY32               ((uint32)(5u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY64               ((uint32)(6u << Counter_1_PRESCALER_SHIFT))
#define Counter_1_PRESCALE_DIVBY128              ((uint32)(7u << Counter_1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Counter_1_MODE_TIMER_COMPARE             ((uint32)(Counter_1__COMPARE         <<  \
                                                                  Counter_1_MODE_SHIFT))
#define Counter_1_MODE_TIMER_CAPTURE             ((uint32)(Counter_1__CAPTURE         <<  \
                                                                  Counter_1_MODE_SHIFT))
#define Counter_1_MODE_QUAD                      ((uint32)(Counter_1__QUAD            <<  \
                                                                  Counter_1_MODE_SHIFT))
#define Counter_1_MODE_PWM                       ((uint32)(Counter_1__PWM             <<  \
                                                                  Counter_1_MODE_SHIFT))
#define Counter_1_MODE_PWM_DT                    ((uint32)(Counter_1__PWM_DT          <<  \
                                                                  Counter_1_MODE_SHIFT))
#define Counter_1_MODE_PWM_PR                    ((uint32)(Counter_1__PWM_PR          <<  \
                                                                  Counter_1_MODE_SHIFT))

/* Quad Modes */
#define Counter_1_MODE_X1                        ((uint32)(Counter_1__X1              <<  \
                                                                  Counter_1_QUAD_MODE_SHIFT))
#define Counter_1_MODE_X2                        ((uint32)(Counter_1__X2              <<  \
                                                                  Counter_1_QUAD_MODE_SHIFT))
#define Counter_1_MODE_X4                        ((uint32)(Counter_1__X4              <<  \
                                                                  Counter_1_QUAD_MODE_SHIFT))

/* Counter modes */
#define Counter_1_COUNT_UP                       ((uint32)(Counter_1__COUNT_UP        <<  \
                                                                  Counter_1_UPDOWN_SHIFT))
#define Counter_1_COUNT_DOWN                     ((uint32)(Counter_1__COUNT_DOWN      <<  \
                                                                  Counter_1_UPDOWN_SHIFT))
#define Counter_1_COUNT_UPDOWN0                  ((uint32)(Counter_1__COUNT_UPDOWN0   <<  \
                                                                  Counter_1_UPDOWN_SHIFT))
#define Counter_1_COUNT_UPDOWN1                  ((uint32)(Counter_1__COUNT_UPDOWN1   <<  \
                                                                  Counter_1_UPDOWN_SHIFT))

/* PWM output invert */
#define Counter_1_INVERT_LINE                    ((uint32)(Counter_1__INVERSE         <<  \
                                                                  Counter_1_INV_OUT_SHIFT))
#define Counter_1_INVERT_LINE_N                  ((uint32)(Counter_1__INVERSE         <<  \
                                                                  Counter_1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Counter_1_TRIG_RISING                    ((uint32)Counter_1__TRIG_RISING)
#define Counter_1_TRIG_FALLING                   ((uint32)Counter_1__TRIG_FALLING)
#define Counter_1_TRIG_BOTH                      ((uint32)Counter_1__TRIG_BOTH)
#define Counter_1_TRIG_LEVEL                     ((uint32)Counter_1__TRIG_LEVEL)

/* Interrupt mask */
#define Counter_1_INTR_MASK_TC                   ((uint32)Counter_1__INTR_MASK_TC)
#define Counter_1_INTR_MASK_CC_MATCH             ((uint32)Counter_1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Counter_1_CC_MATCH_SET                   (0x00u)
#define Counter_1_CC_MATCH_CLEAR                 (0x01u)
#define Counter_1_CC_MATCH_INVERT                (0x02u)
#define Counter_1_CC_MATCH_NO_CHANGE             (0x03u)
#define Counter_1_OVERLOW_SET                    (0x00u)
#define Counter_1_OVERLOW_CLEAR                  (0x04u)
#define Counter_1_OVERLOW_INVERT                 (0x08u)
#define Counter_1_OVERLOW_NO_CHANGE              (0x0Cu)
#define Counter_1_UNDERFLOW_SET                  (0x00u)
#define Counter_1_UNDERFLOW_CLEAR                (0x10u)
#define Counter_1_UNDERFLOW_INVERT               (0x20u)
#define Counter_1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Counter_1_PWM_MODE_LEFT                  (Counter_1_CC_MATCH_CLEAR        |   \
                                                         Counter_1_OVERLOW_SET           |   \
                                                         Counter_1_UNDERFLOW_NO_CHANGE)
#define Counter_1_PWM_MODE_RIGHT                 (Counter_1_CC_MATCH_SET          |   \
                                                         Counter_1_OVERLOW_NO_CHANGE     |   \
                                                         Counter_1_UNDERFLOW_CLEAR)
#define Counter_1_PWM_MODE_ASYM                  (Counter_1_CC_MATCH_INVERT       |   \
                                                         Counter_1_OVERLOW_SET           |   \
                                                         Counter_1_UNDERFLOW_CLEAR)

#if (Counter_1_CY_TCPWM_V2)
    #if(Counter_1_CY_TCPWM_4000)
        #define Counter_1_PWM_MODE_CENTER                (Counter_1_CC_MATCH_INVERT       |   \
                                                                 Counter_1_OVERLOW_NO_CHANGE     |   \
                                                                 Counter_1_UNDERFLOW_CLEAR)
    #else
        #define Counter_1_PWM_MODE_CENTER                (Counter_1_CC_MATCH_INVERT       |   \
                                                                 Counter_1_OVERLOW_SET           |   \
                                                                 Counter_1_UNDERFLOW_CLEAR)
    #endif /* (Counter_1_CY_TCPWM_4000) */
#else
    #define Counter_1_PWM_MODE_CENTER                (Counter_1_CC_MATCH_INVERT       |   \
                                                             Counter_1_OVERLOW_NO_CHANGE     |   \
                                                             Counter_1_UNDERFLOW_CLEAR)
#endif /* (Counter_1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Counter_1_CMD_CAPTURE                    (0u)
#define Counter_1_CMD_RELOAD                     (8u)
#define Counter_1_CMD_STOP                       (16u)
#define Counter_1_CMD_START                      (24u)

/* Status */
#define Counter_1_STATUS_DOWN                    (1u)
#define Counter_1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Counter_1_Init(void);
void   Counter_1_Enable(void);
void   Counter_1_Start(void);
void   Counter_1_Stop(void);

void   Counter_1_SetMode(uint32 mode);
void   Counter_1_SetCounterMode(uint32 counterMode);
void   Counter_1_SetPWMMode(uint32 modeMask);
void   Counter_1_SetQDMode(uint32 qdMode);

void   Counter_1_SetPrescaler(uint32 prescaler);
void   Counter_1_TriggerCommand(uint32 mask, uint32 command);
void   Counter_1_SetOneShot(uint32 oneShotEnable);
uint32 Counter_1_ReadStatus(void);

void   Counter_1_SetPWMSyncKill(uint32 syncKillEnable);
void   Counter_1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Counter_1_SetPWMDeadTime(uint32 deadTime);
void   Counter_1_SetPWMInvert(uint32 mask);

void   Counter_1_SetInterruptMode(uint32 interruptMask);
uint32 Counter_1_GetInterruptSourceMasked(void);
uint32 Counter_1_GetInterruptSource(void);
void   Counter_1_ClearInterrupt(uint32 interruptMask);
void   Counter_1_SetInterrupt(uint32 interruptMask);

void   Counter_1_WriteCounter(uint32 count);
uint32 Counter_1_ReadCounter(void);

uint32 Counter_1_ReadCapture(void);
uint32 Counter_1_ReadCaptureBuf(void);

void   Counter_1_WritePeriod(uint32 period);
uint32 Counter_1_ReadPeriod(void);
void   Counter_1_WritePeriodBuf(uint32 periodBuf);
uint32 Counter_1_ReadPeriodBuf(void);

void   Counter_1_WriteCompare(uint32 compare);
uint32 Counter_1_ReadCompare(void);
void   Counter_1_WriteCompareBuf(uint32 compareBuf);
uint32 Counter_1_ReadCompareBuf(void);

void   Counter_1_SetPeriodSwap(uint32 swapEnable);
void   Counter_1_SetCompareSwap(uint32 swapEnable);

void   Counter_1_SetCaptureMode(uint32 triggerMode);
void   Counter_1_SetReloadMode(uint32 triggerMode);
void   Counter_1_SetStartMode(uint32 triggerMode);
void   Counter_1_SetStopMode(uint32 triggerMode);
void   Counter_1_SetCountMode(uint32 triggerMode);

void   Counter_1_SaveConfig(void);
void   Counter_1_RestoreConfig(void);
void   Counter_1_Sleep(void);
void   Counter_1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Counter_1_BLOCK_CONTROL_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_1_BLOCK_CONTROL_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Counter_1_COMMAND_REG                    (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_1_COMMAND_PTR                    ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Counter_1_INTRRUPT_CAUSE_REG             (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_1_INTRRUPT_CAUSE_PTR             ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Counter_1_CONTROL_REG                    (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__CTRL )
#define Counter_1_CONTROL_PTR                    ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__CTRL )
#define Counter_1_STATUS_REG                     (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__STATUS )
#define Counter_1_STATUS_PTR                     ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__STATUS )
#define Counter_1_COUNTER_REG                    (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_1_COUNTER_PTR                    ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__COUNTER )
#define Counter_1_COMP_CAP_REG                   (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__CC )
#define Counter_1_COMP_CAP_PTR                   ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__CC )
#define Counter_1_COMP_CAP_BUF_REG               (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_1_COMP_CAP_BUF_PTR               ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define Counter_1_PERIOD_REG                     (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_1_PERIOD_PTR                     ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__PERIOD )
#define Counter_1_PERIOD_BUF_REG                 (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_1_PERIOD_BUF_PTR                 ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Counter_1_TRIG_CONTROL0_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_1_TRIG_CONTROL0_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Counter_1_TRIG_CONTROL1_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_1_TRIG_CONTROL1_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Counter_1_TRIG_CONTROL2_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_1_TRIG_CONTROL2_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Counter_1_INTERRUPT_REQ_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR )
#define Counter_1_INTERRUPT_REQ_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR )
#define Counter_1_INTERRUPT_SET_REG              (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_1_INTERRUPT_SET_PTR              ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_SET )
#define Counter_1_INTERRUPT_MASK_REG             (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_1_INTERRUPT_MASK_PTR             ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define Counter_1_INTERRUPT_MASKED_REG           (*(reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Counter_1_INTERRUPT_MASKED_PTR           ( (reg32 *) Counter_1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Counter_1_MASK                           ((uint32)Counter_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Counter_1_RELOAD_CC_SHIFT                (0u)
#define Counter_1_RELOAD_PERIOD_SHIFT            (1u)
#define Counter_1_PWM_SYNC_KILL_SHIFT            (2u)
#define Counter_1_PWM_STOP_KILL_SHIFT            (3u)
#define Counter_1_PRESCALER_SHIFT                (8u)
#define Counter_1_UPDOWN_SHIFT                   (16u)
#define Counter_1_ONESHOT_SHIFT                  (18u)
#define Counter_1_QUAD_MODE_SHIFT                (20u)
#define Counter_1_INV_OUT_SHIFT                  (20u)
#define Counter_1_INV_COMPL_OUT_SHIFT            (21u)
#define Counter_1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Counter_1_RELOAD_CC_MASK                 ((uint32)(Counter_1_1BIT_MASK        <<  \
                                                                            Counter_1_RELOAD_CC_SHIFT))
#define Counter_1_RELOAD_PERIOD_MASK             ((uint32)(Counter_1_1BIT_MASK        <<  \
                                                                            Counter_1_RELOAD_PERIOD_SHIFT))
#define Counter_1_PWM_SYNC_KILL_MASK             ((uint32)(Counter_1_1BIT_MASK        <<  \
                                                                            Counter_1_PWM_SYNC_KILL_SHIFT))
#define Counter_1_PWM_STOP_KILL_MASK             ((uint32)(Counter_1_1BIT_MASK        <<  \
                                                                            Counter_1_PWM_STOP_KILL_SHIFT))
#define Counter_1_PRESCALER_MASK                 ((uint32)(Counter_1_8BIT_MASK        <<  \
                                                                            Counter_1_PRESCALER_SHIFT))
#define Counter_1_UPDOWN_MASK                    ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                            Counter_1_UPDOWN_SHIFT))
#define Counter_1_ONESHOT_MASK                   ((uint32)(Counter_1_1BIT_MASK        <<  \
                                                                            Counter_1_ONESHOT_SHIFT))
#define Counter_1_QUAD_MODE_MASK                 ((uint32)(Counter_1_3BIT_MASK        <<  \
                                                                            Counter_1_QUAD_MODE_SHIFT))
#define Counter_1_INV_OUT_MASK                   ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                            Counter_1_INV_OUT_SHIFT))
#define Counter_1_MODE_MASK                      ((uint32)(Counter_1_3BIT_MASK        <<  \
                                                                            Counter_1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Counter_1_CAPTURE_SHIFT                  (0u)
#define Counter_1_COUNT_SHIFT                    (2u)
#define Counter_1_RELOAD_SHIFT                   (4u)
#define Counter_1_STOP_SHIFT                     (6u)
#define Counter_1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Counter_1_CAPTURE_MASK                   ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                  Counter_1_CAPTURE_SHIFT))
#define Counter_1_COUNT_MASK                     ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                  Counter_1_COUNT_SHIFT))
#define Counter_1_RELOAD_MASK                    ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                  Counter_1_RELOAD_SHIFT))
#define Counter_1_STOP_MASK                      ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                  Counter_1_STOP_SHIFT))
#define Counter_1_START_MASK                     ((uint32)(Counter_1_2BIT_MASK        <<  \
                                                                  Counter_1_START_SHIFT))

/* MASK */
#define Counter_1_1BIT_MASK                      ((uint32)0x01u)
#define Counter_1_2BIT_MASK                      ((uint32)0x03u)
#define Counter_1_3BIT_MASK                      ((uint32)0x07u)
#define Counter_1_6BIT_MASK                      ((uint32)0x3Fu)
#define Counter_1_8BIT_MASK                      ((uint32)0xFFu)
#define Counter_1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Counter_1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Counter_1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Counter_1_QUAD_ENCODING_MODES     << Counter_1_QUAD_MODE_SHIFT))       |\
         ((uint32)(Counter_1_CONFIG                  << Counter_1_MODE_SHIFT)))

#define Counter_1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Counter_1_PWM_STOP_EVENT          << Counter_1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Counter_1_PWM_OUT_INVERT          << Counter_1_INV_OUT_SHIFT))         |\
         ((uint32)(Counter_1_PWM_OUT_N_INVERT        << Counter_1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Counter_1_PWM_MODE                << Counter_1_MODE_SHIFT)))

#define Counter_1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Counter_1_PWM_RUN_MODE         << Counter_1_ONESHOT_SHIFT))
            
#define Counter_1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Counter_1_PWM_ALIGN            << Counter_1_UPDOWN_SHIFT))

#define Counter_1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Counter_1_PWM_KILL_EVENT      << Counter_1_PWM_SYNC_KILL_SHIFT))

#define Counter_1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Counter_1_PWM_DEAD_TIME_CYCLE  << Counter_1_PRESCALER_SHIFT))

#define Counter_1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Counter_1_PWM_PRESCALER        << Counter_1_PRESCALER_SHIFT))

#define Counter_1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Counter_1_TC_PRESCALER            << Counter_1_PRESCALER_SHIFT))       |\
         ((uint32)(Counter_1_TC_COUNTER_MODE         << Counter_1_UPDOWN_SHIFT))          |\
         ((uint32)(Counter_1_TC_RUN_MODE             << Counter_1_ONESHOT_SHIFT))         |\
         ((uint32)(Counter_1_TC_COMP_CAP_MODE        << Counter_1_MODE_SHIFT)))
        
#define Counter_1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Counter_1_QUAD_PHIA_SIGNAL_MODE   << Counter_1_COUNT_SHIFT))           |\
         ((uint32)(Counter_1_QUAD_INDEX_SIGNAL_MODE  << Counter_1_RELOAD_SHIFT))          |\
         ((uint32)(Counter_1_QUAD_STOP_SIGNAL_MODE   << Counter_1_STOP_SHIFT))            |\
         ((uint32)(Counter_1_QUAD_PHIB_SIGNAL_MODE   << Counter_1_START_SHIFT)))

#define Counter_1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Counter_1_PWM_SWITCH_SIGNAL_MODE  << Counter_1_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_1_PWM_COUNT_SIGNAL_MODE   << Counter_1_COUNT_SHIFT))           |\
         ((uint32)(Counter_1_PWM_RELOAD_SIGNAL_MODE  << Counter_1_RELOAD_SHIFT))          |\
         ((uint32)(Counter_1_PWM_STOP_SIGNAL_MODE    << Counter_1_STOP_SHIFT))            |\
         ((uint32)(Counter_1_PWM_START_SIGNAL_MODE   << Counter_1_START_SHIFT)))

#define Counter_1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Counter_1_TC_CAPTURE_SIGNAL_MODE  << Counter_1_CAPTURE_SHIFT))         |\
         ((uint32)(Counter_1_TC_COUNT_SIGNAL_MODE    << Counter_1_COUNT_SHIFT))           |\
         ((uint32)(Counter_1_TC_RELOAD_SIGNAL_MODE   << Counter_1_RELOAD_SHIFT))          |\
         ((uint32)(Counter_1_TC_STOP_SIGNAL_MODE     << Counter_1_STOP_SHIFT))            |\
         ((uint32)(Counter_1_TC_START_SIGNAL_MODE    << Counter_1_START_SHIFT)))
        
#define Counter_1_TIMER_UPDOWN_CNT_USED                                                          \
                ((Counter_1__COUNT_UPDOWN0 == Counter_1_TC_COUNTER_MODE)                  ||\
                 (Counter_1__COUNT_UPDOWN1 == Counter_1_TC_COUNTER_MODE))

#define Counter_1_PWM_UPDOWN_CNT_USED                                                            \
                ((Counter_1__CENTER == Counter_1_PWM_ALIGN)                               ||\
                 (Counter_1__ASYMMETRIC == Counter_1_PWM_ALIGN))               
        
#define Counter_1_PWM_PR_INIT_VALUE              (1u)
#define Counter_1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Counter_1_H */

/* [] END OF FILE */
