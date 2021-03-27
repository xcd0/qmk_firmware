/* Copyright 2021 xcd0
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWRETY] = LAYOUT(
			JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,       /**/    JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    \
			JP_A,    JP_S,    JP_D,    JP_F,    JP_G,       /**/    JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, \
			JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,       /**/    JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, \
															/**/                                                 \
					 NUMBER,  SYMBOL,                    			/**/          JP_LALT, JP_LGUI,              \
			JP_HOME, JP_LCTL, JP_SPC,  JP_4,    			/**/ JP_BSPC, JP_ENT,  JP_DEL,  JP_END,              \
			JP_1,    MOUSE,   ARROW,   JP_MHEN, 			/**/ JP_HENK,    JP_6,    JP_7,    JP_8              \
			),
	[_YSTRP] = LAYOUT(
			JP_Q,    JP_W,    JP_D,    JP_F,    JP_G,       /**/    JP_Y,    JP_S,    JP_T,    JP_R,    JP_P,    \
			JP_A,    JP_O,    JP_E,    JP_U,    JP_I,       /**/    JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, \
			JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,       /**/    JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, \
															/**/                                                 \
					 NUMBER,  SYMBOL,                    			/**/          JP_LALT, JP_LGUI,              \
			JP_HOME, JP_LCTL, JP_SPC,  JP_4,    			/**/ JP_BSPC, JP_ENT,  JP_DEL,  JP_END,              \
			JP_1,    MOUSE,   ARROW,   JP_MHEN, 			/**/ JP_HENK,    JP_6,    JP_7,    JP_8              \
			),
	[_NUMBER] = LAYOUT(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, JP_7, JP_8, JP_9, XXXXXXX,             \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, JP_4, JP_5, JP_6, XXXXXXX,             \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ JP_0,    JP_1, JP_2, JP_3, XXXXXXX,             \
															/**/                                                 \
					 _______, XXXXXXX, 						/**/ 		  XXXXXXX, XXXXXXX,                      \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX              \
			),
	[_ARROW] = LAYOUT(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ JP_LEFT, JP_DOWN, JP_UP,   JP_RGHT, XXXXXXX, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
															/**/                                              \
					 XXXXXXX, XXXXXXX, 						/**/ 		  XXXXXXX, XXXXXXX,                   \
			XXXXXXX, XXXXXXX, XXXXXXX, _______, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX           \
			),
	[_MOUSE] = LAYOUT(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ _______, JP_BTN1, JP_BTN2, JP_BTN3, JP_WH_U, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ JP_MS_L, JP_MS_D, JP_MS_U, JP_MS_R, JP_WH_D, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
															/**/                                              \
					 XXXXXXX, XXXXXXX, 						/**/ 		  XXXXXXX, XXXXXXX,                   \
			XXXXXXX, XXXXXXX, XXXXXXX, _______, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX           \
			),
	[_SYMBOL] = LAYOUT(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
															/**/                                              \
					 XXXXXXX, _______, 						/**/ 		  XXXXXXX, XXXXXXX,                   \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          \
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX           \
	),
};
//                    _______, _______, _______, _______,    _______, _______, _______, _______       \
//
//      JP_ESC,  JP_TAB,  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                   /**/                   JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_AT,   JP_BSPC, \
//      JP_INS,  _______, JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                   /**/                   JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN, JP_ENT,  \
//      KC_MHEN, _______, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,     NUM,    MIDI, /**/ _______, _______, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, JP_BKSL, KC_HENK, \
//                                 JP_HOME, JP_LCTL, L_Q_S,   JP_SPC,  LEFT,          /**/          RIGHT,   JP_BSPC, JP_ENT,  SYMBOL,  JP_END \

//	[_] = LAYOUT(
//			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 	/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//															/**/                                              \
					 XXXXXXX, XXXXXXX, 						/**/ 		  XXXXXXX, XXXXXXX,                      \
//			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          \
//			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 			/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX           \
