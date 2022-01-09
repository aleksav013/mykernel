#include<types.h>
#include<asm.h>
#include<stdio.h>

void add_idt_entry(size_t num,uint32_t offset);

uint32_t tick=0;
const uint32_t TICKS_PER_SECOND=50;
extern uint32_t time;
uint32_t time=0;

void timer_handler()
{
    tick++;
    if(tick==TICKS_PER_SECOND)
    {
        //printf("%d seconds passed\n",time);
        tick=0;
        time++;
    }

    ioport_out(0x20, 0x20);
    ioport_out(0xa0,0x20);
}

void init_timer(uint32_t frequency)
{
    // Firstly, register our timer callback.

    // The value we send to the PIT is the value to divide it's input clock
    // (1193180 Hz) by, to get our required frequency. Important to note is
    // that the divisor must be small enough to fit into 16-bits.
    uint32_t divisor = 1193180 / frequency;

    // Send the command byte.
    ioport_out(0x43, 0x36);

    // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
    uint8_t l = (uint8_t)(divisor & 0xFF);
    uint8_t h = (uint8_t)( (divisor>>8) & 0xFF );

    // Send the frequency divisor.
    ioport_out(0x40, l);
    ioport_out(0x40, h);
}
