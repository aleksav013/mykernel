#include<source/tty.h>
#include<types.h>
#include<source/string.h>
#include<source/stdio.h>
#include<source/vga.h>
#include<source/shell/uptime.h>
#include<source/shell/neofetch.h>
#include<source/shell/game.h>

size_t pieces(char pieces[][CMD_LENGTH],char *buffer)
{
    for(size_t x=0;x<CMD_LENGTH;x++) for(size_t y=0;y<CMD_LENGTH;y++)
        pieces[x][y]='\0';

    size_t i=0,j=0,r=0;
    while(buffer[i]==' '&&buffer[i]!='\0') i++;
    for(;buffer[i]!='\0';i++)
    {
        if(buffer[i]==' ')
        {
            while(buffer[i]==' '&&buffer[i]!='\0') i++;
            j=0;
            r++;
            i--;
        }
        else
        {
            pieces[r][j++]=buffer[i];
        }
    }
    return r+1;
}

void echo(size_t numberof,char parts[][CMD_LENGTH])
{
    for(size_t i=1;i<numberof;i++)
    {
        printf("%s ",parts[i]);
    }
    printf("\n");
}

void merge(char parts[][CMD_LENGTH])
{
    char *str1=parts[1];
    char *str2=parts[2];
    stringcat(str1,str2);
    printf("%s\n",str1);
}

void ls(void)
{
    printf("Filesystem not implemented yet\n");
}

void number(size_t numberof,char parts[][CMD_LENGTH])
{
    if(numberof==1) printf("Please enter a number\n");
    else
    {
        printf("Entered integer number is %d\n",stoi(parts[1]));
        printf("Entered float number is: %f\n",stof(parts[1]));
    }
}


void prompt(void)
{
    //printf("[aleksa@aleksa-os]$ ");
    set_color(VGA_COLOR_RED,VGA_COLOR_BLACK);
    printf("[");
    set_color(VGA_COLOR_YELLOW,VGA_COLOR_BLACK);
    printf("aleksa");
    set_color(VGA_COLOR_GREEN,VGA_COLOR_BLACK);
    printf("@");
    set_color(VGA_COLOR_BLUE,VGA_COLOR_BLACK);
    printf("aleksa-os");
    set_color(VGA_COLOR_RED,VGA_COLOR_BLACK);
    printf("]");
    set_color(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK);
    printf("$ ");
}

void help(void)
{
    printf("Currently available commands:\n");
    printf("clear echo game merge ls number uptime neofetch help\n");
}

extern uint8_t process_id;
extern uint16_t* terminal_buffer;

void tty(char *buffer)
{
    char parts[CMD_LENGTH][CMD_LENGTH];
    size_t numberof=pieces(parts,buffer);

    if(stringcmp(parts[0],"clear")) clear();
    else if(stringcmp(parts[0],"echo")) echo(numberof,parts);
    else if(stringcmp(parts[0],"merge")) merge(parts);
    else if(stringcmp(parts[0],"ls")) ls();
    else if(stringcmp(parts[0],"number")) number(numberof,parts);
    else if(stringcmp(parts[0],"uptime")) uptime();
    else if(stringcmp(parts[0],"neofetch")) neofetch();
    else if(stringcmp(parts[0],"help")) help();
    else if(stringcmp(parts[0],"game")) game_init();
    else printf("command not found: %s\n",parts[0]);

    if (!stringcmp(parts[0],"game")) prompt();
}
