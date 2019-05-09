#include "macros.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Process Macros

    case VIM_SAVE_EXIT:
      if (record->event.pressed) {
        SEND_STRING(":wq");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_DIFF:
      if (record->event.pressed) {
        SEND_STRING("git diff");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_STATUS:
      if (record->event.pressed) {
        SEND_STRING("git status");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_COMMIT_ADD:
      if (record->event.pressed) {
        SEND_STRING("git commit -a");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case GIT_COMMIT_AMEND:
      if (record->event.pressed) {
        SEND_STRING("git commit -a --amend");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case MVN_PACKAGE:
      if (record->event.pressed) {
        SEND_STRING("mvn clean dependency:copy-dependencies package");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case MVN_JAR_INSTALL:
      if (record->event.pressed) {
        SEND_STRING("mvn clean dependency:copy-dependencies source:jar install");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case OPEN_ATOM:
      if (record->event.pressed) {
        SEND_STRING("atom .");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

    case OPEN_CODE:
      if (record->event.pressed) {
        SEND_STRING("code .");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false; break;

  }

  return process_record_keymap(keycode, record);
}
