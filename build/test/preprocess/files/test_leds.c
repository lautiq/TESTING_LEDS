#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"


static uint16_t virtual_port;















void setUp(void) {

    leds_init(&virtual_port);

}



void tearDown(void) {



}







void test_todos_los_leds_deben_arrancar_apagados(void) {

    uint16_t virtual_port = 0xFFFF;



    leds_init(&virtual_port);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}









void test_prender_un_solo_led(void) {

    leds_turn_on(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 2)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}











void test_prender_y_apagar_un_solo_led(void) {

    leds_turn_on(3);

    leds_turn_off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16);

}









void test_prender_y_apagar_2_led(void) {

    leds_turn_on(3);

    leds_turn_on(7);

    leds_turn_off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 6)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_HEX16);

}









void test_prender_todos_los_leds_juntos(void) {

    leds_turn_on_all();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_HEX16);

}









void test_prender_y_apagar_todos_los_leds_juntos(void) {

    leds_turn_on_all();

    leds_turn_off_all();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}









void test_preder_un_led_y_consultar_su_estado(void) {

    uint8_t status = 3;

    leds_turn_on(4);

    status = leds_status(&virtual_port, 4);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x0001)), (UNITY_INT)(UNITY_INT8 )((status)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 3)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX16);

}















void test_leds_fuera_de_rango(void) {



    leds_turn_on(-1);

    do {if (!(led_is_turned_on(-1))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(102)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX16);



    leds_turn_on(17);

    do {if (!(led_is_turned_on(17))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(106)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_HEX16);



    leds_turn_off(-1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_HEX16);



    leds_turn_off(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_port)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_HEX16);

}
