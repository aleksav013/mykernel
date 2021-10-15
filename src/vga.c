#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include"string.h"
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

extern char ioport_in(uint8_t port);
extern void ioport_out(uint8_t port, char data);

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t) uc | (uint16_t) color << 8;
}
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
 
void terminal_initialize()
{
    terminal_row=0;
    terminal_column=0;
    terminal_color=vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer=(uint16_t*) 0xB8000;
    for(size_t y=0;y<VGA_HEIGHT;y++)
    {
	for(size_t x=0;x<VGA_WIDTH;x++)
	{
	    const size_t index=y*VGA_WIDTH+x;
	    terminal_buffer[index]=vga_entry(' ', terminal_color);
	}
    }
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
    const size_t index=y*VGA_WIDTH+x;
    terminal_buffer[index]=vga_entry(c, color);
}

void movescreen()
{
    terminal_row--;
    for(size_t i=0;i<VGA_HEIGHT;i++) for(size_t j=0;j<VGA_WIDTH;j++) terminal_buffer[i*VGA_WIDTH+j]=terminal_buffer[(i+1)*VGA_WIDTH+j];
}

void next_field()
{
    if(++terminal_column==VGA_WIDTH) terminal_column=0,terminal_row++;
}

void previous_field()
{
    if(terminal_column) terminal_column--;
    else terminal_row--,terminal_column=VGA_WIDTH-1;
}
 
void terminal_putchar(char c)
{
    if(c=='\n') terminal_column=0,terminal_row++;
    else
    {
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	next_field();
    }
    if (terminal_row==VGA_HEIGHT) movescreen();
}
 
void terminal_writestring(const char* data)
{
    for(int i=0;data[i]!='\0';i++) terminal_putchar(data[i]);
}

void terminal_writeint(const uint32_t num)
{
    char string[100];
    char *str=string;
    itos(str,num);
    terminal_writestring(str);
}

void prompt()
{
    terminal_writestring("[user@myos] > ");
}

void clear()
{
    for(size_t i=0;i<VGA_HEIGHT;i++) for(size_t j=0;j<VGA_WIDTH;j++) terminal_putchar(' ');
    terminal_column=0;
    terminal_row=0;
}
