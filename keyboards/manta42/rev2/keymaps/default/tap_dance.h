#ifndef _HEADER_TAP_DANCE
#define _HEADER_TAP_DANCE

#include QMK_KEYBOARD_H

#include "process_keycode/process_tap_dance.h"

// タップダンスで使うキーを定義
// 命名規則は
// * TD_A_Bなら1回でA、2回でBとする。
// * TD_A@B_C なら1回でA、1回目長押しでB、2回でCとする。

enum td_keycodes { // タップダンスのキーコード
	TD_HOMEhMHEN = 0, TD_ENDhHENK, TD_ESChL1, TD_TABhL2, TD_INSERThL3, TD_ALThL4,
	TD_NUM // タップダンスが定義された個数
};

typedef struct { bool is_press_action; uint8_t state; } tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_SINGLE_TAP, TAPDANCE_OUTOFRANGE }; // タップダンス状態を定義

//   1回押し,    1回押しホールド, 2回連打
//   SINGLE_TAP, SINGLE_HOLD,     DOUBLE_SINGLE_TAP
uint16_t tapdanceArray[TD_NUM][3] = {
	{ JP_HOME,    JP_MHEN,         XXXXXXX }, // TD_HOMEhMHEN
	{  JP_END,    JP_HENK,         XXXXXXX }, // TD_ENDhHENK
	{  JP_ESC,         L1,         XXXXXXX }, // TD_ESChL1
	{  JP_TAB,         L2,         XXXXXXX }, // TD_TABhL2
	{  JP_INS,         L3,         XXXXXXX }, // TD_INSERThL3
	{ JP_LALT,         L4,         XXXXXXX }  // TD_ALThL4
};


static tap td_key_state[ TD_NUM ] = { {1,0}, {1,0}, {1,0}, {1,0}, {1,0}, {1,0} }; // タップダンスキーの状態構造体の初期化

uint8_t cur_dance(qk_tap_dance_state_t *state) { // タップダンス状態判定
	if (state->count == 1) return state->interrupted || !state->pressed ? SINGLE_TAP : SINGLE_HOLD;
	else if (state->count == 2) return DOUBLE_SINGLE_TAP;
	else return TAPDANCE_OUTOFRANGE;
}

// 各タップダンスキーコードのとりうる状態を制御します:
void td_control(qk_tap_dance_state_t *state, int flag, int td_key ){
	td_key_state[td_key].state = cur_dance(state);
	switch( td_key_state[td_key].state ) {
		case SINGLE_TAP: flag ? register_code16( tapdanceArray[td_key][0] ) : unregister_code16( tapdanceArray[td_key][0] ); break;
		case SINGLE_HOLD: flag ? register_code16( tapdanceArray[td_key][1] ) : unregister_code16( tapdanceArray[td_key][1] ); break;
		case DOUBLE_SINGLE_TAP: flag ? register_code16( tapdanceArray[td_key][2] ) : unregister_code16( tapdanceArray[td_key][2] ); break;
	}
}

void td_homehmhen      (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_HOMEhMHEN ); }
void td_homehmhen_reset(qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_HOMEhMHEN ); }
void td_endhhenk       (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_ENDhHENK  ); }
void td_endhhenk_reset (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_ENDhHENK  ); }
void td_eschl1         (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_ESChL1    ); }
void td_eschl1_reset   (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_ESChL1    ); }
void td_tabhl2         (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_TABhL2    ); }
void td_tabhl2_reset   (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_TABhL2    ); }
void td_inserthl3      (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_INSERThL3 ); }
void td_inserthl3_reset(qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_INSERThL3 ); }
void td_althl4         (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 1, TD_ALThL4    ); }
void td_althl4_reset   (qk_tap_dance_state_t *state, void *user_data){ td_control(state, 0, TD_ALThL4    ); }

// それぞれのタップダンスキーコードに適用する `finished` と `reset` 関数
qk_tap_dance_action_t tap_dance_actions[] = {
	[ TD_HOMEhMHEN ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_homehmhen, td_homehmhen_reset ),
	[ TD_ENDhHENK  ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_endhhenk, td_endhhenk_reset ),
	[ TD_ESChL1    ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_eschl1, td_eschl1_reset ),
	[ TD_TABhL2    ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_tabhl2, td_tabhl2_reset ),
	[ TD_INSERThL3 ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_inserthl3, td_inserthl3_reset ),
	[ TD_ALThL4    ] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, td_althl4, td_althl4_reset ),
};

#endif
