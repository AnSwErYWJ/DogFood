#!/bin/bash
# watch program rss (only one program)

if [ $# -ne 1 ];then
    echo -e "Usage: sh $0 processe"
    exit
fi

# get pids
pids=`pidof $1`
#echo -e ${pids}

if [ $? -ne 0 ];then
    echo -e "Usage: sh $0 Name"
    exit
fi

while :
do
    clear
    count=0
    total=0
    value=0

    echo -e "PID    RES"
    for i in $pids
    do
        echo -n -e ${i}"  "
        
        # display content
        line=`cat /proc/$i/status | grep "VmRSS" | cut -d ":" -f2 `
        
        # res value
        value=`echo ${line} | grep -o "[0-9]\+"`
        
        echo -e ${line}
 
        total=$(($total+$value))
        count=$(($count+1))
    done

    # convert kb to mb
    total=$(($total/1024))

    echo "pids conut: "${count}
    echo "RES total: "${total} MB 

    sleep 3
done

