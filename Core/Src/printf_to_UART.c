/*
 * printf_to_UART.c
 *
 *  Created on: Jun 15, 2021
 *      Author: KUBA
 */
#include "usart.h"

int __io_putchar(int ch) {
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	HAL_UART_Transmit(&huart2, &*c, 1, 10);
	return ch;
}
