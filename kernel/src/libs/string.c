#include <string.h>
#include <arch/video.h>

inline void *memcpy(void *to, void *from, size_t n)
{
	char *to_c = (char *) to, *from_c = (char *) from;
	while(n--)
		*to_c++ = *from_c++;
	
	return to;
}

inline void *memset(void *s, int c, size_t count)
{
	char *buf = (char *)s;
	while(count--)
		*buf++ = (char) c;
	
	return s;
}

inline void *memset16(void *s, u16_t c, size_t count)
{
	u16_t *buf = (u16_t *)s;
	while(count--)
		*buf++ = c;
	
	return s;
}

void puts(char* str)
{
	while(*str != '\0')
		putchar(*str++);
}

