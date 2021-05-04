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

#ifdef CONSOLE_ENABLE
#include "print.h"
// print("string")          : シンプルな文字列を出力します
// uprintf("%s string", var): フォーマットされた文字列を出力します
// dprint("string")         : デバッグモードが有効な場合のみ、シンプルな文字列を出力します
// dprintf("%s string", var): デバッグモードが有効な場合のみ、フォーマットされた文字列を出力します
#endif

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
	IC_Cn_MAJOR, IC_Cn_MINOR, //IC_Cn_7, IC_Cn_MAJOR7, IC_Cn_MINOR7, IC_Cn_MINORMEJOR7, IC_Cn_DIMINISH, IC_Cn_AUGUMENT, IC_Cn_SUSTAIN,
	IC_Cs_MAJOR, IC_Cs_MINOR, //IC_Cs_7, IC_Cs_MAJOR7, IC_Cs_MINOR7, IC_Cs_MINORMEJOR7, IC_Cs_DIMINISH, IC_Cs_AUGUMENT, IC_Cs_SUSTAIN,
	IC_Dn_MAJOR, IC_Dn_MINOR, //IC_Dn_7, IC_Dn_MAJOR7, IC_Dn_MINOR7, IC_Dn_MINORMEJOR7, IC_Dn_DIMINISH, IC_Dn_AUGUMENT, IC_Dn_SUSTAIN,
	IC_Ds_MAJOR, IC_Ds_MINOR, //IC_Ds_7, IC_Ds_MAJOR7, IC_Ds_MINOR7, IC_Ds_MINORMEJOR7, IC_Ds_DIMINISH, IC_Ds_AUGUMENT, IC_Ds_SUSTAIN,
	IC_En_MAJOR, IC_En_MINOR, //IC_En_7, IC_En_MAJOR7, IC_En_MINOR7, IC_En_MINORMEJOR7, IC_En_DIMINISH, IC_En_AUGUMENT, IC_En_SUSTAIN,
	IC_Fn_MAJOR, IC_Fn_MINOR, //IC_Fn_7, IC_Fn_MAJOR7, IC_Fn_MINOR7, IC_Fn_MINORMEJOR7, IC_Fn_DIMINISH, IC_Fn_AUGUMENT, IC_Fn_SUSTAIN,
	IC_Fs_MAJOR, IC_Fs_MINOR, //IC_Fs_7, IC_Fs_MAJOR7, IC_Fs_MINOR7, IC_Fs_MINORMEJOR7, IC_Fs_DIMINISH, IC_Fs_AUGUMENT, IC_Fs_SUSTAIN,
	IC_Gn_MAJOR, IC_Gn_MINOR, //IC_Gn_7, IC_Gn_MAJOR7, IC_Gn_MINOR7, IC_Gn_MINORMEJOR7, IC_Gn_DIMINISH, IC_Gn_AUGUMENT, IC_Gn_SUSTAIN,
	IC_Gs_MAJOR, IC_Gs_MINOR, //IC_Gs_7, IC_Gs_MAJOR7, IC_Gs_MINOR7, IC_Gs_MINORMEJOR7, IC_Gs_DIMINISH, IC_Gs_AUGUMENT, IC_Gs_SUSTAIN,
	IC_An_MAJOR, IC_An_MINOR, //IC_An_7, IC_An_MAJOR7, IC_An_MINOR7, IC_An_MINORMEJOR7, IC_An_DIMINISH, IC_An_AUGUMENT, IC_An_SUSTAIN,
	IC_As_MAJOR, IC_As_MINOR, //IC_As_7, IC_As_MAJOR7, IC_As_MINOR7, IC_As_MINORMEJOR7, IC_As_DIMINISH, IC_As_AUGUMENT, IC_As_SUSTAIN,
	IC_Bn_MAJOR, IC_Bn_MINOR, //IC_Bn_7, IC_Bn_MAJOR7, IC_Bn_MINOR7, IC_Bn_MINORMEJOR7, IC_Bn_DIMINISH, IC_Bn_AUGUMENT, IC_Bn_SUSTAIN,
	IC_string01, IC_string02, IC_string03, IC_string04, IC_string05, IC_string06,
	IC_key01,IC_key02,IC_key03,
	IC_key04,IC_key05,IC_key06,
	IC_key07,IC_key08,IC_key09,
	IC_key10,IC_key11,IC_key12,
	IC_key13,IC_key14,IC_key15,
	IC_key16,IC_key17,IC_key18,
	IC_OCTAVE_UP, IC_OCTAVE_DN, IC_NOTE_UP, IC_NOTE_DN,
	IC_7th, IC_9th,IC_M7, IC_dim, IC_aug, IC_sus4,
	IC_m7sub5, // m7-5
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

