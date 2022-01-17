#include<source/irq_handler.h>
#include<source/stdio.h>
#include<asm.h>

#define INTERRUPT_GATE_32 0x8e

#define KERNEL_CODE 0x08
#define KERNEL_DATA 0x10

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1

void irq0_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 0.\n");
    printf("Divide-by-zero Error\n");
}

void irq1_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 1.\n");
    printf("Debug\n");
}

void irq2_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 2.\n");
    printf("Non-maskable Interrupt\n");
}

void irq3_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 3.\n");
    printf("Breakpoint\n");
}

void irq4_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 4.\n");
    printf("Overflow\n");
}

void irq5_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 5.\n");
    printf("Bound Range Exceeded\n");
}

void irq6_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 6.\n");
    printf("Invalid Opcode\n");
}

void irq7_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 7.\n");
    printf("Device Not Available\n");
}

void irq8_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 8.\n");
    printf("Double Fault\n");
}

void irq9_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 9.\n");
    printf("Coprocessor Segment Overrun\n");
}

void irq10_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 10.\n");
    printf("Invalid TSS\n");
}

void irq11_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 11.\n");
    printf("Segment Not Present\n");
}

void irq12_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 12.\n");
    printf("Stack-Segment Fault\n");
}

void irq13_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 13.\n");
    printf("General Protection Fault\n");
}

void irq14_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 14.\n");
    printf("Page Fault\n");
}

void irq15_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 15.\n");
    printf("Reserved\n");
}

void irq16_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 16.\n");
    printf("x87 Floating-Point Exception\n");
}

void irq17_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 17.\n");
    printf("Alignment Check\n");
}

void irq18_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 18.\n");
    printf("Machine Check\n");
}

void irq19_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 19.\n");
    printf("SIMD Floating-Point ExceptionM/#XF\n");
}

void irq20_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 20.\n");
    printf("Virtualization Exception\n");
}

void irq21_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 21.\n");
    printf("Reserved\n");
}

void irq22_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 22.\n");
    printf("Reserved\n");
}

void irq23_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 23.\n");
    printf("Reserved\n");
}

void irq24_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 24.\n");
    printf("Reserved\n");
}

void irq25_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 25.\n");
    printf("Reserved\n");
}

void irq26_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 26.\n");
    printf("Reserved\n");
}

void irq27_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 27.\n");
    printf("Reserved\n");
}

void irq28_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 28.\n");
    printf("Reserved\n");
}

void irq29_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 29.\n");
    printf("Reserved\n");
}

void irq30_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 30.\n");
    printf("Security Exception\n");
}

void irq31_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 31.\n");
    printf("Reserved\n");
}
