#include <stdio.h>
#include "led_control.h"
#include "pin_const.h"
void app_main(void)
{
    config_led(LED_PIN);
    test_led();
}
