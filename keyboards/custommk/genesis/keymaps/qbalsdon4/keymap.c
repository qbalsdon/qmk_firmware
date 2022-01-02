/* Copyright 2020 customMK
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
//HARD RESET:
//   1. Hold down top left key
//   2. Plug in keyboard
//qmk flash -kb custommk/genesis -km qbalsdon4
#include QMK_KEYBOARD_H
// #include "quintin.h"
#include "../../../qbalsdon/keymacros.h"
#include "../../../qbalsdon/dota.h"
#include "../../../qbalsdon/colours.h"

#define HOVER            LT(LAYER_HOVER, _______ )
#define DOTA_HOVER       LT(LAYER_HOVER, DOTA_STORE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_DOTA] = LAYOUT_ortho_5x4(
	  DOTA_PAUSE        ,TO(LAYER_RASPBERRY), DOTA_HOVER        , DOTA_TYPE_ITEM    ,
		DOTA_SPELL1       , DOTA_SPELL2       , DOTA_SPELL3       , DOTA_ULTIMATE     ,
		DOTA_ITEM_01      , DOTA_ITEM_02      , DOTA_ITEM_03      , DOTA_TP           ,
		DOTA_ITEM_04      , DOTA_ITEM_05      , DOTA_ITEM_06      , DOTA_CHATWHEEL    ,
		DOTA_FOCUS_UNITS  , DOTA_FOCUS_HERO   , DOTA_SHIFT        , DOTA_DENY         ),
  [LAYER_RASPBERRY] = LAYOUT_ortho_5x4(
		RASPBERRY_01      , TO(LAYER_ANDROID) , HOVER             , RASPBERRY_02      ,
		RASPBERRY_03      , RASPBERRY_04      , RASPBERRY_05      , RASPBERRY_06      ,
		RASPBERRY_07      , RASPBERRY_08      , RASPBERRY_09      , RASPBERRY_10      ,
		RASPBERRY_11      , RASPBERRY_12      , RASPBERRY_13      , RASPBERRY_14      ,
		RASPBERRY_15      , RASPBERRY_16      , RASPBERRY_17      , RASPBERRY_18      ),
	[LAYER_ANDROID] = LAYOUT_ortho_5x4(
		HYPR(ANVIL_MAP_01), TO(LAYER_SCRIPTS) , HOVER             , HYPR(ANVIL_MAP_02),
		HYPR(ANVIL_MAP_03), HYPR(ANVIL_MAP_04), HYPR(ANVIL_MAP_05), HYPR(ANVIL_MAP_06),
		HYPR(ANVIL_MAP_07), HYPR(ANVIL_MAP_08), HYPR(ANVIL_MAP_09), HYPR(ANVIL_MAP_10),
		HYPR(ANVIL_MAP_11), HYPR(ANVIL_MAP_12), HYPR(ANVIL_MAP_13), HYPR(ANVIL_MAP_14),
		HYPR(ANVIL_MAP_15), HYPR(ANVIL_MAP_16), HYPR(ANVIL_MAP_17), HYPR(ANVIL_MAP_18)),
	[LAYER_SCRIPTS] = LAYOUT_ortho_5x4(
		LCAG(ANVIL_MAP_01), TO(LAYER_DEMO)    , HOVER             , LCAG(ANVIL_MAP_02),
		LCAG(ANVIL_MAP_03), LCAG(ANVIL_MAP_04), LCAG(ANVIL_MAP_05), LCAG(ANVIL_MAP_06),
		LCAG(ANVIL_MAP_07), LCAG(ANVIL_MAP_08), LCAG(ANVIL_MAP_09), LCAG(ANVIL_MAP_10),
		LCAG(ANVIL_MAP_11), LCAG(ANVIL_MAP_12), LCAG(ANVIL_MAP_13), LCAG(ANVIL_MAP_14),
		LCAG(ANVIL_MAP_15), LCAG(ANVIL_MAP_16), LCAG(ANVIL_MAP_17), LCAG(ANVIL_MAP_18)),
	[LAYER_DEMO] = LAYOUT_ortho_5x4(
		DEMO_01           , TO(LAYER_DOTA)    , HOVER             , DEMO_02           ,
		DEMO_03           , DEMO_04           , DEMO_05           , DEMO_06           ,
		DEMO_07           , DEMO_08           , DEMO_09           , DEMO_10           ,
		DEMO_11           , DEMO_12           , DEMO_13           , DEMO_14           ,
		DEMO_15           , DEMO_16           , DEMO_17           , DEMO_18           ),
	[LAYER_HOVER] = LAYOUT_ortho_5x4(
		_______           , _______           , _______           , _______           ,
		_______           , _______           , _______           , _______           ,
		_______           , _______           , _______           , _______           ,
		RGB_MOD           , _______           , _______           , _______           ,
		RGB_TOG           , _______           , _______           , RESET             ),
};
/*
TODO: ADB_REBOOT(PURPLE?),
	  ADB_FLIP(PURPLE?),
	  ADB_ANIMATION (PURPLE?),
	  ADB_TB_SETTINGS,
	  ADB_TB_MENU,
	  MENU
      A11y_SCANNER

[LAYER_ADB] = LAYOUT_ortho_5x4(
		ADB_TB_CLICK   , LAYER_CYCLE     , HOVER           , ADB_TB_MUTE       ,
		ADB_UNLOCK     , ADB_TALKBACK    , _______         , ADB_SCRNREC       ,
		ADB_BACK       , ADB_TB_FOCUS    , _______         , _______           ,
		ADB_HOME       , ADB_TB_CURTAIN  , _______         , _______           ,
		ADB_POWER      , _______         , _______         , _______           ),

[LAYER_ADB_SCRIPT] = LAYOUT_ortho_5x4(
		ADB_TB_CLICK_S , LAYER_CYCLE     , HOVER           , ADB_TB_MUTE_S     ,
		ADB_UNLOCK_S   , ADB_TALKBACK_S  , _______         , ADB_SCRNREC_S     ,
		ADB_BACK_S     , ADB_TB_FOCUS_S  , _______         , _______           ,
		ADB_HOME_S     , ADB_TB_CURTAIN_S, _______         , _______           ,
		ADB_POWER_S    , _______         , _______         , _______           ),
*/

