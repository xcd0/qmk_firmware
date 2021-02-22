#pragma once

#include "helix.h"

#ifndef SPLIT_KEYBOARD
    extern bool is_helix_master(void);
    #define is_keyboard_master() is_helix_master()
#endif

// Each keymap.c should use is_keyboard_master() instead of 'is_master', 'has_usb()'.
// But keep 'is_master' for a while for backwards compatibility
//  for the old keymap.c.
extern uint8_t is_master; // 'is_master' will be obsolete, it is recommended to use 'is_keyboard_master ()' instead.
#define has_usb() is_keyboard_master()

#define ___ KC_NO
#define LAYOUT( \
    L06, L05, L04, L03, L02,                       R02, R03, R04, R05, R06, \
    L16, L15, L14, L13, L12,                       R12, R13, R14, R15, R16, \
    L26, L25, L24, L23, L22, L01, L00,   R00, R01, R22, R23, R24, R25, R26, \
                   L21, L11, L20, L10,   R10, R20, R11, R21 \
) { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, L26 }, \
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, R26 }  \
}
