#include "keymap_jp.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,      R00, R01, R02, R03, R04, R05, R06, R07, R17, \
    L10, L11, L12, L13, L14, L15,      R10, R11, R12, R13, R14, R15, R16, R27, \
    L20, L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,      R30, R31, R32, R33, R34, R35, R36, \
         L41, L42, L43, L44,           R40, R41,      R43, R44 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   KC_NO, KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   KC_NO, KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   KC_NO, KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   KC_NO, KC_NO }, \
    {KC_NO,  L41,   L42,   L43,   L44, KC_NO,   KC_NO, KC_NO }, \
    { R00,   R01,   R02,   R03,   R04,   R05,   R06,   R07   }, \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,   R17   }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   R27   }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,   KC_NO }, \
    { R40,   R41,   KC_NO, R43,   R44,   KC_NO, KC_NO, KC_NO }  \
  }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
			KC_ESC  , KC_1    , KC_2    , KC_3         , KC_4          , KC_5         , KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , KC_MINS , KC_EQL  , KC_BSLS , KC_GRV ,
			KC_TAB  , KC_Q    , KC_W    , KC_E         , KC_R          , KC_T         , KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_LBRC , KC_RBRC , KC_BSPC ,
			KC_LCTL , KC_A    , KC_S    , KC_D         , KC_F          , KC_G         , KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT , KC_ENT  ,
			KC_LSFT , KC_Z    , KC_X    , KC_C         , KC_V          , KC_B         , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT , MO(1)   ,
			          KC_HOME , KC_LGUI , KC_SPC       , LT(1,KC_MHEN) , LT(2,KC_HENK) , KC_SPC           , KC_INS , KC_END
//			          KC_HOME , KC_LGUI , LT(1,KC_SPC) , KC_MHEN       , KC_HENK , LT(2,KC_SPC)           , KC_INS , KC_END
			),
	[1] = LAYOUT(
			KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,  KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
			       KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO,   KC_NO,          KC_NO,   KC_NO
			),
	[2] = LAYOUT(
			KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO ,
			KC_NO , JP_TILD , JP_UNDS , JP_DQUO , JP_QUOT , JP_GRV  , JP_LPRN , JP_LABK , JP_LCBR , JP_LBRC , JP_AT   , KC_NO , KC_NO , KC_NO ,
			KC_NO , JP_PLUS , JP_MINS , JP_ASTR , JP_EQL  , JP_DLR  , JP_RPRN , JP_RABK , JP_RCBR , JP_RBRC , JP_COLN , KC_NO , KC_NO ,
			KC_NO , KC_NO   , JP_EXLM , JP_QUES , JP_HASH , JP_PERC , KC_NO   , JP_AMPR , JP_PIPE , JP_CIRC , JP_BSLS , KC_NO , KC_NO ,
			        KC_NO   , KC_NO   , KC_NO   , KC_NO             , KC_NO   , KC_NO             , KC_NO   , KC_NO
			)
};


