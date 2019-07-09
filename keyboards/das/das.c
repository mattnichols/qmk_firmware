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


void keyboard_pre_init_kb(void) {
    onboardLedInit();
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    // Blink Onboard Led
    onboardLedBlink(300);

    // Flash lock leds
    numLockLedOn();
    chThdSleepMilliseconds(80);
    numLockLedOff();
    scrollLockLedOff();

    capLockLedOn();
    chThdSleepMilliseconds(80);
    capLockLedOff();
    chThdSleepMilliseconds(80);

    scrollLockLedOn();
    chThdSleepMilliseconds(80);
    scrollLockLedOff();
    chThdSleepMilliseconds(80);

    // Blink all
    numLockLedOn();
    capLockLedOn();
    scrollLockLedOn();

    chThdSleepMilliseconds(200);

    numLockLedOff();
    capLockLedOff();
    scrollLockLedOff();
}

void led_set_kb(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        numLockLedOn();
    } else {
        numLockLedOff();
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        capLockLedOn();
    } else {
        capLockLedOff();
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        scrollLockLedOn();
    } else {
        scrollLockLedOff();
    }

    led_set_user(usb_led);
}
