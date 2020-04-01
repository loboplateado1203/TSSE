#include <stdint.h>

void Leds_Create (uint16_t *puerto);//declaro el prototipo

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);

void Leds_AllOn( void );

void Leds_AllOff( void );

uint8_t Leds_State(uint8_t led);