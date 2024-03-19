#ifndef __USART_H
#define __USART_H

#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/uart.h"
#include "driver/gpio.h"

#define RX_BUF_SIZE         1024    /* 环形缓冲区大小 */

void usart_init(uint32_t baudrate);


#endif // !__USART_H