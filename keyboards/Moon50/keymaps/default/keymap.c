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
	_SYMBOL,
	_NUMBER,
	_ARROW,
	_YSTRP,  // 独自キー配列YSTRP
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
	MI_NOTEMIN,
	MI_NOTE001 = MI_NOTEMIN, MI_NOTE002, MI_NOTE003, MI_NOTE004, MI_NOTE005, MI_NOTE006,
	MI_NOTE007, MI_NOTE008, MI_NOTE009, MI_NOTE010, MI_NOTE011, MI_NOTE012,
	MI_NOTE013, MI_NOTE014, MI_NOTE015, MI_NOTE016, MI_NOTE017, MI_NOTE018,
   	MI_NOTE019, MI_NOTE020, MI_NOTE021, MI_NOTE022, MI_NOTE023, MI_NOTE024,
   	MI_NOTE025, MI_NOTE026, MI_NOTE027, MI_NOTE028, MI_NOTE029, MI_NOTE030,
   	MI_NOTE031, MI_NOTE032, MI_NOTE033, MI_NOTE034, MI_NOTE035, MI_NOTE036,
	MI_NOTEMAX,
	IC_MIN,
	IC_key01 = IC_MIN, IC_key02, IC_key03, IC_key04, IC_key05, IC_key06, IC_key07, IC_key08, IC_key09, IC_key10, IC_key11, IC_key12,
	IC_MUTE, IC_REVERSE,
	IC_Cn_MEJAR, IC_Cn_MINOR, IC_Cn_7, IC_Cn_MEJAR7, IC_Cn_MINOR7, IC_Cn_MINORMEJOR7, IC_Cn_DIMINISH, IC_Cn_AUGUMENT, IC_Cn_SUSTAIN,
	IC_Cs_MEJAR, IC_Cs_MINOR, IC_Cs_7, IC_Cs_MEJAR7, IC_Cs_MINOR7, IC_Cs_MINORMEJOR7, IC_Cs_DIMINISH, IC_Cs_AUGUMENT, IC_Cs_SUSTAIN,
	IC_Dn_MEJAR, IC_Dn_MINOR, IC_Dn_7, IC_Dn_MEJAR7, IC_Dn_MINOR7, IC_Dn_MINORMEJOR7, IC_Dn_DIMINISH, IC_Dn_AUGUMENT, IC_Dn_SUSTAIN,
	IC_Ds_MEJAR, IC_Ds_MINOR, IC_Ds_7, IC_Ds_MEJAR7, IC_Ds_MINOR7, IC_Ds_MINORMEJOR7, IC_Ds_DIMINISH, IC_Ds_AUGUMENT, IC_Ds_SUSTAIN,
	IC_En_MEJAR, IC_En_MINOR, IC_En_7, IC_En_MEJAR7, IC_En_MINOR7, IC_En_MINORMEJOR7, IC_En_DIMINISH, IC_En_AUGUMENT, IC_En_SUSTAIN,
	IC_Fn_MEJAR, IC_Fn_MINOR, IC_Fn_7, IC_Fn_MEJAR7, IC_Fn_MINOR7, IC_Fn_MINORMEJOR7, IC_Fn_DIMINISH, IC_Fn_AUGUMENT, IC_Fn_SUSTAIN,
	IC_Fs_MEJAR, IC_Fs_MINOR, IC_Fs_7, IC_Fs_MEJAR7, IC_Fs_MINOR7, IC_Fs_MINORMEJOR7, IC_Fs_DIMINISH, IC_Fs_AUGUMENT, IC_Fs_SUSTAIN,
	IC_Gn_MEJAR, IC_Gn_MINOR, IC_Gn_7, IC_Gn_MEJAR7, IC_Gn_MINOR7, IC_Gn_MINORMEJOR7, IC_Gn_DIMINISH, IC_Gn_AUGUMENT, IC_Gn_SUSTAIN,
	IC_Gs_MEJAR, IC_Gs_MINOR, IC_Gs_7, IC_Gs_MEJAR7, IC_Gs_MINOR7, IC_Gs_MINORMEJOR7, IC_Gs_DIMINISH, IC_Gs_AUGUMENT, IC_Gs_SUSTAIN,
	IC_An_MEJAR, IC_An_MINOR, IC_An_7, IC_An_MEJAR7, IC_An_MINOR7, IC_An_MINORMEJOR7, IC_An_DIMINISH, IC_An_AUGUMENT, IC_An_SUSTAIN,
	IC_As_MEJAR, IC_As_MINOR, IC_As_7, IC_As_MEJAR7, IC_As_MINOR7, IC_As_MINORMEJOR7, IC_As_DIMINISH, IC_As_AUGUMENT, IC_As_SUSTAIN,
	IC_Bn_MEJAR, IC_Bn_MINOR, IC_Bn_7, IC_Bn_MEJAR7, IC_Bn_MINOR7, IC_Bn_MINORMEJOR7, IC_Bn_DIMINISH, IC_Bn_AUGUMENT, IC_Bn_SUSTAIN,
	IC_string01, IC_string02, IC_string03, IC_string04, IC_string05, IC_string06,
	IC_keyUP, IC_keyDN,
	IC_CODE_PLAY,
	IC_MAX
};

