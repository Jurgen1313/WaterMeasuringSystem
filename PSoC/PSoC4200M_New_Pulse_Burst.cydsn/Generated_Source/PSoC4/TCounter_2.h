/*******************************************************************************
* File Name: TCounter_2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the TCounter_2
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

#if !defined(CY_TCPWM_TCounter_2_H)
#define CY_TCPWM_TCounter_2_H


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
} TCounter_2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  TCounter_2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define TCounter_2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define TCounter_2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define TCounter_2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define TCounter_2_QUAD_ENCODING_MODES            (0lu)
#define TCounter_2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define TCounter_2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define TCounter_2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define TCounter_2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define TCounter_2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define TCounter_2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define TCounter_2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define TCounter_2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define TCounter_2_TC_RUN_MODE                    (1lu)
#define TCounter_2_TC_COUNTER_MODE                (0lu)
#define TCounter_2_TC_COMP_CAP_MODE               (0lu)
#define TCounter_2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define TCounter_2_TC_RELOAD_SIGNAL_MODE          (1lu)
#define TCounter_2_TC_COUNT_SIGNAL_MODE           (1lu)
#define TCounter_2_TC_START_SIGNAL_MODE           (0lu)
#define TCounter_2_TC_STOP_SIGNAL_MODE            (0lu)
#define TCounter_2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define TCounter_2_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define TCounter_2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define TCounter_2_TC_START_SIGNAL_PRESENT        (0lu)
#define TCounter_2_TC_STOP_SIGNAL_PRESENT         (1lu)
#define TCounter_2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TCounter_2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define TCounter_2_PWM_KILL_EVENT                 (0lu)
#define TCounter_2_PWM_STOP_EVENT                 (0lu)
#define TCounter_2_PWM_MODE                       (4lu)
#define TCounter_2_PWM_OUT_N_INVERT               (0lu)
#define TCounter_2_PWM_OUT_INVERT                 (0lu)
#define TCounter_2_PWM_ALIGN                      (0lu)
#define TCounter_2_PWM_RUN_MODE                   (0lu)
#define TCounter_2_PWM_DEAD_TIME_CYCLE            (0lu)
#define TCounter_2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define TCounter_2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define TCounter_2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define TCounter_2_PWM_START_SIGNAL_MODE          (0lu)
#define TCounter_2_PWM_STOP_SIGNAL_MODE           (0lu)
#define TCounter_2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define TCounter_2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define TCounter_2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define TCounter_2_PWM_START_SIGNAL_PRESENT       (0lu)
#define TCounter_2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define TCounter_2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TCounter_2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define TCounter_2_TC_PERIOD_VALUE                (65534lu)
#define TCounter_2_TC_COMPARE_VALUE               (65534lu)
#define TCounter_2_TC_COMPARE_BUF_VALUE           (65535lu)
#define TCounter_2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define TCounter_2_PWM_PERIOD_VALUE               (65535lu)
#define TCounter_2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define TCounter_2_PWM_PERIOD_SWAP                (0lu)
#define TCounter_2_PWM_COMPARE_VALUE              (65535lu)
#define TCounter_2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define TCounter_2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TCounter_2__LEFT 0
#define TCounter_2__RIGHT 1
#define TCounter_2__CENTER 2
#define TCounter_2__ASYMMETRIC 3

#define TCounter_2__X1 0
#define TCounter_2__X2 1
#define TCounter_2__X4 2

#define TCounter_2__PWM 4
#define TCounter_2__PWM_DT 5
#define TCounter_2__PWM_PR 6

#define TCounter_2__INVERSE 1
#define TCounter_2__DIRECT 0

#define TCounter_2__CAPTURE 2
#define TCounter_2__COMPARE 0

#define TCounter_2__TRIG_LEVEL 3
#define TCounter_2__TRIG_RISING 0
#define TCounter_2__TRIG_FALLING 1
#define TCounter_2__TRIG_BOTH 2

#define TCounter_2__INTR_MASK_TC 1
#define TCounter_2__INTR_MASK_CC_MATCH 2
#define TCounter_2__INTR_MASK_NONE 0
#define TCounter_2__INTR_MASK_TC_CC 3

#define TCounter_2__UNCONFIG 8
#define TCounter_2__TIMER 1
#define TCounter_2__QUAD 3
#define TCounter_2__PWM_SEL 7

#define TCounter_2__COUNT_UP 0
#define TCounter_2__COUNT_DOWN 1
#define TCounter_2__COUNT_UPDOWN0 2
#define TCounter_2__COUNT_UPDOWN1 3


/* Prescaler */
#define TCounter_2_PRESCALE_DIVBY1                ((uint32)(0u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY2                ((uint32)(1u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY4                ((uint32)(2u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY8                ((uint32)(3u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY16               ((uint32)(4u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY32               ((uint32)(5u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY64               ((uint32)(6u << TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_PRESCALE_DIVBY128              ((uint32)(7u << TCounter_2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define TCounter_2_MODE_TIMER_COMPARE             ((uint32)(TCounter_2__COMPARE         <<  \
                                                                  TCounter_2_MODE_SHIFT))
