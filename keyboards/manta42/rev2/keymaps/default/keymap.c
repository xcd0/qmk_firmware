#include QMK_KEYBOARD_H
// {{{
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
extern MidiDevice midi_device;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers. }}}
enum layer_number {
    _QWERTY = 0,
//    _COLEMAK,
//    _DVORAK,
//    _LOWER,
//    _RAISE,
    _ADJUST,
	_QWERTY_SHIFT,
	_YSTRP,
	_YSTRP_SHIFT,
	_LAYER_1,
	_LAYER_2,
	_LAYER_3,
	_LAYER_4,
//	_LEFT,
//	_RIGHT,
//	_NUM,
//	_SYMBOL,
//	_MIDI,
};

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	YSTRP,
	LEFT, RIGHT, SYMBOL, NUM, ADJUST,
	EISU, KANA,
	L1,L2,L3,L4,

	MIDI, MI_UP, MI_DOWN, MI_T_UP, MI_T_DN, MI_NOTEMIN,
	MI_L01 = MI_NOTEMIN, MI_L02, MI_L03, MI_L04, MI_L05, MI_L06, MI_L07, MI_L08, MI_L09, MI_L10, MI_L11, MI_L12,
	MI_001, MI_002, MI_003, MI_004, MI_005, MI_006, MI_007, MI_008, MI_009, MI_010, MI_011, MI_012,
	MI_H01, MI_H02, MI_H03, MI_H04, MI_H05, MI_H06, MI_H07, MI_H08, MI_H09, MI_H10, MI_H11, MI_H12,
};

// {{{
enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

#include "keymap_jp.h"


#include "tap_dance.h"

#include "5.h"

#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
//}}}

// tapとholdで挙動を変えるキーについて 判定の境界時間を初期値TAPPING_TERMから変更する場合ここに記述する
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		//case SFT_T(KC_SPC):
		//	return TAPPING_TERM + 1250;
		//case LT(1, KC_GRV):
		//	return 130;
		default:
			return TAPPING_TERM;
	}
}

// midi のノート番号をいい感じに設定する
// 81鍵のピアノで一番低い音C1は24 高い音C8は108 真ん中のドC4は60 ラA4は69
// 初期状態でMI_001を押されたとき C4の60を出力したい ( MI_001 - MI_NOTEMIN = 12 )
// note = keycode - MI_NOTEMIN + midi_base_offset が 60になるようにmidi_base_offsetを48にする
#define MIDI_INIT_OFFSET 48
uint8_t midi_base_offset = MIDI_INIT_OFFSET; // C4のあるオクターブを初期値にする
bool midi_tmp_offset_u = 0; // 押している間だけオフセット
bool midi_tmp_offset_d = 0; // 押している間だけオフセット

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// 追加したコード {{{
		case QWERTY:
			if (record->event.pressed) {
				persistent_default_layer_set(1UL<<_QWERTY);
			}
			return false;
			break;
		case YSTRP:
			if (record->event.pressed) {
				persistent_default_layer_set(1UL<<_YSTRP);
			}
			return false;
			break;
		case L1:
			if (record->event.pressed) {
				if (TOG_STATUS) {
				} else {
					TOG_STATUS = !TOG_STATUS;
				}
				layer_on(_LAYER_1);
				update_tri_layer_RGB(_LAYER_1, _LAYER_2, _ADJUST);
			} else {
				TOG_STATUS = false;
				layer_off(_LAYER_1);
				update_tri_layer_RGB(_LAYER_1, _LAYER_2, _ADJUST);
			}
			return false;
		case L2:
			if (record->event.pressed) {
				if (TOG_STATUS) {
				} else {
					TOG_STATUS = !TOG_STATUS;
				}
				layer_on(_LAYER_2);
				update_tri_layer_RGB(_LAYER_1, _LAYER_2, _ADJUST);
			} else {
				layer_off(_LAYER_2);
				TOG_STATUS = false;
				update_tri_layer_RGB(_LAYER_1, _LAYER_2, _ADJUST);
			}
			return false;
		case L3: if (record->event.pressed) { layer_on(_LAYER_3); } else { layer_off(_LAYER_3); } return false;
		case L4:
					 if (record->event.pressed) { layer_on(_LAYER_4); } else { layer_off(_LAYER_4); } return false;
		case ADJUST: if (record->event.pressed) { layer_on(_ADJUST); } else { layer_off(_ADJUST); } return false;
