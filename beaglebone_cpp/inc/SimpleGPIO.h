/*
 * SimpleGPIO.h
 *
 *  Created on: Jul 28, 2020
 *      Author: dathuynh
 */

#ifndef INC_SIMPLEGPIO_H_
#define INC_SIMPLEGPIO_H_

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3*1000) // 3 seconds
#define MAX_BUF 64
#define SYSFS_OMAP_MUX_DIR "/sys/kernel/debug/omap_mux/"

typedef enum{
	INPUT_PIN = 0,
	OUTPUT_PIN = 1
} PIN_DIRECTION;


typedef enum{
	LOW = 0,
	HIGH = 1
} PIN_VALUE;

/****************************************************************
 * gpio_export
 ****************************************************************/
int gpio_export(unsigned int gpio);
int gpio_unexport(unsigned int gpio);
int gpio_set_dir(unsigned int gpio, PIN_DIRECTION out_flag);
int gpio_set_value(unsigned int gpio, PIN_VALUE value);
int gpio_get_value(unsigned int gpio, unsigned int *value);
int gpio_set_edge(unsigned int gpio, char *edge);
int gpio_fd_open(unsigned int gpio);
int gpio_fd_close(int fd);

#endif /* INC_SIMPLEGPIO_H_ */
