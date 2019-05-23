#include QMK_KEYBOARD_H
#include "version.h"
#include "macros.h"
#include "shortcuts.h"

// ********************************************
// Layers
#define BASE 0 // default layer
#define NAV  1 // Layout, Numpad, Media
#define MEDA 2 // Mouse layer??
#define MCRS 3 // Macros
#define NUM  4
#define SYMB 5

enum custom_keycodes {

  EPRM = NEW_SAFE_RANGE,
  VRSN,
  DYNAMIC_MACRO_RANGE,
  RGB_SLD,

};

#include "dynamic_macro.h"

/*
 * Tap Dances
 */

enum tap_dances {
    TD_GIT_COMMIT,
    TD_SFT_LCK
};

void git_commit_tap_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
      send_git_commit(true);
    } else {
      send_git_commit(false); // no amend
    }
}

// Shift vs capslock function. From bbaserdem's Planck keymap.
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
}

void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    [TD_SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED(caps_tap, NULL, caps_tap_end),

    // Tap once "commit -a", Tap twice "commit -a --amend"
    [TD_GIT_COMMIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, git_commit_tap_finished, NULL),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,----------------------------------------------------.           ,------------------------------------------------------.
 * |  ~`    |    1   |   2  |   3  |   4  |  5   |   6  |           |   7  |   8  |   9  |   0  |  -_  |  =+   |  Bksp/Del |
 * |--------+--------+------+------+------+-------------|           |------+------+------+------+------+-------+-----------|
 * | Tab    |    Q   |   W  |   E  |   R  |   T  |  [{  |           | ]}   |   Y  |   U  |   I  |   O  |   P   |   \|      |
 * |--------+--------+------+------+------+------|[NUM] |           |[MCR] |------+------+------+------+-------+-----------|
 * |Esc(NAV)| A/Shft | S/Ctl| D/Alt| F/Gui|   G  |------|           |------|   H  |J/Gui |K/Alt |L/Ctl |;:/Shft|   '"      |
 * |--------+--------+------+------+------+------|  (   |           |  )   |------+------+------+------+-------+-----------|
 * | LShift | Z/Ctrl |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  Up   | RShft/Ent |
 * `--------+--------+------+------+------+-------------'           `-------------+------+------+------+-------+-----------'
 *   |LCtrl | [SYMB] | LCtrl| LAlt | LGui |                                       | /?   |  =+  | Left | Down  |  Rght  |
 *   `------------------------------------'                                       `-------------------------------------'
 *                                        ,-----------------.       ,-----------------.
 *                                        |        |        |       | Cmd ` |         |
 *                                 ,------|--------|--------|       |-------+---------+-------.
 *                                 | Spc  |  Cmd   |        |       |       |         |       |
 *                                 |      |        |--------|       |-------|  Enter  |  Spc  |
 *                                 |      |        |[NAV]/F5|       |[MEDA] |         |       |
 *                                 `------------------------'       `-------------------------'
 */
[BASE] = LAYOUT_ergodox(

  // Left Hand
  KC_GRAVE,       KC_1,                  KC_2,                 KC_3,                  KC_4,                 KC_5,           KC_6,
  KC_TAB,         KC_Q,                  KC_W,                 KC_E,                  KC_R,                 KC_T,           LT(NUM, KC_LBRACKET),
  KC_ESCAPE,      MT(MOD_LSFT, KC_A),    MT(MOD_LCTL, KC_S),   MT(MOD_LALT, KC_D),    MT(MOD_LGUI, KC_F),   KC_G,
  TD(TD_SFT_LCK), CTL_T(KC_Z),           KC_X,                 KC_C,                  KC_V,                 KC_B,           KC_LPRN,
  KC_LCTRL,       MO(SYMB),              KC_LCTRL,             KC_LALT,               KC_LGUI,

  // Left Thumb
  KC_LBRACKET,    KC_NO,
  KC_NO,
  KC_SPACE, KC_LGUI,  LT(NAV, KC_F5),

  // Right hand
  KC_7,                    KC_8,            KC_9,                 KC_0,                 KC_MINUS,              KC_EQUAL,                   KC_BSPACE,
  LT(MCRS, KC_RBRACKET),   KC_Y,            KC_U,                 KC_I,                 KC_O,                  KC_P,                       KC_BSLASH,
                           KC_H,            MT(MOD_RGUI, KC_J),   MT(MOD_RALT, KC_K),   MT(MOD_RCTL, KC_L),    MT(MOD_RSFT, KC_SCOLON),    KC_QUOT,
  KC_RPRN,                 KC_N,            KC_M,                 KC_COMMA,             KC_DOT,                KC_UP,                      RSFT_T(KC_ENT),
                                            KC_SLASH,             KC_NO,                KC_LEFT,               KC_DOWN,                    KC_RIGHT,

  // Right thumb
  KC_NO,          KC_RBRACKET,
  KC_NO,
  LT(MEDA, KC_NO),  KC_ENTER,  KC_SPACE

),

/* Layer 1:
 *
 * ,------------------------------------------------------------.      ,-----------------------------------------.
 * |        |      F1     |  F2  |      F3      | F4 | F5 | F6  |      |  F7   | F8 | F9  | F10 | F11 | F12 |    |
 * |--------+-------------+------+--------------+----+----+-----|      |-------+----+-----+-----+-----+-----+----|
 * |        | Win Left SM |      | Win Right SM |    |    |     |      |  Vol  |    |     |     |(*1) |(*2) |    |
 * |--------+-------------+------+--------------+----+----|     |      |  Up   |----+-----+-----+-----+-----+----|
 * |        | Win Left Lg | Full | Win Right Lg |    |    |-----|      |-------| <- | \/  | /\  | ->  |     |    |
 * |--------+-------------+------+--------------+----+----|     |      |  Vol  |----+-----+-----+-----+-----+----|
 * |        |             |      |              |    |    |     |      |  Dn   |    |     |     |     |     |    |
 * `--------+-------------+------+--------------+----+----------'      `-------+----+-----+-----+-----+-----+----'
 *   | EPRM |    (*3)     |      |              |    |                         |    |     |     |     |       |
 *   `-----------------------------------------------'                         `------------------------------'
 *                                                ,-------------.      ,-------------.
 *                                                |      |      |      |      |      |
 *                                         ,------|------|------|      |------+------+------.
 *                                         |      |      |      |      |      |      |      |
 *                                         |      |      |------|      |------|      |      |
 *                                         |      |      |      |      |      |      |      |
 *                                         `--------------------'      `--------------------'
 * (*1) - Next window (Cmd-])
 * (*2) - Next window (Cmd-[)
 * (*3) - Split terminal window (Cmd-Shift-D)
 */

[NAV] = LAYOUT_ergodox(

  // Left hand
  KC_TRNS,       KC_TRNS,        KC_F1,           KC_F2,            KC_F3,          KC_F4,             KC_F5,
  KC_TRNS,       KC_TRNS,        DIVVY_LEFT_SM,   KC_TRNS,          DIVVY_RIGHT_SM, KC_TRNS,           KC_TRNS,
  KC_TRNS,       KC_TRNS,        DIVVY_LEFT_LG,   DIVVY_FULL,       DIVVY_RIGHT_LG, KC_TRNS,
  KC_TRNS,       KC_TRNS,        SGUI(KC_D),      KC_TRNS,          KC_TRNS,        KC_TRNS,           KC_TRNS,
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,

  // Left thumb
  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_UNDS,
  KC_PLUS,  KC_TRNS,

  // Right hand
  KC_F6,             KC_F7,          KC_F8,           KC_F9,           KC_F10,             KC_F11,            KC_DEL,
  KC_AUDIO_VOL_UP,   KC_TRNS,        KC_TRNS,         KC_TRNS,         SGUI(KC_LBRACKET),  SGUI(KC_RBRACKET), KC_TRNS,
                     KC_LEFT,        KC_DOWN,         KC_UP,           KC_RIGHT,           KC_TRNS,           KC_TRNS,
  KC_AUDIO_VOL_DOWN, KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,            KC_TRNS,           KC_TRNS,
                                     KC_TRNS,         KC_TRNS,         KC_TRNS,            KC_TRNS,           KC_TRNS,

  // Right thumb
  KC_MEDIA_REWIND,      KC_MEDIA_FAST_FORWARD,
  KC_MEDIA_STOP,        KC_MEDIA_PLAY_PAUSE,
  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK
),

/* Layer 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |       |       |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+-------+-------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |       |       |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+-------+-------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |       |       |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+-------+-------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  Play |  Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+-------+-------+------+------+--------'
 *   |      |      |      |      |      |                                       | VolDn | VolUp | Mute |      |    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MEDA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),

/* Layer 3: Macros
 *
 * NOTES:
 *   git commit can be double-tapped to amend
 *
 * ,----------------------------------------------------------------------.           ,-----------------------------------------------------------------.
 * |        |        |          |            |          |          |      |           |      |      |      |             |           |         |        |
 * |--------+--------+----------+------------+----------+-----------------|           |------+------+------+-------------+-----------+---------+--------|
 * |        | Open A | Open C   |            |          |          |      |           |      |      |      |             |           |         |        |
 * |--------+--------+----------+------------+----------+----------|      |           |      |------+------+-------------+-----------+---------+--------|
 * |        |  gs    | gd       | git pull   | (*1)     |          |------|           |------|      |      |             |           |         |        |
 * |--------+--------+----------+------------+----------+----------|      |           |      |------+------+-------------+-----------+---------+--------|
 * |        | package|jar inst  |            |          |          |      |           |      |      |      |             |           |         |        |
 * `--------+--------+----------+------------+----------+-----------------'           `-------------+------+-------------+-----------+---------+--------'
 *   |      |        |          |            |          |                                       |      |             |           |         |      |
 *   `--------------------------------------------------'                                       `-------------------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * *1 - git commit -a (--amend w/double-tap)
 *
 */
[MCRS] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,    KC_TRNS,     KC_TRNS,         KC_TRNS,  KC_TRNS,            KC_TRNS,   KC_TRNS,
  KC_TRNS,    OPEN_ATOM,   OPEN_CODE,       KC_TRNS,  KC_TRNS,            KC_TRNS,   KC_TRNS,
  KC_TRNS,    GIT_STATUS,  GIT_DIFF,        GIT_PULL, TD(TD_GIT_COMMIT),  KC_TRNS,
  KC_TRNS,    MVN_PACKAGE, MVN_JAR_INSTALL, KC_TRNS,  KC_TRNS,            KC_TRNS,   KC_TRNS,
  KC_TRNS,    KC_TRNS,     KC_TRNS,         KC_TRNS,  KC_TRNS,

                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MVN_JAR_INSTALL, MVN_PACKAGE,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),

