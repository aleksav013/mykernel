#include<source/timer.h>
#include<types.h>
#include<asm.h>
#include<source/stdio.h>
#include<source/tty.h>
#include<source/shell/game.h>

uint32_t tick=0;
extern uint32_t time;
uint32_t time=0;

extern uint8_t process_id;

void timer_handler(void)
{
    tick++;
    if(tick==TICKS_PER_SECOND)
    {
        tick=0;
        time++;
    }

    ioport_out(0x20, 0x20);
    ioport_out(0xa0, 0x20);

    if (process_id == PROCESS_GAME_ID) game_timer_handler();
}

void init_timer(uint32_t frequency)
{
    uint32_t divisor = 1193180 / frequency;
    ioport_out(0x43, 0x36);

    uint8_t l = (uint8_t)(divisor & 0xFF);
    uint8_t h = (uint8_t)( (divisor>>8) & 0xFF );

    ioport_out(0x40, l);
    ioport_out(0x40, h);
}
