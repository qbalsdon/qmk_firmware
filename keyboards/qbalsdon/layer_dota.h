#pragma once

#include "layers.h"
#include "dota.h"

/*
 * Dota layer (LAYER_DOTA)
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
 * B*   decrease/increase → (encoder 0) previous/next shop item (no OLED)
 * E#   press     → DOTA_TYPE_ITEM (types selected shop item)
 * C*   press     → DOTA_PAUSE / KC_F9
 * F#   press     → DOTA_FOCUS_HERO / KC_F1
 * G#   press     → DOTA_HOVER (LT(LAYER_HOVER, DOTA_STORE / KC_F4))
 */

#define DOTA_LYR           TO(LAYER_RASPBERRY)
#define DOTA_ENC_B_PRESS   KC_NO
#define DOTA_ENC_C_PRESS   DOTA_PAUSE
#define DOTA_ENC_D_PRESS   KC_NO
#define DOTA_RGB_E_PRESS   DOTA_TYPE_ITEM
#define DOTA_RGB_F_PRESS   DOTA_FOCUS_HERO
#define DOTA_HOVER         LT(LAYER_HOVER, DOTA_STORE)

#define DOTA_H DOTA_SPELL1
#define DOTA_I DOTA_SPELL2
#define DOTA_J DOTA_SPELL3
#define DOTA_K KC_NO
#define DOTA_L DOTA_ULTIMATE
#define DOTA_M DOTA_ITEM_01
#define DOTA_N DOTA_ITEM_02
#define DOTA_O DOTA_ITEM_03
#define DOTA_P DOTA_CHATWHEEL
#define DOTA_Q DOTA_TP
#define DOTA_R DOTA_ITEM_04
#define DOTA_S DOTA_ITEM_05
#define DOTA_T DOTA_ITEM_06
#define DOTA_U KC_NO
#define DOTA_V KC_NO
#define DOTA_W KC_NO
#define DOTA_X KC_NO
#define DOTA_Y KC_NO
#define DOTA_Z KC_NO
#define DOTA_1 KC_NO
#define DOTA_2 KC_NO
#define DOTA_3 KC_NO
#define DOTA_4 KC_NO
#define DOTA_5 DOTA_SHIFT
#define DOTA_6 DOTA_DENY