#define TCounter_2_MODE_TIMER_CAPTURE             ((uint32)(TCounter_2__CAPTURE         <<  \
                                                                  TCounter_2_MODE_SHIFT))
#define TCounter_2_MODE_QUAD                      ((uint32)(TCounter_2__QUAD            <<  \
                                                                  TCounter_2_MODE_SHIFT))
#define TCounter_2_MODE_PWM                       ((uint32)(TCounter_2__PWM             <<  \
                                                                  TCounter_2_MODE_SHIFT))
#define TCounter_2_MODE_PWM_DT                    ((uint32)(TCounter_2__PWM_DT          <<  \
                                                                  TCounter_2_MODE_SHIFT))
#define TCounter_2_MODE_PWM_PR                    ((uint32)(TCounter_2__PWM_PR          <<  \
                                                                  TCounter_2_MODE_SHIFT))

/* Quad Modes */
#define TCounter_2_MODE_X1                        ((uint32)(TCounter_2__X1              <<  \
                                                                  TCounter_2_QUAD_MODE_SHIFT))
#define TCounter_2_MODE_X2                        ((uint32)(TCounter_2__X2              <<  \
                                                                  TCounter_2_QUAD_MODE_SHIFT))
#define TCounter_2_MODE_X4                        ((uint32)(TCounter_2__X4              <<  \
                                                                  TCounter_2_QUAD_MODE_SHIFT))

/* Counter modes */
#define TCounter_2_COUNT_UP                       ((uint32)(TCounter_2__COUNT_UP        <<  \
                                                                  TCounter_2_UPDOWN_SHIFT))
#define TCounter_2_COUNT_DOWN                     ((uint32)(TCounter_2__COUNT_DOWN      <<  \
                                                                  TCounter_2_UPDOWN_SHIFT))
#define TCounter_2_COUNT_UPDOWN0                  ((uint32)(TCounter_2__COUNT_UPDOWN0   <<  \
                                                                  TCounter_2_UPDOWN_SHIFT))
#define TCounter_2_COUNT_UPDOWN1                  ((uint32)(TCounter_2__COUNT_UPDOWN1   <<  \
                                                                  TCounter_2_UPDOWN_SHIFT))

/* PWM output invert */
#define TCounter_2_INVERT_LINE                    ((uint32)(TCounter_2__INVERSE         <<  \
                                                                  TCounter_2_INV_OUT_SHIFT))
#define TCounter_2_INVERT_LINE_N                  ((uint32)(TCounter_2__INVERSE         <<  \
                                                                  TCounter_2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define TCounter_2_TRIG_RISING                    ((uint32)TCounter_2__TRIG_RISING)
#define TCounter_2_TRIG_FALLING                   ((uint32)TCounter_2__TRIG_FALLING)
#define TCounter_2_TRIG_BOTH                      ((uint32)TCounter_2__TRIG_BOTH)
#define TCounter_2_TRIG_LEVEL                     ((uint32)TCounter_2__TRIG_LEVEL)

