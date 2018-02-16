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
#include "CRC16.h"
#include "Modbus.h"

#define Master_addr 0x02
#define max_number_bytes 20u
#define bytes_number 1u
#define min_package_lenght_from_pc 2u
#define min_package_lenght_rs_485 3u
#define Enable 1u
#define Disable 0u
#define CRC_lenght 2u

uint8 findDevicesOK = 0;
uint8 test_count = 0;
uint8 received_from_pc_byte = 0u;
uint8 received_from_slave_byte = 0u;
uint8 addr_received = 0u;
uint8 received_slave_address = 0;

uint16 calc_crc_value = 0;
uint16 received_crc_value = 0;
uint8 received_package_lenght = 0;

uint8 received_from_PC_package [max_number_bytes] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};

uint8 received_from_Slave_package [max_number_bytes] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};


void UART_PC_Interrupts();
void UART_RS_485_Interrupts();
void send_error (const uint8 error_code, uint8 addr, uint8 *data);

CY_ISR_PROTO(isr_from_Timer_from_pc);
CY_ISR_PROTO(isr_from_Timer_from_slave);


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_RS_485_SetCustomInterruptHandler(UART_RS_485_Interrupts);
    UART_RS_485_Start();
    
    UART_PC_SetCustomInterruptHandler(UART_PC_Interrupts);
    UART_PC_Start();
    
    Rs485_send_Write(Disable);
    
    Clock_2_Start();
    Timer_from_pc_Init();    
    Timer_from_pc_WritePeriod(15);
    Timer_from_pc_SetInterruptMode(Timer_from_pc_STATUS_TC_INT_MASK);
    Timer_from_pc_Enable();
    
    Timer_from_slave_Init();    
    Timer_from_slave_WritePeriod(15);
    Timer_from_slave_SetInterruptMode(Timer_from_slave_STATUS_TC_INT_MASK);
    Timer_from_slave_Enable();
    
    isr_Timer_from_pc_StartEx(isr_from_Timer_from_pc);
    isr_Timer_from_slave_StartEx(isr_from_Timer_from_slave);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

CY_ISR (isr_from_Timer_from_pc)
{
    //ERROR 
    //received wrong package
    Timer_from_pc_Stop();

    addr_received = 0;
    received_from_pc_byte = 0;
    calc_crc_value = 0;
    received_crc_value = 0;
    
    send_error (Error_communication_with_pc, Master_addr, received_from_PC_package);
}

CY_ISR (isr_from_Timer_from_slave)
{
    //ERROR 
    //received wrong package
    Timer_from_slave_Stop();
    
    received_from_slave_byte = 0;
    calc_crc_value = 0;
    received_crc_value = 0;       
    send_error (Error_communication_with_slave, received_slave_address, received_from_PC_package);    
    received_slave_address = 0;
}

void UART_PC_Interrupts()
{
    uint32 tmp_received_byte = UART_PC_GetRxInterruptSource();

    //read buffer interrupt
    if ((tmp_received_byte & UART_PC_INTR_RX_NOT_EMPTY) != 0u)
    {
        //read 1 byte from UART
        tmp_received_byte = UART_PC_UartGetByte();
        
        //if received address byte
        if ( addr_received == 0 && received_from_pc_byte == 0)
        {
            Timer_from_pc_Enable(); // start timer
            addr_received = 1;
            received_from_pc_byte = 0;
            //save received address 
            received_slave_address = (uint8)tmp_received_byte;
        }
        else
        {            
            //save data to the array 
            received_from_PC_package[received_from_pc_byte] = (uint8)tmp_received_byte;
            received_from_pc_byte++;
            
            //end of the received package
            if ((received_from_pc_byte == received_from_PC_package[bytes_number] + min_package_lenght_from_pc) &&
                (received_from_pc_byte >= 4))
            {     
                Timer_from_pc_Stop();
                //package lenght calculation without CRC value
                received_package_lenght = received_from_PC_package[bytes_number] + min_package_lenght_from_pc - 2;
                //read CRC from received data
                received_crc_value = received_from_PC_package[received_package_lenght] << 8 | received_from_PC_package[received_package_lenght + 1];
                //calculation CRC
                calc_crc_value = CRC16 (received_from_PC_package, received_package_lenght);
                
                if ( calc_crc_value == received_crc_value)
                {                    
//                    //send data to a slave
//                    Rs485_send_Write(Enable);
//                    CyDelayUs(1);
                    
                    //----------------------------------------------------------
                    //----------------------------------------------------------
                    if (received_from_PC_package[0] != FindMaster )
                    {
                        //send data to a slave
                        Rs485_send_Write(Enable);
                        CyDelayUs(1);
                        //send adress byte
                        UART_RS_485_UartPutChar(received_slave_address | UART_RS_485_UART_MP_MARK);                    
                        //send rest of the package
                        uint8 i;
                        for( i = 0; i < received_from_PC_package[bytes_number] + min_package_lenght_from_pc; ++i)  
                        {
                            UART_RS_485_UartPutChar(received_from_PC_package[i]);
                        }
                    }
                    else
                    {
//                        if ( received_from_PC_package[1] == FindDevice)
//                        {
//                            findDevicesOK = 1;
                            UART_PC_UartPutChar(Master_addr);
                            UART_PC_UartPutChar(FindMaster);
                            UART_PC_UartPutChar(2);
                            UART_PC_UartPutChar(0x41);
                            UART_PC_UartPutChar(0xFA);
//                        }
                    }
                    //----------------------------------------------------------
                    //---------------------------------------------------------- 
                    
                    
                }
                else  //Error CRC
                {                   
                    //package is damaged                    
                    send_error (Error_damadged_package_from_pc, Master_addr, received_from_PC_package);
                }
                
                received_from_pc_byte = 0;
                addr_received = 0;
            }
        } 
        UART_PC_ClearRxInterruptSource(UART_PC_INTR_RX_NOT_EMPTY); 
    }    
}

