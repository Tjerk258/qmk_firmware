// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/* Copyright 2021 QMK
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

enum planck_layers { _QWERTY};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│Scr│Pse│Vo-│Vo+│Mut│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┤
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Num│ / │ * │ - │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ 7 │ 8 │ 9 │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┼───┼───┤ + │
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │ 4 │ 5 │ 6 │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┼───┼───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift │ ↑ │ 1 │ 2 │ 3 │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┼───┼───┤Ent│
     * │Ctrl│GUI │Alt │         Space          │Alt│GUI│Ctl│ ← │ ↓ │ → │ 0 │ . │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_QWERTY] = LAYOUT_48_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, RGB_MODE_FORWARD , KC_SPC,  RGB_VAI,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
)
    // [1] = LAYOUT_96_ansi(
    //     _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,        _______,      _______,  _______,  _______,  _______,
    //     _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,        _______,    RGB_MOD,  RGB_RMOD, RGB_TOG,   
    //     _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                   _______,         _______,   _______,  RGB_HUI,    RGB_SAI,    RGB_VAI, _______,
    //     _______,          _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,         _______, _______,            RGB_SPI,      _______,      _______, 
    //     _______, _______, _______,                            _______,                             _______, _______, _______, _______, _______, _______, _______,                           _______,  _______
    // )
};

// #endif

//capslock and numlock leds
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (host_keyboard_led_state().caps_lock) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(79, 255, 255, 255); // assuming caps lock is at led #5
//     } else {
//         RGB_MATRIX_INDICATOR_SET_COLOR(79, 0, 0, 0);
//     }
//     if (host_keyboard_led_state().num_lock) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(53, 255, 255, 255); // assuming caps lock is at led #5
//     } else {
//         RGB_MATRIX_INDICATOR_SET_COLOR(53, 0, 0, 0);
//     }
//     return false;
// }


//numlock always active
// void led_set_keymap(uint8_t usb_led) {
//   if (!host_keyboard_led_state().num_lock) {
//     register_code(KC_NUM);
//     unregister_code(KC_NUM);
//   }
// }

// int default_layer_state_set_kb(layer_state_t state){
//     if(state = 0) {

//     }
// }