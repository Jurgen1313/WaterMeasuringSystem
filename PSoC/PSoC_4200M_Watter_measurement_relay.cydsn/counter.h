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
#include "project.h"

#ifndef max_counters
    #define max_counters            8
#endif

#ifndef max_counter_count
#define max_counter_count       65534
#endif

typedef void (*setValue)(uint32 data);
typedef uint32 (*readCounterCount)();
typedef void (*funcWithoutParam)();

struct Test_counter {
    uint8 active;
    uint8 stopped;
    
    uint32 counter_OV_set_val;
    uint32 counter_count_set_val;
    uint32 counter_OV;
    uint32 counter_count;
    
    uint8 start_Examplary_pulse;
    uint32 Examplary_OV_start_val;
    uint32 Examplary_count_start_val;
    uint32 Examplary_OV_end_val;
    uint32 Examplary_count_end_val;
    uint32 Examplary_OV_val;
    uint32 Examplary_count_val; // 
    
//    setValue setPeriod; //not neccessary
    setValue setCount;
    readCounterCount ReadCounterCount;
    funcWithoutParam Start;
    funcWithoutParam Init;
    funcWithoutParam Enable;
    funcWithoutParam Stop;    
};

enum counters_number 
{
    counter_1 = 0,
    counter_2 = 1, 
    counter_3 = 2,
    counter_4 = 3,
    counter_5 = 4,
    counter_6 = 5,
    counter_7 = 6,
    ExamplaryCounter = 7
};

struct Test_counter array_counters [max_counters];
//struct Examplary  Examplary_counter;

//extern uint8 used_counters;
//extern volatile uint8 stopped_counters;
//extern volatile uint8 set_counters;

//void Enable_counters (uint16 *used_counters, 
//                     const uint16 *mask_counters, const uint16 counter_number);
//
//void Disable_counters (uint16 *used_counters, 
//                      const uint16 *mask_counters, const uint16 counter_number);
/* [] END OF FILE */
