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

#include "keymacros.h"

#define DEMO_PLAIN_COUNT 25
#define DEMO_PLAIN_IS(kc) ((kc) >= DEMO_H && (kc) <= DEMO_6)

typedef struct {
    char     label;
    uint16_t keycode;
} demo_key_t;

static const demo_key_t demo_plain_keys[DEMO_PLAIN_COUNT] = {
    {'H', KC_H}, {'I', KC_I}, {'J', KC_J}, {'K', KC_K}, {'L', KC_L},
    {'M', KC_M}, {'N', KC_N}, {'O', KC_O}, {'P', KC_P}, {'Q', KC_Q},
    {'R', KC_R}, {'S', KC_S}, {'T', KC_T}, {'U', KC_U}, {'V', KC_V},
    {'W', KC_W}, {'X', KC_X}, {'Y', KC_Y}, {'Z', KC_Z},
    {'1', KC_1}, {'2', KC_2}, {'3', KC_3}, {'4', KC_4}, {'5', KC_5}, {'6', KC_6},
};

static uint16_t demo_last_key  = 0;
static uint16_t demo_last_time = 0;
static uint8_t  demo_rgb_hue[3] = {0, 85, 170};

#define ANVIL_KEYMAP( \
    k01, k02, k03, k04, \
         k12, k13, k14, \
    k20, k21, k22, k23, k24, \
    k30, k31, k32, k33, k34, \
    k40, k41, k42, k43, k44, \
    k50, k51, k52, k53, k54, \
    k60, k61, k62, k63, k64 \
) \
LAYOUT( \
    k01, k02, k03, k04, \
         k12, k13, k14, \
    k20, k21, k22, k23, k24, \
    k30, k31, k32, k33, k34, \
    k40, k41, k42, k43, k44, \
    k50, k51, k52, k53, k54, \
    k60, k61, k62, k63, k64 \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_DEMO] = ANVIL_KEYMAP(
        ANVIL_LYR, DEMO_ENC_B, DEMO_ENC_C, DEMO_ENC_D,
                   DEMO_RGB_E, DEMO_RGB_F, DEMO_RGB_G,
        DEMO_H, DEMO_I, DEMO_J, DEMO_K, DEMO_L,
        DEMO_M, DEMO_N, DEMO_O, DEMO_P, DEMO_Q,
        DEMO_R, DEMO_S, DEMO_T, DEMO_U, DEMO_V,
        DEMO_W, DEMO_X, DEMO_Y, DEMO_Z, DEMO_1,
        DEMO_2, DEMO_3, DEMO_4, DEMO_5, DEMO_6
    ),
#if 0 // LAYER_DOTA (commented out)
    [LAYER_DOTA] = ANVIL_KEYMAP(
        ANVIL_LYR, DOTA_ENC_B_PRESS, DOTA_ENC_C_PRESS, DOTA_ENC_D_PRESS,
                   DOTA_RGB_E_PRESS, DOTA_RGB_F_PRESS, DOTA_HOVER,
        DOTA_H, DOTA_I, DOTA_J, DOTA_K, DOTA_L,
        DOTA_M, DOTA_N, DOTA_O, DOTA_P, DOTA_Q,
        DOTA_R, DOTA_S, DOTA_T, DOTA_U, DOTA_V,
        DOTA_W, DOTA_X, DOTA_Y, DOTA_Z, DOTA_1,
        DOTA_2, DOTA_3, DOTA_4, DOTA_5, DOTA_6
    ),
