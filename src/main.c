#include "nrf.h"

#include "stdint.h"

#include "led.h"



void dummy(unsigned int x) {
    asm volatile("nop");
}

void sleep(uint8_t i)
{
    for(unsigned int ra=0; ra<500000 * i; ra++) dummy(ra);
}


void _start() {
    led_init();
    while(1)
    {
        led_on(1, 1);
        sleep(5);
        led_off(1, 1);
        sleep(1);
    }
}
