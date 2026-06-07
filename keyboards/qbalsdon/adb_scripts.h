#pragma once

// Scripts layer: shell/adb command strings (typically sent on LCAG key press).

#define ADB_UNLOCK_SCRIPT     "sh unlockWithSwipe -p 314159"
#define ADB_TALKBACK_SCRIPT   "sh talkback"
#define ADB_TB_NEXT_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_SWIPE_RIGHT\""
#define ADB_TB_PREV_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_SWIPE_LEFT\""
#define ADB_TB_VOLU_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_UP\""
#define ADB_TB_VOLD_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_DOWN\""
#define ADB_TB_MUTE_SCRIPT    "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_VOLUME_MUTE\""
#define ADB_TB_HEADP_SCRIPT   "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_FOCUS_ELEMENT\" -e PARAMETER_HEADING \"DIRECTION_BACK\""
#define ADB_TB_HEADN_SCRIPT   "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_FOCUS_ELEMENT\" -e PARAMETER_HEADING \"DIRECTION_FORWARD\""
#define ADB_HOME_SCRIPT       "adb shell input keyevent KEYCODE_HOME"
#define ADB_BACK_SCRIPT       "adb shell input keyevent KEYCODE_BACK"
#define ADB_POWER_SCRIPT      "adb shell input keyevent KEYCODE_POWER"
#define ADB_TB_FOCUS_SCRIPT   "adb shell am broadcast -a com.balsdon.talkback.accessibility -e PARAMETER_ID \"swipeRight\""
#define ADB_TB_CURTAIN_SCRIPT "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_CURTAIN\""
#define ADB_TB_CLICK_SCRIPT   "adb shell am broadcast -a com.balsdon.talkback.accessibility -e ACTION \"ACTION_CLICK\""
#define ADB_RECORD_OFF_SCRIPT "sh recordOff"
#define ADB_RECORD_ON_SCRIPT  "sh recordOn"
#define ADB_FLIP_SCRIPT       "sh flip"
#define ADB_ANIMATION_SCRIPT  "sh animation"
