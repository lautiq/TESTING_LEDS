#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t puerto_virtual;



void setUp(void) {

    leds_init(&puerto_virtual);

}



void tearDown(void) {



}







void test_todos_los_leds_deben_arrancar_apagados(void) {

    uint16_t puerto_virtual = 0xFFFF;



    leds_init(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_solo_led(void) {

    leds_turn_on(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 2)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_solo_led(void) {

    leds_turn_on(3);

    leds_turn_off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_2_led(void) {

    leds_turn_on(3);

    leds_turn_on(7);

    leds_turn_off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 6)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}
