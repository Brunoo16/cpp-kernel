# So our entry-point can be called from asm code.
.extern entry_point
.global entry

.set FLAGS,    0
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot

.long MAGIC
.long FLAGS
.long CHECKSUM

stack_bottom:
.skip 4096

stack_top:
.section .text
.type entry, @function

entry:
mov $stack_top, %esp
call entry_point
cli

.size entry, . - entry

.section .end