#ifndef SOURCE_ASM_H
#define SOURCE_ASM_H

#include<types.h>

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1


extern uint8_t ioport_in(uint8_t port);
extern void ioport_out(uint8_t port, int data);


#endif
