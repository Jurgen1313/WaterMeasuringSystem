/*******************************************************************************
* File Name: Counter_8.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the Counter_8
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

#include "Counter_8.h"

uint8 Counter_8_initVar = 0u;


/*******************************************************************************
* Function Name: Counter_8_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default Counter_8 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (Counter_8__QUAD == Counter_8_CONFIG)
        Counter_8_CONTROL_REG = Counter_8_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Counter_8_TRIG_CONTROL1_REG  = Counter_8_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        Counter_8_SetInterruptMode(Counter_8_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        Counter_8_SetCounterMode(Counter_8_COUNT_DOWN);
        Counter_8_WritePeriod(Counter_8_QUAD_PERIOD_INIT_VALUE);
        Counter_8_WriteCounter(Counter_8_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (Counter_8__QUAD == Counter_8_CONFIG) */

    #if (Counter_8__TIMER == Counter_8_CONFIG)
        Counter_8_CONTROL_REG = Counter_8_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Counter_8_TRIG_CONTROL1_REG  = Counter_8_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Counter_8_SetInterruptMode(Counter_8_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        Counter_8_WritePeriod(Counter_8_TC_PERIOD_VALUE );

        #if (Counter_8__COMPARE == Counter_8_TC_COMP_CAP_MODE)
            Counter_8_WriteCompare(Counter_8_TC_COMPARE_VALUE);

            #if (1u == Counter_8_TC_COMPARE_SWAP)
                Counter_8_SetCompareSwap(1u);
                Counter_8_WriteCompareBuf(Counter_8_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == Counter_8_TC_COMPARE_SWAP) */
        #endif  /* (Counter_8__COMPARE == Counter_8_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (Counter_8_CY_TCPWM_V2 && Counter_8_TIMER_UPDOWN_CNT_USED && !Counter_8_CY_TCPWM_4000)
            Counter_8_WriteCounter(1u);
        #elif(Counter_8__COUNT_DOWN == Counter_8_TC_COUNTER_MODE)
            Counter_8_WriteCounter(Counter_8_TC_PERIOD_VALUE);
        #else
            Counter_8_WriteCounter(0u);
        #endif /* (Counter_8_CY_TCPWM_V2 && Counter_8_TIMER_UPDOWN_CNT_USED && !Counter_8_CY_TCPWM_4000) */
    #endif  /* (Counter_8__TIMER == Counter_8_CONFIG) */

    #if (Counter_8__PWM_SEL == Counter_8_CONFIG)
        Counter_8_CONTROL_REG = Counter_8_CTRL_PWM_BASE_CONFIG;

        #if (Counter_8__PWM_PR == Counter_8_PWM_MODE)
            Counter_8_CONTROL_REG |= Counter_8_CTRL_PWM_RUN_MODE;
            Counter_8_WriteCounter(Counter_8_PWM_PR_INIT_VALUE);
        #else
            Counter_8_CONTROL_REG |= Counter_8_CTRL_PWM_ALIGN | Counter_8_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (Counter_8_CY_TCPWM_V2 && Counter_8_PWM_UPDOWN_CNT_USED && !Counter_8_CY_TCPWM_4000)
                Counter_8_WriteCounter(1u);
            #elif (Counter_8__RIGHT == Counter_8_PWM_ALIGN)
                Counter_8_WriteCounter(Counter_8_PWM_PERIOD_VALUE);
            #else 
                Counter_8_WriteCounter(0u);
            #endif  /* (Counter_8_CY_TCPWM_V2 && Counter_8_PWM_UPDOWN_CNT_USED && !Counter_8_CY_TCPWM_4000) */
        #endif  /* (Counter_8__PWM_PR == Counter_8_PWM_MODE) */

        #if (Counter_8__PWM_DT == Counter_8_PWM_MODE)
            Counter_8_CONTROL_REG |= Counter_8_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (Counter_8__PWM_DT == Counter_8_PWM_MODE) */

        #if (Counter_8__PWM == Counter_8_PWM_MODE)
            Counter_8_CONTROL_REG |= Counter_8_CTRL_PWM_PRESCALER;
        #endif  /* (Counter_8__PWM == Counter_8_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        Counter_8_TRIG_CONTROL1_REG  = Counter_8_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Counter_8_SetInterruptMode(Counter_8_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (Counter_8__PWM_PR == Counter_8_PWM_MODE)
            Counter_8_TRIG_CONTROL2_REG =
                    (Counter_8_CC_MATCH_NO_CHANGE    |
                    Counter_8_OVERLOW_NO_CHANGE      |
                    Counter_8_UNDERFLOW_NO_CHANGE);
        #else
            #if (Counter_8__LEFT == Counter_8_PWM_ALIGN)
                Counter_8_TRIG_CONTROL2_REG = Counter_8_PWM_MODE_LEFT;
            #endif  /* ( Counter_8_PWM_LEFT == Counter_8_PWM_ALIGN) */

            #if (Counter_8__RIGHT == Counter_8_PWM_ALIGN)
                Counter_8_TRIG_CONTROL2_REG = Counter_8_PWM_MODE_RIGHT;
            #endif  /* ( Counter_8_PWM_RIGHT == Counter_8_PWM_ALIGN) */

            #if (Counter_8__CENTER == Counter_8_PWM_ALIGN)
                Counter_8_TRIG_CONTROL2_REG = Counter_8_PWM_MODE_CENTER;
            #endif  /* ( Counter_8_PWM_CENTER == Counter_8_PWM_ALIGN) */

            #if (Counter_8__ASYMMETRIC == Counter_8_PWM_ALIGN)
                Counter_8_TRIG_CONTROL2_REG = Counter_8_PWM_MODE_ASYM;
            #endif  /* (Counter_8__ASYMMETRIC == Counter_8_PWM_ALIGN) */
        #endif  /* (Counter_8__PWM_PR == Counter_8_PWM_MODE) */

        /* Set other values from customizer */
        Counter_8_WritePeriod(Counter_8_PWM_PERIOD_VALUE );
        Counter_8_WriteCompare(Counter_8_PWM_COMPARE_VALUE);

        #if (1u == Counter_8_PWM_COMPARE_SWAP)
            Counter_8_SetCompareSwap(1u);
            Counter_8_WriteCompareBuf(Counter_8_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == Counter_8_PWM_COMPARE_SWAP) */

        #if (1u == Counter_8_PWM_PERIOD_SWAP)
            Counter_8_SetPeriodSwap(1u);
            Counter_8_WritePeriodBuf(Counter_8_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == Counter_8_PWM_PERIOD_SWAP) */
    #endif  /* (Counter_8__PWM_SEL == Counter_8_CONFIG) */
    
}


