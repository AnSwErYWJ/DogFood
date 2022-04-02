/*************************************************************************
	> File Name: typeof.h
	> Author: weijie.yuan
	> Mail: weijie.yuan@aispeech.com
	> Created Time: 2022年04月02日 星期六 15时02分08秒
 ************************************************************************/

#ifndef __TYPEOF__H
#define __TYPEOF__H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 利用 typeof 关键字进行变量与函数类型检查，若不匹配，编译时会有 warning 信息。
 * typeof 不是C语言本身的关键字或运算符，它是 GCC 的一个扩展。
 */

/*
 * int a;
 * a. pass
 *   typecheck(int, a);
 * b. pass
 *   typecheck(long, a);
 * c. warning: comparison of distinct pointer types lacks a cast
 *   typecheck(char, a);
 * 
 * int test() {
 *  return 0;
 * }
 * 
 * a. pass
 *   typecheck_fn(int (*)(), test);
 * b. warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]
 *   typecheck_fn(long (*)(), test);
 */

/*
 * Check at compile time that something is of a particular type.
 * Always evaluates to 1 so you may use it easily in comparisons.
 */
#define typecheck(type,x) \
({  type __dummy; \
    typeof(x) __dummy2; \
    (void)(&__dummy == &__dummy2); \
    1; \
})
 
/*
 * Check at compile time that 'function' is a certain type, or is a pointer
 * to that type (needs to use typedef for the function type.)
 */
#define typecheck_fn(type,function) \
({  typeof(type) __tmp = function; \
    (void)__tmp; \
})

#ifdef __cplusplus
}
#endif

#endif
