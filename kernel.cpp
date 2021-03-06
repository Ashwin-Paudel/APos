#include "utils/print.h"
#include "utils/colors.h"
#include "hardware/port.h"
#include "hardware/keycodes.h"
#include "hardware/keyboard.h"
#include "hardware/gdt.h"
#include "utils/PrintASCII.h"

using namespace apos::print;
using namespace apos::types;
using namespace apos::colors;

unsigned int MyRand(unsigned int start_range,unsigned int end_range)
{
    static unsigned int rand = 0xACE1U; /* Any nonzero start state will work. */

    /*check for valid range.*/
    if(start_range == end_range) {
        return start_range;
    }

    /*get the random in end-range.*/
    rand += 0x3AD;
    rand %= end_range;

    /*get the random in start-range.*/
    while(rand < start_range){
        rand = rand + end_range - start_range;
    }

    return rand;
}

// Since Assembly can only call C files, we need to use extern C to make it a C function
extern "C" void kernel_main() {

    // Clear the screen
    pclear();
    // Change the screem to yellow and black
    psetColor(yellow, black);
    // Print the text
    printf("Welcome to the 64 Bit operating system by Ashwin Paudel");
    GlobalDescriptorTable gdt;
    psetColor(white, black);
    // Print the text
    // 1..10
   APOSLogo(MyRand(0, 9));
    pnewLine();
//rand();
    // Test the GDT
    // GlobalDescriptorTable gdt;
    // Testing

    // Print a new line to type keyboard
    pnewLine();
//    PRINTAP();

    enableInput();
}
