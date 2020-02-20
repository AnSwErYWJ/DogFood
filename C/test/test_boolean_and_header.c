/*************************************************************************
	> File Name: test_boolean_and_header.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 14 Mar 2018 04:25:07 PM CST
 ************************************************************************/

#include "../header.h"
#include "../boolean.h"

int main(void)
{
	
	boolean t = true;
	boolean f = false;

	printf("true is %d, false is %d, enum boolean size is %ld\n", t, f, sizeof(boolean));

	return 0;
}

