#!/bin/bash
# top your programs (multiple program)

# get pids from multiple argv

if [ $# -le 1 ];then
    echo -e "Usage: sh $0 secs program(s)"
    exit
fi

flag=0
for i in $*
do
    if [ $flag -eq 0 ];then
        flag=$(($flag+1))
        continue
    fi

    tmp=`pidof $i`
    pids=${tmp}" "${pids}
done

# add "," to pids
pids=`echo -e ${pids} | sed 's/\s/,/g'`
#echo -e ${pids}

top -d $1 -p ${pids}

if [ $? -ne 0 ];then
    echo -e "Error: invaild arguments"
    exit
fi
