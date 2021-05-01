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
	MI_UP, MI_DN, MI_MAX,
	IC_MIN,
	IC_RESET, IC_MUTE,
	IC_Cn_MAJOR, IC_Cn_MINOR, IC_Cn_7, IC_Cn_MAJOR7, IC_Cn_MINOR7, IC_Cn_MINORMEJOR7, IC_Cn_DIMINISH, IC_Cn_AUGUMENT, IC_Cn_SUSTAIN,
	IC_Cs_MAJOR, IC_Cs_MINOR, IC_Cs_7, IC_Cs_MAJOR7, IC_Cs_MINOR7, IC_Cs_MINORMEJOR7, IC_Cs_DIMINISH, IC_Cs_AUGUMENT, IC_Cs_SUSTAIN,
	IC_Dn_MAJOR, IC_Dn_MINOR, IC_Dn_7, IC_Dn_MAJOR7, IC_Dn_MINOR7, IC_Dn_MINORMEJOR7, IC_Dn_DIMINISH, IC_Dn_AUGUMENT, IC_Dn_SUSTAIN,
	IC_Ds_MAJOR, IC_Ds_MINOR, IC_Ds_7, IC_Ds_MAJOR7, IC_Ds_MINOR7, IC_Ds_MINORMEJOR7, IC_Ds_DIMINISH, IC_Ds_AUGUMENT, IC_Ds_SUSTAIN,
	IC_En_MAJOR, IC_En_MINOR, IC_En_7, IC_En_MAJOR7, IC_En_MINOR7, IC_En_MINORMEJOR7, IC_En_DIMINISH, IC_En_AUGUMENT, IC_En_SUSTAIN,
	IC_Fn_MAJOR, IC_Fn_MINOR, IC_Fn_7, IC_Fn_MAJOR7, IC_Fn_MINOR7, IC_Fn_MINORMEJOR7, IC_Fn_DIMINISH, IC_Fn_AUGUMENT, IC_Fn_SUSTAIN,
	IC_Fs_MAJOR, IC_Fs_MINOR, IC_Fs_7, IC_Fs_MAJOR7, IC_Fs_MINOR7, IC_Fs_MINORMEJOR7, IC_Fs_DIMINISH, IC_Fs_AUGUMENT, IC_Fs_SUSTAIN,
	IC_Gn_MAJOR, IC_Gn_MINOR, IC_Gn_7, IC_Gn_MAJOR7, IC_Gn_MINOR7, IC_Gn_MINORMEJOR7, IC_Gn_DIMINISH, IC_Gn_AUGUMENT, IC_Gn_SUSTAIN,
	IC_Gs_MAJOR, IC_Gs_MINOR, IC_Gs_7, IC_Gs_MAJOR7, IC_Gs_MINOR7, IC_Gs_MINORMEJOR7, IC_Gs_DIMINISH, IC_Gs_AUGUMENT, IC_Gs_SUSTAIN,
	IC_An_MAJOR, IC_An_MINOR, IC_An_7, IC_An_MAJOR7, IC_An_MINOR7, IC_An_MINORMEJOR7, IC_An_DIMINISH, IC_An_AUGUMENT, IC_An_SUSTAIN,
	IC_As_MAJOR, IC_As_MINOR, IC_As_7, IC_As_MAJOR7, IC_As_MINOR7, IC_As_MINORMEJOR7, IC_As_DIMINISH, IC_As_AUGUMENT, IC_As_SUSTAIN,
	IC_Bn_MAJOR, IC_Bn_MINOR, IC_Bn_7, IC_Bn_MAJOR7, IC_Bn_MINOR7, IC_Bn_MINORMEJOR7, IC_Bn_DIMINISH, IC_Bn_AUGUMENT, IC_Bn_SUSTAIN,
	IC_string01, IC_string02, IC_string03, IC_string04, IC_string05, IC_string06,
	IC_OCTAVE_UP, IC_OCTAVE_DN, IC_NOTE_UP, IC_NOTE_DN,
	IC_MAJOR, IC_MINOR, IC_SEVENS, IC_MAJORSEVENS, IC_MINORSEVENS, IC_MINORMEJORSEVENS, IC_DIMINISH, IC_AUGUMENT, IC_SUSTAIN,
	IC_REVERSE, IC_SHARP,
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

void MidiAllSoundOff(void){ midi_send_data(&midi_device,3,0xB0,120,0); } // all sound off

