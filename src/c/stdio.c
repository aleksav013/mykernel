#include<types.h>
#include<string.h>
#include<stdarg.h>

void terminal_putchar(char c);
void terminal_writestring(char* data);
void terminal_writeint(uint32_t data);
void terminal_writefloat(double num);

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
	    if(str[i]=='c') terminal_putchar((char)va_arg(list,int));
	    else if(str[i]=='s') terminal_writestring(va_arg(list,char*));
	    else if(str[i]=='d') terminal_writeint(va_arg(list,int));
	    else if(str[i]=='f') terminal_writefloat(va_arg(list,double));
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
