#!/bin/bash

gcc -Wall -o2 -L. -llog -I ./ test.c -o test

#echo -e "generate test"

export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
./test
