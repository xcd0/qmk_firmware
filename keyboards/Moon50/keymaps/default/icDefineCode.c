#include "icDefineCode.h"
#include "print.h"
#include <stdio.h>

// icCodeBaseを現在のオフセット量から+1or-1するだけの関数
// キーボードからのオフセット値は+1か-1なので
// 要はC4からC5やC3にする
void OffsetOctave(
	IcData* icData,  // 設定
	int octaveOffset // オフセット値
){
	if(octaveOffset < 0 && icData->octaveOffset > -1){ icData->octaveOffset--; }
	else if(octaveOffset > 0 && icData->octaveOffset < 9){ icData->octaveOffset++; }
}

void OffsetNote(
	IcData* icData, // 設定
	int noteOffset   // オフセット値
){
	if(noteOffset < 0 ){ icData->noteOffset--; }
	else if(noteOffset > 0 ){ icData->noteOffset++; }
}

// 和音を設定する
void SetCode(
	IcData* icData,      // 設定
	uint8_t note,        // ドレミ icDefineCode.hのnote
	uint8_t isMinor      // メジャーかどうか 7とかaugとかは別で設定する
){
	icData->baseNote     = note;
	if(isMinor){
		icData->codeStatus &= ~(1UL << (MINOR - 1)); // 
	}else{
		icData->codeStatus |= 1UL << (MINOR - 1);
	}
}