void UpdateStatus( IcData* icData,  uint8_t isPressed, uint16_t* status, CodeStatusBit bitNum );

void ResetIC(void){

	icData.baseNote          = 0;                 // 音 icDefineCode.hのenum note
	icData.octaveOffset      = 3;                 // オクターブオフセット  min=-1 max=9
	icData.noteOffset        = 0;                 // 半音単位でのオフセット いわゆる変調
	icData.codeStatus        = 0;                 // キー ビット演算する
	icData.isSharped         = false;             // # が押されているか 半音あげる

	MidiAllSoundOff();
	UpdateStatus( &icData, 1, &icData.codeStatus, NORMAL ); // NORMALの時 1のところはなんでもいい
}

// 単音を鳴らす
void PlayNote(
	uint8_t note,         // midi のノート番号
	uint8_t midi_channel, // midi のチャンネル番号
	bool    pressed       // キーが押されているか
){
	if(note >= 0 && note <= 127){ midi_send_noteon(&midi_device, midi_channel, note, pressed ? 64 : 0); }
#ifdef CONSOLE_ENABLE
	dprintf("(%u)", note);
#endif
}

#ifdef CONSOLE_ENABLE
const char NoteName[12][6] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B" };
const char* NoteToString(uint8_t note){ return NoteName[note%12]; }
#endif

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
	if(icData->notes[stringNum] != -1){
#ifdef CONSOLE_ENABLE
		//if(isOneString){ dprintf("\nstring%d(+%d):%s", stringNum, icData->notes[stringNum], NoteToString(icData->notes[stringNum])); }
		if(1){ dprintf("\nstring%d(+%d):%s", stringNum, icData->notes[stringNum], NoteToString(icData->notes[stringNum])); }
#endif
		PlayNote( icData->notes[stringNum], midi_channel, record->event.pressed );
	}
}

#ifdef CONSOLE_ENABLE
// C言語のprintfは2真数に対応していないので
void printBinary(char* str, uint16_t v) {
	uint16_t mask;
	char bh[9], bl[9];
	for(int i = 0; i < 9; i++){ bh[i] = '\0'; bl[i] = '\0'; }

	// 2byte リトルエンディアン
	for(int i = 0; i < 8; i++){
		mask = 1U << i;
		bl[ 7 - i ] = v & mask ? '1' : '0';
	}
	for(int i = 0; i < 8; i++){
		mask = 1U << ( i + 8 );
		bh[ 7 - i ] = v & mask ? '1' : '0';
	}
	sprintf(str,"codeStatus:%3d(0x%4x)(0b %s %s)", v, v, bh, bl);
}
#endif

#ifdef CONSOLE_ENABLE
void PrintStatus(
	IcData*      icData        // 設定
){
	char     bi[40];
	uint8_t isReversed, isMinor;

	isReversed = icData->codeStatus & 1UL << (REVERSE-1);
	isMinor = icData->codeStatus & 1UL << (MINOR-1);

	dprintf("baseNote:%u octaveOffset:%d noteOffset:%d ", icData->baseNote, icData->octaveOffset, icData->noteOffset);
	printBinary(bi, icData->codeStatus);
	dprintf("%s ", bi);
	//dprintf("r:%d m:%d \n", isReversed, isMinor);
	//if( ( isReversed && !isMinor ) || ( !isReversed && isMinor ) ){
	//	dprintf("Minor\n");
	//}else{
	//	dprintf("Major\n");
	//}

	dprintf("%s_", NoteToString((icData->baseNote + icData->noteOffset) % 12));

	if(icData->codeStatus & (1UL << (SUSTAIN - 1) ) ){ dprintf("%s", "sus4"); }
	if(icData->codeStatus & (1UL << (AUGUMENT - 1) ) ){ dprintf("%s", "aug"); }
	if(icData->codeStatus & (1UL << (DIMINISH - 1) ) ){ dprintf("%s", "dim"); }

	if( ( isReversed && !isMinor ) || ( !isReversed && isMinor ) ){ dprintf("%s", "m"); }

	if(icData->codeStatus & (1UL << (MAJORSEVENTH - 1) ) ){ dprintf("%s", "M7"); }
	else if(icData->codeStatus & (1UL << (SEVENTH - 1) ) ){ dprintf("%s", "7"); }
	if(icData->codeStatus & (1UL << (SUBFIFTH - 1) ) ){ dprintf("%s", "-5"); }
	if(icData->codeStatus & (1UL << (NINETH - 1) ) ){ dprintf("%s", "9"); }
	if(icData->codeStatus & (1UL << (ADDNINETH - 1) ) ){ dprintf("%s", "add9"); }
	dprintf(" \n");
}
#endif

