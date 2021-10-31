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
            JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_ESC,                    /**/                      JP_LALT, JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,
            JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_TAB,                    /**/                      XXXXXXX, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_MHEN, JP_INS,  JP_HOME, /**/ JP_END,  JP_LGUI,    JP_HENK,  JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,
                              TT(_NUMBER),  TT(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL
                              //TT(_NUMBER),  TT(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ DF(_FF),  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL
    ),
    [_SYMBOL] = LAYOUT(
            JP_TILD, JP_UNDS, JP_DQT,  JP_QUOT, JP_GRV,  JP_ESC,                    /**/                   JP_LALT, JP_LPRN, JP_LT,   JP_LCBR, JP_LBRC, JP_AT,
            JP_PLUS, JP_MINS, JP_ASTR, JP_EQL,  JP_DLR,  JP_TAB,                    /**/                   XXXXXXX, JP_RPRN, JP_GT,   JP_RCBR, JP_RBRC, JP_COLN,
            RESET,   JP_EXLM, JP_QUES, JP_HASH, JP_PERC, JP_LGUI, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, XXXXXXX, JP_AMPR, JP_PIPE, JP_CIRC, JP_BKSL,
                                       XXXXXXX, _______, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL
    ),
    [_NUMBER] = LAYOUT(
            JP_F1,   JP_F2,   JP_F3,   JP_F4,   JP_F5,   JP_F6,                     /**/                   JP_SLSH, JP_ASTR, JP_7,    JP_8,    JP_9,    XXXXXXX,
            JP_F7,   JP_F8,   JP_F9,   JP_F10,  JP_F11,  JP_F12,                    /**/                   JP_MINS, JP_PLUS, JP_4,    JP_5,    JP_6,    XXXXXXX,
            RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, JP_EQL,  JP_0,    JP_1,    JP_2,    JP_3,    JP_DOT,
                                       _______, XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL
    ),
    [_ARROW] = LAYOUT(
            DEBUG,   XXXXXXX, DF(_IC),  XXXXXXX, DF(_YSTRP), DF(_QWERTY),           /**/                   XXXXXXX, XXXXXXX, JP_BTN1, JP_BTN2, JP_BTN3, JP_WH_U,
            XXXXXXX, XXXXXXX, DF(_MIDI),XXXXXXX, XXXXXXX, DF(_FF),                  /**/                   XXXXXXX, JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX,
            RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_TAB,  JP_ESC,  /**/ JP_LGUI, JP_LALT, XXXXXXX, JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D,
                                       XXXXXXX, XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  _______, JP_BSPC, JP_ENT,  JP_DEL
    ),
    [_YSTRP] = LAYOUT(
            JP_Q,    JP_W,    JP_D,    JP_F,    JP_G,    JP_ESC,                    /**/                      JP_LALT, JP_Y,    JP_S,    JP_T,    JP_R,    JP_P,
            JP_A,    JP_O,    JP_E,    JP_U,    JP_I,    JP_TAB,                    /**/                      XXXXXXX, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,
            JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_LGUI, JP_MHEN, JP_HOME, /**/ JP_END,  JP_HENK,    XXXXXXX, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,
                              TT(_NUMBER),  TT(_SYMBOL), JP_SPC,  JP_LSFT, JP_LCTL, /**/ JP_INS,  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL
    ),
	// 左手用デバイスとして振る舞うつもり といっても右手も使える
	// 割り当てないキー
	// JP_LGUI JP_HOME JP_END
	// TT(_NUMBER) TT(_SYMBOL)
    [_FF] = LAYOUT(
            JP_Q,    JP_W,    JP_E,    JP_R,   JP_T,    JP_Y,                   /**/                        JP_GT, JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,       \
            JP_A,    JP_S,    JP_D,    JP_F,   JP_G,    JP_H,                     /**/                        JP_RCBR, JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN,    \
            JP_Z,    JP_X,    JP_C,    JP_V,   JP_B,    JP_N,    JP_MHEN, JP_ESC,  /**/ XXXXXXX,  JP_HENK, JP_RBRC,  JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,    \
                                       JP_SPC, JP_LALT, JP_LCTL, JP_LSFT, JP_TAB,  /**/ DF(_QWERTY),  TT(_ARROW), JP_BSPC, JP_ENT,  JP_DEL                                 \
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
	// IC_Cn_MAJOR, IC_Cn_MINOR, // IC_Cs_MAJOR, IC_Cs_MINOR, // IC_Dn_MAJOR, IC_Dn_MINOR, // IC_Ds_MAJOR, IC_Ds_MINOR
	// IC_En_MAJOR, IC_En_MINOR, // IC_Fn_MAJOR, IC_Fn_MINOR, // IC_Fs_MAJOR, IC_Fs_MINOR, // IC_Gn_MAJOR, IC_Gn_MINOR
	// IC_Gs_MAJOR, IC_Gs_MINOR, // IC_An_MAJOR, IC_An_MINOR, // IC_As_MAJOR, IC_As_MINOR, // IC_Bn_MAJOR, IC_Bn_MINOR
	// IC_7th, IC_9th,IC_M7, IC_dim, IC_aug, IC_sus4, IC_m7sub5, IC_REVERSE, IC_SHARP,
    [_IC] = LAYOUT(
            IC_m7sub5, IC_Bn_MINOR, IC_Ds_MAJOR, IC_As_MAJOR, IC_7th,     IC_M7,                               /**/                       IC_key01, IC_key04, IC_key07, IC_key10, IC_key13, IC_key16, \
            IC_SHARP,  IC_Fn_MAJOR, IC_Gn_MAJOR, IC_An_MINOR, IC_REVERSE, IC_sus4,                             /**/                       IC_key02, IC_key05, IC_key08, IC_key11, IC_key14, IC_key17, \
            IC_dim,    IC_Cn_MAJOR, IC_Dn_MINOR, IC_En_MINOR, IC_9th,     IC_aug,  IC_OCTAVE_DN, IC_OCTAVE_UP, /**/ DF(_QWERTY), XXXXXXX, IC_key03, IC_key06, IC_key09, IC_key12, IC_key15, IC_key18, \
                                                    IC_RESET, IC_MUTE,  IC_PLAY_CODE, IC_NOTE_DN, IC_NOTE_UP,  /**/ IC_string01, IC_string02, IC_string03, IC_string04, IC_string05                   \
    )
};

