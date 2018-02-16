/*******************************************************************************
* File Name: ExemplaryCounter.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the ExemplaryCounter
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

#if !defined(CY_TCPWM_ExemplaryCounter_H)
#define CY_TCPWM_ExemplaryCounter_H


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
} ExemplaryCounter_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  ExemplaryCounter_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define ExemplaryCounter_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define ExemplaryCounter_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define ExemplaryCounter_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define ExemplaryCounter_QUAD_ENCODING_MODES            (0lu)
#define ExemplaryCounter_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define ExemplaryCounter_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define ExemplaryCounter_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define ExemplaryCounter_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define ExemplaryCounter_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define ExemplaryCounter_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define ExemplaryCounter_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define ExemplaryCounter_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define ExemplaryCounter_TC_RUN_MODE                    (0lu)
#define ExemplaryCounter_TC_COUNTER_MODE                (0lu)
#define ExemplaryCounter_TC_COMP_CAP_MODE               (2lu)
#define ExemplaryCounter_TC_PRESCALER                   (0lu)

/* Signal modes */
#define ExemplaryCounter_TC_RELOAD_SIGNAL_MODE          (0lu)
#define ExemplaryCounter_TC_COUNT_SIGNAL_MODE           (1lu)
#define ExemplaryCounter_TC_START_SIGNAL_MODE           (0lu)
#define ExemplaryCounter_TC_STOP_SIGNAL_MODE            (1lu)
#define ExemplaryCounter_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define ExemplaryCounter_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define ExemplaryCounter_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define ExemplaryCounter_TC_START_SIGNAL_PRESENT        (0lu)
#define ExemplaryCounter_TC_STOP_SIGNAL_PRESENT         (0lu)
#define ExemplaryCounter_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define ExemplaryCounter_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define ExemplaryCounter_PWM_KILL_EVENT                 (0lu)
#define ExemplaryCounter_PWM_STOP_EVENT                 (0lu)
#define ExemplaryCounter_PWM_MODE                       (4lu)
#define ExemplaryCounter_PWM_OUT_N_INVERT               (0lu)
#define ExemplaryCounter_PWM_OUT_INVERT                 (0lu)
#define ExemplaryCounter_PWM_ALIGN                      (0lu)
#define ExemplaryCounter_PWM_RUN_MODE                   (0lu)
#define ExemplaryCounter_PWM_DEAD_TIME_CYCLE            (0lu)
#define ExemplaryCounter_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define ExemplaryCounter_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define ExemplaryCounter_PWM_COUNT_SIGNAL_MODE          (3lu)
#define ExemplaryCounter_PWM_START_SIGNAL_MODE          (0lu)
#define ExemplaryCounter_PWM_STOP_SIGNAL_MODE           (0lu)
#define ExemplaryCounter_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define ExemplaryCounter_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define ExemplaryCounter_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define ExemplaryCounter_PWM_START_SIGNAL_PRESENT       (0lu)
#define ExemplaryCounter_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define ExemplaryCounter_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define ExemplaryCounter_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define ExemplaryCounter_TC_PERIOD_VALUE                (65535lu)
#define ExemplaryCounter_TC_COMPARE_VALUE               (65535lu)
#define ExemplaryCounter_TC_COMPARE_BUF_VALUE           (65535lu)
#define ExemplaryCounter_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define ExemplaryCounter_PWM_PERIOD_VALUE               (65535lu)
#define ExemplaryCounter_PWM_PERIOD_BUF_VALUE           (65535lu)
#define ExemplaryCounter_PWM_PERIOD_SWAP                (0lu)
#define ExemplaryCounter_PWM_COMPARE_VALUE              (65535lu)
#define ExemplaryCounter_PWM_COMPARE_BUF_VALUE          (65535lu)
#define ExemplaryCounter_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define ExemplaryCounter__LEFT 0
#define ExemplaryCounter__RIGHT 1
#define ExemplaryCounter__CENTER 2
#define ExemplaryCounter__ASYMMETRIC 3

