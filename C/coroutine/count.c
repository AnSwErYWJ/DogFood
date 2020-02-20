/*************************************************************************
	> File Name: count.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 28 Oct 2019 02:40:17 PM CST
 ************************************************************************/

#include "coroutine.h"
#include <stdio.h>
#include <string.h>

static void base(struct schedule * S, void *ud) {
	int *co_id_base = ud;

	*co_id_base = coroutine_running(S);
	coroutine_yield(S);
}

static void func(struct schedule * S, void *ud) {
	int *co_id_func = ud;

	// function start
	char a[3];
	memset(a, 0x0, 3);
	// function end

	*co_id_func = coroutine_running(S);

	coroutine_yield(S);
}

int main() {
	// 创建一个协程调度器
	struct schedule * S = coroutine_open();
	
	// 创建两个协程
	int co_id_base = 0;
	int co_id_func = 0;
	int co_base = coroutine_new(S, base, &co_id_base);
	int co_func = coroutine_new(S, func, &co_id_func);

	printf("count start\n");

	coroutine_resume(S, co_base);
	coroutine_resume(S, co_func);
	
	printf("count end, base: %d, func: %d\n", co_id_base, co_id_func);
	
	printf("count result: %ld, base: %d, func: %d\n", (coroutine_size(S, co_id_func) - coroutine_size(S, co_id_base)), co_id_base, co_id_func);
	
	// 关闭协程调度器
	coroutine_close(S);

	return 0;
}
