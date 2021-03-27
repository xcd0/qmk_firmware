/* Copyright 2021 xcd0
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define NOP KC_NO

#define LAYOUT( \
  L00, L01, L02, L03, L04,                                  R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,                                  R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,                                  R20, R21, R22, R23, R24, \
                           L32, L33,              R31, R32,                          \
                      L41, L42, L43, L44,    R40, R41, R42, R43,                     \
                      L51, L52, L53, L54,    R50, R51, R52, R53                      \
  ) \
  { \
    { L00, L01, L02, L03, L04,    R00, R01, R02, R03, R04 }, \
    { L10, L11, L12, L13, L14,    R10, R11, R12, R13, R14 }, \
    { L20, L21, L22, L23, L24,    R20, R21, R22, R23, R24 }, \
    { NOP, NOP, L32, L33, NOP,    NOP, R31, R32, NOP, NOP }, \
    { NOP, L41, L42, L43, L44,    R40, R41, R42, R43, NOP }, \
    { NOP, L51, L52, L53, L54,    R50, R51, R52, R53, NOP }  \
 }
