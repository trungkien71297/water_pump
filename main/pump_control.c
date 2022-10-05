#include "pump_control.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

pump_control pump;

void configure_pump(int pin) {
    pump.pin = pin;
    pump.state = 0;
    gpio_pad_select_gpio(pump.pin);
    gpio_set_direction(pump.pin, GPIO_MODE_OUTPUT);
    gpio_set_level(pump.pin, OFF_PUMP);
}

void turn_on_pump() {
    pump.state = ON_PUMP;
    gpio_set_level(pump.pin, ON_PUMP);
}

void turn_off_pump() {
    pump.state = OFF_PUMP;
    gpio_set_level(pump.pin, OFF_PUMP);
}

void set_time_pump(int time) {
    turn_on_pump();
    vTaskDelay(1500/portTICK_PERIOD_MS);
    turn_off_pump();
}