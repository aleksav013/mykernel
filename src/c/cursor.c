#include<source/cursor.h>
#include<asm.h>

void enable_cursor(uint32_t cursor_start, uint32_t cursor_end)
{
	ioport_out(0x3D4, 0x0A);
	ioport_out(0x3D5, (ioport_in(0x3D5) & 0xC0) | cursor_start);

	ioport_out(0x3D4, 0x0B);
	ioport_out(0x3D5, (ioport_in(0x3D5) & 0xE0) | cursor_end);
}

void disable_cursor()
{
	ioport_out(0x3D4, 0x0A);
	ioport_out(0x3D5, 0x20);
}

uint16_t get_cursor_position(void)
{
    uint16_t pos = 0;
    ioport_out(0x3D4, 0x0F);
    pos |= (uint16_t)ioport_in(0x3D5);
    ioport_out(0x3D4, 0x0E);
    pos |= (uint16_t)(ioport_in(0x3D5) << 8);
    return pos;
}
