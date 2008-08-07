#include <errors.h>

#include <arch/arch_interrupts.h>

struct int_handler {
	struct int_handler* next;
	int (*handler)(void *);
	unsigned int num_calls;
};

struct int_vector {
	struct int_handler* head;
	unsigned int num_calls;
};

static struct int_vector int_vectors[ARCH_NUM_INT_VECTORS];

int int_init(void)
{
	return 0;
}

int int_set_handler(int num, int (*handler)(void *), void *data)
{
	return 0;
}

int int_remove_handler(int num, int (*handler)(void *))
{
	return 0;
}

int int_handle(int num)
{
	return 0;
}

