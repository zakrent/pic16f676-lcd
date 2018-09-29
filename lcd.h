/* 
 * File:   lcd.h
 * Author: zakrent
 *
 * Created on September 22, 2018, 5:30 PM
 */

#ifndef  LCD_H
#define LCD_H

#include <xc.h>
#include <stdint.h>

#define LCD_PORT PORTC
#define LCD_TRIS   TRISC

void lcd_init();
void lcd_clear();
void lcd_putc(char c);
void lcd_print(char* string);
void lcd_cursor_set(uint8_t x, uint8_t y);

#endif	/* LCD_H */

