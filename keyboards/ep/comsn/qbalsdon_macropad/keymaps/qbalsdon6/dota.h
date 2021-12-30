#ifndef __dota_h
#define __dota_h

// https://github.com/arduino/Arduino/wiki/1.6-Frequently-Asked-Questions#errors-related-to-avr-progmem-changes

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

#define DOTA_ITEM_MAX_INDEX 8

#define ARCANE_BOOTS "Arcane Boots"
#define QUELLING_BLADE "Quelling Blade"
#define AGHANIMS_SCEPTER "Aghanim's Scepter"
#define REFRESHER_ORB "Refresher Orb"
#define OCTARINE_CORE "Octarine Core"
#define BLACK_KING_BAR "Black King Bar"
#define KAYA_AND_SANGE "Kaya and Sange"
#define LINKENS_SPHERE "Linken's Sphere"
#define SCYTHE_OF_VYSE "Scythe of Vyse"

uint16_t dotaItemIndex = 0;
//const char * const dota_items[] PROGMEM = {
const char* dota_items[]= {
  "Arcane Boots",
  "Quelling Blade",
  "Aghanim's Scepter",
  "Refresher Orb",
  "Octarine Core",
  "Black King Bar",
  "Kaya and Sange",
  "Linken's Sphere",
  "Scythe of Vyse"
};

void dota_item_increase(void) {
    if (dotaItemIndex < DOTA_ITEM_MAX_INDEX) {
        dotaItemIndex = dotaItemIndex + 1;
    } else {
        dotaItemIndex = 0;
    }
}

void dota_item_decrease(void) {
    if (dotaItemIndex == 0) {
        dotaItemIndex = DOTA_ITEM_MAX_INDEX;
    } else {
        dotaItemIndex = dotaItemIndex - 1;
    }
}

#endif
