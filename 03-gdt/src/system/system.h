#ifndef __SYSTEM_H
#define __SYSTEM_H
/* GDT.C */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();
#endif