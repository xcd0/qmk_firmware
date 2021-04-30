#include "icDefineCode.h"

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
	uint8_t codeType     // Majorとかを表す数値
){
	icData->baseNote     = note;
	if(codeType < 9) icData->codeType = codeType;
}


