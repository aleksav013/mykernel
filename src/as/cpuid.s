.global cpuid_vendor

cpuid_vendor:
    pushl %ebp
    mov %esp, %ebp
    pushl %ebx
    pushl %edi
    pushl %esi

    mov $0x0, %eax
    cpuid

    movl 8(%ebp), %eax

    movl %ebx, (%eax)
    movl %edx, 4(%eax)
    movl %ecx, 8(%eax)

    popl %esi
    popl %edi
    popl %ebx
    popl %ebp
    ret
