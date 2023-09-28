#!/bin/bash

## list files in current dir.

for target in $(ls)
do
    if [ -f $target ];then
        echo "file: "$target
    elif [ -d $target ];then
        echo "dir: "$target
    elif [ -L $target ];then
        echo "soft link: "$target
    fi
done

########################################
# [ -b FILE ] 如果 FILE 存在且是一个块特殊文件则为真。
# [ -c FILE ] 如果 FILE 存在且是一个字特殊文件则为真。
# [ -d DIR ] 如果 FILE 存在且是一个目录则为真。
# [ -e FILE ] 如果 FILE 存在则为真。
# [ -f FILE ] 如果 FILE 存在且是一个普通文件则为真。
# [ -g FILE ] 如果 FILE 存在且已经设置了SGID则为真。
# [ -k FILE ] 如果 FILE 存在且已经设置了粘制位则为真。
# [ -p FILE ] 如果 FILE 存在且是一个名字管道(F如果O)则为真。
# [ -r FILE ] 如果 FILE 存在且是可读的则为真。
# [ -s FILE ] 如果 FILE 存在且大小不为0则为真。
# [ -t FD ] 如果文件描述符 FD 打开且指向一个终端则为真。
# [ -u FILE ] 如果 FILE 存在且设置了SUID (set user ID)则为真。
# [ -w FILE ] 如果 FILE存在且是可写的则为真。
# [ -x FILE ] 如果 FILE 存在且是可执行的则为真。
# [ -O FILE ] 如果 FILE 存在且属有效用户ID则为真。
# [ -G FILE ] 如果 FILE 存在且属有效用户组则为真。
# [ -L FILE ] 如果 FILE 存在且是一个符号连接则为真。
# [ -N FILE ] 如果 FILE 存在 and has been mod如果ied since it was last read则为真。
# [ -S FILE ] 如果 FILE 存在且是一个套接字则为真。
# [ FILE1 -nt FILE2 ] 如果 FILE1 has been changed more recently than FILE2, or 如果 FILE1 exists and FILE2 does not则为真。
# [ FILE1 -ot FILE2 ] 如果 FILE1 比 FILE2 要老, 或者 FILE2 存在且 FILE1 不存在则为真。
# [ FILE1 -ef FILE2 ] 如果 FILE1 和 FILE2 指向相同的设备和节点号则为真。
########################################