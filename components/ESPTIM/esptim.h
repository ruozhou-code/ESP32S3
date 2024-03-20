#ifndef __ESPTIM_H
#define __ESPTIM_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "led.h"

void esp_int_init(uint16_t arr, uint64_t tps);
void esptime_cb(void* arg);

#endif // !__ESPTIM_H