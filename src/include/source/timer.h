#ifndef SOURCE_TIMER_H
#define SOURCE_TIMER_H

#define TICKS_PER_SECOND 50

#include<types.h>

void timer_handler(void);
void init_timer(uint32_t frequency);

#endif
