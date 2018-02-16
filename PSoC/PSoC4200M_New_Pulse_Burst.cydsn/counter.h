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

//#ifndef max_counters
////    #define max_counters            8
//#endif

#ifndef max_counter_count
#define max_counter_count       65534
#endif

typedef void (*setValue)(uint32 data);
typedef uint32 (*readCounterCount)();
typedef void (*funcWithoutParam)();

struct BurstMeasurement {
    uint8 firstBurst;
    uint8 secondBurst;
    uint8 endOfMeasurement;
    uint8 endOfPackage;
};

struct Test_counter {
    struct BurstMeasurement recievedPackage;
    
    uint8 active;
    uint8 ready_to_operate;
    uint8 stopped;
    uint16 period;
//    uint16 test_period;
//    uint32 testIsTimerStarted;
//    uint8 initVar;
    
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
    uint32 Examplary_count_val;
    
    funcWithoutParam InitTimer;
    funcWithoutParam StopTimer;
    funcWithoutParam EnableTimer;
    funcWithoutParam StartTimer;
    readCounterCount ReadStatus;
    readCounterCount ReadPeriod;
    setValue WritePeriod;  
};

struct Examplary_counter {
    uint8 active;
    uint8 stopped;
    
    uint32 counter_OV;
    uint32 counter_count;
    
    //only for examplary counter
    readCounterCount ReadCounterCount;    
    funcWithoutParam Init;
    funcWithoutParam Enable;
    funcWithoutParam Stop;
    funcWithoutParam Start;
    setValue setPeriod; 
    setValue setCount;     
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
    ExamplaryCounter = 7,
    max_counters = 7
};

struct PinInterrupt
{
    funcWithoutParam Enable;
    funcWithoutParam Disable;
};

struct Test_counter array_counters [max_counters];
struct  Examplary_counter ExCounter;
struct PinInterrupt InterruptPin;
