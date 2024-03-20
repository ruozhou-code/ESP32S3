#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

#include "led.h"
#include "key.h"
#include "EXTI.h"
#include "usart.h"
#include "esptim.h"

void app_main(void)
{
    esp_err_t ret;
    uint8_t len = 0;
    uint16_t time = 0;
    unsigned char data[RX_BUF_SIZE] = { 0 };

    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    led_init();
    key_EXTI_init();
    usart_init(115200);
    esp_int_init(5000, 1000000);
    while (1)
    {
        uart_get_buffered_data_len(UART_NUM_0, (size_t*)&len);
        if (len > 0)
        {
            memset(data, 0, RX_BUF_SIZE);
            printf("你发送的数据是\n");
            uart_read_bytes(UART_NUM_0, data, len, 100);    /*读取数据*/
            uart_write_bytes(UART_NUM_0, (const char*)data, strlen((const char*)data));                        /*发送出去*/
        }
        else
        {
            time++;
            if (time % 5000 == 0)
            {
                printf("\n 万大神在此 谁敢作妖\n");
                printf("\n愣着干啥 去泡脚啊\n");
            }
            if (time % 200 == 0)
            {
                printf("请输入数据，以回车键结束\n");
            }
            //if (time % 30 == 0)
                //LED_TROGGLE();

        }
        vTaskDelay(10);
    }
}
