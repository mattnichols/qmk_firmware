#include "teensy.h"
#include "wait.h"
#include "hal.h"

void onboardLedInit() {
    palSetPadMode(TEENSY_PIN13_IOPORT, TEENSY_PIN13, PAL_MODE_OUTPUT_PUSHPULL);
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
