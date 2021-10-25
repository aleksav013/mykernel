.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15
.global irq16
.global irq17
.global irq18
.global irq19
.global irq20
.global irq21
.global irq22
.global irq23
.global irq24
.global irq25
.global irq26
.global irq27
.global irq28
.global irq29
.global irq30
.global irq31
.global timer_irq
.global keyboard_irq


irq0:
    pushal
    cld
    call irq0_handler
    popal
    iretl

irq1:
    pushal
    cld
    call irq1_handler
    popal
    iretl

irq2:
    pushal
    cld
    call irq2_handler
    popal
    iretl

irq3:
    pushal
    cld
    call irq3_handler
    popal
    iretl

irq4:
    pushal
    cld
    call irq4_handler
    popal
    iretl

irq5:
    pushal
    cld
    call irq5_handler
    popal
    iretl

irq6:
    pushal
    cld
    call irq6_handler
    popal
    iretl

irq7:
    pushal
    cld
    call irq7_handler
    popal
    iretl

irq8:
    pushal
    cld
    call irq8_handler
    popal
    iretl

irq9:
    pushal
    cld
    call irq9_handler
    popal
    iretl

irq10:
    pushal
    cld
    call irq10_handler
    popal
    iretl

irq11:
    pushal
    cld
    call irq11_handler
    popal
    iretl

irq12:
    pushal
    cld
    call irq12_handler
    popal
    iretl

irq13:
    pushal
    cld
    call irq13_handler
    popal
    iretl

irq14:
    pushal
    cld
    call irq14_handler
    popal
    iretl

irq15:
    pushal
    cld
    call irq15_handler
    popal
    iretl

irq16:
    pushal
    cld
    call irq16_handler
    popal
    iretl

irq17:
    pushal
    cld
    call irq17_handler
    popal
    iretl

irq18:
    pushal
    cld
    call irq18_handler
    popal
    iretl

irq19:
    pushal
    cld
    call irq19_handler
    popal
    iretl

irq20:
    pushal
    cld
    call irq20_handler
    popal
    iretl

irq21:
    pushal
    cld
    call irq21_handler
    popal
    iretl

irq22:
    pushal
    cld
    call irq22_handler
    popal
    iretl

irq23:
    pushal
    cld
    call irq23_handler
    popal
    iretl

irq24:
    pushal
    cld
    call irq24_handler
    popal
    iretl

irq25:
    pushal
    cld
    call irq25_handler
    popal
    iretl

irq26:
    pushal
    cld
    call irq26_handler
    popal
    iretl

irq27:
    pushal
    cld
    call irq27_handler
    popal
    iretl

irq28:
    pushal
    cld
    call irq28_handler
    popal
    iretl

irq29:
    pushal
    cld
    call irq29_handler
    popal
    iretl

irq30:
    pushal
    cld
    call irq30_handler
    popal
    iretl

irq31:
    pushal
    cld
    call irq31_handler
    popal
    iretl

timer_irq:
    pushal
    cld
    call timer_handler
    popal
    iretl

keyboard_irq:
    pushal
    cld
    call keyboard_handler
    popal
    iretl
