#!/bin/bash

# define associative array
declare -A keys #
keys=(
# function keys
[menu]=1
[unlock]=82
[up]=19
[down]=20
[left]=21
[right]=22
[back]=4
[tab]=61
[home]=3
[space]=62
[enter]=66
[delete]=67
[explorer]=64
[search]=84
[power]=26
[volume_up]=24
[volume_down]=25

# number keys
[zero]=7
[one]=8
[two]=9
[three]=10
[four]=11
[five]=12
[six]=13
[seven]=14
[eight]=15
[nine]=16

# character keys
[a]=29
[b]=30
[c]=31
[d]=32
[e]=33
[f]=34
[g]=35
[h]=36
[i]=37
[j]=38
[k]=39
[l]=40
[m]=41
[n]=42
[o]=43
[p]=44
[q]=45
[r]=46
[s]=47
[t]=48
[u]=49
[v]=50
[w]=51
[x]=52
[y]=53
[z]=54
[,]=55
[.]=56
[-]=69
[star]=17 #*
[=]=70
[backslash]=73 #\
[semicolon]=74 #;
[apostrophe]=75 #"'"
[slash]=76 #/
[at]=77 #@
[+]=81 
)

# limit
ceil=85
floor=0

echo -e "# function keys: [menu],[unlock],[up],[down],[left],[right],[back],[tab],[home],[space],[enter],[delete],[explorer],[search],[power],[volume_up],[volume_down]
# number keys:[zero],[one],[two],[three],[four],[five],[six],[seven],[eight],[nine]
# character keys: [a],[b],[c],[d],[e],[f],[g],[h],[i],[j],[k],[l],[m],[n],[o],[p],[q],[r],[s],[t],[u],[v],[w],[x],[y],[z],[,],[.],[-],[star],[=],[backslash],[semicolon],[apostrophe],[slash],[at],[+] 
"
case $# in
    1)
        loops=1;;
    2)
        # judge if number
        expr $2 + 0 &> /dev/null
        
        if [ $? -eq 0 -a $2 -gt 0 ];then
            loops=$2
        else
            echo -e "Error : correct loops is gt 0."
            exit
        fi;;
    *)
        echo -e "Usage : $0 <keyboard_code> [loops]."
        exit;;
esac

# judge if in keys
if [[ "${!keys[@]}" =~ "$1" ]];then
    expr ${keys[$1]} + 0 &> /dev/null
    
    if [[ $? -eq 0 ]];then
        for i in `seq 1 $loops`;do
            adb shell input keyevent ${keys[$1]}
        done
    else
        echo -e "Error:please input right code between [0-85] or defined keys."
    fi

else
    expr $1 + 0 &> /dev/null 
    
    if [ $? -eq 0 ];then
        if [ $1 -ge $floor -a $1 -le $ceil ];then
            for i in `seq 1 $loops`;do
                adb shell input keyevent $1
            done
        else
            echo -e "Error:please input right code between [0-85] or defined keys."
        fi
    else
        echo -e "Error:please input right code between [0-85] or defined keys."
    fi
fi

