/*******************************************************************************
* File Name: ExamplaryCounter.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the ExamplaryCounter
*  component
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

#include "ExamplaryCounter.h"

uint8 ExamplaryCounter_initVar = 0u;


/*******************************************************************************
* Function Name: ExamplaryCounter_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default ExamplaryCounter configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (ExamplaryCounter__QUAD == ExamplaryCounter_CONFIG)
        ExamplaryCounter_CONTROL_REG = ExamplaryCounter_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        ExamplaryCounter_TRIG_CONTROL1_REG  = ExamplaryCounter_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        ExamplaryCounter_SetInterruptMode(ExamplaryCounter_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        ExamplaryCounter_SetCounterMode(ExamplaryCounter_COUNT_DOWN);
        ExamplaryCounter_WritePeriod(ExamplaryCounter_QUAD_PERIOD_INIT_VALUE);
        ExamplaryCounter_WriteCounter(ExamplaryCounter_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (ExamplaryCounter__QUAD == ExamplaryCounter_CONFIG) */

    #if (ExamplaryCounter__TIMER == ExamplaryCounter_CONFIG)
        ExamplaryCounter_CONTROL_REG = ExamplaryCounter_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        ExamplaryCounter_TRIG_CONTROL1_REG  = ExamplaryCounter_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        ExamplaryCounter_SetInterruptMode(ExamplaryCounter_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        ExamplaryCounter_WritePeriod(ExamplaryCounter_TC_PERIOD_VALUE );

        #if (ExamplaryCounter__COMPARE == ExamplaryCounter_TC_COMP_CAP_MODE)
            ExamplaryCounter_WriteCompare(ExamplaryCounter_TC_COMPARE_VALUE);

            #if (1u == ExamplaryCounter_TC_COMPARE_SWAP)
                ExamplaryCounter_SetCompareSwap(1u);
                ExamplaryCounter_WriteCompareBuf(ExamplaryCounter_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == ExamplaryCounter_TC_COMPARE_SWAP) */
        #endif  /* (ExamplaryCounter__COMPARE == ExamplaryCounter_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (ExamplaryCounter_CY_TCPWM_V2 && ExamplaryCounter_TIMER_UPDOWN_CNT_USED && !ExamplaryCounter_CY_TCPWM_4000)
            ExamplaryCounter_WriteCounter(1u);
        #elif(ExamplaryCounter__COUNT_DOWN == ExamplaryCounter_TC_COUNTER_MODE)
            ExamplaryCounter_WriteCounter(ExamplaryCounter_TC_PERIOD_VALUE);
        #else
            ExamplaryCounter_WriteCounter(0u);
        #endif /* (ExamplaryCounter_CY_TCPWM_V2 && ExamplaryCounter_TIMER_UPDOWN_CNT_USED && !ExamplaryCounter_CY_TCPWM_4000) */
    #endif  /* (ExamplaryCounter__TIMER == ExamplaryCounter_CONFIG) */

    #if (ExamplaryCounter__PWM_SEL == ExamplaryCounter_CONFIG)
        ExamplaryCounter_CONTROL_REG = ExamplaryCounter_CTRL_PWM_BASE_CONFIG;

        #if (ExamplaryCounter__PWM_PR == ExamplaryCounter_PWM_MODE)
            ExamplaryCounter_CONTROL_REG |= ExamplaryCounter_CTRL_PWM_RUN_MODE;
            ExamplaryCounter_WriteCounter(ExamplaryCounter_PWM_PR_INIT_VALUE);
        #else
            ExamplaryCounter_CONTROL_REG |= ExamplaryCounter_CTRL_PWM_ALIGN | ExamplaryCounter_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (ExamplaryCounter_CY_TCPWM_V2 && ExamplaryCounter_PWM_UPDOWN_CNT_USED && !ExamplaryCounter_CY_TCPWM_4000)
                ExamplaryCounter_WriteCounter(1u);
            #elif (ExamplaryCounter__RIGHT == ExamplaryCounter_PWM_ALIGN)
                ExamplaryCounter_WriteCounter(ExamplaryCounter_PWM_PERIOD_VALUE);
            #else 
                ExamplaryCounter_WriteCounter(0u);
            #endif  /* (ExamplaryCounter_CY_TCPWM_V2 && ExamplaryCounter_PWM_UPDOWN_CNT_USED && !ExamplaryCounter_CY_TCPWM_4000) */
        #endif  /* (ExamplaryCounter__PWM_PR == ExamplaryCounter_PWM_MODE) */

        #if (ExamplaryCounter__PWM_DT == ExamplaryCounter_PWM_MODE)
            ExamplaryCounter_CONTROL_REG |= ExamplaryCounter_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (ExamplaryCounter__PWM_DT == ExamplaryCounter_PWM_MODE) */

        #if (ExamplaryCounter__PWM == ExamplaryCounter_PWM_MODE)
            ExamplaryCounter_CONTROL_REG |= ExamplaryCounter_CTRL_PWM_PRESCALER;
        #endif  /* (ExamplaryCounter__PWM == ExamplaryCounter_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        ExamplaryCounter_TRIG_CONTROL1_REG  = ExamplaryCounter_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        ExamplaryCounter_SetInterruptMode(ExamplaryCounter_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (ExamplaryCounter__PWM_PR == ExamplaryCounter_PWM_MODE)
            ExamplaryCounter_TRIG_CONTROL2_REG =
                    (ExamplaryCounter_CC_MATCH_NO_CHANGE    |
                    ExamplaryCounter_OVERLOW_NO_CHANGE      |
                    ExamplaryCounter_UNDERFLOW_NO_CHANGE);
        #else
            #if (ExamplaryCounter__LEFT == ExamplaryCounter_PWM_ALIGN)
                ExamplaryCounter_TRIG_CONTROL2_REG = ExamplaryCounter_PWM_MODE_LEFT;
            #endif  /* ( ExamplaryCounter_PWM_LEFT == ExamplaryCounter_PWM_ALIGN) */

            #if (ExamplaryCounter__RIGHT == ExamplaryCounter_PWM_ALIGN)
                ExamplaryCounter_TRIG_CONTROL2_REG = ExamplaryCounter_PWM_MODE_RIGHT;
            #endif  /* ( ExamplaryCounter_PWM_RIGHT == ExamplaryCounter_PWM_ALIGN) */

            #if (ExamplaryCounter__CENTER == ExamplaryCounter_PWM_ALIGN)
                ExamplaryCounter_TRIG_CONTROL2_REG = ExamplaryCounter_PWM_MODE_CENTER;
            #endif  /* ( ExamplaryCounter_PWM_CENTER == ExamplaryCounter_PWM_ALIGN) */

            #if (ExamplaryCounter__ASYMMETRIC == ExamplaryCounter_PWM_ALIGN)
                ExamplaryCounter_TRIG_CONTROL2_REG = ExamplaryCounter_PWM_MODE_ASYM;
            #endif  /* (ExamplaryCounter__ASYMMETRIC == ExamplaryCounter_PWM_ALIGN) */
        #endif  /* (ExamplaryCounter__PWM_PR == ExamplaryCounter_PWM_MODE) */

        /* Set other values from customizer */
        ExamplaryCounter_WritePeriod(ExamplaryCounter_PWM_PERIOD_VALUE );
        ExamplaryCounter_WriteCompare(ExamplaryCounter_PWM_COMPARE_VALUE);

        #if (1u == ExamplaryCounter_PWM_COMPARE_SWAP)
            ExamplaryCounter_SetCompareSwap(1u);
            ExamplaryCounter_WriteCompareBuf(ExamplaryCounter_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == ExamplaryCounter_PWM_COMPARE_SWAP) */

        #if (1u == ExamplaryCounter_PWM_PERIOD_SWAP)
            ExamplaryCounter_SetPeriodSwap(1u);
            ExamplaryCounter_WritePeriodBuf(ExamplaryCounter_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == ExamplaryCounter_PWM_PERIOD_SWAP) */
    #endif  /* (ExamplaryCounter__PWM_SEL == ExamplaryCounter_CONFIG) */
    
}


