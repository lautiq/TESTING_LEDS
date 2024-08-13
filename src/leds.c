/**
 * @file leds.c
 * @brief Abstraction layer for controlling LEDs
 * @author Quarin, Lautaro.
 */

/* === Including header files
 * ================================================================= */
#include "leds.h"

/* === Public macros definitions
 * =============================================================== */
#define LED_OFFSET   1      ///< LEDs are numbered 1-16, but bits are 0-15 (offset 1).
#define FIRST_BIT    1      ///< Value that is shifted to create the mask.
#define ALL_LEDS_OFF 0x0000 ///< Value to set the port for all LEDs off.
#define ALL_LEDS_ON  0xFFFF ///< Value to set the port for all LEDs on. (Removed semicolon)

/* === Private variable declarations
 * =========================================================== */
static uint16_t * virtual_port; ///< Pointer to the virtual port controlling the LEDs.

/* === Private function declarations
 * ============================================================ */
/**
 * @brief Converts a LED number to a bitmask.
 *
 * This function takes a LED number and returns the corresponding bitmask
 * that can be used to manipulate the specific LED.
 *
 * @param led Position of the LED to mask.
 * @return uint16_t Bitmask corresponding to the LED position.
 */
static uint16_t led_to_mask(led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

/* === Public variable definitions
 * ============================================================= */

/* === Private variable definitions
 * ============================================================ */

/**
 * @brief Initializes the LED control by setting up the virtual port.
 *
 * This function initializes the virtual port to control the LEDs. It sets
 * all the LEDs to off by default.
 *
 * @param port Pointer to the virtual port to control the LEDs.
 */
void leds_init(uint16_t * port) {
    virtual_port = port;
    *virtual_port = ALL_LEDS_OFF;
}

/**
 * @brief Turns on a specific LED.
 *
 * This function sets the bit corresponding to the specified LED to turn it on.
 *
 * @param led Position of the LED to turn on.
 */
void leds_turn_on(int led) {
    *virtual_port |= led_to_mask(led);
}

/**
 * @brief Turns off a specific LED.
 *
 * This function clears the bit corresponding to the specified LED to turn it
 * off.
 *
 * @param led Position of the LED to turn off.
 */
void leds_turn_off(int led) {
    *virtual_port &= ~led_to_mask(led);
}

/**
 * @brief Turns on all LEDs.
 *
 * This function sets all the bits in the virtual port to turn on all LEDs.
 */
void leds_turn_on_all(void) {
    *virtual_port = ALL_LEDS_ON;
};

/**
 * @brief Turns off all LEDs.
 *
 * This function clears all the bits in the virtual port to turn off all LEDs.
 */
void leds_turn_off_all(void) {
    *virtual_port = ALL_LEDS_OFF;
};

/**
 * @brief Checks the status of a specific LED.
 *
 * This function returns the status of a specified LED. It checks if the bit
 * corresponding to the LED is set or not.
 *
 * @param led Position of the LED to check.
 * @return uint8_t 1 if the LED is on, 0 if the LED is off.
 */
uint8_t leds_status(uint16_t * virtual_port, uint16_t led) {
    return (*virtual_port & (led_to_mask(led))) ? 1 : 0;
};
