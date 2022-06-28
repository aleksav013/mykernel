.text

.global loadPageDirectory
loadPageDirectory:
    push %ebp
    movl %esp, %ebp
    movl 8(%esp), %eax
    subl $0xC0000000, %eax
    movl %eax, %cr3
    mov %ebp, %esp
    pop %ebp
    ret

.global enablePaging
enablePaging:
    push %ebp
    mov %esp, %ebp
    mov %cr0, %eax
    or $0x80000000, %eax
    mov %eax, %cr0
    mov %ebp, %esp
    pop %ebp
    ret

.global flushPaging
flushPaging:
    push %ebp
    mov %esp, %ebp
	movl %cr3, %ecx
	movl %ecx, %cr3
    mov %ebp, %esp
    pop %ebp
    ret