// 設定された和音を鳴らす
void PlayCode(
	IcData*      icData,       // 設定
	uint8_t      midi_channel, // midiのチャンネル
	keyrecord_t* record        // キー入力状態
){

	for(uint8_t i = 0; i < 16; i++){
		dprintf( "(%d)", icData->notes[i] );
	}

	for(uint8_t i = 0; i < 16; i++){
		PlayStrings(
			icData,       // 現在の設定
			i,            // 弦番号
			midi_channel, // midiの現在設定されている楽器チャネル番号
			record,       // 押下状態
			false         // PlayCodeでPlayStringを呼んでいるのでfalse
		);
	}
#ifdef CONSOLE_ENABLE
	dprintf("\n");
#endif

}

// bitNum 負なら更新しない
void UpdateStatus( IcData* icData,  uint8_t isPressed, uint16_t* status, CodeStatusBit bitNum ){

	uint8_t root = (icData->baseNote + icData->noteOffset) % 12 + (icData->octaveOffset + 1) * 12;
	if(bitNum >= 0 ){ // 押した時のみ 負なら更新しない
		if( bitNum == NORMAL ){ // NORMAL指定なら0にする
			*status = 0;
		}else {
			if( isPressed ){
				*status |= 1UL << (bitNum-1);
			}else{
				*status &= ~(1UL << (bitNum-1));
			}
		}
	}
	CalcNotes( root, icData->codeStatus, icData->notes );
	SetScaleKeys( root, icData->codeStatus, icData->keys);

#ifdef CONSOLE_ENABLE
	dprintf("notes:");
	for(int i = 0; i < 16; i++){
		if(icData->notes[i] != -1){
			dprintf("(%s:%d)", NoteToString(icData->notes[i]),icData->notes[i]);
		}
	}
	dprintf("\n");
#endif
}

// 参考 : https://rephtone.com/electronics/helix-midicustom/
// MIDIの規格書(http://amei.or.jp/midistandardcommittee/MIDI1.0.pdf)の2-10 ベロシティのところには ss:https://imgur.com/nH9lglU
// 「64(40H)の値は，ノート・オンで言えばメゾフォルテ付近に相当し，ベロシティを検出しない送信側機器は，原則としてこの値を送る。」とある。
// なのでとりあえずvelocityに64を入れる。midiでは速さの意味のvelocityをなぜか音の強度の意味で使う。
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
	int tmpNoteNum = keycode - MI_MIN + midiOffset;
