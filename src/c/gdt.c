#include<source/gdt.h>
#include<types.h>

extern void load_gdt(struct gdt_pointer *gdtp);

struct gdt_entry gdt[5];
struct gdt_pointer gdtp;

void init_gdt_entry(size_t num, uint16_t limit, uint32_t base, uint8_t access,
		uint8_t limit_flags)
{
    gdt[num].limit=limit;
    gdt[num].base1=(base & 0xffff);
    gdt[num].base2=(uint8_t)((base & 0xff0000) >> 16);
    gdt[num].access=access;
    gdt[num].limit_flags=limit_flags;
    gdt[num].base3=(uint8_t)((base & 0xff000000) >> 24);
}

void init_gdt_table(void)
{
    gdtp.size=sizeof(gdt)-1;
    gdtp.offset=(uint32_t)&gdt;

    init_gdt_entry(0,0,0,0,0);              // null segment
    init_gdt_entry(1,0xffff,0,0x9a,0xcf);   // code segment
    init_gdt_entry(2,0xffff,0,0x92,0xcf);   // data segment
    init_gdt_entry(3,0xffff,0,0xfa,0xcf);   // user mode code segment
    init_gdt_entry(4,0xffff,0,0xf2,0xcf);   // user mode data segment

    load_gdt(&gdtp);
}
