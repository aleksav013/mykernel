#ifndef SOURCE_CURSOR_H
#define SOURCE_CURSOR_H

#include<types.h>

void enable_cursor(uint32_t cursor_start, uint32_t cursor_end);
void disable_cursor(void);
uint16_t get_cursor_position(void);

#endif
