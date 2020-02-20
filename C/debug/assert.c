/*************************************************************************
	> File Name: assert.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Sat 16 Dec 2017 06:59:35 PM CST
 ************************************************************************/

/* 断言  */

#include <stdio.h>

/* 在引用头文件前加上NDEBUG宏，使assert不生效 */
#define NDEBUG
#include <assert.h>


int main(void)
{
    int i = 1;

    assert(i<0); // 会影响性能，只能在debug版本使用

    printf("successfully\n");
    return 0;
}
