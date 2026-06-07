#pragma once

#include "adb_keys.h"
#include "adb_scripts.h"
#include "layers.h"

/*
 * Scripts layer (LAYER_SCRIPTS)
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
 * LYR  — TO(LAYER_DEMO)
 * B*   press     → LCAG(ANVIL_MAP_01) → ADB_UNLOCK_SCRIPT
 * B*   decrease  → (encoder 0, CCW) ADB_TB_PREV_SCRIPT
 * B*   increase  → (encoder 0, CW)  ADB_TB_NEXT_SCRIPT
 * C*   press     → LCAG(ANVIL_MAP_02) → ADB_TALKBACK_SCRIPT
 * C*   decrease  → (encoder 1, CCW) ADB_TB_VOLD_SCRIPT
 * C*   increase  → (encoder 1, CW)  ADB_TB_VOLU_SCRIPT
 * D*   press     → LCAG(ANVIL_MAP_03) → (maps to ADB_TB_NEXT host combo)
 * D*   decrease  → (encoder 2, CCW) (unassigned)
 * D*   increase  → (encoder 2, CW)  (unassigned)
 * E#   press     → LCAG(ANVIL_MAP_04) → ADB_TB_PREV_SCRIPT
 * F#   press     → LCAG(ANVIL_MAP_05) → ADB_TB_VOLU_SCRIPT
 * G#   press     → SCRIPTS_HOVER (LT(LAYER_HOVER, LCAG(ANVIL_MAP_06))) → ADB_TB_MUTE_SCRIPT
 * H    → LCAG(ANVIL_MAP_07) → ADB_TB_VOLD_SCRIPT
 * I    → LCAG(ANVIL_MAP_08) → ADB_TB_HEADP_SCRIPT
 * J    → LCAG(ANVIL_MAP_09) → ADB_TB_HEADN_SCRIPT
 * K    → LCAG(ANVIL_MAP_10) → ADB_HOME_SCRIPT
 * L    → LCAG(ANVIL_MAP_11) → ADB_BACK_SCRIPT
 * M    → LCAG(ANVIL_MAP_12) → ADB_POWER_SCRIPT
 * N    → LCAG(ANVIL_MAP_13) → ADB_TB_FOCUS_SCRIPT
 * O    → LCAG(ANVIL_MAP_14) → ADB_TB_CURTAIN_SCRIPT
 * P    → LCAG(ANVIL_MAP_15) → ADB_TB_CLICK_SCRIPT
 * Q    → LCAG(ANVIL_MAP_16) → ADB_RECORD_OFF_SCRIPT
 * R    → LCAG(ANVIL_MAP_17) → ADB_RECORD_ON_SCRIPT
 * S    → LCAG(ANVIL_MAP_18)
 * T    → LCAG(ANVIL_MAP_19)
 * U    → LCAG(ANVIL_MAP_20)
 * V    → LCAG(ANVIL_MAP_21)
 * W    → LCAG(ANVIL_MAP_22)
 * X    → LCAG(ANVIL_MAP_23)
 * Y    → LCAG(ANVIL_MAP_24)
 * Z    → LCAG(ANVIL_MAP_25)
 * 1    → LCAG(ANVIL_MAP_26)
 * 2    → LCAG(ANVIL_MAP_27)
 * 3    → LCAG(ANVIL_MAP_28)
 * 4    → LCAG(ANVIL_MAP_29)
 * 5    → LCAG(ANVIL_MAP_30)
 * 6    → LCAG(ANVIL_MAP_31)
 */

#define SCRIPTS_LYR           TO(LAYER_DEMO)
#define SCRIPTS_ENC_B_PRESS   LCAG(ANVIL_MAP_01)
#define SCRIPTS_ENC_C_PRESS   LCAG(ANVIL_MAP_02)
#define SCRIPTS_ENC_D_PRESS   LCAG(ANVIL_MAP_03)
#define SCRIPTS_HOVER         LT(LAYER_HOVER, LCAG(ANVIL_MAP_06))

#define SCRIPTS_E LCAG(ANVIL_MAP_04)
#define SCRIPTS_F LCAG(ANVIL_MAP_05)
#define SCRIPTS_G SCRIPTS_HOVER
#define SCRIPTS_H LCAG(ANVIL_MAP_07)
#define SCRIPTS_I LCAG(ANVIL_MAP_08)
#define SCRIPTS_J LCAG(ANVIL_MAP_09)
#define SCRIPTS_K LCAG(ANVIL_MAP_10)
#define SCRIPTS_L LCAG(ANVIL_MAP_11)
#define SCRIPTS_M LCAG(ANVIL_MAP_12)
#define SCRIPTS_N LCAG(ANVIL_MAP_13)
#define SCRIPTS_O LCAG(ANVIL_MAP_14)
#define SCRIPTS_P LCAG(ANVIL_MAP_15)
#define SCRIPTS_Q LCAG(ANVIL_MAP_16)
#define SCRIPTS_R LCAG(ANVIL_MAP_17)
#define SCRIPTS_S LCAG(ANVIL_MAP_18)
#define SCRIPTS_T LCAG(ANVIL_MAP_19)
#define SCRIPTS_U LCAG(ANVIL_MAP_20)
#define SCRIPTS_V LCAG(ANVIL_MAP_21)
#define SCRIPTS_W LCAG(ANVIL_MAP_22)
#define SCRIPTS_X LCAG(ANVIL_MAP_23)
#define SCRIPTS_Y LCAG(ANVIL_MAP_24)
#define SCRIPTS_Z LCAG(ANVIL_MAP_25)
#define SCRIPTS_1 LCAG(ANVIL_MAP_26)
#define SCRIPTS_2 LCAG(ANVIL_MAP_27)
#define SCRIPTS_3 LCAG(ANVIL_MAP_28)
#define SCRIPTS_4 LCAG(ANVIL_MAP_29)
#define SCRIPTS_5 LCAG(ANVIL_MAP_30)
#define SCRIPTS_6 LCAG(ANVIL_MAP_31)
