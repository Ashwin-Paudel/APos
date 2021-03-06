//
// Created by Ashwin Paudel on 2021-03-06.
//

#ifndef APOS_PRINTASCII_H
#define APOS_PRINTASCII_H

#include "print.h"

using namespace apos::print;

void APOSLogo(int item) {
    if (item == 0) {
        printf(R""""(
      __         _______    ______    ________
     /""\       |   __ "\  /    " \  /"       )
    /    \      (. |__) :)// ____  \(:   \___/
   /' /\  \     |:  ____//  /    ) :)\___  \
  //  __'  \    (|  /   (: (____/ //  __/  \\
 /   /  \\  \  /|__/ \   \        /  /" \   :)
(___/    \___)(_______)   \"_____/  (_______/

)"""");
    } else if (item == 1) {
        printf(R""""(
           _____   ____   _____
     /\   |  __ \ / __ \ / ____|
    /  \  | |__) | |  | | (___
   / /\ \ |  ___/| |  | |\___ \
  / ____ \| |    | |__| |____) |
 /_/    \_\_|     \____/|_____/
               )"""");
    } else if (item == 2) {
        printf(R""""(
_____/\\\\\\\\\_____/\\\\\\\\\\\\\_________/\\\\\__________/\\\\\\\\\\\___
 ___/\\\\\\\\\\\\\__\/\\\/////////\\\_____/\\\///\\\______/\\\/////////\\\_
  __/\\\/////////\\\_\/\\\_______\/\\\___/\\\/__\///\\\___\//\\\______\///__
   _\/\\\_______\/\\\_\/\\\\\\\\\\\\\/___/\\\______\//\\\___\////\\\_________
    _\/\\\\\\\\\\\\\\\_\/\\\/////////____\/\\\_______\/\\\______\////\\\______
     _\/\\\/////////\\\_\/\\\_____________\//\\\______/\\\__________\////\\\___
      _\/\\\_______\/\\\_\/\\\______________\///\\\__/\\\_____/\\\______\//\\\__
       _\/\\\_______\/\\\_\/\\\________________\///\\\\\/_____\///\\\\\\\\\\\/___
        _\///________\///__\///___________________\/////_________\///////////_____
               )"""");
    } else if (item == 3) {
        printf(R""""(
     **     *******    *******    ********
    ****   /**////**  **/////**  **//////
   **//**  /**   /** **     //**/**
  **  //** /******* /**      /**/*********
 **********/**////  /**      /**////////**
/**//////**/**      //**     **        /**
/**     /**/**       //*******   ********
//      // //         ///////   ////////
               )"""");
    } else if (item == 4) {
        printf(R""""(
      >>       >======>       >===>        >=>>=>
     >>=>      >=>    >=>   >=>    >=>   >=>    >=>
    >> >=>     >=>    >=> >=>        >=>  >=>
   >=>  >=>    >======>   >=>        >=>    >=>
  >=====>>=>   >=>        >=>        >=>       >=>
 >=>      >=>  >=>          >=>     >=>  >=>    >=>
>=>        >=> >=>            >===>        >=>>=>
               )"""");
    } else if (item == 5) {
        printf(R""""(
       d8888 8888888b.   .d88888b.   .d8888b.
      d88888 888   Y88b d88P" "Y88b d88P  Y88b
     d88P888 888    888 888     888 Y88b.
    d88P 888 888   d88P 888     888  "Y888b.
   d88P  888 8888888P"  888     888     "Y88b.
  d88P   888 888        888     888       "888
 d8888888888 888        Y88b. .d88P Y88b  d88P
d88P     888 888         "Y88888P"   "Y8888P"
               )"""");
    } else if (item == 6) {
        printf(R""""(
      db      `7MM"""Mq.   .g8""8q.    .M"""bgd
     ;MM:       MM   `MM..dP'    `YM. ,MI    "Y
    ,V^MM.      MM   ,M9 dM'      `MM `MMb.
   ,M  `MM      MMmmdM9  MM        MM   `YMMNq.
   AbmmmqMA     MM       MM.      ,MP .     `MM
  A'     VML    MM       `Mb.    ,dP' Mb     dM
.AMA.   .AMMA..JMML.       `"bmmd"'   P"Ybmmd"
               )"""");
    } else if (item == 7) {
        printf(R""""(
 ______  ____    _____   ____
/\  _  \/\  _`\ /\  __`\/\  _`\
\ \ \L\ \ \ \L\ \ \ \/\ \ \,\L\_\
 \ \  __ \ \ ,__/\ \ \ \ \/_\__ \
  \ \ \/\ \ \ \/  \ \ \_\ \/\ \L\ \
   \ \_\ \_\ \_\   \ \_____\ `\____\
    \/_/\/_/\/_/    \/_____/\/_____/
               )"""");
    } else if (item == 8) {
        printf(R""""(
    _   ____  ___   ____
   / \ / _  |/ _ \ |___ \
  / _ | (_| | | | |/ ___/
 / ___ \__  | |_| | (___
/_/   \_\ |_|\___/ \____|
               )"""");
    } else if (item == 9) {
        printf(R""""(
           ,ggg,  ,ggggggggggg,     _,gggggg,_          ,gg,
          dP""8I dP"""88""""""Y8, ,d8P""d8P"Y8b,       i8""8i
         dP   88 Yb,  88      `8b,d8'   Y8   "8b,dP    `8,,8'
        dP    88  `"  88      ,8Pd8'    `Ybaaad88P'     `88'
       ,8'    88      88aaaad8P" 8P       `""""Y8       dP"8,
       d88888888      88"""""    8b            d8      dP' `8a
 __   ,8"     88      88         Y8,          ,8P     dP'   `Yb
dP"  ,8P      Y8      88         `Y8,        ,8P' _ ,dP'     I8
Yb,_,dP       `8b,    88          `Y8b,,__,,d8P'  "888,,____,dP
 "Y8P"         `Y8    88            `"Y8888P"'    a8P"Y88888P"
               )"""");
    } else if (item == 10) {
        printf(R""""(
______________________________
___    |__  __ \_  __ \_  ___/
__  /| |_  /_/ /  / / /____ \
_  ___ |  ____// /_/ /____/ /
/_/  |_/_/     \____/ /____/
               )"""");
    }
}


#endif //APOS_PRINTASCII_H