#define ExemplaryCounter__X1 0
#define ExemplaryCounter__X2 1
#define ExemplaryCounter__X4 2

#define ExemplaryCounter__PWM 4
#define ExemplaryCounter__PWM_DT 5
#define ExemplaryCounter__PWM_PR 6

#define ExemplaryCounter__INVERSE 1
#define ExemplaryCounter__DIRECT 0

#define ExemplaryCounter__CAPTURE 2
#define ExemplaryCounter__COMPARE 0

#define ExemplaryCounter__TRIG_LEVEL 3
#define ExemplaryCounter__TRIG_RISING 0
#define ExemplaryCounter__TRIG_FALLING 1
#define ExemplaryCounter__TRIG_BOTH 2

#define ExemplaryCounter__INTR_MASK_TC 1
#define ExemplaryCounter__INTR_MASK_CC_MATCH 2
#define ExemplaryCounter__INTR_MASK_NONE 0
#define ExemplaryCounter__INTR_MASK_TC_CC 3

#define ExemplaryCounter__UNCONFIG 8
#define ExemplaryCounter__TIMER 1
#define ExemplaryCounter__QUAD 3
#define ExemplaryCounter__PWM_SEL 7

#define ExemplaryCounter__COUNT_UP 0
#define ExemplaryCounter__COUNT_DOWN 1
#define ExemplaryCounter__COUNT_UPDOWN0 2
#define ExemplaryCounter__COUNT_UPDOWN1 3


/* Prescaler */
#define ExemplaryCounter_PRESCALE_DIVBY1                ((uint32)(0u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY2                ((uint32)(1u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY4                ((uint32)(2u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY8                ((uint32)(3u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY16               ((uint32)(4u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY32               ((uint32)(5u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY64               ((uint32)(6u << ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_PRESCALE_DIVBY128              ((uint32)(7u << ExemplaryCounter_PRESCALER_SHIFT))

/* TCPWM set modes */
#define ExemplaryCounter_MODE_TIMER_COMPARE             ((uint32)(ExemplaryCounter__COMPARE         <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))
#define ExemplaryCounter_MODE_TIMER_CAPTURE             ((uint32)(ExemplaryCounter__CAPTURE         <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))
#define ExemplaryCounter_MODE_QUAD                      ((uint32)(ExemplaryCounter__QUAD            <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))
#define ExemplaryCounter_MODE_PWM                       ((uint32)(ExemplaryCounter__PWM             <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))
#define ExemplaryCounter_MODE_PWM_DT                    ((uint32)(ExemplaryCounter__PWM_DT          <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))
#define ExemplaryCounter_MODE_PWM_PR                    ((uint32)(ExemplaryCounter__PWM_PR          <<  \
                                                                  ExemplaryCounter_MODE_SHIFT))

/* Quad Modes */
#define ExemplaryCounter_MODE_X1                        ((uint32)(ExemplaryCounter__X1              <<  \
                                                                  ExemplaryCounter_QUAD_MODE_SHIFT))
#define ExemplaryCounter_MODE_X2                        ((uint32)(ExemplaryCounter__X2              <<  \
                                                                  ExemplaryCounter_QUAD_MODE_SHIFT))
#define ExemplaryCounter_MODE_X4                        ((uint32)(ExemplaryCounter__X4              <<  \
                                                                  ExemplaryCounter_QUAD_MODE_SHIFT))

/* Counter modes */
#define ExemplaryCounter_COUNT_UP                       ((uint32)(ExemplaryCounter__COUNT_UP        <<  \
                                                                  ExemplaryCounter_UPDOWN_SHIFT))
#define ExemplaryCounter_COUNT_DOWN                     ((uint32)(ExemplaryCounter__COUNT_DOWN      <<  \
                                                                  ExemplaryCounter_UPDOWN_SHIFT))
