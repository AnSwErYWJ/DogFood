/*************************************************************************
	> File Name: test_check_argument.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 14 Mar 2018 07:33:26 PM CST
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	if (check_argument(argc, argv) == 0)
		printf("check argument(s) success\n");
	else
		printf("check argument(s) fail\n");

	return 0;
}
