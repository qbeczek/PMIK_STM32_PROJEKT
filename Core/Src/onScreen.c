/**
  ******************************************************************************
  * @file    onScreen.c
  * @brief   Plik zawiera funkcje wyświetlające dane na wyświetlaczu ST7735
  *****************************************************************************
**/
#include "onScreen.h"

#define MAX_BUF_SIZE 10

char TEMP_BUF[MAX_BUF_SIZE];
char PRES_BUF[MAX_BUF_SIZE];
char ERR_TEMP_BUF[MAX_BUF_SIZE];
char ERR_PRES_BUF[MAX_BUF_SIZE];

/*!
 * @brief funkcja wyświetlająca temperaturę na wyświetlaczu ST7735
 *
 * @param[in] temperature : Temperatura przekazana do funkcji
 *
 * @return void
 */
void writeTemp(double temperature){
	sprintf(TEMP_BUF, "%.2f", temperature);
	ST7735_WriteString(50, 16, TEMP_BUF, Font_11x18, GREEN, BLACK);
}

/*!
 * @brief funkcja wyświetlająca cisnienie na wyświetlaczu ST7735
 *
 * @param[in] pressure : Cisnienie przekazane do funkcji
 *
 * @return void
 */
void writePress(double pressure){
    sprintf(PRES_BUF, "%.2f", pressure);
    ST7735_WriteString(25, 46, PRES_BUF, Font_11x18, GREEN, BLACK);
}
/*!
 * @brief funkcja wyświetlająca menu na wyświetlaczu ST7735
 *
 * @return void
 */
void writeMenu(void){
	ST7735_WriteString(5, 5, "Temperatura [st. C]", Font_7x10, YELLOW,BLACK);
	ST7735_WriteString(5, 35, "Cisnienie [Pa]", Font_7x10, YELLOW,BLACK);
	ST7735_WriteString(5, 65, "Stezenie PM10", Font_7x10, YELLOW,BLACK);
}

/*!
 * @brief funkcja wyświetlająca błędy odczytu ciśnienia i temperatury na wyświetlaczu ST7735
 *
 * @param[in] errTemp : kod błędu odczytu temperatury
 * @param[in] errPres : kod błędu odczytu ciśnienia
 * @return void
 */
void errMenu(int errTemp, int errPres){
	sprintf(ERR_TEMP_BUF, "%d", errTemp);
	sprintf(ERR_PRES_BUF, "%d", errPres);
	ST7735_WriteString(0, 10, "Blad odczytu czujnika BMP280 - kody bledow:", Font_7x10, YELLOW,BLACK);

	ST7735_WriteString(65, 30, ERR_TEMP_BUF, Font_16x26, RED, BLACK);
    ST7735_WriteString(65, 56, ERR_PRES_BUF, Font_16x26, RED, BLACK);
	ST7735_WriteString(0, 80, "Sprawdz czujnik oraz  zresetuj urzadzenie", Font_7x10, YELLOW,BLACK);
}

/*!
 * @brief funkcja wyświetlająca ostrzeżenie o wysokiej temperaturze na wyświetlaczu ST7735
 *
 * @param[in] temperature : Temperatura przekazana do funkcji
 *
 * @return void
 */
void writeTempHighWarn(double temperature){
	ST7735_WriteString(2, 5, "Wywietrz miejsce pracy", Font_7x10, BLACK,RED);
	ST7735_WriteString(5, 20, "Aktualna temperatura:", Font_7x10, YELLOW ,RED);
	sprintf(TEMP_BUF, "%.2f", temperature);
	ST7735_WriteString(35, 35, TEMP_BUF, Font_16x26, GREEN, RED);
}

/*!
 * @brief funkcja wyświetlająca ostrzeżenie o zbyt niskiej temperaturze na wyświetlaczu ST7735
 *
 * @param[in] temperature : Temperatura przekazana do funkcji
 *
 * @return void
 */
void writeTempLowWarn(double temperature){
	ST7735_WriteString(2, 5, "Za niska temperatura", Font_7x10, BLACK,RED);
	ST7735_WriteString(5, 20, "Aktualna temperatura:", Font_7x10, YELLOW ,RED);
	sprintf(TEMP_BUF, "%.2f", temperature);
	ST7735_WriteString(35, 35, TEMP_BUF, Font_16x26, GREEN, RED);
}
