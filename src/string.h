#ifndef STRING_H
#define STRING_H

#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>

size_t stringlen(char *str);
bool stringcmp(char *str1,char *str2);
void stringcat(char *str1,char *str2);
void stringrev(char *str);
void itos(char *str,uint32_t num);
uint32_t stoi(char *str);

#endif
