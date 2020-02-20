#!/bin/bash
#清空文件

if [ $# -ge 1 ];then
    for ((i=1;i<=$#;i=i+1))
    do
        # ! 变量的间接引用
        if [ -s ${!i} ]; then 
            : > ${!i}
            echo -e "Success : ${!i} is empty now."
        else
            echo -e "Error: ${!i} is not exist or is empty."
    fi
    done
else
    echo -e "Usage: sh $0 filename filename ..."
fi
