#ifndef __ARCH_X86_KERNEL_H
# define __ARCH_X86_KERNEL_H

struct arch_kernel_args {
	int apic;
	int pic_at;
};

#define ARCH_MAX_PHYS_RANGES 16
#define ARCH_MAX_CPUS 16
#define PAGE_SIZE 4096

#endif /* __ARCH_X86_KERNEL_H */

