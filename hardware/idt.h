//
//  Interrupts.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-06.
//

#ifndef APOS_INTERRUPTS_H
#define APOS_INTERRUPTS_H


#include "gdt.h"
#include "../utils/types.h"
#include "port.h"
#include "../utils/print.h"
#include "port.h"

using namespace apos::print;
using namespace apos::ports;
using namespace apos::types;

struct IDT {
    uint16_t base_low;  // lower 16 bits 0-15 of the address to jump to when this interrupt fires
    uint16_t segment_selector;  // code segment selector in GDT
    uint8_t zero;  // unused, always be zero
    uint8_t type;  // types trap, interrupt gates
    uint16_t base_high;  // upper 16 bits 16-31 of the address to jump to
} __attribute__((packed));


struct IDT_PTR {
    uint16_t limit_size;  // limit size of all IDT segments
    struct IDT *base_address;  // base address of the first IDT segment
} __attribute__((packed));

extern struct IDT idt_entries[16];
extern struct IDT_PTR idt_first;

extern "C" void init_idt();

#endif