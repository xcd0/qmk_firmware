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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_QWERTY,
	_YSTRP,
	_SYMBOL,
	_NUMBER,
	_ARROW
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	YSTRP,
	SYMBOL,
	NUMBER,
	ARROW
};

#include "keymap_moon50.h"

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY: if (record->event.pressed) { persistent_default_layer_set(1UL<<_QWERTY); } break;
		case YSTRP: if (record->event.pressed) { persistent_default_layer_set(1UL<<_YSTRP); } break;
		case NUMBER: if (record->event.pressed) { layer_on(_NUMBER); } else { layer_off(_NUMBER); }break;
		case ARROW: if (record->event.pressed) { layer_on(_ARROW); } else { layer_off(_ARROW); } break;
		case SYMBOL: if (record->event.pressed) { layer_on(_SYMBOL); } else { layer_off(_SYMBOL); } break;
	}
	return true;
}
