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

#include "icDefineCode.h"

#include "print.h"
// print("string")          : シンプルな文字列を出力します
// uprintf("%s string", var): フォーマットされた文字列を出力します
// dprint("string")         : デバッグモードが有効な場合のみ、シンプルな文字列を出力します
// dprintf("%s string", var): デバッグモードが有効な場合のみ、フォーマットされた文字列を出力します

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
	MI_MIN,
	MI_0001 = MI_MIN, MI_0002, MI_0003, MI_0004, MI_0005, MI_0006,
	MI_0007, MI_0008, MI_0009, MI_0010, MI_0011, MI_0012,
	MI_0013, MI_0014, MI_0015, MI_0016, MI_0017, MI_0018,
	MI_0019, MI_0020, MI_0021, MI_0022, MI_0023, MI_0024,
	MI_0025, MI_0026, MI_0027, MI_0028, MI_0029, MI_0030,
	MI_0031, MI_0032, MI_0033, MI_0034, MI_0035, MI_0036,
	MI_UP, MI_DN,
	MI_MAX,
	IC_MIN,
	IC_RESET,
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
	IC_OCTAVE_UP, IC_OCTAVE_DN, IC_NOTE_UP, IC_NOTE_DN,
	IC_PLAY_CODE,
	IC_MAX
};

#include "keymap_moon50.h"
extern MidiDevice midi_device;
uint8_t midi_channel = 0;  // MIDIのチャンネル
uint8_t midiOffset = 39;   // MI_0_001を39(D#2)にする
IcData icData = { false, 0, 1 };

void ResetIC(void);

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void keyboard_post_init_user(void) { // Call the keyboard pre init code.
	ResetIC();
	debug_enable=true;
}

void ResetIC(void){
	{ // なぜかグローバル変数な配列の初期化ができないのでここで初期化
		uint8_t ic[9][6] = {
		  { 0, 4, 7, 12, 16, 19 }, // 0 Mejar
		  { 0, 3, 7, 12, 15, 19 }, // 1 Minor
		  { 0, 4, 7, 10, 12, 16 }, // 2 Sevens
		  { 0, 4, 7, 11, 12, 16 }, // 3 MejarSevens
		  { 0, 3, 7, 10, 12, 15 }, // 4 MinorSevens
		  { 0, 3, 7, 11, 12, 15 }, // 5 MinorMejorSevens
		  { 0, 3, 6, 12, 15, 18 }, // 6 Diminish
		  { 0, 4, 8, 12, 16, 20 }, // 7 Augument
		  { 0, 5, 7, 12, 17, 19 }  // 8 Sustain
		};
		memcpy( icData.icCodeOffsetArray,ic,sizeof(ic) );
	}

	icData.reverse           = false;             // insta code の ~ 相当
	icData.baseNote          = 0;                 // 音 icDefineCode.hのenum note
	icData.octaveOffset      = 1;                 // オクターブオフセット  min=-1 max=9
	icData.noteOffset        = 0;                 // 半音単位でのオフセット いわゆる変調
	icData.codeType          = 0;                 // Majorとか

	// icData.icCodeOffsetArrayのデバッグ
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			dprintf("%u,", icData.icCodeOffsetArray[i][j]);
		}
		dprintf("\n");
	}
}

// 単音を鳴らす
void PlayNote(
	uint8_t note,         // midi のノート番号
	uint8_t midi_channel, // midi のチャンネル番号
	bool    pressed       // キーが押されているか
){
	if(note >= 0 && note <= 127){ midi_send_noteon(&midi_device, midi_channel, note, pressed ? 127 : 0); }
	dprintf("n%u;", note);
}

void PlayStrings(
	IcData*      icData,       // 設定
	uint8_t      stringNum,    // 弦番号 (低い音から0)
	uint8_t      lowestNote,   // 和音で一番低い音
	uint8_t      midi_channel, // midiのチャンネル
	keyrecord_t* record        // キー入力状態
){
	dprintf("s%d(o%d):", stringNum, icData->icCodeOffsetArray[icData->codeType][stringNum]);
	PlayNote( lowestNote + icData->icCodeOffsetArray[icData->codeType][stringNum], midi_channel, record->event.pressed );
}

