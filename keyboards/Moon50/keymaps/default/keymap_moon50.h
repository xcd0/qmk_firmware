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
            JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_TAB,                    /**/                      XXXXXXX, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_LGUI, JP_MHEN, JP_HOME, /**/ JP_END,  JP_HENK,    XXXXXXX,  JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
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
                                       _______, XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_ARROW] = LAYOUT(
            DEBUG,   XXXXXXX, DF(_IC),  XXXXXXX, DF(_YSTRP), DF(_QWERTY),           /**/                   XXXXXXX, XXXXXXX, JP_BTN1, JP_BTN2, JP_BTN3, JP_WH_U,    \
            XXXXXXX, XXXXXXX, DF(_MIDI),XXXXXXX, DF(IC),  DF(MIDI),                 /**/                   XXXXXXX, JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX,    \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D,    \
                                       XXXXXXX, XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  _______, JP_BSPC, JP_ENT,  JP_DEL                                 \
    ),
    [_YSTRP] = LAYOUT(
            JP_Q,    JP_W,    JP_D,    JP_F,    JP_G,    JP_ESC,                    /**/                      JP_LALT, JP_Y,    JP_S,    JP_T,    JP_R,    JP_P,       \
            JP_A,    JP_O,    JP_E,    JP_U,    JP_I,    JP_TAB,                    /**/                      XXXXXXX, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_LGUI, JP_MHEN, JP_HOME, /**/ JP_END,  JP_HENK,    XXXXXXX, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
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
            MI_0001, MI_0004, MI_0007, MI_0010, MI_0013, MI_0016,                    /**/                     MI_0029, MI_0022, MI_0025, MI_0028, MI_0031, MI_0034,      \
            MI_0002, MI_0005, MI_0008, MI_0011, MI_0014, MI_0017,                    /**/                     MI_0020, MI_0023, MI_0026, MI_0029, MI_0032, MI_0035,      \
            MI_0003, MI_0006, MI_0009, MI_0012, MI_0015, MI_0018, MI_DN,   MI_UP,    /**/ DF(_QWERTY), XXXXXXX, MI_0021, MI_0024, MI_0027, MI_0030, MI_0033, MI_0036,      \
                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/     XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX                                 \
    ),
	// IC_MUTE, IC_REVERSE,
	// IC_Cn_MEJAR, IC_Cn_MINOR, IC_Cn_7, IC_Cn_MEJAR7, IC_Cn_MINOR7, IC_Cn_MINORMEJOR7, IC_Cn_DIMINISH, IC_Cn_AUGUMENT, IC_Cn_SUSTAIN,
	// IC_Cs_MEJAR, IC_Cs_MINOR, IC_Cs_7, IC_Cs_MEJAR7, IC_Cs_MINOR7, IC_Cs_MINORMEJOR7, IC_Cs_DIMINISH, IC_Cs_AUGUMENT, IC_Cs_SUSTAIN,
	// IC_Dn_MEJAR, IC_Dn_MINOR, IC_Dn_7, IC_Dn_MEJAR7, IC_Dn_MINOR7, IC_Dn_MINORMEJOR7, IC_Dn_DIMINISH, IC_Dn_AUGUMENT, IC_Dn_SUSTAIN,
	// IC_Ds_MEJAR, IC_Ds_MINOR, IC_Ds_7, IC_Ds_MEJAR7, IC_Ds_MINOR7, IC_Ds_MINORMEJOR7, IC_Ds_DIMINISH, IC_Ds_AUGUMENT, IC_Ds_SUSTAIN,
	// IC_En_MEJAR, IC_En_MINOR, IC_En_7, IC_En_MEJAR7, IC_En_MINOR7, IC_En_MINORMEJOR7, IC_En_DIMINISH, IC_En_AUGUMENT, IC_En_SUSTAIN,
	// IC_Fn_MEJAR, IC_Fn_MINOR, IC_Fn_7, IC_Fn_MEJAR7, IC_Fn_MINOR7, IC_Fn_MINORMEJOR7, IC_Fn_DIMINISH, IC_Fn_AUGUMENT, IC_Fn_SUSTAIN,
	// IC_Fs_MEJAR, IC_Fs_MINOR, IC_Fs_7, IC_Fs_MEJAR7, IC_Fs_MINOR7, IC_Fs_MINORMEJOR7, IC_Fs_DIMINISH, IC_Fs_AUGUMENT, IC_Fs_SUSTAIN,
	// IC_Gn_MEJAR, IC_Gn_MINOR, IC_Gn_7, IC_Gn_MEJAR7, IC_Gn_MINOR7, IC_Gn_MINORMEJOR7, IC_Gn_DIMINISH, IC_Gn_AUGUMENT, IC_Gn_SUSTAIN,
	// IC_Gs_MEJAR, IC_Gs_MINOR, IC_Gs_7, IC_Gs_MEJAR7, IC_Gs_MINOR7, IC_Gs_MINORMEJOR7, IC_Gs_DIMINISH, IC_Gs_AUGUMENT, IC_Gs_SUSTAIN,
	// IC_An_MEJAR, IC_An_MINOR, IC_An_7, IC_An_MEJAR7, IC_An_MINOR7, IC_An_MINORMEJOR7, IC_An_DIMINISH, IC_An_AUGUMENT, IC_An_SUSTAIN,
	// IC_As_MEJAR, IC_As_MINOR, IC_As_7, IC_As_MEJAR7, IC_As_MINOR7, IC_As_MINORMEJOR7, IC_As_DIMINISH, IC_As_AUGUMENT, IC_As_SUSTAIN,
	// IC_Bn_MEJAR, IC_Bn_MINOR, IC_Bn_7, IC_Bn_MEJAR7, IC_Bn_MINOR7, IC_Bn_MINORMEJOR7, IC_Bn_DIMINISH, IC_Bn_AUGUMENT, IC_Bn_SUSTAIN,
    [_IC] = LAYOUT(
            XXXXXXX, IC_Bn_MINOR, IC_Ds_MEJAR, IC_As_MEJAR, XXXXXXX, XXXXXXX,                              /**/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
            XXXXXXX, IC_Fn_MEJAR, IC_Gn_MEJAR, IC_An_MINOR, XXXXXXX, XXXXXXX,                              /**/                   XXXXXXX, IC_string01, IC_string03, IC_string05, XXXXXXX, XXXXXXX,    \
            XXXXXXX, IC_Cn_MEJAR, IC_Dn_MINOR, IC_En_MINOR, XXXXXXX, IC_RESET, IC_OCTAVE_DN, IC_OCTAVE_UP, /**/ DF(_QWERTY), XXXXXXX, XXXXXXX, IC_string02, IC_string04, IC_string06, XXXXXXX, XXXXXXX,    \
                                                   XXXXXXX, IC_MUTE, IC_PLAY_CODE, IC_NOTE_DN, IC_NOTE_UP, /**/     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                                \
    )
};

