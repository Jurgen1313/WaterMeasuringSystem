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

void IncreaseCounter (uint8 counterNumber, struct Test_counter *array_counters, uint32 exCounterValue)
{
    if ((array_counters[counterNumber].recievedPackage.firstBurst == 1) &&
         (array_counters[counterNumber].recievedPackage.secondBurst == 1) &&
          (array_counters[counterNumber].recievedPackage.endOfPackage == 0))
    {
        array_counters[counterNumber].counter_count++;
        if (array_counters[counterNumber].counter_count >= array_counters[counterNumber].counter_count_set_val)
        {
            array_counters[counterNumber].recievedPackage.endOfMeasurement = 1;            
        }
    }
    else if((array_counters[counterNumber].recievedPackage.firstBurst == 0) &&
            (array_counters[counterNumber].recievedPackage.secondBurst == 0) &&
             (array_counters[counterNumber].recievedPackage.endOfPackage == 1))
    {
        TestPin_Write(1);
//        array_counters[counterNumber].Examplary_count_start_val = ExamplaryCounter_ReadCounter();
//        array_counters[counterNumber].Examplary_count_start_val= ExCounter.ReadCounterCount();
        array_counters[counterNumber].Examplary_count_start_val= exCounterValue;
        array_counters[counterNumber].Examplary_OV_start_val = ExCounter.counter_OV;
        array_counters[counterNumber].recievedPackage.firstBurst = 1;
        array_counters[counterNumber].recievedPackage.endOfPackage = 0;        
        TestPin_Write(0);
    }
    else if((array_counters[counterNumber].recievedPackage.firstBurst == 1) &&
            (array_counters[counterNumber].recievedPackage.secondBurst == 1) &&
             (array_counters[counterNumber].recievedPackage.endOfPackage == 1))
    {
//        TestPin_Write(1);
//        array_counters[counterNumber].Examplary_count_end_val= ExCounter.ReadCounterCount();
        array_counters[counterNumber].Examplary_count_end_val = exCounterValue;
//        ExamplaryCounter_ReadCounter();
        array_counters[counterNumber].Examplary_OV_end_val = ExCounter.counter_OV;
        array_counters[counterNumber].counter_count++;
        array_counters[counterNumber].recievedPackage.endOfPackage = 0;
        if (array_counters[counterNumber].counter_count >= array_counters[counterNumber].counter_count_set_val)
        {
            array_counters[counterNumber].recievedPackage.endOfMeasurement = 1;            
        }
//        TestPin_Write(0);
    }
}

void EndOfPackageISR (uint8 counterNumber, struct Test_counter *array_counters)
{
    if ((array_counters[counterNumber].recievedPackage.firstBurst == 1) &&
        (array_counters[counterNumber].recievedPackage.secondBurst == 0) &&
         (array_counters[counterNumber].recievedPackage.endOfMeasurement == 0))
    {
        array_counters[counterNumber].recievedPackage.secondBurst = 1;
    }
    else if ((array_counters[counterNumber].recievedPackage.firstBurst == 1) &&
            (array_counters[counterNumber].recievedPackage.secondBurst == 1) &&
             (array_counters[counterNumber].recievedPackage.endOfMeasurement == 1))
    {
        array_counters[counterNumber].StopTimer();
        array_counters[counterNumber].ready_to_operate = 0;
        //stop counting
        stopped_counters++;
        if (stopped_counters == active_counters)
        {
            ExCounter.Stop();
            uint8 i;
            for (i = 0; i < max_counters; ++i)
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
//            array_counters[ExamplaryCounter].Examplary_count_val = array_counters[ExamplaryCounter].ReadCounterCount();
            readyToSend = 1;
        }            
    }
    array_counters[counterNumber].recievedPackage.endOfPackage = 1;
}

CY_ISR(inputPinISR)
{
    uint8 portIsr = Channel_1_ClearInterrupt();
    uint8 i;    
    uint32 ExCounterValue = ExCounter.ReadCounterCount();
    
//    TestPin_Write(1);
    for (i = 0; i < 7; ++i)
    {
        if (((portIsr >> i) & 0x01) && (array_counters[i].ready_to_operate == 1))
        {
            IncreaseCounter (i, array_counters, ExCounterValue);
        }
    }   
//    TestPin_Write(0);
}

CY_ISR(Timer_1_interrupt)
{
    EndOfPackageISR (counter_1, array_counters);
    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_TC);
}

CY_ISR(Timer_2_interrupt)
{
    EndOfPackageISR (counter_2, array_counters);
    Counter_2_ClearInterrupt(Counter_2_INTR_MASK_TC);
}

CY_ISR(Timer_3_interrupt)
{
    EndOfPackageISR (counter_3, array_counters);
    Counter_3_ClearInterrupt(Counter_3_INTR_MASK_TC);
}

CY_ISR(Timer_4_interrupt)
{
    EndOfPackageISR (counter_4, array_counters);
    Counter_4_ClearInterrupt(Counter_4_INTR_MASK_TC);
}

CY_ISR(Timer_5_interrupt)
{
    EndOfPackageISR (counter_5, array_counters);
    Counter_5_ClearInterrupt(Counter_5_INTR_MASK_TC);
}

CY_ISR(Timer_6_interrupt)
{
    EndOfPackageISR (counter_6, array_counters);
    Counter_6_ClearInterrupt(Counter_6_INTR_MASK_TC);
}

CY_ISR(Timer_7_interrupt)
{
    EndOfPackageISR (counter_7, array_counters);
    Counter_7_ClearInterrupt(Counter_7_INTR_MASK_TC);
}

CY_ISR(CExamplary_interrupt)
{
    ExCounter.counter_OV++;
    ExCounter.setCount(0);
//    array_counters[ExamplaryCounter].counter_OV ++;
//    array_counters[ExamplaryCounter].setCount(1);
    ExamplaryCounter_ClearInterrupt(ExamplaryCounter_INTR_MASK_TC);
}

/* [] END OF FILE */
