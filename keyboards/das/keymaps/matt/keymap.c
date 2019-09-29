#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_das( \
    KC_ESC,                                  KC_F1,               KC_F2,               KC_F3,               KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,    KC_F12,      KC_MPLY, KC_VOLD, KC_VOLU,                                                 \
    KC_GRV,             KC_1,                KC_2,                KC_3,                KC_4,                KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,             KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,             KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,             KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    LT(1, KC_ESC),      MT(MOD_LSFT, KC_A),  MT(MOD_LCTL, KC_S),  MT(MOD_LALT, KC_D),  MT(MOD_LGUI, KC_F),  KC_G,       KC_H,       MT(MOD_RGUI, KC_J),   MT(MOD_RALT, KC_K),   MT(MOD_RCTL, KC_L),    MT(MOD_RSFT, KC_SCLN),    KC_QUOT,               KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,            \
    KC_LSFT,                                 KC_Z,                KC_X,                KC_C,                KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,               KC_RSFT,              KC_UP,                        KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    KC_LCTL,            KC_LALT,             KC_LGUI,                                        KC_SPC,                                                        KC_RGUI,    KC_RALT,    KC_NO,      KC_RCTL,                KC_LEFT, KC_DOWN, KC_RGHT,             KC_P0,   KC_PDOT                    \
  ),
  [1] = LAYOUT_das( \
    KC_TRNS,                            KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                                                 \
    KC_TRNS,            KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
    KC_TRNS,            KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
    KC_TRNS,            KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_TRNS,    KC_TRNS,               KC_TRNS,                                            KC_TRNS,   KC_TRNS,   KC_TRNS,            \
    KC_TRNS,                            KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,              KC_TRNS,                      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
    KC_TRNS,            KC_TRNS,        KC_TRNS,                                 KC_SPC,                                              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS                        \
  )
  // Transparent Layer Template
  /*
    [1] = LAYOUT_das( \
      KC_TRNS,             KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                                                 \
      KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
      KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
      KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,                                            KC_TRNS,   KC_TRNS,   KC_TRNS,            \
      KC_TRNS,             KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,              KC_TRNS,                      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, \
      KC_TRNS,  KC_TRNS,   KC_TRNS,                       KC_SPC,                                              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,   KC_TRNS                        \
    )
  */
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// void matrix_init_user(void) {
// }

// void matrix_scan_user(void) {
// }

// void led_set_user(uint8_t usb_led) {
// }
