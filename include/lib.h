/* Copyright (C) 2007  Mohammad Nabil 
mohammad (dot) nabil (dot) h (at) gmail (dot) com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/

#ifndef _LIB_H
#define	_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <types.h>
    
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, size_t count);
unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, size_t count);
unsigned char *memset(unsigned char *dest, char val, size_t count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);

void itoa (char *buf, int base, int d); // int to ascii
int strnlen(const char *str, int max);
int strncmp(const char *s1,const char* s2, int max);

#define MAX_CHARS 1024

void printf (const char *format, ...);
void printk (const char *format, ...);
void panic (const char *format);

unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, char _data);

// printk levels
#define TRACE   "\310" // = 200 in decimal
#define DEBUG   "\311"
#define LOG     "\312"
#define WARNING "\313"
#define ERROR   "\314"
#define SEVERE  "\315"
#define LOG_ALL TRACE

#define IO_WAIT() ASM("nop"); ASM("nop"); ASM("nop"); ASM("nop");

// current printk level
#define PRINTK_LEVEL LOG_ALL

#ifdef	__cplusplus
}
#endif

#endif	/* _LIB_H */