void ResetIC(void){
	{ // なぜかグローバル変数な配列の初期化子リストでの初期化ができないのでここでmemcpyして初期化
		uint8_t ic[9][6] = {
			{ 0, 4, 7, 12, 16, 19 }, // 0 Major
			{ 0, 3, 7, 12, 15, 19 }, // 1 Minor
			{ 0, 4, 7, 10, 12, 16 }, // 2 Sevens
			{ 0, 4, 7, 11, 12, 16 }, // 3 MajorSevens
			{ 0, 3, 7, 10, 12, 15 }, // 4 MinorSevens
			{ 0, 3, 7, 11, 12, 15 }, // 5 MinorMajorSevens
			{ 0, 3, 6, 12, 15, 18 }, // 6 Diminish
			{ 0, 4, 8, 12, 16, 20 }, // 7 Augument
			{ 0, 5, 7, 12, 17, 19 }  // 8 Sustain
		};
		memcpy( icData.icCodeOffsetArray,ic,sizeof(ic) );
	}

	icData.baseNote          = 0;                 // 音 icDefineCode.hのenum note
	icData.octaveOffset      = 1;                 // オクターブオフセット  min=-1 max=9
	icData.noteOffset        = 0;                 // 半音単位でのオフセット いわゆる変調
	icData.codeType          = 0;                 // Majorとか

	icData.isForsed          = false;             // dimやsusなどの種類変更キーが押されているか
	icData.isReversed        = false;             // ~ Reverseが押されているか Major <-> Minor
	icData.isSharped         = false;             // # が押されているか 半音あげる
	icData.pressedForseCode  = 0;                 // 押されているコード種類変更キー enum codeTypeが入るのを想定

	// icData.icCodeOffsetArrayのデバッグ
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			dprintf("%u,", icData.icCodeOffsetArray[i][j]);
		}
		dprintf("\n");
	}
	MidiAllSoundOff();
}

// 単音を鳴らす
void PlayNote(
	uint8_t note,         // midi のノート番号
	uint8_t midi_channel, // midi のチャンネル番号
	bool    pressed       // キーが押されているか
){
	if(note >= 0 && note <= 127){ midi_send_noteon(&midi_device, midi_channel, note, pressed ? 64 : 0); }
	dprintf("n%u;", note);
}

const char NoteName[12][6] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B" };
const char* NoteToString(uint8_t note){
	return NoteName[note%12];
}

// 強制的にキーの種類を変える
// dimなど
void ForseChangeKey(
	IcData*      icData,           // 設定
	uint8_t      pressedForseCode, // 押されているキー種類変更キー
	keyrecord_t* record            // キー入力状態
){
	icData->isForsed = record->event.pressed;
	icData->pressedForseCode = pressedForseCode;
}

// PlayStringでなる音の決定方法は複雑で良くない まずコード有りき
// 設定されているコード(MajorとかMinorとか)の低い音順で6音、最も低い音からのオフセット配列がある
// 最も低い音を指定して、その他5音をオフセット配列から生成する
// minor 7なら { 0, 4, 7, 11, 12, 16 } というオフセット配列で、
// C4(60)のCm7は60にオフセット配列の数値を足して、
// 60,64,67,71,72,76が生成されこれらが弦に割り当てられる
// ここから指定の弦の音を鳴らす
void PlayStrings(
	IcData*      icData,       // 設定
	uint8_t      stringNum,    // 弦番号 (低い音から0)
	uint8_t      midi_channel, // midiのチャンネル
	keyrecord_t* record,       // キー入力状態
	bool         isOneString   // デバッグ用 1弦のみのキーコードで鳴らされているか
){
	uint8_t      lowestNote = (icData->baseNote + icData->noteOffset) % 12 + (icData->octaveOffset + 1) * 12;
	uint8_t      codeType   = icData->isForsed ? icData->pressedForseCode : icData->codeType;
	// 現状REVERSEに関しては正しい実装ができていない
	// ギター風にしているがそれはやめた方がいいかもしれない
	// 普通にCならドミソの3音だけにした方が良さそう
	switch(codeType){
		case MAJOR: codeType = MINOR; break;
		case MINOR: codeType = MAJOR; break;
		//case SEVENS:
		case MAJORSEVENS: codeType = MINORSEVENS; break;
		case MINORSEVENS: codeType = MAJORSEVENS; break;
		//case MINORMEJORSEVENS: codeType = MINOR; break;
		//case DIMINISH:
		//case AUGUMENT:
		//case SUSTAIN:
	}
	uint8_t      note = lowestNote + icData->icCodeOffsetArray[codeType][stringNum] + icData->isSharped ? 1 : 0;
	if(isOneString){
		dprintf("\nstring%d(+%d):%s", stringNum, icData->icCodeOffsetArray[icData->codeType][stringNum], NoteToString(note));
	}
	PlayNote( note, midi_channel, record->event.pressed );
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

	dprintf("%s", NoteToString((icData->baseNote + icData->noteOffset) % 12));

	switch(icData->codeType){
		case MAJOR: dprintf("%s ", "M"); break;
		case MINOR: dprintf("%s ", "m"); break;
		case SEVENS: dprintf("%s ", "7"); break;
		case MAJORSEVENS: dprintf("%s ", "M7"); break;
		case MINORSEVENS: dprintf("%s ", "m7"); break;
		case MINORMEJORSEVENS: dprintf("%s ", "Mm7"); break;
		case DIMINISH: dprintf("%s ", "dim"); break;
		case AUGUMENT: dprintf("%s ", "aug"); break;
		case SUSTAIN: dprintf("%s ", "sus"); break;
	}

	for(uint8_t i = 0; i < 6; i++){
		PlayStrings(
			icData,       // 現在の設定
			i,            // 弦番号
			midi_channel, // midiの現在設定されている楽器チャネル番号
			record,       // 押下状態
			false         // PlayCodeでPlayStringを呼んでいるのでfalse
		);
	}
	dprintf("\n");
}