// 設定された和音を鳴らす
void PlayCode(
	IcData*      icData,       // 設定
	uint8_t      midi_channel, // midiのチャンネル
	keyrecord_t* record        // キー入力状態
){
	dprintf("bn%u,oo%d,no%d,ct%u,", icData->baseNote, icData->octaveOffset, icData->noteOffset, icData->codeType);
	dprintf("(%u %u %u %u %u %u)"
		, icData->icCodeOffsetArray[icData->codeType][0]
		, icData->icCodeOffsetArray[icData->codeType][1]
		, icData->icCodeOffsetArray[icData->codeType][2]
		, icData->icCodeOffsetArray[icData->codeType][3]
		, icData->icCodeOffsetArray[icData->codeType][4]
		, icData->icCodeOffsetArray[icData->codeType][5]);
	switch(icData->baseNote){
		case note_Cn: dprintf("%s ", "Cn"); break;
		case note_Cs: dprintf("%s ", "Cs"); break;
		case note_Dn: dprintf("%s ", "Dn"); break;
		case note_Ds: dprintf("%s ", "Ds"); break;
		case note_En: dprintf("%s ", "En"); break;
		case note_Fn: dprintf("%s ", "Fn"); break;
		case note_Fs: dprintf("%s ", "Fs"); break;
		case note_Gn: dprintf("%s ", "Gn"); break;
		case note_Gs: dprintf("%s ", "Gs"); break;
		case note_An: dprintf("%s ", "An"); break;
		case note_As: dprintf("%s ", "As"); break;
		case note_Bn: dprintf("%s ", "Bn"); break;
	}

	switch(icData->codeType){
		case MEJAR: dprintf("%s ", "M"); break;
		case MINOR: dprintf("%s ", "m"); break;
		case SEVENS: dprintf("%s ", "7"); break;
		case MEJARSEVENS: dprintf("%s ", "M7"); break;
		case MINORSEVENS: dprintf("%s ", "m7"); break;
		case MINORMEJORSEVENS: dprintf("%s ", "Mm7"); break;
		case DIMINISH: dprintf("%s ", "dim"); break;
		case AUGUMENT: dprintf("%s ", "aug"); break;
		case SUSTAIN: dprintf("%s ", "sus"); break;
	}

	for(uint8_t i = 0; i < 6; i++){
		PlayStrings( icData, i, icData->baseNote + icData->octaveOffset * 12 + 12 + icData->noteOffset, midi_channel, record);
	}
	dprintf("\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	int tmpNoteNum = keycode - MI_MIN + midiOffset;
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
		case MI_UP: midiOffset += 12; break;
		case MI_DN: midiOffset -= 12; break;
		case MI_0001 ... MI_0036: // MIDI
			if(tmpNoteNum >= 0 && tmpNoteNum <= 127){
				midi_send_noteon(&midi_device, midi_channel, tmpNoteNum, record->event.pressed ? 127 : 0);
			}
			break;
		// }}}
		// IC {{{
		case IC_MUTE:                       midi_send_reset(&midi_device); break;
		case IC_REVERSE:                    icData.reverse = record->event.pressed; break;
		case IC_OCTAVE_UP:                  OffsetOctave( &icData,  1 ); break;
		case IC_OCTAVE_DN:                  OffsetOctave( &icData, -1 ); break;
		case IC_NOTE_UP:                    OffsetNote( &icData,  1 ); break;
		case IC_NOTE_DN:                    OffsetNote( &icData, -1 ); break;
		case IC_Cn_MEJAR ... IC_Cn_SUSTAIN: SetCode( &icData, note_Cn, keycode - IC_Cn_MEJAR); break;
		case IC_Cs_MEJAR ... IC_Cs_SUSTAIN: SetCode( &icData, note_Cs, keycode - IC_Cs_MEJAR); break;
		case IC_Dn_MEJAR ... IC_Dn_SUSTAIN: SetCode( &icData, note_Dn, keycode - IC_Dn_MEJAR); break;
		case IC_Ds_MEJAR ... IC_Ds_SUSTAIN: SetCode( &icData, note_Ds, keycode - IC_Ds_MEJAR); break;
		case IC_En_MEJAR ... IC_En_SUSTAIN: SetCode( &icData, note_En, keycode - IC_En_MEJAR); break;
		case IC_Fn_MEJAR ... IC_Fn_SUSTAIN: SetCode( &icData, note_Fn, keycode - IC_Fn_MEJAR); break;
		case IC_Fs_MEJAR ... IC_Fs_SUSTAIN: SetCode( &icData, note_Fs, keycode - IC_Fs_MEJAR); break;
		case IC_Gn_MEJAR ... IC_Gn_SUSTAIN: SetCode( &icData, note_Gn, keycode - IC_Gn_MEJAR); break;
		case IC_Gs_MEJAR ... IC_Gs_SUSTAIN: SetCode( &icData, note_Gs, keycode - IC_Gs_MEJAR); break;
		case IC_An_MEJAR ... IC_An_SUSTAIN: SetCode( &icData, note_An, keycode - IC_An_MEJAR); break;
		case IC_As_MEJAR ... IC_As_SUSTAIN: SetCode( &icData, note_As, keycode - IC_As_MEJAR); break;
		case IC_Bn_MEJAR ... IC_Bn_SUSTAIN: SetCode( &icData, note_Bn, keycode - IC_Bn_MEJAR); break;
		case IC_string01 ... IC_string06:   PlayStrings( &icData, keycode - IC_string01, icData.baseNote + icData.octaveOffset * 12 + 12 + icData.noteOffset, midi_channel, record); break;
		case IC_PLAY_CODE:                  PlayCode( &icData, midi_channel, record ); break;
		case IC_RESET:                      ResetIC();
	}
	return true;
}

