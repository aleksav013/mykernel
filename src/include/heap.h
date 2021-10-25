#ifndef HEAP_H
#define HEAP_H

#include"types.h"

typedef struct _KHEAPBLOCKBM {
	struct _KHEAPBLOCKBM	                *next;
	uint32_t				size;
	uint32_t				used;
	uint32_t				bsize;
        uint32_t                                lfb;
} KHEAPBLOCKBM;

typedef struct _KHEAPBM {
	KHEAPBLOCKBM			*fblock;
} KHEAPBM;

void k_heapBMInit(KHEAPBM *heap);
int k_heapBMAddBlock(KHEAPBM *heap, uintptr_t addr, uint32_t size, uint32_t bsize);
void *k_heapBMAlloc(KHEAPBM *heap, uint32_t size);
void k_heapBMFree(KHEAPBM *heap, void *ptr);

extern KHEAPBM kheap;

#define kmalloc k_heapBMAlloc
#define kfree k_heapBMFree

#endif
