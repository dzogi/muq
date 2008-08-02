.code32
.global start_32
.extern main

#define GFX_BUFFER 0xB8000

.section .text
start_32:
	hlt
	jmp .

.section .data
_welcome_str: .asciz "Welcome to muQ v0.1"
