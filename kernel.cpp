
#include "utils/print.h"
#include "utils/colors.h"
#include "utils/port.h"
#include "utils/keycodes.h"
#include "utils/keyboard.h"
#include "utils/gdt.h"



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
    printf("test");
    GlobalDescriptorTable gdt;
gdt.~GlobalDescriptorTable();
    enableInput();
}