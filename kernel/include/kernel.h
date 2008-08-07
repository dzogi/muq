#ifndef __KERNEL_H
# define __KERNEL_H

#include <arch/kernel.h>

extern u32_t _kstart;
extern u32_t _kend;

struct kernel_args {
	unsigned int num_cpus;
	unsigned int num_phys_ranges;
	addr_t phys_ranges[ARCH_MAX_PHYS_RANGES];
	struct arch_kernel_args arch_args;
};

#endif /* __KERNEL_H */
