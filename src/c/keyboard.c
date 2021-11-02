#include<types.h>
#include<asm.h>
#include<stdio.h>

#define BUFFER_SIZE 200
char buffer[BUFFER_SIZE];
size_t buffer_index=0;

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1
// IO Ports for Keyboard
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void previous_field(void);
void terminal_putchar(char c);
void tty(char *buffer);
void prompt(void);
void clear();
void us_en(char keymap[]);

char charcode[256];
bool ispressed[128];

void init_keyboard()
{
    us_en(charcode);
}

void backspace()
{
    if(buffer_index<=0) return;

    previous_field();
    printf(" ");
    previous_field();
    buffer[--buffer_index]='\0';
    return;
}

void enter()
{
    printf("\n");
    if(buffer_index>0)
    {
	tty(buffer);
	for(int i=0;i<BUFFER_SIZE;i++) buffer[i]='\0';
	buffer_index=0;
    }
    prompt();
    return;
}

void space()
{
    buffer[buffer_index++]=' ';
    printf(" ");
}
#define lshift ispressed[0x2A]
#define lctrl ispressed[0x1D]

void keyboard_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    uint8_t status = ioport_in(KEYBOARD_STATUS_PORT);

    if (status & 0x1)
    {
	uint8_t keycode = ioport_in(KEYBOARD_DATA_PORT);
	if(keycode<0x80)
	{
	    ispressed[keycode]=1;
	    if(keycode==0x0E) backspace();
	    else if(keycode==0x1C) enter();
	    else if(keycode==0x39) space();
	    else
	    {
		char c=charcode[keycode];
		if(c!=' ')
		{
		    if(lshift)
		    {
			if(c>='a'&&c<='z') c-=32;
		    }
		    if(lctrl)
		    {
			if(c=='l')
			{
			    clear();
			    prompt();
			    printf("%s",buffer);
			    return;
			}
		    }
		    buffer[buffer_index++]=c;
		    printf("%c",c);
		}
	    }
	}
	else
	{
	    ispressed[keycode-0x80]=0;
	}
    }
}
