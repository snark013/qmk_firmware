/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *          ,------------------------------------------.                   ,----------------------------------------------.
 *          |  ESC  |   Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |  -        |
 * ,--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------.
 * | LShift |   ~   |   A  |   S  |   D  |   F  |   G  |                   |   H  |   J  |   K  |   L  |   ;  |  '        |      |
 * |--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------|
 * | LCTRL  |  LALT |   Z  |   X  |   C  |   V  |   B  |                   |   N  |   M  |   ,  |   .  |   /  |RShft/Enter|      |
 * `-----------------------------------------------------------.   .-------------------------------------------------------------'
 *                                | LGUI | LALT | Lower| Space |   | Enter | Raise|BackSP| RGUI |
 *                                `----------------------------'   '----------------------------'
 */

 [_QWERTY] = LAYOUT(
              KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT,  KC_TILD,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        XXXXXXX,
    KC_LCTRL, KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), XXXXXXX,
                                      KC_LGUI,   LOWER,   LOWER,  KC_SPC,      KC_ENT,  RAISE,   KC_BSPC, KC_RGUI
),
/* LOWER

 *          ,------------------------------------------.                   ,----------------------------------------------.
 *          |       |  F1  |  F2  |  F3  |  F4  |  F5  |                   |  F6  |  F7  |  F8  |  F9  | F10  |  F11      |
 * ,--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------.
 * |        |       |   1  |   2  |   3  |   4  |   5  |                   |   6  |   7  |   8  |   9  |   0  |  F12      |      |
 * |--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------|
 * |        |   `   |   !  |   @  |   #  |   $  |   %  |                   |   ^  |   &  |   *  |   (  |   )  |    ~      |  _   |
 * `-----------------------------------------------------------.   .-------------------------------------------------------------'
 *                                |      |      |      |       |   |       |      |      |      |
 *                                `----------------------------'   '----------------------------'
 */

[_LOWER] = LAYOUT(
             _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,  _______,
    _______, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, KC_UNDS,
//    _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
                                        _______, _______, _______, _______,    _______, _______, _______, _______
),
/* RAISE
 *          ,------------------------------------------.                   ,----------------------------------------------.
 *          |   `   |   1  |   2  |   3  |   4  |   5  |                   |   6  |   7  |   8  |   9  |   0  |           |
 * ,--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------.
 * |        |   F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                   |      | Left | Down |  Up  | Right|           |      |
 * |--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------|
 * |        |   F7  |  F8  |  F9  | F10  | F11  | F12  |                   |   +  |   -  |   =  |   [  |   ]  |    \      |      |
 * `-----------------------------------------------------------.   .-------------------------------------------------------------'
 *                                |      |      |      |       |   |       |      |      |      |
 *                                `----------------------------'   '----------------------------'
 */

[_RAISE] = LAYOUT(
             KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
                                       _______, _______, _______, _______,    _______, _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 *          ,------------------------------------------.                   ,----------------------------------------------.
 *          | RESET |      |      |      |      |      |                   |      |      |      |      |      |           |
 * ,--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------.
 * |        | RGB On| Hue+ | Sat+ | Val+ |      |      |                   | Prev | Play | Next |      |      |           |      |
 * |--------+-------+------+------+------+------+------|                   |------+------+------+------+------+-----------+------|
 * |        | Mode  | Hue- | Sat- | Val- |      |      |                   | Vol+ | Mute | Vol- |      |      |           |      |
 * `-----------------------------------------------------------.   .-------------------------------------------------------------'
 *                                |      |      |      |       |   |       |      |      |      |
 *                                `----------------------------'   '----------------------------'
 */

[_ADJUST] = LAYOUT(
               RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______,   _______, _______, _______, _______
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("Kimiko"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_winmac_layout(uint8_t is_mac) {

    static const char PROGMEM win_layout[] = {
        0x20, 0x20, 0x5E, 0x5F, 0x20,
        0x20, 0x20, 0x7E, 0x7F, 0x20, 0 };
    static const char PROGMEM mac_layout[] = {
        0x20, 0x20, 0x5C, 0x5D, 0x20,
        0x20, 0x20, 0x7C, 0x7D, 0x20, 0 };

    if(is_mac) {
        oled_write_P(mac_layout, false);
    } else {
        oled_write_P(win_layout, false);
    }

}

void render_status_main(void) {
    render_space();
//    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_winmac_layout(keymap_config.swap_lalt_lgui);
}

void render_status_secondary(void) {
    render_space();
//    render_space();
    render_logo();
    render_space();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
//        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    // register_mods(mod_config(MOD_LALT));
                    // register_code(KC_LEFT);
                    register_code(KC_HOME);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    // unregister_mods(mod_config(MOD_LALT));
                    // unregister_code(KC_LEFT);
                    unregister_code(KC_HOME);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    // register_mods(mod_config(MOD_LALT));
                    // register_code(KC_RIGHT);
                    register_code(KC_END);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    // unregister_mods(mod_config(MOD_LALT));
                    // unregister_code(KC_RIGHT);
                    unregister_code(KC_END);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_BSPC);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_BSPC);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_BSPC);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_BSPC);
                }
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_C);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_C);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_C);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_C);
                }
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_V);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_V);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_V);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_V);
                }
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_X);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_X);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_X);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_X);
                }
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_Z);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_Z);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_Z);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_Z);
                }
            }
            return false;
    }
    return true;
}


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder on master side
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Arrow Up/Down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;

            // If the RAISE layer is active
            case _RAISE:
                // Switch browser tabs
                if (clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(RCS(KC_TAB));
                }
                break;
            // If the ADJUST layer is active
            case _ADJUST:
                // RGB brightness up/down
                if (clockwise) {
                    rgblight_decrease_val(); // tap_code(RGB_VAD);
                } else {
                    rgblight_increase_val(); // tap_code(RGB_VAI);
                }
                break;
        }
    }
    // Encoder on slave side
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Scroll by Word
                if (clockwise) {
                    tap_code16(LCTL(KC_RGHT));
                } else {
                    tap_code16(LCTL(KC_LEFT));
                }
                break;

            // If the LOWER layer is active
            case _LOWER:
                // Volume up/down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

            // If the ADJUST layer is active
            case _ADJUST:
                // RGB hue up/down
                if (clockwise) {
                    // tap_code(RGB_HUI);
                    rgblight_increase_hue();
                } else {
                    // tap_code(RGB_HUD);
                    rgblight_decrease_hue();
                }
                break;
        }
    }
}
#endif // ENCODER_ENABLE
