#ifndef __keymacros_h
#define __keymacros_h

#define LAYER_ANDROID 2
#define LAYER_SCRIPTS 3
#define LAYER_DEMO 4
#define LAYER_DOTA 0
#define LAYER_RASPBERRY 1
#define LAYER_HOVER 5

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

enum custom_keycodes {
    DOTA_TYPE_ITEM = SAFE_RANGE,
    DOTA_ITEM_RESET,
    DEMO_01,
    DEMO_02,
    DEMO_03,
    DEMO_04,
    DEMO_05,
    DEMO_06,
    DEMO_07,
    DEMO_08,
    DEMO_09,
    DEMO_10,
    DEMO_11,
    DEMO_12,
    DEMO_13,
    DEMO_14,
    DEMO_15,
    DEMO_16,
    DEMO_17,
    DEMO_18,
    DEMO_19,
    DEMO_20,
    DEMO_21,
    DEMO_22,
    DEMO_23,
    DEMO_24,
    DEMO_25,
    DEMO_26,
    DEMO_27,
    DEMO_28,
    DEMO_29,
    DEMO_30,
    DEMO_31,
    DEMO_32,
    DEMO_33,
    DEMO_34,
    DEMO_35,
    DEMO_36,
    DEMO_37,
    DEMO_38,
    DEMO_39,
    RASPBERRY_01,
    RASPBERRY_02,
    RASPBERRY_03,
    RASPBERRY_04,
    RASPBERRY_05,
    RASPBERRY_06,
    RASPBERRY_07,
    RASPBERRY_08,
    RASPBERRY_09,
    RASPBERRY_10,
    RASPBERRY_11,
    RASPBERRY_12,
    RASPBERRY_13,
    RASPBERRY_14,
    RASPBERRY_15,
    RASPBERRY_16,
    RASPBERRY_17,
    RASPBERRY_18,
    RASPBERRY_19,
    RASPBERRY_20,
    RASPBERRY_21,
    RASPBERRY_22,
    RASPBERRY_23,
    RASPBERRY_24,
    RASPBERRY_25,
    RASPBERRY_26,
    RASPBERRY_27,
    RASPBERRY_28,
    RASPBERRY_29,
    RASPBERRY_30,
    RASPBERRY_31,
    RASPBERRY_32,
    RASPBERRY_33,
    RASPBERRY_34,
    RASPBERRY_35,
    RASPBERRY_36,
    RASPBERRY_37,
    RASPBERRY_38,
    RASPBERRY_39,
};

#endif
