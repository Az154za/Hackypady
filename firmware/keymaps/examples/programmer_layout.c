/*
 * Hackypady - Programmer Layout
 * 
 * Optimized for software developers and programmers.
 * Features quick access to debug keys, copy/paste, and navigation.
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _DEBUG,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer - Code Editing
     * ┌──────┬──────┬──────┬──────┐
     * │ F5   │ F9   │ F10  │ F11  │  Debug: Run, Breakpoint, Step Over, Step Into
     * ├──────┼──────┼──────┼──────┤
     * │ Ctrl │ C    │ V    │ Z    │  Copy, Paste, Undo
     * ├──────┼──────┼──────┼──────┤
     * │ Home │ End  │ PgUp │ NAV  │  Quick navigation + layer toggle
     * └──────┴──────┴──────┴──────┘
     */
    [_BASE] = LAYOUT(
        KC_F5,      KC_F9,      KC_F10,     KC_F11,
        KC_LCTL,    KC_C,       KC_V,       KC_Z,
        KC_HOME,    KC_END,     KC_PGUP,    MO(_NAV)
    ),

    /*
     * Debug Layer - Advanced debugging
     * ┌──────┬──────┬──────┬──────┐
     * │ F5   │ F9   │Shft10│Shft11│  Run, Toggle Breakpoint, Step Out, Continue
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-K│Ctrl-/│Ctrl-D│Ctrl-Y│  Format, Comment, Duplicate Line, Redo
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-B│Ctrl-J│Ctrl-P│      │  Build, Terminal, Quick Open
     * └──────┴──────┴──────┴──────┘
     */
    [_DEBUG] = LAYOUT(
        KC_F5,         KC_F9,         LSFT(KC_F10),  LSFT(KC_F11),
        LCTL(KC_K),    LCTL(KC_SLSH), LCTL(KC_D),    LCTL(KC_Y),
        LCTL(KC_B),    LCTL(KC_J),    LCTL(KC_P),    KC_TRNS
    ),

    /*
     * Navigation Layer - File and code navigation
     * ┌──────┬──────┬──────┬──────┐
     * │Ctrl-F│Ctrl-H│Ctrl-G│Ctrl-T│  Find, Replace, Go to Line, New File
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-W│Ctrl-S│ Tab  │Alt-←│  Close, Save, Next Tab, Navigate Back
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-Z│Ctrl-F│Ctrl-R│      │  Undo, Find, Run
     * └──────┴──────┴──────┴──────┘
     */
    [_NAV] = LAYOUT(
        LCTL(KC_F),    LCTL(KC_H),    LCTL(KC_G),     LCTL(KC_T),
        LCTL(KC_W),    LCTL(KC_S),    KC_TAB,         LALT(KC_LEFT),
        LCTL(KC_Z),    LCTL(KC_F),    LCTL(KC_R),     KC_TRNS
    )
};

// Custom encoder for programmers
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                // Scroll through code
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _DEBUG:
                // Step through code
                if (clockwise) {
                    tap_code(KC_F10);  // Step over
                } else {
                    tap_code(KC_F11);  // Step into
                }
                break;
            case _NAV:
                // Navigate tabs
                if (clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(LCTL(LSFT(KC_TAB)));
                }
                break;
        }
    }
    return true;
}
#endif
