.global load_idt

load_idt:
    movl 4(%esp), %edx
    lidt (%edx)
    sti
    ret
