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
//#include "main.h"

#ifndef max_PWMs
    #define max_PWMs 8
#endif

#ifndef max_period
    #define max_period 65535
    #endif

#define PWM1            0u
#define PWM2            1u
#define PWM3            2u
#define PWM4            3u
#define PWM5            4u
#define PWM6            5u
#define PWM7            6u
#define PWMExemplary    7u



//struct PWM_structure
//{
//    uint32 period;
//    uint32 compare;
//    uint8 active;
//    uint32 number_of_pulses;
//    uint32 set_number_of_pulses;
//    uint32 max_PWM_period;// = 65535;
//    write writePeriod;
//    write writeCompare;
//    start_stop startPWM;
//    start_stop stopPWM;    
//    start_stop initPWM;
//};

//extern struct PWM_structure array_PWMs [max_PWMs];

uint8 number_of_active_PWMs = 0;
/* [] END OF FILE */
