/**
  ******************************************************************************
  * @file    printf_to_UART.c
  * @brief   Plik zawieta pomocniczą funkcję do przekierowania stdin z funkcji printf na uart.
  ******************************************************************************
  *
  */
#include "usart.h"

int __io_putchar(int ch) {
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	HAL_UART_Transmit(&huart2, &*c, 1, 10);
	return ch;
}
