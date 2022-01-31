#ifndef SOURCE_IDT_H
#define SOURCE_IDT_H

#include<types.h>

#define INTERRUPT_GATE_32 0x8E

#define KERNEL_CODE 0x08
#define KERNEL_DATA 0x10

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1

struct idt_entry
{
    uint16_t offset1;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset2;
} __attribute__((packed));

struct idt_pointer
{
    uint16_t size;
    uint32_t offset;
} __attribute__((packed));

void init_idt_entry(size_t num, uint32_t offset, uint16_t selector, uint8_t
        type_attr);
void add_idt_entry(size_t num,uint32_t offset);
void init_pic(void);
void init_idt_table(void);

#endif
