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
//#include "PWM_struct.h"
#include "project.h"
#include "main.h"

#define PWM1            0u
#define PWM2            1u
#define PWM3            2u
#define PWM4            3u
#define PWM5            4u
#define PWM6            5u
#define PWM7            6u
#define PWMExemplary    7u

#ifndef max_PWMs
    #define max_PWMs 8
#endif

//extern struct PWM_structure ;
//extern struct PWM_structure array_PWMs[max_PWMs];
//extern struct PWM_structure ;
extern uint8 stopped_PWMs;
extern uint8 ready_to_send_data;
extern uint8 active_PWMs;

CY_ISR_PROTO(Interrupt_PWM_1);
CY_ISR_PROTO(Interrupt_PWM_2);
CY_ISR_PROTO(Interrupt_PWM_3);
CY_ISR_PROTO(Interrupt_PWM_4);
CY_ISR_PROTO(Interrupt_PWM_5);
CY_ISR_PROTO(Interrupt_PWM_6);
CY_ISR_PROTO(Interrupt_PWM_7);
CY_ISR_PROTO(Interrupt_PWM_Exemplary);
             
//isr_PWM_Exemplary_StartEx(Interrupt_PWM_Exemplary);

//static uint8 process_PWM_interrupt(struct PWM_structure *PWM);
static void process_PWM_interrupt(struct PWM_structure *PWM, uint8 *stop, const uint8 all_activeted_PWMs, uint8 PWM_number);
/* [] END OF FILE */


