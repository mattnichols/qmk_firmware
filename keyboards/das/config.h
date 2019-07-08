/*
Copyright 2019 Matt Nichols <matt@nichols.link>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID     0xFEED
#define PRODUCT_ID    0x6060
#define DEVICE_VER    0x0001
#define MANUFACTURER  das
#define PRODUCT       Das Keyboard S (teensy3.2)
#define DESCRIPTION   QMK keyboard firmware for Das Keyboard

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *         ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/

#define MATRIX_ROWS 18
#define MATRIX_COLS 8
#define DIODE_DIRECTION COL2ROW

// Uses custom matrix. For reference, here are the pins.
// #define MATRIX_ROW_PINS { 8, 7, 6, 9, 1, 3, 10, 2, 5, 4, 22, 23, 24, 16, 21, 25, 26, 27 }
// #define MATRIX_COL_PINS { 11, 20, 18, 12, 14, 17, 15, 19 }
#define DEBOUNCE 5

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// #define DEBOUNCING_DELAY 5