[NUM] = LAYOUT_ergodox(

  // Left hand
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,       KC_TRNS,           KC_TRNS,
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,       KC_TRNS,           KC_TRNS,
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,       KC_TRNS,
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,       KC_TRNS,           KC_TRNS,
  KC_TRNS,       KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_TRNS,

  // Left thumb
  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,

  // Right hand
  KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,    KC_TRNS,           KC_TRNS,
  KC_TRNS,     KC_TRNS,        KC_7,            KC_8,            KC_9,       KC_KP_PLUS,        KC_TRNS,
               KC_TRNS,        KC_4,            KC_5,            KC_6,       KC_KP_MINUS,       KC_TRNS,
  KC_TRNS,     KC_TRNS,        KC_1,            KC_2,            KC_3,       KC_KP_ASTERISK,    KC_TRNS,
                               KC_TRNS,         KC_0,            KC_TRNS,    KC_KP_SLASH,       KC_TRNS,

  // Right thumb
  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS
),

[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, KC_TRNS,
                                                        KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, RGB_SLD,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),

};

#define M_RGB_OFF {0,0,0}
#define M_RGB_WHITE {0,0,255}
#define M_RGB_RED {0,204,255}
#define M_RGB_RED_DRK {12,225,241}
#define M_RGB_CYAN {32,255,234}

