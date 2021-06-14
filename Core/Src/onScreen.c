/*
 * onScreen.c
 *
 *  Created on: 11 cze 2021
 *      Author: KUBA
 */
#include "onScreen.h"
#define MAX_BUF_SIZE 10

char TEMP_BUF[MAX_BUF_SIZE];
char PRES_BUF[MAX_BUF_SIZE];
char ERR_TEMP_BUF[MAX_BUF_SIZE];
char ERR_PRES_BUF[MAX_BUF_SIZE];

void writeTemp(double temperature){
	sprintf(TEMP_BUF, "%.2f", temperature);
	ST7735_WriteString(50, 16, TEMP_BUF, Font_11x18, GREEN, BLACK);
}

void writePress(double pressure){
    sprintf(PRES_BUF, "%.2f", pressure);
    ST7735_WriteString(25, 46, PRES_BUF, Font_11x18, GREEN, BLACK);
}

void writeMenu(void){
	ST7735_WriteString(5, 5, "Temperatura [st. C]", Font_7x10, YELLOW,BLACK);
	ST7735_WriteString(5, 35, "Cisnienie [Pa]", Font_7x10, YELLOW,BLACK);
}

void errMenu(int errTemp, int errPres){
	sprintf(ERR_TEMP_BUF, "%d", errTemp);
	sprintf(ERR_PRES_BUF, "%d", errPres);
	ST7735_WriteString(0, 10, "Blad odczytu czujnika BMP280 - kody bledow:", Font_7x10, YELLOW,BLACK);

	ST7735_WriteString(65, 30, ERR_TEMP_BUF, Font_16x26, RED, BLACK);
    ST7735_WriteString(65, 56, ERR_PRES_BUF, Font_16x26, RED, BLACK);
	ST7735_WriteString(0, 80, "Sprawdz czujnik oraz  zresetuj urzadzenie", Font_7x10, YELLOW,BLACK);
}


void writeTempHighWarn(double temperature){

}
void writeTempLowWarn(double temperatures){

}
