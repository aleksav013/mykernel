#include"../include/types.h"

extern void loadPageDirectory(uint32_t*);
extern void enablePaging();

uint32_t page_directory[1024] __attribute__((aligned(4096)));

void set_pd()
{
    //set each entry to not present
    for(size_t i=0;i<1024;i++)
    {
	// This sets the following flags to the pages:
	//   Supervisor: Only kernel-mode can access them
	//   Write Enabled: It can be both read from and written to
	//   Not Present: The page table is not present
	page_directory[i] = 0x00000002;
    }
}

uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void set_pt()
{
    // holds the physical address where we want to start mapping these pages to.
    // in this case, we want to map these pages to the very beginning of memory.
    unsigned int i;
     
    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for(i = 0; i < 1024; i++)
    {
	// As the address is page aligned, it will always leave 12 bits zeroed.
	// Those bits are used by the attributes ;)
	first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }
}

void put_pt()
{
    // attributes: supervisor level, read/write, present
    page_directory[0] = ((uint32_t)first_page_table) | 3;
}

void set_paging()
{
    set_pd();
    set_pt();
    put_pt();
    loadPageDirectory(page_directory);
    enablePaging();
}
