#ifndef __LED_H
#define __LED_H

#include "driver/gpio.h"

enum LED_Stature {
    PIN_RESET,
    PIN_SET
};

#define LED(x) {x?gpio_set_level(GPIO_NUM_1,PIN_SET):gpio_set_level(GPIO_NUM_1,PIN_RESET);}
#define LED_TROGGLE()   {gpio_set_level(GPIO_NUM_1,!gpio_get_level(GPIO_NUM_1));}

void led_init(void);

#endif // !__LED_H