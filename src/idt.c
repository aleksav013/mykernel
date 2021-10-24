#include"types.h"

#define INTERRUPT_GATE_32 0x8e

#define KERNEL_CODE 0x08
#define KERNEL_DATA 0x10

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1

struct idt_entry
{
    uint16_t offset1;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset2;
} __attribute__((packed));

struct idt_pointer
{
    uint16_t size;
    uint32_t offset;
} __attribute__((packed));

// asm function
extern void load_idt(struct idt_pointer *idtp);
extern void keyboard_handler();
extern void ioport_out(uint8_t port, char data);

struct idt_entry idt[256];
struct idt_pointer idtp;

void init_idt_entry(size_t num, uint32_t offset, uint16_t selector, uint8_t type_attr)
{
    idt[num].offset1=(offset & 0xffff);
    idt[num].selector=selector;
    idt[num].zero=0;
    idt[num].type_attr=type_attr;
    idt[num].offset2=(offset & 0xffff0000)>>16;
}

void init_idt_table()
{
    // Program the PICs - Programmable Interrupt Controllers
    // Background:
	// In modern architectures, the PIC is not a separate chip.
	// It is emulated in the CPU for backwards compatability.
	// The APIC (Advanced Programmable Interrupt Controller)
	// is the new version of the PIC that is integrated into the CPU.
	// Default vector offset for PIC is 8
	// This maps IRQ0 to interrupt 8, IRQ1 to interrupt 9, etc.
	// This is a problem. The CPU reserves the first 32 interrupts for
	// CPU exceptions such as divide by 0, etc.
	// In programming the PICs, we move this offset to 0x2 (32) so that
	// we can handle all interrupts coming to the PICs without overlapping
	// with any CPU exceptions.

    // Send ICWs - Initialization Command Words
    // PIC1: IO Port 0x20 (command), 0xA0 (data)
    // PIC2: IO Port 0x21 (command), 0xA1 (data)
    // ICW1: Initialization command
    // Send a fixed value of 0x11 to each PIC to tell it to expect ICW2-4
    // Restart PIC1
    ioport_out(PIC1_COMMAND_PORT, 0x11);
    ioport_out(PIC2_COMMAND_PORT, 0x11);
    // ICW2: Vector Offset (this is what we are fixing)
    // Start PIC1 at 32 (0x20 in hex) (IRQ0=0x20, ..., IRQ7=0x27)
    // Start PIC2 right after, at 40 (0x28 in hex)
    ioport_out(PIC1_DATA_PORT, 0x20);
    ioport_out(PIC2_DATA_PORT, 0x28);
    // ICW3: Cascading (how master/slave PICs are wired/daisy chained)
    // Tell PIC1 there is a slave PIC at IRQ2 (why 4? don't ask me - https://wiki.osdev.org/8259_PIC)
    // Tell PIC2 "its cascade identity" - again, I'm shaky on this concept. More resources in notes
    ioport_out(PIC1_DATA_PORT, 0x0);
    ioport_out(PIC2_DATA_PORT, 0x0);
    // ICW4: "Gives additional information about the environemnt"
    // See notes for some potential values
    // We are using 8086/8088 (MCS-80/85) mode
    // Not sure if that's relevant, but there it is.
    // Other modes appear to be special slave/master configurations (see wiki)
    ioport_out(PIC1_DATA_PORT, 0x1);
    ioport_out(PIC2_DATA_PORT, 0x1);
    // Voila! PICs are initialized

    // Mask all interrupts (why? not entirely sure)
    // 0xff is 16 bits that are all 1.
    // This masks each of the 16 interrupts for that PIC.
    ioport_out(PIC1_DATA_PORT, 0xff);
    ioport_out(PIC2_DATA_PORT, 0xff);

    init_idt_entry(0x21,(uint32_t)keyboard_handler,KERNEL_CODE,INTERRUPT_GATE_32);

    idtp.size=sizeof(struct idt_entry)*256-1;
    idtp.offset=(uint32_t)&idt;


    load_idt(&idtp);
}
