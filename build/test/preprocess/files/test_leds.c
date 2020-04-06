#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;





void setUp(void){

 Leds_Create(&ledsVirtuales);

}



void tearDown(void){

}

void test_Leds0ffAfterCreate(void){

  uint16_t ledsVirtuales = 0xFFFF;

  Leds_Create(&ledsVirtuales);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}





void test_IndividualLedOn(void){

  const uint8_t led = 3;

  Leds_On(led);

  UnityAssertEqualNumber((UNITY_INT)((1 << (led - 1))), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

}





void test_IndividualLedOnOff(void){

  const uint8_t led = 3;

  Leds_On(led);

  Leds_Off(led);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}





void test_Multipleleds(void){

  const uint8_t led =3;

  Leds_On(2);

  Leds_On(5);

  Leds_Off(2);

  UnityAssertEqualNumber((UNITY_INT)((1<<(5-1))), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedsOn(void)

{

  Leds_AllOn();

  UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedsOff(void)

{

  Leds_AllOff();

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}









void test_Leds_State(void)

{

  Leds_On(2);

  Leds_Off(3);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Leds_State( 2 ))), (

 ((void *)0)

 ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Leds_State( 3 ))), (

 ((void *)0)

 ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);



}

void test_Leds_StateOn(void)

{

  Leds_On(2);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Leds_StateOn( 2 ))), (

 ((void *)0)

 ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);



}

void test_Leds_StateOff(void)

{

  Leds_Off(3);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Leds_StateOff( 3 ))), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);



}
