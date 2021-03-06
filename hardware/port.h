
#ifndef __APOS__HARDWARE__PORT_H
#define __APOS__HARDWARE__PORT_H

#include "../utils/types.h"

using namespace apos::types;

namespace apos {
    namespace ports {
        class Port8Bit {
        private:
            /* data */
        public:
            Port8Bit();

            ~Port8Bit();

            uint8_t Read(uint16_t port);

            void Write(uint16_t port, uint16_t data);
        };
    }
}

#endif