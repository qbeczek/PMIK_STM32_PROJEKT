/*
 * temp.h
 *
 *  Created on: Jun 8, 2021
 *      Author: KUBA
 */

#ifndef INC_BMP280_READ_H_
#define INC_BMP280_READ_H_

#include "stdio.h"
#include "bmp280.h"
#include "onScreen.h"
#include "i2c.h"



void delay_ms(uint32_t period_ms);
int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t BMP280_init(void);
int8_t BMP280_TempRead(double *temperature);
int8_t BMP280_PressRead(double *pressure);
double getTemp(double temperature);
#endif /* INC_BMP280_READ_H_ */
