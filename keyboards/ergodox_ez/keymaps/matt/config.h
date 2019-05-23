/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION

#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define EECONFIG_RGB_MATRIX (uint32_t *)16
#define MACROS_ENABLED

// How long before a tap is considered a hold.
// #define TAPPING_TERM 120 // Already defined in keyboards/ergodox_ez/config.h

// Consider MT a mod if another key is simultaneously pressed.
#define PERMISSIVE_HOLD
