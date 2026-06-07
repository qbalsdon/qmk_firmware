#pragma once

#include "layers.h"

/*
 * Demo layer (LAYER_DEMO) — default layer (index 0)
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
 * LYR  — DEMO_LYR (custom keycode; advances to LAYER_RASPBERRY, next in cycle)
 * B*   press     → DEMO_ENC_B (shows B on OLED)
 * B*   decrease  → (encoder 0, CCW) shows B-
 * B*   increase  → (encoder 0, CW)  shows B+
 * C*   press     → DEMO_ENC_C (shows C on OLED)
 * C*   decrease  → (encoder 1, CCW) shows C-
 * C*   increase  → (encoder 1, CW)  shows C+
 * D*   press     → DEMO_ENC_D (shows D on OLED)
 * D*   decrease  → (encoder 2, CCW) shows D-
 * D*   increase  → (encoder 2, CW)  shows D+
 * E#   press     → DEMO_RGB_E (shows E; double-press cycles LED 11 hue)
 * F#   press     → DEMO_RGB_F (shows F; double-press cycles LED 10 hue)
 * G#   press     → DEMO_RGB_G (shows G; double-press cycles LED 9 hue)
 * H    → DEMO_H (shows H; double-press sends KC_H)
 * I    → DEMO_I (shows I; double-press sends KC_I)
 * J    → DEMO_J (shows J; double-press sends KC_J)
 * K    → DEMO_K (shows K; double-press sends KC_K)
 * L    → DEMO_L (shows L; double-press sends KC_L)
 * M    → DEMO_M (shows M; double-press sends KC_M)
 * N    → DEMO_N (shows N; double-press sends KC_N)
 * O    → DEMO_O (shows O; double-press sends KC_O)
 * P    → DEMO_P (shows P; double-press sends KC_P)
 * Q    → DEMO_Q (shows Q; double-press sends KC_Q)
 * R    → DEMO_R (shows R; double-press sends KC_R)
 * S    → DEMO_S (shows S; double-press sends KC_S)
 * T    → DEMO_T (shows T; double-press sends KC_T)
 * U    → DEMO_U (shows U; double-press sends KC_U)
 * V    → DEMO_V (shows V; double-press sends KC_V)
 * W    → DEMO_W (shows W; double-press sends KC_W)
 * X    → DEMO_X (shows X; double-press sends KC_X)
 * Y    → DEMO_Y (shows Y; double-press sends KC_Y)
 * Z    → DEMO_Z (shows Z; double-press sends KC_Z)
 * 1    → DEMO_1 (shows 1; double-press sends KC_1)
 * 2    → DEMO_2 (shows 2; double-press sends KC_2)
 * 3    → DEMO_3 (shows 3; double-press sends KC_3)
 * 4    → DEMO_4 (shows 4; double-press sends KC_4)
 * 5    → DEMO_5 (shows 5; double-press sends KC_5)
 * 6    → DEMO_6 (shows 6; double-press sends KC_6)
 */

#define DEMO_LYR_TO           TO(LAYER_RASPBERRY)
#define DEMO_ENC_B_PRESS      DEMO_ENC_B
#define DEMO_ENC_C_PRESS      DEMO_ENC_C
#define DEMO_ENC_D_PRESS      DEMO_ENC_D
#define DEMO_RGB_E_PRESS      DEMO_RGB_E
#define DEMO_RGB_F_PRESS      DEMO_RGB_F
#define DEMO_RGB_G_PRESS      DEMO_RGB_G

// RGB button LED indices (E# F# G#)
#define DEMO_RGB_LED_E 11
#define DEMO_RGB_LED_F 10
#define DEMO_RGB_LED_G 9
