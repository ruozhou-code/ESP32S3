#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

#include "led.h"
#include "key.h"
#include "EXTI.h"

void app_main(void)
{
    led_init();
    key_EXTI_init();
    while (1)
    {
        vTaskDelay(1);
    }
}
