CROSS_COMPILE = arm-none-eabi-
CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld -v
CP      = $(CROSS_COMPILE)objcopy
OD      = $(CROSS_COMPILE)objdump
  
CFLAGS  =  -I./ -c -fno-common -Os -mcpu=cortex-m3 -mthumb -g
LFLAGS  = -Tstm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

all: test

clean:
	-rm -f ledblink.lst ledblink.o ledblink.elf ledblink.lst ledblink.bin

test: ledblink.elf
	@ echo "...copying"
	$(CP) $(CPFLAGS) ledblink.elf ledblink.bin
	$(OD) $(ODFLAGS) ledblink.elf > ledblink.lst

ledblink.elf: ledblink.o stm32.ld 
	@ echo "..linking"
	$(LD) $(LFLAGS) -o ledblink.elf ledblink.o    

ledblink.o: ledblink.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) ledblink.c