/* Interrupt mask */
#define TCounter_2_INTR_MASK_TC                   ((uint32)TCounter_2__INTR_MASK_TC)
#define TCounter_2_INTR_MASK_CC_MATCH             ((uint32)TCounter_2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define TCounter_2_CC_MATCH_SET                   (0x00u)
#define TCounter_2_CC_MATCH_CLEAR                 (0x01u)
#define TCounter_2_CC_MATCH_INVERT                (0x02u)
#define TCounter_2_CC_MATCH_NO_CHANGE             (0x03u)
#define TCounter_2_OVERLOW_SET                    (0x00u)
#define TCounter_2_OVERLOW_CLEAR                  (0x04u)
#define TCounter_2_OVERLOW_INVERT                 (0x08u)
#define TCounter_2_OVERLOW_NO_CHANGE              (0x0Cu)
#define TCounter_2_UNDERFLOW_SET                  (0x00u)
#define TCounter_2_UNDERFLOW_CLEAR                (0x10u)
#define TCounter_2_UNDERFLOW_INVERT               (0x20u)
#define TCounter_2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define TCounter_2_PWM_MODE_LEFT                  (TCounter_2_CC_MATCH_CLEAR        |   \
                                                         TCounter_2_OVERLOW_SET           |   \
                                                         TCounter_2_UNDERFLOW_NO_CHANGE)
#define TCounter_2_PWM_MODE_RIGHT                 (TCounter_2_CC_MATCH_SET          |   \
                                                         TCounter_2_OVERLOW_NO_CHANGE     |   \
                                                         TCounter_2_UNDERFLOW_CLEAR)
#define TCounter_2_PWM_MODE_ASYM                  (TCounter_2_CC_MATCH_INVERT       |   \
                                                         TCounter_2_OVERLOW_SET           |   \
                                                         TCounter_2_UNDERFLOW_CLEAR)

#if (TCounter_2_CY_TCPWM_V2)
    #if(TCounter_2_CY_TCPWM_4000)
        #define TCounter_2_PWM_MODE_CENTER                (TCounter_2_CC_MATCH_INVERT       |   \
                                                                 TCounter_2_OVERLOW_NO_CHANGE     |   \
                                                                 TCounter_2_UNDERFLOW_CLEAR)
    #else
        #define TCounter_2_PWM_MODE_CENTER                (TCounter_2_CC_MATCH_INVERT       |   \
                                                                 TCounter_2_OVERLOW_SET           |   \
                                                                 TCounter_2_UNDERFLOW_CLEAR)
    #endif /* (TCounter_2_CY_TCPWM_4000) */
#else
    #define TCounter_2_PWM_MODE_CENTER                (TCounter_2_CC_MATCH_INVERT       |   \
                                                             TCounter_2_OVERLOW_NO_CHANGE     |   \
                                                             TCounter_2_UNDERFLOW_CLEAR)
#endif /* (TCounter_2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define TCounter_2_CMD_CAPTURE                    (0u)
#define TCounter_2_CMD_RELOAD                     (8u)
#define TCounter_2_CMD_STOP                       (16u)
#define TCounter_2_CMD_START                      (24u)

/* Status */
#define TCounter_2_STATUS_DOWN                    (1u)
#define TCounter_2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   TCounter_2_Init(void);
void   TCounter_2_Enable(void);
void   TCounter_2_Start(void);
void   TCounter_2_Stop(void);

void   TCounter_2_SetMode(uint32 mode);
void   TCounter_2_SetCounterMode(uint32 counterMode);
void   TCounter_2_SetPWMMode(uint32 modeMask);
void   TCounter_2_SetQDMode(uint32 qdMode);

void   TCounter_2_SetPrescaler(uint32 prescaler);
void   TCounter_2_TriggerCommand(uint32 mask, uint32 command);
void   TCounter_2_SetOneShot(uint32 oneShotEnable);
uint32 TCounter_2_ReadStatus(void);

void   TCounter_2_SetPWMSyncKill(uint32 syncKillEnable);
void   TCounter_2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   TCounter_2_SetPWMDeadTime(uint32 deadTime);
void   TCounter_2_SetPWMInvert(uint32 mask);

