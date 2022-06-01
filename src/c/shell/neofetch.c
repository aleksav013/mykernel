#include<source/shell/neofetch.h>
#include<source/shell/uptime.h>
#include<source/vga.h>
#include<source/stdio.h>
#include<source/timer.h>

void neofetch(void)
{
    set_color(VGA_COLOR_WHITE,VGA_COLOR_BLACK);
    printf("      .                ");         printf("Dobrodosli u moj     \n");
    printf("     J:L    (\"\"\")      ");      printf("operativni sistem :) \n");
    printf("     |:|     III       ");         printf("Uzivajte!            \n");
    printf("     |:|     III       ");         printf("                     \n");
    printf("     |:|     III       ");         printf("Welcome to my        \n");
    printf("     |:|   __III__     ");         printf("operating system :)  \n");
    printf("     |:| /:-.___,-:\\   ");        printf("Enjoy your stay!     \n");
    printf("     |:| \\]  |:|  [/   ");        printf("                     \n");
    printf("     |:|     |:|       ");         printf("                     \n");
    printf("     |:|     |:|       ");         printf("                     \n");
    printf("     |:|     |:|       ");         printf("                     \n");
    printf(" /]  |:|  [\\ |:|       ");        printf("                     \n");
    printf(" \\:-'\"\"\"`-:/ |:|       ");     printf("                     \n");
    printf("   \"\"III\"\"   |:|       ");     printf("                     \n");
    printf("     III     |:|       ");         printf("                     \n");
    printf("     III     |:|       ");         printf("                     \n");
    printf("     III     |:|       ");         printf("napravio/made by:    \n");
    printf("    (___)    J:F       ");         printf("Aleksa Vuckovic      \n");
    printf("              \"        ");        printf("                     \n");

    for(size_t i=0;i<16;i++)
    {
        set_color(0,i);
        printf("  ",i);
    }
    printf("\n");


    set_color(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK);
    uptime();
}
