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
#include "Modbus.h"
#include "CRC16.h"
#include "PWMs_interrupt.h"

#define max_bytes 20
#define max_period 65535
#define number_of_bytes_position    1
#define command_position            0

#define Enable  1u
#define Disable 0u

#define Master_Address 0x02

// DeviceType  
// 1 --- pulse measurement
// 2 --- gerkon measurement
// 3 --- pulse emulator
// 4 --- gerkon emulator
const int8 DeviceType = 3;
uint8 SlaveAddr = 0;

uint32 CRC_calc = 0;
uint16 CRC_value = 0;
uint8 CRCHi = 0;
uint8 CRCLo = 0;  
//------------------------------------------------------------
uint8 ready_to_send_data = 0;

uint8 start_pwm = 0;
//------------------------------------------------------------
uint8 active_PWMs = 0;
uint8 stopped_PWMs = 0;
uint8 used_PWMs = 0;
uint8 received_message [max_bytes] = {0};

uint8 stage = 0;
uint8 read_bytes = 0;

struct PWM_structure First_PWM;
struct PWM_structure Second_PWM;
struct PWM_structure Third_PWM;
struct PWM_structure Fourth_PWM;
struct PWM_structure Fifth_PWM;
struct PWM_structure Sixth_PWM;
struct PWM_structure Seventh_PWM;
struct PWM_structure Exemplary_PWM;
    
void Init_all_PWMs();
void reset_PWM_data (struct PWM_structure *data);
void UART_RS_485_Interrupts();
void send_error (const uint8 error_code, uint8 *data);
void form_package_measured_pulses (const struct PWM_structure *PWM, const uint8 PWM_number, uint8 *data);
void send_measured_pulses (const uint8 *data);
void form_package_ready_or_not (const uint8 ready_to_send, uint8 *data);
void send_ready_or_not (const uint8 *data);

uint8  MakeFiveBytesPackage (const uint8 command, const uint8 data, uint8 *package);
uint8 MakeFiveBytesPackageWithCRC (const uint8 command, const uint8 data, uint8 *package);
uint8 addCrc(uint8 *_package, uint16 crc, uint8 _lenght);
void send_answer (const uint8 *data, const uint8 lenght);

uint8 initSlaveAddr ();

CY_ISR_PROTO(from_Timer_from_master);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Trasmitter_Write(Disable);

    Timer_from_master_Init();
    Timer_from_master_WritePeriod(5);    
    Timer_from_master_SetInterruptMode(Timer_from_master_STATUS_TC_INT_MASK);
    
    UART_RS_485_SetCustomInterruptHandler(UART_RS_485_Interrupts);
    UART_RS_485_Start();
    SlaveAddr = initSlaveAddr();
    
    isr_Timer_from_master_StartEx(from_Timer_from_master);
    
    isr_PWM_1_StartEx(Interrupt_PWM_1);
    isr_PWM_2_StartEx(Interrupt_PWM_2);
    isr_PWM_3_StartEx(Interrupt_PWM_3);
    isr_PWM_4_StartEx(Interrupt_PWM_4);
    isr_PWM_5_StartEx(Interrupt_PWM_5);
    isr_PWM_6_StartEx(Interrupt_PWM_6);
    isr_PWM_7_StartEx(Interrupt_PWM_7);
    isr_PWM_Exemplary_StartEx(Interrupt_PWM_Exemplary);   
    Init_all_PWMs();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */    
    for(;;)
    {
//        SlaveAddr = initSlaveAddr();
        /* Place your application code here. */
    }
}

CY_ISR(from_Timer_from_master)
{
     //ERROR 
    //received wrong package
    Timer_from_master_Stop();

    read_bytes = 0;
    stage = 0;
    CRC_value = 0;
    CRC_calc = 0;
    
    received_message[0] = Error_master_communication;
    received_message[1] = 0x02;
//    uint16 crc_calc = CRC_calculation(received_message,2);
    
    Trasmitter_Write(Enable);
    CyDelayUs(1);
    send_error (Error_master_communication, received_message);
}

