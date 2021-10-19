
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

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

#define MAXMODS 4
static const struct modstr {
    uint16_t mask;
    char str[6];
} modstr[MAXMODS] = {
    {MOD_MASK_CTRL, "CTRL"},
    {MOD_MASK_ALT, "Alt"},
    {MOD_MASK_SHIFT, "Shft"},
    {MOD_MASK_GUI, "Win"},
};

#define LOCKCOUNT 3
static const struct lockstr {
    uint8_t shift_dist;
    char str[6];
} locks[LOCKCOUNT] = {
    {0, "CapL"},
    {1, "NumL"},
    {2, "SclL"}
};

static void print_status_narrow(void) {
    // Print current mode
    //oled_write_P(PSTR("\n\n"), false);
    // oled_write_ln_P(PSTR("Dane\nEvans"), false);

    //oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }

    uint16_t mods = get_mods();
    for (int i=0;i<MAXMODS;i++) {
        if (mods & modstr[i].mask) oled_write_ln(modstr[i].str, false);
        else oled_write_ln("", false);
    }

    uint8_t leds = host_keyboard_leds();
    if (leds & (1<<USB_LED_CAPS_LOCK) ) {
        oled_write_ln(locks[0].str, false);
    } else {
        oled_write_ln_P(PSTR(""), false);
    }
    if (leds & (1<<USB_LED_NUM_LOCK)) {
        oled_write_ln(locks[1].str, false);
    } else {
        oled_write_ln_P(PSTR(""), false);
    }
    if (leds & (1<<USB_LED_SCROLL_LOCK)) {
        oled_write_ln(locks[2].str, false);
    } else {
        oled_write_ln_P(PSTR(""), false);
    }

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif
