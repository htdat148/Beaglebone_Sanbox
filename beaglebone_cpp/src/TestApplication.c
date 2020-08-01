/*
 * TestApplication.cpp
 *
 *  Created on: Jul 28, 2020
 *      Author: dathuynh
 */

#include "../inc/SimpleGPIO.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

unsigned int LEDGPIO = 60;
unsigned int ButtonGPIO = 20;

int main(int argc, char **argv)
{
	printf("Testing the GPIO Pins \n");
	gpio_export(LEDGPIO);
	gpio_export(ButtonGPIO);
	gpio_set_dir(LEDGPIO, OUTPUT_PIN);
	gpio_set_dir(ButtonGPIO, INPUT_PIN);


	//Flash the LED 5 times
	int i = 0;
	for(i=0; i<5; i++)
	{
		printf("Setting led on\n");
		gpio_set_value(LEDGPIO, HIGH);
		usleep(500000);
		printf("Setting led off\n");
		gpio_set_value(LEDGPIO, LOW);
		usleep(500000);
	}

	//wait for press the button
	printf("Please press the button!\n");

	unsigned int value = LOW;
	do {
		gpio_get_value(ButtonGPIO, &value);
		usleep(1000);
	}
	while(value != HIGH);

	printf("\nButton was just released\n");

	printf("Finish testing the GPIO Pins");

	gpio_unexport(LEDGPIO);
	gpio_unexport(ButtonGPIO);
	return 0;
}
