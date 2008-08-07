#include <string.h>
#include <mm.h>
#include <interrupts.h>
#include <multiboot.h>

#include <arch/video.h>

void __attribute__((noreturn))
kernel_main(struct multiboot_info *info)
{
	video_init();
	mm_init(info);
	int_init();
	
	puts("Welcome to muq");
	
	while(1) {
		
	}
}

