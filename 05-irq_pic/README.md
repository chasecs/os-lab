# IRQ and PICs

Interrupt Requests are interrupts that are raised by hardware devices.

Programmable Interrupt Controllers, PICs, are 2 chips used to manage IRQs

Every interrupt from the PIC has to be acknowledged - that is, sending a message to the PIC confirming that the interrupt has been handled. If this isn’t done the PIC won’t generate any more interrupts.

The PIC uses interrupts 0 - 15 for hardware interrupts by default, which conflicts with the CPU interrupts. Therefore the PIC interrupts must be remapped to another interval.we will map IRQ0 through IRQ15 to IDT entries 32 through 47.


## build and run 

```
make && make run
```

Enter `c` to make bochs run.


