# All the cimpiles objects, used to combine to object files into a .bin file
objects = build/header.o build/print.o build/main64.o build/kernel.o build/main.o build/port.o build/gdt.o build/keyboard.o
# Parameters for when compiling Gcc
gccParams = -Wno-write-strings -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore

.PHONY: build
build:
	# Make a build directory
	mkdir -p build/x86_64
	# Compile C++ files
	x86_64-elf-gcc -c -I utils/ $(gccParams) utils/print.cpp -o build/print.o
	x86_64-elf-gcc -c -I utils/ $(gccParams) utils/port.cpp -o build/port.o
	x86_64-elf-gcc -c -I utils/ $(gccParams) kernel.cpp -o build/kernel.o
	x86_64-elf-gcc -c -I utils/ $(gccParams) utils/keyboard.cpp -o build/keyboard.o
	x86_64-elf-gcc -c -I utils/ $(gccParams) utils/gdt.cpp -o build/gdt.o
	# Compile Assembly files
	nasm -f elf64 boot/header.asm -o build/header.o
	nasm -f elf64 boot/main.asm -o build/main.o
	nasm -f elf64 boot/main64.asm -o build/main64.o
	# Combine the object files into a .bin file
	x86_64-elf-ld -n -o build/x86_64/APos.bin -T linker/linker.ld $(objects)
	cp build/x86_64/APos.bin isodir/boot/APos.bin
	# Turn the .bin file into a .iso file
	grub-mkrescue /usr/lib/grub/i386-pc -o build/x86_64/APos.iso isodir

.PHONY: run
run:
	exit
	qemu-system-x86_64 build/x86_64/APos.iso

.PHONY: docker
docker:
	docker build . -t apos-buildenv
	docker run --rm -it -v "$PWD":/root/env apos-buildenv
	