//    case SYMBOL:
//      if (record->event.pressed) {
//        layer_on(_SYMBOL);
//      } else {
//        layer_off(_SYMBOL);
//      }
//      return false;
//      break;
//    case LEFT:
//      if (record->event.pressed) {
//          //not sure how to have keyboard check mode and set it to a variable, so my work around
//          //uses another variable that would be set to true after the first time a reactive key is pressed.
//        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
//        } else {
//          TOG_STATUS = !TOG_STATUS;
//        }
//        layer_on(_LEFT);
//        update_tri_layer_RGB(_LEFT, _RIGHT, _ADJUST);
//      } else {
//        TOG_STATUS = false;
//        layer_off(_LEFT);
//        update_tri_layer_RGB(_LEFT, _RIGHT, _ADJUST);
//      }
//      return false;
//      break;
//    case RIGHT:
//      if (record->event.pressed) {
//        //not sure how to have keyboard check mode and set it to a variable, so my work around
//        //uses another variable that would be set to true after the first time a reactive key is pressed.
//        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
//        } else {
//          TOG_STATUS = !TOG_STATUS;
//        }
//        layer_on(_RIGHT);
//        update_tri_layer_RGB(_LEFT, _RIGHT, _ADJUST);
//      } else {
//        layer_off(_RIGHT);
//        TOG_STATUS = false;
//        update_tri_layer_RGB(_LEFT, _RIGHT, _ADJUST);
//      }
//      return false;
//      break;
//    case NUM:
//      if (record->event.pressed) {
//        layer_on(_NUM);
//      } else {
//        layer_off(_NUM);
//      }
//      return false;
//      break;
//    case ADJUST:
//        if (record->event.pressed) {
//          layer_on(_ADJUST);
//        } else {
//          layer_off(_ADJUST);
//        }
//        return false;
//        break;
//// 追加したコードここまで }}}
//	case MIDI:
//		if( record->event.pressed ) {
//			persistent_default_layer_set(1UL<<_MIDI);
//			midi_base_offset =  MIDI_INIT_OFFSET; // オクターブをリセット
//		} return false; break;
//		case MI_UP:   if( midi_base_offset < 120 ){ midi_base_offset+=12; } return false; break;
//		case MI_DOWN: if( midi_base_offset > 12  ){ midi_base_offset-=12; } return false; break;
//		case MI_T_UP: midi_tmp_offset_u = record->event.pressed;  return false; break;
//		case MI_T_DN: midi_tmp_offset_d = record->event.pressed;  return false; break;
//	/*
//		MIDI, MI_UP, MI_DOWN, MI_T_UP, MI_T_DN, MI_NOTEMIN,
//		MI_L01 = MI_NOTEMIN, MI_L02, MI_L03, MI_L04, MI_L05, MI_L06, MI_L07, MI_L08, MI_L09, MI_L10, MI_L11, MI_L12,
//		MI_001, MI_002, MI_003, MI_004, MI_005, MI_006, MI_007, MI_008, MI_009, MI_010, MI_011, MI_012,
//		MI_H01, MI_H02, MI_H03, MI_H04, MI_H05, MI_H06, MI_H07, MI_H08, MI_H09, MI_H10, MI_H11, MI_H12,
//	*/
//		// Lxxは１つ下のオクターブ
//		// 0xxは基本のオクターブ   基準
//		// Hxxは１つ上のオクターブ
//		case MI_L01 ... MI_L12:   // 0 ~ 11
//		case MI_001 ... MI_012:   // 11 ~ 23
//		case MI_H01 ... MI_H12: { // 24 ~ 35
//				int16_t note = keycode - MI_NOTEMIN + midi_base_offset;
//				if( midi_tmp_offset_u ) note += 12; if( midi_tmp_offset_d ) note -= 12; if( note < 0 || note > 127 ){ return false; }
//				if( record->event.pressed ) { midi_send_noteon( &midi_device, 0, (uint8_t)note, 127 ); }else{ midi_send_noteoff( &midi_device, 0, (uint8_t)note, 0 ); }
//				return false; break;
//		}

// 元のコード {{{
/*
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
*/
// 元のコードここまで }}}
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(struct CharacterMatrix *matrix) {

  static const char helix_logo[] PROGMEM ={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write_P(matrix, helix_logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}

static void render_rgbled_status(bool full, struct CharacterMatrix *matrix) {
#ifdef RGBLIGHT_ENABLE
  char buf[30];
  if (RGBLIGHT_MODES > 1 && rgblight_config.enable) {
      if (full) {
          snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ",
                   rgblight_config.mode,
                   rgblight_config.hue/RGBLIGHT_HUE_STEP,
                   rgblight_config.sat/RGBLIGHT_SAT_STEP,
                   rgblight_config.val/RGBLIGHT_VAL_STEP);
      } else {
          snprintf(buf, sizeof(buf), "[%2d] ",rgblight_config.mode);
      }
      matrix_write(matrix, buf);
  }
#endif
}

static void render_layer_status(struct CharacterMatrix *matrix) {
  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[10];
  matrix_write_P(matrix, PSTR("Layer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_RAISE:
           matrix_write_P(matrix, PSTR("Raise"));
           break;
        case L_LOWER:
           matrix_write_P(matrix, PSTR("Lower"));
           break;
        case L_ADJUST:
        case L_ADJUST_TRI:
           matrix_write_P(matrix, PSTR("Adjust"));
           break;
        default:
           matrix_write_P(matrix, PSTR("Undef-"));
           snprintf(buf,sizeof(buf), "%ld", layer_state);
           matrix_write(matrix, buf);
    }
}

void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static const char os_logo[][2][3] PROGMEM  ={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write_P(matrix, os_logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[0][1]);
  }else{
    matrix_write_P(matrix, os_logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[1][1]);
  }

  matrix_write_P(matrix, PSTR(" "));
  render_layer_status(matrix);
  matrix_write_P(matrix, PSTR("\n"));

  // Host Keyboard LED Status
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ?
                 PSTR("NUMLOCK") : PSTR("       "));
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ?
                 PSTR("CAPS") : PSTR("    "));
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ?
                 PSTR("SCLK") : PSTR("    "));
  matrix_write_P(matrix, PSTR("\n"));
  render_rgbled_status(true, matrix);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
    render_rgbled_status(false, &matrix);
    render_layer_status(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
