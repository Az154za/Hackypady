# Hackypady Keymap Customization Guide

Learn how to create and customize your own keymaps for Hackypady.

## Table of Contents
1. [Understanding Layers](#understanding-layers)
2. [Basic Keycodes](#basic-keycodes)
3. [Advanced Features](#advanced-features)
4. [Example Keymaps](#example-keymaps)
5. [VIA Configuration](#via-configuration)

## Understanding Layers

Layers are like different keyboard layouts that you can switch between. Think of them as transparent sheets stacked on top of each other.

### Layer Types
- **Base Layer**: Your default layout (Layer 0)
- **Function Layer**: Accessed by holding a modifier key
- **Toggle Layer**: Switched with a key press
- **Momentary Layer**: Active only while holding a key

### Layer Switching Keys
```c
MO(layer)    // Momentary - active while held
TG(layer)    // Toggle - switches layer on/off
TO(layer)    // To layer - permanent switch
LT(layer, kc) // Layer tap - tap for key, hold for layer
```

## Basic Keycodes

### Letters and Numbers
```c
KC_A to KC_Z     // Letters A-Z
KC_1 to KC_0     // Numbers 1-0
```

### Modifiers
```c
KC_LCTL   // Left Control
KC_LSFT   // Left Shift
KC_LALT   // Left Alt
KC_LGUI   // Left Windows/Command
KC_RCTL   // Right Control
KC_RSFT   // Right Shift
```

### Function Keys
```c
KC_F1 to KC_F24   // Function keys
KC_ESC            // Escape
KC_TAB            // Tab
KC_ENTER          // Enter
KC_BSPC           // Backspace
KC_DEL            // Delete
```

### Navigation
```c
KC_UP     // Up arrow
KC_DOWN   // Down arrow
KC_LEFT   // Left arrow
KC_RIGHT  // Right arrow
KC_HOME   // Home
KC_END    // End
KC_PGUP   // Page Up
KC_PGDN   // Page Down
```

### Media Keys
```c
KC_MPLY   // Play/Pause
KC_MNXT   // Next track
KC_MPRV   // Previous track
KC_MSTP   // Stop
KC_MUTE   // Mute
KC_VOLU   // Volume Up
KC_VOLD   // Volume Down
```

## Advanced Features

### Mod-Tap Keys
Tap for one action, hold for modifier:
```c
MT(MOD_LCTL, KC_A)  // Tap: A, Hold: Control
LCTL_T(KC_A)        // Same as above (shorthand)
LSFT_T(KC_B)        // Tap: B, Hold: Shift
```

### Macros
Create custom key sequences:
```c
enum custom_keycodes {
    MY_MACRO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_MACRO:
            if (record->event.pressed) {
                SEND_STRING("Hello World!");
            }
            return false;
    }
    return true;
}
```

### Combos
Press multiple keys together for an action:
```c
const uint16_t PROGMEM combo_esc[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC)
};
```

### Tap Dance
Multiple actions on the same key:
```c
// Single tap: (, Double tap: )
enum {
    TD_BRACES = 0
};

void dance_braces(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LPRN);
    } else {
        tap_code16(KC_RPRN);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACES] = ACTION_TAP_DANCE_FN(dance_braces)
};
```

## Example Keymaps

### Programmer Layout
```c
[_PROG] = LAYOUT(
    KC_F5,    KC_F9,    KC_F10,   KC_F11,      // Debug keys
    LCTL(KC_C), LCTL(KC_V), LCTL(KC_Z), LCTL(KC_Y),  // Copy, Paste, Undo, Redo
    KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN      // Navigation
)
```

### Video Editor Layout
```c
[_VIDEO] = LAYOUT(
    KC_SPC,   KC_J,     KC_K,     KC_L,        // Playback control
    KC_C,     KC_V,     KC_B,     KC_X,        // Cut, Paste, Blade, Delete
    LCTL(KC_Z), LCTL(KC_S), KC_I, KC_O        // Undo, Save, In, Out
)
```

### Streamer Layout
```c
[_STREAM] = LAYOUT(
    KC_F13,   KC_F14,   KC_F15,   KC_F16,      // OBS scenes 1-4
    KC_F17,   KC_F18,   KC_F19,   KC_F20,      // Start/stop, mute, etc
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY      // Audio control
)
```

### Music Production Layout
```c
[_MUSIC] = LAYOUT(
    KC_SPC,   KC_R,     KC_M,     KC_S,        // Play, Record, Metronome, Save
    KC_Z,     KC_X,     KC_C,     KC_V,        // Zoom, Cut, Copy, Paste
    LCTL(KC_Z), KC_HOME, KC_END, KC_ENTER     // Undo, Start, End, Accept
)
```

### System Admin Layout
```c
[_ADMIN] = LAYOUT(
    LCTL(LSFT(KC_ESC)), KC_F5, KC_F12, LCTL(LALT(KC_DEL)),  // Task manager, Refresh
    LGUI(KC_L), LGUI(KC_D), LGUI(KC_E), LGUI(KC_R),          // Lock, Desktop, Explorer, Run
    KC_PSCR,  LGUI(LSFT(KC_S)), KC_CALC, KC_MYCM             // Screenshot, Snip, Calculator
)
```

## VIA Configuration

VIA allows real-time keymap editing without recompiling firmware.

### Enable VIA
Add to `rules.mk`:
```makefile
VIA_ENABLE = yes
```

Add to `config.h`:
```c
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
```

### Using VIA
1. Install VIA from [caniusevia.com](https://caniusevia.com)
2. Connect your Hackypady
3. VIA will auto-detect your keyboard
4. Drag and drop keys to customize
5. Changes save automatically to EEPROM

### VIA Features
- **Drag & Drop**: Visual keymap editor
- **Macros**: Record and assign macros
- **Lighting**: Control RGB effects
- **Save/Load**: Export and import layouts
- **Live Updates**: Changes apply immediately

## Tips and Best Practices

### Layout Design
1. **Keep common keys accessible**: Place frequently used keys in easy-to-reach positions
2. **Use layers logically**: Group related functions together
3. **Test extensively**: Try your layout for a few days before finalizing
4. **Document your layout**: Create a visual reference for quick lookup

### Performance Optimization
```c
// Reduce firmware size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Faster response
#define USB_POLLING_INTERVAL_MS 1
#define TAP_CODE_DELAY 0
```

### Debugging
```c
// Enable console output
CONSOLE_ENABLE = yes

// In your code
uprintf("Key pressed: %d\n", keycode);
```

## Common Issues

### Key Not Responding
- Check if layer is blocking the key
- Verify keycode spelling
- Test with a simple keycode like `KC_A`

### Modifier Stuck
- Add `#define IGNORE_MOD_TAP_INTERRUPT`
- Adjust `TAPPING_TERM` value
- Use `PERMISSIVE_HOLD` if needed

### Layer Confusion
- Use OLED to show active layer
- Use different RGB colors per layer
- Keep layer switching keys consistent

## Resources

- [QMK Keycodes](https://docs.qmk.fm/#/keycodes)
- [Layer Documentation](https://docs.qmk.fm/#/feature_layers)
- [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/)
- [VIA Documentation](https://www.caniusevia.com/docs)

## Share Your Layout!

Created an awesome keymap? Share it with the community!
1. Fork the repository
2. Add your keymap to `firmware/keymaps/your_name/`
3. Include a README describing your layout
4. Submit a pull request

Happy customizing! ⌨️
