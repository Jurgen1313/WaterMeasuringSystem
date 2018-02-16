/*******************************************************************************
* File Name: ExamplaryCounter.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the ExamplaryCounter
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

#if !defined(CY_TCPWM_ExamplaryCounter_H)
#define CY_TCPWM_ExamplaryCounter_H


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
} ExamplaryCounter_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  ExamplaryCounter_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define ExamplaryCounter_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define ExamplaryCounter_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define ExamplaryCounter_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define ExamplaryCounter_QUAD_ENCODING_MODES            (0lu)
#define ExamplaryCounter_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define ExamplaryCounter_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define ExamplaryCounter_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define ExamplaryCounter_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define ExamplaryCounter_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define ExamplaryCounter_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define ExamplaryCounter_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define ExamplaryCounter_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define ExamplaryCounter_TC_RUN_MODE                    (0lu)
#define ExamplaryCounter_TC_COUNTER_MODE                (0lu)
#define ExamplaryCounter_TC_COMP_CAP_MODE               (2lu)
#define ExamplaryCounter_TC_PRESCALER                   (0lu)

/* Signal modes */
#define ExamplaryCounter_TC_RELOAD_SIGNAL_MODE          (0lu)
#define ExamplaryCounter_TC_COUNT_SIGNAL_MODE           (1lu)
#define ExamplaryCounter_TC_START_SIGNAL_MODE           (0lu)
#define ExamplaryCounter_TC_STOP_SIGNAL_MODE            (1lu)
#define ExamplaryCounter_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define ExamplaryCounter_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define ExamplaryCounter_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define ExamplaryCounter_TC_START_SIGNAL_PRESENT        (0lu)
#define ExamplaryCounter_TC_STOP_SIGNAL_PRESENT         (0lu)
#define ExamplaryCounter_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define ExamplaryCounter_TC_INTERRUPT_MASK              (3lu)

/* PWM Mode */
/* Parameters */
#define ExamplaryCounter_PWM_KILL_EVENT                 (0lu)
#define ExamplaryCounter_PWM_STOP_EVENT                 (0lu)
#define ExamplaryCounter_PWM_MODE                       (4lu)
#define ExamplaryCounter_PWM_OUT_N_INVERT               (0lu)
#define ExamplaryCounter_PWM_OUT_INVERT                 (0lu)
#define ExamplaryCounter_PWM_ALIGN                      (0lu)
#define ExamplaryCounter_PWM_RUN_MODE                   (0lu)
#define ExamplaryCounter_PWM_DEAD_TIME_CYCLE            (0lu)
#define ExamplaryCounter_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define ExamplaryCounter_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define ExamplaryCounter_PWM_COUNT_SIGNAL_MODE          (3lu)
#define ExamplaryCounter_PWM_START_SIGNAL_MODE          (0lu)
#define ExamplaryCounter_PWM_STOP_SIGNAL_MODE           (0lu)
#define ExamplaryCounter_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define ExamplaryCounter_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define ExamplaryCounter_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define ExamplaryCounter_PWM_START_SIGNAL_PRESENT       (0lu)
#define ExamplaryCounter_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define ExamplaryCounter_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define ExamplaryCounter_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define ExamplaryCounter_TC_PERIOD_VALUE                (65535lu)
#define ExamplaryCounter_TC_COMPARE_VALUE               (65535lu)
#define ExamplaryCounter_TC_COMPARE_BUF_VALUE           (65535lu)
#define ExamplaryCounter_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define ExamplaryCounter_PWM_PERIOD_VALUE               (65535lu)
#define ExamplaryCounter_PWM_PERIOD_BUF_VALUE           (65535lu)
#define ExamplaryCounter_PWM_PERIOD_SWAP                (0lu)
#define ExamplaryCounter_PWM_COMPARE_VALUE              (65535lu)
#define ExamplaryCounter_PWM_COMPARE_BUF_VALUE          (65535lu)
#define ExamplaryCounter_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define ExamplaryCounter__LEFT 0
#define ExamplaryCounter__RIGHT 1
#define ExamplaryCounter__CENTER 2
#define ExamplaryCounter__ASYMMETRIC 3