// 指定した度数分上のノート番号を計算する
// 度と音の違いがある ピアノで言えば3度と言ったとき間に黒鍵がどれだけ入るかがどの音からかで変わる
// ド,3ならミの4を返す感じ ド,4ならファの5になる レ,3ならファの6になる ファ,3ならラの9になる
// 0,3->4  0,4->6  2,3->6  6,3->10  60,3->64, 65,3->69
//                 音階数   度数(-は短 +は長とする)
// C     (C,E,G)     0,4,7    1,3,5
// C7    (C,E,G,Bb)  0,4,7,10 1,3,5,-7         ド#  レ#     ファ# ソ# ラ#
// CM7   (C,E,G,B)   0,4,7,11 1,3,5            1C#  3D#      6F#  8G# 10A#
// Cm7   (C,Eb,G,Bb) 0,3,7,10 1,3,5          ド   レ  ミ  ファ  ソ  ラ  シ  ド
// CmM7  (C,Eb,G,B)  0,3,7,11                0C   2D  4E  5F    7G  9A  11B 12C
//
// Db    (Db,F,Ab)   1,5,8    1,3,5
// Db7   (Db,F,Ab,B) 1,5,8,11 1,3,5,-7
// DbM7  (Db,F,Ab,C) 1,5,8,12 1,3,5
// Dbm7  (Db,E,Ab,B) 1,4,8,11 1,3,5
// DbmM7 (Db,E,Ab,C)
//
// D     (D,F#,A)     2,6,9    1,3,5
// D7    (D,F#,A,C)   2,6,9,12 1,3,5,-7
// DM7   (D,F#,A,C#)  2,6,9,13 1,3,5
// Dm7   (D,E,A,C)    2,5,9,12 1,3,5
//
// スケール                             note                      degree
// メジャースケール                     0,2,4,5,7,9,11            1 2 3 4 5 6 7
// メロディックマイナースケール         0,2,3,5,7,9,11            1 2 b3 4 5 6 7         // jazz
// ドリアンスケール                     0,2,3,5,7,9,10            1 2 b3 4 5 6 b7        // 教会旋法
// フリジアンスケール                   0,2,3,5,7,8,10            1 b2 b3 4 5 b6 b7      // 教会旋法
// リディアンスケール                   0,2,4,6,7,9,11            1 2 3 #4 5 6 7         // 教会旋法
// ミクソリディアンスケール             0,2,4,5,7,9,10            1 b2 b3 4 b5 b6 b7     // 教会旋法
// ロクリアンスケール                   0,1,3,5,6,8,10            1 b2 b3 4 b5 b6 b7     // 教会旋法
// //
// ナチュラルマイナースケール           0,2,3,5,7,8,10            1 2 b3 4 5 b6 b7
// ハーモニックマイナースケール         0,2,3,5,7,8,11            1 2 b3 4 5 b6 7     // あんまり使われない
// ディミニッシュスケール               0,2,3,5,6,8,9,11          1 2 b3 4 b5 #5 6 7
// ドミナントディミニッシュスケール     0,1,3,4,6,7,9,11          1 b2 b3 b4 b5 5 6 b7
// ホールトーンスケール                 0,2,4,6,8,10              1 2 3 #4 b6 b7
// シンメトリックオーギュメントスケール 0,3,4,7,8,11              1 b3 3 5 #5 7
// クロマチックスケール                 0,1,2,3,4,5,6,7,8,9,10,11 1 #1 2 #2 3 4 #4 5 #5 6 #6 7
// メジャーペンタトニックスケール       0,2,4,7,9                 1 2 3 5 6
// マイナーペンタトニックスケール       0,3,5,7,10                1 b3 4 5 b7
// ブルーススケール                     0,2,3,4,7,9               1 2 b3 3 5 6
// マイナーブルーススケール             0,2,5,6,7,10              1 b3 4 b5 5 b7
// ブルー・ノート・スケール             0,2,3,4,5,6,7,9,10,11     1 2 b3 3 4 b5 5 6 b7 7
// 呂旋法（雅楽）                       0,2,4,7,9                 1 2 3 5 6
// 律旋法（雅楽）                       0,2,5,7,9                 1 2 4 5 6
// 琉球音階                             0,4,5,7,11                1 3 4 5 7
//
// |    | 完全5度 |    |    C(0)->5度->G(7)は+7でB(11)->5度->F(11)は+6
// | 減 | 短 | 長 | 増 |    同じ度数でも差が大きい方が長で差が小さい方が短
// |    |    |    |    |    短より半音低いのが減で長より半音高いのが増
//
uint8_t GetOffsetNoteWithDegree(
	uint8_t noteNum,     // 音階 0~127
	uint8_t offsetDegree // 音数
){
	uint8_t tmpDegree = 1;
	uint8_t offsetNote = noteNum + 1; // これを返す 入力ノートの次からカウントする

	//std::cout << "n" << (int)noteNum << " " << std::left << std::setw(6) << NoteToString(noteNum) << ",";
	//std::cout << "offsetDegree" << (int)offsetDegree << ",tmpDegree" << (int)tmpDegree << std::endl;
	for(; tmpDegree < offsetDegree; offsetNote++){
		switch( offsetNote % 12 ){ // 次の音が白鍵なら度数としてカウントする
			case 1:  // C#
			case 3:  // D#
			case 6:  // F#
			case 8:  // G#
			case 10: // A#
				break; // 黒鍵はカウントしない
			default: // 白鍵
				tmpDegree++;
		}
		//std::cout << "o" << (int)offsetNote << " " << std::left << std::setw(6) << NoteToString(offsetNote) << ",";
		//std::cout << "offsetDegree" << (int)offsetDegree << ",tmpDegree" << (int)tmpDegree << std::endl;
		if(tmpDegree == offsetDegree){
			return offsetNote;
		}
	}
	// 来ないはず
	return offsetNote-1;
}

