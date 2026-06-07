#pragma once

#include "adb_keys.h"
#include "layers.h"

/*
 * Android layer (LAYER_ANDROID)
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
 * LYR  — TO(LAYER_SCRIPTS)
 * B*   press     → ADB_UNLOCK / HYPR(ANVIL_MAP_01) / KC_F1
 * B*   decrease  → (encoder 0, CCW) ADB_TB_PREV / HYPR(ANVIL_MAP_04)
 * B*   increase  → (encoder 0, CW)  ADB_TB_NEXT / HYPR(ANVIL_MAP_03)
 * C*   press     → ADB_TALKBACK / HYPR(ANVIL_MAP_02) / KC_F2
 * C*   decrease  → (encoder 1, CCW) ADB_TB_VOLD / HYPR(ANVIL_MAP_07)
 * C*   increase  → (encoder 1, CW)  ADB_TB_VOLU / HYPR(ANVIL_MAP_05)
 * D*   press     → ADB_TB_NEXT / HYPR(ANVIL_MAP_03) / KC_F3
 * D*   decrease  → (encoder 2, CCW) ANVIL_MAP_37 / KC_8
 * D*   increase  → (encoder 2, CW)  ANVIL_MAP_36 / KC_7
 * E#   press     → ADB_TB_PREV / HYPR(ANVIL_MAP_04) / KC_F4
 * F#   press     → ADB_TB_VOLU / HYPR(ANVIL_MAP_05) / KC_F5
 * G#   press     → ANDROID_HOVER (LT(LAYER_HOVER, ADB_TB_MUTE / HYPR(ANVIL_MAP_06)))
 * H    → ADB_TB_VOLD / HYPR(ANVIL_MAP_07) / KC_F7
 * I    → ADB_TB_HEADP / HYPR(ANVIL_MAP_08) / KC_F8
 * J    → ADB_TB_HEADN / HYPR(ANVIL_MAP_09) / KC_F9
 * K    → ADB_HOME / HYPR(ANVIL_MAP_10) / KC_F10
 * L    → ADB_BACK / HYPR(ANVIL_MAP_11) / KC_F11
 * M    → ADB_POWER / HYPR(ANVIL_MAP_12) / KC_F12
 * N    → ADB_TB_FOCUS / HYPR(ANVIL_MAP_13) / KC_F13
 * O    → ADB_TB_CURTAIN / HYPR(ANVIL_MAP_14) / KC_F14
 * P    → ADB_TB_CLICK / HYPR(ANVIL_MAP_15) / KC_F15
 * Q    → ADB_RECORD_OFF / HYPR(ANVIL_MAP_16) / KC_F16
 * R    → ADB_RECORD_ON / HYPR(ANVIL_MAP_17) / KC_F17
 * S    → HYPR(ANVIL_MAP_18) / KC_F18
 * T    → HYPR(ANVIL_MAP_19) / KC_F19
 * U    → HYPR(ANVIL_MAP_20) / KC_UP
 * V    → HYPR(ANVIL_MAP_21) / KC_DOWN
 * W    → HYPR(ANVIL_MAP_22) / KC_LEFT
 * X    → HYPR(ANVIL_MAP_23) / KC_RIGHT
 * Y    → HYPR(ANVIL_MAP_24) / KC_KP_ASTERISK
 * Z    → HYPR(ANVIL_MAP_25) / KC_KP_MINUS
 * 1    → HYPR(ANVIL_MAP_26) / KC_KP_PLUS
 * 2    → HYPR(ANVIL_MAP_27) / KC_EQL
 * 3    → HYPR(ANVIL_MAP_28) / KC_SPC
 * 4    → HYPR(ANVIL_MAP_29) / KC_NUHS
 * 5    → HYPR(ANVIL_MAP_30) / KC_1
 * 6    → HYPR(ANVIL_MAP_31) / KC_2
 */

#define ANDROID_LYR           TO(LAYER_SCRIPTS)
#define ANDROID_ENC_B_PRESS   ADB_UNLOCK
#define ANDROID_ENC_C_PRESS   ADB_TALKBACK
#define ANDROID_ENC_D_PRESS   ADB_TB_NEXT
#define ANDROID_HOVER         LT(LAYER_HOVER, ADB_TB_MUTE)

#define ANDROID_E ADB_TB_PREV
#define ANDROID_F ADB_TB_VOLU
#define ANDROID_G ANDROID_HOVER
#define ANDROID_H ADB_TB_VOLD
#define ANDROID_I ADB_TB_HEADP
#define ANDROID_J ADB_TB_HEADN
#define ANDROID_K ADB_HOME
#define ANDROID_L ADB_BACK
#define ANDROID_M ADB_POWER
#define ANDROID_N ADB_TB_FOCUS
#define ANDROID_O ADB_TB_CURTAIN
#define ANDROID_P ADB_TB_CLICK
#define ANDROID_Q ADB_RECORD_OFF
#define ANDROID_R ADB_RECORD_ON
#define ANDROID_S HYPR(ANVIL_MAP_18)
#define ANDROID_T HYPR(ANVIL_MAP_19)
#define ANDROID_U HYPR(ANVIL_MAP_20)
#define ANDROID_V HYPR(ANVIL_MAP_21)
#define ANDROID_W HYPR(ANVIL_MAP_22)
#define ANDROID_X HYPR(ANVIL_MAP_23)
#define ANDROID_Y HYPR(ANVIL_MAP_24)
#define ANDROID_Z HYPR(ANVIL_MAP_25)
#define ANDROID_1 HYPR(ANVIL_MAP_26)
#define ANDROID_2 HYPR(ANVIL_MAP_27)
#define ANDROID_3 HYPR(ANVIL_MAP_28)
#define ANDROID_4 HYPR(ANVIL_MAP_29)
#define ANDROID_5 HYPR(ANVIL_MAP_30)
#define ANDROID_6 HYPR(ANVIL_MAP_31)
