#pragma once

#include "layers.h"

/*
 * Hover layer (LAYER_HOVER)
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
 * LYR  — (not assigned; hold another layer's G# to reach hover)
 * B*   press     → (unassigned)
 * B*   decrease  → (encoder 0, CCW) (unassigned)
 * B*   increase  → (encoder 0, CW)  (unassigned)
 * C*   press     → (unassigned)
 * C*   decrease  → (encoder 1, CCW) (unassigned)
 * C*   increase  → (encoder 1, CW)  (unassigned)
 * D*   press     → (unassigned)
 * D*   decrease  → (encoder 2, CCW) (unassigned)
 * D*   increase  → (encoder 2, CW)  (unassigned)
 * E#   press     → (unassigned)
 * F#   press     → (unassigned)
 * G#   press     → (unassigned)
 * H    → (unassigned)
 * I    → (unassigned)
 * J    → (unassigned)
 * K    → (unassigned)
 * L    → (unassigned)
 * M    → (unassigned)
 * N    → (unassigned)
 * O    → (unassigned)
 * P    → (unassigned)
 * Q    → (unassigned)
 * R    → (unassigned)
 * S    → (unassigned)
 * T    → (unassigned)
 * U    → (unassigned)
 * V    → (unassigned)
 * W    → (unassigned)
 * X    → (unassigned)
 * Y    → (unassigned)
 * Z    → (unassigned)
 * 1    → RGB_TOG
 * 2    → (unassigned)
 * 3    → (unassigned)
 * 4    → (unassigned)
 * 5    → SCREEN_ON
 * 6    → SCREEN_OFF
 */

#define HOVER_1 RGB_TOG
#define HOVER_5 SCREEN_ON
#define HOVER_6 SCREEN_OFF
