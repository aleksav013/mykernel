#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include"keyboard.h"
#include"stdio.h"

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

extern char ioport_in(uint8_t port);
extern void ioport_out(uint8_t port, char data);

void previous_field(void);
void terminal_putchar(char c);
void tty(char *buffer);
void prompt(void);

void init_keyboard()
{
    // 0xFD = 1111 1101 in binary. enables only IRQ1
    // Why IRQ1? Remember, IRQ0 exists, it's 0-based
    ioport_out(PIC1_DATA_PORT, 0xFD);
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

void handle_keyboard_interrupt()
{
    // Write end of interrupt (EOI)
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    unsigned char status = ioport_in(KEYBOARD_STATUS_PORT);

    // Lowest bit of status will be set if buffer not empty
    if (status & 0x1)
    {
	int16_t keycode = ioport_in(KEYBOARD_DATA_PORT);
	if (keycode < 0 || keycode >= 128) return;

	if(keycode==14) backspace();
	else if(keycode==28) enter();
	else
	{
	    buffer[buffer_index++]=keyboard[keycode];
	    printf("%c",keyboard[keycode]);
	}

    }
}
