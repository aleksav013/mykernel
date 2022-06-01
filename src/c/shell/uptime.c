#include<source/shell/uptime.h>
#include<source/stdio.h>
#include<types.h>

extern uint32_t time;

void uptime(void)
{
    printf("System uptime is: %d seconds\n",time);
}
