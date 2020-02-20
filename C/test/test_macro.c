/*************************************************************************
	> File Name: test_macro.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 15 Mar 2018 06:22:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include "../macro.h"

#define N 999

int main(void)
{
	printf("N tostring is %s\n", tostring(N));

	return 0;
}