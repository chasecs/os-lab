#ifndef __SYSTEM_H
#define __SYSTEM_H
/* GDT.C */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();

// idt.c
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();

/* main.c */
extern void *memset(void *dest, char val, int count);




/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;    
};

/* ISRS.C */
extern void isrs_install();

//irq.c
extern void irq_install();
void irq_install_handler(int irq, void (*handler)(struct regs *r));


/* Installs the keyboard handler into IRQ1 */
extern void keyboard_install();

#endif