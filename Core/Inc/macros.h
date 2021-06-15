/*
 * macros.h
 *
 *  Created on: 15 cze 2021
 *      Author: KUBA
 */

#ifndef INC_MACROS_H_
#define INC_MACROS_H_
/*!
 * @name constants to specify a range
 */
#define TEMP_MAX 							INT8_C(30)
#define TEMP_MIN							INT8_C(15)
/*!
 * @name error variables
 */
int8_t errTemp = 0;
int8_t errPres = 0;
/*!
 * @name global measure variables
 */
double temp = 0.0;
double pres = 0.0;
/*!
 * @name auxiliary variables
 */

int refreshScreen1 = 0;
int refreshScreen2 = 0;
int refreshScreen3 = 0;
int refreshScreen4 = 0;

#endif /* INC_MACROS_H_ */
