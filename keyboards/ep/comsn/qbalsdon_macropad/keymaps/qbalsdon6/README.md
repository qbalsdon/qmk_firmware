# Anvil V2

## Deployment

`qmk flash -kb ep/comsn/qbalsdon_macropad -km qbalsdon6`

[Useful cheatsheet][0]

## Keys

### Plain keys

There are 25 plain keys, they have no lights associated with them. They will perform most of the macro functions and will be mapped via some
combination of keys that I don't typically use.

Each layer will use complex [Modifier][1] so that if the key itself is mapped, the combination is probably not. The Modifiers used will be

`HYPR(kc)` - Hold Left Control, Shift, Alt and GUI with key code `kc`
`MEH(kc)`  - Hold Left Control, Shift and Alt  with key code `kc`
`LCAG(kc)` - Hold Left Control, Alt and GUI and press key code `kc`

KC_F1 through KC_F19 (KC_F20 to KC_24 is not recognised by Mac)
KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT
KC_KP_ASTERISK
KC_KP_MINUS
KC_KP_PLUS
KC_EQL
KC_SPC
KC_NUHS
KC_1 through KC_0

### RGB Keys

[QMK COLOUR DOCUMENTATION][2]

All the colours are on one strip. The 3 RGB buttons are located to the right of the OLED. They are labelled (from left to right):
1. A: LED index 11
2. B: LED index 10
3. C: LED index 9

### Rotary encoders

Have 2 features: Push button and rotation

### Push buttons

Top left of the OLED: Hard wired reset. This cannot be changed.

Top right of the OLED: Can be modified. Used for layer transitions.

## Under glow

Exists on a strip with the 3 buttons. Their indices are from 0 to 12, excluding 9, 10 and 11

## OLED

## TODO
1. The hover layer is not being reported on the OLED correctly

[0]: https://jayliu50.github.io/qmk-cheatsheet/
[1]: https://beta.docs.qmk.fm/using-qmk/simple-keycodes/feature_advanced_keycodes
[2]: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#colors-id-colors
