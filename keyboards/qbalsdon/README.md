# qbalsdon

Personal QMK firmware for the **Anvil** macropad — a custom 32-key board with rotary encoders, an OLED display, and RGB underglow. This folder holds shared macro and lighting definitions used across qbalsdon keymaps.

The keyboard hardware lives at [`keyboards/ep/comsn/qbalsdon_macropad`](../ep/comsn/qbalsdon_macropad).

## Hardware

| Spec | Value |
|------|-------|
| MCU | ATmega32u4 |
| Bootloader | atmel-dfu |
| Matrix | 7×5 (32 keys) |
| Encoders | 3 (push + rotate) |
| Display | SH1106 OLED (128×64) |
| Lighting | 13-LED RGB underglow strip |

### Physical layout

- **32 plain keys** — mapped via modifier combinations (`HYPR`, `MEH`, `LCAG`) to avoid conflicts with normal keyboard shortcuts.
- **3 rotary encoders** — rotation behaviour depends on the active layer; encoder 3 scrolls through Dota item names on the Dota layer.
- **3 RGB buttons** (A, B, C) — to the right of the OLED; LED indices 11, 10, and 9.
- **Underglow** — LED indices 0–8 and 12 (indices 9–11 are the RGB buttons).
- **Reset button** — top left of the OLED; hard-wired reset for entering the bootloader.

### Demo layer key grid (5×7)

The `qbalsdon6` keymap is currently running a demo layer. Special positions use these suffixes:

| Symbol | Meaning |
|--------|---------|
| **RST** | Hardware reset — not in the matrix; enters the bootloader |
| **LYR** | Layer key — advances to the next layer, wrapping from last to first |
| **\*** | Rotary encoder — press shows the label; rotate shows `X-` / `X+` on the OLED |
| **#** | RGB key — LED indices 11 (E), 10 (F), 9 (G); press shows the label, double-press cycles hue |
| **LCD** | Display only — not a switch |

Plain keys (`H`–`Z`, `1`–`6`) show their label on press; double-press sends the matching keycode.

```
        ┌─────┬─────┬─────┬─────┬─────┐
        │ RST │ LYR │  B* │  C* │  D* │
        ├─────┼─────┼─────┼─────┼─────┤
        │    LCD    │  E# │  F# │  G# │
        ├─────┼─────┼─────┼─────┼─────┤
        │  H  │  I  │  J  │  K  │  L  │
        ├─────┼─────┼─────┼─────┼─────┤
        │  M  │  N  │  O  │  P  │  Q  │
        ├─────┼─────┼─────┼─────┼─────┤
        │  R  │  S  │  T  │  U  │  V  │
        ├─────┼─────┼─────┼─────┼─────┤
        │  W  │  X  │  Y  │  Z  │  1  │
        ├─────┼─────┼─────┼─────┼─────┤
        │  2  │  3  │  4  │  5  │  6  │
        └─────┴─────┴─────┴─────┴─────┘
```

Two demo sub-layers (`L0`, `L1`) are defined in the active `qbalsdon6` keymap for local testing; underglow tint changes per sub-layer (cyan / magenta).

### Layer order (shared headers)

The `LYR` key cycles through functional layers in this order (wraps back to the start):

| Index | Layer | Next on LYR |
|-------|-------|-------------|
| 0 | Demo | Dota |
| 1 | Dota | Raspberry Pi |
| 2 | Raspberry Pi | Android |
| 3 | Android | Scripts |
| 4 | Scripts | Demo |

`LAYER_HOVER` is not part of the cycle; reach it by holding `G#` on any functional layer.

## Keymaps

| Keymap | Keyboard | Description |
|--------|----------|-------------|
| `qbalsdon6` | `ep/comsn/qbalsdon_macropad` | **Anvil V2** — current macropad firmware (recommended) |
| `qbalsdon5` | `ep/comsn/qbalsdon_macropad` | Earlier Anvil macropad layout |
| `qbalsdon4` | `custommk/genesis` | Genesis ortho layout using shared qbalsdon headers |

