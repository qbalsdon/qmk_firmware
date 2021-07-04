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
//qmk flash -kb custommk/genesis -km qbalsdon4
#include QMK_KEYBOARD_H
#include "quintin.h"

#define HOVER            LT(LAYER_HOVER, _______ )
#define DOTA_HOVER       LT(LAYER_HOVER, DOTA_STORE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//TODO: ADB_REBOOT(PURPLE?), ADB_FLIP(PURPLE?), ADB_ANIMATION (PURPLE?), ADB_TB_SETTINGS, ADB_TB_MENU, MENU
//      A11y_SCANNER
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

	[LAYER_DOTA] = LAYOUT_ortho_5x4(
		  DOTA_PAUSE      , LAYER_CYCLE     , DOTA_HOVER      , DOTA_TYPE_ITEM    ,
			DOTA_SPELL1     , DOTA_SPELL2     , DOTA_SPELL3     , DOTA_ULTIMATE     ,
			DOTA_01         , DOTA_02         , DOTA_03         , DOTA_TP           ,
			DOTA_04         , DOTA_05         , DOTA_06         , DOTA_CHATWHEEL    ,
			DOTA_FOCUS_UNITS, DOTA_FOCUS_HERO , DOTA_SHIFT      , DOTA_DENY         ),

	[LAYER_HOVER] = LAYOUT_ortho_5x4(
			_______         , _______         , _______         , _______           ,
			_______         , _______         , _______         , _______           ,
			_______         , _______         , _______         , _______           ,
			_______         , _______         , _______         , _______           ,
			RGB_TOG         , _______         , _______         , RESET             ),
};

void encoder_update_user_adb(uint8_t index, bool clockwise) {
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

void encoder_update_user_adb_script(uint8_t index, bool clockwise) {
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
			if (dotaItemIndex < DOTA_ITEM_COUNT - 1) {
				dotaItemIndex++;
			}
		} else {
			if (dotaItemIndex > 0) {
				dotaItemIndex--;
			}
		}
	}
}

__attribute__((weak)) void encoder_update_user(uint8_t index, bool clockwise) {
	uint16_t layer = currentLayer();

  if (layer == LAYER_ADB) {
    encoder_update_user_adb(index, clockwise);
	}
	if (layer == LAYER_ADB_SCRIPT) {
    encoder_update_user_adb_script(index, clockwise);
	}
  else if (layer == LAYER_DOTA) {
		encoder_update_user_dota(index, clockwise);
	}
}
