/*
 * Hackypady - Video Editor Layout
 * 
 * Optimized for video editing in Adobe Premiere, DaVinci Resolve, Final Cut Pro.
 * Features playback controls, timeline editing, and tool shortcuts.
 */

#include QMK_KEYBOARD_H

enum layers {
    _PLAYBACK,
    _EDIT,
    _TOOLS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Playback Layer
     * ┌──────┬──────┬──────┬──────┐
     * │ J    │ K    │ L    │ Spc  │  Rev, Stop/Play, Fwd, Play/Pause
     * ├──────┼──────┼──────┼──────┤
     * │ I    │ O    │ M    │ /    │  In Point, Out Point, Marker, Clear Marker
     * ├──────┼──────┼──────┼──────┤
     * │ ←    │ →    │ ↑    │ EDIT │  Prev Frame, Next Frame, Clip, Edit Layer
     * └──────┴──────┴──────┴──────┘
     */
    [_PLAYBACK] = LAYOUT(
        KC_J,       KC_K,       KC_L,       KC_SPC,
        KC_I,       KC_O,       KC_M,       KC_SLSH,
        KC_LEFT,    KC_RIGHT,   KC_UP,      MO(_EDIT)
    ),

    /*
     * Edit Layer
     * ┌──────┬──────┬──────┬──────┐
     * │Ctrl-Z│Ctrl-C│Ctrl-V│Ctrl-X│  Undo, Copy, Paste, Cut
     * ├──────┼──────┼──────┼──────┤
     * │ C    │ V    │ B    │ N    │  Razor, Selection, Blade, Track Select
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-S│ Del  │ Q    │      │  Save, Delete, Ripple Delete
     * └──────┴──────┴──────┴──────┘
     */
    [_EDIT] = LAYOUT(
        LCTL(KC_Z), LCTL(KC_C), LCTL(KC_V), LCTL(KC_X),
        KC_C,       KC_V,       KC_B,       KC_N,
        LCTL(KC_S), KC_DEL,     KC_Q,       KC_TRNS
    ),

    /*
     * Tools Layer
     * ┌──────┬──────┬──────┬──────┐
     * │ R    │ T    │ Y    │ U    │  Rate Stretch, Type Tool, Slip Tool
     * ├──────┼──────┼──────┼──────┤
     * │Ctrl-+│Ctrl--│ =    │ -    │  Zoom In, Zoom Out, Timeline Scale
     * ├──────┼──────┼──────┼──────┤
     * │ F1   │ F2   │ F3   │      │  Import, Export, Render
     * └──────┴──────┴──────┴──────┘
     */
    [_TOOLS] = LAYOUT(
        KC_R,       KC_T,       KC_Y,       KC_U,
        LCTL(KC_PLUS), LCTL(KC_MINS), KC_EQL, KC_MINS,
        KC_F1,      KC_F2,      KC_F3,      KC_TRNS
    )
};

// Encoder for scrubbing timeline
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _PLAYBACK:
                // Frame-by-frame scrubbing
                if (clockwise) {
                    tap_code(KC_RIGHT);  // Next frame
                } else {
                    tap_code(KC_LEFT);   // Previous frame
                }
                break;
            case _EDIT:
                // Zoom timeline
                if (clockwise) {
                    tap_code16(LCTL(KC_PLUS));
                } else {
                    tap_code16(LCTL(KC_MINS));
                }
                break;
            case _TOOLS:
                // Audio level adjustment
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;
        }
    }
    return true;
}
#endif

// OLED display for video editors
#ifdef OLED_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("Video Edit\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _PLAYBACK:
            oled_write_P(PSTR("PLAY\n"), false);
            break;
        case _EDIT:
            oled_write_P(PSTR("EDIT\n"), false);
            break;
        case _TOOLS:
            oled_write_P(PSTR("TOOL\n"), false);
            break;
    }
}
#endif
