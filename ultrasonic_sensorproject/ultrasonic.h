/*
 * ultrasonic.h
 *
 *  Created on: Oct 11, 2023
 *      Author: abdo
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
#include "gpio.h"
#include "icu.h"
#include <util/delay.h>
//#include "common_macros.h"
#define trigger_Port  PORTB_ID
#define trigger_pin  PIN5_ID
extern uint16 g_IcutimeHigh;
extern uint8 g_edgeCount;

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
