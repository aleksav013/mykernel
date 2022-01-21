#ifndef SOURCE_KEYBOARD_H
#define SOURCE_KEYBOARD_H

#define BUFFER_SIZE 200
#define BUFFER_LOG 200

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void init_keyboard(void);
void deletelast(void);
void backspace(void);
void enter(void);
void space(void);
void keyup(void);
void keydown(void);
void keyleft(void);
void keyright(void);
void keyboard_handler(void);

#endif
