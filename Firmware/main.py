import board
from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.handlers.sequences import simple_key_sequence

from kmk.modules.encoder import Encoder
from kmk.modules.display import Display, Oled, OledData
display = Display(
    oled=Oled(
        OledData(
            width=128,
            height=64,
            i2c=board.I2C(),  # use your board’s I2C pins
        )
    )
)
keyboard.modules.append(display)


encoder = Encoder()
keyboard.modules.append(encoder)

# Only A and B pins (no switch)
encoder.pins = ((board.GP02, board.GP01))

# Map actions: (counter‑clockwise, clockwise)
encoder.map = [
    ((KC.VOLD, KC.VOLU),)  # Rotate left = Volume Down, right = Volume Up
]
volume_level = 50  # start at 50%

def update_volume(delta):
    global volume_level
    volume_level = max(0, min(100, volume_level + delta))
    display.oled.draw_text(0, 0, f'Volume: {volume_level}%')
    display.oled.show()
def on_encoder_turn(direction):
    if direction < 0:
        update_volume(-5)
    else:
        update_volume(+5)

encoder.handler = on_encoder_turn


with open("output.txt", "r") as file:
    lines = file.readlines()
# Remove newline characters
lines = [line.strip() for line in lines]
print(lines)
keyboard = KMKKeyboard()
spotify=KC.LCTRL(KC.LALT(KC._0))
terminal=KC.LCTRL(KC.LALT(KC._1))
vscode=KC.LCTRL(KC.LALT(KC._2))
fusion360=KC.LCTRL(KC.LALT(KC._3))
kicad=KC.LCTRL(KC.LALT(KC._4))
reddit=simple_key_sequence((
    KC.LCTRL, KC.LALT, KC._5,   # Trigger your browser shortcut
    KC.H, KC.T, KC.T, KC.P, KC.S, KC.COLN, KC.SLSH, KC.SLSH,
    KC.R, KC.E, KC.D, KC.D, KC.I, KC.T, KC.DOT, KC.C, KC.O, KC.M,
    KC.ENTER))
github = simple_key_sequence((
    KC.LCTRL(KC.LALT(KC._5)),   # Trigger your browser shortcut
    KC.H, KC.T, KC.T, KC.P, KC.S, KC.COLN, KC.SLSH, KC.SLSH,
    KC.G, KC.I, KC.T, KC.H, KC.U, KC.B,
    KC.DOT, KC.C, KC.O, KC.M,
    KC.ENTER
))
linkedln = simple_key_sequence((
    KC.LCTRL(KC.LALT(KC._5)),   # Trigger your browser shortcut
    KC.H, KC.T, KC.T, KC.P, KC.S, KC.COLN, KC.SLSH, KC.SLSH,
    KC.W, KC.W, KC.W, KC.DOT,
    KC.L, KC.I, KC.N, KC.K, KC.E, KC.D, KC.I, KC.N,
    KC.DOT, KC.C, KC.O, KC.M,
    KC.ENTER
))
youtube = simple_key_sequence((
    KC.LCTRL(KC.LALT(KC._5)),   # Trigger your browser shortcut
    KC.H, KC.T, KC.T, KC.P, KC.S, KC.COLN, KC.SLSH, KC.SLSH,
    KC.W, KC.W, KC.W, KC.DOT,
    KC.Y, KC.O, KC.U, KC.T, KC.U, KC.B, KC.E,
    KC.DOT, KC.C, KC.O, KC.M,
    KC.ENTER
))

keyboard.col_pins = (board.GP27, board.GP28, board.GP29)
keyboard.row_pins = (board.GP0, board.GP10, board.GP11)
keyboard.diode_orientation = keyboard.DIODE_COL2ROW
keyboard.keymap = [
    [spotify, terminal, vscode],
    [fusion360, kicad, reddit],
    [github, linkedln,youtube ]
]

if __name__ == '__main__':
    keyboard.go()
