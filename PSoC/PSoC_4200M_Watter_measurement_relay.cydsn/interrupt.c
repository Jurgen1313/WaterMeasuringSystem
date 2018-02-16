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

#include "interrupt.h"

#define active_counter   1
#define inactive_counter 0

CY_ISR(Counter_1_interrupt)
{
    set_counter_count_value (counter_1, array_counters);
    Counter_1_ClearInterrupt(Counter_1_INTR_MASK_TC);
}

CY_ISR(Counter_2_interrupt)
{
    set_counter_count_value (counter_2, array_counters);
    Counter_2_ClearInterrupt(Counter_2_INTR_MASK_TC);
}

CY_ISR(Counter_3_interrupt)
{
    set_counter_count_value (counter_3, array_counters);
    Counter_3_ClearInterrupt(Counter_3_INTR_MASK_TC);
}

CY_ISR(Counter_4_interrupt)
{
    set_counter_count_value (counter_4, array_counters);
    Counter_4_ClearInterrupt(Counter_4_INTR_MASK_TC);
}

CY_ISR(Counter_5_interrupt)
{
    set_counter_count_value (counter_5, array_counters);
    Counter_5_ClearInterrupt(Counter_5_INTR_MASK_TC);
}

CY_ISR(Counter_6_interrupt)
{
    set_counter_count_value (counter_6, array_counters);
    Counter_6_ClearInterrupt(Counter_6_INTR_MASK_TC);
}

CY_ISR(Counter_7_interrupt)
{
    set_counter_count_value (counter_7, array_counters);
    Counter_7_ClearInterrupt(Counter_7_INTR_MASK_TC);
}

CY_ISR(CExamplary_interrupt)
{
//    Examplary_counter.Examplary_OV_val++;
    array_counters[ExamplaryCounter].counter_OV ++;
    array_counters[ExamplaryCounter].setCount(1);
//    array_counters[ExamplaryCounter].counter_count = array_counters[ExamplaryCounter].ReadCounterCount();
    ExamplaryCounter_ClearInterrupt(ExamplaryCounter_INTR_MASK_TC);
}

void set_counter_count_value (uint8 counter_number, struct Test_counter *array_counters)
{
    uint16 examplaryCount = array_counters[ExamplaryCounter].ReadCounterCount();
    
    if ( !array_counters[counter_number].start_Examplary_pulse )
    {
        array_counters[counter_number].start_Examplary_pulse = active_counter;
        array_counters[counter_number].Examplary_OV_start_val = array_counters[ExamplaryCounter].counter_OV;
        array_counters[counter_number].Examplary_count_start_val = examplaryCount;    
        array_counters[counter_number].setCount(array_counters[counter_number].counter_count_set_val - 1);
    }
    else
    {
        array_counters[counter_number].counter_OV++;
//        array_counters[counter_number].setCount (max_counter_count);
        
        // stop counter
        if (array_counters[counter_number].counter_OV > array_counters[counter_number].counter_OV_set_val)
        { 
            array_counters[counter_number].Stop();
            //read Exemplary OV variable
            array_counters[counter_number].Examplary_OV_end_val = array_counters[ExamplaryCounter].counter_OV;
            array_counters[counter_number].Examplary_count_end_val =  examplaryCount;
//            array_counters[counter_number].active = inactive_counter;
            array_counters[counter_number].stopped = 0;
            stopped_counters++;
//            
//            uint32 tmpExamplaryCount = 0;
//            tmpExamplaryCount = (array_counters[counter_number].Examplary_OV_end_val - array_counters[counter_number].Examplary_OV_start_val) * 65535;
//            if (array_counters[counter_number].Examplary_count_end_val > array_counters[counter_number].Examplary_count_start_val)
//            {
//                tmpExamplaryCount += (array_counters[counter_number].Examplary_count_end_val - array_counters[counter_number].Examplary_count_start_val);
//            }
//            else
//            {
//                uint32 tmp_val = 0;
//                tmp_val = (65535 - array_counters[counter_number].Examplary_count_start_val) + array_counters[counter_number].Examplary_count_end_val;
//                tmpExamplaryCount += tmp_val;
//                
//            }            
//            array_counters[counter_number].Examplary_OV_val = array_counters[counter_number].Examplary_OV_end_val - array_counters[counter_number].Examplary_OV_start_val;
//            array_counters[counter_number].Examplary_count_val = tmpExamplaryCount;
            
            if (stopped_counters == active_counters)
            {
//                array_counters[ExamplaryCounter].active = 0;
                array_counters[ExamplaryCounter].Stop();
                
                uint8 i;
                for (i = 0; i < (max_counters - 1); ++i)
                {                                        
                    uint32 tmpExamplaryCount = 0;
                    tmpExamplaryCount = (array_counters[i].Examplary_OV_end_val - array_counters[i].Examplary_OV_start_val) * 65535;
                    if (array_counters[i].Examplary_count_end_val > array_counters[i].Examplary_count_start_val)
                    {
                        tmpExamplaryCount += (array_counters[i].Examplary_count_end_val - array_counters[i].Examplary_count_start_val);
                    }
                    else
                    {
                        uint32 tmp_val = 0;
                        tmp_val = (65535 - array_counters[i].Examplary_count_start_val) + array_counters[i].Examplary_count_end_val;
                        tmpExamplaryCount += tmp_val;                        
                    }  
                    array_counters[i].Examplary_OV_val = array_counters[i].Examplary_OV_end_val - array_counters[i].Examplary_OV_start_val;
                    array_counters[i].Examplary_count_val = tmpExamplaryCount;
                }
                
                
                
                array_counters[ExamplaryCounter].Examplary_count_val = array_counters[ExamplaryCounter].ReadCounterCount();
                readyToSend = 1;
            }
        }
    }
}

/* [] END OF FILE */
