#include "lcd.h"
#include "system.h"
#include <stdbool.h>

#define LCD_CMD_CLEAR 0b

void lcd_send(char msg, bool RS){
    LCD_PORT = (msg & 0b1111) | 0b100000 | (int)RS << 4;
    __delay_us(1);
    LCD_PORT &= 0b011111;
    __delay_us(1);
}

void lcd_init(){
    LCD_PORT = 0b100000;
    LCD_TRIS = 0x00;
    
    lcd_send(0b0011, 0);
    lcd_send(0b0011, 0);
    lcd_send(0b0011, 0);
    
    lcd_send(0b0010, 0);
    lcd_send(0b1000, 0);
    __delay_us(50);
    lcd_send(0b0000, 0);
    lcd_send(0b1111, 0);
    __delay_us(50);
    lcd_send(0b0000, 0);
    lcd_send(0b0001, 0);
    __delay_us(1);
    lcd_send(0b0000, 0);
    lcd_send(0b0110, 0);
    __delay_us(1);
}

void lcd_putc(char c){
    lcd_send(c >> 4, 1);
    lcd_send(c, 1);
    __delay_us(50);
}

void lcd_print(char* string){
    for(uint8_t i = 0; string[i] != 0; i++){
        lcd_putc(string[i]);
    }
}

void lcd_clear(){
    lcd_send(0b0000, 0);
    lcd_send(0b0001, 0);
    __delay_ms(2);
    lcd_cursor_set(0,0);
}

void lcd_cursor_set(uint8_t x, uint8_t y){
    uint8_t addr = 0x40*x+y;
    lcd_send(addr>>4 | 0b1000, 0);
    lcd_send(addr, 0);
    __delay_us(50);
}
