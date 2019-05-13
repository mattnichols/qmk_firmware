#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

// Define all of
enum macro_keycodes {

  KC_MAKE = SAFE_RANGE,

  // Vim

  VIM_SAVE_EXIT,    // :wq

  // Git

  GIT_PULL,         // git pull
  GIT_DIFF,         // git diff
  GIT_STATUS,       // git status
  GIT_PUSH,         // git push
  GIT_COMMIT_ADD,   // git commit -a
  GIT_COMMIT_AMEND, // git commit -a --amend

  // Maven

  MVN_PACKAGE,      // mvn clean dependency:copy-dependencies package
  MVN_JAR_INSTALL,  // mvn clean dependency:copy-dependencies source:jar install

  // Editors

  OPEN_ATOM,        // "atom ."
  OPEN_CODE,        // "code ."

  // Give a new safe range
  NEW_SAFE_RANGE,

};

void send_git_commit(bool amend);
