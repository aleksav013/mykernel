#ifndef SOURCE_STRING_H
#define SOURCE_STRING_H

#include<types.h>

size_t stringlen(char* str);
bool stringcmp(const char* str1, const char* str2);
void stringcat(char* str1, const char* str2);
void stringcpy(char* str1, const char* str2);
void stringrev(char* str);

void itos(uint32_t num, char *str);
uint32_t stoi(const char* str);
double stof(const char* str);
void ftos(double num, char* str);

#endif