#define ExamplaryCounter__X1 0
#define ExamplaryCounter__X2 1
#define ExamplaryCounter__X4 2

#define ExamplaryCounter__PWM 4
#define ExamplaryCounter__PWM_DT 5
#define ExamplaryCounter__PWM_PR 6

#define ExamplaryCounter__INVERSE 1
#define ExamplaryCounter__DIRECT 0

#define ExamplaryCounter__CAPTURE 2
#define ExamplaryCounter__COMPARE 0

#define ExamplaryCounter__TRIG_LEVEL 3
#define ExamplaryCounter__TRIG_RISING 0
#define ExamplaryCounter__TRIG_FALLING 1
#define ExamplaryCounter__TRIG_BOTH 2

#define ExamplaryCounter__INTR_MASK_TC 1
#define ExamplaryCounter__INTR_MASK_CC_MATCH 2
#define ExamplaryCounter__INTR_MASK_NONE 0
#define ExamplaryCounter__INTR_MASK_TC_CC 3

#define ExamplaryCounter__UNCONFIG 8
#define ExamplaryCounter__TIMER 1
#define ExamplaryCounter__QUAD 3
#define ExamplaryCounter__PWM_SEL 7

#define ExamplaryCounter__COUNT_UP 0
#define ExamplaryCounter__COUNT_DOWN 1
#define ExamplaryCounter__COUNT_UPDOWN0 2
#define ExamplaryCounter__COUNT_UPDOWN1 3


/* Prescaler */
#define ExamplaryCounter_PRESCALE_DIVBY1                ((uint32)(0u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY2                ((uint32)(1u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY4                ((uint32)(2u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY8                ((uint32)(3u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY16               ((uint32)(4u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY32               ((uint32)(5u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY64               ((uint32)(6u << ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_PRESCALE_DIVBY128              ((uint32)(7u << ExamplaryCounter_PRESCALER_SHIFT))

/* TCPWM set modes */
#define ExamplaryCounter_MODE_TIMER_COMPARE             ((uint32)(ExamplaryCounter__COMPARE         <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))
#define ExamplaryCounter_MODE_TIMER_CAPTURE             ((uint32)(ExamplaryCounter__CAPTURE         <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))
#define ExamplaryCounter_MODE_QUAD                      ((uint32)(ExamplaryCounter__QUAD            <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))
#define ExamplaryCounter_MODE_PWM                       ((uint32)(ExamplaryCounter__PWM             <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))
#define ExamplaryCounter_MODE_PWM_DT                    ((uint32)(ExamplaryCounter__PWM_DT          <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))
#define ExamplaryCounter_MODE_PWM_PR                    ((uint32)(ExamplaryCounter__PWM_PR          <<  \
                                                                  ExamplaryCounter_MODE_SHIFT))

/* Quad Modes */
#define ExamplaryCounter_MODE_X1                        ((uint32)(ExamplaryCounter__X1              <<  \
                                                                  ExamplaryCounter_QUAD_MODE_SHIFT))
#define ExamplaryCounter_MODE_X2                        ((uint32)(ExamplaryCounter__X2              <<  \
                                                                  ExamplaryCounter_QUAD_MODE_SHIFT))
#define ExamplaryCounter_MODE_X4                        ((uint32)(ExamplaryCounter__X4              <<  \
                                                                  ExamplaryCounter_QUAD_MODE_SHIFT))

/* Counter modes */
#define ExamplaryCounter_COUNT_UP                       ((uint32)(ExamplaryCounter__COUNT_UP        <<  \
                                                                  ExamplaryCounter_UPDOWN_SHIFT))
