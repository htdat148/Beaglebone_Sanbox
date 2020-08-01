#
# File:   Makefile
# Author: Dat Huynh (gibsonk@cis)
# Desc:   Makefile for Fall 2014 livecoding: SimpleGPIOmorphism
#
################################
####Remote host information#####
################################
REMOTE_DIR := ~/zhuydat/sandbox/
REMOTE_USER := debian@192.168.1.95

INCPATH := ./inc
SRCPATH := ./src
OBJPATH := ./out
APPPATH := ./app
OBJS = 	SimpleGPIO.o TestApplication.o

CC := arm-linux-gnueabihf-gcc
CFLAGS := -g -Wall -Werror  -I$(INCPATH)
TARGET := TestApplication




all: $(TARGET) putobj putapp

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^


%.o : $(SRCPATH)/%.c $(INCPATH)/SimpleGPIO.h
	${CC} -c $(CFLAGS) $(SRCPATH)/$*.c

# SimpleGPIO.o: $(INCPATH)/SimpleGPIO.h
# 	${CC} -c $(CFLAGS) $(SRCPATH)/SimpleGPIO.c

# TestApplication.o: $(INCPATH)/SimpleGPIO.h
# 	${CC} -c $(CFLAGS) $(SRCPATH)/TestApplication.c

putapp:
	mv $(TARGET) $(APPPATH)
putobj:
	mv ./*.o $(OBJPATH)
clean:
	-@rm $(OBJPATH)/* $(APPPATH)/* 

send:
	scp $(APPPATH)/$(TARGET) $(REMOTE_USER):$(REMOTE_DIR)
