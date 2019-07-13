/*
 * INT_LCD.c
 *
 * Created: 7/18/2017 10:52:11 AM
 * Author : Pandora MCIE
 */ 
#define F_CPU 8e6
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "LCD.h"
#include "UART.h"

int main(void){
	DDRB = 0xF6;
	DDRC = 0x0F;
	TCCR0A = 0x02;
	TCCR0B = 0x05;
	TIMSK0 = 0x02;
	OCR0A = 0xFF;
	
	LCD_init();
	sei();
    while (1);
}

ISR(TIMER0_COMPA_vect){//Hola ...o
	LCD_goto(1, 1);
	LCD_wrd4str("Hola mundo");
}
