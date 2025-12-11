/*
 * Hackypady Default Keymap
 * 
 * This is the default keymap for the Hackypady mini keyboard.
 * It includes 4 layers for different use cases.
 */

#include QMK_KEYBOARD_H

// Define layer names
enum layers {
    _BASE,      // Layer 0: Default
    _FUNCTION,  // Layer 1: Function keys
    _GAMING,    // Layer 2: Gaming macros
    _MEDIA      // Layer 3: Media controls
};

// Define custom keycodes
enum custom_keycodes {
    KC_LAYER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: Base Layer (Default)
     * ┌────┬────┬────┬────┐
     * │ 1  │ 2  │ 3  │ 4  │
     * ├────┼────┼────┼────┤
     * │ 5  │ 6  │ 7  │ 8  │
     * ├────┼────┼────┼────┤
     * │ 9  │ 0  │ -  │FN1 │
     * └────┴────┴────┴────┘
     */
    [_BASE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8,
        KC_9,    KC_0,    KC_MINS, MO(_FUNCTION)
    ),

    /*
     * Layer 1: Function Layer
     * ┌────┬────┬────┬────┐
     * │ F1 │ F2 │ F3 │ F4 │
     * ├────┼────┼────┼────┤
     * │ F5 │ F6 │ F7 │ F8 │
     * ├────┼────┼────┼────┤
     * │ F9 │F10 │F11 │    │
     * └────┴────┴────┴────┘
     */
    [_FUNCTION] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,
        KC_F9,   KC_F10,  KC_F11,  KC_TRNS
    ),

    /*
     * Layer 2: Gaming Layer
     * ┌────┬────┬────┬────┐
     * │ Q  │ W  │ E  │ R  │
     * ├────┼────┼────┼────┤
     * │ A  │ S  │ D  │ F  │
     * ├────┼────┼────┼────┤
     * │CTRL│SHFT│SPC │TAB │
     * └────┴────┴────┴────┘
     */
    [_GAMING] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,
        KC_A,    KC_S,    KC_D,    KC_F,
        KC_LCTL, KC_LSFT, KC_SPC,  KC_TAB
    ),

    /*
     * Layer 3: Media Layer
     * ┌────┬────┬────┬────┐
     * │MUTE│VOL-│VOL+│PLAY│
     * ├────┼────┼────┼────┤
     * │PREV│NEXT│STOP│EJCT│
     * ├────┼────┼────┼────┤
     * │BRI-│BRI+│    │    │
     * └────┴────┴────┴────┘
     */
    [_MEDIA] = LAYOUT(
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
        KC_MPRV, KC_MNXT, KC_MSTP, KC_EJCT,
        KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS
    )
};

// Rotary encoder rotation
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Get current layer
        switch (get_highest_layer(layer_state)) {
            case _BASE:
            case _FUNCTION:
                // Volume control on base layer
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _GAMING:
                // Weapon switch in gaming layer
                if (clockwise) {
                    tap_code(KC_MWHL_UP);
                } else {
                    tap_code(KC_MWHL_DOWN);
                }
                break;
            case _MEDIA:
                // Brightness control in media layer
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
        }
    }
    return true;
}
#endif

// OLED Display
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        default:
            oled_write_P(PSTR("Unknown\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

// RGB Layer indication
#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv(HSV_WHITE);
            break;
        case _FUNCTION:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _GAMING:
            rgblight_sethsv(HSV_RED);
            break;
        case _MEDIA:
            rgblight_sethsv(HSV_GREEN);
            break;
    }
    return state;
}
#endif
