#ifndef _IC_DEFINE_CODE
#define _IC_DEFINE_CODE

enum note { // n:ナチュラル s:シャープ b:フラット
	note_Cn = 0, note_Cs = 1,
	note_Dn = 2, note_Ds = 3,
	note_En = 4,
	note_Fn = 5, note_Fs = 6,
	note_Gn = 7, note_Gs = 8,
	note_An = 9, note_As = 10,
	note_Bn = 11,
};

enum codeType {
	MAJOR = 0,          // 0 Major
	MINOR,              // 1 Minor
	SEVENS,             // 2 Sevens
	MAJORSEVENS,        // 3 MajarSevens
	MINORSEVENS,        // 4 MinorSevens
	MINORMEJORSEVENS,   // 5 MinorMejorSevens
	DIMINISH,           // 6 Diminish
	AUGUMENT,           // 7 Augument
	SUSTAIN             // 8 Sustain
};


// memo : 普通ギターのCの6つの弦は E1, C2, E2, G2, C3, E3
// uint8_t ic[9][6] = {
//   { 0, 4, 7, 12, 16, 19 }, // 0 Major
//   { 0, 3, 7, 12, 15, 19 }, // 1 Minor
//   { 0, 4, 7, 10, 12, 16 }, // 2 Sevens
//   { 0, 4, 7, 11, 12, 16 }, // 3 MajorSevens
//   { 0, 3, 7, 10, 12, 15 }, // 4 MinorSevens
//   { 0, 3, 7, 11, 12, 15 }, // 5 MinorMejorSevens
//   { 0, 3, 6, 12, 15, 18 }, // 6 Diminish
//   { 0, 4, 8, 12, 16, 20 }, // 7 Augument
//   { 0, 5, 7, 12, 17, 19 }  // 8 Sustain
// };

typedef struct {
	uint8_t   baseNote         ; // = 0;                 // 音 icDefineCode.hのenum note // noteOffsetとの組み合わせでスケールが決まる
	int       octaveOffset     ; // = 1;                 // オクターブオフセット  min=-1 max=9
	int       noteOffset       ; // = 0;                 // 半音単位でのオフセット いわゆる変調
	uint8_t   codeType         ; // = 0;                 // Majorとか
	long      codeStatus       ; // = 0;                 // 
	char      isForsed         ; // = false;             // dimやsusなどの種類変更キーが押されているか
	char      isReversed       ; // = false;             // ~ Reverseが押されているか Major <-> Minor
	char      isSharped        ; // = false;             // # が押されているか 半音あげる
	uint8_t   pressedForseCode ; // = 0;                 // 押されているコード種類変更キー enum codeTypeが入るのを想定
	uint8_t   icCodeOffsetArray[9][6]; // = icCodeOffsetArray; // 和音のそれぞれの音baseからのoffset配列へのポインタ
}IcData;

// 和音を設定する
extern void SetCode(
	IcData* icData,      // 設定
	uint8_t note,        // ドレミ icDefineCode.hのnote
	uint8_t codeType     // Majorとかを表す数値
);

// icDataのoctaveOffsetを現在のオフセット量から+1or-1する
// 要はC4からC5やC3にする
extern void OffsetOctave(
	IcData* icData,  // 設定
	int octaveOffset   // オフセット値
);
// icDataのnoteOffsetを現在のオフセット量から+1or-1する
extern void OffsetNote(
	IcData* icData,    // 設定
	int noteffset // オフセット値
);


#endif
