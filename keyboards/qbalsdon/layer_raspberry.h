#pragma once

#include "layers.h"

/*
 * Raspberry Pi layer (LAYER_RASPBERRY)
 *
 *        ┌─────┬─────┬─────┬─────┬─────┐
 *        │ RST │ LYR │  B* │  C* │  D* │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │    LCD    │  E# │  F# │  G# │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │  H  │  I  │  J  │  K  │  L  │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │  M  │  N  │  O  │  P  │  Q  │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │  R  │  S  │  T  │  U  │  V  │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │  W  │  X  │  Y  │  Z  │  1  │
 *        ├─────┼─────┼─────┼─────┼─────┤
 *        │  2  │  3  │  4  │  5  │  6  │
 *        └─────┴─────┴─────┴─────┴─────┘
 *
 * RST  — (hardware reset, not assigned)
 * LYR  — TO(LAYER_ANDROID)
 * B*   press     → RASPBERRY_01 (encoder 1 click)
 * B*   decrease  → (encoder 0, CCW) (unassigned)
 * B*   increase  → (encoder 0, CW)  (unassigned)
 * C*   press     → RASPBERRY_02 (encoder 2 click)
 * C*   decrease  → (encoder 1, CCW) (unassigned)
 * C*   increase  → (encoder 1, CW)  (unassigned)
 * D*   press     → (unassigned)
 * D*   decrease  → (encoder 2, CCW) (unassigned)
 * D*   increase  → (encoder 2, CW)  (unassigned)
 * E#   press     → RASPBERRY_03 → LALT(KC_F2)
 * F#   press     → RASPBERRY_04 → send_string("lxterminal")
 * G#   press     → HOVER (LT(LAYER_HOVER, _______))
 * H    → RASPBERRY_05 → send_string("hostname -I")
 * I    → RASPBERRY_06 → KC_BSPACE
 * J    → RASPBERRY_07 → send_string("sudo raspi-config")
 * K    → RASPBERRY_08 → send_string("cat /etc/wpa_supplicant/wpa_supplicant.conf")
 * L    → RASPBERRY_09 → send_string("sudo sh -c wpa_passphrase …")
 * M    → RASPBERRY_10 → (unassigned)
 * N    → RASPBERRY_11 → send_string("wpa_passphrase …")
 * O    → RASPBERRY_12 → send_string("iwlist wlan0 scan")
 * P    → RASPBERRY_13 → (unassigned)
 * Q    → RASPBERRY_14 → (unassigned)
 * R    → RASPBERRY_15 → send_string("sudo poweroff")
 * S    → RASPBERRY_16 → LSFT(LCTL(KC_Q))
 * T    → RASPBERRY_17 → KC_ESCAPE
 * U    → RASPBERRY_18 → KC_ENTER
 * V    → RASPBERRY_19 → (unassigned)
 * W    → RASPBERRY_20 → (unassigned)
 * X    → RASPBERRY_21 → (unassigned)
 * Y    → RASPBERRY_22 → (unassigned)
 * Z    → RASPBERRY_23 → (unassigned)
 * 1    → RASPBERRY_24 → (unassigned)
 * 2    → RASPBERRY_25 → (unassigned)
 * 3    → RASPBERRY_26 → (unassigned)
 * 4    → RASPBERRY_27 → (unassigned)
 * 5    → RASPBERRY_28 → (unassigned)
 * 6    → RASPBERRY_29 → (unassigned)
 */

#define RASPBERRY_LYR           TO(LAYER_ANDROID)
#define RASPBERRY_ENC_B_PRESS   RASPBERRY_01
#define RASPBERRY_ENC_C_PRESS   RASPBERRY_02
#define RASPBERRY_ENC_D_PRESS   KC_NO
#define RASPBERRY_HOVER         LT(LAYER_HOVER, KC_NO)

#define RASPBERRY_E RASPBERRY_03
#define RASPBERRY_F RASPBERRY_04
#define RASPBERRY_G RASPBERRY_HOVER
#define RASPBERRY_H RASPBERRY_05
#define RASPBERRY_I RASPBERRY_06
#define RASPBERRY_J RASPBERRY_07
#define RASPBERRY_K RASPBERRY_08
#define RASPBERRY_L RASPBERRY_09
#define RASPBERRY_M RASPBERRY_10
#define RASPBERRY_N RASPBERRY_11
#define RASPBERRY_O RASPBERRY_12
#define RASPBERRY_P RASPBERRY_13
#define RASPBERRY_Q RASPBERRY_14
#define RASPBERRY_R RASPBERRY_15
#define RASPBERRY_S RASPBERRY_16
#define RASPBERRY_T RASPBERRY_17
#define RASPBERRY_U RASPBERRY_18
#define RASPBERRY_V RASPBERRY_19
#define RASPBERRY_W RASPBERRY_20
#define RASPBERRY_X RASPBERRY_21
#define RASPBERRY_Y RASPBERRY_22
#define RASPBERRY_Z RASPBERRY_23
#define RASPBERRY_1 RASPBERRY_24
#define RASPBERRY_2 RASPBERRY_25
#define RASPBERRY_3 RASPBERRY_26
#define RASPBERRY_4 RASPBERRY_27
#define RASPBERRY_5 RASPBERRY_28
#define RASPBERRY_6 RASPBERRY_29
