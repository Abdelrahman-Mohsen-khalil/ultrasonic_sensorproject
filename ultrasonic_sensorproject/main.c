#include "ultrasonic.h"
#include"lcd.h"
#include <avr/io.h>
int main(){
Ultrasonic_init();
LCD_init();
uint16  temp=0;
SREG |= (1<<7);
LCD_moveCursor(0, 0);
LCD_displayString("Distance=     cm  ");

while(1){

	temp=Ultrasonic_readDistance();
    LCD_moveCursor(0, 10);
    LCD_intgerToString(temp);




	}
}