#define ExamplaryCounter_COUNT_DOWN                     ((uint32)(ExamplaryCounter__COUNT_DOWN      <<  \
                                                                  ExamplaryCounter_UPDOWN_SHIFT))
#define ExamplaryCounter_COUNT_UPDOWN0                  ((uint32)(ExamplaryCounter__COUNT_UPDOWN0   <<  \
                                                                  ExamplaryCounter_UPDOWN_SHIFT))
#define ExamplaryCounter_COUNT_UPDOWN1                  ((uint32)(ExamplaryCounter__COUNT_UPDOWN1   <<  \
                                                                  ExamplaryCounter_UPDOWN_SHIFT))

/* PWM output invert */
#define ExamplaryCounter_INVERT_LINE                    ((uint32)(ExamplaryCounter__INVERSE         <<  \
                                                                  ExamplaryCounter_INV_OUT_SHIFT))
#define ExamplaryCounter_INVERT_LINE_N                  ((uint32)(ExamplaryCounter__INVERSE         <<  \
                                                                  ExamplaryCounter_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define ExamplaryCounter_TRIG_RISING                    ((uint32)ExamplaryCounter__TRIG_RISING)
#define ExamplaryCounter_TRIG_FALLING                   ((uint32)ExamplaryCounter__TRIG_FALLING)
#define ExamplaryCounter_TRIG_BOTH                      ((uint32)ExamplaryCounter__TRIG_BOTH)
#define ExamplaryCounter_TRIG_LEVEL                     ((uint32)ExamplaryCounter__TRIG_LEVEL)

/* Interrupt mask */
#define ExamplaryCounter_INTR_MASK_TC                   ((uint32)ExamplaryCounter__INTR_MASK_TC)
#define ExamplaryCounter_INTR_MASK_CC_MATCH             ((uint32)ExamplaryCounter__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define ExamplaryCounter_CC_MATCH_SET                   (0x00u)
#define ExamplaryCounter_CC_MATCH_CLEAR                 (0x01u)
#define ExamplaryCounter_CC_MATCH_INVERT                (0x02u)
#define ExamplaryCounter_CC_MATCH_NO_CHANGE             (0x03u)
#define ExamplaryCounter_OVERLOW_SET                    (0x00u)
#define ExamplaryCounter_OVERLOW_CLEAR                  (0x04u)
#define ExamplaryCounter_OVERLOW_INVERT                 (0x08u)
#define ExamplaryCounter_OVERLOW_NO_CHANGE              (0x0Cu)
#define ExamplaryCounter_UNDERFLOW_SET                  (0x00u)
#define ExamplaryCounter_UNDERFLOW_CLEAR                (0x10u)
#define ExamplaryCounter_UNDERFLOW_INVERT               (0x20u)
#define ExamplaryCounter_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define ExamplaryCounter_PWM_MODE_LEFT                  (ExamplaryCounter_CC_MATCH_CLEAR        |   \
                                                         ExamplaryCounter_OVERLOW_SET           |   \
                                                         ExamplaryCounter_UNDERFLOW_NO_CHANGE)
#define ExamplaryCounter_PWM_MODE_RIGHT                 (ExamplaryCounter_CC_MATCH_SET          |   \
                                                         ExamplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                         ExamplaryCounter_UNDERFLOW_CLEAR)
#define ExamplaryCounter_PWM_MODE_ASYM                  (ExamplaryCounter_CC_MATCH_INVERT       |   \
                                                         ExamplaryCounter_OVERLOW_SET           |   \
                                                         ExamplaryCounter_UNDERFLOW_CLEAR)

