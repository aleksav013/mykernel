#include<source/kernel.h>
#include<source/paging.h>
#include<source/idt.h>
#include<source/timer.h>
#include<source/keyboard.h>
#include<source/heap.h>
#include<source/vga.h>
#include<source/tty.h>


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
