
#ifndef PRINT_H
#define PRINT_H

#include "types.h"
#include "colors.h"

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
#endif
