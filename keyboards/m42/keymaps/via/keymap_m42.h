/* Copyright 2021 xcd0 
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

#include "keymap_jp.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
      JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                                          JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    \
      JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                                          JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, \
      JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,   JP_ESC,  JP_LALT,    JP_INS, JP_LGUI, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, \
                                 JP_HOME, JP_SPC, JP_LSFT, JP_LCTL,    JP_BSPC, JP_ENT,  JP_DEL,  JP_END                              \
      ),
  [_NUMBER] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    \
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
      KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,  JP_AMPR, JP_PIPE, JP_EQL,  JP_PLUS, JP_MINS, JP_ASTR, JP_SLSH, \
                                 XXXXXXX, JP_SPC, JP_LSFT, JP_LCTL, JP_EXLM, JP_QUES, JP_TILD, JP_PERC \
      ),
  [_SYMBOL] = LAYOUT( \
      _______, _______, JP_PSCR, JP_SCLK, JP_PAUS,                                       JP_LPRN, JP_RPRN, JP_LCBR, JP_RCBR, JP_AT,   \
      _______, _______, JP_INS,  JP_HOME, JP_PGUP,                                       JP_LBRC, JP_RBRC, JP_LT,   JP_GT,   JP_COLN, \
      _______, _______, JP_DEL,  JP_END,  JP_PGDN, _______,  _______,   JP_HASH, JP_DLR,  JP_BQT,  JP_QT,   JP_DQT,  JP_UNDS, JP_BSLS, \
                                 XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),
  [_ARROW] = LAYOUT( \
      XXXXXXX, JP_MS_U, XXXXXXX, JP_WH_U, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      JP_MS_L, JP_MS_D, JP_MS_R, JP_WH_D, XXXXXXX,                                     JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX, \
      JP_BTN1, JP_BTN3, JP_BTN2, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                        XXXXXXX, QWERTY,  YSTRP,   RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX \
      )
};




