/**
 * @file leds.c
 * @brief Abstraction layer for controlling LEDs
 */

#include "leds.h"

#define LED_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000

static uint16_t * puerto_virtual;

static uint16_t led_to_mask(led) {
    return(FIRST_BIT << (led - LED_OFFSET));
}


void leds_init(uint16_t * puerto) {
    puerto_virtual = puerto;
    *puerto_virtual = ALL_LEDS_OFF;
}

void leds_turn_on(int led) {
    *puerto_virtual |= led_to_mask(led);
}

void leds_turn_off(int led) {
    *puerto_virtual &= ~led_to_mask(led);
} 