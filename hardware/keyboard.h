#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../utils/types.h"
#include "keycodes.h"
#include "port.h"
#include "../utils/print.h"

extern char get_ascii_char(uint8_t);
void enableInput();

#endif
