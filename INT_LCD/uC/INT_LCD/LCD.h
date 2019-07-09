/*
 * LCD.h
 *
 * Created: 01/06/2018 10:39:18 a. m.
 *  Author: Xochiquetzal
 */ 


#ifndef LCD_H_
#define LCD_H_


void Enable();
void LCD_cmd4(char);
void LCD_wrd4(char);
void LCD_wrd4str(char *, ...);
void LCD_init();
void LCD_goto(char,char);
void LCDSetContrast(char);
char LCDReadAddress(char);

#endif /* LCD_H_ */