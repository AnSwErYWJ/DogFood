VPATH ?= .:$VPATH

ALL_SRC = ./test-implicit.c ./welcome.c ./test-explicit.c ./test-sta.c
WEL_SRC := ./welcome.c
IMP_SRC := ./test-implicit.c 
EX_SRC := ./test-explicit.c 
STA_SRC := ./test-sta.c

ALL_OBJS := $(ALL_SRC:.c=.o)
WEL_OBJS := $(WEL_SRC:.c=.o)
IMP_OBJS := $(IMP_SRC:.c=.o)
EX_OBJS := $(EX_SRC:.c=.o)
STA_OBJS := $(STA_SRC:.c=.o)

WEL_SO_TARGET := ./libwelcome.so
WEL_A_TARGET := ./libwelcome.a
IMP_TARGET := ./test-implicit
EX_TARGET := ./test-explicit
STA_TARGET := ./test-sta

CC := gcc
PLUS := g++ # 可以链接C++库
AR = ar crv
RM := -rm -rf
CFLAGS := -Wall -O2 -fPIC
IMP_LDFLAGS = -L. -lwelcome # 放在最后
EX_LDFLAGS = -ldl # 放在最后
STA_LDFLAGS = ./libwelcome.a
LDSHFLAGS = -shared
CPPFLAGS = -I./

rely := $(ALL_SRC:.c=.d) # 生成.d文件
tmp := ./*.d.*

#############################

.PHONY: so a implicit explicit sta clean 

# 生成动态库
so : $(WEL_SO_TARGET)
$(WEL_SO_TARGET): $(WEL_OBJS)
	$(PLUS) $(LDSHFLAGS) $^ -o $@

# 生成静态库
a : $(WEL_A_TARGET)
$(WEL_A_TARGET): $(WEL_OBJS)
	$(AR) $@ $^

# 隐式调用动态库
implicit : $(IMP_TARGET)
$(IMP_TARGET): $(IMP_OBJS)
	$(PLUS) $^ -o $@ $(IMP_LDFLAGS)
	-export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

# 显式调用动态库
explicit : $(EX_TARGET)
$(EX_TARGET): $(EX_OBJS)
	$(PLUS)  $^ -o $@ $(EX_LDFLAGS)

# 调用静态库
sta : $(STA_TARGET)
$(STA_TARGET): $(STA_OBJS)
	$(PLUS) $^ -o $@ $(STA_LDFLAGS)

# 自动生成依赖
$(rely): $(ALL_SRC)
	@set -e; rm -f $@ &> /dev/null; # 设置错误检查,若下面有语句执行错误则直接退出, 删除旧的.d文件\
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; # 生成依赖文件 \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; # 替换临时文件 \
	rm -f $@.$$$$ &> /dev/null # 删除临时文件

# 替换
-include $(rely)

clean:
	$(RM) $(rely) $(tmp) $(ALL_OBJS)
