/*
 * Copyright (c) 2024 CurrentMakers
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

/* PA15 is IO_RST on the MCU connector. 
 * We must set it HIGH as early as possible (before I2C devices initialize) 
 * so the carrier board mux/expanders can communicate.
 */

static int colibri_mcu3_board_init(void)
{
	const struct device *gpioa = DEVICE_DT_GET(DT_NODELABEL(gpioa));

	if (!device_is_ready(gpioa)) {
		return -ENODEV;
	}

	/* PA15: Release reset on the carrier board */
	gpio_pin_configure(gpioa, 15, GPIO_OUTPUT_HIGH);

	return 0;
}

/* Run very early to release carrier reset before POST_KERNEL bus/device init. */
SYS_INIT(colibri_mcu3_board_init, POST_KERNEL, CONFIG_GPIO_INIT_PRIORITY);
