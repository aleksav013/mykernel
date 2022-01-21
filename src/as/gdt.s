.global load_gdt

load_gdt:
    movl 4(%esp), %edx
    lgdt (%edx)
    ret
