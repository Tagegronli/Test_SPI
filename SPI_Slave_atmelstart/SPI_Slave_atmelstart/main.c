#include <atmel_start.h>
#include <stdlib.h>
#include <stdio.h>
#include <atmel_start_pins.h>


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	uint8_t data = 4;
	SPI_0_init();
	/* Replace with your application code */
	_gpio_set_direction(GPIO_PORTC, 0b1000000000, GPIO_DIRECTION_OUT);
	_gpio_set_direction(GPIO_PORTB, 0b100, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(PB2, GPIO_DIRECTION_IN);
	
	gpio_set_pin_level(PC9, true);
	while (1) {
		delay_ms(100);
		struct io_descriptor *io;
		spi_s_sync_get_io_descriptor(&SPI_0, &io);
		spi_s_sync_enable(&SPI_0);
		io_read(io, &data, 1);
		
		
		if (data == 69)
		{
			gpio_toggle_pin_level(PC9);
		}
	}
}
