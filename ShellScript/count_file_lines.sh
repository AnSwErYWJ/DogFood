#!/bin/bash
#统计文本有几行数
if (($# != 1));then
    echo -e "Usage: sh $0 filename"
    exit
fi

lines=`awk 'END{ print NR }' $1`

echo -e $0" has "${lines}" lines."
