#include<types.h>
#include<asm.h>
#include<stdio.h>

#define BUFFER_SIZE 200
#define BUFFER_LOG 200
char buffer[BUFFER_LOG][BUFFER_SIZE];
size_t buffer_size[BUFFER_LOG];
size_t buffer_current=0;
size_t buffer_all=0;
size_t buffer_index=0;

#define PIC1_COMMAND_PORT 0x20
#define PIC1_DATA_PORT 0x21
#define PIC2_COMMAND_PORT 0xA0
#define PIC2_DATA_PORT 0xA1
// IO Ports for Keyboard
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void previous_field(void);
void tty(char *buffer);
void prompt(void);
void clear();
void us_en(char keymap[]);
void us_en_shift(char keymap[]);

char charcode[256];
char shift_charcode[256];
bool ispressed[128];

void init_keyboard()
{
    us_en(charcode);
    us_en_shift(shift_charcode);
}

void deletelast()
{
    previous_field();
    printf(" ");
    previous_field();
}

void backspace()
{
    if(buffer_index<=0) return;

    deletelast();
    buffer[buffer_current][--buffer_index]='\0';
    return;
}

void enter()
{
    printf("\n");
    if(buffer_index>0)
    {
	tty(buffer[buffer_current]);
	buffer_size[buffer_current]=buffer_index;
	if(buffer_current==buffer_all) buffer_current=(++buffer_all);
	else
	{
	    for(size_t i=0;i<BUFFER_SIZE;i++) buffer[buffer_all][i]='\0';
	    buffer_current=buffer_all;
	}
	buffer_index=0;
    }
    prompt();
    return;
}

void space()
{
    buffer[buffer_current][buffer_index++]=' ';
    printf(" ");
}

void keyup()
{
    if(buffer_current>0)
    {
	buffer_size[buffer_current]=buffer_index;
	for(size_t i=0;i<buffer_index;i++) deletelast();
	buffer_current--;
	buffer_index=buffer_size[buffer_current];
	printf("%s",buffer[buffer_current]);
    }
}
void keydown()
{
    if(buffer_current<buffer_all)
    {
	buffer_size[buffer_current]=buffer_index;
	for(size_t i=0;i<buffer_index;i++) deletelast();
	buffer_current++;
	buffer_index=buffer_size[buffer_current];
	printf("%s",buffer[buffer_current]);
    }
}
void keyleft()
{

}
void keyright()
{

}

#define lshift ispressed[0x2A]
#define rshift ispressed[0x36]
#define lctrl ispressed[0x1D]

void keyboard_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    uint8_t status = ioport_in(KEYBOARD_STATUS_PORT);

    if (status & 0x1)
    {
	uint8_t keycode = ioport_in(KEYBOARD_DATA_PORT);
//	printf("%d\n",keycode);
	if(keycode<0x80)
	{
	    ispressed[keycode]=1;
	    if(keycode==0x0E) backspace();
	    else if(keycode==0x1C) enter();
	    else if(keycode==0x39) space();
	    else if(keycode==72) keyup();
	    else if(keycode==80) keydown();
	    else if(keycode==75) keyleft();
	    else if(keycode==77) keyright();
	    else
	    {
		char c=charcode[keycode];
		if(c!=' ')
		{
		    if(lctrl)
		    {
			if(c=='l')
			{
			    clear();
			    prompt();
			    printf("%s",buffer[buffer_current]);
			    return;
			}
		    }
		    if(lshift||rshift)
		    {
			c=shift_charcode[keycode];
		    }
		    buffer[buffer_current][buffer_index++]=c;
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
