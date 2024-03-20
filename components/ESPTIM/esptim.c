#include "esptim.h"

void esp_int_init(uint16_t arr, uint64_t tps)
{
    esp_timer_create_args_t args;
    esp_timer_handle_t out_handle;
    args.arg = NULL;
    args.callback = &esptime_cb;
    esp_timer_create(&args, &out_handle);
    esp_timer_start_periodic(out_handle, tps);
}

void esptime_cb(void* arg)
{
    LED_TROGGLE();
}