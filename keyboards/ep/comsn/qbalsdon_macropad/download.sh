#!/bin/sh

curl -o config.h https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/config.h

corl -o info.json https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/info.json

curl -o qbalsdon_macropad.h https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/qbalsdon_macropad.h

curl -o rules.mk https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/rules.mk

curl -o qbalsdon_macropad.c https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/qbalsdon_macropad.c

mkdir keymaps
mkdir keymaps/default

curl -o keymaps/default/keymap.c https://raw.githubusercontent.com/e11i0t23/qmk_firmware/qbal_macro/keyboards/ep/comsn/qbalsdon_macropad/keymaps/default/keymap.c


1234554321123455432112345
