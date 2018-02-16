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

enum modbus_command 
{
    StartCounters = 0xA1,                //0xA1  --  Start all active PWMs 
    StopCounters = 0xA2,                 //0xB2  --  Stop all PWMs 
    Ready_to_send_data = 0xA3,
    FindDevice = 0xA6,
    EnableCounter = 0xB1,
    //0xE5  --  Enable counter
//    EnableCounter = 0xB2,
    SetPeriod = 0xC1,        
    SetCompare = 0xC2,        
    SetCount = 0xC3,           //0xC2  --  Set channels with pulses    
    ReadCount = 0xC4,
    SetCounter = 0xC5,
    ReadExamplaryStartValue = 0xC6,
    ReadExamplaryEndValue = 0xC7,    
    ReadExamplaryCounter = 0xC8,
    ReadCounterMeasuredPulses = 0xC9,
//    Reset_all_channels = 0xC3,            //0xC3  --  Reset all channels to 0
//    Reset_counter = 0xD4,                //0xD4  --  Reset counter to 0
//    Disable_counter = 0xF6,              //0xF6  --  Disable counter
    Package_sent_successfully = 0xD1,     //0xCD  --  Package was successfully sent 
    Package_received_successfully = 0xD2, //0xCD  --  Package received successfully 
//    Repeat_package = 0xD3,                //0xAB  --  Repeat package transmission  
    Error_damadged_package_from_pc = 0xE0,       //0xE0  --  package from PC is damaged
    Error_communication_with_pc = 0xE1,       //0xE1  -- communiation error with PC
    Error_damaged_package_from_slave = 0xE2,
    Error_communication_with_slave = 0xE3,       //0xE1  -- communiation error with PC
    Error_master_damaged_package = 0XE4,
    Error_master_communication = 0xE5,
    Error_unknown_command = 0xE9
};

/* [] END OF FILE */
