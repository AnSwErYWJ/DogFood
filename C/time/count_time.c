/*************************************************************************
	> File Name: count_time.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 01 Nov 2016 04:55:18 PM CST
 ************************************************************************/

/* 纳秒级计时程序 
 * librt库中实现,编译时需要 -lrt
 */

#include<stdio.h>
#include<time.h>

int main(void)
{
    struct timespec start_time,end_time;
    int i = 0;

    /*
     * CLOCK_MONOTONIC : 相对时间,稳定,只受jiffiesc(系统启动后的产生的心跳数)影响.
     * CLOCK_REALTIME : 绝对时间,wall clock time,受系统时间影响.
     */

    clock_gettime(CLOCK_MONOTONIC,&start_time);

    for(i=0;i<1000;i++){}

    clock_gettime(CLOCK_MONOTONIC,&end_time);

    printf("coast time: %f\n",(end_time.tv_sec+end_time.tv_nsec/1.0E9)-(start_time.tv_sec+start_time.tv_nsec/1.0E9));

    return 0;
}
