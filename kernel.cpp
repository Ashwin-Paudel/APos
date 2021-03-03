#include "utils/print.h"
#include "utils/colors.h"
#include "hardware/port.h"
#include "hardware/keycodes.h"
#include "hardware/keyboard.h"
#include "hardware/gdt.h"

// Since Assembly can only call C files, we need to use extern C to make it a C function
extern "C" void kernel_main()
{

    // Clear the screen
    pclear();
    // Change the screem to yellow and black
    psetColor(yellow, black);
    // Print the text
    printf("Welcome to the 64 Bit operating system by Ashwin Paudel");

    psetColor(white, black);
    // Print the text
    printf("You can type text");
    // Test the GDT
    GlobalDescriptorTable gdt;
    // Testing
    // some code ...
    gdt.~GlobalDescriptorTable();
    // Print a new line to type keyboard
    pnewLine();
    enableInput();
}
