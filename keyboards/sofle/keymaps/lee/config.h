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
  #pragma once


//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
#define ENCODER_DIRECTION_FLIP


#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 35    // Number of LEDs
#define RGBLED_NUM 35    // Number of LEDs
#define DRIVER_LED_TOTAL RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

    //#define RGBLIGHT_ANIMATIONS
	#define RGBLIGHT_EFFECT_BREATHING
	//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_SNAKE
	//#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 58
	//#define RGBLED_SPLIT
	#define RGBLED_SPLIT { 29, 29 } // haven't figured out how to use this yet

	//#define RGBLED_NUM 30
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
// #   define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #   define DISABLE_RGB_MATRIX_BREATHING
// #   define DISABLE_RGB_MATRIX_CYCLE_ALL
// #   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #   define DISABLE_RGB_MATRIX_DUAL_BEACON
// #   define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #   define DISABLE_RGB_MATRIX_RAINDROPS
// #   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #   define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #   define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #   define DISABLE_RGB_MATRIX_SPLASH
// #   define DISABLE_RGB_MATRIX_MULTISPLASH
// #   define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
