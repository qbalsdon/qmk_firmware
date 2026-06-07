#pragma once

#include "anvil_map.h"

// Android layer: HYPR() shortcuts consumed by host-side ADB tooling.

#define ADB_UNLOCK     HYPR(ANVIL_MAP_01)
#define ADB_TALKBACK   HYPR(ANVIL_MAP_02)
#define ADB_TB_NEXT    HYPR(ANVIL_MAP_03)
#define ADB_TB_PREV    HYPR(ANVIL_MAP_04)
#define ADB_TB_VOLU    HYPR(ANVIL_MAP_05)
#define ADB_TB_MUTE    HYPR(ANVIL_MAP_06)
#define ADB_TB_VOLD    HYPR(ANVIL_MAP_07)
#define ADB_TB_HEADP   HYPR(ANVIL_MAP_08)
#define ADB_TB_HEADN   HYPR(ANVIL_MAP_09)
#define ADB_HOME       HYPR(ANVIL_MAP_10)
#define ADB_BACK       HYPR(ANVIL_MAP_11)
#define ADB_POWER      HYPR(ANVIL_MAP_12)
#define ADB_TB_FOCUS   HYPR(ANVIL_MAP_13)
#define ADB_TB_CURTAIN HYPR(ANVIL_MAP_14)
#define ADB_TB_CLICK   HYPR(ANVIL_MAP_15)
#define ADB_RECORD_OFF HYPR(ANVIL_MAP_16)
#define ADB_RECORD_ON  HYPR(ANVIL_MAP_17)
