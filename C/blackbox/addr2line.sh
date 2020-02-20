#!/bin/bash

# 将函数地址转换为行数

addr2line -e $1 $2 -f

if (($? != 0));then
    echo -e "Usage: ./addr2line.sh execute_file addr"
fi


