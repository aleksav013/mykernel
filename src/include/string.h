#ifndef _STRING_H
#define _STRING_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
void* memcpy(void*, const void*, size_t);
void* memset(void*, int, size_t);
char* strcpy(char*, const char*);
size_t strlen(const char*);
#ifdef __cplusplus
}
#endif

#include<types.h>

size_t stringlen(char *str);
bool stringcmp(char *str1,char *str2);
void stringcat(char *str1,char *str2);
void stringrev(char *str);
void itos(uint32_t num,char *str);
uint32_t stoi(const char *str);
double stof(const char *str);
void ftos(double num, char *str);

#endif