// 参考 : https://rephtone.com/electronics/helix-midicustom/
// MIDIの規格書(http://amei.or.jp/midistandardcommittee/MIDI1.0.pdf)の2-10 ベロシティのところには ss:https://imgur.com/nH9lglU
// 「64(40H)の値は，ノート・オンで言えばメゾフォルテ付近に相当し，ベロシティを検出しない送信側機器は，原則としてこの値を送る。」とある。
// なのでとりあえずvelocityに64を入れる。midiでは速さの意味のvelocityをなぜか音の強度の意味で使う。
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	int tmpNoteNum = keycode - MI_MIN + midiOffset;
	if(record->event.pressed){ // 押した時と離した時両方で反応すると2回同じものを送信してしまうので分ける
		switch (keycode) {
			case IC_RESET:                      ResetIC();
			case MI_UP:                         midiOffset += 12; break;
			case MI_DN:                         midiOffset -= 12; break;
			case IC_MUTE:                       MidiAllSoundOff(); break;
			case IC_OCTAVE_UP:                  OffsetOctave( &icData,  1 ); break;
			case IC_OCTAVE_DN:                  OffsetOctave( &icData, -1 ); break;
			case IC_NOTE_UP:                    OffsetNote( &icData,  1 ); break;
			case IC_NOTE_DN:                    OffsetNote( &icData, -1 ); break;
			case IC_Cn_MAJOR ... IC_Cn_SUSTAIN: SetCode( &icData, note_Cn, keycode - IC_Cn_MAJOR); break;
			case IC_Cs_MAJOR ... IC_Cs_SUSTAIN: SetCode( &icData, note_Cs, keycode - IC_Cs_MAJOR); break;
			case IC_Dn_MAJOR ... IC_Dn_SUSTAIN: SetCode( &icData, note_Dn, keycode - IC_Dn_MAJOR); break;
			case IC_Ds_MAJOR ... IC_Ds_SUSTAIN: SetCode( &icData, note_Ds, keycode - IC_Ds_MAJOR); break;
			case IC_En_MAJOR ... IC_En_SUSTAIN: SetCode( &icData, note_En, keycode - IC_En_MAJOR); break;
			case IC_Fn_MAJOR ... IC_Fn_SUSTAIN: SetCode( &icData, note_Fn, keycode - IC_Fn_MAJOR); break;
			case IC_Fs_MAJOR ... IC_Fs_SUSTAIN: SetCode( &icData, note_Fs, keycode - IC_Fs_MAJOR); break;
			case IC_Gn_MAJOR ... IC_Gn_SUSTAIN: SetCode( &icData, note_Gn, keycode - IC_Gn_MAJOR); break;
			case IC_Gs_MAJOR ... IC_Gs_SUSTAIN: SetCode( &icData, note_Gs, keycode - IC_Gs_MAJOR); break;
			case IC_An_MAJOR ... IC_An_SUSTAIN: SetCode( &icData, note_An, keycode - IC_An_MAJOR); break;
			case IC_As_MAJOR ... IC_As_SUSTAIN: SetCode( &icData, note_As, keycode - IC_As_MAJOR); break;
			case IC_Bn_MAJOR ... IC_Bn_SUSTAIN: SetCode( &icData, note_Bn, keycode - IC_Bn_MAJOR); break;
		}
	}

	// IC_PLAY_CODEはギターの弦全部を鳴らした状態を想定 なので直前にall sound offを送っている。
	switch (keycode) { // 押した時と離した時両方で反応して欲しいキーの設定
		case MI_0001 ... MI_0036:           if(tmpNoteNum >= 0 && tmpNoteNum <= 127){ midi_send_noteon(&midi_device, midi_channel, tmpNoteNum, record->event.pressed ? 64 : 0); } break;
		case IC_REVERSE:                    icData.isReversed = record->event.pressed; break;
		case IC_SHARP:                      icData.isSharped = record->event.pressed; break;
		case IC_string01 ... IC_string06:   PlayStrings( &icData, keycode - IC_string01, midi_channel, record, true); break;
		case IC_PLAY_CODE:                  MidiAllSoundOff(); PlayCode( &icData, midi_channel, record ); break;
		case IC_MAJOR ... IC_SUSTAIN:       ForseChangeKey( &icData, keycode - IC_MAJOR, record );
	}
	return true;
}

