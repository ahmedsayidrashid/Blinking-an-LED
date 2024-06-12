/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define LED 15

void main() {
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_set_function(LED, GPIO_FUNC_PWM); // set the LED as the pwm output
    uint slice_num = pwm_gpio_to_slice_num(LED); // get the pwm channel of this specific GPIO
    pwm_set_enabled(slice_num, 1); 
    int duty_factor = 10; // variable to manipulate the duty factor
    int clock_divider = 12500; // a divider to set the frequency. (125000000/12500 = 10 kHz)
    pwm_set_wrap(slice_num, clock_divider); // set the wrap point of the specific pwm channel
    pwm_set_chan_level(slice_num, 1, duty_factor);
    while(1){
        if(duty_factor < clock_divider){ // increment duty cycle
            duty_factor += 10;
            pwm_set_chan_level(slice_num, 1, duty_factor);
        }
        else{ // at this point, duty cylce is 100%, so loop until its zero.
            while(duty_factor > 10){
                duty_factor -= 10;
                pwm_set_chan_level(slice_num, 1, duty_factor);
            }
        }
        sleep_ms(5); // sleep 5 milliseconds before changing the duty cycle again.
        tight_loop_contents();
    }
}