void encoder_update_user_android(uint8_t index, bool clockwise) {
	/* top left encoder */
	if (index == 0) {
		if (clockwise) {
			tap_code16(ADB_TB_NEXT);
		} else {
			tap_code16(ADB_TB_PREV);
		}
	}
	/* top right encoder */
	else if (index == 1) {
		if (clockwise) {
			tap_code16(ADB_TB_VOLU);
		} else {
			tap_code16(ADB_TB_VOLD);
		}
	}
}

void encoder_update_user_demo(uint8_t index, bool clockwise) {
	/* top left encoder */
	if (index == 0) {
		if (clockwise) {
			send_string(ADB_TB_NEXT_SCRIPT);
			tap_code(KC_ENTER);
		} else {
			send_string(ADB_TB_PREV_SCRIPT);
			tap_code(KC_ENTER);
		}
	}
	/* top right encoder */
	else if (index == 1) {
		if (clockwise) {
			send_string(ADB_TB_VOLU_SCRIPT);
			tap_code(KC_ENTER);
		} else {
			send_string(ADB_TB_VOLD_SCRIPT);
			tap_code(KC_ENTER);
		}
	}
}

void encoder_update_user_dota(uint8_t index, bool clockwise) {
	/* top left encoder */
	if (index == 0) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	}
	/* top right encoder */
	else if (index == 1) {
		if (clockwise) {
			dota_item_increase();
		} else {
			dota_item_decrease();
		}
	}
}

