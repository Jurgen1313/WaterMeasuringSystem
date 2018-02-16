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
#include "counter.h"

#ifndef max_counters
    #define max_counters            8
#endif

//#define max_counters            8
//extern struct Test_counter array_counters [8];

//extern struct Test_counter;
//extern uint32 counters_Overflow [max_counters];
//extern struct Test_counter array_counters[20];
//extern enum counters_number;

extern uint8 stopped_counters;
extern uint8 active_counters;
extern _Bool readyToSend;

CY_ISR_PROTO(Counter_1_interrupt);
CY_ISR_PROTO(Counter_2_interrupt);
CY_ISR_PROTO(Counter_3_interrupt);
CY_ISR_PROTO(Counter_4_interrupt);
CY_ISR_PROTO(Counter_5_interrupt);
CY_ISR_PROTO(Counter_6_interrupt);
CY_ISR_PROTO(Counter_7_interrupt);
CY_ISR_PROTO(CExamplary_interrupt);

void set_counter_count_value (uint8 counter_number, struct Test_counter *array_counters);


/* [] END OF FILE */
