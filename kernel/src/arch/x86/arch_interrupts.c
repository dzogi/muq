#include <interrupts.h>

inline void cli(void)
{
	__asm__ __volatile__("cli");
}

inline void sti(void)
{
	__asm__ __volatile__("sti");
}

static inline void x86_int_ack(void) {
	
}

int arch_int_init(void)
{
	return 0;
}


int arch_int_enable_vector(int num)
{
	return 0;
}

int arch_int_disable_vector(int num)
{
	return 0;
}

