#ifndef __INCLUDE_STRING_H
#define __INCLUDE_STRING_H

inline void *memcpy(void *to, void *from, size_t n);
inline void *memset(void *s, int c, size_t count);
inline void *memset16(void *s, u16_t c, size_t count);
void puts(char* str);

#endif /* __INCLUDE_STRING_H */
