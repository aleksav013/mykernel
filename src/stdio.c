#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdarg.h>
#include"string.h"

void terminal_putchar(char c);
void terminal_writestring(const char* data);
void terminal_writeint(const uint32_t data);

void printf(char *str, ...)
{
    size_t count=0;
    for(size_t i=0;str[i]!='\0';i++) if(str[i]=='%') count++;

    va_list list;
    va_start(list, str);

    for(size_t i=0;str[i]!='\0';i++)
    {
	if(str[i]=='%')
	{
	    i++;
	    if(str[i]=='c') terminal_putchar(va_arg(list,int));
	    else if(str[i]=='s') terminal_writestring(va_arg(list,char*));
	    else if(str[i]=='d') terminal_writeint(va_arg(list,int));
	    else
	    {
		terminal_writestring("wrong format using print function\n");
		return;
	    }
	}
	else terminal_putchar(str[i]);
    }

    va_end(list);
}
