
#ifndef __APOS__UTILS__PRINT_H
#define __APOS__UTILS__PRINT_H

#include "types.h"
#include "colors.h"

using namespace apos::types;
using namespace apos::colors;

namespace apos
{
    namespace print
    {
        // Clear the screen
        void pclear();
        // Print just one char
        void pchar(char character);
        // Print a string
        void printf(char *string);
        // Set the foreground color of the text
        void psetColor(uint8_t foreground, uint8_t background);
        // Print a new line
        void pnewLine();
        // Delete a charecter
        void pdelete();
        // Printf for a interger
        void printf(int num);
    }
}
#endif
