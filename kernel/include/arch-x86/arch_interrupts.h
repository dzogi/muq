#ifndef __ARCH_X86_INTERRUPTS_H
# define __ARCH_X86_INTERRUPTS_H

#define ARCH_NUM_INT_VECTORS 16

inline void cli(void);
inline void sti(void);

int arch_int_init(void);
int arch_int_enable_vector(int num);
int arch_int_disable_vector(int num);

#endif /* __ARCH_X86_INTERRUPTS_H */

