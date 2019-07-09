#include "teensy.h"
#include "wait.h"

void onboardLedInit() {
    palSetPadMode(TEENSY_PIN13_IOPORT, TEENSY_PIN13, PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_PIN, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(NUM_LOCK_LED_PORT, NUM_LOCK_LED_PIN, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_PIN, PAL_MODE_OUTPUT_PUSHPULL);
}

void onboardLedOn(void) {
    palSetPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
}

void onboardLedOff(void) {
    palClearPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
}

void onboardLedBlink(int millis) {
    onboardLedOn();
    wait_ms(millis);
    onboardLedOff();
}

void numLockLedOn(void) {
    palSetPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_PIN);
}
void numLockLedOff(void) {
    palClearPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_PIN);
}

void capLockLedOn(void) {
    palSetPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_PIN);
}
void capLockLedOff(void) {
    palClearPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_PIN);
}

void scrollLockLedOn(void) {
    palSetPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_PIN);
}
void scrollLockLedOff(void) {
    palClearPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_PIN);
}
