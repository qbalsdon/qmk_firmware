#ifndef __quintin_h
#define __quintin_h

//https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes#modifiers-id-modifiers
#define ADB_UNLOCK        HYPR(KC_3)
#define ADB_TALKBACK      HYPR(KC_6)
#define ADB_TB_NEXT       HYPR(KC_9)
#define ADB_TB_PREV       HYPR(KC_8)
#define ADB_TB_VOLU       HYPR(KC_F1)
#define ADB_TB_VOLD       HYPR(KC_F2)
#define ADB_TB_MUTE       HYPR(KC_F3)
#define ADB_TB_HEADP      HYPR(KC_F4)
#define ADB_TB_HEADN      HYPR(KC_F5)
#define ADB_HOME          HYPR(KC_F6)
#define ADB_BACK          HYPR(KC_F7)
#define ADB_POWER         HYPR(KC_F8)
#define ADB_TB_FOCUS      HYPR(KC_F9)
#define ADB_TB_CURTAIN    HYPR(KC_BSLASH)
#define ADB_TB_CLICK      HYPR(KC_QUOTE)
#define ADB_RECORD_OFF    HYPR(KC_M)
#define ADB_RECORD_ON     HYPR(KC_N)

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

//DOTA KEY MAPPING
#define DOTA_SPELL1       KC_Q
#define DOTA_SPELL2       KC_W
#define DOTA_SPELL3       KC_E
#define DOTA_ULTIMATE     KC_R
#define DOTA_FOCUS_HERO   KC_F1
#define DOTA_FOCUS_UNITS  KC_F2
#define DOTA_01           KC_1
#define DOTA_02           KC_2
#define DOTA_03           KC_3
#define DOTA_TP           KC_T
#define DOTA_04           KC_4
#define DOTA_05           KC_5
#define DOTA_06           KC_6
#define DOTA_SHIFT        KC_LSHIFT
#define DOTA_DENY         KC_A
#define DOTA_PAUSE        KC_F9
#define DOTA_STORE        KC_F4
#define DOTA_CHATWHEEL    KC_Y

#define LAYER_COUNT 3
enum layers {
  LAYER_ADB,
  LAYER_ADB_SCRIPT,
  LAYER_DOTA,
  LAYER_HOVER //NOT COUNTED! This is a functional helper
};

enum qjb_keycodes {
  LAYER_CYCLE = SAFE_RANGE,
  ADB_SCRNREC, //special behaviour
  DOTA_TYPE_ITEM,
  DOTA_ITEM_RESET,
  DOTA_BRIAN,
  ADB_UNLOCK_S,
  ADB_TALKBACK_S,
  ADB_TB_NEXT_S,
  ADB_TB_PREV_S,
  ADB_TB_VOLU_S,
  ADB_TB_VOLD_S,
  ADB_TB_MUTE_S,
  ADB_TB_HEADP_S,
  ADB_TB_HEADN_S,
  ADB_HOME_S,
  ADB_BACK_S,
  ADB_POWER_S,
  ADB_TB_FOCUS_S,
  ADB_TB_CURTAIN_S,
  ADB_TB_CLICK_S,
  ADB_SCRNREC_S,
  ADB_FLIP_S,
  ADB_ANIMATION_S,
};

#define DOTA_ITEM_COUNT 8

uint16_t dotaItemIndex = 0;
const char* dota_items[DOTA_ITEM_COUNT] = {
  "Arcane Boots",
  "Quelling Blade",
  "Aghanim's Scepter",
  "Refresher Orb",
  "Octarine Core",
  "Black King Bar",
  "Kaya and Sange",
  "Linken's Sphere"
};

#define DOTA_BRIAN_COUNT 3
uint16_t dotaBrianIndex = 0;
const char* dota_brian[DOTA_BRIAN_COUNT] = {
  "Both your dads are gay",
  "You play like your mom",
  "I have pickles and you don't - nah-nah nah-nah-nah nah",
};

bool phone_is_recording = false;
bool layer_changed_recently = false;
uint16_t layer_change_timer = 0;

#define ANIMATION_FRAMES 32
uint16_t animation_time = 0;
uint16_t animation_frame = 0;

#define COLOUR_LIST_COUNT 16
int colourReference = 0;
int flashIndex = -1;

uint16_t currentLayer(void) {
  for (int layer = 0; layer < LAYER_COUNT; layer++) {
    if (layer_state_is(layer)) return layer;
  }
  return 0;
}

void cycleLayer(void) {
  uint16_t nextLayer = (currentLayer() + 1) % LAYER_COUNT;
  layer_move(nextLayer);
  layer_changed_recently = true;
  layer_change_timer = timer_read();
}

