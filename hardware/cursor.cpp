//
// Created by Ashwin Paudel on 2021-03-06.
//

#include "cursor.h"

namespace apos {
    namespace cursor {
        void disable_cursor()
        {
            Port8Bit mousePort;
            mousePort.Write(0x3D4, 0x0A);
            mousePort.Write(0x3D5, 0x20);
        }
        uint16_t getCursorX()
        {
            Port8Bit mousePort;
            uint16_t x = 0;
            uint16_t y = 0;
            mousePort.Write(0x3D4, 0x0F);
            x |= mousePort.Read(0x3D5);
            mousePort.Write(0x3D4, 0x0E);
            y |= ((uint16_t)mousePort.Read(0x3D5)) << 8;
            return x;
        }
        uint16_t getCursorY()
        {
            Port8Bit mousePort;
            uint16_t x = 0;
            uint16_t y = 0;
            mousePort.Write(0x3D4, 0x0F);
            x |= mousePort.Read(0x3D5);
            mousePort.Write(0x3D4, 0x0E);
            y |= ((uint16_t)mousePort.Read(0x3D5)) << 8;
            return y;
        }
        void test_input() {
            Port8Bit cursor;
            uint16_t* VideoMemory = (uint16_t*)0xb8000;
            int offset = 0;
            int buttons = 0;

            int x = getCursorX();
            int y = getCursorY();
            while (true) {
                 x = getCursorY();
                 y = getCursorX();
            }

            VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                                  | (VideoMemory[80*y+x] & 0xF000) >> 4
                                  | (VideoMemory[80*y+x] & 0x00FF);

            cursor.Write(0xA8, 0x60);
            cursor.Write(0x20, 0x60); // command 0x60 = read controller command byte
            uint8_t status = cursor.Read(0x60) | 2;
            cursor.Write(0x60, 0x60); // command 0x60 = set controller command byte
            cursor.Write(status, 0x60);

            cursor.Write(0xD4, 0x60);
            cursor.Write(0xF4, 0x60);
            cursor.Read(0x60);
        }
    }
}