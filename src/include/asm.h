#ifndef ASM_H
#define ASM_H

#include<types.h>

extern uint8_t ioport_in(uint8_t port);
extern void ioport_out(uint8_t port, char data);

#endif
