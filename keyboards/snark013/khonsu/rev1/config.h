/* Copyright 2020 @ben_roe (keycapsss.com)
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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4150
#define PRODUCT_ID      0x3638
#define DEVICE_VER      0x0001
#define MANUFACTURER    AGP
#define PRODUCT         Khonsu

/* key matrix size */
// rows are doubled-up for split-keyboard
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { D4, C6, B3, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, D7, B1, F7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define SOFT_SERIAL_PIN D2

/* SK6812 RGB LED */
#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#   define RGBLED_NUM 14  // Total number of LEDs
#   define RGBLED_SPLIT { 7, 7 } // LEDs per side
#   define RGBLIGHT_SPLIT
#endif

// Limit the power draw
#ifdef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 40
#else
  #define RGBLIGHT_LIMIT_VAL 80
#endif

#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { B5 }
#   define ENCODERS_PAD_B { B6 }
#   define ENCODERS_PAD_A_RIGHT { B5 }
#   define ENCODERS_PAD_B_RIGHT { B6 }
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
