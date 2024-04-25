/*
 * ultrasonic.c
 *
 *  Created on: Oct 11, 2023
 *      Author: abdo
 */
#include "ultrasonic.h"
#include <math.h>
uint16 g_IcutimeHigh = 0;
uint8 g_edgeCount = 0;
void Ultrasonic_init(void){
	ICU_ConfigType icuconf={F_CPU_8,RAISING};
ICU_init(&icuconf);
GPIO_setupPinDirection(trigger_Port, trigger_pin, PIN_OUTPUT);
ICU_setCallBack(Ultrasonic_edgeProcessing);

}
void Ultrasonic_Trigger(void){

	g_IcutimeHigh = 0;
	GPIO_writePin(trigger_Port, trigger_pin, LOGIC_HIGH);
	_delay_us(12);
	GPIO_writePin(trigger_Port, trigger_pin, LOGIC_LOW);

}
uint16 Ultrasonic_readDistance(void){

	uint16 distance=0;
	Ultrasonic_Trigger();
	while(g_edgeCount!=2);
	g_edgeCount=0;
	distance =( (float)g_IcutimeHigh/58)+1 ;
	return distance;
}
void Ultrasonic_edgeProcessing(void){

	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_IcutimeHigh = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
	}

}

