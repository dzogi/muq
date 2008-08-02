OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(start_32)
virt_addr = 0xE0000000; /* 3 gigs */
phys_addr = 0X00100000; /* 1 meg */

SECTIONS
{
	. = virt_addr + phys_addr + SIZEOF_HEADERS;
	.mboot : AT(ADDR(.mboot) - virt_addr) { *(.mboot) }
	.init32 : AT(ADDR(.init32) - virt_addr) { *(.init32) }

	_kcode = .;
  	.text : AT(ADDR(.text) - virt_addr) { *(.text) }

 	. = ALIGN(4K);
 	.rodata : AT(ADDR(.rodata) - virt_addr) { *(.rodata) }

	. = ALIGN(4K);
  	_kdata = .;
 	.data : AT(ADDR(.data) - virt_addr) { *(.data) }

 	. = ALIGN(4K);
 	_kbss = .;
 	.bss : AT(ADDR(.bss) - virt_addr) { *(COMMON) *(.bss) }

 	_kend = .;
}

