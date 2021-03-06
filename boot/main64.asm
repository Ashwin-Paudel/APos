

global long_mode_start
extern kernel_main

section .text
bits 64 ; Tell that were in 64 bit mode
long_mode_start:
    ; load null into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    call kernel_main
    hlt
    int 0x80


innnnnteerrruptssss:
    int 0x20