void UART_RS_485_Interrupts()
{
    uint32 receivedByte;
    
    receivedByte = UART_RS_485_GetRxInterruptSource();
    
    if(receivedByte & UART_RS_485_INTR_RX_NOT_EMPTY)
    {
        receivedByte = UART_RS_485_UartGetByte();
        // read command number
        switch ( stage )
        {
            // command received
            case 0:
            {   
                read_bytes = 0;
                received_message[read_bytes] = (uint8)receivedByte;
                read_bytes++;
                stage++;
                Timer_from_master_Enable();
                break;
            }
            // read number of bytes
            case 1:
            {                
                received_message[read_bytes] = (uint8)receivedByte;
                read_bytes++;
                stage++;
                break;
            }
            // read data
            case 2:            
            {
                received_message[read_bytes] = (uint8)receivedByte;

                read_bytes++;
                if ((read_bytes) == (received_message[number_of_bytes_position] + 2))
                {
                    Timer_from_master_Stop();
                    CRCHi = read_bytes - 2;
                    CRCLo = read_bytes - 1;
                    CRC_value = (received_message[CRCHi] << 8) | (received_message[CRCLo]);

                    uint8 received_message_lenght = read_bytes - 2;
                    CRC_calc = CRC_calculation(received_message, received_message_lenght);
                    
                    if (CRC_calc == CRC_value)
                    {                        
                        switch (received_message[command_position])
                        {
                            case Start_PWMs:
                            {   
//                                uint8 start_pwm = 0;
                                start_pwm = 0;
                                uint8 i;
                                for (i = 0; i < max_PWMs; ++i)
                                {
                                    array_PWMs[i].number_of_pulses = 0;
                                    if (array_PWMs[i].active == 1)
                                    {
                                        array_PWMs[i].number_of_pulses = 0;
                                        array_PWMs[i].started = 1;
//                                        array_PWMs[i].startPWM();
                                        start_pwm |= (1u << i);
                                    }
                                }
                                stopped_PWMs = 0;
                                ready_to_send_data = 0;
                                Control_PWM_Write(start_pwm);
                                send_error (Package_received_successfully, received_message);
                                break;                
                            }
                            case Stop_PWMs:
                            {
                                uint8 stop_pwm = 0;
                                uint8 i;
                                for (i = 0; i < max_PWMs; ++i)
                                {
                                    if (array_PWMs[i].active == 1)
                                    {
//                                        array_PWMs[i].stopPWM();
                                        array_PWMs[i].started = 0;
//                                        array_PWMs[i].active = 0;                                        
                                        stop_pwm |= (1u << i);
                                    }
                                }
//                                stopped_PWMs = 0;
                                ready_to_send_data = 1;
                                active_PWMs = 0;
//                                Control_PWM_Write(stop_pwm);
                                Control_PWM_Write(0);
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Ready_to_send_data:
                            {
//                                if (ready_to_send_data == 1)
//                                {
                                    form_package_ready_or_not (ready_to_send_data, received_message);
                                    send_ready_or_not(received_message);
//                                }
//                                else
//                                {
//                                    form_package_ready_or_not (ready_to_send_data, received_message);
//                                    send_ready_or_not(received_message);
//                                }
                                break;
                            }
                            case FindDevice:
                            {
                                uint8 lenght = 0;
                                lenght = MakeFiveBytesPackageWithCRC(FindDevice, DeviceType, received_message);
                                send_answer(received_message, lenght);
                                break;
                            }
                            case Enable_PWM:
                            {
                                Control_LED_Write(received_message[2]);
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Enable_emul_PWM:
                            {
                                uint8 ledOn = 0;
                                uint8 i;
                                active_PWMs = 0;
                                for (i = 0; i < max_PWMs; ++i)
                                {
                                    array_PWMs[i].active = (received_message[2] >> i) & 0x01;
//                                    ledOn |= (received_message[2] >> i) & 0x01;
                                    if (((received_message[2] >> i) & 0x01) == 1)
                                    {
                                        active_PWMs++;
                                    }                                    
                                }
//                                active_PWMs = q;
                                Control_LED_Write(received_message[2]);
                                array_PWMs[0].all_active = active_PWMs;
                                ready_to_send_data = 0;
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Set_period:
                            {
                                uint8 PWM_number = 2;
                                uint32 period = 0;
                                period = (received_message[3] << 24 | received_message[4] << 16 | received_message[5] << 8 | received_message[6]) \
                                * 255 + received_message[7];
                                array_PWMs[received_message[PWM_number]].period = period;
                                array_PWMs[received_message[PWM_number]].writePeriod (period);
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Set_compare:
                            {
                                uint8 PWM_number = 2;
                                uint32 compare = 0;
                                compare = (received_message[3] << 24 | received_message[4] << 16 | received_message[5] << 8 | received_message[6]) \
                                * 255 + received_message[7];
                                array_PWMs[received_message[PWM_number]].compare = compare;
                                array_PWMs[received_message[PWM_number]].writeCompare(compare);
//                                array_PWMs[received_message[PWM_number]].active = 1;
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Set_number_pulses:
                            {
                                uint8 PWM_number = 2;
                                uint32 number_of_pulses = 0;
                                number_of_pulses = (received_message[3] << 24 | received_message[4] << 16 | received_message[5] << 8 | received_message[6]) \
                                * 255 + received_message[7];
                                array_PWMs[received_message[PWM_number]].set_number_of_pulses = number_of_pulses;
//                                array_PWMs[received_message[PWM_number]].active = 1;
                                send_error (Package_received_successfully, received_message);
                                break;
                            }
                            case Read_measured_pulses:
                            {
                                uint8 PWM_number = 2;
                                
                                form_package_measured_pulses (&array_PWMs[received_message[PWM_number]], received_message[PWM_number], received_message);
                                send_measured_pulses (received_message);
//                                send
                                break;
                            }
                            default:
                            {
                                //error! unknown command 0xE9
                                stage = 0;          
                                read_bytes = 0;
                                send_error (Error_unknown_command, received_message);
                                break;
                            }
                        }  
//                        send_error (Package_received_successfully, received_message);
                    }
                    else
                    {
                        //damaged package
                        read_bytes = 0;
                        stage = 0;
                        CRC_value = 0;
                        CRC_calc = 0;
                        
                        send_error (Error_master_damaged_package, received_message);
                    }
                    stage = 0;          
                    read_bytes = 0;
                }
                break;
            }          
        }   
        UART_RS_485_ClearRxInterruptSource(UART_RS_485_INTR_RX_NOT_EMPTY);
    }    
    
    receivedByte = UART_RS_485_GetTxInterruptSource();
    if (receivedByte & UART_RS_485_INTR_TX_UART_DONE)
    {        
        Trasmitter_Write(Disable);
        CyDelayUs(1);
        UART_RS_485_ClearTxInterruptSource(UART_RS_485_INTR_TX_UART_DONE);
    }
}

void form_package_ready_or_not (const uint8 ready_to_send, uint8 *data)
{
    *data = Ready_to_send_data;
    *(data + 1) = 3;
    *(data + 2) = ready_to_send;   
    uint16 crc_calc = CRC_calculation(data,3);
    *(data + 3) = crc_calc >> 8;
    *(data + 4) = crc_calc & 0xFF;
}

void send_ready_or_not (const uint8 *data)
{
    uint8 bytes_number = 5;
    
    Trasmitter_Write(Enable);
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    uint8 i;
    for(i = 0; i < bytes_number; ++i)
    {
        UART_RS_485_UartPutChar(*(data + i));
    }    
}
void form_package_measured_pulses (const struct PWM_structure *PWM, const uint8 PWM_number, uint8 *data)
{
//    uint8 bytes_number = 0x08;
    uint8 max_uint = 255;
    uint32 overflow = 0;
    overflow = PWM->number_of_pulses / 255;
//    overflow = PWM->number_of_pulses;
    *data = Read_measured_pulses;
    *(data + 1) = 8;
    *(data + 2) = PWM_number;
    *(data + 3) = overflow >> 24;
    *(data + 4) = (overflow >> 16) & 0xFF;
    *(data + 5) = (overflow >> 8) & 0xFF;
    *(data + 6) = overflow & 0xFF;
    *(data + 7) = PWM->number_of_pulses - overflow * max_uint;
    uint16 crc_calc = CRC_calculation(data,8);
    *(data + 8) = crc_calc >> 8;
    *(data + 9) = crc_calc & 0xFF;
}
void send_measured_pulses (const uint8 *data)
{
    uint8 bytes_number = 10;
    
    Trasmitter_Write(Enable);
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    uint8 i;
    for(i = 0; i < bytes_number; ++i)
    {
        UART_RS_485_UartPutChar(*(data + i));
    }    
    
//    uint8 i;
//    for (i = 0; i < max_bytes; ++i)
//    {
//        *(data + i) = 0;
//    }  
}
void send_error (const uint8 error_code, uint8 *data)
{
    uint8 bytes_number = 0x02;
    *data = error_code;
    *(data + 1) = bytes_number;
    uint16 crc_calc = CRC_calculation(data,2);
    
    Trasmitter_Write(Enable);
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    UART_RS_485_UartPutChar(*data);
    UART_RS_485_UartPutChar(*(data + 1));
    UART_RS_485_UartPutChar(crc_calc >> 8);
    UART_RS_485_UartPutChar(crc_calc & 0xFF);    
    
    uint8 i;
    for (i = 0; i < max_bytes; ++i)
    {
        *(data + i) = 0;
    }
}

void Init_all_PWMs()
{    
    First_PWM.initPWM = PWM_1_Init;
    First_PWM.writePeriod = PWM_1_WritePeriod;
    First_PWM.writeCompare = PWM_1_WriteCompare;
    First_PWM.startPWM = PWM_1_Enable;
    First_PWM.stopPWM = PWM_1_Stop;
    
    Second_PWM.initPWM = PWM_2_Init;
    Second_PWM.writePeriod = PWM_2_WritePeriod;
    Second_PWM.writeCompare = PWM_2_WriteCompare;
    Second_PWM.startPWM = PWM_2_Enable;
    Second_PWM.stopPWM = PWM_2_Stop;
    
    Third_PWM.initPWM = PWM_3_Init;
    Third_PWM.writePeriod = PWM_3_WritePeriod;
    Third_PWM.writeCompare = PWM_3_WriteCompare;
    Third_PWM.startPWM = PWM_3_Enable;
    Third_PWM.stopPWM = PWM_3_Stop;
    
    Fourth_PWM.initPWM = PWM_4_Init;
    Fourth_PWM.writePeriod = PWM_4_WritePeriod;
    Fourth_PWM.writeCompare = PWM_4_WriteCompare;
    Fourth_PWM.startPWM = PWM_4_Enable;
    Fourth_PWM.stopPWM = PWM_4_Stop;
    
    Fifth_PWM.initPWM = PWM_5_Init;
    Fifth_PWM.writePeriod = PWM_5_WritePeriod;
    Fifth_PWM.writeCompare = PWM_5_WriteCompare;
    Fifth_PWM.startPWM = PWM_5_Enable;
    Fifth_PWM.stopPWM = PWM_5_Stop;
    
    Sixth_PWM.initPWM = PWM_6_Init;
    Sixth_PWM.writePeriod = PWM_6_WritePeriod;
    Sixth_PWM.writeCompare = PWM_6_WriteCompare;
    Sixth_PWM.startPWM = PWM_6_Enable;
    Sixth_PWM.stopPWM = PWM_6_Stop;
    
    Seventh_PWM.initPWM = PWM_7_Init;
    Seventh_PWM.writePeriod = PWM_7_WritePeriod;
    Seventh_PWM.writeCompare = PWM_7_WriteCompare;
    Seventh_PWM.startPWM = PWM_7_Enable;
    Seventh_PWM.stopPWM = PWM_7_Stop;
    
    Exemplary_PWM.initPWM = PWM_Exemplary_Init;
    Exemplary_PWM.writePeriod = PWM_Exemplary_WritePeriod;
    Exemplary_PWM.writeCompare = PWM_Exemplary_WriteCompare;
    Exemplary_PWM.startPWM = PWM_Exemplary_Enable;
    Exemplary_PWM.stopPWM = PWM_Exemplary_Stop;    
    
    
    array_PWMs[PWM1] = First_PWM;
    array_PWMs[PWM2] = Second_PWM;
    array_PWMs[PWM3] = Third_PWM;
    array_PWMs[PWM4] = Fourth_PWM;
    array_PWMs[PWM5] = Fifth_PWM;
    array_PWMs[PWM6] = Sixth_PWM;
    array_PWMs[PWM7] = Seventh_PWM;
    array_PWMs[PWMExemplary] = Exemplary_PWM;
    
    uint8 i;
    for ( i = PWM1; i < max_PWMs; ++i)
    {
        array_PWMs[i].initPWM();
        array_PWMs[i].startPWM();
        array_PWMs[i].max_PWM_period = max_period;   
    }
}

void reset_PWM_data (struct PWM_structure *data)
{
    data->active = 0;
    data->compare = 0;
    data->number_of_pulses = 0;
    data->period = 0;
    data->set_number_of_pulses = 0;    
}


uint8 MakeFiveBytesPackageWithCRC (const uint8 command, const uint8 data, uint8 *package)
{
    uint8 lenght = 0;
    uint16 crc_val = 0;
    lenght = MakeFiveBytesPackage (command, data, package);
    crc_val = CRC_calculation(package, lenght);
    lenght = addCrc(package, crc_val, lenght);
    return lenght;
}

uint8  MakeFiveBytesPackage (const uint8 command, const uint8 data, uint8 *package)
{
    const uint8 bytes_number = 3;    
    *package = command;
    *(package + 1) = bytes_number;
    *(package + 2) = data;
    return bytes_number;
}

uint8 addCrc(uint8 *_package, uint16 crc, uint8 _lenght)
{
    *(_package + _lenght) = crc >> 8;
    *(_package + _lenght + 1) = crc & 0xFF;
    return _lenght + 2;
}

void send_answer (const uint8 *data, const uint8 lenght)
{     
//    Trasmitter_Write(Enable);
    Trasmitter_Write(1);
//    Transmiter_Write (On);
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    uint8 i;
    for ( i = 0; i < lenght; ++i)
    {
        UART_RS_485_UartPutChar(*(data + i));
    }
}

uint8 initSlaveAddr ()
{
    int slaveAddr = 10;
    slaveAddr += PinAddr1_Read() + (PinAddr2_Read() << 1) + (PinAddr3_Read() << 2) + (PinAddr4_Read() << 3);
//    slaveAddr = PinAddr_Read();
//    PinAddr_ReadDaraReg();
//    slaveAddr += Addr_re
    UART_RS_485_UartSetRxAddress(slaveAddr);    
    UART_RS_485_UartSetRxAddressMask(0xFF);
    return slaveAddr;
}
/* [] END OF FILE */
