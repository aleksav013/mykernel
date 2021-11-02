#ifndef HEAP_H
#define HEAP_H

#include<types.h>

void kheapinit();
int kheapaddblock(uintptr_t addr,uint32_t size,uint32_t bsize);
void *kmalloc(uint32_t size);
void kfree(void *ptr);

#endif
