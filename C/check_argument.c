/*************************************************************************
	> File Name: check_argument.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月29日 星期三 15时26分00秒
 ************************************************************************/

/*
 *命令行参数实例
 */

#include <stdio.h>


int check_argument(int argc, const char *argv[])
{
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s arguments\n", argv[0]);
        return -1;
    }

    for (i = 0; argv[i] != NULL; i++)
        printf("argv[%d]:%s\n", i, argv[i]);

    return 0;
}