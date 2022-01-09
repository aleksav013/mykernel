.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.global _start
.global load_gdt
.global load_idt
.global enable_interrupts
.global ioport_in
.global ioport_out

load_gdt:
    movl 4(%esp), %edx
    lgdt (%edx)
    ret

load_idt:
    movl 4(%esp), %edx
    lidt (%edx)
    sti
    ret

ioport_in:
    movl 4(%esp),%edx
    in %dx,%al
    ret

ioport_out:
    movl 4(%esp),%edx
    movl 8(%esp),%eax
    outb %al,%dx
    ret

.set CODE_SEGMENT, 0x08
.set DATA_SEGMENT, 0x10

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.type _start, @function
_start:
    call init_gdt_table
    ljmp $CODE_SEGMENT, $code

code:
    movw $DATA_SEGMENT, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs
    movw %ax, %ss
    movl $stack_top, %esp
    cli
    call _init
    call kernel_main
    hlt

.size _start, . - _start
