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
//#include "counter.h"
#include "Modbus.h"
#include "interrupt.h"

#define On                      1u
#define Off                     0u
#define Master_Address          0x02
//#define max_counters            8
#define max_counter_count       65534
#define Start_counter_value     0
#define start_all_counters      1
#define stop_all_counters       0
#define command_position        0
#define number_of_bytes_position 1

//#define Read_Data_RS_485        0
//#define Transfer_Data_RS_485    1
#define max_bytes_protocol      20


uint8 test_Init_timer = 0;
uint8 test_Enable_timer = 0;



// DeviceType  
// 1 --- pulse measurement
// 2 --- gerkon measurement
// 3 --- pulse emulator
// 4 --- gerkon emulator
const int8 DeviceType = 1;
uint8 SlaveAddr = 0;

uint8 number_received_bytes = 0;
uint8 read_bytes = 0;
//uint8 stage = 0;
//uint8 received_data [max_bytes] = {0};
uint8 received_message [max_bytes_protocol] = {0};
uint8 stopped_counters = 0;
uint8 active_counters = 0;
_Bool readyToSend = 0;


//    uint16 CRC_calc = 0;
//    uint16 CRC_value = 0;
//    uint8 received_message_lenght = 0;
//    uint16 CRC_value_hi = 0;
//    uint16 CRC_value_lo = 0;

uint8 used_led_counters = 0;

//void reset_all_counters ();
void reset_all_counters (struct Test_counter *counters, uint8 counter_number);
void read_all_counters ();

//--------------------------------------------------------------
//void init_counter_array();
void init_all_counters ();
void init_all_interrupts ();
void init_counter_before_start(struct Test_counter *counters_array, uint8 counter_number);
void resest_counter (struct Test_counter *counter);
void init_first_counter();
void init_second_counter();
void init_third_counter();
void init_fourth_counter();
void init_fifth_counter();
void init_sixth_counter();
void init_seventh_counter();
void init_examplary_counter();
void init_pinInterrupt ();
uint8 initSlaveAddr ();

uint8 MakeFourBytesPackage (const uint8 command, uint8 *package);
uint8 MakeFiveBytesPackage (const uint8 command, const uint8 data, uint8 *package);
uint8 MakePackageWithCRC (const uint8 command, uint8 *package);
uint8 MakeTenBytesPackage (const uint8 command, const uint8 channel, const uint32 data, uint8 *package);
uint8 MakeElevenBytesPackage (const uint8 command, const uint8 channel, const uint32 dataOV, const uint32 data, uint8 *package);
uint8 MakeFourBytesPackageWithCRC (const uint8 command, uint8 *package);
uint8 MakeFiveBytesPackageWithCRC (const uint8 command, const uint8 data, uint8 *package);
uint8 MakeTenBytesPackageWithCRC (const uint8 command, const uint8 channel, const uint32 data, uint8 *package); 
uint8 MakeElevenBytesPackageWithCRC (const uint8 command, const uint8 channel, const uint32 dataOV, const uint32 data, uint8 *package);
uint8 addCrc(uint8 *_package, uint16 crc, uint8 _lenght);
void resetCounterBeforeStart (struct Test_counter *counter);
//void resetExamplaryCounter (struct Test_counter *counters);
void resetExamplaryCounter (struct Examplary_counter counters);

void commandRun(uint8 *receivedMessage, const uint8 *receivedBytes, struct Test_counter *counter);
void EnableCounters(struct Test_counter *counters, const uint8 data);

void send_answer (const uint8 *data, const uint8 lenght);
_Bool receiveData (const uint8 data, uint8 *receivedMessage, uint8 *readBytes);
_Bool isPackageDamaged (const uint8 *receivedMessage, const uint8 *receivedBytes);
void SetCounterCount(struct Test_counter *counters, const uint8 *receivedMessage);
void StartActiveCounters(struct Test_counter *counters, const uint8 *receivedMessage);
void send_ready_or_not (const uint8 *data);
void form_package_ready_or_not (const uint8 ready_to_send, uint8 *data);
//--------------------------------------------------------------
CY_ISR_PROTO(from_Timer_from_master);

