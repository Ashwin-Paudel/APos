//
//  keyboard.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-03.
//

#ifndef __APOS__HARDWARE__KEYBOARD_H
#define __APOS__HARDWARE__KEYBOARD_H

#include "../utils/types.h"
#include "keycodes.h"
#include "port.h"
#include "../utils/print.h"

using namespace apos::types;
using namespace apos::print;
using namespace apos::ports;
using namespace apos::keycodes;

extern char get_ascii_char(uint8_t);

void enableKeyboard();

#endif