#if (ExamplaryCounter_CY_TCPWM_V2)
    #if(ExamplaryCounter_CY_TCPWM_4000)
        #define ExamplaryCounter_PWM_MODE_CENTER                (ExamplaryCounter_CC_MATCH_INVERT       |   \
                                                                 ExamplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                                 ExamplaryCounter_UNDERFLOW_CLEAR)
    #else
        #define ExamplaryCounter_PWM_MODE_CENTER                (ExamplaryCounter_CC_MATCH_INVERT       |   \
                                                                 ExamplaryCounter_OVERLOW_SET           |   \
                                                                 ExamplaryCounter_UNDERFLOW_CLEAR)
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */
#else
    #define ExamplaryCounter_PWM_MODE_CENTER                (ExamplaryCounter_CC_MATCH_INVERT       |   \
                                                             ExamplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                             ExamplaryCounter_UNDERFLOW_CLEAR)
#endif /* (ExamplaryCounter_CY_TCPWM_NEW) */

/* Command operations without condition */
#define ExamplaryCounter_CMD_CAPTURE                    (0u)
#define ExamplaryCounter_CMD_RELOAD                     (8u)
#define ExamplaryCounter_CMD_STOP                       (16u)
#define ExamplaryCounter_CMD_START                      (24u)

/* Status */
#define ExamplaryCounter_STATUS_DOWN                    (1u)
#define ExamplaryCounter_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   ExamplaryCounter_Init(void);
void   ExamplaryCounter_Enable(void);
void   ExamplaryCounter_Start(void);
void   ExamplaryCounter_Stop(void);

void   ExamplaryCounter_SetMode(uint32 mode);
void   ExamplaryCounter_SetCounterMode(uint32 counterMode);
void   ExamplaryCounter_SetPWMMode(uint32 modeMask);
void   ExamplaryCounter_SetQDMode(uint32 qdMode);

void   ExamplaryCounter_SetPrescaler(uint32 prescaler);
void   ExamplaryCounter_TriggerCommand(uint32 mask, uint32 command);
void   ExamplaryCounter_SetOneShot(uint32 oneShotEnable);
uint32 ExamplaryCounter_ReadStatus(void);

void   ExamplaryCounter_SetPWMSyncKill(uint32 syncKillEnable);
void   ExamplaryCounter_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   ExamplaryCounter_SetPWMDeadTime(uint32 deadTime);
void   ExamplaryCounter_SetPWMInvert(uint32 mask);

void   ExamplaryCounter_SetInterruptMode(uint32 interruptMask);
uint32 ExamplaryCounter_GetInterruptSourceMasked(void);
uint32 ExamplaryCounter_GetInterruptSource(void);
void   ExamplaryCounter_ClearInterrupt(uint32 interruptMask);
void   ExamplaryCounter_SetInterrupt(uint32 interruptMask);

void   ExamplaryCounter_WriteCounter(uint32 count);
uint32 ExamplaryCounter_ReadCounter(void);

uint32 ExamplaryCounter_ReadCapture(void);
uint32 ExamplaryCounter_ReadCaptureBuf(void);

void   ExamplaryCounter_WritePeriod(uint32 period);
uint32 ExamplaryCounter_ReadPeriod(void);
void   ExamplaryCounter_WritePeriodBuf(uint32 periodBuf);
uint32 ExamplaryCounter_ReadPeriodBuf(void);

void   ExamplaryCounter_WriteCompare(uint32 compare);
uint32 ExamplaryCounter_ReadCompare(void);
void   ExamplaryCounter_WriteCompareBuf(uint32 compareBuf);
uint32 ExamplaryCounter_ReadCompareBuf(void);

void   ExamplaryCounter_SetPeriodSwap(uint32 swapEnable);
void   ExamplaryCounter_SetCompareSwap(uint32 swapEnable);

void   ExamplaryCounter_SetCaptureMode(uint32 triggerMode);
void   ExamplaryCounter_SetReloadMode(uint32 triggerMode);
void   ExamplaryCounter_SetStartMode(uint32 triggerMode);
void   ExamplaryCounter_SetStopMode(uint32 triggerMode);
void   ExamplaryCounter_SetCountMode(uint32 triggerMode);

