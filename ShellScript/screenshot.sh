#!/bin/bash
# screenshot

function tips()
{
    echo -e "Usage: sh $0 0|1|2|3|4 [delay second(s)]";
    echo -e "Option:"
    echo -e "0: full screen \n1:current terminal \n2:custom screen(unsupport delay seconds) \n3:current terminal without head";
    exit;
}

# check argc
if [ $# -ne 1 -a $# -ne 2 ];then
    tips
fi

# set argv 1
case $1 in
    0)
        FLAGS="";; 
    1)
        FLAGS="-w";; 
    2)
        FLAGS="-a";; 
    3)
        FLAGS="-w -B";; 
    *)
        tips;;
esac

# set argv 2 and option 2 unsupport [delay seconds]
if [ $# -eq 2 ]
then
    if [ $1 -ne 2  ];then
        FLAGS=${FLAGS}" ""-d"" "$2    
        echo $FLAGS
    else
        echo -e "ERROR: option 2 unsupport [seconds]"
        exit
    fi
fi

gnome-screenshot $FLAGS
