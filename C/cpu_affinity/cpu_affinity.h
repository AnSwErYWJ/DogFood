/*************************************************************************
	> File Name: cpu_affinity.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 27 Aug 2019 04:55:46 PM CST
 ************************************************************************/

#ifndef __CPU_AFFINITY__H
#define __CPU_AFFINITY__H

#ifdef __cplusplus
extern "C" {
#endif

#include <sched.h>
#include <pthread.h>

#ifndef CPU_ZERO
typedef unsigned long int __cpu_mask;

#define __CPU_SETSIZE 1024

#define __NCPUBITS (8 * sizeof (__cpu_mask))  
#define __CPUELT(cpu) ((cpu) / __NCPUBITS)  
#define __CPUMASK(cpu) ((__cpu_mask) 1UL << ((cpu) % __NCPUBITS))

typedef struct  
{  
	__cpu_mask __bits[__CPU_SETSIZE / __NCPUBITS];  
} cpu_set_t; 

/* 初始化为0 */
#define CPU_ZERO(cpusetp) \
do { \
unsigned int __i; \
cpu_set_t *__arr = (cpusetp); \
for (__i = 0; __i < sizeof (cpu_set_t) / sizeof (__cpu_mask); ++__i) \
__arr->__bits[__i] = 0; \
} while (0)  

/* 设置cpu, 0,1,2,3  */
#define CPU_SET(cpu, cpusetp) \
((cpusetp)->__bits[__CPUELT (cpu)] |= __CPUMASK (cpu))  

/* 删除cpu */
#define CPU_CLR(cpu, cpusetp) \
((cpusetp)->__bits[__CPUELT (cpu)] &= ~__CPUMASK (cpu))  

/* 判断cpu, 如果cpu是CPU集set的一员，这个宏就返回一个非零值（true），否则就返回零（false） */
#define CPU_ISSET(cpu, cpusetp) \
(((cpusetp)->__bits[__CPUELT (cpu)] & __CPUMASK (cpu)) != 0)

#else
//#define CPU_SET(cpu,cpustep) ((void)0)
//#define CPU_ZERO(cpustep)    ((void)0)
#endif

int get_procs_conf(void);
int get_procs(void);

int set_process_affinity(int cpu);
int get_process_affinity();

int set_thread_affinity(int cpu);
int get_thread_affinity();

#ifdef __cplusplus
}
#endif

#endif