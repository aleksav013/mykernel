#ifndef SOURCE_PAGING_H
#define SOURCE_PAGING_H

#include<types.h>

void set_pd(void);
void set_pt(size_t num, uint32_t address);
void set_paging(void);

#endif
