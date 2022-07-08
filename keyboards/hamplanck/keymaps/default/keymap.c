/* Copyright 2021 liffon
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
    _FN,
    _NF,
    _FNNF,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,     SE_ARNG,
        MT(MOD_RALT, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,     KC_L,    SE_ODIA,  SE_ADIA,
        KC_LSHIFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_SFTENT,
        KC_LCTRL,             KC_LGUI, KC_LALT, SE_QUOT, MO(_NF), KC_BSPC, KC_SPC, MO(_FN), KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT
    ),
    
    [_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_7,   KC_8,         KC_9,              XXXXXXX,         XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_4,   KC_5,         KC_6,              XXXXXXX,         XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    KC_0,   KC_1,   KC_2,         KC_3,              XXXXXXX,         XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_FNNF), XXXXXXX, XXXXXXX, XXXXXXX, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE
    ),

    [_NF] = LAYOUT(
        SE_EXLM, SE_DQUO, SE_HASH, SE_DLR,  SE_PERC, SE_AMPR, SE_SLSH, SE_LPRN,   SE_RPRN,  SE_EQL, SE_QUES, SE_PLUS,
        XXXXXXX, XXXXXXX, XXXXXXX, SE_ACUT, C(KC_B), XXXXXXX, XXXXXXX, SE_LABK,   SE_RABK, XXXXXXX,  SE_GRV, SE_TILD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_SECT, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, SE_CIRC, SE_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL , XXXXXXX, MO(_FNNF), KC_HOME, KC_PGDN, KC_PGUP,  KC_END
    ),

    [_FNNF] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,     KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,     KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F10,     KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
