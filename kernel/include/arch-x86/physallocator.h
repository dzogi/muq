#ifndef __ARCH_X86_PHYSALLOCATOR_H
# define __ARCH_X86_PHYSALLOCATOR_H

int ph_init(int mem_available);
struct page ph_get_page_low(void);
struct page ph_get_page(void);
void ph_free_page(struct page p);

#endif /* __ARCH_X86_PHYSALLOCATOR_H */

