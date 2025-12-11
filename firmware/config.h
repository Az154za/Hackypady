/*
 * Hackypady - Mini Keyboard Configuration
 * 
 * This file contains the hardware configuration and feature flags
 * for the Hackypady mini keyboard.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Hackypady
#define PRODUCT         Hackypady Mini Keyboard
#define DESCRIPTION     A customizable mini keyboard for productivity

/* Key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

/* Key matrix pins */
#define MATRIX_ROW_PINS { D1, D0, D4 }
#define MATRIX_COL_PINS { C6, D7, E6, B4 }
#define UNUSED_PINS

/* Diode direction */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) */
#define DEBOUNCE 5

/* Mechanical locking support */
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

/* RGB Underglow */
#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN F4
    #define RGBLED_NUM 12
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 255
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_ANIMATIONS
#endif

/* Rotary Encoder */
#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { F5 }
    #define ENCODERS_PAD_B { F6 }
    #define ENCODER_RESOLUTION 4
#endif

/* OLED Display */
#ifdef OLED_DRIVER_ENABLE
    #define OLED_DISPLAY_128X64
    #define OLED_TIMEOUT 30000
#endif

/* Features */
#define TAP_CODE_DELAY 10
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* Layer settings */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* VIA Support */
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