#define ExemplaryCounter_COUNT_UPDOWN0                  ((uint32)(ExemplaryCounter__COUNT_UPDOWN0   <<  \
                                                                  ExemplaryCounter_UPDOWN_SHIFT))
#define ExemplaryCounter_COUNT_UPDOWN1                  ((uint32)(ExemplaryCounter__COUNT_UPDOWN1   <<  \
                                                                  ExemplaryCounter_UPDOWN_SHIFT))

/* PWM output invert */
#define ExemplaryCounter_INVERT_LINE                    ((uint32)(ExemplaryCounter__INVERSE         <<  \
                                                                  ExemplaryCounter_INV_OUT_SHIFT))
#define ExemplaryCounter_INVERT_LINE_N                  ((uint32)(ExemplaryCounter__INVERSE         <<  \
                                                                  ExemplaryCounter_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define ExemplaryCounter_TRIG_RISING                    ((uint32)ExemplaryCounter__TRIG_RISING)
#define ExemplaryCounter_TRIG_FALLING                   ((uint32)ExemplaryCounter__TRIG_FALLING)
#define ExemplaryCounter_TRIG_BOTH                      ((uint32)ExemplaryCounter__TRIG_BOTH)
#define ExemplaryCounter_TRIG_LEVEL                     ((uint32)ExemplaryCounter__TRIG_LEVEL)

/* Interrupt mask */
#define ExemplaryCounter_INTR_MASK_TC                   ((uint32)ExemplaryCounter__INTR_MASK_TC)
#define ExemplaryCounter_INTR_MASK_CC_MATCH             ((uint32)ExemplaryCounter__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define ExemplaryCounter_CC_MATCH_SET                   (0x00u)
#define ExemplaryCounter_CC_MATCH_CLEAR                 (0x01u)
#define ExemplaryCounter_CC_MATCH_INVERT                (0x02u)
#define ExemplaryCounter_CC_MATCH_NO_CHANGE             (0x03u)
#define ExemplaryCounter_OVERLOW_SET                    (0x00u)
#define ExemplaryCounter_OVERLOW_CLEAR                  (0x04u)
#define ExemplaryCounter_OVERLOW_INVERT                 (0x08u)
#define ExemplaryCounter_OVERLOW_NO_CHANGE              (0x0Cu)
#define ExemplaryCounter_UNDERFLOW_SET                  (0x00u)
#define ExemplaryCounter_UNDERFLOW_CLEAR                (0x10u)
#define ExemplaryCounter_UNDERFLOW_INVERT               (0x20u)
#define ExemplaryCounter_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define ExemplaryCounter_PWM_MODE_LEFT                  (ExemplaryCounter_CC_MATCH_CLEAR        |   \
                                                         ExemplaryCounter_OVERLOW_SET           |   \
                                                         ExemplaryCounter_UNDERFLOW_NO_CHANGE)
#define ExemplaryCounter_PWM_MODE_RIGHT                 (ExemplaryCounter_CC_MATCH_SET          |   \
                                                         ExemplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                         ExemplaryCounter_UNDERFLOW_CLEAR)
#define ExemplaryCounter_PWM_MODE_ASYM                  (ExemplaryCounter_CC_MATCH_INVERT       |   \
                                                         ExemplaryCounter_OVERLOW_SET           |   \
                                                         ExemplaryCounter_UNDERFLOW_CLEAR)

#if (ExemplaryCounter_CY_TCPWM_V2)
    #if(ExemplaryCounter_CY_TCPWM_4000)
        #define ExemplaryCounter_PWM_MODE_CENTER                (ExemplaryCounter_CC_MATCH_INVERT       |   \
                                                                 ExemplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                                 ExemplaryCounter_UNDERFLOW_CLEAR)
    #else
        #define ExemplaryCounter_PWM_MODE_CENTER                (ExemplaryCounter_CC_MATCH_INVERT       |   \
                                                                 ExemplaryCounter_OVERLOW_SET           |   \
                                                                 ExemplaryCounter_UNDERFLOW_CLEAR)
    #endif /* (ExemplaryCounter_CY_TCPWM_4000) */
