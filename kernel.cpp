//
//  kernel.cpp
//  APos
//
//  Created by Ashwin Paudel on 2021-03-03.
//


// Include the files
#include "utils/print.h"
#include "utils/colors.h"
#include "hardware/port.h"
#include "hardware/keycodes.h"
#include "hardware/keyboard.h"
#include "hardware/gdt.h"
#include "utils/PrintASCII.h"
#include "utils/APosInfo.h"
#include "hardware/cursor.h"

// Use the files namespaces
using namespace apos::print;
using namespace apos::types;
using namespace apos::colors;
using namespace apos::osInfo;
using namespace apos::cursor;

// Since Assembly can only call C files, we need to use extern C to make it a C function
extern "C" void kernel_main() {

    /*
     * When you boot in Qemu, it will show text
     * So we need to clear the text
     * By Calling the Pclear function
     */
    pclear();
    // Change the screem to yellow and black
    psetColor(yellow, black);
    // Print the text
    printf("Welcome to the 64 Bit operating system by Ashwin Paudel");
    // Change the text color to plain white and black
    psetColor(white, black);

    // Numbers go 0 to 10
    // Print APos Logo with ASCII Characters
    APOSLogo(2);


    // Print the OS information
    printf(apos::osInfo::aposInformation());

    // Just testing if the Gdt works
    GlobalDescriptorTable gdt;

    // Print a new line
    pnewLine();
    // Enable keyboard type events

    enableKeyboard();

    // If the user presses the enter key, it will trigger this function
    // This function has no use here
    enableMouse();
}
