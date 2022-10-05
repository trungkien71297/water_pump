#ifndef WATERPUMP_PUMP_CONTROL_H
#define WATERPUMP_PUMP_CONTROL_H

#define ON_PUMP 1
#define OFF_PUMP 0
typedef struct
{
    /* data */
    int pin;
    int state;
} pump_control;

void turn_on_pump();
void turn_off_pump();
void set_time_pump(int time);

#endif //WATERPUMP_PUMP_CONTROL_H