 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.
#define CTLESC LCTL_T(KC_ESC)
#define CTLALTDEL LCA(KC_DEL)
#define RAISE MO(1)
#define SPACE_2 LT(1, KC_SPC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  CTLALTDEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
                       KC_LGUI, KC_LALT, RAISE,   SPACE_2, KC_ENT,    KC_ENT, KC_SPC,  KC_ESC,   RAISE,   KC_RALT
  //                 \---------+--------+--------+--------+--------| |--------+--------+--------+--------+---------/
),
[1] = LAYOUT(
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_F11,  KC_F12,  KC_MS_U, KC_SLCK, KC_NLCK,                     KC_PGUP, KC_LPRN, KC_RPRN, KC_PMNS, _______, KC_PPLS, 
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_NLCK,                     KC_PGDN, KC_LBRC, KC_RBRC, KC_UNDS, KC_UP,   KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_PAUS, KC_HOME, _______, KC_END, KC_SLCK,  _______ ,  _______, KC_BTN1, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
                      _______,  _______, _______, _______, _______,   KC_BTN2, _______, _______, _______, _______
  //                 \---------+--------+--------+--------+--------| |--------+--------+--------+--------+---------/
)
};
