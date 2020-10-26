CC = gcc

CC_FLAGS = -m32 -c -nostdlib -std=c++11 -ffreestanding -O2 -Wall -Wextra

CPP_FILES := $(wildcard *.cpp)
ASM_FILES := $(wildcard *.asm)
BOOT_FILE := boot.asm
O_FILES := $(CPP_FILES:.cpp=.o) $(ASM_FILES:.asm=.o)
KERNEL_BIN := Kernel.bin

all: $(KERNEL_BIN)

clean:
	rm -f $(KERNEL_BIN) $(O_FILES)

%.o: %.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

$(BOOT_FILE): $(O_FILES)
	as --32 -o $@ $<

$(KERNEL_BIN): $(O_FILES)
	ld -m elf_i386 -nostdlib -T linker.ld -o $@ $^
	./iso.sh