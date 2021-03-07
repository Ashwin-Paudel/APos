;
; interrupts.asm
; APos
;
; Created by Ashwin Paudel on 2021-03-06
;

; Code doesn't compile so leave blank before compiling

section .text
global load_idt

load_idt:
	mov 4(%esp), %eax
	lidt (%eax)
  ret