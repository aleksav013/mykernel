#include<source/shell/game.h>
#include<types.h>
#include<source/vga.h>
#include<source/tty.h>
#include<source/timer.h>
#include<source/stdio.h>

extern uint16_t* terminal_buffer;
extern uint8_t terminal_color;
extern uint8_t process_id;

#define N 1000

uint16_t x;
uint16_t y;
uint16_t rep[N];

uint32_t game_time;
uint32_t game_tick;
uint8_t gameover;
uint8_t duzina;
uint8_t smer;

uint16_t jabuka;
uint16_t x_jabuke;
uint16_t y_jabuke;

void game_keyboard_handler(uint16_t keycode)
{
    switch(keycode)
    {
    //  space();
        case 0x39:
            process_id = PROCESS_TTY_ID;
            clear();
            prompt();
            break;
    //  keyup();
        case 72:
            smer = 1;
            break;
    //  keydown();
        case 80:
            smer = 2;
            break;
    //  keyleft();
        case 75:
            smer = 3;
            break;
    //  keyright();
        case 77:
            smer = 4;
            break;
    }
}

void game_init(void)
{
    x=VGA_WIDTH/2;
    y=VGA_HEIGHT/2;
    game_time=0;
    game_tick=0;
    duzina=1;
    gameover=0;
    smer=0;

    x_jabuke=5;
    y_jabuke=5;

    process_id = PROCESS_GAME_ID;
    clear();
}

void game_timer_handler()
{
    game_tick++;
    if (game_tick == TICKS_PER_SECOND/8 && !gameover)
    {
        switch(smer)
        {
            case 1:
                if(y>0) y--;
                else y=VGA_HEIGHT-1;
                break;
            case 2:
                if(y<VGA_HEIGHT-1) y++;
                else y=0;
                break;
            case 3:
                if(x>0) x--;
                else x=VGA_WIDTH-1;
                break;
            case 4:
                if(x<VGA_WIDTH-1) x++;
                else x=0;
                break;
            default:
                break;
        }
        game_tick=0;
        game_time+=1;

        for(uint8_t i = duzina; i > 0; i--) rep[i]=rep[i-1];
        rep[0]=(uint16_t)(y*80+x);

        if (rep[0] == y_jabuke*80+x_jabuke)
        {
            duzina++;

            uint8_t ind;
            do {
                ind = 1;
                x_jabuke = (uint16_t)((game_time*game_time)%80);
                y_jabuke = (uint16_t)((game_time*game_time)%25);
                jabuka = (uint16_t)(y_jabuke*80+x_jabuke);
                for(uint8_t i = 0; i < duzina; i++) if(rep[i] == jabuka) ind=0;
                game_time++;
            } while(!ind);

            terminal_buffer[jabuka]=(uint16_t)(terminal_color<<8|'J');
        }
        terminal_buffer[rep[duzina]]=(uint16_t)(terminal_color<<8|' ');
        terminal_buffer[rep[0]]=(uint16_t)(terminal_color<<8|'#');

        set_color(VGA_COLOR_RED,VGA_COLOR_BLACK);
        terminal_buffer[y_jabuke*80+x_jabuke]=(uint16_t)(terminal_color<<8|'J');
        set_color(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK);

        for(uint8_t i = 1; i < duzina; i++) if(rep[0] == rep[i])
        {
            printf("GAME OVER\nPress <Space> to return to shell\n");
            gameover=1;
        }
    }
}
