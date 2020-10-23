#include "led.h"

#include "nrf.h"


typedef struct
{
    uint8_t row;
    uint8_t col;
} LED_t;


void map(uint8_t index, LED_t* led)
{
    switch(index)
    {
    case 0:
        led->row = 13;
        led->col = 4;
        return;
    case 1:
        led->row = 13;
        led->col = 5;
        return;
    case 2:
        led->row = 13;
        led->col = 6;
        return;
    case 3:
        led->row = 13;
        led->col = 7;
        return;
    case 4:
        led->row = 13;
        led->col = 8;
        return;
    case 5:
        led->row = 13;
        led->col = 9;
        return;
    case 6:
        led->row = 13;
        led->col = 10;
        return;
    case 7:
        led->row = 13;
        led->col = 11;
        return;
    case 8:
        led->row = 13;
        led->col = 12;
        return;
        
    case 9:
        led->row = 14;
        led->col = 4;
        return;
    case 10:
        led->row = 14;
        led->col = 5;
        return;
    case 11:
        led->row = 14;
        led->col = 6;
        return;
    case 12:
        led->row = 14;
        led->col = 7;
        return;
    case 13:
        led->row = 14;
        led->col = 8;
        return;
    case 14:
        led->row = 14;
        led->col = 9;
        return;
    case 15:
        led->row = 14;
        led->col = 10;
        return;
        
    case 16:
        led->row = 15;
        led->col = 4;
        return;
    case 17:
        led->row = 15;
        led->col = 5;
        return;
    case 18:
        led->row = 15;
        led->col = 6;
        return;
    case 19:
        led->row = 15;
        led->col = 7;
        return;
    case 20:
        led->row = 15;
        led->col = 8;
        return;
    case 21:
        led->row = 15;
        led->col = 9;
        return;
    case 22:
        led->row = 15;
        led->col = 10;
        return;
    case 23:
        led->row = 15;
        led->col = 11;
        return;
    case 24:
        led->row = 15;
        led->col = 12;
        return;
    }

}


void led_init()
{
    LED_t led;

    led.row = 13;
    led.col = 4;

    // NRF_GPIO->DIRSET = (1<<led.row) | (1<<led.col);
    // NRF_GPIO->OUTCLR = 1<<led.col;

    uint32_t dir = 0;
    for (uint8_t i = 4; i <= 15; ++i)
    {
        dir |= (1 << i);
    }

    NRF_GPIO->DIRSET = dir;

    NRF_GPIO->OUTSET = (1 << 13) | (1 << 14) | (1 << 15);

    uint32_t clr = 0;
    for (uint8_t i = 4; i < 13; ++i)
    {
        clr |= (1 << i);
    }
    NRF_GPIO->OUTSET = clr;
}


void led_on(uint8_t x, uint8_t y)
{
    // const uint8_t index = (5 * x) + y;
    LED_t led;

    led.row = 13;
    led.col = 4;

    // map(index, &led);

    NRF_GPIO->OUTSET = 1<<led.col;
    
}

void led_off(uint8_t x, uint8_t y)
{
    // const uint8_t index = (5 * x) + y;
    LED_t led;

    led.row = 13;
    led.col = 4;

    // map(index, &led);    

    NRF_GPIO->OUTCLR =  1<<led.col;
}
