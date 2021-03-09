//
// Created by Ashwin Paudel on 2021-03-09.
//

#include "Sleep.h"

namespace apos {
    namespace sleep {
        void sleep(uint32_t timer_count) {
            while (1) {
                asm volatile("nop");
                timer_count--;

                if (timer_count <= 0) {
                    break;
                }
            }
        }
    }
}