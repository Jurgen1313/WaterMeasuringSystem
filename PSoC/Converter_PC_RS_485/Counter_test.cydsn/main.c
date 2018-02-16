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
uint8 counter_count = 0;

CY_ISR(counter_isr_handler_2)
{
    counter_count++;
    Timer_1_WriteCounter(counter_count);
    LCD_Position(1,0);
//    LCD_PrintNumber(Timer_1_ReadCounter());
    LCD_PrintNumber(counter_count);
    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_TC);
}
CY_ISR(counter_isr_handler)
{
//    counter_count++;
    LCD_Position(0,0);
    LCD_PrintNumber(Timer_1_ReadCounter());
    LCD_PrintString(" ");
//    Timer_1_WritePeriod(counter_count);
//    if
//    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_TC);
//    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_CC_MATCH);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    Clock_1_Start();
    Clock_2_Start();
//    PWM_2_Start();
    
    Timer_1_Start();
//    Timer_1_WritePeriod(5);
    Timer_1_WriteCounter(counter_count);
    
    isr_1_StartEx(counter_isr_handler);
    isr_2_StartEx(counter_isr_handler_2);
    
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("ok");
    CyDelay(1000);
    LCD_ClearDisplay();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