void   ExamplaryCounter_SaveConfig(void);
void   ExamplaryCounter_RestoreConfig(void);
void   ExamplaryCounter_Sleep(void);
void   ExamplaryCounter_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define ExamplaryCounter_BLOCK_CONTROL_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define ExamplaryCounter_BLOCK_CONTROL_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define ExamplaryCounter_COMMAND_REG                    (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define ExamplaryCounter_COMMAND_PTR                    ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define ExamplaryCounter_INTRRUPT_CAUSE_REG             (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define ExamplaryCounter_INTRRUPT_CAUSE_PTR             ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define ExamplaryCounter_CONTROL_REG                    (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CTRL )
#define ExamplaryCounter_CONTROL_PTR                    ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CTRL )
#define ExamplaryCounter_STATUS_REG                     (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__STATUS )
#define ExamplaryCounter_STATUS_PTR                     ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__STATUS )
#define ExamplaryCounter_COUNTER_REG                    (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__COUNTER )
#define ExamplaryCounter_COUNTER_PTR                    ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__COUNTER )
#define ExamplaryCounter_COMP_CAP_REG                   (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CC )
#define ExamplaryCounter_COMP_CAP_PTR                   ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CC )
#define ExamplaryCounter_COMP_CAP_BUF_REG               (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define ExamplaryCounter_COMP_CAP_BUF_PTR               ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define ExamplaryCounter_PERIOD_REG                     (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__PERIOD )
#define ExamplaryCounter_PERIOD_PTR                     ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__PERIOD )
#define ExamplaryCounter_PERIOD_BUF_REG                 (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define ExamplaryCounter_PERIOD_BUF_PTR                 ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define ExamplaryCounter_TRIG_CONTROL0_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define ExamplaryCounter_TRIG_CONTROL0_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define ExamplaryCounter_TRIG_CONTROL1_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define ExamplaryCounter_TRIG_CONTROL1_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define ExamplaryCounter_TRIG_CONTROL2_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define ExamplaryCounter_TRIG_CONTROL2_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define ExamplaryCounter_INTERRUPT_REQ_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR )
#define ExamplaryCounter_INTERRUPT_REQ_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR )
#define ExamplaryCounter_INTERRUPT_SET_REG              (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define ExamplaryCounter_INTERRUPT_SET_PTR              ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define ExamplaryCounter_INTERRUPT_MASK_REG             (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define ExamplaryCounter_INTERRUPT_MASK_PTR             ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define ExamplaryCounter_INTERRUPT_MASKED_REG           (*(reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_MASKED )
#define ExamplaryCounter_INTERRUPT_MASKED_PTR           ( (reg32 *) ExamplaryCounter_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define ExamplaryCounter_MASK                           ((uint32)ExamplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define ExamplaryCounter_RELOAD_CC_SHIFT                (0u)
#define ExamplaryCounter_RELOAD_PERIOD_SHIFT            (1u)
#define ExamplaryCounter_PWM_SYNC_KILL_SHIFT            (2u)
#define ExamplaryCounter_PWM_STOP_KILL_SHIFT            (3u)
#define ExamplaryCounter_PRESCALER_SHIFT                (8u)
#define ExamplaryCounter_UPDOWN_SHIFT                   (16u)
#define ExamplaryCounter_ONESHOT_SHIFT                  (18u)
#define ExamplaryCounter_QUAD_MODE_SHIFT                (20u)
#define ExamplaryCounter_INV_OUT_SHIFT                  (20u)
#define ExamplaryCounter_INV_COMPL_OUT_SHIFT            (21u)
#define ExamplaryCounter_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define ExamplaryCounter_RELOAD_CC_MASK                 ((uint32)(ExamplaryCounter_1BIT_MASK        <<  \
                                                                            ExamplaryCounter_RELOAD_CC_SHIFT))
#define ExamplaryCounter_RELOAD_PERIOD_MASK             ((uint32)(ExamplaryCounter_1BIT_MASK        <<  \
                                                                            ExamplaryCounter_RELOAD_PERIOD_SHIFT))
