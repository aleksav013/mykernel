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

load_gdt:
    movl 4(%esp), %edx
    lgdt (%edx)
    ret

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.type _start, @function
_start:
	call init_gdt_table
	mov 0x10, %ax
	mov %ds, %ax
	mov %es, %ax
	mov %fs, %ax
	mov %gs, %ax
	mov %ss, %ax
	mov $stack_top, %esp
	cli
	call _init
	call kernel_main
1:	hlt
	jmp 1b
 
.size _start, . - _start
