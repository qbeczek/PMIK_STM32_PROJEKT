/*
 * printf_to_UART.c
 *
 *  Created on: Jun 15, 2021
 *      Author: KUBA
 */
#include "usart.h"

int __io_putchar(int ch)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    return 1;
}
