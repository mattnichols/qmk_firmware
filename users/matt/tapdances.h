#pragma once

#include "action.h"
#include "keycode.h"
#include "process_tap_dance.h"

/*
 * Tap Dances
 */

enum tap_dances {
    TD_GIT_COMMIT,   /* Git commit, git commit --amend on double tap */
    TD_SFT_LCK       /* Shift, CapsLock on double tap */
};

void git_commit_tap_finished(qk_tap_dance_state_t *state, void *user_data);

void caps_tap(qk_tap_dance_state_t *state, void *user_data);

void caps_tap_end(qk_tap_dance_state_t *state, void *user_data);