#endif
    [LAYER_RASPBERRY] = ANVIL_KEYMAP(
        ANVIL_LYR, RASPBERRY_ENC_B_PRESS, RASPBERRY_ENC_C_PRESS, RASPBERRY_ENC_D_PRESS,
                   RASPBERRY_E, RASPBERRY_F, RASPBERRY_HOVER,
        RASPBERRY_H, RASPBERRY_I, RASPBERRY_J, RASPBERRY_K, RASPBERRY_L,
        RASPBERRY_M, RASPBERRY_N, RASPBERRY_O, RASPBERRY_P, RASPBERRY_Q,
        RASPBERRY_R, RASPBERRY_S, RASPBERRY_T, RASPBERRY_U, RASPBERRY_V,
        RASPBERRY_W, RASPBERRY_X, RASPBERRY_Y, RASPBERRY_Z, RASPBERRY_1,
        RASPBERRY_2, RASPBERRY_3, RASPBERRY_4, RASPBERRY_5, RASPBERRY_6
    ),
    [LAYER_ANDROID] = ANVIL_KEYMAP(
        ANVIL_LYR, ANDROID_ENC_B_PRESS, ANDROID_ENC_C_PRESS, ANDROID_ENC_D_PRESS,
                   ANDROID_E, ANDROID_F, ANDROID_HOVER,
        ANDROID_H, ANDROID_I, ANDROID_J, ANDROID_K, ANDROID_L,
        ANDROID_M, ANDROID_N, ANDROID_O, ANDROID_P, ANDROID_Q,
        ANDROID_R, ANDROID_S, ANDROID_T, ANDROID_U, ANDROID_V,
        ANDROID_W, ANDROID_X, ANDROID_Y, ANDROID_Z, ANDROID_1,
        ANDROID_2, ANDROID_3, ANDROID_4, ANDROID_5, ANDROID_6
    ),
    [LAYER_SCRIPTS] = ANVIL_KEYMAP(
        ANVIL_LYR, SCRIPTS_ENC_B_PRESS, SCRIPTS_ENC_C_PRESS, SCRIPTS_ENC_D_PRESS,
                   SCRIPTS_E, SCRIPTS_F, SCRIPTS_HOVER,
        SCRIPTS_H, SCRIPTS_I, SCRIPTS_J, SCRIPTS_K, SCRIPTS_L,
        SCRIPTS_M, SCRIPTS_N, SCRIPTS_O, SCRIPTS_P, SCRIPTS_Q,
        SCRIPTS_R, SCRIPTS_S, SCRIPTS_T, SCRIPTS_U, SCRIPTS_V,
        SCRIPTS_W, SCRIPTS_X, SCRIPTS_Y, SCRIPTS_Z, SCRIPTS_1,
        SCRIPTS_2, SCRIPTS_3, SCRIPTS_4, SCRIPTS_5, SCRIPTS_6
    ),
    [LAYER_HOVER] = ANVIL_KEYMAP(
        KC_NO, KC_NO, KC_NO, KC_NO,
               KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, HOVER_1,
        KC_NO, KC_NO, KC_NO, HOVER_5, HOVER_6
    ),
};

static void demo_rgb_apply(uint8_t rgb_index) {
    static const uint8_t led_indices[] = {DEMO_RGB_LED_E, DEMO_RGB_LED_F, DEMO_RGB_LED_G};
    rgblight_sethsv_at(demo_rgb_hue[rgb_index], 255, RGBLIGHT_LIMIT_VAL, led_indices[rgb_index]);
}

static void demo_rgb_cycle(uint8_t rgb_index) {
    demo_rgb_hue[rgb_index] = (demo_rgb_hue[rgb_index] + RGBLIGHT_HUE_STEP) % 256;
    demo_rgb_apply(rgb_index);
}

#ifdef OLED_ENABLE

static void oled_show_text_centered(const char *text) {
    uint8_t len = strlen(text);
    uint8_t col = len < 21 ? (21 - len) / 2 : 0;

    oled_clear();
    oled_set_cursor(col, 3);
    oled_write(text, false);
}

static void demo_oled_show_text(const char *text) {
    oled_show_text_centered(text);
}

static void demo_oled_show_char(char label) {
    char buf[2] = {label, '\0'};
    demo_oled_show_text(buf);
}

void oled_render_layer_state(uint8_t layer) {
    switch (layer) {
        case LAYER_DEMO:
            oled_show_text_centered("Demo");
            break;
#if 0 // LAYER_DOTA (commented out)
        case LAYER_DOTA:
            oled_show_text_centered("Dota");
            break;
#endif
        case LAYER_RASPBERRY:
            oled_show_text_centered("Pi");
            break;
        case LAYER_ANDROID:
            oled_show_text_centered("Android");
            break;
        case LAYER_SCRIPTS:
            oled_show_text_centered("Scripts");
            break;
        case LAYER_HOVER:
            oled_show_text_centered("Hover");
            break;
    }
}

void oled_refresh(void) {
    oled_render_layer_state(get_highest_layer(layer_state));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
#endif // OLED_ENABLE

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

static void encoder_update_android(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code16(clockwise ? ADB_TB_NEXT : ADB_TB_PREV);
    } else if (index == 1) {
        tap_code16(clockwise ? ADB_TB_VOLU : ADB_TB_VOLD);
    }
}

