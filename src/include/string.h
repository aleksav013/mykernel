#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

void* memcpy(void*, const void*, size_t);
void* memset(void*, int, size_t);
char* strcpy(char*, const char*);
size_t strlen(const char*);

#endif
