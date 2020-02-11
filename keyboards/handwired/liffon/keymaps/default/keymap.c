/* Copyright 2020 Liffon
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
#include QMK_KEYBOARD_H

#include "keymap_swedish.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,     KC_8,    KC_9,     KC_0,    SE_PLUS, SE_HALF,
            KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,     KC_P,    SE_AM,   KC_BSPACE,
   ALGR_T(KC_ESC),   MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,     KC_J,    KC_K,     KC_L,    SE_OSLH, SE_AE,       KC_ENTER,
            KC_LSHIFT, SE_LESS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,      KC_M,    KC_COMMA, KC_DOT,  SE_MINS, KC_RSHIFT,
               KC_LCTRL, KC_LGUI, KC_LALT, SE_APOS, MO(_FN), KC_ALGR, KC_SPC, MO(_FN),  SE_QUOT, KC_DEL,   KC_DOWN,  KC_UP
    ),
    [_FN] = LAYOUT(
           KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,     KC_F8,      KC_F9,     KC_F10,    KC_F11,    KC_F12,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  C(KC_LEFT),  KC_UP,  C(KC_RIGHT),  _______,  _______,  _______,
     SE_HALF,  _______,  TG(_FN),  _______,  _______,  KC_LSHIFT,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_END,  _______,  MU_TOG,
        _______,  _______,  _______,  _______,  _______,  C(KC_B),  _______,  _______,  _______,  _______,  _______,  _______,  MU_MOD,
           _______,  RESET,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_PGUP
    )
};

const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
        2,  5,  8, 11, 14, 17, 20, 23, 26, 29, 32, 35,
      1,  4,  7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 
    0,  3,  6,  9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39,
      2,  5,  8, 11, 14, 17, 20, 23, 26, 29, 32, 35, 38,
        4,  7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
