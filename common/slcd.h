// I2C code for AVR master and mcp23008 port expander slave

// For use with the Adafruit I2C/SPI backpack for LCDs using the Hitachi
// HD44780 driver or equivalent. Uses 4 bit mode. Only I2C implemented here.

#ifndef __SLCD_H__
#define __SLCD_H__

#include "MCP23008.h"

// Bits in byte written to HD44780 via MCP23008 GP1-GP7 pins (GP0 not connected)
#define LCD_RS     1 // GP1:   Register Select (0: cmd, 1: data)
#define LCD_E      2 // GP2:   Enable bit
#define LCD_DB4    3 // GP3-6: Highest 4 data bits
#define LCD_DB5    4 //        DB0-3 not used in 4-bit mode.
#define LCD_DB6    5 //        Instead, a byte is written to DB4-7 in 2 nibbles. 
#define LCD_DB7    6 //        
#define LCD_LITE   7 // GP7:   LCD backlight on/off (only on 16 pin LCDs)

// Line start positions for a 20x4 display
#define LINE1  0 // First char on line 1
#define LINE2 40 // First char on line 2
#define LINE3 20 // First char on line 3
#define LINE4 84 // First char on line 4

void send_nibble(uint8_t rs, uint8_t nibble, uint8_t backlit);
void send_byte(uint8_t rs, uint8_t data, uint8_t backlit);
void lcd_write(uint8_t data, uint8_t backlit);
void lcd_command(uint8_t cmd);
void init_lcd();
void lcd_puts(const char *s, uint8_t backlit);
void lcd_goto(uint8_t pos);
void lcd_clrscr();
void lcd_home();

#endif /*__SLCD_H__*/
