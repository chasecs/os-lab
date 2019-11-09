# Keyboard 

## scancode 

keyboard generates scan codes.A scan code represents a button - both presses and releases.

The scan code representing the just pressed button can be read from the keyboard’s data I/O port which has address 0x60.

if bit 7 is set (test with 'scancode & 0x80'), then this is the keyboard's way of telling us that a key was just released.


## build and run 

```
make && make run
```

Enter `c` to make bochs run.