#ifdef CONSOLE_ENABLE
	dprintf("-------\n");
	dprintf("[%s] ",record->event.pressed ? "push" : "release");
	dprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

	if(record->event.pressed){ // 押した時と離した時両方で反応すると2回同じものを送信してしまうので分ける
		switch (keycode) {
			case IC_RESET:                    ResetIC();
			case MI_UP:                       midiOffset += 12; break;
			case MI_DN:                       midiOffset -= 12; break;
			case IC_MUTE:                     MidiAllSoundOff(); break;
			case IC_OCTAVE_UP:                OffsetOctave( &icData,  1 ); break;
			case IC_OCTAVE_DN:                OffsetOctave( &icData, -1 ); break;
			case IC_NOTE_UP:                  OffsetNote( &icData,  1 ); break;
			case IC_NOTE_DN:                  OffsetNote( &icData, -1 ); break;
			case IC_Cn_MAJOR ... IC_Cn_MINOR: SetCode( &icData, note_Cn, keycode - IC_Cn_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Cn_MAJOR ); break;
			case IC_Cs_MAJOR ... IC_Cs_MINOR: SetCode( &icData, note_Cs, keycode - IC_Cs_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Cs_MAJOR ); break;
			case IC_Dn_MAJOR ... IC_Dn_MINOR:
	PrintStatus(&icData);
	dprintf("sub%d\n", keycode - IC_Dn_MAJOR);
											  SetCode( &icData, note_Dn, keycode - IC_Dn_MAJOR);
	PrintStatus(&icData);
											  UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Dn_MAJOR );
	PrintStatus(&icData);
											  break;
			case IC_Ds_MAJOR ... IC_Ds_MINOR: SetCode( &icData, note_Ds, keycode - IC_Ds_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Ds_MAJOR ); break;
			case IC_En_MAJOR ... IC_En_MINOR: SetCode( &icData, note_En, keycode - IC_En_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_En_MAJOR ); break;
			case IC_Fn_MAJOR ... IC_Fn_MINOR: SetCode( &icData, note_Fn, keycode - IC_Fn_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Fn_MAJOR ); break;
			case IC_Fs_MAJOR ... IC_Fs_MINOR: SetCode( &icData, note_Fs, keycode - IC_Fs_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Fs_MAJOR ); break;
			case IC_Gn_MAJOR ... IC_Gn_MINOR: SetCode( &icData, note_Gn, keycode - IC_Gn_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Gn_MAJOR ); break;
			case IC_Gs_MAJOR ... IC_Gs_MINOR: SetCode( &icData, note_Gs, keycode - IC_Gs_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Gs_MAJOR ); break;
			case IC_An_MAJOR ... IC_An_MINOR: SetCode( &icData, note_An, keycode - IC_An_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_An_MAJOR ); break;
			case IC_As_MAJOR ... IC_As_MINOR: SetCode( &icData, note_As, keycode - IC_As_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_As_MAJOR ); break;
			case IC_Bn_MAJOR ... IC_Bn_MINOR: SetCode( &icData, note_Bn, keycode - IC_Bn_MAJOR); UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, keycode - IC_Bn_MAJOR ); break;
		}
	}

	// IC_PLAY_CODEはギターの弦全部を鳴らした状態を想定 なので直前にall sound offを送っている。
	// Cを例にコード理論のC,Cm,C7,CM7,Cm7,CmM7,C9,Cadd9,Csus4,Cdim,Cm7-5が使えるはず
	// すごくわかりづらいがM7は7を半音上げたもの。Cm7とCM7が何かの対になっていたりはしない。Cm7はC(m)(7)、CmM7はC(m)(M7)のような意味。
	// 同様にCm7-5はC(m7)(-5)のような意味
	switch (keycode) { // 押した時と離した時両方で反応して欲しいキーの設定
		case MI_0001 ... MI_0036:         if(tmpNoteNum >= 0 && tmpNoteNum <= 127){ midi_send_noteon(&midi_device, midi_channel, tmpNoteNum, record->event.pressed ? 64 : 0); } break;
		case IC_string01 ... IC_string06: PlayStrings( &icData, keycode - IC_string01, midi_channel, record, true); break;
		case IC_SHARP:                    icData.isSharped = record->event.pressed; break;
		case IC_PLAY_CODE:                MidiAllSoundOff(); PlayCode( &icData, midi_channel, record ); break;
		case IC_7th:                      UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, SEVENTH ); break;
		case IC_9th:                      UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, NINETH ); break;
		case IC_M7:                       UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, MAJORSEVENTH ); break;
		case IC_dim:                      UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, DIMINISH ); break;
		case IC_aug:                      UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, AUGUMENT ); break;
		case IC_sus4:                     UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, SUSTAIN ); break;
		case IC_m7sub5:                   UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, MINOR );
		                                  UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, SEVENTH );
		                                  UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, SUBFIFTH ); break;
		case IC_key01 ...  IC_key18:      PlayNote( icData.keys[keycode - IC_key01], midi_channel, record->event.pressed );
		                                  dprintf("(%s)", NoteToString(icData.keys[keycode - IC_key01])); break;
		case IC_REVERSE:                  UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, REVERSE ); break;
	}
	UpdateStatus( &icData, record->event.pressed, &icData.codeStatus, KEEP );
	PrintStatus(&icData);
	return true;
} // }}}

