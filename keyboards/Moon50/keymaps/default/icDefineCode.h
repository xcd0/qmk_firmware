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


// IcData.codeStatus で使われることを想定 ちなみにpromicroのavr-gccはchar 1byte, int 2byte, short 2byte, long 4byte, long long 8byte
// uint16_tにした
// Majorを分けているのはC7とCM7が違うらしいので判別するため
// Mやm以外のやつが指定されていないときはNormalもMajor扱いする
typedef enum {    // bit Type     実際のbitのイメージ
	KEEP = -1,          //  -1 ステータスを更新しない
	NORMAL = 0,         //  0   指定なし 0b 0000 0000 0000 0000  0
	REVERSE,            //  1   reverse  0b 0000 0000 0000 0001  1
	MINOR,              //  2   m        0b 0000 0000 0000 0010  2
	SEVENTH,            //  3   7        0b 0000 0000 0000 0100  4
	MAJORSEVENTH,       //  4   M7       0b 0000 0000 0000 1000  8
	NINETH,             //  5   9        0b 0000 0000 0001 0000  16
	ADDNINETH,          //  6   add9     0b 0000 0000 0010 0000  32
	DIMINISH,           //  7   dim      0b 0000 0000 0100 0000  64
	AUGUMENT,           //  8   aug      0b 0000 0000 1000 0000  128
	SUSTAIN,            //  9   sus      0b 0000 0001 0000 0000  256
	SUBFIFTH            //  10  -5       0b 0000 0010 0000 0000  512
} CodeStatusBit;

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

	uint16_t  codeStatus       ; // = 0;                 // 本実装 ビット演算する 0はMajor
	int16_t   notes[ 16 ]      ; // = {};                // 和音の音オフセット配列 同時に鳴らしたい音を入れる 取り合えず2byte x 16音にしている -1は鳴らさない想定
	int16_t   keys[ 18 ]       ; // = {};                // 右手18キーに割り当ててみる

	char      isSharped        ; // = false;             // # が押されているか 半音あげる
} IcData;

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

// IcDataのcodeStatusから和音の音オフセット配列notesを計算する
// -1 が入っていたらオフセット配列終了
void CalcNoteOffset(IcData* icData);

uint8_t GetOffsetNoteWithDegree(
	uint8_t noteNum,     // 音階 0~127
	uint8_t offsetDegree // 音数
);

int16_t CalcNote(
	uint8_t in,     // root
	uint8_t degree, // 度数
	uint8_t isLong  // 長or短
);

void CalcNotes(
	uint8_t     in,         // root
	uint16_t    keyState,   // keyを表す2進数値
	int16_t     notes[ 16 ] // 戻り値 配列を上書きする
);

void SetScaleKeys(
	uint8_t     rootNote,         // root
	uint16_t    keyState,   // keyを表す2進数値
	int16_t     keys[ 18 ]  // 戻り値 配列を上書きする
);

#endif
