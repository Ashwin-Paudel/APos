//
//  APosInfo.h
//  APos
//
//  Created by Ashwin Paudel on 2021-03-06.
//

#ifndef APOS_APOSINFO_H
#define APOS_APOSINFO_H

#include "types.h"

using namespace apos::types;
namespace apos {
    namespace osInfo {
        char *aposVersion() {
            return "1.2";
        }

        char *aposInformation() {
            return R""""(
Version: 1.2,
Last Modified: March 6, 2021,
Developers: Ashwin Paudel
               )"""";
        }
    }
}


#endif //APOS_APOSINFO_H
