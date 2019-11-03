#include "print/monitor.h"

#include "system/system.h"

int main()
{
    gdt_install();
    monitor_clear();
    set_text_color(15, 0);
    // Write out a sample string
    monitor_write("Hello world!");

    
    return 0;

}
