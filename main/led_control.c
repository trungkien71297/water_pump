#include "led_control.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

led_info led_notification;
void config_led(int led_pin) {
    led_notification.led_pin = led_pin;
    led_notification.led_state = 0;
    gpio_pad_select_gpio(led_notification.led_pin);
    gpio_set_direction(led_notification.led_pin, GPIO_MODE_OUTPUT);
    gpio_set_level(led_notification.led_pin, OFF_LED_LEVEL);
}

void toggle_led() {
    led_notification.led_state ^= led_notification.led_state;
    gpio_set_level(led_notification.led_pin, led_notification.led_state);
}

void turn_off() {
    led_notification.led_state = OFF_LED_LEVEL;
    gpio_set_level(led_notification.led_pin, led_notification.led_state);
}

void turn_on() {
    led_notification.led_state = ON_LED_LEVEL;
    gpio_set_level(led_notification.led_pin, ON_LED_LEVEL);
}

void test_led() {
    while(true) {
        toggle_led();
        vTaskDelay(1500/portTICK_PERIOD_MS);
    }
}