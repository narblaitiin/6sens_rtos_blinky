/*
 * Copyright (c) 2025
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

//  ========== includes ====================================================================
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

//  ========== defines =====================================================================
// time in milliseconds to wait between LED toggles (2000 ms = 2 seconds)
#define SLEEP_TIME_MS   2000

// device tree node identifiers for the LEDs (transmit and receive indicators)
#define LED_0 DT_ALIAS(led0)
#define LED_1 DT_ALIAS(led1)

//  ========== globals =====================================================================
// define GPIO configurations for the LEDs
static const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED_0, gpios);
static const struct gpio_dt_spec led_2 = GPIO_DT_SPEC_GET(LED_1, gpios);

//  ========== main ========================================================================
int8_t main(void)
{
	// test if GPIO is ready to use
	if ((!gpio_is_ready_dt(&led_0)) & (!gpio_is_ready_dt(&led_1))) {
        return 0;
    }

	// configure the LEDs as active output pins
	gpio_pin_configure_dt(&led_0, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_ACTIVE);

	// turn off both LEDs initially
	gpio_pin_set_dt(&led_0, 0);
	gpio_pin_set_dt(&led_1, 0);

	// infinite loop to toggle LEDs and print status
	while (1) {
		// print "Hello World" message with the board configuration name
		printk("Hello World! %s\n", CONFIG_BOARD);

		// toggle the LED and check for errors
		int8_t ret = gpio_pin_toggle_dt(&led_0);
		if (ret < 0) {
			return 0;
		}


		ret = gpio_pin_toggle_dt(&led_1);
		if (ret < 0) {
			return 0;
		}

		// wait for the defined sleep time before toggling again
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}