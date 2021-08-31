/* Copyright 2020 umbyno
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

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// readability
#define XXX KC_NO

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
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array

#define LAYOUT_68_ansi( \
    k01, k51, k02, k52, k03, k53, k04, k54, k05, k15, k55, k06, k56,  k07,  k17, k57, \
    k11,  k61, k12, k62, k13, k63, k14, k24, k64, k25, k65, k16, k66, k77,  k27, k67, \
    k21,   k71, k22, k72, k23, k73, k34, k74, k84, k35, k75, k26,     k76,            \
    k31,    k81, k32, k82, k33, k83, k44, k94, k45, k85, k36,         k86,  k37,      \
    k41, k91, k42,               k93,               k95,  k96,  k46,   k87, k47, k97  \
) \
{ \
    { k01, k02, k03, k04, k05, k06, k07 }, \
    { k11, k12, k13, k14, k15, k16, k17 }, \
    { k21, k22, k23, k24, k25, k26, k27 }, \
    { k31, k32, k33, k34, k35, k36, k37 }, \
    { k41, k42, XXX, k44, k45, k46, k47 }, \
    { k51, k52, k53, k54, k55, k56, k57 }, \
    { k61, k62, k63, k64, k65, k66, k67 }, \
    { k71, k72, k73, k74, k75, k76, k77 }, \
    { k81, k82, k83, k84, k85, k86, k87 }, \
    { k91, XXX, k93, k94, k95, k96, k97 } \
}
