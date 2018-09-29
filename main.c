/*
 * File:   main.c
 * Author: zakrent
 *
 * Created on September 22, 2018, 2:04 PM
 */

#include "system.h"
#include <xc.h>
#include <stdlib.h>
#include "lcd.h"

void init(){
    OPTION_REG = 0b01010111;
    ANSEL = 0x00;
    lcd_init();
}

void main(void) {
    init();
   
    char buffer[5];
    uint8_t counter = 0;
    while(1){ 
        counter++;
        lcd_clear();
        lcd_print("Counter");
        lcd_cursor_set(1,0);
        itoa(buffer, counter, 10);
        lcd_print(buffer);
        __delay_ms(1000);
    }
    return;
}
