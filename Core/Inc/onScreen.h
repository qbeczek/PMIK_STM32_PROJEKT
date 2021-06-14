/*
 * onScreen.h
 *
 *  Created on: 11 cze 2021
 *      Author: KUBA
 */

#ifndef INC_ONSCREEN_H_
#define INC_ONSCREEN_H_

#include "ST7735.h"
#include <stdio.h>
void writeTemp(double temperature);
void writePress(double pressure);
void writeMenu(void);
void errMenu(int errTemp, int errPres);

void writeTempHighWarn(double temperature);
void writeTempLowWarn(double temperatures);

#endif /* INC_ONSCREEN_H_ */
