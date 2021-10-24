#ifndef STRING_H
#define STRING_H

#include"types.h"

size_t stringlen(char *str);
bool stringcmp(char *str1,char *str2);
void stringcat(char *str1,char *str2);
void stringrev(char *str);
void itos(uint32_t num,char *str);
uint32_t stoi(const char *str);
double stof(const char *str);
void ftos(double num, char *str);

#endif
