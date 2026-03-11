#include "uart_driver.h"
#include "driver/uart.h"

#define UART_PORT UART_NUM_0
#define BUF_SIZE 1024

// UART Config 
void uart_init(void) { 
    uart_config_t config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE, 
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_param_config(UART_PORT, &config);
    uart_driver_install(UART_PORT, BUF_SIZE, 0, 0, NULL, 0);
}

// fn to send one byte over UART 
void uart_write_byte(uint8_t data) { 
    uart_write_bytes (UART_PORT, (const char*)&data, 1);
}

void uart_write_string(const char *str) 
{
    while(*str){
        uart_write_bytes(*str ++ );
    }
}

