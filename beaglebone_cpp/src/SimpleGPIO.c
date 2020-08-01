/*
 * SimpleGPIO.cpp
 *
 *  Created on: Jul 28, 2020
 *      Author: dathuynh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#include "../inc/SimpleGPIO.h"
/****************************************************************
 * gpio_export
 ****************************************************************/
int gpio_export(unsigned int gpio){
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if(fd < 0)
	{
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	printf("\n export - gpio%d success\n", gpio);
	close(fd);
	return 0;
}


/****************************************************************
 * gpio_export
 ****************************************************************/
int gpio_unexport(unsigned int gpio)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
	if (fd < 0)
	{
		perror("gpio/unexport");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	printf("\n unexport - gpio%d success\n", gpio);

	close(fd);
	return 0;
}


/****************************************************************
 * gpio_set_dir
 ****************************************************************/
int gpio_set_dir(unsigned int gpio, PIN_DIRECTION out_flag)
{
	 int fd;
	 char buf[MAX_BUF];

	 snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/direction", gpio);
	 printf("\n direction: %s\n",buf);
	 fd = open(buf, O_WRONLY);
	 if(fd < 0){
		 perror("gpio/direction");
		 return fd;
	 }

	 if (out_flag == OUTPUT_PIN)
		 write(fd, "out", 4);
	 else
		 write(fd, "in", 3);

	 close(fd);
	 return 0;
}


/****************************************************************
 * gpio_set_value
 ****************************************************************/
int gpio_set_value(unsigned int gpio, PIN_VALUE value)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);
	printf("\n direction: %s\n",buf);
	fd = open(buf, O_WRONLY);
	if(fd < 0)
	{
		perror("gpio/set-value");
		return fd;
	}

	if (value == LOW)
		write(fd, "0", 2);
	else
		write(fd, "1", 2);

	close(fd);
	return 0;

}
/****************************************************************
 * gpio_get_value
 ****************************************************************/
int gpio_get_value(unsigned int gpio, unsigned int *value){
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY);

	if(fd < 0)
	{
		perror("gpio/get-value");
		return fd;
	}

	read(fd, &ch, 1);

	if (ch != '0')
		*value = 1;
	else
		*value = 0;

	close(fd);
	return 0;
}

/****************************************************************
* gpio_set_edge
****************************************************************/
int gpio_set_edge(unsigned int gpio, char *edge){
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/edge", gpio);

	fd = open(buf, O_RDONLY);
	if( fd < 0)
	{
		perror("gpio/set-edge");
		return fd;
	}

	write(fd, edge, strlen(edge) +1);
	close(fd);
	return 0;
}

/****************************************************************
 * gpio_fd_open
 ****************************************************************/
int gpio_fd_open(unsigned int gpio)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY | O_NONBLOCK);
	if(fd < 0)
	{
		perror("gpio/fd_open");
		return fd;
	}
	return fd;
}

/****************************************************************
 * gpio_fd_close
 ****************************************************************/
int gpio_fd_close(int fd)
{
	return close(fd);
}
