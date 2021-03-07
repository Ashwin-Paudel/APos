//
//  types.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-03.
//

#ifndef __APOS__UTILS__TYPES_H
#define __APOS__UTILS__TYPES_H

namespace apos {
    namespace types {
        // 8 Bits
        typedef char int8_t;
        typedef unsigned char uint8_t;

        // 16 Bits
        typedef short int16_t;
        typedef unsigned short uint16_t;

        // 32 Bits
        typedef int int32_t;
        typedef unsigned int uint32_t;

        // 64 Bits
        typedef long long int int64_t;
        typedef unsigned long long int uint64_t;

        // Others
        typedef const char *string;
        typedef uint32_t size_t;
    }
}

#endif