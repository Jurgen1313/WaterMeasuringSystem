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

typedef void (*write)(uint32);
typedef void (*start_stop)();

struct PWM_structure
{
    uint32 period;
    uint32 compare;
    uint8 active;
    uint8 started;
    uint8 all_active;
    uint32 number_of_pulses;
    uint32 set_number_of_pulses;
    uint32 max_PWM_period;// = 65535;
    write writePeriod;
    write writeCompare;
    start_stop startPWM;
    start_stop stopPWM;    
    start_stop initPWM;
    uint32 test_var;
};

struct PWM_structure array_PWMs [8];
/* [] END OF FILE */
