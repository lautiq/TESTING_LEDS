#include <unity.h>
#include "leds.h"

static uint16_t puerto_virtual;

void setUp(void) {
    leds_init(&puerto_virtual);
}

void tearDown(void) {

}


//Al arrancar el sistema todos los leds apagados:
void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;

    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

//Despues de arrancar el sistema, con los leds apagados, prender un led cualquiera
void test_prender_un_solo_led(void) {
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

//Prender un led y apagarlo para ver si se apaga.
void test_prender_y_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

//Prender dos leds, apagar uno y ver que solo se apaga el correspondiente y el otro queda prendido.
void test_prender_y_apagar_2_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual);
}