#else
    #define ExemplaryCounter_PWM_MODE_CENTER                (ExemplaryCounter_CC_MATCH_INVERT       |   \
                                                             ExemplaryCounter_OVERLOW_NO_CHANGE     |   \
                                                             ExemplaryCounter_UNDERFLOW_CLEAR)
#endif /* (ExemplaryCounter_CY_TCPWM_NEW) */

/* Command operations without condition */
#define ExemplaryCounter_CMD_CAPTURE                    (0u)
#define ExemplaryCounter_CMD_RELOAD                     (8u)
#define ExemplaryCounter_CMD_STOP                       (16u)
#define ExemplaryCounter_CMD_START                      (24u)

/* Status */
#define ExemplaryCounter_STATUS_DOWN                    (1u)
#define ExemplaryCounter_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   ExemplaryCounter_Init(void);
void   ExemplaryCounter_Enable(void);
void   ExemplaryCounter_Start(void);
void   ExemplaryCounter_Stop(void);

void   ExemplaryCounter_SetMode(uint32 mode);
void   ExemplaryCounter_SetCounterMode(uint32 counterMode);
void   ExemplaryCounter_SetPWMMode(uint32 modeMask);
void   ExemplaryCounter_SetQDMode(uint32 qdMode);

void   ExemplaryCounter_SetPrescaler(uint32 prescaler);
void   ExemplaryCounter_TriggerCommand(uint32 mask, uint32 command);
void   ExemplaryCounter_SetOneShot(uint32 oneShotEnable);
uint32 ExemplaryCounter_ReadStatus(void);

void   ExemplaryCounter_SetPWMSyncKill(uint32 syncKillEnable);
void   ExemplaryCounter_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   ExemplaryCounter_SetPWMDeadTime(uint32 deadTime);
void   ExemplaryCounter_SetPWMInvert(uint32 mask);

void   ExemplaryCounter_SetInterruptMode(uint32 interruptMask);
uint32 ExemplaryCounter_GetInterruptSourceMasked(void);
uint32 ExemplaryCounter_GetInterruptSource(void);
void   ExemplaryCounter_ClearInterrupt(uint32 interruptMask);
void   ExemplaryCounter_SetInterrupt(uint32 interruptMask);

void   ExemplaryCounter_WriteCounter(uint32 count);
uint32 ExemplaryCounter_ReadCounter(void);

uint32 ExemplaryCounter_ReadCapture(void);
uint32 ExemplaryCounter_ReadCaptureBuf(void);

void   ExemplaryCounter_WritePeriod(uint32 period);
uint32 ExemplaryCounter_ReadPeriod(void);
void   ExemplaryCounter_WritePeriodBuf(uint32 periodBuf);
uint32 ExemplaryCounter_ReadPeriodBuf(void);

void   ExemplaryCounter_WriteCompare(uint32 compare);
uint32 ExemplaryCounter_ReadCompare(void);
void   ExemplaryCounter_WriteCompareBuf(uint32 compareBuf);
uint32 ExemplaryCounter_ReadCompareBuf(void);

void   ExemplaryCounter_SetPeriodSwap(uint32 swapEnable);
void   ExemplaryCounter_SetCompareSwap(uint32 swapEnable);

void   ExemplaryCounter_SetCaptureMode(uint32 triggerMode);
void   ExemplaryCounter_SetReloadMode(uint32 triggerMode);
void   ExemplaryCounter_SetStartMode(uint32 triggerMode);
void   ExemplaryCounter_SetStopMode(uint32 triggerMode);
void   ExemplaryCounter_SetCountMode(uint32 triggerMode);

