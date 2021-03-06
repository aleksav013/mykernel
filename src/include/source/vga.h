#ifndef SOURCE_VGA_H
#define SOURCE_VGA_H

#include<types.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_DARK_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_TURQUOISE = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_PURPLE = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_BLUE = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_PINK = 13,
    VGA_COLOR_YELLOW = 14,
    VGA_COLOR_WHITE = 15,
};

void set_color(enum vga_color fg, enum vga_color bg);
void terminal_initialize(void);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void movescreen(void);
void next_field(void);
void previous_field(void);
void terminal_putchar(char c);
void terminal_writestring(const char* data);
void terminal_writeint(uint32_t num);
void terminal_writefloat(double num);
void clear(void);

#endif
