/* boot.S - bootstrap the kernel */
/* Copyright (C) 1999, 2001	Free Software Foundation, Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#define ASM	1
#include <multiboot.h>

	.text

	.globl	start, _start,
start:
_start:
	jmp	multiboot_entry

	/* Align 32 bits boundary. */
	.align	4

multiboot_header:

	/* magic */
	.long	MULTIBOOT_HEADER_MAGIC
	
	/* flags */
	.long	MULTIBOOT_HEADER_FLAGS
	
	/* checksum */
	.long	-(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
#ifndef __ELF__

	/* header_addr */
	.long	multiboot_header
	
	/* load_addr */
	.long	_start
	
	/* load_end_addr */
	.long	__end_data
	
	/* bss_end_addr */	
	.long	__end_bss
	
	/* entry_addr */	
	.long	multiboot_entry
#endif /* ! __ELF__ */
multiboot_entry:
	/* Initialize the stack pointer. */
	movl	$(stack + STACK_SIZE), %esp

	/* Reset EFLAGS. */
	pushl	$0
	popf

	/* Push the pointer to the Multiboot information structure. */
	pushl	%ebx
	/* Push the magic value. */
	pushl	%eax
	.global asm_to_c
	/* Now enter the C main function... */
        pushl $0 /* to stop the back trace here, set ebp = NULL */
        popl %ebp
.stabs "asm_to_c:F1",36,0,0,asm_to_c      
	asm_to_c: call	cmain

	/* Halt. */
	pushl	timer_ticks
	pushl	$halt_message
	call	printf
	popl	%eax
	popl	%eax
        
loop:
    pause
    hlt
    jmp	loop

halt_message:
	.asciz	"Halted at tick %d :).\n"

	/* Our stack area. */
	.comm	stack, STACK_SIZE