void   ExemplaryCounter_SaveConfig(void);
void   ExemplaryCounter_RestoreConfig(void);
void   ExemplaryCounter_Sleep(void);
void   ExemplaryCounter_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define ExemplaryCounter_BLOCK_CONTROL_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define ExemplaryCounter_BLOCK_CONTROL_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define ExemplaryCounter_COMMAND_REG                    (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define ExemplaryCounter_COMMAND_PTR                    ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define ExemplaryCounter_INTRRUPT_CAUSE_REG             (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define ExemplaryCounter_INTRRUPT_CAUSE_PTR             ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define ExemplaryCounter_CONTROL_REG                    (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CTRL )
#define ExemplaryCounter_CONTROL_PTR                    ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CTRL )
#define ExemplaryCounter_STATUS_REG                     (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__STATUS )
#define ExemplaryCounter_STATUS_PTR                     ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__STATUS )
#define ExemplaryCounter_COUNTER_REG                    (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__COUNTER )
#define ExemplaryCounter_COUNTER_PTR                    ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__COUNTER )
#define ExemplaryCounter_COMP_CAP_REG                   (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CC )
#define ExemplaryCounter_COMP_CAP_PTR                   ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CC )
#define ExemplaryCounter_COMP_CAP_BUF_REG               (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define ExemplaryCounter_COMP_CAP_BUF_PTR               ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define ExemplaryCounter_PERIOD_REG                     (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__PERIOD )
#define ExemplaryCounter_PERIOD_PTR                     ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__PERIOD )
#define ExemplaryCounter_PERIOD_BUF_REG                 (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define ExemplaryCounter_PERIOD_BUF_PTR                 ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define ExemplaryCounter_TRIG_CONTROL0_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define ExemplaryCounter_TRIG_CONTROL0_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define ExemplaryCounter_TRIG_CONTROL1_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define ExemplaryCounter_TRIG_CONTROL1_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define ExemplaryCounter_TRIG_CONTROL2_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define ExemplaryCounter_TRIG_CONTROL2_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define ExemplaryCounter_INTERRUPT_REQ_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR )
#define ExemplaryCounter_INTERRUPT_REQ_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR )
#define ExemplaryCounter_INTERRUPT_SET_REG              (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define ExemplaryCounter_INTERRUPT_SET_PTR              ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define ExemplaryCounter_INTERRUPT_MASK_REG             (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define ExemplaryCounter_INTERRUPT_MASK_PTR             ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define ExemplaryCounter_INTERRUPT_MASKED_REG           (*(reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_MASKED )
#define ExemplaryCounter_INTERRUPT_MASKED_PTR           ( (reg32 *) ExemplaryCounter_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define ExemplaryCounter_MASK                           ((uint32)ExemplaryCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define ExemplaryCounter_RELOAD_CC_SHIFT                (0u)
#define ExemplaryCounter_RELOAD_PERIOD_SHIFT            (1u)
#define ExemplaryCounter_PWM_SYNC_KILL_SHIFT            (2u)
#define ExemplaryCounter_PWM_STOP_KILL_SHIFT            (3u)
#define ExemplaryCounter_PRESCALER_SHIFT                (8u)
#define ExemplaryCounter_UPDOWN_SHIFT                   (16u)
#define ExemplaryCounter_ONESHOT_SHIFT                  (18u)
#define ExemplaryCounter_QUAD_MODE_SHIFT                (20u)
#define ExemplaryCounter_INV_OUT_SHIFT                  (20u)
#define ExemplaryCounter_INV_COMPL_OUT_SHIFT            (21u)
#define ExemplaryCounter_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define ExemplaryCounter_RELOAD_CC_MASK                 ((uint32)(ExemplaryCounter_1BIT_MASK        <<  \
                                                                            ExemplaryCounter_RELOAD_CC_SHIFT))
#define ExemplaryCounter_RELOAD_PERIOD_MASK             ((uint32)(ExemplaryCounter_1BIT_MASK        <<  \
                                                                            ExemplaryCounter_RELOAD_PERIOD_SHIFT))
#define ExemplaryCounter_PWM_SYNC_KILL_MASK             ((uint32)(ExemplaryCounter_1BIT_MASK        <<  \
                                                                            ExemplaryCounter_PWM_SYNC_KILL_SHIFT))
