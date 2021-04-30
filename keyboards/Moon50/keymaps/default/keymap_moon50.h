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
            JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_ESC,                    /**/                      JP_LALT, JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,       \
            JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_TAB,                    /**/                    TG(_IC),   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_LGUI, JP_MHEN, JP_HOME, /**/ JP_END,  JP_HENK,  TG(_MIDI), JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
                              TT(_NUMBER),  TT(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_SYMBOL] = LAYOUT(
            JP_TILD, JP_UNDS, JP_DQT,  JP_QUOT, JP_GRV,  JP_ESC,                    /**/                   JP_LALT, JP_LPRN, JP_LT,   JP_LCBR, JP_LBRC, JP_AT,      \
            JP_PLUS, JP_MINS, JP_ASTR, JP_EQL,  JP_DLR,  JP_TAB,                    /**/                   XXXXXXX, JP_RPRN, JP_GT,   JP_RCBR, JP_RBRC, JP_COLN,    \
            XXXXXXX, JP_EXLM, JP_QUES, JP_HASH, JP_PERC, JP_LGUI, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, XXXXXXX, JP_AMPR, JP_PIPE, JP_CIRC, JP_BKSL,    \
                                       XXXXXXX, _______, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_NUMBER] = LAYOUT(
            JP_F1,   JP_F2,   JP_F3,   JP_F4,   JP_F5,   JP_F6,                     /**/                   JP_SLSH, JP_ASTR, JP_7,    JP_8,    JP_9,    XXXXXXX,    \
            JP_F7,   JP_F8,   JP_F9,   JP_F10,  JP_F11,  JP_F12,                    /**/                   JP_MINS, JP_PLUS, JP_4,    JP_5,    JP_6,    XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, JP_EQL,  JP_0,    JP_1,    JP_2,    JP_3,    JP_DOT,     \
                                        _______, XXXXXX, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_ARROW] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_YSTRP), DF(_QWERTY),            /**/                   XXXXXXX, XXXXXXX, JP_BTN1, JP_BTN2, JP_BTN3, JP_WH_U,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(IC),  DF(MIDI),                  /**/                   XXXXXXX, JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D,    \
                              MO(_NUMBER),  MO(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_YSTRP] = LAYOUT(
            JP_Q,    JP_W,    JP_D,    JP_F,    JP_G,    JP_ESC,                    /**/                      JP_LALT, JP_Y,    JP_S,    JP_T,    JP_R,    JP_P,       \
            JP_A,    JP_O,    JP_E,    JP_U,    JP_I,    JP_TAB,                    /**/                    TG(_IC),   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_LGUI, JP_MHEN, JP_HOME, /**/ JP_END,  JP_HENK,  TG(_MIDI), JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
                              TT(_NUMBER),  TT(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
	// こうしたい
	//  2eb, 2gb, 2a,  3c,  3eb, 3gb,    3a,  4c,  4eb, 4gb, 4a,  5c,
	//  2e,  2g,  2bs, 3db, 3e,  3g,     3bs, 4db, 4e,  4g,  4bs, 5db,
	//  2f,  2ab, 2b,  3d,  3f,  3ab,    3b,  4d , 4f,  4ab, 4b,  5d,
	//
	//  2eb = 2ds は midiの39
	//  5d は midiの74
    [_MIDI] = LAYOUT(
            MI_0001, MI_0004, MI_0007, MI_0010, MI_0013, MI_0016,                   /**/                   MI_0029, MI_0022, MI_0025, MI_0028, MI_0031, MI_0034,      \
            MI_0002, MI_0005, MI_0008, MI_0011, MI_0014, MI_0017,                   /**/                   MI_0020, MI_0023, MI_0026, MI_0029, MI_0032, MI_0035,      \
            MI_0003, MI_0006, MI_0009, MI_0012, MI_0015, MI_0018, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, MI_0021, MI_0024, MI_0027, MI_0030, MI_0033, MI_0036,      \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_IC] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
                                       JP_SPC,  JP_LSFT, JP_LCTL, SYMBOL,  NUMBER,  /**/ JP_INS,  ARROW,   JP_BSPC, JP_ENT,  JP_DEL                                 \
    )
};

