#include "EXTI.h"

static void IRAM_ATTR exti_gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t)arg;
    if (gpio_num == GPIO_NUM_0)
    {
        LED_TROGGLE();
    }
}


void key_EXTI_init(void)
{
    gpio_config_t pGPIOConfig;
    pGPIOConfig.intr_type = GPIO_INTR_NEGEDGE;
    pGPIOConfig.mode = GPIO_MODE_INPUT;
    pGPIOConfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
    pGPIOConfig.pull_up_en = GPIO_PULLUP_ENABLE;
    pGPIOConfig.pin_bit_mask = 1ull << GPIO_NUM_0;
    gpio_config(&pGPIOConfig);

    /*注册中断服务函数*/
    gpio_install_isr_service(0);

    gpio_isr_handler_add(GPIO_NUM_0, exti_gpio_isr_handler, (void*)GPIO_NUM_0);
}