#define ExemplaryCounter_PWM_STOP_KILL_MASK             ((uint32)(ExemplaryCounter_1BIT_MASK        <<  \
                                                                            ExemplaryCounter_PWM_STOP_KILL_SHIFT))
#define ExemplaryCounter_PRESCALER_MASK                 ((uint32)(ExemplaryCounter_8BIT_MASK        <<  \
                                                                            ExemplaryCounter_PRESCALER_SHIFT))
#define ExemplaryCounter_UPDOWN_MASK                    ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                            ExemplaryCounter_UPDOWN_SHIFT))
#define ExemplaryCounter_ONESHOT_MASK                   ((uint32)(ExemplaryCounter_1BIT_MASK        <<  \
                                                                            ExemplaryCounter_ONESHOT_SHIFT))
#define ExemplaryCounter_QUAD_MODE_MASK                 ((uint32)(ExemplaryCounter_3BIT_MASK        <<  \
                                                                            ExemplaryCounter_QUAD_MODE_SHIFT))
#define ExemplaryCounter_INV_OUT_MASK                   ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                            ExemplaryCounter_INV_OUT_SHIFT))
#define ExemplaryCounter_MODE_MASK                      ((uint32)(ExemplaryCounter_3BIT_MASK        <<  \
                                                                            ExemplaryCounter_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define ExemplaryCounter_CAPTURE_SHIFT                  (0u)
#define ExemplaryCounter_COUNT_SHIFT                    (2u)
#define ExemplaryCounter_RELOAD_SHIFT                   (4u)
#define ExemplaryCounter_STOP_SHIFT                     (6u)
#define ExemplaryCounter_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define ExemplaryCounter_CAPTURE_MASK                   ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                  ExemplaryCounter_CAPTURE_SHIFT))
#define ExemplaryCounter_COUNT_MASK                     ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                  ExemplaryCounter_COUNT_SHIFT))
#define ExemplaryCounter_RELOAD_MASK                    ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                  ExemplaryCounter_RELOAD_SHIFT))
#define ExemplaryCounter_STOP_MASK                      ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                  ExemplaryCounter_STOP_SHIFT))
#define ExemplaryCounter_START_MASK                     ((uint32)(ExemplaryCounter_2BIT_MASK        <<  \
                                                                  ExemplaryCounter_START_SHIFT))

/* MASK */
#define ExemplaryCounter_1BIT_MASK                      ((uint32)0x01u)
#define ExemplaryCounter_2BIT_MASK                      ((uint32)0x03u)
#define ExemplaryCounter_3BIT_MASK                      ((uint32)0x07u)
#define ExemplaryCounter_6BIT_MASK                      ((uint32)0x3Fu)
#define ExemplaryCounter_8BIT_MASK                      ((uint32)0xFFu)
#define ExemplaryCounter_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define ExemplaryCounter_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define ExemplaryCounter_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(ExemplaryCounter_QUAD_ENCODING_MODES     << ExemplaryCounter_QUAD_MODE_SHIFT))       |\
         ((uint32)(ExemplaryCounter_CONFIG                  << ExemplaryCounter_MODE_SHIFT)))

#define ExemplaryCounter_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(ExemplaryCounter_PWM_STOP_EVENT          << ExemplaryCounter_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(ExemplaryCounter_PWM_OUT_INVERT          << ExemplaryCounter_INV_OUT_SHIFT))         |\
         ((uint32)(ExemplaryCounter_PWM_OUT_N_INVERT        << ExemplaryCounter_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(ExemplaryCounter_PWM_MODE                << ExemplaryCounter_MODE_SHIFT)))

#define ExemplaryCounter_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(ExemplaryCounter_PWM_RUN_MODE         << ExemplaryCounter_ONESHOT_SHIFT))
            
