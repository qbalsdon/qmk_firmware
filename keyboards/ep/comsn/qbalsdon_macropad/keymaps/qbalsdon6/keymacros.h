#ifndef __keymacros_h
#define __keymacros_h
//https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes
#define ANVIL_MAP_01 KC_F1
#define ANVIL_MAP_02 KC_F2
#define ANVIL_MAP_03 KC_F3
#define ANVIL_MAP_04 KC_F4
#define ANVIL_MAP_05 KC_F5
#define ANVIL_MAP_06 KC_F6
#define ANVIL_MAP_07 KC_F7
#define ANVIL_MAP_08 KC_F8
#define ANVIL_MAP_09 KC_F9
#define ANVIL_MAP_10 KC_F10
#define ANVIL_MAP_11 KC_F11
#define ANVIL_MAP_12 KC_F12
#define ANVIL_MAP_13 KC_F13
#define ANVIL_MAP_14 KC_F14
#define ANVIL_MAP_15 KC_F15
#define ANVIL_MAP_16 KC_F16
#define ANVIL_MAP_17 KC_F17
#define ANVIL_MAP_18 KC_F18
#define ANVIL_MAP_19 KC_F19
#define ANVIL_MAP_20 KC_UP
#define ANVIL_MAP_21 KC_DOWN
#define ANVIL_MAP_22 KC_LEFT
#define ANVIL_MAP_23 KC_RIGHT
#define ANVIL_MAP_24 KC_KP_ASTERISK
#define ANVIL_MAP_25 KC_KP_MINUS
#define ANVIL_MAP_26 KC_KP_PLUS
#define ANVIL_MAP_27 KC_EQL
#define ANVIL_MAP_28 KC_SPC
#define ANVIL_MAP_29 KC_NUHS
#define ANVIL_MAP_30 KC_1
#define ANVIL_MAP_31 KC_2
#define ANVIL_MAP_32 KC_3
#define ANVIL_MAP_33 KC_4
#define ANVIL_MAP_34 KC_5
#define ANVIL_MAP_35 KC_6
#define ANVIL_MAP_36 KC_7
#define ANVIL_MAP_37 KC_8
#define ANVIL_MAP_38 KC_9
#define ANVIL_MAP_39 KC_0

#define ADB_UNLOCK        HYPR(KC_F1)
#define ADB_TALKBACK      HYPR(KC_F2)
#define ADB_TB_NEXT       HYPR(KC_F3)
#define ADB_TB_PREV       HYPR(KC_F4)
#define ADB_TB_VOLU       HYPR(KC_F5)
#define ADB_TB_VOLD       HYPR(KC_F6)
#define ADB_TB_MUTE       HYPR(KC_F7)
#define ADB_TB_HEADP      HYPR(KC_F8)
#define ADB_TB_HEADN      HYPR(KC_F9)
#define ADB_HOME          HYPR(KC_F10)
#define ADB_BACK          HYPR(KC_F11)
#define ADB_POWER         HYPR(KC_F12)
#define ADB_TB_FOCUS      HYPR(KC_F13)
#define ADB_TB_CURTAIN    HYPR(KC_F14)
#define ADB_TB_CLICK      HYPR(KC_F15)
#define ADB_RECORD_OFF    HYPR(KC_F16)
#define ADB_RECORD_ON     HYPR(KC_F17)

//DOTA KEY MAPPING
#define DOTA_SPELL1       KC_Q
#define DOTA_SPELL2       KC_W
#define DOTA_SPELL3       KC_E
#define DOTA_ULTIMATE     KC_R
#define DOTA_TP           KC_T
#define DOTA_FOCUS_HERO   KC_F1
#define DOTA_FOCUS_UNITS  KC_F2
#define DOTA_ITEM_01      KC_1
#define DOTA_ITEM_02      KC_2
#define DOTA_ITEM_03      KC_3
#define DOTA_ITEM_04      KC_4
#define DOTA_ITEM_05      KC_5
#define DOTA_ITEM_06      KC_6
#define DOTA_SHIFT        KC_LSHIFT
#define DOTA_DENY         KC_A
#define DOTA_PAUSE        KC_F9
#define DOTA_STORE        KC_F4
#define DOTA_CHATWHEEL    KC_Y

#define ADB_UNLOCK_SCRIPT        "sh unlockWithSwipe -p 314159"
#define ADB_TALKBACK_SCRIPT      "sh talkback"
#define ADB_TB_NEXT_SCRIPT       "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_SWIPE_RIGHT\""
#define ADB_TB_PREV_SCRIPT       "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_SWIPE_LEFT\""
#define ADB_TB_VOLU_SCRIPT       "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_UP\""
#define ADB_TB_VOLD_SCRIPT       "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_DOWN\""
#define ADB_TB_MUTE_SCRIPT       "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_MUTE\""
#define ADB_TB_HEADP_SCRIPT      "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_FOCUS_ELEMENT\" -e PARAMETER_HEADING \"DIRECTION_BACK\""
#define ADB_TB_HEADN_SCRIPT      "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_FOCUS_ELEMENT\" -e PARAMETER_HEADING \"DIRECTION_FORWARD\""
#define ADB_HOME_SCRIPT          "adb shell input keyevent KEYCODE_HOME"
#define ADB_BACK_SCRIPT          "adb shell input keyevent KEYCODE_BACK"
#define ADB_POWER_SCRIPT         "adb shell input keyevent KEYCODE_POWER"
#define ADB_TB_FOCUS_SCRIPT      "adb shell am broadcast -a com.balsdon.talkback.accessibility -e PARAMETER_ID \"swipeRight\""
#define ADB_TB_CURTAIN_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_CURTAIN\""
#define ADB_TB_CLICK_SCRIPT      "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_CLICK\""
#define ADB_RECORD_OFF_SCRIPT    "sh recordOff"
#define ADB_RECORD_ON_SCRIPT     "sh recordOn"
#define ADB_FLIP_SCRIPT          "sh flip"
#define ADB_ANIMATION_SCRIPT     "sh animation"

#endif