/*******************************************************************************
* Function Name: Counter_8_Enable
********************************************************************************
*
* Summary:
*  Enables the Counter_8.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Counter_8_BLOCK_CONTROL_REG |= Counter_8_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (Counter_8__PWM_SEL == Counter_8_CONFIG)
        #if (0u == Counter_8_PWM_START_SIGNAL_PRESENT)
            Counter_8_TriggerCommand(Counter_8_MASK, Counter_8_CMD_START);
        #endif /* (0u == Counter_8_PWM_START_SIGNAL_PRESENT) */
    #endif /* (Counter_8__PWM_SEL == Counter_8_CONFIG) */

    #if (Counter_8__TIMER == Counter_8_CONFIG)
        #if (0u == Counter_8_TC_START_SIGNAL_PRESENT)
            Counter_8_TriggerCommand(Counter_8_MASK, Counter_8_CMD_START);
        #endif /* (0u == Counter_8_TC_START_SIGNAL_PRESENT) */
    #endif /* (Counter_8__TIMER == Counter_8_CONFIG) */
    
    #if (Counter_8__QUAD == Counter_8_CONFIG)
        #if (0u != Counter_8_QUAD_AUTO_START)
            Counter_8_TriggerCommand(Counter_8_MASK, Counter_8_CMD_RELOAD);
        #endif /* (0u != Counter_8_QUAD_AUTO_START) */
    #endif  /* (Counter_8__QUAD == Counter_8_CONFIG) */
}


