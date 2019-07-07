#pragma once

#include "quantum.h"

#define LAYOUT_das( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E, K5F, K60, K61, K62, K63, K64, K65, K66, K67 \
) { \
  { K00, K10, K25, K11, KC_NO, K26, K4B, K3B }, \
  { KC_NO, K01, K3A, K12, KC_NO, K27, K4C, K3C }, \
  { K04, K02, K03, K13, KC_NO, K28, K4D, K3D }, \
  { KC_NO, K5B, KC_NO, K05, KC_NO, K0F, K62, KC_NO }, \
  { K06, K1C, K31, K18, KC_NO, K2D, K52, K42 }, \
  { KC_NO, K08, K07, K19, K61, K2E, K53, K43 }, \
  { K0B, K09, K1D, K0A, K0C, KC_NO, K46, K32 }, \
  { K5D, KC_NO, KC_NO, K0D, K5F, K0E, KC_NO, KC_NO }, \
  { K3F, K15, K2A, K14, K4F, K29, K4E, K3E }, \
  { K40, K16, K2B, K17, K50, K2C, K51, K41 }, \
  { K45, K1B, K30, K1A, K54, K2F, KC_NO, K44 }, \
  { K66, K1E, K48, KC_NO, K65, K37, K22, K58 }, \
  { K56, K1F, KC_NO, K34, K63, K39, KC_NO, K5A }, \
  { K67, K20, K49, K35, K24, K38, K23, K59 }, \
  { K5E, K33, K47, KC_NO, K64, K36, K21, K57 }, \
  { KC_NO, KC_NO, K4A, KC_NO, KC_NO, KC_NO, KC_NO, K55 }, \
  { KC_NO, KC_NO, K5C, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K60 } \
}

#define UNUSED_PINS
