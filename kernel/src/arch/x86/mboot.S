.code32

.extern start_32
#define MB_FLAGS ((1<<0) | (1<<1) | (1<<16))

.section .mboot
.align 4
_mb_header:

.long 0x1BADB002 /* magic */
.long MB_FLAGS
.long -(0x1BADB002 + MB_FLAGS) /* checksum */
.long _mb_header-0xE000000 /* header_addr*/
.long 0x00100000 /* load_addr */
.long 0 /* end_addr */
.long 0 /* bss_end */
.long start_32-0xE0000000
