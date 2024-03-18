#ifndef __KEY_H
#define __KEY_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern uint8_t key_flag;

#define KEY_Read() gpio_get_level(GPIO_NUM_0)

void key_init(void);
void Key_Scanf(void);

#endif // !__KEY_H