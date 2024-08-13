/**
 * @file leds.h
 * @brief Abstraction layer for controlling LEDs
 * @author Quarin, Lautaro.
 */

#ifndef LEDS_H_
#define LEDS_H_

/* === Header files inclusions
 * ================================================================ */
#include <stdbool.h>
#include <stdint.h>

/* === C++ Header
 * ============================================================================
 */
#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions
 * =============================================================== */
/* === Public data type declarations
 * =========================================================== */
/* === Public variable declarations
 * ============================================================ */
/* === Public function declarations
 * ============================================================ */

/**
 * @brief Initializes the LED control by setting up the virtual port.
 *
 * This function initializes the virtual port to control the LEDs. It sets
 * all the LEDs to off by default.
 *
 * @param port Pointer to the virtual port to control the LEDs.
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Turns on a specific LED.
 *
 * This function sets the bit corresponding to the specified LED to turn it on.
 *
 * @param led Position of the LED to turn on.
 */
void leds_turn_on(int led);

/**
 * @brief Turns off a specific LED.
 *
 * This function clears the bit corresponding to the specified LED to turn it
 * off.
 *
 * @param led Position of the LED to turn off.
 */
void leds_turn_off(int led);

/**
 * @brief Turns on all LEDs.
 *
 * This function sets all the bits in the virtual port to turn on all LEDs.
 */
void leds_turn_on_all(void);

/**
 * @brief Turns off all LEDs.
 *
 * This function clears all the bits in the virtual port to turn off all LEDs.
 */
void leds_turn_off_all(void);

/**
 * @brief Checks the status of a specific LED.
 *
 * This function returns the status of a specified LED. It checks if the bit
 * corresponding to the LED is set or not.
 *
 * @param led Position of the LED to check.
 * @return uint8_t 1 if the LED is on, 0 if the LED is off.
 */
uint8_t leds_status(uint16_t * virtual_port, uint16_t led);

/* === End of documentation
 * ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif // LEDS_H_
