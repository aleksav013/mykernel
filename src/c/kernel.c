#include<stdio.h>
#include<heap.h>

void terminal_initialize(void);
void init_idt_table(void);
void init_keyboard(void);
void init_timer(uint32_t frequency);
void prompt(void);
void set_paging();

void kernel_main(void)
{
    set_paging();
    init_idt_table();
    init_timer(50);
    init_keyboard();
    kheapinit();
    kheapaddblock(0x00200000, 0x00100000, 16);

    terminal_initialize();
    prompt();

    while(1) __asm__("hlt\n\t");
}
