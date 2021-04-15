# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include
FLAGS           = -mfloat-abi= hard

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: proj.elf 

#additional rules for files
proj.elf: ${COMMON_OBJECTS} projMain.o stateMachines.o led.o wdInterruptHandler.o switches.o buzzer.o p1_interrupt_handler.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: proj.elf
	msp430loader.sh proj.elf

projMain.o: projMain.c

clean:
	rm -f *.o *.elf *.c~ *.# *.s~

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

p1_interrupt_handler.o: p1_interrupt_handler.c

buzzer.o: buzzer.h buzzer.c
