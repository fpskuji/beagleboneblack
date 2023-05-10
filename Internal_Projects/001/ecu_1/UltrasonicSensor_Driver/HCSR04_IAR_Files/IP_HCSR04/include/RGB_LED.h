/*
 * RGB_LED.h
 *
 *  Created on: 27 Mar 2023
 *      Author: Angela.Depamallo
 */


#ifndef RGB_LED_H_
#define RGB_LED_H_

#include "Dio.h"

void RED_ON(void) __attribute__ ((section (".flash_blinkled")));
void GREEN_ON(void) __attribute__ ((section (".flash_blinkled")));
void BLUE_ON(void) __attribute__ ((section (".flash_blinkled")));
void PURPLE_ON(void) __attribute__ ((section (".flash_blinkled")));
void ALL_OFF(void) __attribute__ ((section (".flash_blinkled")));

#endif /* RGB_LED_H_ */
