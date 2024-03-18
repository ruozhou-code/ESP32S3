#include "led.h"

void led_init(void)
{
    gpio_config_t pGPIOConfig;
    pGPIOConfig.mode = GPIO_MODE_INPUT_OUTPUT;
    pGPIOConfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
    pGPIOConfig.pull_up_en = GPIO_PULLUP_ENABLE;
    pGPIOConfig.pin_bit_mask = 1ull << GPIO_NUM_1;
    pGPIOConfig.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&pGPIOConfig);

    LED(0);
}