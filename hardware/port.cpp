
#include "port.h"

namespace apos {
    namespace ports {
        Port8Bit::Port8Bit(/* args */) {
        }

        Port8Bit::~Port8Bit() {
        }

        uint8_t Port8Bit::Read(uint16_t port) {
            uint8_t result;
            __asm__ volatile("inb %1, %0"
            : "=a"(result)
            : "Nd"(port));
            return result;
        }
    }
}