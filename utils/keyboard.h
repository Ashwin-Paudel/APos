#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"
#include "keycodes.h"
#include "port.h"
#include "print.h"

extern char get_ascii_char(uint8_t);
void enableInput();

#endif
