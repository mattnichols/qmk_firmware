#include "das.h"

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

void matrix_init_kb(void) {
  debug_enable=true;
  debug_matrix=true;

  matrix_init_user();
};

void matrix_scan_kb(void) {
  matrix_scan_user();
};