/*******************************************************************************
* Function Name: Counter_8_Start
********************************************************************************
*
* Summary:
*  Initializes the Counter_8 with default customizer
*  values when called the first time and enables the Counter_8.
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
*  Counter_8_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time Counter_8_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the Counter_8_Start() routine.
*
*******************************************************************************/
void Counter_8_Start(void)
{
    if (0u == Counter_8_initVar)
    {
        Counter_8_Init();
        Counter_8_initVar = 1u;
    }

    Counter_8_Enable();
}


/*******************************************************************************
* Function Name: Counter_8_Stop
********************************************************************************
*
* Summary:
*  Disables the Counter_8.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_BLOCK_CONTROL_REG &= (uint32)~Counter_8_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the Counter_8. This function is used when
*  configured as a generic Counter_8 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the Counter_8 to operate in
*   Values:
*   - Counter_8_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - Counter_8_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - Counter_8_MODE_QUAD - Quadrature decoder
*         - Counter_8_MODE_PWM - PWM
*         - Counter_8_MODE_PWM_DT - PWM with dead time
*         - Counter_8_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_MODE_MASK;
    Counter_8_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - Counter_8_MODE_X1 - Counts on phi 1 rising
*         - Counter_8_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - Counter_8_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_QUAD_MODE_MASK;
    Counter_8_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - Counter_8_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - Counter_8_PRESCALE_DIVBY2    - Divide by 2
*         - Counter_8_PRESCALE_DIVBY4    - Divide by 4
*         - Counter_8_PRESCALE_DIVBY8    - Divide by 8
*         - Counter_8_PRESCALE_DIVBY16   - Divide by 16
*         - Counter_8_PRESCALE_DIVBY32   - Divide by 32
*         - Counter_8_PRESCALE_DIVBY64   - Divide by 64
*         - Counter_8_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_PRESCALER_MASK;
    Counter_8_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the Counter_8 runs
*  continuously or stops when terminal count is reached.  By default the
*  Counter_8 operates in the continuous mode.
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
void Counter_8_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_ONESHOT_MASK;
    Counter_8_CONTROL_REG |= ((uint32)((oneShotEnable & Counter_8_1BIT_MASK) <<
                                                               Counter_8_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetPWMMode
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
void Counter_8_SetPWMMode(uint32 modeMask)
{
    Counter_8_TRIG_CONTROL2_REG = (modeMask & Counter_8_6BIT_MASK);
}



/*******************************************************************************
* Function Name: Counter_8_SetPWMSyncKill
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
void Counter_8_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_PWM_SYNC_KILL_MASK;
    Counter_8_CONTROL_REG |= ((uint32)((syncKillEnable & Counter_8_1BIT_MASK)  <<
                                               Counter_8_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetPWMStopOnKill
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
void Counter_8_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_PWM_STOP_KILL_MASK;
    Counter_8_CONTROL_REG |= ((uint32)((stopOnKillEnable & Counter_8_1BIT_MASK)  <<
                                                         Counter_8_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetPWMDeadTime
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
void Counter_8_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_PRESCALER_MASK;
    Counter_8_CONTROL_REG |= ((uint32)((deadTime & Counter_8_8BIT_MASK) <<
                                                          Counter_8_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetPWMInvert
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
*         - Counter_8_INVERT_LINE   - Inverts the line output
*         - Counter_8_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_INV_OUT_MASK;
    Counter_8_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: Counter_8_WriteCounter
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
void Counter_8_WriteCounter(uint32 count)
{
    Counter_8_COUNTER_REG = (count & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadCounter
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
uint32 Counter_8_ReadCounter(void)
{
    return (Counter_8_COUNTER_REG & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - Counter_8_COUNT_UP       - Counts up
*     - Counter_8_COUNT_DOWN     - Counts down
*     - Counter_8_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - Counter_8_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_UPDOWN_MASK;
    Counter_8_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_WritePeriod
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
void Counter_8_WritePeriod(uint32 period)
{
    Counter_8_PERIOD_REG = (period & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadPeriod
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
uint32 Counter_8_ReadPeriod(void)
{
    return (Counter_8_PERIOD_REG & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_SetCompareSwap
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
void Counter_8_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_RELOAD_CC_MASK;
    Counter_8_CONTROL_REG |= (swapEnable & Counter_8_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_WritePeriodBuf
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
void Counter_8_WritePeriodBuf(uint32 periodBuf)
{
    Counter_8_PERIOD_BUF_REG = (periodBuf & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadPeriodBuf
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
uint32 Counter_8_ReadPeriodBuf(void)
{
    return (Counter_8_PERIOD_BUF_REG & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_SetPeriodSwap
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
void Counter_8_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_CONTROL_REG &= (uint32)~Counter_8_RELOAD_PERIOD_MASK;
    Counter_8_CONTROL_REG |= ((uint32)((swapEnable & Counter_8_1BIT_MASK) <<
                                                            Counter_8_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_WriteCompare
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
void Counter_8_WriteCompare(uint32 compare)
{
    #if (Counter_8_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Counter_8_CY_TCPWM_4000) */

    #if (Counter_8_CY_TCPWM_4000)
        currentMode = ((Counter_8_CONTROL_REG & Counter_8_UPDOWN_MASK) >> Counter_8_UPDOWN_SHIFT);

        if (((uint32)Counter_8__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)Counter_8__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (Counter_8_CY_TCPWM_4000) */
    
    Counter_8_COMP_CAP_REG = (compare & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadCompare
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
uint32 Counter_8_ReadCompare(void)
{
    #if (Counter_8_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Counter_8_CY_TCPWM_4000) */

    #if (Counter_8_CY_TCPWM_4000)
        currentMode = ((Counter_8_CONTROL_REG & Counter_8_UPDOWN_MASK) >> Counter_8_UPDOWN_SHIFT);
        
        regVal = Counter_8_COMP_CAP_REG;
        
        if (((uint32)Counter_8__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Counter_8__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Counter_8_16BIT_MASK);
    #else
        return (Counter_8_COMP_CAP_REG & Counter_8_16BIT_MASK);
    #endif /* (Counter_8_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Counter_8_WriteCompareBuf
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
void Counter_8_WriteCompareBuf(uint32 compareBuf)
{
    #if (Counter_8_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Counter_8_CY_TCPWM_4000) */

    #if (Counter_8_CY_TCPWM_4000)
        currentMode = ((Counter_8_CONTROL_REG & Counter_8_UPDOWN_MASK) >> Counter_8_UPDOWN_SHIFT);

        if (((uint32)Counter_8__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)Counter_8__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (Counter_8_CY_TCPWM_4000) */
    
    Counter_8_COMP_CAP_BUF_REG = (compareBuf & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadCompareBuf
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
uint32 Counter_8_ReadCompareBuf(void)
{
    #if (Counter_8_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Counter_8_CY_TCPWM_4000) */

    #if (Counter_8_CY_TCPWM_4000)
        currentMode = ((Counter_8_CONTROL_REG & Counter_8_UPDOWN_MASK) >> Counter_8_UPDOWN_SHIFT);

        regVal = Counter_8_COMP_CAP_BUF_REG;
        
        if (((uint32)Counter_8__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Counter_8__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Counter_8_16BIT_MASK);
    #else
        return (Counter_8_COMP_CAP_BUF_REG & Counter_8_16BIT_MASK);
    #endif /* (Counter_8_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Counter_8_ReadCapture
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
uint32 Counter_8_ReadCapture(void)
{
    return (Counter_8_COMP_CAP_REG & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_ReadCaptureBuf
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
uint32 Counter_8_ReadCaptureBuf(void)
{
    return (Counter_8_COMP_CAP_BUF_REG & Counter_8_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Counter_8_SetCaptureMode
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
*     - Counter_8_TRIG_LEVEL     - Level
*     - Counter_8_TRIG_RISING    - Rising edge
*     - Counter_8_TRIG_FALLING   - Falling edge
*     - Counter_8_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_TRIG_CONTROL1_REG &= (uint32)~Counter_8_CAPTURE_MASK;
    Counter_8_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Counter_8_TRIG_LEVEL     - Level
*     - Counter_8_TRIG_RISING    - Rising edge
*     - Counter_8_TRIG_FALLING   - Falling edge
*     - Counter_8_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_TRIG_CONTROL1_REG &= (uint32)~Counter_8_RELOAD_MASK;
    Counter_8_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Counter_8_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Counter_8_TRIG_LEVEL     - Level
*     - Counter_8_TRIG_RISING    - Rising edge
*     - Counter_8_TRIG_FALLING   - Falling edge
*     - Counter_8_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_TRIG_CONTROL1_REG &= (uint32)~Counter_8_START_MASK;
    Counter_8_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Counter_8_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Counter_8_TRIG_LEVEL     - Level
*     - Counter_8_TRIG_RISING    - Rising edge
*     - Counter_8_TRIG_FALLING   - Falling edge
*     - Counter_8_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_TRIG_CONTROL1_REG &= (uint32)~Counter_8_STOP_MASK;
    Counter_8_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Counter_8_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Counter_8_TRIG_LEVEL     - Level
*     - Counter_8_TRIG_RISING    - Rising edge
*     - Counter_8_TRIG_FALLING   - Falling edge
*     - Counter_8_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_TRIG_CONTROL1_REG &= (uint32)~Counter_8_COUNT_MASK;
    Counter_8_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Counter_8_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_TriggerCommand
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
*     - Counter_8_CMD_CAPTURE    - Trigger Capture/Switch command
*     - Counter_8_CMD_RELOAD     - Trigger Reload/Index command
*     - Counter_8_CMD_STOP       - Trigger Stop/Kill command
*     - Counter_8_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Counter_8_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Counter_8_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the Counter_8.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - Counter_8_STATUS_DOWN    - Set if counting down
*     - Counter_8_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 Counter_8_ReadStatus(void)
{
    return ((Counter_8_STATUS_REG >> Counter_8_RUNNING_STATUS_SHIFT) |
            (Counter_8_STATUS_REG & Counter_8_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: Counter_8_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - Counter_8_INTR_MASK_TC       - Terminal count mask
*     - Counter_8_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetInterruptMode(uint32 interruptMask)
{
    Counter_8_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: Counter_8_GetInterruptSourceMasked
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
*     - Counter_8_INTR_MASK_TC       - Terminal count mask
*     - Counter_8_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Counter_8_GetInterruptSourceMasked(void)
{
    return (Counter_8_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: Counter_8_GetInterruptSource
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
*     - Counter_8_INTR_MASK_TC       - Terminal count mask
*     - Counter_8_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Counter_8_GetInterruptSource(void)
{
    return (Counter_8_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: Counter_8_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - Counter_8_INTR_MASK_TC       - Terminal count mask
*     - Counter_8_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_ClearInterrupt(uint32 interruptMask)
{
    Counter_8_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: Counter_8_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - Counter_8_INTR_MASK_TC       - Terminal count mask
*     - Counter_8_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Counter_8_SetInterrupt(uint32 interruptMask)
{
    Counter_8_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
