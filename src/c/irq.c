#include"../include/stdio.h"
#include"../include/asm.h"

#define INTERRUPT_GATE_32 0x8e

#define KERNEL_CODE 0x08
#define KERNEL_DATA 0x10

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1

void irq0_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 0.\n");
}

void irq1_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 1.\n");
}

void irq2_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 2.\n");
}

void irq3_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 3.\n");
}

void irq4_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 4.\n");
}

void irq5_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 5.\n");
}

void irq6_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 6.\n");
}

void irq7_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 7.\n");
}

void irq8_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 8.\n");
}

void irq9_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 9.\n");
}

void irq10_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 10.\n");
}

void irq11_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 11.\n");
}

void irq12_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 12.\n");
}

void irq13_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 13.\n");
}

void irq14_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 14.\n");
}

void irq15_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 15.\n");
}

void irq16_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 16.\n");
}

void irq17_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 17.\n");
}

void irq18_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 18.\n");
}

void irq19_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 19.\n");
}

void irq20_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 20.\n");
}

void irq21_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 21.\n");
}

void irq22_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 22.\n");
}

void irq23_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 23.\n");
}

void irq24_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 24.\n");
}

void irq25_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 25.\n");
}

void irq26_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 26.\n");
}

void irq27_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 27.\n");
}

void irq28_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 28.\n");
}

void irq29_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 29.\n");
}

void irq30_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 30.\n");
}

void irq31_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 31.\n");
}
