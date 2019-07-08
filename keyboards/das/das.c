#include "das.h"
#include "hal.h"
#include "teensy.h"

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

void matrix_init_kb(void) {
  matrix_init_user();
};

void matrix_scan_kb(void) {
  matrix_scan_user();
};

#define CAPS_LOCK_LED_PIN  TEENSY_PIN28
#define CAPS_LOCK_LED_PORT TEENSY_PIN28_IOPORT
#define NUM_LOCK_LED_PIN   TEENSY_PIN29
#define NUM_LOCK_LED_PORT  TEENSY_PIN29_IOPORT
#define SCROLL_LOCK_LED_PIN   TEENSY_PIN30
#define SCROLL_LOCK_LED_PORT  TEENSY_PIN30_IOPORT

void keyboard_pre_init_kb(void) {
    // Set our LED pins as output
    palSetPadMode(TEENSY_PIN28_IOPORT, TEENSY_PIN28, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(TEENSY_PIN29_IOPORT, TEENSY_PIN29, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(TEENSY_PIN30_IOPORT, TEENSY_PIN30, PAL_MODE_OUTPUT_PUSHPULL);

    keyboard_pre_init_user();
}

void led_set_kb(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        palSetPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_PIN);
    } else {
        palClearPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_PIN);
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        onboardLedOn();
        palSetPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_PIN);
    } else {
        onboardLedOff();
        palClearPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_PIN);
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        palSetPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_PIN);
    } else {
        palClearPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_PIN);
    }

    led_set_user(usb_led);
}