void   TCounter_2_SetInterruptMode(uint32 interruptMask);
uint32 TCounter_2_GetInterruptSourceMasked(void);
uint32 TCounter_2_GetInterruptSource(void);
void   TCounter_2_ClearInterrupt(uint32 interruptMask);
void   TCounter_2_SetInterrupt(uint32 interruptMask);

void   TCounter_2_WriteCounter(uint32 count);
uint32 TCounter_2_ReadCounter(void);

uint32 TCounter_2_ReadCapture(void);
uint32 TCounter_2_ReadCaptureBuf(void);

void   TCounter_2_WritePeriod(uint32 period);
uint32 TCounter_2_ReadPeriod(void);
void   TCounter_2_WritePeriodBuf(uint32 periodBuf);
uint32 TCounter_2_ReadPeriodBuf(void);

void   TCounter_2_WriteCompare(uint32 compare);
uint32 TCounter_2_ReadCompare(void);
void   TCounter_2_WriteCompareBuf(uint32 compareBuf);
uint32 TCounter_2_ReadCompareBuf(void);

void   TCounter_2_SetPeriodSwap(uint32 swapEnable);
void   TCounter_2_SetCompareSwap(uint32 swapEnable);

void   TCounter_2_SetCaptureMode(uint32 triggerMode);
void   TCounter_2_SetReloadMode(uint32 triggerMode);
void   TCounter_2_SetStartMode(uint32 triggerMode);
void   TCounter_2_SetStopMode(uint32 triggerMode);
void   TCounter_2_SetCountMode(uint32 triggerMode);

void   TCounter_2_SaveConfig(void);
void   TCounter_2_RestoreConfig(void);
void   TCounter_2_Sleep(void);
void   TCounter_2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define TCounter_2_BLOCK_CONTROL_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TCounter_2_BLOCK_CONTROL_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TCounter_2_COMMAND_REG                    (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TCounter_2_COMMAND_PTR                    ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TCounter_2_INTRRUPT_CAUSE_REG             (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TCounter_2_INTRRUPT_CAUSE_PTR             ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TCounter_2_CONTROL_REG                    (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CTRL )
#define TCounter_2_CONTROL_PTR                    ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CTRL )
#define TCounter_2_STATUS_REG                     (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__STATUS )
#define TCounter_2_STATUS_PTR                     ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__STATUS )
#define TCounter_2_COUNTER_REG                    (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__COUNTER )
#define TCounter_2_COUNTER_PTR                    ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__COUNTER )
#define TCounter_2_COMP_CAP_REG                   (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CC )
#define TCounter_2_COMP_CAP_PTR                   ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CC )
#define TCounter_2_COMP_CAP_BUF_REG               (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define TCounter_2_COMP_CAP_BUF_PTR               ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define TCounter_2_PERIOD_REG                     (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__PERIOD )
#define TCounter_2_PERIOD_PTR                     ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__PERIOD )
#define TCounter_2_PERIOD_BUF_REG                 (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TCounter_2_PERIOD_BUF_PTR                 ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TCounter_2_TRIG_CONTROL0_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TCounter_2_TRIG_CONTROL0_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TCounter_2_TRIG_CONTROL1_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TCounter_2_TRIG_CONTROL1_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TCounter_2_TRIG_CONTROL2_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TCounter_2_TRIG_CONTROL2_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TCounter_2_INTERRUPT_REQ_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR )
#define TCounter_2_INTERRUPT_REQ_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR )
#define TCounter_2_INTERRUPT_SET_REG              (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_SET )
#define TCounter_2_INTERRUPT_SET_PTR              ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_SET )
#define TCounter_2_INTERRUPT_MASK_REG             (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define TCounter_2_INTERRUPT_MASK_PTR             ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define TCounter_2_INTERRUPT_MASKED_REG           (*(reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define TCounter_2_INTERRUPT_MASKED_PTR           ( (reg32 *) TCounter_2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define TCounter_2_MASK                           ((uint32)TCounter_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define TCounter_2_RELOAD_CC_SHIFT                (0u)
#define TCounter_2_RELOAD_PERIOD_SHIFT            (1u)
#define TCounter_2_PWM_SYNC_KILL_SHIFT            (2u)
#define TCounter_2_PWM_STOP_KILL_SHIFT            (3u)
#define TCounter_2_PRESCALER_SHIFT                (8u)
#define TCounter_2_UPDOWN_SHIFT                   (16u)
#define TCounter_2_ONESHOT_SHIFT                  (18u)
#define TCounter_2_QUAD_MODE_SHIFT                (20u)
#define TCounter_2_INV_OUT_SHIFT                  (20u)
#define TCounter_2_INV_COMPL_OUT_SHIFT            (21u)
#define TCounter_2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define TCounter_2_RELOAD_CC_MASK                 ((uint32)(TCounter_2_1BIT_MASK        <<  \
                                                                            TCounter_2_RELOAD_CC_SHIFT))
