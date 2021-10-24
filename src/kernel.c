#include"heap.h"
#include"stdio.h"

void terminal_initialize(void);
void init_idt_table(void);
void init_keyboard(void);
void prompt(void);

void *f();

void kernel_main(void)
{
    terminal_initialize();
    init_idt_table();
    init_keyboard();
    k_heapBMInit(&kheap);

    prompt();
    while(1) __asm__("hlt\n\t");
}
