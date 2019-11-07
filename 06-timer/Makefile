OUTPUT=build
SOURCE=src
VPATH=src:$(SOURCE)

OBJECTS = loader.o main.o print/monitor.o print/common.o \
			 system/gdt.o system/idt.o system/isrs.o system/irq.o system/timer.o

CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
             -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c -I ./

LDFLAGS =  -melf_i386

AS = nasm
ASFLAGS = -f elf32

ifeq ($(shell uname), Darwin)
	ISO = mkisofs
	CC = i386-elf-gcc
	LD = i386-elf-ld
else
	ISO = genisoimage
	CC = gcc
	LD = ld
endif

all: kernel.elf

kernel.elf: link.ld $(OBJECTS)
	$(LD) -T $< $(LDFLAGS) $(addprefix $(OUTPUT)/, $(OBJECTS)) -o $(OUTPUT)/kernel.elf

os.iso: kernel.elf
	@cp $(OUTPUT)/kernel.elf iso/boot/kernel.elf
	$(ISO)  -R                              \
            -b boot/grub/stage2_eltorito    \
            -no-emul-boot                   \
            -boot-load-size 4               \
            -A os                           \
            -input-charset utf8             \
            -quiet                          \
            -boot-info-table                \
            -o os.iso				\
            iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	@mkdir -p $(dir $(OUTPUT)/$@)
	$(CC) $(CFLAGS)  $< -o $(OUTPUT)/$@

%.o: %.asm
	@mkdir -p $(dir $(OUTPUT)/$@)
	$(AS) $(ASFLAGS) $< -o $(OUTPUT)/$@

clean:
	@find $(OUTPUT) -name '*.o' -delete
	@rm -rf $(OUTPUT)/kernel.* os.iso
