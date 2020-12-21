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

#define _BASE 0
#define _FN 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MD_BOOT = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT,  KC_RGUI, KC_RCTL, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [_FN] = LAYOUT_ortho_5x15( \
    _______,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     KC_F7,     KC_F8,     KC_F9,      KC_F10,     KC_F11,     KC_F12,     _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    KC_MPLY,    _______,
    _______,  _______,    _______,    _______,    _______,    MD_BOOT,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    KC_VOLU,    _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    KC_MRWD,    KC_VOLD,    KC_MFFD
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;

  switch (keycode) {
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
