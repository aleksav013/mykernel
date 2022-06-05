.global cpuid_vendor

cpuid_vendor:
    pushl %ebp
    mov %esp, %ebp
    pushl %edi
    pushl %esi
    pushl %ebx

    mov $0x0, %eax
    cpuid

    movl 8(%ebp), %eax

    movl %ebx, (%eax)
    movl %edx, 4(%eax)
    movl %ecx, 8(%eax)

    popl %ebx
    popl %esi
    popl %edi
    popl %ebp
    ret
