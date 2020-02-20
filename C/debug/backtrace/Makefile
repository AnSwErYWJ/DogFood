VPATH ?= .:$VPATH

SRC = ./main.c

TARGET := ./bt

CC := gcc
RM := -rm -rf
CFLAGS := -g -I . -rdynamic

#############################

.PHONY: all clean 

all : 
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

clean:
	$(RM) $(TARGET)
