#include "tapdances.h"
#include "macros.h"

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
