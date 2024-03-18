#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

#include "led.h"
#include "key.h"

void app_main(void)
{
    led_init();
    key_init();
    while (1)
    {
        Key_Scanf();
        if (key_flag == 1)
        {
            printf("the key is pressed\r\n");
            key_flag = 0;
        }
        vTaskDelay(1);
    }
}
