/*************************************************************************
	> File Name: macro.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 15 Mar 2018 06:07:28 PM CST
 ************************************************************************/

#ifndef _MACRO_H
#define _MACRO_H

/* reference: http://blog.csdn.net/lhf_tiger/article/details/9086049 */
#define tostring_1(x) #x
#define tostring(x) tostring_1(x)

/* -DBUG */
#if defined BUG
#warning this is bug //抛出警告信息，编译继续
#error this is bug //抛出错误信息，编译停止
#endif

#endif