void encoder_update_user_raspberry(uint8_t index, bool clockwise) {
	/* top left encoder */
	if (index == 0) {
		if (clockwise) {
			tap_code(KC_DOWN);
		} else {
			tap_code(KC_UP);
		}
	}
	/* top right encoder */
	else if (index == 1) {
		if (clockwise) {
			tap_code(KC_LEFT);
		} else {
			tap_code(KC_RIGHT);
		}
	}
}

bool encoder_update_user(uint8_t encoder_index, bool clockwise) {
	uint16_t layer = biton32(layer_state);
	switch (layer) {
		case LAYER_ANDROID:
			encoder_update_user_android(encoder_index, clockwise);
		break;
		case LAYER_SCRIPTS:

		break;
		case LAYER_DEMO:
			encoder_update_user_demo(encoder_index, clockwise);
		break;
		case LAYER_DOTA:
			encoder_update_user_dota(encoder_index, clockwise);
		break;
		case LAYER_RASPBERRY:
			encoder_update_user_raspberry(encoder_index, clockwise);
		break;
		case LAYER_HOVER:

		break;
	}
	return true;
}

uint16_t* getLayerPrimaryColour(void) {
	uint16_t layer = biton32(layer_state);
	static uint16_t colour[3];
	switch (layer) {
		case LAYER_ANDROID:
			colour[0] = 0xFF; colour[1] = 0xFF; colour[2] = 0xFF;
		break;
		case LAYER_SCRIPTS:
			colour[0] = 0x00; colour[1] = 0x00; colour[2] = 0xFF;
		break;
		case LAYER_DEMO:
			colour[0] = 0xFF; colour[1] = 0xFF; colour[2] = 0xFF;
		break;
		case LAYER_DOTA:
			colour[0] = 0xFF; colour[1] = 0x00; colour[2] = 0x00;
		break;
		case LAYER_RASPBERRY:
			colour[0] = 0x00; colour[1] = 0xFF; colour[2] = 0x00;
		break;
		case LAYER_HOVER:
			colour[0] = 0x00; colour[1] = 0xFF; colour[2] = 0xFF;
		break;
	}
	return colour;
}

uint16_t* getLayerSecondaryColour(void) {
	uint16_t layer = biton32(layer_state);
	static uint16_t colour[3];
	switch (layer) {
		case LAYER_ANDROID:
			colour[0] = 0x24; colour[1] = 0xE5; colour[2] = 0x00;
		break;
		case LAYER_SCRIPTS:
			colour[0] = 0xFA; colour[1] = 0xED; colour[2] = 0x27;
		break;
		case LAYER_DEMO:
			colour[0] = 0x00; colour[1] = 0x00; colour[2] = 0x00;
		break;
		case LAYER_DOTA:
			colour[0] = 0x00; colour[1] = 0x00; colour[2] = 0x00;
		break;
		case LAYER_RASPBERRY:
			colour[0] = 0xFF; colour[1] = 0x00; colour[2] = 0x00;
		break;
		case LAYER_HOVER:
			colour[0] = 0x00; colour[1] = 0x00; colour[2] = 0xFF;
		break;
	}
	return colour;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed) {
		return true;
	}
	switch (keycode) {
		case DEMO_01:
			if (record->event.pressed) {
				send_string("frRFNJP9gKRe");
			}
		break;
		case DEMO_02:
			if (record->event.pressed) {
				SEND_STRING("M0rganm0u");
			}
		break;
		case RASPBERRY_01:
			// ROTARY 1 click
		break;
		case RASPBERRY_02:
			// ROTARY 2 click
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
		case RASPBERRY_10:
		break;
		case RASPBERRY_11:
		    send_string("wpa_passphrase RouterOfEvil \"Zuhlke1234$\" > ");
		break;
		case RASPBERRY_12:
				send_string("iwlist wlan0 scan");
		break;
		case RASPBERRY_13:
		break;
		case RASPBERRY_14:
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
		case RASPBERRY_19:
		break;
		case RASPBERRY_20:
		break;
	}
	return true;
}

void matrix_scan_user(void) {
	updateAnimationFrame(getLayerPrimaryColour(), getLayerSecondaryColour());
}
