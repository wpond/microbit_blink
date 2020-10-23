#ifndef LED_H
#define LED_H

#include <stdint.h>

void led_init();
void led_on(uint8_t x, uint8_t y);
void led_off(uint8_t x, uint8_t y);

#endif