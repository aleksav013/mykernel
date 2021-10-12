void terminal_initialize(void);
void init_idt_table(void);
void init_keyboard(void);
void prompt(void);

void kernel_main(void)
{
    terminal_initialize();
    init_idt_table();
    init_keyboard();
    prompt();
    while(1) __asm__("hlt\n\t");
}
