/*
• >> 1 Después de la inicialización todos los LEDs deben quedar apagados.
• >> 2 Se puede prender un LED individual.
• >> 3 Se puede apagar un LED individual.
• >> 4 Se pueden prender y apagar múltiples LED’s.
• >> 5 Se pueden prender todos los LEDs de una vez.
• >> 6 Se pueden apagar todos los LEDs de una vez.
• >> 7 Se puede consultar el estado de un LED.
*/
#include "unity.h"
#include "leds.h"

static uint16_t ledsVirtuales;


void setUp(void){//Funcion que se ejecuta al inicio de todos los test
	Leds_Create(&ledsVirtuales);
}

void tearDown(void){
}
//************************** Mensaje de error ********************************
/*void test_Leds0ffAfterCreateError(void){//arrancan apagados
		
		//uint16_t ledsVirtuales = 0xFFFF;//  remplaza la variable de 16 bits el gpio
		//Leds_Create(&ledsVirtuales);    // se pasa la direccion del puerto gpio
		TEST_FAIL_MESSAGE("EMPEZAMOS");//esta linea hace que el test falle y escribe el mensaje
		
}*/
//*****************************************************************************

void test_Leds0ffAfterCreate(void){
		uint16_t ledsVirtuales = 0xFFFF;
		Leds_Create(&ledsVirtuales);  
		TEST_ASSERT_EQUAL(0, ledsVirtuales);
}
//***************** 2 Se puede prender el led individual **************************

void test_IndividualLedOn(void){
		const uint8_t led = 3;// int led = 3;
		Leds_On(led);//Leds_On (3);
		TEST_ASSERT_EQUAL(1 << (led - 1), ledsVirtuales);//TEST_ASSERT_EQUAL (1 << (3 -1)), ledsVirtuales);
}
//******************* 3 Se puede apagar un led individual ***************************

void test_IndividualLedOnOff(void){
		const uint8_t led = 3;
		Leds_On(led);
		Leds_Off(led);
		TEST_ASSERT_EQUAL (0,ledsVirtuales);
}
//******************** 4 Se puede prender y apagar varios leds*************************

void test_Multipleleds(void){
		const uint8_t led =3;
		Leds_On(2);
		Leds_On(5);
		Leds_Off(2);
		TEST_ASSERT_EQUAL (1<<(5-1),ledsVirtuales);
}
//***************** 5 Se puede prender todos los leds **************************

void test_AllLedsOn(void)
{
		Leds_AllOn();
		TEST_ASSERT_EQUAL ( 0xFFFF, ledsVirtuales );
}

//******************* 6 Se puede apagar todos los leds ***************************
void test_AllLedsOff(void)
{
		Leds_AllOff();
		TEST_ASSERT_EQUAL ( 0, ledsVirtuales );
}


//******************* 7 Se puede consultar el estado de un LED.********************

void test_LedsState(void)
{
		Leds_On(2);
		Leds_Off(3);
		TEST_ASSERT_EQUAL ( 1, Leds_State( 2 ) );
		TEST_ASSERT_EQUAL ( 0, Leds_State( 3 ) );

}
