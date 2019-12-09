/* Copyright 2018 MechMerlin
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

#include "macros.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SHRUG = NEW_SAFE_RANGE,
  ESHRUG
};

#define _QW 0
#define _FN 1
#define _MOVE 2
#define _ADJUST 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QW] = LAYOUT_ortho_5x15( \
    KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,        KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
    LT(_ADJUST, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_DEL,  KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    LT(_MOVE, KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MPLY, KC_VOLU, KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MFFD, KC_VOLD, KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
    KC_LCTL,              KC_LCTL, KC_LALT, KC_LGUI, KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RGUI,     KC_RGUI, KC_BSLS, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_FN] = LAYOUT_ortho_5x15( \
    _______,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     KC_F7,     KC_F8,     KC_F9,      KC_F10,     KC_F11,     KC_F12,     _______,    KC_DEL,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    RGB_MOD,   RGB_M_P,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    MD_BOOT,    RGB_HUI,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    RGB_HUD,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______
  ),
  [_MOVE] = LAYOUT_ortho_5x15( \
    _______,  _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,     KC_F6,     KC_F7,     KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    KC_MRWD,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______
  ),
  [_ADJUST] = LAYOUT_ortho_5x15( \
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    RGB_MOD,   RGB_M_P,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    RGB_HUI,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    MD_BOOT,    RGB_HUD,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______
  ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;

  switch (keycode) {
    case SHRUG:
      if (record->event.pressed) {
        SEND_STRING("shrug");
      } else {
      }
      break;
    case ESHRUG:
      if (record->event.pressed) {
        SEND_STRING("eshrug");
      } else {
      }
      break;
    case MD_BOOT:
      if (record->event.pressed) {
          key_timer = timer_read32();
      } else {
          if (timer_elapsed32(key_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;

  }

  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