// -----------------------------------------------------------------
// RGB

// Layer RGB Matrix

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {

    /*

    Layout is Right Hand (Top-Left to Bottom-Right)
              Left Hand (Top-Left to Bottom-Right)

    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    | 28  | 27  | 26  | 25  | 24  |          |  0  |  1  |  2  |  3  |  4  |
    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    | 33  | 32  | 31  | 30  | 29  |          |  5  |  6  |  7  |  8  |  9  |
    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    | 38  | 37  | 36  | 35  | 34  |          | 10  | 11  | 12  | 13  | 14  |
    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    | 43  | 42  | 41  | 40  | 39  |          | 15  | 16  | 17  | 18  | 19  |
    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    | 47  | 46  | 45  | 44  |     |          |     | 20  | 21  | 22  | 23  |
    |-----+-----+-----+-----+-----|          |-----+-----+-----+-----+-----|
    */

    [BASE] = {
      // Right Hand (Left to right)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
                     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,

      // Left Hand (Right to left)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF
    },

    [NAV] = {
      // Right Hand (Left to right)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_CYAN,     M_RGB_CYAN,
      M_RGB_CYAN,    M_RGB_CYAN,    M_RGB_CYAN,    M_RGB_CYAN,     M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
                     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,

      // Left Hand (Right to left)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_CYAN,    M_RGB_OFF,     M_RGB_CYAN,     M_RGB_OFF,
      M_RGB_OFF,     M_RGB_CYAN,    M_RGB_CYAN,    M_RGB_CYAN,     M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF
    },

    [MEDA] =  {
      // Right Hand (Left to right)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_CYAN,    M_RGB_CYAN,    M_RGB_CYAN,     M_RGB_OFF,
                     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,

      // Left Hand (Right to left)

      M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,   M_RGB_WHITE,    M_RGB_WHITE,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_CYAN,    M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_CYAN,    M_RGB_CYAN,    M_RGB_CYAN,     M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,      M_RGB_OFF,
      M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF,     M_RGB_OFF
    },
};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Set layer indicator lights
uint32_t layer_state_set_user(uint32_t state) {
  return state;

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state) { return; }
  switch (biton32(layer_state)) {
    // case 0:
    //   set_layer_color(0);
    //   break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
  }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }

      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }

      return false;
    case RGB_TOG:
      if (record->event.pressed) {
        if (rgb_matrix_config.val) {
          rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 0);
        } else {
          rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 255);
        }
      }

      return false;
  }

  return true;
}
