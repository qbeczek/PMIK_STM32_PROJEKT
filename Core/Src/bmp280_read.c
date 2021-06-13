/*
 * temp.c
 *
 *  Created on: Jun 8, 2021
 *      Author: KUBA
 */
/*!
 *  @brief Example shows basic setup of sensor which includes following
 *      Initialization of the interface.
 *      performing the sensor initialization.
 */

#include <bmp280_read.h>


struct bmp280_dev bmp;

/*
 * Funkcja inicjalizująca czujnik bmp280
 * Zwracana wartość rslt to kod błędu w przypadku błędu inicjalizacji
 */
int8_t BMP280_init(void) {
	int8_t rslt;
    struct bmp280_config conf;

    /* Map the delay function pointer with the function responsible for implementing the delay */
    bmp.delay_ms = delay_ms;

    /* Assign device I2C address based on the status of SDO pin (GND for PRIMARY(0x76) & VDD for SECONDARY(0x77)) */
    bmp.dev_id = (BMP280_I2C_ADDR_PRIM<<1);

    /* Select the interface mode as I2C */
    bmp.intf = BMP280_I2C_INTF;

    /* Map the I2C read & write function pointer with the functions responsible for I2C bus transfer */
    bmp.read = i2c_reg_read;
    bmp.write = i2c_reg_write;

    rslt = bmp280_init(&bmp);


    /* Always read the current settings before writing, especially when
     * all the configuration is not modified
     */
    rslt = bmp280_get_config(&conf, &bmp);


    /* configuring the temperature oversampling, filter coefficient and output data rate */
    /* Overwrite the desired settings */
    conf.filter = BMP280_FILTER_COEFF_2;

    /* Pressure oversampling set at 4x */
    conf.os_pres = BMP280_OS_4X;

    /* Temperature oversampling set at 4x */
    conf.os_temp = BMP280_OS_4X;

    /* Setting the output data rate as 1HZ(1000ms) */
    conf.odr = BMP280_ODR_1000_MS;
    rslt = bmp280_set_config(&conf, &bmp);


    /* Always set the power mode after setting the configuration */
    rslt = bmp280_set_power_mode(BMP280_NORMAL_MODE, &bmp);


    return rslt;

}
/*
 * Funkcja odczytuje temperature z czujnika i przypisuje je do zmiennej globalnej
 * Zwracana wartość rslt to kod błędu przy złym odczycie
 */
int8_t BMP280_TempRead(double *temperature) {
	 int8_t errGet = 0;
	 int8_t errComp = 0;
     struct bmp280_uncomp_data ucomp_data;
     double temp;
	 /* Pobranie danych z czujnika */
     if(errGet = bmp280_get_uncomp_data(&ucomp_data, &bmp) != BMP280_OK) {
    	 return errGet;
     }

     /* Konwersja na liczby zmiennoprzecinkowe */
      if(errComp = bmp280_get_comp_temp_double(&temp, ucomp_data.uncomp_temp, &bmp) != BMP280_OK){
    	  return errComp;
      }
     /*przypisanie wartości temperatury do zmiennej globalnej*/
     *temperature = temp;
     return errComp;
}

/*
 * Funkcja odczytuje cisnienie z czujnika i przypisuje je do zmiennej globalnej
 * Zwracana wartość rslt to kod błędu przy złym odczycie
 */
int8_t BMP280_PressRead(double *pressure) {
	 int8_t rslt;
     struct bmp280_uncomp_data ucomp_data;

     double pres;

	 /* Pobranie danych z czujnika */
     rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);

     /* Konwersja na liczby zmiennoprzecinkowe */
     rslt = bmp280_get_comp_pres_double(&pres, ucomp_data.uncomp_press, &bmp);

     /*przypisanie wartości ciśnienia do zmiennej globalnej*/
     *pressure = pres;

     return rslt;
}
/*!
 *  @brief Function that creates a mandatory delay required in some of the APIs such as "bmg250_soft_reset",
 *      "bmg250_set_foc", "bmg250_perform_self_test"  and so on.
 *
 *  @param[in] period_ms  : the required wait time in milliseconds.
 *  @return void.
 *
 */
void delay_ms(uint32_t period_ms)
{
    /* Implement the delay routine according to the target machine */
	HAL_Delay(period_ms);
}

/*!
 *  @brief Function for writing the sensor's registers through I2C bus.
 *
 *  @param[in] i2c_addr : sensor I2C address.
 *  @param[in] reg_addr : Register address.
 *  @param[in] reg_data : Pointer to the data buffer whose value is to be written.
 *  @param[in] length   : No of bytes to write.
 *
 *  @return Status of execution
 *  @retval 0 -> Success
 *  @retval >0 -> Failure Info
 *
 */
int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{

    /* Implement the I2C write routine according to the target machine. */
	HAL_I2C_Mem_Write(&hi2c1, i2c_addr, reg_addr, 1, reg_data, length, 100);
    return 0;
}

/*!
 *  @brief Function for reading the sensor's registers through I2C bus.
 *
 *  @param[in] i2c_addr : Sensor I2C address.
 *  @param[in] reg_addr : Register address.
 *  @param[out] reg_data    : Pointer to the data buffer to store the read data.
 *  @param[in] length   : No of bytes to read.
 *
 *  @return Status of execution
 *  @retval 0 -> Success
 *  @retval >0 -> Failure Info
 *
 */
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{

    /* Implement the I2C read routine according to the target machine. */
	HAL_I2C_Mem_Read(&hi2c1, i2c_addr, reg_addr, 1, reg_data, length, 100);
    return 0;
}

/*!
 *  @brief Function for writing the sensor's registers through SPI bus.
 *
 *  @param[in] cs           : Chip select to enable the sensor.
 *  @param[in] reg_addr     : Register address.
 *  @param[in] reg_data : Pointer to the data buffer whose data has to be written.
 *  @param[in] length       : No of bytes to write.
 *
 *  @return Status of execution
 *  @retval 0 -> Success
 *  @retval >0 -> Failure Info
 *
 */

/*!
 *  @brief Prints the execution status of the APIs.
 *
 *  @param[in] api_name : name of the API whose execution status has to be printed.
 *  @param[in] rslt     : error code returned by the API whose execution status has to be printed.
 *
 *  @return void.
 */
