#!/bin/bash

# way 1
if [ $UID -ne 0 ];then
    echo "Current user is not root."
else
    echo "Current user is root."
fi

# way 2
test=$(env | grep USER | cut -d "=" -f 2)

if [ "$test" == "root" ];then
    echo "Current user is root."
else
    echo "Current user is not root."
fi