static void encoder_update_scripts(uint8_t index, bool clockwise) {
    if (index == 0) {
        send_string(clockwise ? ADB_TB_NEXT_SCRIPT : ADB_TB_PREV_SCRIPT);
        tap_code(KC_ENTER);
    } else if (index == 1) {
        send_string(clockwise ? ADB_TB_VOLU_SCRIPT : ADB_TB_VOLD_SCRIPT);
        tap_code(KC_ENTER);
    }
}

#if 0 // LAYER_DOTA (commented out)
static void encoder_update_dota(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            dota_item_increase();
        } else {
            dota_item_decrease();
        }
    }
}
#endif

static void encoder_update_demo(uint8_t index, bool clockwise) {
#ifdef OLED_ENABLE
    static const char encoder_labels[] = {'B', 'C', 'D'};
    if (index < 3) {
        char text[3];
        text[0] = encoder_labels[index];
        text[1] = clockwise ? '+' : '-';
        text[2] = '\0';
        demo_oled_show_text(text);
    }
#else
    (void)index;
    (void)clockwise;
#endif
}

bool encoder_update_user(uint8_t encoder_index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case LAYER_DEMO:
            encoder_update_demo(encoder_index, clockwise);
            break;
#if 0 // LAYER_DOTA (commented out)
        case LAYER_DOTA:
            encoder_update_dota(encoder_index, clockwise);
            break;
#endif
        case LAYER_ANDROID:
            encoder_update_android(encoder_index, clockwise);
            break;
        case LAYER_SCRIPTS:
            encoder_update_scripts(encoder_index, clockwise);
            break;
        default:
            break;
    }
    return true;
}

const rgblight_segment_t PROGMEM anvil_layer_demo[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_CYAN}, {12, 1, HSV_CYAN}, {9, 1, HSV_CYAN}, {10, 1, HSV_CYAN}, {11, 1, HSV_CYAN}
);
#if 0 // LAYER_DOTA (commented out)
const rgblight_segment_t PROGMEM anvil_layer_dota[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_RED}, {12, 1, HSV_RED}, {9, 1, HSV_RED}, {10, 1, HSV_RED}, {11, 1, HSV_RED}
);
#endif
const rgblight_segment_t PROGMEM anvil_layer_raspberry[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_GREEN}, {12, 1, HSV_GREEN}, {9, 1, HSV_GREEN}, {10, 1, HSV_GREEN}, {11, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM anvil_layer_android[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_WHITE}, {12, 1, HSV_WHITE}, {9, 1, HSV_BLUE}, {10, 1, HSV_RED}, {11, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM anvil_layer_scripts[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_YELLOW}, {12, 1, HSV_YELLOW}, {9, 1, HSV_GREEN}, {10, 1, HSV_GOLDENROD}, {11, 1, HSV_TEAL}
);
const rgblight_segment_t PROGMEM anvil_layer_hover[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_WHITE}, {12, 1, HSV_WHITE}, {9, 1, HSV_WHITE}, {10, 1, HSV_WHITE}, {11, 1, HSV_WHITE}
);

const rgblight_segment_t* const PROGMEM anvil_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    anvil_layer_demo,
    anvil_layer_raspberry,
    anvil_layer_android,
    anvil_layer_scripts,
    anvil_layer_hover
);

void keyboard_post_init_user(void) {
    rgblight_layers = anvil_rgb_layers;
    rgblight_set_layer_state(1, true);
    demo_rgb_apply(0);
    demo_rgb_apply(1);
    demo_rgb_apply(2);
#ifdef OLED_ENABLE
    oled_refresh();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LAYER_DEMO));
    rgblight_set_layer_state(2, layer_state_cmp(state, LAYER_RASPBERRY));
    rgblight_set_layer_state(3, layer_state_cmp(state, LAYER_ANDROID));
    rgblight_set_layer_state(4, layer_state_cmp(state, LAYER_SCRIPTS));
    rgblight_set_layer_state(5, layer_state_cmp(state, LAYER_HOVER));
#ifdef OLED_ENABLE
    oled_render_layer_state(get_highest_layer(state));
#endif
    return state;
}

static bool demo_handle_plain_key(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return false;
    }

    const demo_key_t *key = &demo_plain_keys[keycode - DEMO_H];
    uint16_t          now = timer_read();

    if (keycode == demo_last_key && TIMER_DIFF_16(now, demo_last_time) < GET_TAPPING_TERM(keycode, record)) {
        tap_code16(key->keycode);
        demo_last_key = 0;
    } else {
#ifdef OLED_ENABLE
        demo_oled_show_char(key->label);
#endif
        demo_last_key  = keycode;
        demo_last_time = now;
    }

    return false;
}

