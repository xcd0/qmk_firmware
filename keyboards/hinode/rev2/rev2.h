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

#if 0

#define LAYOUT( \
L07, L06, L05, L04, L03, L02, L01, L00,    R00, R01, R02, R03, R04, R05, R06, R07, \
L17, L16, L15, L14, L13, L12, L11, L10,    R10, R11, R12, R13, R14, R15, R16, R17, \
L27, L26, L25, L24, L23, L22, L21, L20,    R20, R21, R22, R23, R24, R25, R26, R27, \
L37, L36, L35, L34, L33, L32, L31, L30,    R30, R31, R32, R33, R34, R35, R36, R37, \
               L44, L43, L42, L41, L40,    R40, R41, R42, R43, R44                 \
) \
{ \
  { L07, L06, L05, L04, L03, L02, L01, L00 }, \
  { L17, L16, L15, L14, L13, L12, L11, L10 }, \
  { L27, L26, L25, L24, L23, L22, L21, L20 }, \
  { L37, L36, L35, L34, L33, L32, L31, L30 }, \
  {                L44, L43, L42, L41, L40 }, \
  { R00, R01, R02, R03, R04, R05, R06, R07 }, \
  { R10, R11, R12, R13, R14, R15, R16, R17 }, \
  { R20, R21, R22, R23, R24, R25, R26, R27 }, \
  { R30, R31, R32, R33, R34, R35, R36, R37 }, \
  { R40, R41, R42, R43, R44                }  \
}

#else

#define LAYOUT( \
L07, L06, L05, L04, L03, L02, L01, L00,    R00, R01, R02, R03, R04, R05, R06, R07, \
L17, L16, L15, L14, L13, L12, L11, L10,    R10, R11, R12, R13, R14, R15, R16, R17, \
L27, L26, L25, L24, L23, L22, L21, L20,    R20, R21, R22, R23, R24, R25, R26, R27, \
L37, L36, L35, L34, L33, L32, L31, L30,    R30, R31, R32, R33, R34, R35, R36, R37, \
               L44, L43, L42, L41, L40,    R40, R41, R42, R43, R44                 \
) \
{ \
  { L00, L01, L02, L03, L04, L05, L06, L07 }, \
  { L10, L11, L12, L13, L14, L15, L16, L17 }, \
  { L20, L21, L22, L23, L24, L25, L26, L27 }, \
  { L30, L31, L32, L33, L34, L35, L36, L37 }, \
  { L40, L41, L42, L43, L44                }, \
  { R00, R01, R02, R03, R04, R05, R06, R07 }, \
  { R10, R11, R12, R13, R14, R15, R16, R17 }, \
  { R20, R21, R22, R23, R24, R25, R26, R27 }, \
  { R30, R31, R32, R33, R34, R35, R36, R37 }, \
  { R40, R41, R42, R43, R44                }  \
}

#endif
