#ifndef SOURCE_GDT_H
#define SOURCE_GDT_H

#include<types.h>

struct gdt_entry
{
    uint16_t limit;
    uint16_t base1;
    uint8_t base2;
    uint8_t access;
    uint8_t limit_flags;
    uint8_t base3;
} __attribute__((packed));

struct gdt_pointer
{
    uint16_t size;
    uint32_t offset;
} __attribute__((packed));

void init_gdt_entry(size_t num, uint16_t limit, uint32_t base, uint8_t access,
        uint8_t limit_flags);
void init_gdt_table(void);

#endif
