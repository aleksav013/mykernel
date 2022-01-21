.global ioport_in
.global ioport_out

ioport_in:
    movl 4(%esp),%edx
    in %dx,%al
    ret

ioport_out:
    movl 4(%esp),%edx
    movl 8(%esp),%eax
    outb %al,%dx
    ret
