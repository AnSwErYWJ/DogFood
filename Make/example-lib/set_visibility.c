/*
 * @Author: weijie.yuan 
 * @Date: 2018-02-26 16:31:13 
 * @Last Modified by: weijie.yuan
 * @Last Modified time: 2018-02-26 17:29:19
 */

#include <stdio.h>

/* visible */
#define EXPORT __attribute ((visibility("default")))

EXPORT void test1()
{
    printf("This is test1\n");
}

void test2()
{
    printf("This is test2\n");
}

/*
 * gcc -shared -fvisibility=hidden -fPIC -o libtest.so set_visibility.c
 */