void UART_RS_485_Interrupts()
{
    uint32 receivedByte;
    receivedByte = UART_RS_485_GetRxInterruptSource();
    
    if(receivedByte & UART_RS_485_INTR_RX_NOT_EMPTY)
    {
        receivedByte = (uint8)UART_RS_485_UartGetByte();
        
        if (receiveData(receivedByte, received_message, &read_bytes) == 1)
        {
//            (uint8 *receivedMessage, const uint8 *receivedBytes);
            if (!isPackageDamaged(received_message, &read_bytes))
            {                               
                commandRun(received_message, &read_bytes, array_counters);
                read_bytes = 0; 
            }
            else
            {
                //send error {Wrong CRC}
                uint8 lenght = 0;
                lenght = MakeFourBytesPackageWithCRC(Error_master_damaged_package, received_message);
                send_answer(received_message, lenght);                
            }
        }    
        UART_RS_485_ClearRxInterruptSource(UART_RS_485_INTR_RX_NOT_EMPTY);
    }    
    receivedByte = UART_RS_485_GetTxInterruptSource();
    if (receivedByte & UART_RS_485_INTR_TX_UART_DONE)
    {        
        Transfer_enable_Write(Off);
        CyDelayUs(1);
        UART_RS_485_ClearTxInterruptSource(UART_RS_485_INTR_TX_UART_DONE);
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
     
    Transfer_enable_Write(Off);

    Clock_1_Start(); 
    Clock_2_Start();
    Clock_3_Start();
    
    UART_RS_485_SetCustomInterruptHandler(UART_RS_485_Interrupts);    
    UART_RS_485_Start(); 
    SlaveAddr = initSlaveAddr();
    
    isr_Timer_from_master_StartEx(from_Timer_from_master);
    
    Timer_from_master_Init();
    Timer_from_master_WritePeriod(5);    
    Timer_from_master_SetInterruptMode(Timer_from_master_STATUS_TC_INT_MASK);
    
    init_all_counters ();
    init_all_interrupts (); 
    
    for(;;)
    {       
    }
}

CY_ISR(from_Timer_from_master)
{
     //ERROR 
    //received wrong package
    Timer_from_master_Stop();
    uint8 lenght = 0;
    lenght = MakeFourBytesPackage(Error_master_communication, received_message);
    send_answer(received_message, lenght);
    read_bytes = 0;
}

void init_first_counter()
{
    array_counters[counter_1].StartTimer = Timer_1_Start;
    array_counters[counter_1].StopTimer = Timer_1_Stop;
    array_counters[counter_1].InitTimer = Timer_1_Init;
    array_counters[counter_1].EnableTimer = Timer_1_Enable;
    array_counters[counter_1].WritePeriod = Timer_1_WritePeriod;  
    array_counters[counter_1].ReadStatus = Timer_1_ReadStatus;
    array_counters[counter_1].ReadPeriod = Timer_1_ReadPeriod;
}
void init_second_counter()
{
    array_counters[counter_2].StartTimer = Counter_2_Start;
    array_counters[counter_2].StopTimer = Counter_2_Stop;
    array_counters[counter_2].InitTimer = Counter_2_Init;
    array_counters[counter_2].EnableTimer = Counter_2_Enable;
    array_counters[counter_2].WritePeriod = Counter_2_WritePeriod;  
    array_counters[counter_2].ReadStatus = Counter_2_ReadStatus;
//    array_counters[counter_2].initVar = Counter_2_initVar;
}
void init_third_counter()
{
    array_counters[counter_3].StartTimer = Counter_3_Start;
    array_counters[counter_3].StopTimer = Counter_3_Stop;
    array_counters[counter_3].InitTimer = Counter_3_Init; 
    array_counters[counter_3].EnableTimer = Counter_3_Enable;
    array_counters[counter_3].WritePeriod= Counter_3_WritePeriod;
}
void init_fourth_counter()
{
    array_counters[counter_4].StartTimer = Counter_4_Start;
    array_counters[counter_4].StopTimer = Counter_4_Stop;
    array_counters[counter_4].InitTimer = Counter_4_Init;    
    array_counters[counter_4].EnableTimer = Counter_4_Enable;
    array_counters[counter_4].WritePeriod = Counter_4_WritePeriod; 
}
void init_fifth_counter()
{
    array_counters[counter_5].StartTimer = Counter_5_Start;
    array_counters[counter_5].StopTimer = Counter_5_Stop;
    array_counters[counter_5].InitTimer = Counter_5_Init;    
    array_counters[counter_5].EnableTimer = Counter_5_Enable;
    array_counters[counter_5].WritePeriod = Counter_5_WritePeriod;  
}
void init_sixth_counter()
{
    array_counters[counter_6].StartTimer = Counter_6_Start;
    array_counters[counter_6].StopTimer = Counter_6_Stop;
    array_counters[counter_6].InitTimer = Counter_6_Init;    
    array_counters[counter_6].EnableTimer = Counter_6_Enable;
    array_counters[counter_6].WritePeriod= Counter_6_WritePeriod; 
}
void init_seventh_counter()
{
    array_counters[counter_7].StartTimer = Counter_7_Start;
    array_counters[counter_7].StopTimer = Counter_7_Stop;
    array_counters[counter_7].InitTimer = Counter_7_Init;
    array_counters[counter_7].EnableTimer = Counter_7_Enable;
    array_counters[counter_7].WritePeriod = Counter_7_WritePeriod; 
}
void init_examplary_counter()
{
    ExCounter.Start = ExamplaryCounter_Start;
    ExCounter.Stop = ExamplaryCounter_Stop;
    ExCounter.Init = ExamplaryCounter_Init;
    ExCounter.Enable = ExamplaryCounter_Enable;
    ExCounter.ReadCounterCount = ExamplaryCounter_ReadCounter;
    ExCounter.setCount = ExamplaryCounter_WriteCounter;
    ExCounter.setPeriod = ExamplaryCounter_WritePeriod;
}
void init_pinInterrupt ()
{
    InterruptPin.Enable = isrCounter_Enable;
    InterruptPin.Disable = isrCounter_Disable;
}
void init_counter_before_start(struct Test_counter *counters_array, uint8 counter_number)
{
    uint8 i;
    uint16 _period = 15600;
    
    for (i = 0; i < counter_number; ++i)
    {
        counters_array[i].InitTimer();
        counters_array[i].WritePeriod(_period);
//        counters_array[i].period = counters_array[i].ReadPeriod();
//        counters_array[i].testIsTimerStarted = counters_array[i].initVar;
    }
    ExCounter.Init();
//    init_pinInterrupt ();
}
void init_all_counters ()
{
    init_first_counter();
    init_second_counter();
    init_third_counter();
    init_fourth_counter();
    init_fifth_counter();
    init_sixth_counter();
    init_seventh_counter();
    init_examplary_counter();    
    
    reset_all_counters (array_counters, max_counters);
    init_counter_before_start(array_counters, max_counters);
}
void init_all_interrupts ()
{
    isr_CExamplary_OV_StartEx(CExamplary_interrupt);  
    init_pinInterrupt ();
    
    isrCounter_StartEx(inputPinISR);
    InterruptPin.Disable();
    
    isrTimer1_StartEx(Timer_1_interrupt);
    isrTimer2_StartEx(Timer_2_interrupt);
    isrTimer3_StartEx(Timer_3_interrupt);
    isrTimer4_StartEx(Timer_4_interrupt);
    isrTimer5_StartEx(Timer_5_interrupt);
    isrTimer6_StartEx(Timer_6_interrupt);
    isrTimer7_StartEx(Timer_7_interrupt);
}
void reset_all_counters (struct Test_counter *counters, uint8 counter_number)
{
    uint8 i;
    for ( i = 0; i < counter_number; ++i)
    {
        resest_counter(&counters[i]);
    }
}
void resetCounterBeforeStart (struct Test_counter *counter)
{    
    counter->ready_to_operate = 1;
    counter->counter_count = 0;//
    counter->counter_OV = 0;//
    counter->Examplary_count_end_val = 0;//
    counter->Examplary_count_start_val = 0;//
    counter->Examplary_count_val = 0;//
    counter->Examplary_OV_val = 0;//
    counter->Examplary_OV_end_val = 0;//
    counter->Examplary_OV_start_val = 0;//
    counter->start_Examplary_pulse = 0;//
    counter->recievedPackage.firstBurst = 0;
    counter->recievedPackage.secondBurst = 0;
    counter->recievedPackage.endOfPackage = 0;
    counter->recievedPackage.endOfMeasurement = 0;
//    counter->testIsTimerStarted = counter->ReadStatus();
//    counter->isTim
}
void resest_counter (struct Test_counter *counter)
{
    counter->active = 0;//
    counter->ready_to_operate = 1;
    counter->counter_count = 0;//
    counter->counter_count_set_val = 0;//
    counter->counter_OV = 0;//
    counter->counter_OV_set_val = 0;//
    counter->Examplary_count_end_val = 0;//
    counter->Examplary_count_start_val = 0;//
    counter->Examplary_count_val = 0;//
    counter->Examplary_OV_val = 0;//
    counter->Examplary_OV_end_val = 0;//
    counter->Examplary_OV_start_val = 0;//
    counter->start_Examplary_pulse = 0;//
    counter->recievedPackage.firstBurst = 0;
    counter->recievedPackage.secondBurst = 0;
    counter->recievedPackage.endOfPackage = 0;
    counter->recievedPackage.endOfMeasurement = 0;
}

void resetExamplaryCounter (struct Examplary_counter counters)
{
    counters.setCount(0);      
    counters.counter_count = 0;  
    counters.counter_OV = 0;
}
void send_answer (const uint8 *data, const uint8 lenght)
{     
    Transfer_enable_Write (On);
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    uint8 i;
    for ( i = 0; i < lenght; ++i)
    {
        UART_RS_485_UartPutChar(*(data + i));
    }
}
uint8  MakeFourBytesPackage (const uint8 command, uint8 *package)
{
    const uint8 bytes_number = 2;    
    *package = command;
    *(package + 1) = bytes_number;
    return bytes_number;
}
uint8  MakeFiveBytesPackage (const uint8 command, const uint8 data, uint8 *package)
{
    const uint8 bytes_number = 3;    
    *package = command;
    *(package + 1) = bytes_number;
    *(package + 2) = data;
    return bytes_number;
}
uint8  MakeTenBytesPackage (const uint8 command, const uint8 channel, const uint32 data, uint8 *package)
{
    const uint8 bytes_number = 8;  
    const uint8 maxPeriod = 255;
    uint32 overflow = 0;
    overflow = data / maxPeriod;
    *package = command;
    *(package + 1) = bytes_number;
    *(package + 2) = channel;
    *(package + 3) = overflow >> 24;
    *(package + 4) = (overflow >> 16) & 0xFF;
    *(package + 5) = (overflow >> 8) & 0xFF;
    *(package + 6) = overflow & 0xFF;
    *(package + 7) = data - overflow * maxPeriod;
    return bytes_number;
}
uint8  MakeElevenBytesPackage (const uint8 command, const uint8 channel, const uint32 dataOV, const uint32 data, uint8 *package)
{
    const uint8 bytes_number = 9;  
//    const uint8 maxPeriod = 255;
    uint32 overflow = 0;
//    overflow = data / maxPeriod;
    *package = command;
    *(package + 1) = bytes_number;
    *(package + 2) = channel;
    *(package + 3) = dataOV >> 24;
    *(package + 4) = (dataOV >> 16) & 0xFF;
    *(package + 5) = (dataOV >> 8) & 0xFF;
    *(package + 6) = dataOV & 0xFF;
    *(package + 7) = data >> 8;
    *(package + 8) = data & 0xFF;
    return bytes_number;
}
uint8 MakeFourBytesPackageWithCRC (const uint8 command, uint8 *package)
{
    uint8 lenght = 0;
    uint16 crc_val = 0;
    lenght = MakeFourBytesPackage (command, package);
    crc_val = CRCcalculation(package, lenght);
    lenght = addCrc(package, crc_val, lenght);
    return lenght;
}
uint8 MakeFiveBytesPackageWithCRC (const uint8 command, const uint8 data, uint8 *package)
{
    uint8 lenght = 0;
    uint16 crc_val = 0;
    lenght = MakeFiveBytesPackage (command, data, package);
    crc_val = CRCcalculation(package, lenght);
    lenght = addCrc(package, crc_val, lenght);
    return lenght;
}
uint8 MakeTenBytesPackageWithCRC (const uint8 command, const uint8 channel, const uint32 data, uint8 *package)
{
    uint8 lenght = 0;
    uint16 crc_val = 0;
    lenght = MakeTenBytesPackage (command, channel, data, package);
    crc_val = CRCcalculation(package, lenght);
    lenght = addCrc(package, crc_val, lenght);
    return lenght;
}
uint8 MakeElevenBytesPackageWithCRC (const uint8 command, const uint8 channel, const uint32 dataOV, const uint32 data, uint8 *package)
{
    uint8 lenght = 0;
    uint16 crc_val = 0;
    lenght = MakeElevenBytesPackage (command, channel, dataOV, data, package);
    crc_val = CRCcalculation(package, lenght);
    lenght = addCrc(package, crc_val, lenght);
    return lenght;
}
uint8 addCrc(uint8 *_package, uint16 crc, uint8 _lenght)
{
    *(_package + _lenght) = crc >> 8;
    *(_package + _lenght + 1) = crc & 0xFF;
    return _lenght + 2;
}
_Bool receiveData (const uint8 data, uint8 *receivedMessage, uint8 *readBytes)
{
    const uint8 bytes_position = 1;
    static uint8 stage = 0;
    
    if (*readBytes == 0)
    {
        stage = 0;
    }
    
    switch (stage)
    {
        // command received
        case 0:
        {   
            *(receivedMessage + *readBytes) = data;
            (*readBytes)++;
            stage ++;  
            Timer_from_master_Enable();
            return 0;
            break;
        }
        // read number of bytes
        case 1:
        {                
            *(receivedMessage + *readBytes) = data;
            (*readBytes)++;
            stage++;
            return 0;
            break;
        }
        // read data
        case 2:            
        {
            *(receivedMessage + *readBytes) = data;
            (*readBytes)++;
            if (*readBytes == (*(received_message + bytes_position) + 2))
            {
                Timer_from_master_Stop();   
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        default:
        {
            return 4;
            break;
        }
    }  
}
_Bool isPackageDamaged (const uint8 *receivedMessage, const uint8 *receivedBytes)
{
    _Bool True = 1;
    _Bool False = 0;
    uint16 CRC_calc = 0;
    uint16 CRC_value = 0;
    uint8 received_message_lenght = *receivedBytes - 2;
//    received_message_lenght = *receivedBytes - 2;
//    CRC_value_hi = (*(received_message + *receivedBytes - 2) << 8);
//    CRC_value_lo = *(received_message + *receivedBytes - 1);
    CRC_value = ((*(received_message + *receivedBytes - 2) << 8) | *(received_message + *receivedBytes - 1));
    CRC_calc = CRCcalculation(receivedMessage, received_message_lenght);
    
    if ( CRC_calc == CRC_value)
    {
        return False;
    }
    else
    {
        return True;
    }
}
void commandRun(uint8 *receivedMessage, const uint8 *receivedBytes, struct Test_counter *counter)
{
    uint8 commandposition = 0;
//    uint8 dataPosition = 2;
    switch (receivedMessage[commandposition])
    {
        case StartCounters:
        {   
            StartActiveCounters(array_counters, receivedMessage);
            uint8 lenght = 0;
            lenght = MakeFourBytesPackageWithCRC(Package_received_successfully,receivedMessage);
            send_answer(receivedMessage, lenght);
            break;                
        }
        case StopCounters:
        {
            uint8 lenght = 0;
            lenght = MakeFourBytesPackageWithCRC(Package_received_successfully,receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        case Ready_to_send_data:
        {
            form_package_ready_or_not (readyToSend, receivedMessage);
            send_ready_or_not(receivedMessage);
            break;
        }
        case FindDevice:
        {
            uint8 lenght = 0;
            lenght = MakeFiveBytesPackageWithCRC(FindDevice, DeviceType, receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        case EnableCounter: //ready
        {
            uint8 lenght = 0;
            EnableCounters(counter, receivedMessage[2]);
            
            Led_Write(receivedMessage[2]);
            
            lenght = MakeFourBytesPackageWithCRC(Package_received_successfully,receivedMessage);
            send_answer(receivedMessage, lenght);           

            break;
        }
        case SetCount: // ready
        {
            SetCounterCount(array_counters, received_message);
            uint8 lenght = 0;
            lenght = MakeFourBytesPackageWithCRC(Package_received_successfully,receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        case ReadCount:
        {
            uint8 lenght = 0;
            uint8 counterNumber = receivedMessage[2];
            lenght = MakeElevenBytesPackageWithCRC(ReadCount, counterNumber, counter[counterNumber].counter_OV, counter[counterNumber].counter_count, receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        case ReadExamplaryStartValue:
        {
            uint8 lenght = 0;
            uint8 counterNumber = receivedMessage[2];            
            //-------read examplary counter start value
            lenght = MakeElevenBytesPackageWithCRC(ReadExamplaryStartValue, counterNumber, counter[counterNumber].Examplary_OV_start_val , counter[counterNumber].Examplary_count_start_val , receivedMessage);
            send_answer(receivedMessage, lenght);
//            //-------read examplary counter end value
//            lenght = MakeElevenBytesPackageWithCRC(ReadCount, counterNumber, counter[counterNumber].Examplary_OV_end_val , counter[counterNumber].Examplary_count_end_val, receivedMessage);
//            send_answer(receivedMessage, lenght);
        }
        case ReadExamplaryEndValue:
        {
            uint8 lenght = 0;
            uint8 counterNumber = receivedMessage[2];            
//            //-------read examplary counter start value
//            lenght = MakeElevenBytesPackageWithCRC(ReadCount, counterNumber, counter[counterNumber].Examplary_OV_start_val , counter[counterNumber].Examplary_count_start_val , receivedMessage);
//            send_answer(receivedMessage, lenght);
            //-------read examplary counter end value
            lenght = MakeElevenBytesPackageWithCRC(ReadExamplaryEndValue, counterNumber, counter[counterNumber].Examplary_OV_end_val , counter[counterNumber].Examplary_count_end_val, receivedMessage);
            send_answer(receivedMessage, lenght);
        }
        case ReadExamplaryCounter:
        {
            uint8 lenght = 0;
            uint8 counterNumber = receivedMessage[2]; 
            lenght = MakeElevenBytesPackageWithCRC(ReadExamplaryCounter, counterNumber, counter[counterNumber].Examplary_OV_val, counter[counterNumber].Examplary_count_val, receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        case ReadCounterMeasuredPulses:
        {
            uint8 lenght = 0;
            uint8 counterNumber = receivedMessage[2]; 
            lenght = MakeElevenBytesPackageWithCRC(ReadCounterMeasuredPulses, counterNumber, counter[counterNumber].counter_OV, counter[counterNumber].counter_count, receivedMessage);
            send_answer(receivedMessage, lenght);
            break;
        }
        default: // ready
        {
            //error! unknown command 0xE9
            read_bytes = 0;
            uint8 lenght = 0;
            lenght = MakeFourBytesPackageWithCRC(Error_unknown_command,received_message);
            send_answer(receivedMessage, lenght);
            break;
        }
    }  
//                        send_error (Package_received_successfully, received_message);
}
void EnableCounters(struct Test_counter *counters, const uint8 data)
{
    uint8 i;
    uint8 max_counter = 8;
    for (i = 0; i < max_counter; ++i)
    {        
        counters[i].active = (data >> i) & 0x01;
    }
}
void SetCounterCount(struct Test_counter *counters, const uint8 *receivedMessage)
{
//    uint32 data = 0;
    uint32 maxPeriod = 65534;
    uint32 ov_value = 0;
    uint32 numberOfPulses = 0;
    
    numberOfPulses = (receivedMessage[3] << 24 | receivedMessage[4] << 16 | receivedMessage[5] << 8 | receivedMessage[6]) \
                * 255 + receivedMessage[7];
    ov_value = numberOfPulses / maxPeriod;
                
    counters[receivedMessage[2]].counter_OV_set_val = ov_value;
    counters[receivedMessage[2]].counter_count_set_val = numberOfPulses - ov_value * maxPeriod;
//    counters[receivedMessage[2]].setCount(counters[receivedMessage[2]].counter_count_set_val);
}
void StartActiveCounters(struct Test_counter *counters, const uint8 *receivedMessage)
{
    //---Start examplary counter
    ExCounter.active = 1;
    resetExamplaryCounter(ExCounter);
    
    ExCounter.Enable();    
    readyToSend = 0;
    active_counters = 0;
    stopped_counters = 0;
    
//    InterruptPin.Enable();
    uint8 i;    
    for (i = 0; i < max_counters; ++i)
    {
        if (counters[i].active == 1)
        {
            active_counters++;
            resetCounterBeforeStart(&counters[i]);    
//            if (!counters[i].initVar)
//            {
//                counters[i].InitTimer();
//            }            
            counters[i].EnableTimer();
//            counters[i].testIsTimerStarted = counters[i].ReadStatus();
        }
    } 
    InterruptPin.Enable();
//    counters[i].initVar = Timer_1_initVar;
//    Counter_1_Start();
}
void form_package_ready_or_not (const uint8 ready_to_send, uint8 *data)
{
    *data = Ready_to_send_data;
    *(data + 1) = 3;
    *(data + 2) = ready_to_send;   
    uint16 crc_calc = CRCcalculation(data,3);
    *(data + 3) = crc_calc >> 8;
    *(data + 4) = crc_calc & 0xFF;
}
void send_ready_or_not (const uint8 *data)
{
    uint8 bytes_number = 5;
    
    Transfer_enable_Write(On);    
    CyDelayUs(1);
    
    UART_RS_485_UartPutChar (Master_Address | UART_RS_485_UART_MP_MARK);
    uint8 i;
    for(i = 0; i < bytes_number; ++i)
    {
        UART_RS_485_UartPutChar(*(data + i));
    }    
}
uint8 initSlaveAddr ()
{
    uint8 slaveAddr = 10;
    slaveAddr += PinAddr_Read();
    UART_RS_485_UartSetRxAddress(slaveAddr);    
    return slaveAddr;
}
/* [] END OF FILE */
