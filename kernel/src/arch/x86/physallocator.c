/**
 * Physical page allocator
 *
 * We keep two arrays (one for low DMA memory) with page elements just
 * after _kend
 */

#include <kernel.h>

#define PAGE_SIZE 4096
#define ROUND_TO_NEXT(addr) (((addr)+PAGE_SIZE-1) & (~0xFFF))
#define MEM_LOW 0x1000000 /* 16MB, DMA memory */
#define KERNEL_OFFSET 0xE0000000

struct page {
	struct page *next;
	u32_t addr;
};

static struct page *stack_low_head;
static struct page *stack_high_head;

int ph_init(int mem_available)
{
	unsigned int num, i, len_stacks;
	u32_t addr, end_at;
	static struct page *stack_low, *stack_high;
	
	end_at = ((u32_t) &_kend);
	end_at = ROUND_TO_NEXT(end_at);
	
	num = (mem_available-(end_at+KERNEL_OFFSET))/PAGE_SIZE;
	
	len_stacks = ROUND_TO_NEXT(num*sizeof(struct page));
	end_at += len_stacks;
	num -= len_stacks/PAGE_SIZE;
	
	stack_low = (struct page *) end_at;
	stack_low_head = stack_low;
	
	for(addr=end_at-KERNEL_OFFSET, i=0; addr<MEM_LOW && addr<=(mem_available-PAGE_SIZE); 
	    addr+=PAGE_SIZE, i++) {
		stack_low[i].addr = addr;
		stack_low[i].next = &stack_low[i+1];
	}
	stack_low[i-1].next = NULL;
	
	stack_high = &stack_low[i];
	stack_high_head = stack_high;
	
	for(i=0; addr<=(mem_available-PAGE_SIZE); i++, addr+=PAGE_SIZE) {
		stack_high[i].addr = addr;
		stack_high[i].next = &stack_high[i+1];
	}
	stack_high[i-1].next = NULL;
	
	return 0;
}

struct page *ph_get_page_low(void)
{
	struct page *p;
	
	if((p = stack_low_head) != NULL) {
		stack_low_head = p->next;
		return p;
	} else {
		return NULL;
	}
}

struct page *ph_get_page(void)
{
	struct page *p;
	
	if((p = stack_high_head) != NULL) {
		stack_high_head = p->next;
		return p;
	} else {
		return ph_get_page_low();
	}
}

void ph_free_page(struct page *p)
{
	if(p->addr<MEM_LOW) {
		p->next = stack_low_head;
		stack_low_head = p;
	} else {
		p->next = stack_high_head;
		stack_high_head = p;
	}
}

