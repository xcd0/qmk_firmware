/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// place overrides here

// If you need more program area, try select and reduce rgblight modes to use.

// Selection of RGBLIGHT MODE to use.
#if defined(LED_ANIMATIONS)
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   #define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   //#define RGBLIGHT_EFFECT_RGB_TEST
   //#define RGBLIGHT_EFFECT_ALTERNATING
#endif

// midi
#define MIDI_ADVANCED

// タップホールド
#define TAPPING_TERM_PER_KEY // この関数を使えるようにする？→ uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
#define TAPPING_TERM 200     // tapとholdの境界秒数
#define RETRO_TAPPING        // 秒数過ぎてもほかのキーが押下されていない場合タップ扱いする
#define PERMISSIVE_HOLD      // 秒数過ぎる前にほかのキーを押下するとhold中に押した扱いされる
#define TAPPING_FORCE_HOLD   // こう書いてあるが意味がわからない  →　Mod Tap keyをTap後にすぐにHoldしたときに、Holdとして扱われるようになる。


