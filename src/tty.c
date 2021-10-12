#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
bool stringcmp(char *str1,char *str2);
size_t pieces(char pieces[][15],char *buffer);
void clear();
void terminal_writestring(const char* data);
void terminal_putchar(char c);

void echo(size_t numberof,char parts[][15])
{
    for(size_t i=1;i<numberof;i++)
    {
	terminal_writestring(parts[i]);
	terminal_putchar(' ');
    }
    terminal_putchar('\n');
}

void tty(char *buffer)
{
    char parts[15][15];
    size_t numberof=pieces(parts,buffer);
    if(stringcmp(parts[0],"clear")) clear();
    else if(stringcmp(parts[0],"echo")) echo(numberof,parts);
    else
    {
	terminal_writestring("command not found: ");
	terminal_writestring(parts[0]);
	terminal_putchar('\n');
    }
}
