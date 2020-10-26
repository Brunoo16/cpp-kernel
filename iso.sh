grub2-file --is-x86-multiboot Kernel.bin
mkdir -p iso/boot/grub
cp Kernel.bin iso/boot/Kernel.bin
cp grub.cfg iso/boot/grub/grub.cfg
grub2-mkrescue -o Kernel.iso iso