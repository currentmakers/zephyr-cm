#include <errno.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/init.h>

static int shield_clear_spi_bus(void)
{
	const struct device *tca = DEVICE_DT_GET(DT_NODELABEL(tca6424));

	if (!device_is_ready(tca)) {
		return -ENODEV;
	}

	for (int i = 16; i <= 23; i++) {
		int ret = gpio_pin_configure(tca, i, GPIO_OUTPUT_HIGH);
		if (ret < 0) {
			return ret;
		}
	}

	printk("Shield: SPI CS pins forced HIGH (inactive)\n");
	return 0;
}

SYS_INIT(shield_clear_spi_bus, POST_KERNEL, 84);
