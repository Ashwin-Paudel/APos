//
//  gdt.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-05.
//

#ifndef __APOS__HARDWARE__GDT_H
#define __APOS__HARDWARE__GDT_H

#include "../utils/types.h"
#include "../utils/print.h"

using namespace apos::print;
using namespace apos::types;

class GlobalDescriptorTable {
public:
    class SegmentDescriptor {
    private:
        uint16_t limit_lo;
        uint16_t base_lo;
        uint8_t base_hi;
        uint8_t type;
        uint8_t limit_hi;
        uint8_t base_vhi;

    public:
        SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);

        uint32_t Base();

        uint32_t Limit();
    } __attribute__((packed));

private:
    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;

public:
    GlobalDescriptorTable();

    ~GlobalDescriptorTable();

    uint16_t CodeSegmentSelector();

    uint16_t DataSegmentSelector();
};

#endif