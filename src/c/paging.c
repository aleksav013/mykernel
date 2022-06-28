#include<source/paging.h>
#include<types.h>

extern void loadPageDirectory(uint32_t*);
extern void enablePaging(void);
extern void flushPaging(void);

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
    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for(size_t i=0;i<1024;i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        page_table[num][i] = (address + i * 0x1000) | 3;
        // attributes: supervisor level, read/write, present.
    }

    page_directory[num] = ((uint32_t)page_table[num] - 0xC0000000) | 3;
    // attributes: supervisor level, read/write, present
}

void empty_pt(size_t num)
{
    for(size_t i=0;i<1024;i++)
    {
        page_table[num][i] = 0;
    }

    page_directory[num] = 0x00000002;
}

void set_paging(void)
{
    set_pd();
    set_pt(768,0x00000000); // maps 0x00000000 to 0xC0000000
    set_pt(769,0x00400000); // maps 0x00400000 to 0xC0400000
    set_pt(832,0x000B8000); // maps 0x000B8000 to 0xD0000000
    loadPageDirectory(page_directory);
    flushPaging();
}
