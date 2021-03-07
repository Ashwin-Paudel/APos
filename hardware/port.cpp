//
//  port.cpp
//  APos
//
//  Created by Ashwin Paudel on 2021-03-04.
//

#include "port.h"

namespace apos {
    namespace ports {
        Port8Bit::Port8Bit() {
        }

        Port8Bit::~Port8Bit() {
        }

        void Port8Bit::Write(uint8_t data, uint16_t portnumber) {
            Write8(portnumber, data);
        }

        uint8_t Port8Bit::Read(uint16_t portnumber) {
            return Read8(portnumber);
        }


        Port8BitSlow::Port8BitSlow() {
        }

        Port8BitSlow::~Port8BitSlow() {
        }

        void Port8BitSlow::Write(uint8_t data, uint16_t portnumber) {
            Write8Slow(portnumber, data);
        }


        Port16Bit::Port16Bit() {
        }

        Port16Bit::~Port16Bit() {
        }

        void Port16Bit::Write(uint16_t data, uint16_t portnumber) {
            Write16(portnumber, data);
        }

        uint16_t Port16Bit::Read(uint16_t portnumber) {
            return Read16(portnumber);
        }


        Port32Bit::Port32Bit() {
        }

        Port32Bit::~Port32Bit() {
        }

        void Port32Bit::Write(uint16_t portnumber, uint32_t data) {
            Write32(portnumber, data);
        }

        uint32_t Port32Bit::Read(uint16_t portnumber) {
            return Read32(portnumber);
        }

    }
}