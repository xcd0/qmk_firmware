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

#include "keymap_jp.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
            JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_HOME,                   /**/                   JP_END,  JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,       \
            JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_MHEN,                   /**/                   JP_HENK, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    XXXXXXX, JP_TAB, JP_ESC,   /**/ JP_LGUI, JP_LALT, XXXXXXX, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_SYMBOL] = LAYOUT(
            JP_TILD, JP_UNDS, JP_DQT,  JP_QUOT, JP_GRV,  XXXXXXX,                   /**/                   XXXXXXX, JP_LPRN, JP_LT,   JP_LCBR, JP_LBRC, JP_AT,      \
            JP_PLUS, JP_MINS, JP_ASTR, JP_EQL,  JP_DLR,  XXXXXXX,                   /**/                   XXXXXXX, JP_RPRN, JP_GT,   JP_RCBR, JP_RBRC, JP_COLN,    \
            XXXXXXX, JP_EXLM, JP_QUES, JP_HASH, JP_PERC, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, XXXXXXX, JP_AMPR, JP_PIPE, JP_CIRC, JP_BKSL,    \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_NUMBER] = LAYOUT(
            JP_F1,   JP_F2,   JP_F3,   JP_F4,   JP_F5,   JP_F6,                     /**/                   JP_SLSH, JP_ASTR, JP_7,    JP_8,    JP_9,    XXXXXXX,    \
            JP_F7,   JP_F8,   JP_F9,   JP_F10,  JP_F11,  JP_F12,                    /**/                   JP_MINS, JP_PLUS, JP_4,    JP_5,    JP_6,    XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, YSTRP,    QWERTY, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, JP_EQL,  JP_0,    JP_1,    JP_2,    JP_3,    JP_DOT,     \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_ARROW] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, XXXXXXX, JP_BTN1, JP_BTN2, JP_BTN3, JP_WH_U,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D,    \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    )
};

