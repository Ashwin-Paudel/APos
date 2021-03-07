//
//  Interrupts.cpp
//  APos
//
//  Created by Ashwin Paudel on 2021-03-06.
//

#include "idt.h"
#include "isr.h"

struct IDT idt_entries[16];
struct IDT_PTR idt_first;

extern "C" void load_idt(struct IDT*);

void set_idt_gate(int intnum, uint64_t isr)
{
    idt_entries[intnum].base_low = isr & 0xffff;
    idt_entries[intnum].segment_selector = 0x08;
    idt_entries[intnum].zero = 0;
    idt_entries[intnum].type = 0x8E;
    idt_entries[intnum].base_high = (isr >> 16) & 0xffff;
}

void init_idt()
{
    set_idt_gate(0, (uint64_t)isr_0);
    set_idt_gate(1, (uint64_t)isr_1);
    set_idt_gate(2, (uint64_t)isr_2);
    set_idt_gate(3, (uint64_t)isr_3);
    set_idt_gate(4, (uint64_t)isr_4);
    set_idt_gate(5, (uint64_t)isr_5);
    set_idt_gate(6, (uint64_t)isr_6);
    set_idt_gate(7, (uint64_t)isr_7);
    set_idt_gate(8, (uint64_t)isr_8);
    set_idt_gate(9, (uint64_t)isr_9);
    set_idt_gate(10, (uint64_t)isr_10);
    set_idt_gate(11, (uint64_t)isr_11);
    set_idt_gate(12, (uint64_t)isr_12);
    set_idt_gate(13, (uint64_t)isr_13);
    set_idt_gate(14, (uint64_t)isr_14);
    set_idt_gate(15, (uint64_t)isr_15);

    idt_first.limit_size = sizeof(idt_entries) - 1;
    idt_first.base_address = (struct IDT*)&idt_entries;

    load_idt((struct IDT*)&idt_first);
}
