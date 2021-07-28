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
#include QMK_KEYBOARD_H

#include "joystick.h"
#include "analog.h"
#include "print.h"
#include <math.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

////joystick config
//joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
//    [0] = JOYSTICK_AXIS_IN(F7, 900, 575, 285),
//    [1] = JOYSTICK_AXIS_IN(F6, 900, 575, 285)
//};

void joystick_task(){
	const long _xc = 488;
	const long _yc = 484;
	const long _xm = _xc - 130, _xM = 800 - _xc;
	const long _ym = _yc - 180, _yM = 860 - _yc;
	long x = analogReadPin(F7);
	long y = analogReadPin(F6);
	x = x - _xc;
	y = y - _yc;

	// 軸毎の調整
	if( x > 0 ) x = x * 200 / _xM;
	else        x = x * 200 / _xm;
	if( y > 0 ) y = y * 200 / _yM;
	else        y = y * 200 / _ym;
	x = x < -127 ? -127 : x > 127 ? 127 : x;
	y = y < -127 ? -127 : y > 127 ? 127 : y;

	joystick_status.axes[0] = -1 * x;
	joystick_status.axes[1] = -1 * y;

	//dprintf( "(%d, %d)\n", joystick_status.axes[0], joystick_status.axes[1] );

	//joystick_axes[0] = JOYSTICK_AXIS_IN(F7, 900, 575, 285);
	//joystick_axes[1] = JOYSTICK_AXIS_IN(F6, 900, 575, 285);

	joystick_status.status |= JS_UPDATED;
	send_joystick_packet(&joystick_status);
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _ARROW,
    _RIGHT,
    _LEFT,
    _SYMBOL
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

//#include "ld31.h"
#include "keymap_jp.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    // 左手用デバイスとして振る舞うつもり といっても右手も使える
    [_BASE] = LAYOUT(
            JP_TAB,  JP_1,    JP_2,     JP_3,     JP_4,    JP_5,    JP_6, \
            JP_LCTL, JP_Q,    JP_W,     JP_E,     JP_R,    JP_T,    JP_Y, \
            JP_LSFT, JP_A,    JP_S,     JP_D,     JP_F,    JP_G,    JP_H, \
            JP_LALT, JP_Z,    JP_X,     JP_C,     JP_V,    JP_B,    JP_N, \
                              TT(_LEFT), TT(_RIGHT),  LT( _ARROW, JP_SPC ) \
    ),
    [_ARROW] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, JP_UP,   XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, JP_LEFT, JP_DOWN, JP_RGHT, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                              XXXXXXX, XXXXXXX, XXXXXXX \
    ),
	//OSL(_SYMBOL),
    [_RIGHT] = LAYOUT(
            JP_ESC,  JP_0,    JP_9,    JP_8,    JP_7,    JP_6,    JP_BSPC, \
            JP_AT,   JP_P,    JP_O,    JP_I,    JP_U,    JP_Y,    JP_ENT,  \
            JP_COLN, JP_SCLN, JP_L,    JP_K,    JP_J,    JP_H,    JP_SPC,  \
            JP_BSLS, JP_SLSH, JP_DOT,  JP_COMM, JP_M,    JP_N,    XXXXXXX, \
                              _______, _______, JP_SPC \
    ),
    [_LEFT] = LAYOUT(
            JP_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, \
                              XXXXXXX, XXXXXXX,  JP_SPC \
    )
	/*
    [_SYMBOL] = LAYOUT(
            JP_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                              XXXXXXX, XXXXXXX,  JP_SPC \
    )
	*/
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
