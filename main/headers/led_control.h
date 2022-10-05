
#ifndef WATERPUMP_LED_CONTROL_H
#define WATERPUMP_LED_CONTROL_H

#define OFF_LED_LEVEL 0
#define ON_LED_LEVEL 1
typedef struct
{
    /* data */
    int led_pin;
    int led_state;
} led_info;


void config_led(int led_pin);
void toggle_led();
void turn_on();
void turn_off();
void test_led();

#endif  // WATERPUMP_LED_CONTROL_H