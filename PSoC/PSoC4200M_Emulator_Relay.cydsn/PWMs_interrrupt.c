/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "PWMs_interrupt.h"

CY_ISR(Interrupt_PWM_1)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM1]);
    process_PWM_interrupt (&array_PWMs[PWM1], &stopped_PWMs, active_PWMs, PWM1);
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_2)
{ 
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM2]);
    process_PWM_interrupt (&array_PWMs[PWM2], &stopped_PWMs, active_PWMs, PWM2);
    PWM_2_ClearInterrupt(PWM_2_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_3)
{   
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM3]);
    process_PWM_interrupt (&array_PWMs[PWM3], &stopped_PWMs, active_PWMs, PWM3);
    PWM_3_ClearInterrupt(PWM_3_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_4)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM4]);
    process_PWM_interrupt (&array_PWMs[PWM4], &stopped_PWMs, active_PWMs, PWM4);
    PWM_4_ClearInterrupt(PWM_4_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_5)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM5]);
    process_PWM_interrupt (&array_PWMs[PWM5], &stopped_PWMs, active_PWMs, PWM5);
    PWM_5_ClearInterrupt(PWM_5_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_6)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM6]);
    process_PWM_interrupt (&array_PWMs[PWM6], &stopped_PWMs, active_PWMs, PWM6);
    PWM_6_ClearInterrupt(PWM_6_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_7)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM7]);
    process_PWM_interrupt (&array_PWMs[PWM7], &stopped_PWMs, active_PWMs, PWM7);
//    if (stopped_PWMs == )
    PWM_7_ClearInterrupt(PWM_7_INTR_MASK_CC_MATCH);
}

CY_ISR(Interrupt_PWM_Exemplary)
{
//    stopped_PWMs += process_PWM_interrupt (&array_PWMs[PWM7]);
    process_PWM_interrupt (&array_PWMs[PWMExemplary], &stopped_PWMs, active_PWMs, PWMExemplary);
    PWM_Exemplary_ClearInterrupt(PWM_Exemplary_INTR_MASK_CC_MATCH);
}

static void process_PWM_interrupt(struct PWM_structure *PWM, uint8 *stop, const uint8 all_activeted_PWMs, uint8 PWM_number)
{
    PWM->number_of_pulses++;
    if (PWM->number_of_pulses == PWM->set_number_of_pulses)
    {        
        ++(*stop);
//        PWM->active = 0;
        PWM->started = 0;
        Control_PWM_Write(Control_PWM_Read() ^ (1 << PWM_number));
        if (*stop == all_activeted_PWMs)
        {
            ready_to_send_data = 1;
        }
    }
}
/* [] END OF FILE */
