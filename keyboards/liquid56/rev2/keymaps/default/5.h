#include "rev2.h"
#include "keymap_jp.h"

#define L_Q_S TT(_QWERTY_SHIFT)
#define L_Y_S TT(_QWERTY_SHIFT)

// http://www.keyboard-layout-editor.com/##@_name=msw58&author=xcd0&notes=A%20hand-wiring%20split%20keyboard%20with%203D%20print%20case.%20%20%0Ahttps%2F:%2F%2F%2F%2Fgithub.com%2F%2Fxcd0%2F%2Fmsw58&switchMount=cherry%3B&@_c=%23f7c199&sb=gateron&a:7&f:9&w:2&h:2%3B&=&_x:-2&w:2&h:2%3B&=%3Cb%3EEsc%3C%2F%2Fb%3E%0A%0A%0A%0AF1&_c=%23cccccc&w:2&h:2%3B&=%3Cb%3E1%0A%0A%0A%0AF2&_w:2&h:2%3B&=%3Cb%3E2%0A%0A%0A%0AF3&_w:2&h:2%3B&=%3Cb%3E3%0A%0A%0A%0AF4&_w:2&h:2%3B&=%3Cb%3E4%0A%0A%0A%0AF5&_w:2&h:2%3B&=%3Cb%3E5%0A%0A%0A%0AF6&_x:4&w:2&h:2%3B&=%3Cb%3E6%0A%0A%0A%0AF7&_w:2&h:2%3B&=%3Cb%3E7%0A%0A%0A%0AF8&_w:2&h:2%3B&=%3Cb%3E8%0A%0A%0A%0AF9&_w:2&h:2%3B&=%3Cb%3E9%0A%0A%0A%0AF10&_w:2&h:2%3B&=%3Cb%3E0%0A%0A%0A%0AF11&_w:2&h:2%3B&=%3Cb%3E-%0A%0A%0A%0AF12%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3ETab&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A~%0A%0A%0A%0A%0A%3Cb%3EQ&_w:2&h:2%3B&=%0A%2F_%0A%0A%0A%0A%0A%3Cb%3EW&_w:2&h:2%3B&=%22D%22%0A%22%0A%0A%0A%0A%0A%3Cb%3EE&_a:4&fa@:0&:0&:0&:0&:0&:0&:5&:0&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AQ%3Cbr%3EW%3Cbr%3EE%3Cbr%3ET%3Cbr%3EY%0A%0A%22F%22%0A%3Cb%3ER%0A'&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AE%3Cbr%3EE%3Cbr%3EP%3Cbr%3ER%3Cbr%3ES%3Cbr%3ET%0A%0AG%0A%3Cb%3ET%0A%60&_x:4&a:5&f2:0&w:2&h:2%3B&=%0A%2F&%0A%0A%0A%0A%0A%3Cb%3EY&_a:4&fa@:0&:0&:0&:0&:0&:0&:0&:8&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3EL%0AS%0A%3Cb%3EU%0A(&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3EC%0AT%0A%3Cb%3EI%0A%3C&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AM%3Cbr%3EC%3Cbr%3ER%0AR%0A%3Cb%3EO%0A%7B&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AW%3Cbr%3EU%0A%0A%3Cb%3EP%0A%5B&_a:7&w:2&h:2%3B&=%3Cb%3E%2F@%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3EIns%3C%2F%2Fb%3E%3Cbr%3E%E2%86%92Alt&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A+%0A%0A%0A%0A%0A%3Cb%3EA&_w:2&h:2%3B&=O%0A-%0A%0A%0A%0A%0A%3Cb%3ES&_w:2&h:2%3B&=E%0A*%0A%0A%0A%0A%0A%3Cb%3ED&_a:4&fa@:0&:0&:0&:0&:0&:0&:5&:8&:0&:0&:0%3B&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AY%3Cbr%3ES%3Cbr%3ET%3Cbr%3ER%3Cbr%3EP%0A%0AU%0A%3Cb%3EF%0A%2F=&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0AR%3Cbr%3ES%3Cbr%3ET%0A%0AI%0A%3Cb%3EG%0A%2F:&_x:4&a:6&fa@:5&:0&:8&:0&:0&:0&:5&:8&:0%3B&w:2&h:2%3B&=%E2%86%90%0A%0AM%3Cbr%3EL%0A%0A%0A%0A%0A%0A%3Cb%3EH&_a:4&w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%93%0AM%3Cbr%3ED%0A%0A%3Cb%3EJ%0A)&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%91%0AM%3Cbr%3EU%0A%0A%3Cb%3EK%0A%3E&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%E2%86%92%0AM%3Cbr%3ER%0A%0A%3Cb%3EL%0A%7D&_w:2&h:2%3B&=%0A%0A%0A%0A%0A%0A%0AW%3Cbr%3ED%0A%0A%3Cb%3E%2F%3B%0A%5D&_a:7&f2=undefined&w:2&h:2%3B&=%3Cb%3E%2F:%3B&@_y:1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3EHome&_c=%23cccccc&a:5&w:2&h:2%3B&=%0A!%0A%0A%0A%0A%0A%3Cb%3EZ&_w:2&h:2%3B&=%0A%3F%0A%0A%0A%0A%0A%3Cb%3EX&_w:2&h:2%3B&=%0A%23%0A%0A%0A%0A%0A%3Cb%3EC&_w:2&h:2%3B&=%0A$%0A%0A%0A%0A%0A%3Cb%3EV&_w:2&h:2%3B&=%0A%25%0A%0A%0A%0A%0A%3Cb%3EB&_x:4&a:7&w:2&h:2%3B&=%3Cb%3EN&_w:2&h:2%3B&=%3Cb%3EM&_w:2&h:2%3B&=%3Cb%3E,&_w:2&h:2%3B&=%3Cb%3E.&_w:2&h:2%3B&=%E2%86%91%20jk%5C%3Cbr%3E%3Cb%3E%2F%2F%3C%2F%2Fb%3E&_c=%23f7c199&w:2&h:2%3B&=%3Cb%3EEnd%3B&@_rx:4&ry:18&y:-10&x:-1&c=%23cccccc&w:2&h:2%3B&=%3Cb%3E%E8%8B%B1%3C%2F%2Fb%3E%3Cbr%3E%E2%86%92gui%3B&@_rx:24&y:-10&x:-1&c=%23f7c199&w:2&h:2%3B&=%3Cb%3E%E3%81%8B%E3%81%AA%3B&@_r:15&rx:4&y:-10&x:-1&w:2&h:2%3B&=%3Cb%3ECtrl%3B&@_r:30&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3EShift%3B&@_r:45&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3ESpace%3B&@_r:60&y:-1&x:-1&c=%23d18686&a:5&fa@:0&:5&:0&:0&:0&:0&:0%3B&w:2&h:2%3B&=%0AAlt%0A%0A%0A%0A%0A%3Cb%3E%E2%86%90%3B&@_r:-60&rx:24&y:-10&x:-1&w:2&h:2%3B&=%0AGUI%0A%0A%0A%0A%0A%3Cb%3E%E2%86%92%3B&@_r:-45&y:-1&x:-1&c=%23f7c199&a:7&w:2&h:2%3B&=%E2%86%91%20Del%3Cbr%3E%3Cb%3EBs%3C%2F%2Fb%3E%3B&@_r:-30&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3EEnt%3B&@_r:-15&y:-1&x:-1&w:2&h:2%3B&=%3Cb%3ESymbol%3C%2F%2Fb%3E

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------------.                                  ,-------------------------------------------------------.
   * |Escape|  Tab  |   Q   |   W   |   E   |   R   |   T   |                                  |   Y   |   U   |   I   |   O   |   P   |   @   | Bkspc |
   * |------+-------+-------+-------+-------+-------+-------+                                  |-------+-------+-------+-------+-------+-------+-------|
   * |Insert|       |   A   |   S   |   D   |   F   |   G   |                                  |   H   |   J   |   K   |   L   |   ;   |   :   | Enter |
   * |------+-------+-------+-------+-------+-------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Eisu |       |   Z   |   X   |   C   |   V   |   B   | NUM   | MIDI  |  |       |       |   N   |   M   |   ,   |   .   |   /   |   \   | Kana  |
   * `------------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------------------------------'
   *                                |  Home | Ctrl  | Space | Shift |   L   |  |   R   | Bkspc | Enter |Delete |  End  |
   *                                `---------------------------------------'  `---------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      JP_ESC,  JP_TAB,  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                   /**/                   JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_AT,   JP_BSPC, \
      JP_INS,  _______, JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                   /**/                   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN, JP_ENT,  \
      KC_MHEN, _______, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,     NUM,    MIDI, /**/ _______, _______, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, JP_BKSL, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  LEFT,          /**/          RIGHT,   JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),
  /* SHIFTを押してるとき レイヤーを切り替えちゃう */
  [_QWERTY_SHIFT] = LAYOUT( \
      S(JP_ESC),  S(JP_TAB),  S(JP_Q), S(JP_W), S(JP_E), S(JP_R), S(JP_T),                   /**/                   S(JP_Y), S(JP_U), S(JP_I),    S(JP_O),   S(JP_P),    S(JP_AT),   JP_BSPC, \
      S(JP_INS),  _______,    S(JP_A), S(JP_S), S(JP_D), S(JP_F), S(JP_G),                   /**/                   S(JP_H), S(JP_J), S(JP_K),    S(JP_L),   S(JP_SCLN), S(JP_COLN), JP_ENT,  \
      S(KC_MHEN), _______,    S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), _______, _______, /**/ _______, _______, S(JP_N), S(JP_M), S(JP_COMM), S(JP_DOT), S(JP_SLSH), S(JP_BKSL), KC_HENK, \
                                       S(JP_HOME), S(JP_LCTL),    _______, S(JP_SPC), LEFT,  /**/ RIGHT, S(JP_BSPC), S(JP_ENT), _______, S(JP_END) \
      ),

  /* Ystrp
   * ,------------------------------------------------------.                                  ,-------------------------------------------------------.
   * |Escape|  Tab  |   Q   |   W   |   D   |   F   |   G   |                                  |   Y   |   S   |   T   |   R   |   P   |   @   | Bkspc |
   * |------+-------+-------+-------+-------+-------+-------+                                  |-------+-------+-------+-------+-------+-------+-------|
   * |Insert|       |   A   |   O   |   E   |   U   |   i   |                                  |   H   |   J   |   K   |   L   |   ;   |   :   | Enter |
   * |------+-------+-------+-------+-------+-------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Eisu |       |   Z   |   X   |   C   |   V   |   B   |       |       |  |       |       |   N   |   M   |   ,   |   .   |   /   |   \   | Kana  |
   * `------------------------------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------------------------------'
   *                                |  Home | Ctrl  | Space | Shift |   L   |  |   R   | Bkspc | Enter |Delete |  End  |
   *                                `---------------------------------------'  `---------------------------------------'
   */
  [_YSTRP] = LAYOUT( \
      JP_ESC,  JP_TAB,  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                   /**/                   JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_AT,   JP_BSPC, \
      JP_INS,  _______, JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                   /**/                   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN, JP_ENT,  \
      KC_MHEN, _______, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,     NUM,    MIDI, /**/ _______, _______, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, JP_BKSL, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Y_S,   JP_SPC,  LEFT,          /**/          RIGHT,   JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),
  /* SHIFTを押してるとき レイヤーを切り替えちゃう */
  [_YSTRP_SHIFT] = LAYOUT( \
      S(JP_ESC),  S(JP_TAB),  S(JP_Q), S(JP_W), S(JP_E), S(JP_R), S(JP_T),                   /**/                   S(JP_Y), S(JP_U), S(JP_I),    S(JP_O),   S(JP_P),    S(JP_AT),   JP_BSPC, \
      S(JP_INS),  _______,    S(JP_A), S(JP_S), S(JP_D), S(JP_F), S(JP_G),                   /**/                   S(JP_H), S(JP_J), S(JP_K),    S(JP_L),   S(JP_SCLN), S(JP_COLN), JP_ENT,  \
      S(KC_MHEN), _______,    S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), _______, _______, /**/ _______, _______, S(JP_N), S(JP_M), S(JP_COMM), S(JP_DOT), S(JP_SLSH), S(JP_BKSL), KC_HENK, \
                                       S(JP_HOME), S(JP_LCTL),    _______, S(JP_SPC),  LEFT, /**/ RIGHT, S(JP_BSPC), S(JP_ENT), S(JP_DEL), S(JP_END) \
      ),

  /* symbol
   * 普通のレイヤーでshiftとかaltとかguiがマクロになっているので、何かしら問題があるかもしれない。
   * その時代替できるようにピュアなやつをここにおく。
   * ,------------------------------------------------------.                                  ,-------------------------------------------------------.
   * |escape|  tab  |   ~   |   _   |   "   |   '   |   `   |                                  |   &   |   (   |   <   |   {   |   [   |   @   | bkspc |
   * |------+-------+-------+-------+-------+-------+-------+                                  |-------+-------+-------+-------+-------+-------+-------|
   * |insert|       |   +   |   -   |   *   |   =   |   :   |                                  |   |   |   )   |   >   |   }   |   ]   |   :   | enter |
   * |------+-------+-------+-------+-------+-------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | eisu |       |   !   |   ?   |   #   |   $   |   %   |       |       |  |       |       |       |   @   |   ^   |   ,   |   \   |   /   | kana  |
   * `------+-------+-------+-----------------------------------------------|  |-----------------------------------------------------------------------'
   *                                |  home | ctrl  | space | shift | Alt   |  |  GUI  | bksp  | enter |delete |  end  |
   *                                `---------------------------------------'  `---------------------------------------'
   */

  [_SYMBOL] = LAYOUT( \
      JP_ESC,  JP_TAB,  JP_TILD, JP_UNDS, JP_DQT,  JP_QUOT, JP_GRV,                     /**/                    JP_AMPR, JP_LPRN, JP_LT,   JP_LCBR, JP_LBRC, JP_AT,   JP_BSPC, \
      JP_INS,  XXXXXXX, JP_PLUS, JP_MINS, JP_ASTR, JP_EQL,  JP_COLN,                    /**/                    JP_PIPE, JP_RPRN, JP_GT,   JP_RCBR, JP_RBRC, JP_COLN, JP_ENT,  \
      KC_MHEN, XXXXXXX, JP_EXLM, JP_QUES, JP_HASH, JP_DLR,  JP_PERC,     NUM, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, JP_AT,   JP_CIRC, JP_COMM, JP_BKSL, XXXXXXX, KC_HENK, \
                                 JP_HOME, JP_LCTL, JP_LSFT, JP_SPC,  JP_LALT,           /**/           JP_LGUI, JP_BSPC, JP_ENT,  JP_DEL,   JP_END \
      ),

  /* LEFT
   * ,------------------------------------------------.                                      ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                                      |  F7  |  F8  |  F9  | F10  |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------|                                      |------+------+------+------+------+------+------|
   * |      |      |      |      |      |Qwerty|EEPROM|                                      | Left | Down |  Up  |Right |      |      |      |
   * |------+------+------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |Ystrp |Reset |      |      |          |      |      |      |      |      |      |      |      |      |
   * `------+------+------+---------------------------------------------.  ,------------------------------------------------------------------'
   *                                 |      | Ctrl |Space |Shift |      |  |Adjust| BkSp |Enter |Delete|      |
   *                                 `----------------------------------'  `----------------------------------'
   */

  [_LEFT] = LAYOUT( \
      JP_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     /**/                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  JP_BSPC, \
      JP_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  EEP_RST,                   /**/                   JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX, XXXXXXX, JP_ENT,  \
      KC_MHEN, XXXXXXX, XXXXXXX, XXXXXXX, MIDI,    YSTRP,   RESET,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  XXXXXXX,          /**/          RIGHT,   JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),

  /* Right
   * ,------------------------------------------------.                                      ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                                      |  F7  |  F8  |  F9  | F10  |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------|                                      |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                                      |      |M.L.Cl|M.M.Cl|M.R.Cl| WH.Up|      |      |
   * |------+------+------+------+------+------+------+                                      |------+------+------+------+------+------+------|
   * |      |      |      |      |      |Qwerty|EEPROM|                                      |M.Left|M.Down| M.Up |M.Rght| WH.Dn|      |      |
   * |------+------+------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |Ystrp |Reset |      |      |          |      |      |      |      |      |      |      |      |      |
   * `------+------+------+---------------------------------------------.  ,------------------------------------------------------------------'
   *                                 |      | Ctrl |Space |Shift |Adjust|  |      | BkSp |Enter |Delete|      |
   *                                 `----------------------------------'  `----------------------------------'
   */

  [_RIGHT] = LAYOUT( \
      JP_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, JP_BTN1, JP_BTN3, JP_BTN2, JP_WH_U, XXXXXXX, JP_BSPC, \
      JP_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY, EEP_RST,                    /**/                   JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D, XXXXXXX, JP_ENT,  \
      KC_MHEN, XXXXXXX, XXXXXXX, XXXXXXX, MIDI,    YSTRP,   RESET,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  LEFT,             /**/          XXXXXXX, JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),


  [_NUM] = LAYOUT( \
      JP_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX, JP_BSPC, \
      JP_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX, JP_ENT,  \
      KC_MHEN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, KC_0,    KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  XXXXXXX,          /**/          XXXXXXX, JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),

  /* Adjust
   * LeftとRightを同時押しするとこのレイヤーになります。
   * ,-----------------------------------------.  ,------------------------------------------.
   * |      |      |      |      |      |      |  |      |      |      |      |      |       |
   * |------+------+------+------+------+------|  |------+------+------+------+------+-------|
   * |      |      |      |      |      |      |  |      |      |      |      |      |       |
   * |------+------+------+------+------+------|  |------+------+------+------+------+-------|
   * |      |      |      |      |      |      |  |      |      |      |      |      |       |
   * |------+------+------+------+------+------|  |------+------+------+------+------+-------|
   * |      |      |      |      |      |      |  |      |      |      |      |      |       |
   * `------+------+------+------+------+------|  |------+------+------+------+------+-------'
   *        |      |      |      |      |      |  |      |      |      |      |      |
   *        `----------------------------------'  `----------------------------------'
   */

  [_ADJUST] = LAYOUT( \
      QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_BSPC, \
      YSTRP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   /**/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_ENT,  \
      MIDI,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HENK, \
                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  LEFT,             /**/          RIGHT,   JP_BSPC, JP_ENT,  SYMBOL,  JP_END \
      ),

  [_MIDI] = LAYOUT( \
      QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MI_UP,                     /**/                   XXXXXXX, MI_009,  MI_010,  MI_011,  MI_012, MI_H01,  MI_H02,  \
      YSTRP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MI_DOWN,                   /**/                   XXXXXXX, MI_005,  MI_006,  MI_007,  MI_008, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  /**/ XXXXXXX, XXXXXXX, MI_L12,  MI_001,  MI_002,  MI_003,  MI_004, XXXXXXX, XXXXXXX, \
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          /**/          XXXXXXX, MI_T_DN, XXXXXXX, MI_T_UP, XXXXXXX \
      ),
};