#define TCounter_2_RELOAD_PERIOD_MASK             ((uint32)(TCounter_2_1BIT_MASK        <<  \
                                                                            TCounter_2_RELOAD_PERIOD_SHIFT))
#define TCounter_2_PWM_SYNC_KILL_MASK             ((uint32)(TCounter_2_1BIT_MASK        <<  \
                                                                            TCounter_2_PWM_SYNC_KILL_SHIFT))
#define TCounter_2_PWM_STOP_KILL_MASK             ((uint32)(TCounter_2_1BIT_MASK        <<  \
                                                                            TCounter_2_PWM_STOP_KILL_SHIFT))
#define TCounter_2_PRESCALER_MASK                 ((uint32)(TCounter_2_8BIT_MASK        <<  \
                                                                            TCounter_2_PRESCALER_SHIFT))
#define TCounter_2_UPDOWN_MASK                    ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                            TCounter_2_UPDOWN_SHIFT))
#define TCounter_2_ONESHOT_MASK                   ((uint32)(TCounter_2_1BIT_MASK        <<  \
                                                                            TCounter_2_ONESHOT_SHIFT))
#define TCounter_2_QUAD_MODE_MASK                 ((uint32)(TCounter_2_3BIT_MASK        <<  \
                                                                            TCounter_2_QUAD_MODE_SHIFT))
#define TCounter_2_INV_OUT_MASK                   ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                            TCounter_2_INV_OUT_SHIFT))
#define TCounter_2_MODE_MASK                      ((uint32)(TCounter_2_3BIT_MASK        <<  \
                                                                            TCounter_2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define TCounter_2_CAPTURE_SHIFT                  (0u)
#define TCounter_2_COUNT_SHIFT                    (2u)
#define TCounter_2_RELOAD_SHIFT                   (4u)
#define TCounter_2_STOP_SHIFT                     (6u)
#define TCounter_2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define TCounter_2_CAPTURE_MASK                   ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                  TCounter_2_CAPTURE_SHIFT))
#define TCounter_2_COUNT_MASK                     ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                  TCounter_2_COUNT_SHIFT))
#define TCounter_2_RELOAD_MASK                    ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                  TCounter_2_RELOAD_SHIFT))
#define TCounter_2_STOP_MASK                      ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                  TCounter_2_STOP_SHIFT))
#define TCounter_2_START_MASK                     ((uint32)(TCounter_2_2BIT_MASK        <<  \
                                                                  TCounter_2_START_SHIFT))

/* MASK */
#define TCounter_2_1BIT_MASK                      ((uint32)0x01u)
#define TCounter_2_2BIT_MASK                      ((uint32)0x03u)
#define TCounter_2_3BIT_MASK                      ((uint32)0x07u)
#define TCounter_2_6BIT_MASK                      ((uint32)0x3Fu)
#define TCounter_2_8BIT_MASK                      ((uint32)0xFFu)
#define TCounter_2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define TCounter_2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define TCounter_2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(TCounter_2_QUAD_ENCODING_MODES     << TCounter_2_QUAD_MODE_SHIFT))       |\
         ((uint32)(TCounter_2_CONFIG                  << TCounter_2_MODE_SHIFT)))

#define TCounter_2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(TCounter_2_PWM_STOP_EVENT          << TCounter_2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(TCounter_2_PWM_OUT_INVERT          << TCounter_2_INV_OUT_SHIFT))         |\
         ((uint32)(TCounter_2_PWM_OUT_N_INVERT        << TCounter_2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(TCounter_2_PWM_MODE                << TCounter_2_MODE_SHIFT)))