// @return 0 完全
// @return 1 長
// @return 2 短
// @return 3 増
// @return 4 減
// @return 5 8度以上
// @return 6 バグ
uint8_t JudgeDegreeType(
	uint8_t degree,  // 度数
	uint8_t noteDiff // 半音数
){
	if(noteDiff > 8 ){ // 8度以上は何も表示しない
		return 5;
	}else
	if( degree == 0
	 || degree == 1
	 || degree == 4
	 || degree == 5
	 || degree == 8 ){ // 度数1,4,5,8は長短なし
		if(noteDiff == 6){
			//printf("減5度");  // 減5度
			return 4;
		}else if(noteDiff == 8){
			//printf("増5度");  // 増5度
			return 3;
		}else{
			//printf("完全");
			return 0;
		}
	}else                         // 度数2,3,6,7は長短あり 6は減5度の方が言われる
	if( noteDiff == 2  // 長2度
	 || noteDiff == 4  // 長3度
	 || noteDiff == 9  // 長6度
	 || noteDiff == 11 // 長7度
	){
		//printf("長");
		return 1;
	}else
	if( noteDiff == 1  // 短2度
	 || noteDiff == 3  // 短3度
	 || noteDiff == 8  // 短6度
	 || noteDiff == 10 // 短7度
	){
		//printf("短");
		return 2;
	}else{
		//printf("バグ");
		return 6;
	}
}

// inからdegree度上の音で 長または短の音を返す
// noteType 0:完全 // 1:長 // 2:短
int16_t CalcNote(uint8_t in, uint8_t degree, uint8_t noteType){
	int16_t out = (int16_t)GetOffsetNoteWithDegree(in,degree);
	uint8_t ret = JudgeDegreeType(degree,out-in); // 0:完全 // 1:長 // 2:短
	if(ret == 0) {
		return out;
	} else {
		switch(noteType){
			case 0: return out;
			case 1: return (ret == 1) ? out : out + 1; // 長が欲しいので短だったら半音足して返す
			case 2: return (ret == 2) ? out - 1 : out; // 短が欲しいので長だったら半音引いて返す
		}
	}
	return out;
}

void CalcNotes(
	uint8_t     in,         // root
	uint16_t    keyState,   // keyを表す2進数値
	int16_t     notes[ 16 ] // 戻り値 配列を上書きする
){
	for( uint8_t i = 0; i < 16; i++ ){ notes[i] = -1; } // リセット -1は鳴らさない
	notes[0] = (int16_t)in;

	if( keyState & ~1UL ){ // 1bit目以外にフラグが立っていたら
		keyState &= ~1UL; // 1bit目を0にする
	}

	// Major or Minor or Diminish or Susteain 4 or Augument

	if( keyState == 0 ){ // 指定なし ピュアなメジャーコード
		notes[1] = CalcNote(in,3,1);     // 長3度
		notes[2] = CalcNote(in,5,0);     // 完全5度
	} else if( keyState & 1UL << (MINOR - 1 )){
		notes[1] = CalcNote(in,3,2);     // 短3度
		notes[2] = CalcNote(in,5,0);     // 完全5度
	} else if( keyState & 1UL << (DIMINISH - 1 )){
		notes[1] = in + (int16_t)3;
		notes[2] = in + (int16_t)6;
	} else if( keyState & 1UL << (SUSTAIN - 1 )){
		notes[1] = CalcNote(in,3,0) + (int16_t)1; // 増3度
		notes[2] = CalcNote(in,5,0);     // 完全5度
	} else if( keyState & 1UL << (AUGUMENT - 1 )){
		notes[1] = CalcNote(in,3,1);     // 長3度
		notes[2] = CalcNote(in,5,0) + (int16_t)1; // 増5度
	}

	if( keyState & 1UL << SEVENTH ){
		notes[3] = CalcNote(in,7,false); // 7 or m7
	}else if( keyState & 1UL << (MAJORSEVENTH - 1 )){ // M7 or mM7
		notes[3] = CalcNote(in,7,true);
	} else if( keyState & 1UL << (NINETH - 1 )){ // 9は2度を抑えるものとする 9度の場合はadd9を使う
		notes[4] = CalcNote(in,2,true); // 9
	} else if( keyState & 1UL << (ADDNINETH - 1 )){
		notes[5] = CalcNote(in,9,true); // add9
	} else if( keyState & 1UL << (SUBFIFTH - 1 )){
		notes[2] = CalcNote(in,5,true) - (int16_t)1; // 減5度
	}
}

