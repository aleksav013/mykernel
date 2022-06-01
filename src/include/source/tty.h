#ifndef SOURCE_TTY_H
#define SOURCE_TTY_H

#include<types.h>

#define CMD_LENGTH 20

#define PROCESS_TTY_ID 1
#define PROCESS_GAME_ID 2

size_t pieces(char pieces[][CMD_LENGTH], char *buffer);
void echo(size_t numberof, char parts[][CMD_LENGTH]);
void merge(char parts[][CMD_LENGTH]);
void ls(void);
void number(size_t numberof, char parts[][CMD_LENGTH]);
void uptime(void);
void prompt(void);
void neofetch(void);
void help(void);
void game_init(void);
void tty(char *buffer);
void tty_keyboard_handler(uint16_t keycode);

#endif
