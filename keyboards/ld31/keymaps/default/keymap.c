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

/*
#include "joystick.h"
#include "analog.h"

//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(F7, 900, 575, 285),
    [1] = JOYSTICK_AXIS_IN(F6, 900, 575, 285)
};

void joystick_task(){
	//joystick_status.axes[0] = analogReadPin(F7)/4 - 128;
	//joystick_status.axes[1] = analogReadPin(F6)/4 - 128;

	joystick_axes[0] = JOYSTICK_AXIS_IN(F7, 900, 575, 285);
	joystick_axes[1] = JOYSTICK_AXIS_IN(F6, 900, 575, 285);

	joystick_status.status |= JS_UPDATED;
	send_joystick_packet(&joystick_status);
}
*/

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
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
            KC_TAB,  KC_0,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5, \
            KC_LCTL, KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_Y, \
            KC_LSFT, KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    KC_H, \
            KC_LALT, KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N, \
                              XXXXXXX,  XXXXXXX,  KC_SPC \
    )
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
