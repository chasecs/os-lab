#include "common.h"

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outb(unsigned short port, unsigned char value){

    asm volatile("outb %1, %0" : : "dN"(port), "a"(value));

};