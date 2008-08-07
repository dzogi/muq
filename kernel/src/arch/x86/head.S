.code32

.global start_32
.global gdt

.extern arch_init

#define GFX_BUFFER 0xB8000
#define OFFSET 0xE0000000

#define PRESENT_RW_USER 0x7 /* for the global page table entries */
#define HIGH_TBL_OFFSET (((OFFSET)/(1024*1024*4))*4)

.section .text

start_32:
	cld
	movl $_stack_end-OFFSET, %ebp
	movl $_stack_end-OFFSET, %esp
	lgdt gdt_desc-OFFSET
	movl $0x10, %eax
	movl %eax,%ds
	movl %eax,%es
	movl %eax,%fs
	movl %eax,%gs
	ljmp $0x08, $_load_cs_segment-OFFSET 
_load_cs_segment:
	/** Initializing the page tables.
	  * Do *NOT* use the stack here */
	
	/* Identity mapping of the first 1MB */
	movl $(gp0-OFFSET), %edi
	movl $0, %ecx /* number of entries */
	movl $PRESENT_RW_USER, %eax
lp1:
	stosl
	inc %ecx
	add $0x1000, %eax
	cmp $1024, %ecx
	jne lp1
	movl $(gp0-OFFSET), (gptable-OFFSET)
	orl $3, (gptable-OFFSET)
	/* 0-4Megs at 3GB */
	movl $(gp1-OFFSET), %edi
	movl $0, %ecx
	movl $(PRESENT_RW_USER), %eax
lp2:
	stosl
	inc %ecx
	add $0x1000, %eax
	cmp $1024, %ecx
	jne lp2
	movl $(gp0-OFFSET), (gptable-OFFSET+HIGH_TBL_OFFSET)
	orl $3, (gptable-OFFSET+HIGH_TBL_OFFSET)
	movl $(gptable-OFFSET), %eax
	
	/* Set up the fractal mapping (last entry points back the the table */
	movl $(gptable-OFFSET), (gptable-OFFSET+4096-4)
	orl $3, (gptable-OFFSET+4096-4)
	
	movl %eax, %cr3
	movl %cr0,%eax
	orl $0x80000000,%eax
	movl %eax,%cr0
	ljmp $0x08, $paging_enabled
paging_enabled:
	pushl %ebx
	pushl $0xDEADBEEF /* return address, never returns */
	jmp arch_init

.section .data
_welcome_str: .asciz "Welcome to muQ v0.1"
gdt: 
	.quad 0
	.quad 0x00cf9a000000ffff /* kernel 4GB code at 0x00000000 */
	.quad 0x00cf92000000ffff /* kernel 4GB data at 0x00000000 */
gdt_desc:
	.word gdt-gdt_desc
	.long gdt-OFFSET

.section .bss
.align 4096

_stack_start:
.space 4096 /* 4K stack */
_stack_end:

gptable:
	.fill 1024, 4, 0
gp0: /* the first table used to identity map the first 1meg */
	.fill 1024, 4, 0
gp1: /* map of 0MB-4MB at 3gigs */
	.fill 1024, 4, 0
