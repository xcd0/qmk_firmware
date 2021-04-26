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
	_ARROW,
	_MIDI,   // 普通にMIDIのキーボード
	_IC      // インスタコード風キーボード
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	YSTRP,
	SYMBOL,
	NUMBER,
	ARROW,
	MIDI,
	IC,
	TOG_SYM,
	TOG_NUM,
	TOG_MID,
	TOG_IC,
	IC_Lkey01, IC_Lkey02, IC_Lkey03, IC_Lkey04,
	IC_Lkey05, IC_Lkey06, IC_Lkey07, IC_Lkey08,
	IC_Lkey09, IC_Lkey10, IC_Lkey11, IC_Lkey12,
	IC_MUTE, IC_ALL,
	IC_REVERSE, IC_SHARP,
	IC_MINER, IC_MINER7,
	IC_SUS4, IC_AUG, IC_dim, IC_m75,
	IC_Lstring01, IC_Lstring02, IC_Lstring03,
	IC_Lstring04, IC_Lstring05, IC_Lstring06,
	IC_keyUP, IC_keyDN,
	IC_MAX
};

#include "keymap_moon50.h"

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

int layer_toggle_status = 0; // 0:通常 1:記号 2:数字 3:MIDI 4:IC

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY: if (record->event.pressed) { persistent_default_layer_set(1UL<<_QWERTY); } break;
		case YSTRP: if (record->event.pressed) { persistent_default_layer_set(1UL<<_YSTRP); } break;
		case SYMBOL: if (record->event.pressed) { layer_on(_SYMBOL); } else { layer_off(_SYMBOL); } break;
		case NUMBER: if (record->event.pressed) { layer_on(_NUMBER); } else { layer_off(_NUMBER); }break;
		case ARROW: if (record->event.pressed) { layer_on(_ARROW); } else { layer_off(_ARROW); } break;
		// toggleな感じのキーコード{{{
		case TOG_SYM:
			if (record->event.pressed) {
				if(layer_toggle_status==0){
					layer_toggle_status = 1; layer_on(_SYMBOL);
				}else if(layer_toggle_status==1){
					layer_toggle_status = 0; layer_off(_SYMBOL);
				}
			}
			break;
		case TOG_NUM:
			if (record->event.pressed) {
				if(layer_toggle_status==0){
					layer_toggle_status = 2; layer_on(_NUMBER);
				}else if(layer_toggle_status==2){
					layer_toggle_status = 0; layer_off(_NUMBER);
				}
			break;
		case TOG_MID:
			if (record->event.pressed) {
				if(layer_toggle_status==0){
					layer_toggle_status = 3; layer_on(_MIDI);
				}else if(layer_toggle_status==3){
					layer_toggle_status = 0; layer_off(_MIDI);
				}
			break;
		case TOG_IC:
			if (record->event.pressed) {
				if(layer_toggle_status==0){
					layer_toggle_status = 4; layer_on(_IC);
				}else if(layer_toggle_status==4){
					layer_toggle_status = 0; layer_off(_IC);
				}
			break;
		default:
			if( keycode >= IC_Lkey01 && keycode < IC_MAX){
				if(keycode <= IC_Lkey12){
					// コード表からとってくる
				}

	IC_Lkey01, IC_Lkey02, IC_Lkey03, IC_Lkey04,
	IC_Lkey05, IC_Lkey06, IC_Lkey07, IC_Lkey08,
	IC_Lkey09, IC_Lkey10, IC_Lkey11, IC_Lkey12,
	IC_MUTE, IC_ALL,
	IC_REVERSE, IC_SHARP,
	IC_MINER, IC_MINER7,
	IC_SUS4, IC_AUG, IC_dim, IC_m75,
	IC_Lstring01, IC_Lstring02, IC_Lstring03,
	IC_Lstring04, IC_Lstring05, IC_Lstring06,
	IC_keyUP, IC_keyDN,
			}

		// }}}
	}
	return true;
}
