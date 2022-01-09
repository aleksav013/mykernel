#include<types.h>
#include<string.h>
#include<asm.h>
#include<vga.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void set_color(enum vga_color fg, enum vga_color bg)
{
    terminal_color = fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_initialize()
{
    terminal_row=0;
    terminal_column=0;
    set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
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
    for(size_t i=0;i<VGA_HEIGHT;i++) for(size_t j=0;j<VGA_WIDTH;j++)
        terminal_buffer[i*VGA_WIDTH+j]=terminal_buffer[(i+1)*VGA_WIDTH+j];
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

void terminal_writestring(char* data)
{
    for(int i=0;data[i]!='\0';i++) terminal_putchar(data[i]);
}

void terminal_writeint(uint32_t num)
{
    char string[100];
    for(int i=0;i<100;i++) string[i]='\0';
    char *str=string;
    itos(num,str);
    terminal_writestring(str);
}

void terminal_writefloat(double num)
{
    char string[100];
    for(int i=0;i<100;i++) string[i]='\0';
    char *str=string;
    ftos(num,str);
    terminal_writestring(str);
}

void clear()
{
    for(size_t i=0;i<VGA_HEIGHT;i++) for(size_t j=0;j<VGA_WIDTH;j++) terminal_putchar(' ');
    terminal_column=0;
    terminal_row=0;
}
