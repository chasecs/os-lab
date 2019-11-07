#include "print/monitor.h"

#include "system/system.h"

void *memset(void *dest, char val, int count){
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

int main(){
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    
    
    monitor_clear();
    set_text_color(15, 0);
    timer_install();
    // Set Interrupt Flag
    __asm__ __volatile__ ("sti"); 
    return 0;
}
