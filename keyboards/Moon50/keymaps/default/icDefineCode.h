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
};       // 音 オクターブ-1相当 0=C ~ 11=B

enum codeType {
	MEJAR = 0,          // 0 Mejar
	MINOR,              // 1 Minor
	SEVENS,             // 2 Sevens
	MEJARSEVENS,        // 3 MejarSevens
	MINORSEVENS,        // 4 MinorSevens
	MINORMEJORSEVENS,   // 5 MinorMejorSevens
	DIMINISH,           // 6 Diminish
	AUGUMENT,           // 7 Augument
	SUSTAIN             // 8 Sustain
};

enum codeBase {
	CodeBase_C = 60, // とりあえずC4
	CodeBase_D = 62,
	CodeBase_E = 64,
	CodeBase_F = 65,
	CodeBase_G = 67,
	CodeBase_A = 69,
	CodeBase_B = 71,
};

// const uint8_tのsize=4の配列へのポインタが返る -1は鳴らさない
// icCodeBase は コードの一番低い音のノート番号
// icCodeType は Mejorとか
const uint8_t* GetCodeArray(uint8_t icCodeBase, uint8_t icCodeType);

// icCodeBaseを現在のオフセット量から+1or-1するだけの関数 // キーボードからのオフセット値は+1か-1だから
// 要はC4からC5やC3にする
void OffsetCodeBase(
	IcData* icData,    // 設定
	int diffOffset // オフセット値
);

// icDefineCode.cで定義 [codeType] で和音の4音へのオフセット値が入っている
// -1は鳴らさない
// 例 icCodeOffsetArray[0] -> { 0, 4, 7, -1 }, // Mejar
extern const uint8_t icCodeOffsetArray[9][4];


// memo : 普通ギターのCの6つの弦は E1, C2, E2, G2, C3, E3

struct IcData{
	bool    reverse              = false;             // insta code の ~ 相当
	uint8_t baseNote             = 0;                 // 音 icDefineCode.hのenum note
	uint8_t octaveOffset         = 1;                 // オクターブオフセット  min=-1 max=9
	uint8_t noteOffset           = 0;                 // 半音単位でのオフセット いわゆる変調
	const uint8_t** icCodeOffset = icCodeOffsetArray; // icDefineCode.c で定義されている和音のそれぞれの音baseからのoffset配列へのポインタ
};

// 和音を設定する
void SetCode(
	IcData* icData,      // 設定
	uint8_t note,        // ドレミ icDefineCode.hのnote
	uint8_t noteOffset,  // 半音単位でのオフセット いわゆる変調
	uint8_t codeType     // Majorとかを表す数値
);


#endif