#define ExamplaryCounter_PWM_SYNC_KILL_MASK             ((uint32)(ExamplaryCounter_1BIT_MASK        <<  \
                                                                            ExamplaryCounter_PWM_SYNC_KILL_SHIFT))
#define ExamplaryCounter_PWM_STOP_KILL_MASK             ((uint32)(ExamplaryCounter_1BIT_MASK        <<  \
                                                                            ExamplaryCounter_PWM_STOP_KILL_SHIFT))
#define ExamplaryCounter_PRESCALER_MASK                 ((uint32)(ExamplaryCounter_8BIT_MASK        <<  \
                                                                            ExamplaryCounter_PRESCALER_SHIFT))
#define ExamplaryCounter_UPDOWN_MASK                    ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                            ExamplaryCounter_UPDOWN_SHIFT))
#define ExamplaryCounter_ONESHOT_MASK                   ((uint32)(ExamplaryCounter_1BIT_MASK        <<  \
                                                                            ExamplaryCounter_ONESHOT_SHIFT))
#define ExamplaryCounter_QUAD_MODE_MASK                 ((uint32)(ExamplaryCounter_3BIT_MASK        <<  \
                                                                            ExamplaryCounter_QUAD_MODE_SHIFT))
#define ExamplaryCounter_INV_OUT_MASK                   ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                            ExamplaryCounter_INV_OUT_SHIFT))
#define ExamplaryCounter_MODE_MASK                      ((uint32)(ExamplaryCounter_3BIT_MASK        <<  \
                                                                            ExamplaryCounter_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define ExamplaryCounter_CAPTURE_SHIFT                  (0u)
#define ExamplaryCounter_COUNT_SHIFT                    (2u)
#define ExamplaryCounter_RELOAD_SHIFT                   (4u)
#define ExamplaryCounter_STOP_SHIFT                     (6u)
#define ExamplaryCounter_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define ExamplaryCounter_CAPTURE_MASK                   ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                  ExamplaryCounter_CAPTURE_SHIFT))
#define ExamplaryCounter_COUNT_MASK                     ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                  ExamplaryCounter_COUNT_SHIFT))
#define ExamplaryCounter_RELOAD_MASK                    ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                  ExamplaryCounter_RELOAD_SHIFT))
#define ExamplaryCounter_STOP_MASK                      ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                  ExamplaryCounter_STOP_SHIFT))
#define ExamplaryCounter_START_MASK                     ((uint32)(ExamplaryCounter_2BIT_MASK        <<  \
                                                                  ExamplaryCounter_START_SHIFT))

/* MASK */
#define ExamplaryCounter_1BIT_MASK                      ((uint32)0x01u)
#define ExamplaryCounter_2BIT_MASK                      ((uint32)0x03u)
#define ExamplaryCounter_3BIT_MASK                      ((uint32)0x07u)
#define ExamplaryCounter_6BIT_MASK                      ((uint32)0x3Fu)
#define ExamplaryCounter_8BIT_MASK                      ((uint32)0xFFu)
#define ExamplaryCounter_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define ExamplaryCounter_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define ExamplaryCounter_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(ExamplaryCounter_QUAD_ENCODING_MODES     << ExamplaryCounter_QUAD_MODE_SHIFT))       |\
         ((uint32)(ExamplaryCounter_CONFIG                  << ExamplaryCounter_MODE_SHIFT)))

#define ExamplaryCounter_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(ExamplaryCounter_PWM_STOP_EVENT          << ExamplaryCounter_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(ExamplaryCounter_PWM_OUT_INVERT          << ExamplaryCounter_INV_OUT_SHIFT))         |\
         ((uint32)(ExamplaryCounter_PWM_OUT_N_INVERT        << ExamplaryCounter_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(ExamplaryCounter_PWM_MODE                << ExamplaryCounter_MODE_SHIFT)))

