#include <arch/physallocator.h>

#include <multiboot.h>
#include <string.h>

int mm_init(struct multiboot_info *info)
{
	while(1) {
		if(!ph_init((info->mem_upper+1024)*1024))
			puts("\n* Physical allocator initialized\n");
	}
	
	return 0;
}

