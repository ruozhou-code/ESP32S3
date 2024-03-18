#include "key.h"
uint8_t key_flag = 0;

void key_init(void)
{
    gpio_config_t pGPIOConfig;
    pGPIOConfig.mode = GPIO_MODE_INPUT;
    pGPIOConfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
    pGPIOConfig.pull_up_en = GPIO_PULLUP_ENABLE;
    pGPIOConfig.pin_bit_mask = 1ull << GPIO_NUM_0;
    pGPIOConfig.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&pGPIOConfig);
}

void Key_Scanf(void)
{
    if (KEY_Read() == 0)
    {
        vTaskDelay(10);
        if (KEY_Read() == 0)
        {
            while (KEY_Read() == 1);
            vTaskDelay(10);
            if (KEY_Read() == 1)
            {
                key_flag = 1;
            }
        }
    }
    else {
        key_flag = 0;
    }

}