// スケール                             note                      degree
// メジャースケール                     0,2,4,5,7,9,11            1 2 3 4 5 6 7
// メロディックマイナースケール         0,2,3,5,7,9,11            1 2 b3 4 5 6 7         // jazz
// ディミニッシュスケール               0,2,3,5,6,8,9,11          1 2 b3 4 b5 #5 6 7
void SetScaleKeys(
	uint8_t     rootNote,         // root
	uint16_t    keyState,   // keyを表す2進数値
	int16_t     keys[ 18 ]  // 戻り値 配列を上書きする
){
	for( uint8_t i = 0; i < 18; i++ ){ keys[i] = -1; } // リセット -1は鳴らさない
	keys[3] = (int16_t)rootNote;

	// Major or Minor or Diminish or Susteain 4 or Augument
	uint8_t isReversed, isMinor;
	isReversed = keyState & 1UL << (REVERSE-1);
	isMinor = keyState & 1UL << (MINOR-1);

	if( ( isReversed && isMinor ) || keyState == 0 ){ // メジャースケール                     0,2,4,5,7,9,11            1 2 3 4 5 6 7
		keys[0] = keys[3] - 12 + 7;
		keys[1] = keys[3] - 12 + 9;
		keys[2] = keys[3] - 12 + 11;
		keys[4] = keys[3] + 2;
		keys[5] = keys[3] + 4;
		keys[6] = keys[3] + 5;
		keys[7] = keys[3] + 7;
		keys[8] = keys[3] + 9;
		keys[9] = keys[3] + 11;
		keys[10] = keys[3] + 12;
		keys[11] = keys[3] + 12 + 2;
		keys[12] = keys[3] + 12 + 4;
		keys[13] = keys[3] + 12 + 5;
		keys[14] = keys[3] + 12 + 7;
		keys[15] = keys[3] + 12 + 9;
		keys[16] = keys[3] + 12 + 11;
		keys[17] = keys[3] + 12 + 12;
	} else if( ( isReversed && !isMinor ) || ( !isReversed && isMinor ) ){ // メロディックマイナースケール         0,2,3,5,7,9,11            1 2 b3 4 5 6 7         // jazz
		keys[0] = keys[3] - 12 + 7;
		keys[1] = keys[3] - 12 + 9;
		keys[2] = keys[3] - 12 + 11;
		keys[4] = keys[3] + 2;
		keys[5] = keys[3] + 3;
		keys[6] = keys[3] + 5;
		keys[7] = keys[3] + 7;
		keys[8] = keys[3] + 9;
		keys[9] = keys[3] + 11;
		keys[10] = keys[3] + 12;
		keys[11] = keys[3] + 12 + 2;
		keys[12] = keys[3] + 12 + 3;
		keys[13] = keys[3] + 12 + 5;
		keys[14] = keys[3] + 12 + 7;
		keys[15] = keys[3] + 12 + 9;
		keys[16] = keys[3] + 12 + 11;
		keys[17] = keys[3] + 12 + 12;
	} else if( keyState & 1UL << (DIMINISH - 1)){ // ディミニッシュスケール               0,2,3,5,6,8,9,11          1 2 b3 4 b5 #5 6 7
		keys[0] = keys[3] - 12 + 8;
		keys[1] = keys[3] - 12 + 9;
		keys[2] = keys[3] - 12 + 11;
		keys[4] = keys[3] + 2;
		keys[5] = keys[3] + 3;
		keys[6] = keys[3] + 5;
		keys[7] = keys[3] + 6;
		keys[8] = keys[3] + 8;
		keys[9] = keys[3] + 9;
		keys[10] = keys[3] + 11;
		keys[11] = keys[3] + 12;
		keys[12] = keys[3] + 12 + 2;
		keys[13] = keys[3] + 12 + 3;
		keys[14] = keys[3] + 12 + 5;
		keys[15] = keys[3] + 12 + 6;
		keys[16] = keys[3] + 12 + 8;
		keys[17] = keys[3] + 12 + 9;
	}
}

