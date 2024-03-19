#include "usart.h"

void usart_init(uint32_t baudrate)
{
    uart_config_t uart_config;
    uart_config.baud_rate = baudrate;
    uart_config.data_bits = UART_DATA_8_BITS;
    uart_config.parity = UART_PARITY_DISABLE;
    uart_config.stop_bits = UART_STOP_BITS_1;
    uart_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
    uart_config.source_clk = UART_SCLK_APB;
    uart_config.rx_flow_ctrl_thresh = 122;
    uart_param_config(UART_NUM_0, &uart_config);

    /*配置uart引脚*/
    uart_set_pin(UART_NUM_0, GPIO_NUM_43, GPIO_NUM_44, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    /*安装串口驱动*/
    uart_driver_install(UART_NUM_0, RX_BUF_SIZE * 2, RX_BUF_SIZE * 2, 20, NULL, 0);
}