#define ExemplaryCounter_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(ExemplaryCounter_PWM_ALIGN            << ExemplaryCounter_UPDOWN_SHIFT))

#define ExemplaryCounter_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(ExemplaryCounter_PWM_KILL_EVENT      << ExemplaryCounter_PWM_SYNC_KILL_SHIFT))

#define ExemplaryCounter_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(ExemplaryCounter_PWM_DEAD_TIME_CYCLE  << ExemplaryCounter_PRESCALER_SHIFT))

#define ExemplaryCounter_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(ExemplaryCounter_PWM_PRESCALER        << ExemplaryCounter_PRESCALER_SHIFT))

#define ExemplaryCounter_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(ExemplaryCounter_TC_PRESCALER            << ExemplaryCounter_PRESCALER_SHIFT))       |\
         ((uint32)(ExemplaryCounter_TC_COUNTER_MODE         << ExemplaryCounter_UPDOWN_SHIFT))          |\
         ((uint32)(ExemplaryCounter_TC_RUN_MODE             << ExemplaryCounter_ONESHOT_SHIFT))         |\
         ((uint32)(ExemplaryCounter_TC_COMP_CAP_MODE        << ExemplaryCounter_MODE_SHIFT)))
        
#define ExemplaryCounter_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(ExemplaryCounter_QUAD_PHIA_SIGNAL_MODE   << ExemplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExemplaryCounter_QUAD_INDEX_SIGNAL_MODE  << ExemplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExemplaryCounter_QUAD_STOP_SIGNAL_MODE   << ExemplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExemplaryCounter_QUAD_PHIB_SIGNAL_MODE   << ExemplaryCounter_START_SHIFT)))

#define ExemplaryCounter_PWM_SIGNALS_MODES                                                              \
        (((uint32)(ExemplaryCounter_PWM_SWITCH_SIGNAL_MODE  << ExemplaryCounter_CAPTURE_SHIFT))         |\
         ((uint32)(ExemplaryCounter_PWM_COUNT_SIGNAL_MODE   << ExemplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExemplaryCounter_PWM_RELOAD_SIGNAL_MODE  << ExemplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExemplaryCounter_PWM_STOP_SIGNAL_MODE    << ExemplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExemplaryCounter_PWM_START_SIGNAL_MODE   << ExemplaryCounter_START_SHIFT)))

#define ExemplaryCounter_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(ExemplaryCounter_TC_CAPTURE_SIGNAL_MODE  << ExemplaryCounter_CAPTURE_SHIFT))         |\
         ((uint32)(ExemplaryCounter_TC_COUNT_SIGNAL_MODE    << ExemplaryCounter_COUNT_SHIFT))           |\
         ((uint32)(ExemplaryCounter_TC_RELOAD_SIGNAL_MODE   << ExemplaryCounter_RELOAD_SHIFT))          |\
         ((uint32)(ExemplaryCounter_TC_STOP_SIGNAL_MODE     << ExemplaryCounter_STOP_SHIFT))            |\
         ((uint32)(ExemplaryCounter_TC_START_SIGNAL_MODE    << ExemplaryCounter_START_SHIFT)))
        
#define ExemplaryCounter_TIMER_UPDOWN_CNT_USED                                                          \
                ((ExemplaryCounter__COUNT_UPDOWN0 == ExemplaryCounter_TC_COUNTER_MODE)                  ||\
                 (ExemplaryCounter__COUNT_UPDOWN1 == ExemplaryCounter_TC_COUNTER_MODE))

#define ExemplaryCounter_PWM_UPDOWN_CNT_USED                                                            \
                ((ExemplaryCounter__CENTER == ExemplaryCounter_PWM_ALIGN)                               ||\
                 (ExemplaryCounter__ASYMMETRIC == ExemplaryCounter_PWM_ALIGN))               
        
#define ExemplaryCounter_PWM_PR_INIT_VALUE              (1u)
#define ExemplaryCounter_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_ExemplaryCounter_H */

/* [] END OF FILE */
