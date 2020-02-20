#!/bin/bash
# 执行命令直到成功

if [ $# -le 0 ];then
    echo -e "Usage: sh $0 command"
    exit
fi

while :
do
    $@ && exit
    sleep 5
done
