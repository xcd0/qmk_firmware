#ifndef _HEADER_5
#define _HEADER_5

#include "rev2.h"
#include "keymap_jp.h"

#define L_Q_S TT(_QWERTY_SHIFT)
#define L_Y_S TT(_YSTRP_SHIFT)
#define T_HO_MH TD(TD_HOMEhMHEN)
#define T_EN_HN TD(TD_ENDhHENK)
#define T_ES_L1 TD(TD_ESChL1)
#define T_TA_L2 TD(TD_TABhL2)
#define T_IN_L3 TD(TD_INSERThL3)
#define T_AL_L4 TD(TD_ALThL4)
#define T_J_ESC TD(TD_J_ESC)

// http://www.keyboard-layout-editor.com/##@_name=msw58&author=xcd0&notes=A%20hand-wiring%20split%20keyboard%20with%203D%20print%20case.%20%20%0Ahttps%2F:%2F%2F%2F%2Fgithub.com%2F%2Fxcd0%2F%2Fmsw58&switchMount=cherry%3B&@_c=%23f7c199&sb=gateron&a:7&f:9&w:2&h:2%3B&=&_x:-2&w:2&h:2%3B&=%3Cb%3EEsc%3C%2F%2Fb%3E%0A%0A%0A%0AF1&_c=%23cccccc&w:2&h:2%3B&=%3Cb%3E1%0A%0A%0A%0AF2&_w:2&h:2%3B&=%3Cb%3E2%0A%0A%0A%0AF3&_w:2&h:2%3B&=%3Cb%3E3%0A%0A%0A%0AF4&_w:2&h:2%3B&=%3Cb%3E4%0A%0A%0A%0AF5&_w:2&h:2%3B&=%3Cb%3E5%0A%0A%0A%0AF6&_x:4&w:2&h:2%3B&=%3Cb%3E6%0A%0A%0A%0AF7&_w:2&h:2%3B&=%3Cb%3E7%0A%0A%0A%0AF8&_w:2&h:2%3B&=%3Cb%3E8%0A%0A%0A%0AF9&_w:2&h:2%3B&=%3Cb%3E9%0A%0A%0A%0AF10&_w:2&h:2%3B&=%3Cb%3E0%0A%0A%0A%0AF11&_w:2&h:2%3B&=%3Cb%3E-%0A%0A%0A%0AF12%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3ETab&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A~%0A%0A%0A%0A%0A%3Cb%3EQ&_w:2&h:2%3B&=%0A%2F_%0A%0A%0A%0A%0A%3Cb%3EW&_w:2&h:2%3B&=%22D%22%0A%22%0A%0A%0A%0A%0A%3Cb%3EE&_a:4&fa@:0&:0&:0&:0&:0&:0&:5&:0&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AQ%3Cbr%3EW%3Cbr%3EE%3Cbr%3ET%3Cbr%3EY%0A%0A%22F%22%0A%3Cb%3ER%0A'&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AE%3Cbr%3EE%3Cbr%3EP%3Cbr%3ER%3Cbr%3ES%3Cbr%3ET%0A%0AG%0A%3Cb%3ET%0A%60&_x:4&a:5&f2:0&w:2&h:2%3B&=%0A%2F&%0A%0A%0A%0A%0A%3Cb%3EY&_a:4&fa@:0&:0&:0&:0&:0&:0&:0&:8&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3EL%0AS%0A%3Cb%3EU%0A(&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3EC%0AT%0A%3Cb%3EI%0A%3C&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3ER%0AR%0A%3Cb%3EO%0A%7B&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AW%3Cbr%3EU%0A%0A%3Cb%3EP%0A%5B&_a:7&w:2&h:2%3B&=%3Cb%3E%2F@%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3EIns%3C%2F%2Fb%3E%3Cbr%3E%E2%86%92Alt&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A+%0A%0A%0A%0A%0A%3Cb%3EA&_w:2&h:2%3B&=O%0A-%0A%0A%0A%0A%0A%3Cb%3ES&_w:2&h:2%3B&=E%0A*%0A%0A%0A%0A%0A%3Cb%3ED&_a:4&fa@:0&:0&:0&:0&:0&:0&:5&:8&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AY%3Cbr%3ES%3Cbr%3ET%3Cbr%3ER%3Cbr%3EP%0A%0AU%0A%3Cb%3EF%0A%2F=&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AR%3Cbr%3ES%3Cbr%3ET%0A%0AI%0A%3Cb%3EG%0A%2F:&_x:4&a:6&fa@:5&:0&:8&:0&:0&:0&:5&:8&:0%3B&w:2&h:2%3B&=%E2%86%90%0A%0AM%3Cbr%3EL%0A%0A%0A%0A%0A%0A%3Cb%3EH&_a:4&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%93%0AM%3Cbr%3ED%0A%0A%3Cb%3EJ%0A)&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%91%0AM%3Cbr%3EU%0A%0A%3Cb%3EK%0A%3E&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%92%0AM%3Cbr%3ER%0A%0A%3Cb%3EL%0A%7D&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AW%3Cbr%3ED%0A%0A%3Cb%3E%2F%3B%0A%5D&_a:7&f2=undefined&w:2&h:2%3B&=%3Cb%3E%2F:%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3EHome&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A!%0A%0A%0A%0A%0A%3Cb%3EZ&_w:2&h:2%3B&=%0A%3F%0A%0A%0A%0A%0A%3Cb%3EX&_w:2&h:2%3B&=%0A%23%0A%0A%0A%0A%0A%3Cb%3EC&_w:2&h:2%3B&=%0A$%0A%0A%0A%0A%0A%3Cb%3EV&_w:2&h:2%3B&=%0A%25%0A%0A%0A%0A%0A%3Cb%3EB&_x:4&a:7&w:2&h:2%3B&=%3Cb%3EN&_w:2&h:2%3B&=%3Cb%3EM&_w:2&h:2%3B&=%3Cb%3E,&_w:2&h:2%3B&=%3Cb%3E.&_w:2&h:2%3B&=%E2%86%91%20jk%5C%3Cbr%3E%3Cb%3E%2F%2F%3C%2F%2Fb%3E&_c=%23f7c199&w:2&h:2%3B&=%3Cb%3EEnd%3B&@_rx:4&ry:18&y:-10&x:-1&c=%23cccccc&w:2&h:2%3B&=%3Cb%3E%E8%8B%B1%3C%2F%2Fb%3E%3Cbr%3E%E2%86%92gui%3B&@_rx:24&y:-10&x:-1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3E%E3%81%8B%E3%81%AA%3B&@_r:15&rx:4&y:-10&x:-1&w:2&h:2%3B&=%3Cb%3ECtrl%3B&@_r:30&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3EShift%3B&@_r:45&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3ESpace%3B&@_r:60&y:-1&x:-1&c=%23d18686&a:5&fa@:0&:5&:0&:0&:0&:0&:0%3B&w:2&h:2%3B&=%0AAlt%0A%0A%0A%0A%0A%3Cb%3E%E2%86%90%3B&@_r:-60&rx:24&y:-10&x:-1&w:2&h:2%3B&=%0AGUI%0A%0A%0A%0A%0A%3Cb%3E%E2%86%92%3B&@_r:-45&y:-1&x:-1&c=%23f7c199&a:7&w:2&h:2%3B&=%E2%86%91%20Del%3Cbr%3E%3Cb%3EBs%3C%2F%2Fb%3E%3B&@_r:-30&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3EEnt%3B&@_r:-15&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3ESymbol%3C%2F%2Fb%3E

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // QWERTY と YSTRP{{{
  // Qwerty
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |   Q   |   W   |   E   |    R   |   T   |                                  |   Y   |   U   |   I   |   O   |   P   |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |   A   |   S   |   D   |    F   |   G   |                                  |   H   | J>Esc |   K   |   L   |   ;   |
  // |-------+-------+-------+--------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------|
  // |   Z   |   X   |   C   |    V   |   B   | ESC~L1| TAB~L2|  |  INS  |  ALT  |   N   |   M   |   ,   |   .   |   /   |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         | Home~英| Space | Shift | Ctrl  |  | Bkspc | Enter |  Del  | End~か|
  //                         `--------------------------------'  `-------------------------------'
  // 英数とかな は無変換と変換を使う これはOSで設定してる前提とする。
  // A~Bはタップホールド tapでA、holdでBになることを表す
  // A>Bはタップダンス   1tapでA、2tapでBになることを表す
  //    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,   T_ES_L1, T_TA_L2,    T_IN_L3, T_AL_L4, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, 
  //
  [_QWERTY] = LAYOUT( \
      JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                                          JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    \
      JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                                          JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, \
      JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,   T_ES_L1, T_TA_L2,    T_IN_L3, T_AL_L4, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, \
                                 T_HO_MH, JP_SPC, L_Q_S,   JP_LCTL,    JP_BSPC, JP_ENT,  JP_DEL,  T_EN_HN \
      ),
  // SHIFTを押してるとき レイヤーを切り替えちゃう
  [_QWERTY_SHIFT] = LAYOUT( \
      S(JP_Q), S(JP_W), S(JP_E), S(JP_R), S(JP_T),                                                S(JP_Y),   S(JP_U), S(JP_I),    S(JP_O),   S(JP_P),    \
      S(JP_A), S(JP_S), S(JP_D), S(JP_F), S(JP_G),                                                S(JP_H),   S(JP_J), S(JP_K),    S(JP_L),   S(JP_SCLN), \
      S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), S(JP_ESC),  S(JP_TAB),  S(JP_INS), S(JP_LALT), S(JP_N),   S(JP_M), S(JP_COMM), S(JP_DOT), S(JP_SLSH), \
                            S(JP_HOME), S(JP_SPC), _______,    S(JP_LCTL), S(JP_BSPC), S(JP_ENT), S(JP_DEL), S(JP_END) \
      ),

  // Ystrp
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |   Q   |   W   |   G   |    F   |   G   |                                  |   Y   |   S   |   T   |   R   |   P   |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |   A   |   O   |   E   |    U   |   I   |                                  |   H   |   J   |   K   |   L   |   ;   |
  // |-------+-------+-------+--------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------|
  // |   Z   |   X   |   C   |    V   |   B   | ESC~L1| TAB~L2|  |  INS  |  ALT  |   N   |   M   |   ,   |   .   |   /   |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         | Home~英| Space | Shift | Ctrl  |  | Bkspc | Enter |  Del  | End~か|
  //                         `--------------------------------'  `-------------------------------'
  // 英数とかな は無変換と変換を使う これはOSで設定してる前提とする。
  // A~Bはタップホールド tapでA、holdでBになることを表す
  // A>Bはタップダンス   1tapでA、2tapでBになることを表す
  [_YSTRP] = LAYOUT( \
      JP_Q,    JP_W,    JP_D,    JP_F,    JP_G,                                                   JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    \
      JP_A,    JP_O,    JP_E,    JP_U,    JP_I,                                                   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, \
      JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,   T_ES_L1, T_TA_L2,    T_IN_L3, T_AL_L4, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, \
                                 T_HO_MH, JP_SPC, L_Q_S,   JP_LCTL,    JP_BSPC, JP_ENT,  JP_DEL,  T_EN_HN \
      ),
  // SHIFTを押してるとき レイヤーを切り替えちゃう
  [ _YSTRP_SHIFT] = LAYOUT( \
      S(JP_Q), S(JP_W), S(JP_D), S(JP_F), S(JP_G),                                               S(JP_Y),   S(JP_S), S(JP_T),    S(JP_R),   S(JP_P),    \
      S(JP_A), S(JP_O), S(JP_E), S(JP_U), S(JP_I),                                               S(JP_H),   S(JP_J), S(JP_K),    S(JP_L),   S(JP_SCLN), \
      S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), S(JP_ESC), S(JP_TAB),  S(JP_INS), S(JP_LALT), S(JP_N),   S(JP_M), S(JP_COMM), S(JP_DOT), S(JP_SLSH), \
                          S(KC_MHEN), S(JP_SPC), S(JP_LSFT), S(JP_LCTL),  S(JP_BSPC), S(JP_ENT), S(JP_DEL), S(JP_HENK) \
      ),
  // }}}


  // layer 1
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |   F1  |   F2  |   F3  |    F4  |   F5  |                                  |   1   |   2   |   3   |   4   |   5   |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |   F6  |   F7  |   F8  |    F9  |  F10  |                                  |   6   |   7   |   8   |   9   |   0   |
  // |-------+-------+-------+--------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------|
  // |  F11  |  F12  |  F13  |   F14  |  F15  |KC_TRNS| Adjust|  |   &   |   |   |   =   |   +   |   -   |   *   |   /   |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         |        | Space |  Ctrl | Shift |  |   !   |   ?   |   ~   |   %   |
  //                         `--------------------------------'  `-------------------------------'
  [_LAYER_1] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    \
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, _______, ADJUST,  JP_AMPR, JP_PIPE, JP_EQL,  JP_PLUS, JP_MINS, JP_ASTR, JP_SLSH, \
                                 XXXXXXX, JP_SPC, JP_LSFT, JP_LCTL, JP_EXLM, JP_QUES, JP_TILD, JP_PERC \
      ),
  // layer 2
  // ,---------------------------------------.                                  ,---------------------------------------.
  // |       |       |PrintSc|ScrLock|PauseBr|                                  |   (   |   )   |   {   |   }   |   @   |
  // |-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------|
  // |       |       | Insert| Home  | PageUp|                                  |   [   |   ]   |   <   |   >   |   :   |
  // |-------+-------+-------+-------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------|
  // |       |       | Delete|  End  | PageDn| Adjust|KC_TRNS|  |   #   |   $   |   `   |   '   |   "   |   _   |   \   |
  // `-----------------------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         |       | Space |  Ctrl | Shift |  |       |       |       |       |
  //                         `-------------------------------'  `-------------------------------'
  [_LAYER_2] = LAYOUT( \
      _______, _______, JP_PSCR, JP_SCLK, JP_PAUS,                                       JP_LPRN, JP_RPRN, JP_LCBR, JP_RCBR, JP_AT,   \
      _______, _______, JP_INS,  JP_HOME, JP_PGUP,                                       JP_LBRC, JP_RBRC, JP_LT,   JP_GT,   JP_COLN, \
      _______, _______, JP_DEL,  JP_END,  JP_PGDN, ADJUST,  _______,   JP_HASH, JP_DLR,  JP_BQT,  JP_QT,   JP_DQT,  JP_UNDS, JP_BSLS, \
                                 XXXXXXX, JP_SPC,  JP_LSFT, JP_LCTL,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  // Adjust
  // L1とL2を両方同時押しするとこのレイヤー(になってほしい..
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |       | m.Up  |       |m.wh.up |       |                                  |       |       |       |       |       |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |m.Left |m.Down |m.Right|m.wh.dn |       |                                  |  left |  down |  up   | right |       |
  // |-------+-------+-------+--------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------|
  // |Click_L|Click_M|Click.R|        |       |KC_TRNS|KC_TRNS|  |       |       |       |       |       |       |       |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         |        |       |       |       |  |       |       |       |       |
  //                         `--------------------------------'  `-------------------------------'
  [_ADJUST] = LAYOUT( \
      XXXXXXX, JP_MS_U, XXXXXXX, JP_WH_U, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      JP_MS_L, JP_MS_D, JP_MS_R, JP_WH_D, XXXXXXX,                                     JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX, \
      JP_BTN1, JP_BTN3, JP_BTN2, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                        XXXXXXX, QWERTY,  YSTRP,   RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  // layer 3
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |       |       |       |        |       |                                  |       |       |       |       |       |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |       |       |       |        |       |                                  |       |       |       |       |       |
  // |-------+-------+-------+--------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------|
  // |       |       |       |        |       |       |       |  |KC_TRNS|       |       |       |       |       |       |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         |        |       |       |       |  |       |       |       |       |
  //                         `--------------------------------'  `-------------------------------'
  [_LAYER_3] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),
  // layer 4
  // ,----------------------------------------.                                  ,---------------------------------------.
  // |       |       |       |        |       |                                  |       |       |       |       |       |
  // |-------+-------+-------+--------+-------|                                  |-------+-------+-------+-------+-------|
  // |       |       |       |        |       |                                  |       |       |       |       |       |
  // |-------+-------+-------+--------+-------+---------------.  ,---------------+-------+-------+-------+-------+-------|
  // |       |       |       |        |       |       |       |  |       |KC_TRNS|       |       |       |       |       |
  // `-----------------------+--------+-------+-------+-------|  |-------+-------+-------+-------+-------+---------------'
  //                         |        |       |       |       |  |       |       |       |       |
  //                         `--------------------------------'  `-------------------------------'
  [_LAYER_4] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      )
};

#endif
