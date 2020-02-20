SRC = BlackBox.c 
TARGET := blackbox

CC := gcc
LOCAL_CFLAGS = -Wall -rdynamic -g -o #编译器参数
LOCAL_LDFLAGS =  #链接器参数

#############################

.PHONY:all clean
all: 
	$(CC) $(LOCAL_CFLAGS) $(TARGET) $(SRC)

clean:
	rm -rf $(TARGET)
