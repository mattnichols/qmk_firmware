#pragma once

#include "hal.h"

#define NUM_LOCK_LED_PIN      TEENSY_PIN31
#define NUM_LOCK_LED_PORT     TEENSY_PIN31_IOPORT
#define CAPS_LOCK_LED_PIN     TEENSY_PIN30
#define CAPS_LOCK_LED_PORT    TEENSY_PIN30_IOPORT
#define SCROLL_LOCK_LED_PIN   TEENSY_PIN29
#define SCROLL_LOCK_LED_PORT  TEENSY_PIN29_IOPORT

void onboardLedInit(void);
void onboardLedOn(void);
void onboardLedOff(void);
void onboardLedBlink(int millis);
void numLockLedOn(void);
void numLockLedOff(void);
void capLockLedOn(void);
void capLockLedOff(void);
void scrollLockLedOn(void);
void scrollLockLedOff(void);