/*******************************************************************************
* Function Name: ExamplaryCounter_Enable
********************************************************************************
*
* Summary:
*  Enables the ExamplaryCounter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    ExamplaryCounter_BLOCK_CONTROL_REG |= ExamplaryCounter_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (ExamplaryCounter__PWM_SEL == ExamplaryCounter_CONFIG)
        #if (0u == ExamplaryCounter_PWM_START_SIGNAL_PRESENT)
            ExamplaryCounter_TriggerCommand(ExamplaryCounter_MASK, ExamplaryCounter_CMD_START);
        #endif /* (0u == ExamplaryCounter_PWM_START_SIGNAL_PRESENT) */
    #endif /* (ExamplaryCounter__PWM_SEL == ExamplaryCounter_CONFIG) */

    #if (ExamplaryCounter__TIMER == ExamplaryCounter_CONFIG)
        #if (0u == ExamplaryCounter_TC_START_SIGNAL_PRESENT)
            ExamplaryCounter_TriggerCommand(ExamplaryCounter_MASK, ExamplaryCounter_CMD_START);
        #endif /* (0u == ExamplaryCounter_TC_START_SIGNAL_PRESENT) */
    #endif /* (ExamplaryCounter__TIMER == ExamplaryCounter_CONFIG) */
    
    #if (ExamplaryCounter__QUAD == ExamplaryCounter_CONFIG)
        #if (0u != ExamplaryCounter_QUAD_AUTO_START)
            ExamplaryCounter_TriggerCommand(ExamplaryCounter_MASK, ExamplaryCounter_CMD_RELOAD);
        #endif /* (0u != ExamplaryCounter_QUAD_AUTO_START) */
    #endif  /* (ExamplaryCounter__QUAD == ExamplaryCounter_CONFIG) */
}


