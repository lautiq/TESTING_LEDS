#ifndef LEDS_H_
#define LEDS_H_

/**
 * @file leds.h
 * @brief Abstraction layer for controlling LEDs
 */

/* === Header files inclusions ================================================================ */
#include <stdint.h>

/* === C++ Header ============================================================================ */
#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
/* === Public data type declarations =========================================================== */
/* === Public variable declarations ============================================================ */
/* === Public function declarations ============================================================ */

void leds_init(uint16_t * puerto);
void leds_turn_on(int led);
void leds_turn_off(int led);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif // LEDS_H_
