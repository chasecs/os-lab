// monitor.c -- Defines functions for writing to the monitor.
//             heavily based on Bran's kernel development tutorials,
//             but rewritten for JamesM's kernel tutorials.

#include "monitor.h"

// The VGA framebuffer starts at 0xB8000.
unsigned short *video_memory = (unsigned short  *)0xB8000;
// Stores the cursor position.
int cursor_x = 0;
int cursor_y = 0;

// The attribute byte is made up of two nibbles - the lower being the 
// foreground colour, and the upper the background colour.
unsigned char attribute = 0x0F; //

// // Updates the hardware cursor.
static void move_cursor()
{
    // The screen is 80 characters wide...
    unsigned char cursorLocation = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
    outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
    outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
    outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

void monitor_put(char c){
  

    // VGA board.
    unsigned short *location;
    location = video_memory + (cursor_y*80 + cursor_x);
    *location = c | (attribute << 8);
    
  
    if(cursor_x < COL_MAX - 1 ){
        cursor_x ++;
    }else{
        cursor_y ++;
        cursor_x = 0;
    }
    move_cursor();
}

void monitor_write(char *c){
    int i = 0;
    while(c[i]){
        monitor_put(c[i++]);
    }
}
void set_text_color(unsigned char forecolor, unsigned char backcolor){
    attribute = (backcolor << 4) | (forecolor & 0x0F);

    
}
void monitor_clear(){

    //set forcolor white, backcolor black
    set_text_color(0,15);
    // Get a space character with the default colour attributes.
    unsigned char blank = 0x20 /* space */ | (attribute << 8);

    int i;
    for (i = 0; i < 80*25; i++)
    {
        video_memory[i] = blank;
    }

    // Move the hardware cursor back to the start.
    cursor_x = 0;
    cursor_y = 0; 

}


