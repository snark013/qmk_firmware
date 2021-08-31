/* Copyright 2020 umbynos
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

#define ESC_FN LT(_FN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* OSIRIS68 ANSI layout
 * ,---------------------------------------------------------------------.
 * | 01| 51| 02| 52| 03| 53| 04| 54| 05| 15| 55| 06| 56|   07  | | 17| 57|
 * |-----------------------------------------------------------| |-------|
 * | 11  | 61| 12| 62| 13| 63| 14| 24| 64| 25| 65| 16| 66| 77  | | 27| 67|
 * |-----------------------------------------------------------| `-------|
 * | 21    | 71| 22| 72| 23| 73| 34| 74| 84| 35| 75| 26|   76  |         |
 * |-----------------------------------------------------------| ,---.   |
 * | 31     | 81| 32| 82| 33| 83| 44| 94| 45| 85| 36|      86  | | 37|   |
 * |---------------------------------------------------------------------|
 * | 41 | 91 | 42 |            93           | 95 | 96 | 46 | | 87| 47| 97|
 * `---------------------------------------------------------------------'
 */

    /* Keymap _BASE: (Base Layer) Default Layer
     * ,-----------------------------------------------------------. ,---------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |Home|PgUp|
     * |-----------------------------------------------------------| |---------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | | End|PdDn|
     * |-----------------------------------------------------------| `---------'
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     * |-----------------------------------------------------------| ,----.
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   | | Up |
     * |-----------------------------------------------------------------------.
     * |Ctrl|Win |Alt |          Space         |Alt | FN |Ctrl| |Left|Down|Rig |
     * `------------------------------------------------------' `--------------'
     */
    [_BASE] = LAYOUT_68_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,            KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                           KC_RALT, MO(_FN), KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL: Function Layer
     * ,-----------------------------------------------------------. ,---------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Del   | |    |    |
     * |-----------------------------------------------------------| |---------|
     * |     |   | Up|   |   |   |   |   |   |   |   |   |  ]|RESET| |    |    |
     * |-----------------------------------------------------------| `---------'
     * |       |Lft|Dwn|Rth|   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------| ,----.
     * |        |   |   |   |   |   |   | V-| V+|Mut|   |          | | MSU|
     * |-----------------------------------------------------------------------.
     * |    |    |    |                        |    |    |    | | MSL| MSD| MSR|
     * `------------------------------------------------------' `--------------'
     */
    [_FN] = LAYOUT_68_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME, _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_MS_U,
        _______, _______, _______,                            _______,                   _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),
};


