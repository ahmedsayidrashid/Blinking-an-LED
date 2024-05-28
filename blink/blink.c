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

#define CAPACITOR_CHARGE_GPIO 13

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    bool currentStatus = 0; // to get the status of the LED
    stdio_init_all();
    gpio_init(BUTTON_GPIO); // initialize the button
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_down(BUTTON_GPIO); // was up before
    
    const int LED_PIN = PICO_DEFAULT_LED_PIN; // initilaize the LED
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_init(CAPACITOR_CHARGE_GPIO);
    gpio_set_dir(CAPACITOR_CHARGE_GPIO, GPIO_OUT);
    
    while(1){
        currentStatus = gpio_get(BUTTON_GPIO) ? !currentStatus : currentStatus;
        gpio_put(LED, currentStatus);  
        gpio_put(CAPACITOR_CHARGE_GPIO, currentStatus);
        sleep_ms(500);
    }

#endif
} 
/*k
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const int LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(2050);
        printf("Hello");
    }
    */


