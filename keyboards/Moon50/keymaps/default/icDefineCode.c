#include "icDefineCode.h"

const uint8_t icCodeOffsetArray = {
  { 0, 4, 7, 12, 16, 19 }, // 0 Mejar
  { 0, 3, 7, 12, 15, 19 }, // 1 Minor
  { 0, 4, 7, 10, 12, 16 }, // 2 Sevens
  { 0, 4, 7, 11, 12, 16 }, // 3 MejarSevens
  { 0, 3, 7, 10, 12, 15 }, // 4 MinorSevens
  { 0, 3, 7, 11, 12, 15 }, // 5 MinorMejorSevens
  { 0, 3, 6, 12, 15, 18 }, // 6 Diminish
  { 0, 4, 8, 12, 16, 20 }, // 7 Augument
  { 0, 5, 7, 12, 17, 19 }, // 8 Sustain
  { 0, 0, 0,  0,  0,  0 }, // 9 エラー
};

const uint8_t* GetMejar(){ return codeOffset[0]; }
const uint8_t* GetMinor(){ return codeOffset[1]; }
const uint8_t* GetSevens(){ return codeOffset[2]; }
const uint8_t* GetMejarSevens(){ return codeOffset[3]; }
const uint8_t* GetMinorSevens(){ return codeOffset[4]; }
const uint8_t* GetMinorMejorSevens(){ return codeOffset[5]; }
const uint8_t* GetDiminish(){ return codeOffset[6]; }
const uint8_t* GetAugument(){ return codeOffset[7]; }
const uint8_t* GetSustain(){ return codeOffset[8]; }

const uint8_t* GetCodeArray(uint8_t icCodeType){
	codeOffset[ icCodeType < 9 ? icCodeType : 9 ];
}

// icCodeBaseを現在のオフセット量から+1or-1するだけの関数
// キーボードからのオフセット値は+1か-1なので
// 要はC4からC5やC3にする
void OffsetCodeBase(
	IcData* icData,    // 設定
	int diffOffset // オフセット値
){
	if(diffOffset < 0 && icData->offsetValue > -1){ *offsetValue--; }
	else if(diffOffset > 0 && icData->offsetValue < 9){ *offsetValue++; }
}

// 和音を設定する
void SetCode(
	IcData* icData,      // 設定
	uint8_t note,        // ドレミ icDefineCode.hのnote
	uint8_t noteOffset,  // 半音単位でのオフセット いわゆる変調
	uint8_t codeType     // Majorとかを表す数値
){
	icData->baseNote     = baseNote;
	icData->noteOffset   = noteOffset;
	icData->icCodeOffset = GetCodeArray(codeBaseNote + icCodeBaseOffset, codeType);
}


