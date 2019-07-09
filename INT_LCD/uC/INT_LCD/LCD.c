/*
 * LCD.c
 *
 * Created: 01/06/2018 10:40:17 a. m.
 *  Author: Xochiquetzal
 */ 
#ifndef F_CPU
#define F_CPU 8e6
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <stdarg.h>
#include <stdio.h>
#include "LCD.h"

void LCD_goto(char r,char c){
	LCD_cmd4(0x80 | (0x40*(r - 1)) | (c - 1));
}

void LCD_init(){
	//Start delay
	_delay_ms(15);
	//Set 4 bit mode
	PORTC = 0x02;
	//Trigger instruction
	Enable();
	//DL = 4 bit mode, N;S = 2 Lines with 5x7 dots font
	LCD_cmd4(0x28);
	_delay_ms(1);
	//D = On display, C = Display cursor, B = Blink cursor
	LCD_cmd4(0x0F);
	_delay_ms(1);
	//Return home
	LCD_cmd4(0x03);
	_delay_ms(5);
	//I/D = increments the DDRAM, S = No shift
	LCD_cmd4(0x06);
	_delay_ms(2);
}

void Enable(){
	PORTB |= 0x80;
	_delay_us(35);
	PORTB &= 0x7F;
}

void LCD_cmd4(char cmd){
	PORTC &= 0xF0;
	PORTC |= cmd >> 4;
	Enable();
	PORTC &= 0xF0;
	PORTC |= cmd & 0x0F;
	Enable();
}

void LCD_wrd4(char sym){
	PORTB |= 0x20;
	PORTC &= 0xF0;
	PORTC |= sym >> 4;
	Enable();
	PORTC &= 0xF0;
	PORTC |= sym & 0x0F;
	Enable();
	PORTB &= 0xDF;
}

void LCD_wrd4str(char *str, ...){
	char lcd[16];
	va_list args;
	va_start(args, str);
	vsprintf(lcd, str, args);
	va_end(args);
	char i = 0;
	while (*(lcd + i) != '\0')
	LCD_wrd4(*(lcd + i++));
}

void LCDSetContrast(char pContrast){
	
}

char LCDReadAddress(char pAddress){
	return '0';
}