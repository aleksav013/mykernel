#include"../include/heap.h"

void terminal_initialize(void);
void init_idt_table(void);
void init_keyboard(void);
void init_timer(uint32_t frequency);
void prompt(void);
void set_paging();

void kernel_main(void)
{
    terminal_initialize();
    set_paging();
    init_idt_table();
    init_keyboard();
    init_timer(50);
    //k_heapBMInit(&kheap);
    //k_heapBMAddBlock(&kheap, 0x100000, 0x100000, 16);
    prompt();

    while(1) __asm__("hlt\n\t");
}
