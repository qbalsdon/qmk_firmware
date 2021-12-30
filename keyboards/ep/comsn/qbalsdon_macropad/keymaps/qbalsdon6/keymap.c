/* Copyright 2021 Quintin Balsdon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include <string.h>

#include "images.h"
#include "keymacros.h"
#include "dota.h"

#define LAYER_ANDROID 0
#define LAYER_ALT 1
#define LAYER_DOTA 2
#define LAYER_HOVER 3

#define ANDROID_HOVER  LT(LAYER_HOVER, HYPR(ANVIL_MAP_06))
#define ALT_HOVER      LT(LAYER_HOVER, LCAG(ANVIL_MAP_06))
#define DOTA_HOVER     LT(LAYER_HOVER, DOTA_STORE)

#define ENCODER_1 0
#define ENCODER_2 1
#define ENCODER_3 2

enum custom_keycodes {
    DOTA_TYPE_ITEM = SAFE_RANGE,
    SCREEN_OFF,
    SCREEN_ON,
    //OTHERS HERE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    // ANDROID MAP
    [LAYER_ANDROID] = LAYOUT(
                               TO(LAYER_ALT)  , HYPR(ANVIL_MAP_01), HYPR(ANVIL_MAP_02), HYPR(ANVIL_MAP_03),
                                                HYPR(ANVIL_MAP_04), HYPR(ANVIL_MAP_05), ANDROID_HOVER,
        HYPR(ANVIL_MAP_07), HYPR(ANVIL_MAP_08), HYPR(ANVIL_MAP_09), HYPR(ANVIL_MAP_10), HYPR(ANVIL_MAP_11),
        HYPR(ANVIL_MAP_12), HYPR(ANVIL_MAP_13), HYPR(ANVIL_MAP_14), HYPR(ANVIL_MAP_15), HYPR(ANVIL_MAP_16),
        HYPR(ANVIL_MAP_17), HYPR(ANVIL_MAP_18), HYPR(ANVIL_MAP_19), HYPR(ANVIL_MAP_20), HYPR(ANVIL_MAP_21),
        HYPR(ANVIL_MAP_22), HYPR(ANVIL_MAP_23), HYPR(ANVIL_MAP_24), HYPR(ANVIL_MAP_25), HYPR(ANVIL_MAP_26),
        HYPR(ANVIL_MAP_27), HYPR(ANVIL_MAP_28), HYPR(ANVIL_MAP_29), HYPR(ANVIL_MAP_30), HYPR(ANVIL_MAP_31)
    ),
    // SECONDARY LAYER MAP
    [LAYER_ALT] = LAYOUT(
                               TO(LAYER_DOTA),  LCAG(ANVIL_MAP_01), LCAG(ANVIL_MAP_02), LCAG(ANVIL_MAP_03),
                                                LCAG(ANVIL_MAP_04), LCAG(ANVIL_MAP_05), ALT_HOVER,
        LCAG(ANVIL_MAP_07), LCAG(ANVIL_MAP_08), LCAG(ANVIL_MAP_09), LCAG(ANVIL_MAP_10), LCAG(ANVIL_MAP_11),
        LCAG(ANVIL_MAP_12), LCAG(ANVIL_MAP_13), LCAG(ANVIL_MAP_14), LCAG(ANVIL_MAP_15), LCAG(ANVIL_MAP_16),
        LCAG(ANVIL_MAP_17), LCAG(ANVIL_MAP_18), LCAG(ANVIL_MAP_19), LCAG(ANVIL_MAP_20), LCAG(ANVIL_MAP_21),
        LCAG(ANVIL_MAP_22), LCAG(ANVIL_MAP_23), LCAG(ANVIL_MAP_24), LCAG(ANVIL_MAP_25), LCAG(ANVIL_MAP_26),
        LCAG(ANVIL_MAP_27), LCAG(ANVIL_MAP_28), LCAG(ANVIL_MAP_29), LCAG(ANVIL_MAP_30), LCAG(ANVIL_MAP_31)
    ),
    // DOTA LAYER MAP
    [LAYER_DOTA] = LAYOUT(
                            TO(LAYER_ANDROID), KC__MUTE           , DOTA_PAUSE        , DOTA_TYPE_ITEM    ,
                                               DOTA_FOCUS_UNITS   , DOTA_FOCUS_HERO   , DOTA_HOVER        ,
        DOTA_SPELL1       , DOTA_SPELL2      , DOTA_SPELL3        , KC_NO             , DOTA_ULTIMATE     ,
        DOTA_ITEM_01      , DOTA_ITEM_02     , DOTA_ITEM_03       , DOTA_CHATWHEEL    , DOTA_TP           ,
        DOTA_ITEM_04      , DOTA_ITEM_05     , DOTA_ITEM_06       , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , DOTA_SHIFT        , DOTA_DENY
    ),
    // HOVER LAYER MAP
    [LAYER_HOVER] = LAYOUT(
                            KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
                                               KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , KC_NO              , KC_NO             , KC_NO             ,
        KC_NO             , KC_NO            , SCREEN_ON          , SCREEN_OFF        , RGB_TOG
    ),
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

void update_element(void) {
    switch (dotaItemIndex) {
        case 0:
            oled_write_ln_P(PSTR(ARCANE_BOOTS), false);
        break;
        case 1:
            oled_write_ln_P(PSTR(QUELLING_BLADE), false);
        break;
        case 2:
            oled_write_ln_P(PSTR(AGHANIMS_SCEPTER), false);
        break;
        case 3:
            oled_write_ln_P(PSTR(REFRESHER_ORB), false);
        break;
        case 4:
            oled_write_ln_P(PSTR(OCTARINE_CORE), false);
        break;
        case 5:
            oled_write_ln_P(PSTR(BLACK_KING_BAR), false);
        break;
        case 6:
            oled_write_ln_P(PSTR(KAYA_AND_SANGE), false);
        break;
        case 7:
            oled_write_ln_P(PSTR(LINKENS_SPHERE), false);
        break;
        case 8:
            oled_write_ln_P(PSTR(SCYTHE_OF_VYSE), false);
        break;
  }
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case LAYER_ANDROID:
            oled_write_ln_P(PSTR("Android\n"), false);
            break;
        case LAYER_ALT:
            oled_write_ln_P(PSTR("Alternate\n"), false);
            break;
        case LAYER_DOTA:
            oled_write_ln_P(PSTR("DotA\n"), false);
            oled_write_ln_P(PSTR("  Current Item: \n"), false);
            update_element();
            break;
        case LAYER_HOVER:
            oled_write_ln_P(PSTR("Keeb\n"), false);
            break;
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    const char* logo_data = android_logo;
    uint8_t current_layer = biton32(layer_state);
    switch (current_layer) {
        case LAYER_ANDROID:
            logo_data = android_logo;
            break;
        case LAYER_ALT:
            logo_data = tiger_logo;
            break;
        case LAYER_DOTA:
            logo_data = dota_logo;
            break;
    }
    oled_write_raw_P(logo_data, sizeof(logo_data));
}
#endif // OLED_ENABLE

void oled_refresh(void) {
    #ifdef OLED_ENABLE
    oled_clear();
    // oled_render_logo();
    oled_render_layer_state();
    #endif
}

void oled_display_non_functional(void) {
    #ifdef OLED_ENABLE
    oled_clear();
    oled_write_P(PSTR("~~ Power Off ~~\n"), false);
    #endif
}

void oled_turn_screen_off(void) {
    #ifdef OLED_ENABLE
    oled_off();
    #endif
}

void oled_turn_screen_on(void) {
    #ifdef OLED_ENABLE
    oled_on();
    #endif
}

void encoder_map_dota(uint8_t key_code) {
    switch(key_code) {
        case ANVIL_MAP_32: // encoder 1 clockwise
        break;
        case ANVIL_MAP_33: // encoder 1 anti clockwise
        break;
        case ANVIL_MAP_34: // encoder 2 clockwise
        break;
        case ANVIL_MAP_35: // encoder 2 anti clockwise
        break;
        case ANVIL_MAP_36: // encoder 3 clockwise
            dota_item_increase();
        break;
        case ANVIL_MAP_37: // encoder 3 anti clockwise
            dota_item_decrease();
        break;
    }
}

void perform_encoder_action_with_code(uint8_t key_code) {
    uint8_t current_layer = biton32(layer_state);
    switch (current_layer) {
        case LAYER_ANDROID:
            tap_code16(HYPR(key_code));
            break;
        case LAYER_ALT:
            tap_code16(LCAG(key_code));
            break;
        case LAYER_DOTA:
            encoder_map_dota(key_code);
            break;
    }
}

bool encoder_update_user(uint8_t encoder_index, bool clockwise) {
    uint8_t key_code = ANVIL_MAP_32;
    switch(encoder_index) {
        case ENCODER_1:
            if (!clockwise) {
                key_code = ANVIL_MAP_33;
            }
            perform_encoder_action_with_code(key_code);
            break;
        case ENCODER_2:
            key_code = ANVIL_MAP_34;
            if (!clockwise) {
                key_code = ANVIL_MAP_35;
            }
            perform_encoder_action_with_code(key_code);
            break;
        case ENCODER_3:
            key_code = ANVIL_MAP_36;
            if (!clockwise) {
                key_code = ANVIL_MAP_37;
            }
            perform_encoder_action_with_code(key_code);
            break;
        }
        oled_refresh();
    return true;
}

// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 1, HSV_RED}       // Light 1 LEDs, starting with LED 6
// );
const rgblight_segment_t PROGMEM anvil_layer_layer_caps[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_BLUE},
    {12, 1, HSV_BLUE}, // these 2 are the underglow
    {9, 1, HSV_BLUE}, // C
    {10, 1, HSV_BLUE}, // B
    {11, 1, HSV_BLUE} // A
);
const rgblight_segment_t PROGMEM anvil_layer_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_GREEN},
    {12, 1, HSV_GREEN}, // these 2 are the underglow
    {9, 1, HSV_BLUE}, // C
    {10, 1, HSV_RED}, // B
    {11, 1, HSV_YELLOW} // A
);
const rgblight_segment_t PROGMEM anvil_layer_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_YELLOW},
    {12, 1, HSV_YELLOW}, // these 2 are the underglow
    {9, 1, HSV_GREEN}, // C
    {10, 1, HSV_GOLDENROD}, // B
    {11, 1, HSV_TEAL} // A
);
const rgblight_segment_t PROGMEM anvil_layer_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_RED},
    {12, 1, HSV_RED}, // these 2 are the underglow
    {9, 1, HSV_AZURE}, // C
    {10, 1, HSV_GOLDENROD}, // B
    {11, 1, HSV_TEAL} // A
);
const rgblight_segment_t PROGMEM anvil_layer_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_WHITE},
    {12, 1, HSV_WHITE}, // these 2 are the underglow
    {9, 1, HSV_WHITE}, // C
    {10, 1, HSV_WHITE}, // B
    {11, 1, HSV_WHITE} // A
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM anvil_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    anvil_layer_layer_caps,
    anvil_layer_layer0,
    anvil_layer_layer1,
    anvil_layer_layer2,
    anvil_layer_layer3
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = anvil_rgb_layers;
}

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_refresh();
    rgblight_set_layer_state(1,  layer_state_cmp(state, 0));
    rgblight_set_layer_state(2,  layer_state_cmp(state, 1));
    rgblight_set_layer_state(3,  layer_state_cmp(state, 2));
    rgblight_set_layer_state(4,  layer_state_cmp(state, 3));
    // rgblight_set_layer_state(2, layer_state_cmp(state, 1));
    // rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    // rgblight_set_layer_state(4, layer_state_cmp(state, 3));
    // rgblight_set_layer_state(5, layer_state_cmp(state, 4));
    // rgblight_set_layer_state(6, layer_state_cmp(state, 5));Arcane BootsArcane BootsArcane Boots
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    oled_refresh();
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case DOTA_TYPE_ITEM:
            //tap_code16(LGUI(KC_A));
            send_string(dota_items[dotaItemIndex]);
        break;
        case SCREEN_OFF:
            oled_turn_screen_off();
        break;
        case SCREEN_ON:
            oled_turn_screen_on();
        break;
    }
    return true;
};

void suspend_wakeup_init_user(void) {
    oled_refresh();
}

void suspend_power_down_user(void) {
    oled_display_non_functional();
}
