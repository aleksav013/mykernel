#include<source/keyboard.h>
#include<types.h>
#include<asm.h>
#include<source/stdio.h>
#include<source/keymap.h>
#include<source/vga.h>
#include<source/tty.h>

char buffer[BUFFER_LOG][BUFFER_SIZE];
size_t buffer_size[BUFFER_LOG];
size_t buffer_current=0;
size_t buffer_all=0;
size_t buffer_index=0;

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

void keyboard_handler()
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    uint8_t status = ioport_in(KEYBOARD_STATUS_PORT);

    if (status & 0x1)
    {
        uint8_t keycode = ioport_in(KEYBOARD_DATA_PORT);
        if(keycode<0x80)
        {
            char c=charcode[keycode];
            ispressed[keycode]=1;
            // printf("%d ",&keycode);

            switch(keycode)
            {
                case 0x0E:
                    backspace();
                    break;
                case 0x1C:
                    enter();
                    break;
                case 0x39:
                    space();
                    break;
                case 72:
                    keyup();
                    break;
                case 80:
                    keydown();
                    break;
                case 75:
                    keyleft();
                    break;
                case 77:
                    keyright();
                    break;

                default:
                    if(c!=' ')
                    {
                        if(ispressed[lctrl]||ispressed[rctrl])
                        {
                            if(c=='l')
                            {
                                clear();
                                prompt();
                                printf("%s",buffer[buffer_current]);
                                return;
                            }
                        }
                        if(ispressed[lshift]||ispressed[rshift])
                        {
                            c=shift_charcode[keycode];
                        }
                        buffer[buffer_current][buffer_index++]=c;
                        printf("%c",c);
                    }
                    break;
            }

        }
        else
        {
            ispressed[keycode-0x80]=0;
        }
    }
}
