#include "common.h"

void outb(u16int port, u8int value){

    asm volatile("outb %1, %0" : : "dN"(port), "a"(value));

};