### qbalsdon6 layers

| Layer | Purpose |
|-------|---------|
| Demo | Default layer; OLED feedback and double-tap-to-send keys |
| Raspberry Pi | Pi terminal commands and shortcuts |
| Android | `HYPR()` key combinations for Android/ADB automation |
| Scripts | Shell/adb script strings via encoders and keys |
| Hover | Utility layer (screen on/off, RGB toggle) |

Layer colours are shown on the RGB strip and buttons. The OLED displays the active layer name.

## Shared headers

| File | Purpose |
|------|---------|
| `keymacros.h` | Umbrella include: layer indices, custom keycodes, and all layer definitions |
| `layers.h` | Layer index constants and `LAYER_NEXT()` helper |
| `anvil_map.h` | `ANVIL_MAP_*` host keycodes (F-keys, arrows, numpad, digits) |
| `adb_keys.h` | Android `HYPR()` ADB shortcut combinations |
| `adb_scripts.h` | Shell/adb script strings for the scripts layer |
| `layer_raspberry.h` | Raspberry Pi layer grid map and key macros |
| `layer_android.h` | Android layer grid map and key macros |
| `layer_scripts.h` | Scripts layer grid map and key macros |
| `layer_demo.h` | Demo layer grid map and key macros |
| `layer_hover.h` | Hover utility layer grid map and key macros |
| `colours.h` | RGB animation helpers and rainbow colour palette |

Each `layer_*.h` file contains the 5×7 grid as a comment and documents the macro bound to every letter/number position (plus `*`, `#`, `LYR`, and `RST`).

Keymaps can include `keymacros.h` directly or maintain a thin re-export (as `qbalsdon6` does).

## Build and flash

### Prerequisites

- [QMK CLI](https://docs.qmk.fm/#/newbs_getting_started)
- AVR toolchain (`avr-gcc@8` recommended on macOS)
- `dfu-util` (for flashing)

On macOS with Homebrew:

```bash
brew tap osx-cross/avr
brew install avr-gcc@8 dfu-util
pip install qmk
```

`avr-gcc@8` is keg-only and is not added to your PATH automatically. Add it before building or flashing:

```bash
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
```

To make that permanent, add the same line to `~/.zshrc`.

Initialize the LUFA submodule (required for AVR builds):

```bash
git submodule update --init lib/lufa
```

### Compile

```bash
qmk compile -kb ep/comsn/qbalsdon_macropad -km qbalsdon6
```

Or with `make`:

```bash
make ep/comsn/qbalsdon_macropad:qbalsdon6
```

### Flash

1. Put the board into bootloader mode using the reset button (top left of the OLED).
2. Verify the device is visible:

```bash
dfu-util -l
```

3. Flash:

```bash
qmk flash -kb ep/comsn/qbalsdon_macropad -km qbalsdon6
```

## Modifier reference

qbalsdon keymaps use QMK [advanced keycodes](https://docs.qmk.fm/features/advanced_keycodes) to send key combinations unlikely to conflict with host shortcuts:

| Modifier | Keys held |
|----------|-----------|
| `HYPR(kc)` | Left Ctrl + Shift + Alt + GUI + `kc` |
| `MEH(kc)` | Left Ctrl + Shift + Alt + `kc` |
| `LCAG(kc)` | Left Ctrl + Alt + GUI + `kc` |

Plain keys are mapped to `KC_F1`–`KC_F19`, arrow keys, numpad operators, and `KC_1`–`KC_0`. Note that macOS does not recognise `KC_F20`–`KC_F24`.

## Further reading

- [qbalsdon6 keymap README](../ep/comsn/qbalsdon_macropad/keymaps/qbalsdon6/README.md) — RGB indices, encoder details, and known issues
- [qbalsdon5 keymap README](../ep/comsn/qbalsdon_macropad/keymaps/qbalsdon5/README.md) — earlier layout notes
- [QMK cheatsheet](https://jayliu50.github.io/qmk-cheatsheet/)

## Maintainer

Quintin Balsdon — hardware originally designed by Elliot Powell.