#include "keymap_moon50.h"

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// uint8_t layer_toggle_status = 0; // 0:通常 1:記号 2:数字 3:MIDI 4:IC
// uint8_t midi_channel = 0;        // MIDIのチャンネル

uint8_t midiOffset = 39; // MI_NOTE_001を39(D#2)にする

#include "icDefineCode.h"
IcData icData;
//icData.icCodeOffset[0] -> Mejorコード4音のオフセット値


// 単音を鳴らす
void PlayNote(
	uint8_t note,         // midi のノート番号
	uint8_t midi_channel, // midi のチャンネル番号
	bool    pressed       // キーが押されているか
){
	if(note >= 0 && note <= 127) midi_send_noteon(&midi_device, midi_channel, note, pressed ? 127 : 0);
}

// 設定された和音を鳴らす
void PlayCode(
	IcData* icData,                 // 設定
	uint8_t      codeNote,          // 鳴らしたい和音の一番低い音
	uint8_t      icCodeNoteOffset,  // 半音単位でのオフセット いわゆる変調
	uint8_t*     icCodeOffsetArray, // 和音の個々の単音についてのオフセット値の配列へのポインタ
	uint8_t      midi_channel,      // midiのチャンネル
	keyrecord_t* record             // キー入力状態
){
	uint8_t lowestNote = codeNote + icCodeNoteOffset;
	for(uint8_t i = 0; i < 6; i++){ if(codeArray[i] != -1) PlayNote( lowestNote + codeArray[i], midi_channel, record->event.pressed ); }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		//case QWERTY: if (record->event.pressed) { persistent_default_layer_set(1UL<<_QWERTY); } break;
		//case YSTRP: if (record->event.pressed) { persistent_default_layer_set(1UL<<_YSTRP); } break;
		//case SYMBOL: if (record->event.pressed) { layer_on(_SYMBOL); } else { layer_off(_SYMBOL); } break;
		//case NUMBER: if (record->event.pressed) { layer_on(_NUMBER); } else { layer_off(_NUMBER); }break;
		//case ARROW: if (record->event.pressed) { layer_on(_ARROW); } else { layer_off(_ARROW); } break;
		//// toggleな感じのキーコード{{{
		//case TOG_SYM:
		//	if (record->event.pressed) {
		//		if(layer_toggle_status==0){
		//			layer_toggle_status = 1; layer_on(_SYMBOL);
		//		}else if(layer_toggle_status==1){
		//			layer_toggle_status = 0; layer_off(_SYMBOL);
		//		}
		//	}
		//	break;
		//case TOG_NUM:
		//	if (record->event.pressed) {
		//		if(layer_toggle_status==0){
		//			layer_toggle_status = 2; layer_on(_NUMBER);
		//		}else if(layer_toggle_status==2){
		//			layer_toggle_status = 0; layer_off(_NUMBER);
		//		}
		//	break;
		//case TOG_MID:
		//	if (record->event.pressed) {
		//		if(layer_toggle_status==0){
		//			layer_toggle_status = 3; layer_on(_MIDI);
		//		}else if(layer_toggle_status==3){
		//			layer_toggle_status = 0; layer_off(_MIDI);
		//		}
		//	break;
		//case TOG_IC:
		//	if (record->event.pressed) {
		//		if(layer_toggle_status==0){
		//			layer_toggle_status = 4; layer_on(_IC);
		//		}else if(layer_toggle_status==4){
		//			layer_toggle_status = 0; layer_off(_IC);
		//		}
		//	break;
		// }}}
		//// MIDI {{{
		// 参考 : https://rephtone.com/electronics/helix-midicustom/
		case MI_NOTE001 ... MI_NOTE012: // MIDI
			uint8_t note = keycode - MI_NOTEMIN + midiOffset;
			midi_send_noteon(&midi_device, midi_channel, note, record->event.pressed ? 127 : 0);
			return false;
		// }}}
		// IC {{{
		case IC_MUTE: break;
		case IC_REVERSE:                    icData->reverse = record->event.pressed; break;
		case IC_keyUP:                      OffsetCodeBase( &icData, 1 ); break;
		case IC_keyDN:                      OffsetCodeBase( &icData, -1); break;
		case IC_Cn_MEJAR ... IC_Cn_SUSTAIN: SetCode( &icData, note_Cn, noteOffset, keycode - IC_Cn_MEJAR); break;
		case IC_Cs_MEJAR ... IC_Cs_SUSTAIN: SetCode( &icData, note_Cs, noteOffset, keycode - IC_Cs_MEJAR); break;
		case IC_Dn_MEJAR ... IC_Dn_SUSTAIN: SetCode( &icData, note_Dn, noteOffset, keycode - IC_Dn_MEJAR); break;
		case IC_Ds_MEJAR ... IC_Ds_SUSTAIN: SetCode( &icData, note_Ds, noteOffset, keycode - IC_Ds_MEJAR); break;
		case IC_En_MEJAR ... IC_En_SUSTAIN: SetCode( &icData, note_En, noteOffset, keycode - IC_En_MEJAR); break;
		case IC_Fn_MEJAR ... IC_Fn_SUSTAIN: SetCode( &icData, note_Fn, noteOffset, keycode - IC_Fn_MEJAR); break;
		case IC_Fs_MEJAR ... IC_Fs_SUSTAIN: SetCode( &icData, note_Fs, noteOffset, keycode - IC_Fs_MEJAR); break;
		case IC_Gn_MEJAR ... IC_Gn_SUSTAIN: SetCode( &icData, note_Gn, noteOffset, keycode - IC_Gn_MEJAR); break;
		case IC_Gs_MEJAR ... IC_Gs_SUSTAIN: SetCode( &icData, note_Gs, noteOffset, keycode - IC_Gs_MEJAR); break;
		case IC_An_MEJAR ... IC_An_SUSTAIN: SetCode( &icData, note_An, noteOffset, keycode - IC_An_MEJAR); break;
		case IC_As_MEJAR ... IC_As_SUSTAIN: SetCode( &icData, note_As, noteOffset, keycode - IC_As_MEJAR); break;
		case IC_Bn_MEJAR ... IC_Bn_SUSTAIN: SetCode( &icData, note_Bn, noteOffset, keycode - IC_Bn_MEJAR); break;
		case IC_string01 ... IC_string06:   if(codeArray[keycode - IC_string01] != -1){ PlayNote( lowestNote + codeArray[keycode - IC_string01], midi_channel, record->event.pressed ); } break;
		case IC_PLAY_CODE:                  PlayCode( codeNote, icCodeNoteOffset, codeArray, midi_channel, record );
		// }}}
	}
	return true;
}

