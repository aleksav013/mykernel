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

extern void load_gdt(struct gdt_pointer *gdtp);

struct gdt_entry gdt[5];
struct gdt_pointer gdtp;

void init_gdt_entry(size_t num, uint32_t limit, uint32_t base, uint8_t access, uint8_t limit_flags)
{
    gdt[num].limit=limit;
    gdt[num].base1=(base & 0xffff);
    gdt[num].base2=(base & 0xff0000) >> 16;
    gdt[num].access=access;
    gdt[num].limit_flags=limit_flags;
    gdt[num].base3=(base & 0xff000000) >> 24;
}

void init_gdt_table()
{
    gdtp.size=sizeof(gdt)-1;
    gdtp.offset=(uint32_t)&gdt;

    init_gdt_entry(0,0,0,0,0);                              // null segment
    init_gdt_entry(1,0xffffffff,0,0b10011010,0b11001111);   // code segment
    init_gdt_entry(2,0xffffffff,0,0b10010010,0b11001111);   // data segment
    init_gdt_entry(3,0xffffffff,0,0b11111010,0b11001111);   // user mode code segment
    init_gdt_entry(4,0xffffffff,0,0b11110010,0b11001111);   // user mode data segment

    load_gdt(&gdtp);
}
