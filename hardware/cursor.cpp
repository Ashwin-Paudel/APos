//
// Created by Ashwin Paudel on 2021-03-06.
//

#include "cursor.h"

namespace apos {
    namespace cursor {
        void disable_cursor()
        {
            outb(0x3D4, 0x0A);
            outb(0x3D5, 0x20);
        }
        uint16_t get_cursor_position()
        {
            Port8Bit mousePort;
            uint16_t pos = 0;
            mousePort.Write(0x3D4, 0x0F);
            pos |= mousePort.Read(0x3D5);
            mousePort.Write(0x3D4, 0x0E);
            pos |= ((uint16_t)mousePort.Read(0x3D5)) << 8;
            return pos;
        }
        void test_input() {
            Port8Bit cursor;
            uint16_t* VideoMemory = (uint16_t*)0xb8000;
            int offset = 0;
            int buttons = 0;
            int sdfsadf = 0;

            int x = get_cursor_position();
            int y = get_cursor_position();
            for (;;) {
                x = get_cursor_position();
                y = get_cursor_position();

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