#define ExamplaryCounter_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(ExamplaryCounter_PWM_RUN_MODE         << ExamplaryCounter_ONESHOT_SHIFT))
            
#define ExamplaryCounter_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(ExamplaryCounter_PWM_ALIGN            << ExamplaryCounter_UPDOWN_SHIFT))

#define ExamplaryCounter_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(ExamplaryCounter_PWM_KILL_EVENT      << ExamplaryCounter_PWM_SYNC_KILL_SHIFT))

#define ExamplaryCounter_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(ExamplaryCounter_PWM_DEAD_TIME_CYCLE  << ExamplaryCounter_PRESCALER_SHIFT))

#define ExamplaryCounter_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(ExamplaryCounter_PWM_PRESCALER        << ExamplaryCounter_PRESCALER_SHIFT))

#define ExamplaryCounter_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(ExamplaryCounter_TC_PRESCALER            << ExamplaryCounter_PRESCALER_SHIFT))       |\
         ((uint32)(ExamplaryCounter_TC_COUNTER_MODE         << ExamplaryCounter_UPDOWN_SHIFT))          |\
         ((uint32)(ExamplaryCounter_TC_RUN_MODE             << ExamplaryCounter_ONESHOT_SHIFT))         |\
         ((uint32)(ExamplaryCounter_TC_COMP_CAP_MODE        << ExamplaryCounter_MODE_SHIFT)))
        
#define ExamplaryCounter_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(ExamplaryCounter_QUAD_PHIA_SIGNAL_MODE   << ExamplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExamplaryCounter_QUAD_INDEX_SIGNAL_MODE  << ExamplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExamplaryCounter_QUAD_STOP_SIGNAL_MODE   << ExamplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExamplaryCounter_QUAD_PHIB_SIGNAL_MODE   << ExamplaryCounter_START_SHIFT)))

#define ExamplaryCounter_PWM_SIGNALS_MODES                                                              \
        (((uint32)(ExamplaryCounter_PWM_SWITCH_SIGNAL_MODE  << ExamplaryCounter_CAPTURE_SHIFT))         |\
         ((uint32)(ExamplaryCounter_PWM_COUNT_SIGNAL_MODE   << ExamplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExamplaryCounter_PWM_RELOAD_SIGNAL_MODE  << ExamplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExamplaryCounter_PWM_STOP_SIGNAL_MODE    << ExamplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExamplaryCounter_PWM_START_SIGNAL_MODE   << ExamplaryCounter_START_SHIFT)))

#define ExamplaryCounter_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(ExamplaryCounter_TC_CAPTURE_SIGNAL_MODE  << ExamplaryCounter_CAPTURE_SHIFT))         |\
         ((uint32)(ExamplaryCounter_TC_COUNT_SIGNAL_MODE    << ExamplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExamplaryCounter_TC_RELOAD_SIGNAL_MODE   << ExamplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExamplaryCounter_TC_STOP_SIGNAL_MODE     << ExamplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExamplaryCounter_TC_START_SIGNAL_MODE    << ExamplaryCounter_START_SHIFT)))
        
#define ExamplaryCounter_TIMER_UPDOWN_CNT_USED                                                          \
                ((ExamplaryCounter__COUNT_UPDOWN0 == ExamplaryCounter_TC_COUNTER_MODE)                  ||\
                 (ExamplaryCounter__COUNT_UPDOWN1 == ExamplaryCounter_TC_COUNTER_MODE))

#define ExamplaryCounter_PWM_UPDOWN_CNT_USED                                                            \
                ((ExamplaryCounter__CENTER == ExamplaryCounter_PWM_ALIGN)                               ||\
                 (ExamplaryCounter__ASYMMETRIC == ExamplaryCounter_PWM_ALIGN))               
        
#define ExamplaryCounter_PWM_PR_INIT_VALUE              (1u)
#define ExamplaryCounter_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_ExamplaryCounter_H */

/* [] END OF FILE */
