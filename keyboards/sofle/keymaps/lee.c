
 /* Copyright 2021 Dane Evans
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
// SOFLE RGB
#include <stdio.h>
#include "lee.h"
#include QMK_KEYBOARD_H
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST
};
#define CTLESC LCTL_T(KC_ESC)
#define CTLALTDEL LCA(KC_DEL)
#define SPACE_1 LT(1, KC_SPC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,    KC_0,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
                       KC_LGUI, KC_LALT, KC_LOWER, SPACE_1, KC_ENT,    KC_ENT, KC_SPC,  KC_LOWER,  KC_RAISE,   KC_RALT
  //                 \---------+--------+--------+--------+--------| |--------+--------+--------+--------+---------/
),
[_LOWER] = LAYOUT(
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_F11,  KC_F12,  KC_MS_U, KC_SLCK, KC_CAPS,                     KC_PGUP, KC_LPRN, KC_RPRN, KC_PMNS, _______, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_PSCR, KC_MS_L, KC_MS_D, KC_MS_R, KC_NLCK,                     KC_PGDN, KC_LBRC, KC_RBRC, KC_UNDS, KC_UP,   KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
     _______, KC_PAUS, KC_HOME, _______, KC_END, KC_SLCK,  KC_1 ,     KC_1,    KC_BTN1, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------|========| |========|--------+--------+--------+--------+--------+--------|
                      _______,  _______, _______, _______, _______,   _______, _______, _______, _______, _______
  //                 \---------+--------+--------+--------+--------| |--------+--------+--------+--------+---------/
),

[_RAISE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, _______ , _______ , _______ , _______ , _______,               _______,  _______  , _______,  _______ ,  _______ ,_______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_INS, KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                   KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_LALT, KC_LCTL, KC_LSFT,  XXXXXXX, KC_CAPS,                 KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_UP,   KC_GRV,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,XXXXXXX,KC_2,      KC_2,   KC_UNDS, KC_PLUS,KC_LBRC, KC_LEFT, KC_DOWN, KC_RGHT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RESET,   XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, XXXXXXX,XXXXXXX,                     XXXXXXX, KC_NO,  KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX,KC_QWERTY,KC_3,      KC_3,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
)

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}
