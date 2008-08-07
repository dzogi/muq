#ifndef __INTERRUPTS_H
# define __INTERRUPTS_H

int int_init(void);
int int_set_handler(int num, int (*handler)(void *), void *data);
int int_remove_handler(int num, int (*handler)(void *));
int int_handle(int num);

#endif /* __INTERRUPTS_H */