void UART_RS_485_Interrupts()
{
    uint32 tmp_received_byte = UART_RS_485_GetRxInterruptSource();

    if (tmp_received_byte & UART_RS_485_INTR_RX_NOT_EMPTY)
    {
        tmp_received_byte = UART_RS_485_UartGetByte();
        received_from_Slave_package[received_from_slave_byte] = (uint8)tmp_received_byte;
        received_from_slave_byte++;
        
        if (received_from_slave_byte == received_from_Slave_package[bytes_number] + min_package_lenght_from_pc )
        {
            Timer_from_slave_Stop();
            //package lenght calculation without CRC value
            received_package_lenght = received_from_Slave_package[bytes_number] + min_package_lenght_from_pc - 2;
            //read CRC from received data
            received_crc_value = received_from_Slave_package[received_package_lenght] << 8 | received_from_Slave_package[received_package_lenght + 1];
            //calculation CRC
            calc_crc_value = CRC16 (received_from_Slave_package, received_package_lenght);
            
            if (calc_crc_value == received_crc_value)
            {     
                UART_PC_UartPutChar(received_slave_address);                  
                received_slave_address = 0;
                uint8 i;
                uint8 received_package_lenght = received_from_Slave_package[bytes_number];
                for( i = 0; i < received_package_lenght + min_package_lenght_from_pc; ++i)
                {
                    UART_PC_UartPutChar(received_from_Slave_package[i]);
                    received_from_Slave_package[i] = 0;
                }
                received_from_slave_byte = 0;
            }
            else
            {               
                //package is damaged
                send_error (Error_damaged_package_from_slave, received_slave_address, received_from_PC_package);
            }
        }
        UART_RS_485_ClearRxInterruptSource(UART_RS_485_INTR_RX_NOT_EMPTY); 
    }
    
    tmp_received_byte = UART_RS_485_GetTxInterruptSource();
    if (tmp_received_byte & UART_RS_485_INTR_TX_UART_DONE)
    {        
        Rs485_send_Write(Disable);
        CyDelayUs(1);     
        Timer_from_slave_Enable();
        UART_RS_485_ClearTxInterruptSource(UART_RS_485_INTR_TX_UART_DONE);
    }
}

void send_error (const uint8 error_code, uint8 addr, uint8 *data)
{
    uint8 BNumber = 0x02;
    *data = addr;
    *(data + 1) = error_code;
    *(data + 2) = BNumber;
    uint16 crc_calc = CRC16(data,3);   
   
    UART_PC_UartPutChar(*data);
    UART_PC_UartPutChar(*(data + 1));
    UART_PC_UartPutChar(*(data + 2));
    UART_PC_UartPutChar(crc_calc >> 8);
    UART_PC_UartPutChar(crc_calc & 0xFF);    
    
    uint8 i;
    uint8 max_bytes = 20;
    for (i = 0; i < max_bytes; ++i)
    {
        *(data + i) = 0;
    }
}
/* [] END OF FILE */