/*******************************************************************************
* Function Name: ExamplaryCounter_Start
********************************************************************************
*
* Summary:
*  Initializes the ExamplaryCounter with default customizer
*  values when called the first time and enables the ExamplaryCounter.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ExamplaryCounter_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time ExamplaryCounter_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the ExamplaryCounter_Start() routine.
*
*******************************************************************************/
void ExamplaryCounter_Start(void)
{
    if (0u == ExamplaryCounter_initVar)
    {
        ExamplaryCounter_Init();
        ExamplaryCounter_initVar = 1u;
    }

    ExamplaryCounter_Enable();
}


/*******************************************************************************
* Function Name: ExamplaryCounter_Stop
********************************************************************************
*
* Summary:
*  Disables the ExamplaryCounter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_BLOCK_CONTROL_REG &= (uint32)~ExamplaryCounter_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the ExamplaryCounter. This function is used when
*  configured as a generic ExamplaryCounter and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the ExamplaryCounter to operate in
*   Values:
*   - ExamplaryCounter_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - ExamplaryCounter_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - ExamplaryCounter_MODE_QUAD - Quadrature decoder
*         - ExamplaryCounter_MODE_PWM - PWM
*         - ExamplaryCounter_MODE_PWM_DT - PWM with dead time
*         - ExamplaryCounter_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_MODE_MASK;
    ExamplaryCounter_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - ExamplaryCounter_MODE_X1 - Counts on phi 1 rising
*         - ExamplaryCounter_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - ExamplaryCounter_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_QUAD_MODE_MASK;
    ExamplaryCounter_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - ExamplaryCounter_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - ExamplaryCounter_PRESCALE_DIVBY2    - Divide by 2
*         - ExamplaryCounter_PRESCALE_DIVBY4    - Divide by 4
*         - ExamplaryCounter_PRESCALE_DIVBY8    - Divide by 8
*         - ExamplaryCounter_PRESCALE_DIVBY16   - Divide by 16
*         - ExamplaryCounter_PRESCALE_DIVBY32   - Divide by 32
*         - ExamplaryCounter_PRESCALE_DIVBY64   - Divide by 64
*         - ExamplaryCounter_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_PRESCALER_MASK;
    ExamplaryCounter_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the ExamplaryCounter runs
*  continuously or stops when terminal count is reached.  By default the
*  ExamplaryCounter operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_ONESHOT_MASK;
    ExamplaryCounter_CONTROL_REG |= ((uint32)((oneShotEnable & ExamplaryCounter_1BIT_MASK) <<
                                                               ExamplaryCounter_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPWMMode(uint32 modeMask)
{
    ExamplaryCounter_TRIG_CONTROL2_REG = (modeMask & ExamplaryCounter_6BIT_MASK);
}



/*******************************************************************************
* Function Name: ExamplaryCounter_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_PWM_SYNC_KILL_MASK;
    ExamplaryCounter_CONTROL_REG |= ((uint32)((syncKillEnable & ExamplaryCounter_1BIT_MASK)  <<
                                               ExamplaryCounter_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_PWM_STOP_KILL_MASK;
    ExamplaryCounter_CONTROL_REG |= ((uint32)((stopOnKillEnable & ExamplaryCounter_1BIT_MASK)  <<
                                                         ExamplaryCounter_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_PRESCALER_MASK;
    ExamplaryCounter_CONTROL_REG |= ((uint32)((deadTime & ExamplaryCounter_8BIT_MASK) <<
                                                          ExamplaryCounter_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - ExamplaryCounter_INVERT_LINE   - Inverts the line output
*         - ExamplaryCounter_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_INV_OUT_MASK;
    ExamplaryCounter_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: ExamplaryCounter_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_WriteCounter(uint32 count)
{
    ExamplaryCounter_COUNTER_REG = (count & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadCounter(void)
{
    return (ExamplaryCounter_COUNTER_REG & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - ExamplaryCounter_COUNT_UP       - Counts up
*     - ExamplaryCounter_COUNT_DOWN     - Counts down
*     - ExamplaryCounter_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - ExamplaryCounter_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_UPDOWN_MASK;
    ExamplaryCounter_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_WritePeriod(uint32 period)
{
    ExamplaryCounter_PERIOD_REG = (period & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadPeriod(void)
{
    return (ExamplaryCounter_PERIOD_REG & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_RELOAD_CC_MASK;
    ExamplaryCounter_CONTROL_REG |= (swapEnable & ExamplaryCounter_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_WritePeriodBuf(uint32 periodBuf)
{
    ExamplaryCounter_PERIOD_BUF_REG = (periodBuf & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadPeriodBuf(void)
{
    return (ExamplaryCounter_PERIOD_BUF_REG & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_CONTROL_REG &= (uint32)~ExamplaryCounter_RELOAD_PERIOD_MASK;
    ExamplaryCounter_CONTROL_REG |= ((uint32)((swapEnable & ExamplaryCounter_1BIT_MASK) <<
                                                            ExamplaryCounter_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void ExamplaryCounter_WriteCompare(uint32 compare)
{
    #if (ExamplaryCounter_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */

    #if (ExamplaryCounter_CY_TCPWM_4000)
        currentMode = ((ExamplaryCounter_CONTROL_REG & ExamplaryCounter_UPDOWN_MASK) >> ExamplaryCounter_UPDOWN_SHIFT);

        if (((uint32)ExamplaryCounter__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)ExamplaryCounter__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */
    
    ExamplaryCounter_COMP_CAP_REG = (compare & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadCompare(void)
{
    #if (ExamplaryCounter_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */

    #if (ExamplaryCounter_CY_TCPWM_4000)
        currentMode = ((ExamplaryCounter_CONTROL_REG & ExamplaryCounter_UPDOWN_MASK) >> ExamplaryCounter_UPDOWN_SHIFT);
        
        regVal = ExamplaryCounter_COMP_CAP_REG;
        
        if (((uint32)ExamplaryCounter__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)ExamplaryCounter__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & ExamplaryCounter_16BIT_MASK);
    #else
        return (ExamplaryCounter_COMP_CAP_REG & ExamplaryCounter_16BIT_MASK);
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: ExamplaryCounter_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void ExamplaryCounter_WriteCompareBuf(uint32 compareBuf)
{
    #if (ExamplaryCounter_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */

    #if (ExamplaryCounter_CY_TCPWM_4000)
        currentMode = ((ExamplaryCounter_CONTROL_REG & ExamplaryCounter_UPDOWN_MASK) >> ExamplaryCounter_UPDOWN_SHIFT);

        if (((uint32)ExamplaryCounter__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)ExamplaryCounter__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */
    
    ExamplaryCounter_COMP_CAP_BUF_REG = (compareBuf & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadCompareBuf(void)
{
    #if (ExamplaryCounter_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */

    #if (ExamplaryCounter_CY_TCPWM_4000)
        currentMode = ((ExamplaryCounter_CONTROL_REG & ExamplaryCounter_UPDOWN_MASK) >> ExamplaryCounter_UPDOWN_SHIFT);

        regVal = ExamplaryCounter_COMP_CAP_BUF_REG;
        
        if (((uint32)ExamplaryCounter__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)ExamplaryCounter__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & ExamplaryCounter_16BIT_MASK);
    #else
        return (ExamplaryCounter_COMP_CAP_BUF_REG & ExamplaryCounter_16BIT_MASK);
    #endif /* (ExamplaryCounter_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadCapture(void)
{
    return (ExamplaryCounter_COMP_CAP_REG & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadCaptureBuf(void)
{
    return (ExamplaryCounter_COMP_CAP_BUF_REG & ExamplaryCounter_16BIT_MASK);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - ExamplaryCounter_TRIG_LEVEL     - Level
*     - ExamplaryCounter_TRIG_RISING    - Rising edge
*     - ExamplaryCounter_TRIG_FALLING   - Falling edge
*     - ExamplaryCounter_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_TRIG_CONTROL1_REG &= (uint32)~ExamplaryCounter_CAPTURE_MASK;
    ExamplaryCounter_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - ExamplaryCounter_TRIG_LEVEL     - Level
*     - ExamplaryCounter_TRIG_RISING    - Rising edge
*     - ExamplaryCounter_TRIG_FALLING   - Falling edge
*     - ExamplaryCounter_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_TRIG_CONTROL1_REG &= (uint32)~ExamplaryCounter_RELOAD_MASK;
    ExamplaryCounter_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << ExamplaryCounter_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - ExamplaryCounter_TRIG_LEVEL     - Level
*     - ExamplaryCounter_TRIG_RISING    - Rising edge
*     - ExamplaryCounter_TRIG_FALLING   - Falling edge
*     - ExamplaryCounter_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_TRIG_CONTROL1_REG &= (uint32)~ExamplaryCounter_START_MASK;
    ExamplaryCounter_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << ExamplaryCounter_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - ExamplaryCounter_TRIG_LEVEL     - Level
*     - ExamplaryCounter_TRIG_RISING    - Rising edge
*     - ExamplaryCounter_TRIG_FALLING   - Falling edge
*     - ExamplaryCounter_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_TRIG_CONTROL1_REG &= (uint32)~ExamplaryCounter_STOP_MASK;
    ExamplaryCounter_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << ExamplaryCounter_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - ExamplaryCounter_TRIG_LEVEL     - Level
*     - ExamplaryCounter_TRIG_RISING    - Rising edge
*     - ExamplaryCounter_TRIG_FALLING   - Falling edge
*     - ExamplaryCounter_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_TRIG_CONTROL1_REG &= (uint32)~ExamplaryCounter_COUNT_MASK;
    ExamplaryCounter_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << ExamplaryCounter_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - ExamplaryCounter_CMD_CAPTURE    - Trigger Capture/Switch command
*     - ExamplaryCounter_CMD_RELOAD     - Trigger Reload/Index command
*     - ExamplaryCounter_CMD_STOP       - Trigger Stop/Kill command
*     - ExamplaryCounter_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    ExamplaryCounter_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the ExamplaryCounter.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - ExamplaryCounter_STATUS_DOWN    - Set if counting down
*     - ExamplaryCounter_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 ExamplaryCounter_ReadStatus(void)
{
    return ((ExamplaryCounter_STATUS_REG >> ExamplaryCounter_RUNNING_STATUS_SHIFT) |
            (ExamplaryCounter_STATUS_REG & ExamplaryCounter_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - ExamplaryCounter_INTR_MASK_TC       - Terminal count mask
*     - ExamplaryCounter_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetInterruptMode(uint32 interruptMask)
{
    ExamplaryCounter_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: ExamplaryCounter_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - ExamplaryCounter_INTR_MASK_TC       - Terminal count mask
*     - ExamplaryCounter_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 ExamplaryCounter_GetInterruptSourceMasked(void)
{
    return (ExamplaryCounter_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - ExamplaryCounter_INTR_MASK_TC       - Terminal count mask
*     - ExamplaryCounter_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 ExamplaryCounter_GetInterruptSource(void)
{
    return (ExamplaryCounter_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: ExamplaryCounter_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - ExamplaryCounter_INTR_MASK_TC       - Terminal count mask
*     - ExamplaryCounter_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_ClearInterrupt(uint32 interruptMask)
{
    ExamplaryCounter_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: ExamplaryCounter_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - ExamplaryCounter_INTR_MASK_TC       - Terminal count mask
*     - ExamplaryCounter_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void ExamplaryCounter_SetInterrupt(uint32 interruptMask)
{
    ExamplaryCounter_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
