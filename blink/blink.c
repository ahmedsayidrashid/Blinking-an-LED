/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include <stdbool.h>


#define BUTTON_GPIO 28
#define LED 15

int main() {

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    bool currentStatus = 0; // variable to keep track of the LED status
    stdio_init_all();
    gpio_init(BUTTON_GPIO); // initialize the button
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_down(BUTTON_GPIO); // use a pull down resistor to avoid flaots
    
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    
    while(1){
        currentStatus = gpio_get(BUTTON_GPIO) ? !currentStatus : currentStatus;
        gpio_put(LED, currentStatus);  
        gpio_put(CAPACITOR_CHARGE_GPIO, currentStatus);
        sleep_ms(500);
    }

#endif

