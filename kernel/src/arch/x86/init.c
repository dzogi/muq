#include <multiboot.h>
#include <kernel.h>

extern void kernel_main(struct multiboot_info *info);

struct kernel_args args;

void
arch_init(struct multiboot_info *info)
{
	kernel_main(info);
}