#define TCounter_2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(TCounter_2_PWM_RUN_MODE         << TCounter_2_ONESHOT_SHIFT))
            
#define TCounter_2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(TCounter_2_PWM_ALIGN            << TCounter_2_UPDOWN_SHIFT))

#define TCounter_2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(TCounter_2_PWM_KILL_EVENT      << TCounter_2_PWM_SYNC_KILL_SHIFT))

#define TCounter_2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(TCounter_2_PWM_DEAD_TIME_CYCLE  << TCounter_2_PRESCALER_SHIFT))

#define TCounter_2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(TCounter_2_PWM_PRESCALER        << TCounter_2_PRESCALER_SHIFT))

#define TCounter_2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(TCounter_2_TC_PRESCALER            << TCounter_2_PRESCALER_SHIFT))       |\
         ((uint32)(TCounter_2_TC_COUNTER_MODE         << TCounter_2_UPDOWN_SHIFT))          |\
         ((uint32)(TCounter_2_TC_RUN_MODE             << TCounter_2_ONESHOT_SHIFT))         |\
         ((uint32)(TCounter_2_TC_COMP_CAP_MODE        << TCounter_2_MODE_SHIFT)))
        
#define TCounter_2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(TCounter_2_QUAD_PHIA_SIGNAL_MODE   << TCounter_2_COUNT_SHIFT))           |\
         ((uint32)(TCounter_2_QUAD_INDEX_SIGNAL_MODE  << TCounter_2_RELOAD_SHIFT))          |\
         ((uint32)(TCounter_2_QUAD_STOP_SIGNAL_MODE   << TCounter_2_STOP_SHIFT))            |\
         ((uint32)(TCounter_2_QUAD_PHIB_SIGNAL_MODE   << TCounter_2_START_SHIFT)))

#define TCounter_2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(TCounter_2_PWM_SWITCH_SIGNAL_MODE  << TCounter_2_CAPTURE_SHIFT))         |\
         ((uint32)(TCounter_2_PWM_COUNT_SIGNAL_MODE   << TCounter_2_COUNT_SHIFT))           |\
         ((uint32)(TCounter_2_PWM_RELOAD_SIGNAL_MODE  << TCounter_2_RELOAD_SHIFT))          |\
         ((uint32)(TCounter_2_PWM_STOP_SIGNAL_MODE    << TCounter_2_STOP_SHIFT))            |\
         ((uint32)(TCounter_2_PWM_START_SIGNAL_MODE   << TCounter_2_START_SHIFT)))

#define TCounter_2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(TCounter_2_TC_CAPTURE_SIGNAL_MODE  << TCounter_2_CAPTURE_SHIFT))         |\
         ((uint32)(TCounter_2_TC_COUNT_SIGNAL_MODE    << TCounter_2_COUNT_SHIFT))           |\
         ((uint32)(TCounter_2_TC_RELOAD_SIGNAL_MODE   << TCounter_2_RELOAD_SHIFT))          |\
         ((uint32)(TCounter_2_TC_STOP_SIGNAL_MODE     << TCounter_2_STOP_SHIFT))            |\
         ((uint32)(TCounter_2_TC_START_SIGNAL_MODE    << TCounter_2_START_SHIFT)))
        
#define TCounter_2_TIMER_UPDOWN_CNT_USED                                                          \
                ((TCounter_2__COUNT_UPDOWN0 == TCounter_2_TC_COUNTER_MODE)                  ||\
                 (TCounter_2__COUNT_UPDOWN1 == TCounter_2_TC_COUNTER_MODE))

#define TCounter_2_PWM_UPDOWN_CNT_USED                                                            \
                ((TCounter_2__CENTER == TCounter_2_PWM_ALIGN)                               ||\
                 (TCounter_2__ASYMMETRIC == TCounter_2_PWM_ALIGN))               
        
#define TCounter_2_PWM_PR_INIT_VALUE              (1u)
#define TCounter_2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_TCounter_2_H */

/* [] END OF FILE */
