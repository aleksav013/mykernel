#include<source/paging.h>
#include<types.h>

extern void loadPageDirectory(uint32_t*);
extern void enablePaging(void);

uint32_t page_directory[1024] __attribute__((aligned(4096)));

void set_pd(void)
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

uint32_t page_table[1024][1024] __attribute__((aligned(4096)));

void set_pt(size_t num,uint32_t address)
{
    // holds the physical address where we want to start mapping these pages
    // to.
    // in this case, we want to map these pages to the very beginning of
    // memory.

    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for(size_t i=0;i<1024;i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        page_table[num][i] = (address + i * 0x1000) | 3;
        // attributes: supervisor level, read/write, present.
    }

    page_directory[num] = ((uint32_t)page_table[num]) | 3;
    // attributes: supervisor level, read/write, present
}

void set_paging(void)
{
    set_pd();
    for(size_t i=0;i<1024;i++) set_pt(i,0x00400000 * i); // all 4GB mapped
    loadPageDirectory(page_directory);
    enablePaging();
}
