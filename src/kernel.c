#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include"vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1
// IO Ports for Keyboard
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

extern char ioport_in(uint8_t port);
extern void ioport_out(uint8_t port, char data);

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
 
void terminal_initialize(void) 
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
 
void terminal_putchar(char c) 
{
    if(c=='\n') terminal_column = 0,terminal_row++;
    else
    {
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column==VGA_WIDTH) terminal_column=0,terminal_row++;
    }
    if (terminal_row==VGA_HEIGHT) movescreen();
}
 
void terminal_writestring(const char* data) 
{
    for(int i=0;data[i]!='\0';i++) terminal_putchar(data[i]);
}

void init_keyboard()
{
    // 0xFD = 1111 1101 in binary. enables only IRQ1
    // Why IRQ1? Remember, IRQ0 exists, it's 0-based
    ioport_out(PIC1_DATA_PORT, 0xFD);
}

#include"keyboard.h"
void handle_keyboard_interrupt()
{
    // Write end of interrupt (EOI)
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    unsigned char status = ioport_in(KEYBOARD_STATUS_PORT);

    // Lowest bit of status will be set if buffer not empty
    // (thanks mkeykernel)
    if (status & 0x1)
    {
	char keycode = ioport_in(KEYBOARD_DATA_PORT);
	if (keycode < 0 || (uint8_t)keycode >= 128) return;

	if(keycode==14)
	{
	    if(terminal_column) terminal_column--;
	    terminal_putchar(keyboard[keycode]);
	    terminal_column--;
	    return;
	}

	terminal_putchar(keyboard[keycode]);

    }
}
void print_message()
{
    for(size_t i=0;i<50;i++)
    {
       for(size_t j=0;j<i;j++) terminal_writestring("#");
       terminal_writestring("Hello, kernel World!\n");
    }
}

void kernel_main(void)
{
    terminal_initialize();
    print_message();
    init_idt_table();
    init_keyboard();
    terminal_writestring("First part is working\n");
    while(1);
}
