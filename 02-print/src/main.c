#include "print/monitor.h"

int main()
{
    monitor_clear();
    set_text_color(15, 0);
    // Write out a sample string
    monitor_write("Hello world!");

    
    return 0;

}
