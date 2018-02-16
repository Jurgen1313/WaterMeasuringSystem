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

extern uint8 stopped_counters;
extern uint8 active_counters;
extern _Bool readyToSend;

CY_ISR_PROTO(inputPinISR);
CY_ISR_PROTO(Timer_1_interrupt);
CY_ISR_PROTO(Timer_2_interrupt);
CY_ISR_PROTO(Timer_3_interrupt);
CY_ISR_PROTO(Timer_4_interrupt);
CY_ISR_PROTO(Timer_5_interrupt);
CY_ISR_PROTO(Timer_6_interrupt);
CY_ISR_PROTO(Timer_7_interrupt);
CY_ISR_PROTO(CExamplary_interrupt);

//void IncreaseCounter (uint8 counterNumber, struct Test_counter *array_counters);
void IncreaseCounter (uint8 counterNumber, struct Test_counter *array_counters, uint32 exCounterValue);
void EndOfPackageISR (uint8 counterNumber, struct Test_counter *array_counters);

/* [] END OF FILE */
