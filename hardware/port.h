//
//  port.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-04.
//

#ifndef __APOS__HARDWARE__PORT_H
#define __APOS__HARDWARE__PORT_H

#include "../utils/types.h"

using namespace apos::types;

namespace apos {
    namespace ports {

        class Port8Bit {
        public:
            Port8Bit();

            ~Port8Bit();

            virtual uint8_t Read(uint16_t portnumber);

            virtual void Write(uint8_t data, uint16_t portnumber);

        protected:
            static inline uint8_t Read8(uint16_t _port) {
                uint8_t result;
                __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_port));
                return result;
            }

            static inline void Write8(uint16_t _port, uint8_t _data) {
                __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
            }
        };


        class Port8BitSlow {
        public:
            Port8BitSlow();

            ~Port8BitSlow();

            virtual void Write(uint8_t data, uint16_t portnumber);

        protected:
            static inline void Write8Slow(uint16_t _port, uint8_t _data) {
                __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (_data), "Nd" (_port));
            }

        };


        class Port16Bit {
        public:
            Port16Bit();

            ~Port16Bit();

            virtual uint16_t Read(uint16_t portnumber);

            virtual void Write(uint16_t data, uint16_t portnumber);

        protected:
            static inline uint16_t Read16(uint16_t _port) {
                uint16_t result;
                __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (_port));
                return result;
            }

            static inline void Write16(uint16_t _port, uint16_t _data) {
                __asm__ volatile("outw %0, %1" : : "a" (_data), "Nd" (_port));
            }
        };


        class Port32Bit {
        public:
            Port32Bit();

            ~Port32Bit();

            virtual uint32_t Read(uint16_t portnumber);

            virtual void Write(uint16_t portnumber, uint32_t data);

        protected:
            static inline uint32_t Read32(uint16_t _port) {
                uint32_t result;
                __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (_port));
                return result;
            }

            static inline void Write32(uint16_t _port, uint32_t _data) {
                __asm__ volatile("outl %0, %1" : : "a"(_data), "Nd" (_port));
            }
        };

    }

}

#endif