#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stdint.h>

void uart_init(void);
void uart_write_byte(uint8_t data);
void uart_write_string(const char * str);
uint8_t uart_read_byte(void);

#endif
