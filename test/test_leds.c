/**
 * @file leds.h
 * @brief Abstraction layer for controlling LEDs
 * @author Quarin, Lautaro.
 */

/* === Headers files inclusions
 * =============================================================== */
#include "leds.h"
#include <unity.h>

static uint16_t virtual_port; ///< Virtual port controlling the LEDs.

/**
 * @brief Initial configuration for the tests.
 *
 * This function is executed before each test, initializing the port with all
 * LEDs off.
 */
void setUp(void) {
    leds_init(&virtual_port);
}

void tearDown(void) {

}
/**
 * @test Verifies that all LEDs start off when the system is initialized.
 */
void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t virtual_port = 0xFFFF;

    leds_init(&virtual_port);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);
}

/**
 * @test Turns on a single LED and then turns it off to verify it turns off.
 */
void test_prender_un_solo_led(void) {
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, virtual_port);
}

/**
 * @test Turns on two LEDs, turns one off, and verifies that only the correct
 * LED turns off.
 */
void test_prender_y_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);
}

/**
 * @test Turns on all LEDs at once.
 */
void test_prender_y_apagar_2_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 6, virtual_port);
}

/**
 * @test Turns on and then turns off all LEDs at once.
 */
void test_prender_todos_los_leds_juntos(void) {
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_port);
}

/**
 * @test Turns on a single LED and checks its status.
 */
void test_prender_y_apagar_todos_los_leds_juntos(void) {
    leds_turn_on_all();
    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);
}

/**
 * @test Turns on a single LED and checks its status.
 */
void test_preder_un_led_y_consultar_su_estado(void) {
    uint8_t status = 3;
    leds_turn_on(4);
    status = leds_status(&virtual_port, 4);
    TEST_ASSERT_EQUAL_HEX8(0x0001, status);
    TEST_ASSERT_EQUAL_HEX16(1 << 3, virtual_port);
}

/**
 * @test Tests LEDs outside the valid range.
 *
 * Turns on and off LEDs with values greater than 16 and less than 1,
 * verifying that the port state does not change.
 */
void test_leds_fuera_de_rango(void) {

    leds_turn_on(-1);
    TEST_ASSERT_FALSE(led_is_turned_on(-1));
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);

    leds_turn_on(17);
    TEST_ASSERT_FALSE(led_is_turned_on(17));
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);

    leds_turn_off(-1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);

    leds_turn_off(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_port);
}