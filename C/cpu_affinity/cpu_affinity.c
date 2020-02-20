/*************************************************************************
	> File Name: cpu_affinity.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 27 Aug 2019 04:55:20 PM CST
 ************************************************************************/

#ifndef _GNU_SOURCE     
#define _GNU_SOURCE   
#endif

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include "cpu_affinity.h"

#ifdef __ANDROID__
#include <sys/syscall.h>
#endif

/***
 * rm -rf test ./cpu_affinity.o
 * gcc -O2 -std=c99 -fPIC -Wall -Wno-variadic-macros -Wno-format-zero-length -fvisibility=hidden -ffunction-sections -fdata-sections -D_GNU_SOURCE  -c cpu_affinity.c -o cpu_affinity.o
 * g++ cpu_affinity.o -Wl,--gc-sections -lpthread  -o test
 */


/***
 *查看进程当前运行在哪个cpu上:
 *taskset -p pid
 *pid pid's current affinity mask: 3
 *显示的十进制数字3转换为2进制为0011，每个1对应一个cpu，所以进程运行在2个cpu上
 *
 *指定进程运行在cpu1上:
 *taskset -pc 1 pid
 *pid pid's current affinity list: 0,1
 *pid pid's new affinity list: 1
 *注意，cpu的标号是从0开始的，所以cpu1表示第二个cpu（第一个cpu的标号是0）
 *taskset -p pid
 *pid 2726's current affinity mask: 2
 *
 *启动程序时绑定cpu
 *taskset -c 1 ./a.out&
 *taskset -p pid
 *pid pid's current affinity mask: 2
 */

/* 返回系统可以使用的核数，但是其值会包括系统中禁用的核的数目，因此该值并不代表当前系统中可用的核数 */
int get_procs_conf(void) {
    return sysconf(_SC_NPROCESSORS_CONF);
}
#if 0
// android不兼容
int get_procs_conf_1(void) {
    return get_nprocs_conf();
}
#endif

/* 返回值真正的代表了系统当前可用的核数 */
int get_procs(void) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}
#if 0
// android不兼容
int get_procs_1(void) {
    return get_nprocs();
}
#endif

int set_process_affinity(int cpu) {
    if (cpu > (get_procs_conf() -1) || cpu < 0) return -1;

    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);

#ifdef __ANDROID__
    return -1;
#else
    int result = sched_setaffinity(0, sizeof(mask), &mask);
    return result;
#endif
}


int get_process_affinity() {
    cpu_set_t mask;
    CPU_ZERO(&mask);

    int ret = -1;

#ifdef __ANDROID__
    return ret;
#else
    ret = sched_getaffinity(0, sizeof(mask), &mask);
#endif
    if (ret < 0) return ret;

    int i = 0;
    int nProcessNum = get_procs_conf();
    for (i=0;i<nProcessNum;i++) {
		if (CPU_ISSET(i, &mask)) {
            ret = i;
            break;
        }
	}

    return ret;
}

int set_thread_affinity(int cpu) {
    if (cpu > (get_procs_conf() -1) || cpu < 0) return -1;

    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);

#ifdef __ANDROID__
    int syscallres;
    syscallres = syscall(__NR_sched_setaffinity, gettid(), sizeof(mask), &mask);
    return syscallres;
#else
    int result = pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask);
    return result;
#endif
}

int get_thread_affinity() {
    cpu_set_t mask;
    CPU_ZERO(&mask);

    int ret = -1;

#ifdef __ANDROID__
    ret = syscall(__NR_sched_getaffinity, gettid(), sizeof(mask), &mask);
#else
    ret = pthread_getaffinity_np(pthread_self(), sizeof(mask), &mask);
#endif

    if (ret < 0) return ret;
    int i = 0;
    int nProcessNum = get_procs_conf();
    for (i=0;i<nProcessNum;i++) {
		if (CPU_ISSET(i, &mask)) {
            ret = i;
            break;
        }
	}

    return ret;
}

int main(void) {

    printf("get_procs_conf: %d, get_procs: %d\n", get_procs_conf(), get_procs());

    printf("get_process_affinity: %d\n", get_process_affinity());
    printf("set_process_affinity ret: %d\n", set_process_affinity(2));
    printf("get_process_affinity: %d\n", get_process_affinity());

    printf("get_thread_affinity: %d\n", get_thread_affinity());
    printf("set_thread_affinity ret: %d\n", set_thread_affinity(3));
    printf("get_thread_affinity: %d\n", get_thread_affinity());

    printf("get_thread_affinity: %d\n", get_thread_affinity());
    printf("set_thread_affinity ret: %d\n", set_thread_affinity(-1));
    printf("get_thread_affinity: %d\n", get_thread_affinity());

    printf("get_process_affinity: %d\n", get_process_affinity());
    printf("set_process_affinity ret: %d\n", set_process_affinity(4));
    printf("get_process_affinity: %d\n", get_process_affinity());

    return 0;
}