//https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#super-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER_CYCLE:
      if (!record->event.pressed) { //only on release
        cycleLayer();
      } return false;
    case ADB_SCRNREC:
      if (!record->event.pressed) { //only on release
        if (phone_is_recording) {
          tap_code16(ADB_RECORD_OFF);
        } else {
          tap_code16(ADB_RECORD_ON);
        }
        phone_is_recording = !phone_is_recording;
      } return false;
    case DOTA_TYPE_ITEM:
      if (!record->event.pressed) { //only on release
        tap_code16(LGUI(KC_A));
        send_string(dota_items[dotaItemIndex]);
      } return false;
    case DOTA_ITEM_RESET:
      if (!record->event.pressed) { //only on release
        dotaItemIndex = 0;
      } return false;
    case DOTA_BRIAN:
      if (!record->event.pressed) { //only on release
        tap_code(KC_ENTER);
        send_string(dota_brian[dotaBrianIndex]);
        tap_code(KC_ENTER);
        dotaBrianIndex = (dotaBrianIndex + 1) % DOTA_BRIAN_COUNT;
      } return false;
    case ADB_UNLOCK_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_UNLOCK_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TALKBACK_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TALKBACK_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_NEXT_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_NEXT_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_PREV_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_PREV_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_VOLU_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_VOLU_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_VOLD_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_VOLD_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_MUTE_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_MUTE_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_HEADP_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_HEADP_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_HEADN_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_HEADN_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_HOME_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_HOME_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_BACK_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_BACK_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_POWER_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_POWER_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_FOCUS_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_FOCUS_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_CURTAIN_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_CURTAIN_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_TB_CLICK_S:
      if(!record->event.pressed){ //only on release
        send_string(ADB_TB_CLICK_SCRIPT);
        tap_code(KC_ENTER);
      } return false;
    case ADB_SCRNREC_S:
      if(!record->event.pressed){ //only on release
        if (phone_is_recording) {
          send_string(ADB_RECORD_OFF_SCRIPT);
        } else {
          send_string(ADB_RECORD_ON_SCRIPT);
        }
        tap_code(KC_ENTER);
        phone_is_recording = !phone_is_recording;
      } return false;
    default:
      return true; // ignore everything else
  }
}

void keyboard_post_init_user(void) {
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb(0,0,0);
}

uint16_t* getColourForIndex(int index)
{
  static uint16_t colour[3];

  switch (index % COLOUR_LIST_COUNT) {
    case 1:  colour[0] = 0xC2; colour[1] = 0x18; colour[2] = 0x5B; break;
    case 2:  colour[0] = 0x7B; colour[1] = 0x1F; colour[2] = 0xA2; break;
    case 3:  colour[0] = 0x51; colour[1] = 0x2D; colour[2] = 0xA8; break;
    case 4:  colour[0] = 0x30; colour[1] = 0x3F; colour[2] = 0x9F; break;
    case 5:  colour[0] = 0x19; colour[1] = 0x76; colour[2] = 0xD2; break;
    case 6:  colour[0] = 0x02; colour[1] = 0x88; colour[2] = 0xD1; break;
    case 7:  colour[0] = 0x00; colour[1] = 0x97; colour[2] = 0xA7; break;
    case 8:  colour[0] = 0x00; colour[1] = 0x79; colour[2] = 0x6B; break;
    case 9:  colour[0] = 0x38; colour[1] = 0x8E; colour[2] = 0x3C; break;
    case 10: colour[0] = 0x68; colour[1] = 0x9F; colour[2] = 0x38; break;
    case 11: colour[0] = 0xAF; colour[1] = 0xB4; colour[2] = 0x2B; break;
    case 12: colour[0] = 0xFB; colour[1] = 0xC0; colour[2] = 0x2D; break;
    case 13: colour[0] = 0xFF; colour[1] = 0xA0; colour[2] = 0x00; break;
    case 14: colour[0] = 0xF5; colour[1] = 0x7C; colour[2] = 0x00; break;
    case 15: colour[0] = 0xE6; colour[1] = 0x4A; colour[2] = 0x19; break;
    default: colour[0] = 0xd3; colour[1] = 0x2f; colour[2] = 0x2f;
  }
  return colour;
}

void updateAnimationFrame(void) {

  flashIndex = (flashIndex + 1) % RGBLED_NUM;
  if (flashIndex == 0) {
    colourReference = (colourReference + 1) % COLOUR_LIST_COUNT;
  }

  uint16_t layer = currentLayer();

  if (layer == LAYER_DOTA) {
    for (int i = 0; i < RGBLED_NUM; i++) {
      if (i <= dotaItemIndex) {
        rgblight_setrgb_at(255, 255, 255, i);
      } else {
        if (i >= flashIndex - 1 && i <= flashIndex + 1) {
          rgblight_setrgb_at(0, 0, 150, i);
        } else {
          rgblight_setrgb_at(255, 0, 0, i);
        }
      }
    }
  }
  else if (layer == LAYER_ADB_SCRIPT) {
    uint16_t* colour = getColourForIndex(animation_frame);
    for (int i = 0; i < RGBLED_NUM; i++) {
      rgblight_setrgb_at(colour[0], colour[1], colour[2], i);
    }
  } else {
    uint16_t* colour = getColourForIndex(colourReference);
    for (int i = 0; i < RGBLED_NUM; i++) {
      if (i >= flashIndex - 1 && i <= flashIndex + 1) {
        if (phone_is_recording){
          rgblight_setrgb_at(255, 0, 255, i);
        } else {
          rgblight_setrgb_at(0, 255, 0, i);
        }
      } else {
        rgblight_setrgb_at(colour[0], colour[1], colour[2], i);
      }
    }
  }
}

void matrix_scan_user(void) {
  if (layer_changed_recently) {
    if (timer_elapsed(layer_change_timer) > 500) {
      layer_changed_recently = false;
    }
  }

  if (timer_read() - animation_time > 50) {
    animation_time = timer_read();
    animation_frame = (animation_frame + 1) % ANIMATION_FRAMES;
    updateAnimationFrame();
  }
}
#endif
