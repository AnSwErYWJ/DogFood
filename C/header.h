/*************************************************************************
	> File Name: header.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 14 Dec 2017 03:57:36 PM CST
 ************************************************************************/

/*
 * 头文件作用：
 * 1. 提供接口给使用者
 * 2. 加强类型安全检查。如果某个接口在实现或者使用时，其方式与头文件中声明的不一致，编译器就会报错
 */


/* 防止头问见被重复引用 */
#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h> // 编译器将从标准库目录开始搜索
#include "boolean.h" // 编译器将从当前目录下搜索，再到标准库目录搜索


/* APIS for test/test_xxxxxxxxx.c */
int check_argument(int argc, const char *argv[]);

#endif

