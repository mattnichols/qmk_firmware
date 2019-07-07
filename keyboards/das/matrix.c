#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "hal.h"
#include "timer.h"
#include "wait.h"
#include "print.h"
#include "matrix.h"

// #include "printf.h"

/*
 * Matt3o's WhiteFox
 * Column pins are input with internal pull-down. Row pins are output and strobe with high.
 * Key is high or 1 when it turns on.
 *
 *     col: { PTD0, PTD1, PTD4, PTD5, PTD6, PTD7, PTC1, PTC2 }
 *     row: { PTB2, PTB3, PTB18, PTB19, PTC0, PTC8, PTC9, PTC10, PTC11 }
 */
/* matrixy state(1:on, 0:off) */
static matrix_row_t matrixy[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
static bool debouncing = false;
static uint16_t debouncing_time = 0;

// #define MATRIX_ROW_PINS { 8, 7, 6, 9, 1, 3, 10, 2, 5, 4, 22, 23, 24, 16, 21, 25, 26, 27 }
// #define MATRIX_COL_PINS { 11, 20, 18, 12, 14, 17, 15, 19 }

// Rows ---------------------------
// static int matrix_row_pins[MATRIX_ROWS] = { 8, 7, 6, 9, 1, 3, 10, 2, 5, 4, 22, 23, 24, 16, 21, 25, 26, 27 };
static int matrix_row_pins[MATRIX_ROWS] = {TEENSY_PIN8, TEENSY_PIN7, TEENSY_PIN6, TEENSY_PIN9, TEENSY_PIN1, TEENSY_PIN3, TEENSY_PIN10, TEENSY_PIN2, TEENSY_PIN5, TEENSY_PIN4, TEENSY_PIN22, TEENSY_PIN23, TEENSY_PIN24, TEENSY_PIN16, TEENSY_PIN21, TEENSY_PIN25, TEENSY_PIN26, TEENSY_PIN27};
static GPIO_TypeDef* matrix_row_ports[MATRIX_ROWS] = {TEENSY_PIN8_IOPORT, TEENSY_PIN7_IOPORT, TEENSY_PIN6_IOPORT, TEENSY_PIN9_IOPORT, TEENSY_PIN1_IOPORT, TEENSY_PIN3_IOPORT, TEENSY_PIN10_IOPORT, TEENSY_PIN2_IOPORT, TEENSY_PIN5_IOPORT, TEENSY_PIN4_IOPORT, TEENSY_PIN22_IOPORT, TEENSY_PIN23_IOPORT, TEENSY_PIN24_IOPORT, TEENSY_PIN16_IOPORT, TEENSY_PIN21_IOPORT, TEENSY_PIN25_IOPORT, TEENSY_PIN26_IOPORT, TEENSY_PIN27_IOPORT};

// Cols ---------------------------
// static int matrix_col_pins[MATRIX_COLS] = {11, 20, 18, 12, 14, 17, 15, 19};
static int matrix_col_pins[MATRIX_COLS] = {TEENSY_PIN11, TEENSY_PIN20, TEENSY_PIN18, TEENSY_PIN12, TEENSY_PIN14, TEENSY_PIN17, TEENSY_PIN15, TEENSY_PIN19};
static GPIO_TypeDef* matrix_col_ports[MATRIX_COLS] = {TEENSY_PIN11_IOPORT, TEENSY_PIN20_IOPORT, TEENSY_PIN18_IOPORT, TEENSY_PIN12_IOPORT, TEENSY_PIN14_IOPORT, TEENSY_PIN17_IOPORT, TEENSY_PIN15_IOPORT, TEENSY_PIN19_IOPORT};

void matrix_init(void)
{
    //debug_matrix = true;

    /* Row(strobe) */
    for (int row = 0; row < MATRIX_ROWS; row++) {
        palSetPadMode(matrix_row_ports[row], matrix_row_pins[row], PAL_MODE_OUTPUT_PUSHPULL);
        palSetPad(matrix_row_ports[row], matrix_row_pins[row]);
    }

    /* Column(sense) */
    for (int col = 0; col < MATRIX_COLS; col++) {
        palSetPadMode(matrix_col_ports[col], matrix_col_pins[col], PAL_MODE_INPUT_PULLUP);
    }

    memset(matrixy, 0, MATRIX_ROWS * sizeof(matrix_row_t));
    memset(matrix_debouncing, 0, MATRIX_ROWS * sizeof(matrix_row_t));

    palSetPadMode(TEENSY_PIN13_IOPORT, TEENSY_PIN13, PAL_MODE_OUTPUT_PUSHPULL);

    palSetPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    chThdSleepMilliseconds(300);
    palClearPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    chThdSleepMilliseconds(300);

    // palSetPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    // chThdSleepMilliseconds(50);
    // palClearPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    // chThdSleepMilliseconds(50);

    // delay(500);
    // palClearPad(GPIOB, 13);

    matrix_init_quantum();
}

uint8_t matrix_scan(void)
{
    for (int row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t data = 0;

        // strobe row
        palClearPad(matrix_row_ports[row], matrix_row_pins[row]);

        wait_us(20); // need wait to settle pin state

        for (int col = 0; col < MATRIX_COLS; col++) {
            unsigned int lstate = palReadPad(matrix_col_ports[col], matrix_col_pins[col]);
            if(lstate == PAL_LOW) {
                data = data | (1U << col);
            } else {
                data = data | (0U << col);
            }
        }

        // un-strobe row
        palSetPad(matrix_row_ports[row], matrix_row_pins[row]);

        if (matrix_debouncing[row] != data) {
            matrix_debouncing[row] = data;
            debouncing = true;
            debouncing_time = timer_read();
        }
    }


    if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            matrixy[row] = matrix_debouncing[row];
        }
        debouncing = false;
    }

    matrix_scan_quantum();
    return 1;
}

bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrixy[row] & (1<<col));
}

matrix_row_t matrix_get_row(uint8_t row)
{
    matrix_row_t r = matrixy[row];
    return r;
}

void matrix_print(void)
{
    xprintf("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        xprintf("%X0: ", row);
        matrix_row_t data = matrix_get_row(row);
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (data & (1<<col))
                xprintf("1");
            else
                xprintf("0");
        }
        xprintf("\n");
    }
}
