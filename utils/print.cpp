

#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char *buffer = (struct Char *) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = white | black << 4;
namespace apos {
    namespace print {
        // The the row
        void clear_row(size_t row) {
            struct Char empty = (struct Char) {
                    character : ' ',
                    color : color,
            };

            for (size_t col = 0; col < NUM_COLS; col++) {
                buffer[col + NUM_COLS * row] = empty;
            }
        }

        // Clear the screen
        void pclear() {
            for (size_t i = 0; i < NUM_ROWS; i++) {
                clear_row(i);
            }
        }

        // Print a new line
        void pnewLine() {
            col = 0;

            if (row < NUM_ROWS - 1) {
                row++;
                return;
            }

            for (size_t row = 1; row < NUM_ROWS; row++) {
                for (size_t col = 0; col < NUM_COLS; col++) {
                    struct Char character = buffer[col + NUM_COLS * row];
                    buffer[col + NUM_COLS * (row - 1)] = character;
                }
            }

            clear_row(NUM_COLS - 1);
        }

        // Print just one char
        void pchar(char character) {
            if (character == '\n') {
                pnewLine();
                return;
            }

            if (col > NUM_COLS) {
                pnewLine();
            }

            buffer[col + NUM_COLS * row] = (struct Char) {
                    character : (uint8_t) character,
                    color : color,
            };

            col++;
        }

        // Print just one char
        void pdelete() {
            col--;
        }

        uint32_t digit_count(int num) {
            uint32_t count = 0;
            if (num == 0)
                return 1;
            while (num > 0) {
                //count++;
                num = num / 10;
            }
            return count;
        }

        void itoa(int num, char *number) {
            int dgcount = digit_count(num);
            int index = dgcount - 1;
            char x;
            if (num == 0 && dgcount == 1) {
                number[0] = '0';
                number[1] = '\0';
            } else {
                while (num != 0) {
                    x = num % 10;
                    number[index] = x + '0';
                    index--;
                    num = num / 10;
                }
                number[dgcount] = '\0';
            }
        }

        //print int by converting it into string
        //& then printing string
        void printf(int num) {
            char str_num[digit_count(num) + 1];
            itoa(num, str_num);
            printf(str_num);
        }

        // Print multiple chars
        void printf(char *str) {
            for (size_t i = 0; 1; i++) {
                char character = (uint8_t) str[i];

                if (character == '\0') {
                    return;
                }

                pchar(character);
            }
        }

        void printfHex(uint8_t key) {
            char *foo = "00";
            char *hex = "0123456789ABCDEF";
            foo[0] = hex[(key >> 4) & 0xF];
            foo[1] = hex[key & 0xF];
            printf(foo);
        }

        // Change the color of the background when printing the text
        void psetColor(uint8_t foreground, uint8_t background) {
            color = foreground + (background << 4);
        }

    }
}