static bool demo_handle_rgb_key(uint16_t keycode, keyrecord_t *record, char label, uint8_t rgb_index) {
    if (!record->event.pressed) {
        return false;
    }

    uint16_t now = timer_read();

    if (keycode == demo_last_key && TIMER_DIFF_16(now, demo_last_time) < GET_TAPPING_TERM(keycode, record)) {
        demo_rgb_cycle(rgb_index);
        demo_last_key = 0;
    } else {
#ifdef OLED_ENABLE
        demo_oled_show_char(label);
#endif
        demo_last_key  = keycode;
        demo_last_time = now;
    }

    return false;
}

static bool process_demo_key(uint16_t keycode, keyrecord_t *record) {
    if (DEMO_PLAIN_IS(keycode)) {
        return demo_handle_plain_key(keycode, record);
    }

    if (!record->event.pressed) {
        switch (keycode) {
            case DEMO_ENC_B:
            case DEMO_ENC_C:
            case DEMO_ENC_D:
                return false;
            default:
                break;
        }
        return true;
    }

    switch (keycode) {
        case DEMO_ENC_B:
#ifdef OLED_ENABLE
            demo_oled_show_char('B');
#endif
            return false;
        case DEMO_ENC_C:
#ifdef OLED_ENABLE
            demo_oled_show_char('C');
#endif
            return false;
        case DEMO_ENC_D:
#ifdef OLED_ENABLE
            demo_oled_show_char('D');
#endif
            return false;
        case DEMO_RGB_E:
            return demo_handle_rgb_key(keycode, record, 'E', 0);
        case DEMO_RGB_F:
            return demo_handle_rgb_key(keycode, record, 'F', 1);
        case DEMO_RGB_G:
            return demo_handle_rgb_key(keycode, record, 'G', 2);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == ANVIL_LYR) {
        if (record->event.pressed) {
            layer_move(LAYER_NEXT(get_highest_layer(layer_state)));
        }
        return false;
    }

    if (get_highest_layer(layer_state) == LAYER_DEMO) {
        if (!process_demo_key(keycode, record)) {
            return false;
        }
    }

#if 0 // LAYER_DOTA (commented out)
    if (get_highest_layer(layer_state) == LAYER_DOTA && record->event.pressed && keycode == DOTA_TYPE_ITEM) {
        send_string(dota_items[dotaItemIndex]);
        return false;
    }
#endif

    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case SCREEN_OFF:
            oled_turn_screen_off();
            break;
        case SCREEN_ON:
            oled_turn_screen_on();
#ifdef OLED_ENABLE
            oled_refresh();
#endif
            break;
        case RASPBERRY_03:
            tap_code16(LALT(KC_F2));
            break;
        case RASPBERRY_04:
            send_string("lxterminal");
            break;
        case RASPBERRY_05:
            send_string("hostname -I");
            break;
        case RASPBERRY_06:
            tap_code(KC_BSPACE);
            break;
        case RASPBERRY_07:
            send_string("sudo raspi-config");
            break;
        case RASPBERRY_08:
            send_string("cat /etc/wpa_supplicant/wpa_supplicant.conf");
            break;
        case RASPBERRY_09:
            send_string("sudo sh -c wpa_passphrase RouterOfEvil \"Zuhlke1234$\" > /etc/wpa_supplicant/wpa_supplicant.conf");
            break;
        case RASPBERRY_11:
            send_string("wpa_passphrase RouterOfEvil \"Zuhlke1234$\" > ");
            break;
        case RASPBERRY_12:
            send_string("iwlist wlan0 scan");
            break;
        case RASPBERRY_15:
            send_string("sudo poweroff");
            break;
        case RASPBERRY_16:
            tap_code16(LSFT(LCTL(KC_Q)));
            break;
        case RASPBERRY_17:
            tap_code16(KC_ESCAPE);
            break;
        case RASPBERRY_18:
            tap_code16(KC_ENTER);
            break;
    }

    return true;
}

void suspend_power_down_user(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
}

void suspend_wakeup_init_user(void) {
#ifdef OLED_ENABLE
    oled_on();
    oled_refresh();
#endif
}
