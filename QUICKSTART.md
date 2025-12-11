# Hackypady Quick Start Guide

Get your Hackypady mini keyboard up and running in 5 minutes!

## Prerequisites

Before you begin, make sure you have:
- ✅ A computer with USB port (Windows/Mac/Linux)
- ✅ USB-C cable
- ✅ Your assembled Hackypady keyboard (or see [BUILD_GUIDE.md](docs/BUILD_GUIDE.md))

## Step 1: Connect Your Keyboard (30 seconds)

1. Plug the USB-C cable into your Hackypady
2. Connect the other end to your computer
3. Wait for the device to be recognized (LEDs should light up)

> **Note**: Windows users may need to wait for driver installation to complete.

## Step 2: Test Basic Functionality (1 minute)

1. Open a text editor (Notepad, TextEdit, etc.)
2. Press each key on your Hackypady
3. Verify that numbers 1-9, 0, and "-" appear on screen

**Default Layout:**
```
┌───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 4 │
├───┼───┼───┼───┤
│ 5 │ 6 │ 7 │ 8 │
├───┼───┼───┼───┤
│ 9 │ 0 │ - │FN │
└───┴───┴───┴───┘
```

## Step 3: Try Different Layers (1 minute)

1. Hold the bottom-right key (FN/Layer key)
2. While holding, press the other keys
3. You should see F1-F11 function keys instead!

**Function Layer (hold FN):**
```
┌───┬───┬───┬───┐
│F1 │F2 │F3 │F4 │
├───┼───┼───┼───┤
│F5 │F6 │F7 │F8 │
├───┼───┼───┼───┤
│F9 │F10│F11│   │
└───┴───┴───┴───┘
```

## Step 4: Customize with VIA (3 minutes)

### Download VIA
1. Visit [caniusevia.com](https://caniusevia.com)
2. Download VIA for your operating system
3. Install and open VIA

### Configure Your Keys
1. VIA will automatically detect your Hackypady
2. Click on any key to change its function
3. Drag and drop from the available keycodes
4. Changes save automatically!

### Popular Customizations
- **Copy/Paste Combo**: Set keys to Ctrl+C and Ctrl+V
- **Media Controls**: Add play, pause, volume up/down
- **App Launchers**: Assign keys to open your favorite apps
- **Custom Macros**: Record multi-key sequences

## Step 5: Test RGB Lighting (Optional)

If your Hackypady has RGB LEDs:

1. Press FN + F9 to toggle RGB on/off
2. Press FN + F10 to cycle through effects
3. Press FN + F11/F12 to adjust brightness

## Common Issues & Solutions

### Keyboard Not Detected
- **Try a different USB port** - Some ports provide more power
- **Use a different cable** - Some cables are charge-only
- **Reset the keyboard** - Press the reset button on the back twice

### Keys Not Working
- **Check if FN is stuck** - Press and release the FN key
- **Test in different software** - Try a text editor, web browser
- **Reflash firmware** - See [README.md](README.md#firmware-installation)

### VIA Not Detecting Keyboard
- **Update VIA** - Download the latest version
- **Enable VIA in firmware** - Make sure VIA support is compiled in
- **Try USB 2.0 port** - Some USB 3.0 ports have issues

## What's Next?

### Learn More
- 📖 **Full Documentation**: See [README.md](README.md) for all features
- 🔧 **Build Guide**: [docs/BUILD_GUIDE.md](docs/BUILD_GUIDE.md) for assembly
- ⌨️ **Keymap Guide**: [docs/KEYMAP_GUIDE.md](docs/KEYMAP_GUIDE.md) for advanced customization
- 🛠️ **Hardware Details**: [hardware/SCHEMATIC.md](hardware/SCHEMATIC.md) for technical specs

### Try Example Layouts
Check out pre-made layouts for different workflows:
- **Programmer**: [firmware/keymaps/examples/programmer_layout.c](firmware/keymaps/examples/programmer_layout.c)
- **Video Editor**: [firmware/keymaps/examples/video_editor_layout.c](firmware/keymaps/examples/video_editor_layout.c)
- **Streamer**: [firmware/keymaps/examples/streamer_layout.c](firmware/keymaps/examples/streamer_layout.c)

### Join the Community
- 🐛 **Report Issues**: [GitHub Issues](https://github.com/Az154za/Hackypady/issues)
- 💬 **Ask Questions**: [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions)
- 🤝 **Contribute**: See [CONTRIBUTING.md](CONTRIBUTING.md)

## Tips for New Users

1. **Start Simple**: Use the default layout for a few days before customizing
2. **Document Your Changes**: Keep notes on what each key does in your layout
3. **Use Layer Colors**: If you have RGB, assign different colors to each layer
4. **Backup Your Config**: Export your VIA configuration regularly
5. **Experiment**: Don't be afraid to try different layouts - it's easy to change back!

## Quick Reference Card

Print this and keep it near your keyboard:

```
┌────────────────────────────────────────┐
│         HACKYPADY QUICK REF            │
├────────────────────────────────────────┤
│ Layer 0 (Default): Numbers 1-0, -     │
│ Layer 1 (Hold FN): Function keys F1-11│
│ Layer 2 (Gaming): Q,W,E,R,A,S,D,F     │
│ Layer 3 (Media): Media controls       │
├────────────────────────────────────────┤
│ Reset: Double-tap reset button        │
│ RGB Toggle: FN + F9                   │
│ RGB Mode: FN + F10                    │
│ Brightness: FN + F11/F12              │
└────────────────────────────────────────┘
```

---

**Congratulations!** You're now ready to boost your productivity with Hackypady! 🎉

For detailed documentation, see the full [README.md](README.md).

**Questions?** Open an issue or discussion on GitHub!
