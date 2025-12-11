/*
 * Hackypady - Streamer Layout
 * 
 * Optimized for streamers using OBS Studio, Streamlabs, or similar.
 * Quick access to scene switching, audio control, and stream management.
 */

#include QMK_KEYBOARD_H

enum layers {
    _SCENES,
    _AUDIO,
    _STREAM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Scenes Layer - OBS Scene Switching
     * ┌──────┬──────┬──────┬──────┐
     * │ F13  │ F14  │ F15  │ F16  │  Scene 1, 2, 3, 4
     * ├──────┼──────┼──────┼──────┤
     * │ F17  │ F18  │ F19  │ F20  │  Scene 5, 6, 7, 8
     * ├──────┼──────┼──────┼──────┤
     * │ F21  │ F22  │ Mute │AUDIO │  Scene 9, 10, Mute Mic, Audio Layer
     * └──────┴──────┴──────┴──────┘
     */
    [_SCENES] = LAYOUT(
        KC_F13,     KC_F14,     KC_F15,     KC_F16,
        KC_F17,     KC_F18,     KC_F19,     KC_F20,
        KC_F21,     KC_F22,     KC_MUTE,    MO(_AUDIO)
    ),

    /*
     * Audio Layer - Audio and Source Control
     * ┌──────┬──────┬──────┬──────┐
     * │Vol-  │Vol+  │Desk- │Desk+ │  Volume, Desktop Audio
     * ├──────┼──────┼──────┼──────┤
     * │Mic-  │Mic+  │ Mute │UnMut │  Microphone Control
     * ├──────┼──────┼──────┼──────┤
     * │Music │ SFX  │Alert │      │  Music, Sound FX, Alert
     * └──────┴──────┴──────┴──────┘
     */
    [_AUDIO] = LAYOUT(
        KC_VOLD,    KC_VOLU,    KC_F23,     KC_F24,
        LSFT(KC_F13), LSFT(KC_F14), KC_MUTE, LSFT(KC_F15),
        LSFT(KC_F16), LSFT(KC_F17), LSFT(KC_F18), KC_TRNS
    ),

    /*
     * Stream Layer - Stream Control
     * ┌──────┬──────┬──────┬──────┐
     * │Start │ Stop │ Rec  │StpRc │  Start/Stop Stream, Start/Stop Recording
     * ├──────┼──────┼──────┼──────┤
     * │ BRB  │ End  │ Chat │Advrts│  BRB Scene, Ending Scene, Show Chat, Ads
     * ├──────┼──────┼──────┼──────┤
     * │Raid  │Host  │Clipr │      │  Raid, Host, Create Clip
     * └──────┴──────┴──────┴──────┘
     */
    [_STREAM] = LAYOUT(
        LCTL(KC_F13), LCTL(KC_F14), LCTL(KC_F15), LCTL(KC_F16),
        LCTL(KC_F17), LCTL(KC_F18), LCTL(KC_F19), LCTL(KC_F20),
        LCTL(KC_F21), LCTL(KC_F22), LCTL(KC_F23), KC_TRNS
    )
};

// Custom macro for quick messages
enum custom_keycodes {
    CHAT_BRB = SAFE_RANGE,
    CHAT_THANKS,
    CHAT_GG
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CHAT_BRB:
            if (record->event.pressed) {
                SEND_STRING("Be right back! Taking a quick break.");
            }
            return false;
        case CHAT_THANKS:
            if (record->event.pressed) {
                SEND_STRING("Thanks for the follow/sub!");
            }
            return false;
        case CHAT_GG:
            if (record->event.pressed) {
                SEND_STRING("GG everyone! Great game!");
            }
            return false;
    }
    return true;
}

// Encoder for audio control
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _SCENES:
                // Cycle through scenes
                if (clockwise) {
                    tap_code(KC_F14);  // Next scene
                } else {
                    tap_code(KC_F13);  // Previous scene
                }
                break;
            case _AUDIO:
                // Master volume
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _STREAM:
                // Mic monitoring
                if (clockwise) {
                    tap_code16(LSFT(KC_F14));
                } else {
                    tap_code16(LSFT(KC_F13));
                }
                break;
        }
    }
    return true;
}
#endif

// RGB for stream status
#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SCENES:
            rgblight_sethsv(HSV_PURPLE);  // Scene switching mode
            break;
        case _AUDIO:
            rgblight_sethsv(HSV_CYAN);    // Audio control mode
            break;
        case _STREAM:
            rgblight_sethsv(HSV_MAGENTA); // Stream control mode
            break;
    }
    return state;
}

// Stream status indicator (set from OBS)
// Note: These variables and function are provided as an example for
// integration with OBS via custom scripts or plugins. To use:
// 1. Set streaming/recording booleans via raw HID or serial
// 2. Call stream_status_update() in matrix_scan_user() or similar
// 3. Configure OBS to send status updates via websocket/plugin
bool streaming = false;
bool recording = false;

void stream_status_update(void) {
    if (streaming && recording) {
        rgblight_sethsv(HSV_RED);  // Live + Recording
        rgblight_mode(RGBLIGHT_MODE_BREATHING);
    } else if (streaming) {
        rgblight_sethsv(HSV_RED);  // Live
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    } else if (recording) {
        rgblight_sethsv(HSV_ORANGE);  // Recording only
        rgblight_mode(RGBLIGHT_MODE_BREATHING);
    } else {
        rgblight_sethsv(HSV_GREEN);  // Offline
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    }
}
#endif

// OLED for stream info
#ifdef OLED_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("Streamer\n"), false);
    oled_write_P(PSTR("Mode: "), false);
    switch (get_highest_layer(layer_state)) {
        case _SCENES:
            oled_write_P(PSTR("SCENE\n"), false);
            break;
        case _AUDIO:
            oled_write_P(PSTR("AUDIO\n"), false);
            break;
        case _STREAM:
            oled_write_P(PSTR("STRM\n"), false);
            break;
    }
    
    // Stream status
    oled_write_P(streaming ? PSTR("LIVE ") : PSTR("OFF  "), false);
    oled_write_P(recording ? PSTR("REC") : PSTR("   "), false);
}
#endif
