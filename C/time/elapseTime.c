/*************************************************************************
	> File Name: elapseTime.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: 2023年09月08日 星期五 16时08分52秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

static void elapseFunc()
{
    unsigned int i = 0;
    long long int sum = 1000000;
    long long int tmp = 0;

    for (i = 0; i < sum; i++)
    {
        tmp += i % sum + i / sum;
        if (tmp > sum) tmp = 0;
    }
}

int main(void)
{
    float elapseTime = 0.0f;

    /* 
     * 纳秒级计时程序, 通过clock_gettime获取, 数据类型struct timespec
     * librt库中实现, 编译时需要 -lrt
     * CLOCK_MONOTONIC : 相对时间,稳定,只受jiffiesc(系统启动后的产生的心跳数)影响.
     * CLOCK_REALTIME : 绝对时间, wall clock time,受系统时间影响.
     */

    struct timespec ts_st;
    struct timespec ts_ed;

    // CLOCK_MONOTONIC
    memset(&ts_st, 0x0, sizeof(struct timespec));
    memset(&ts_ed, 0x0, sizeof(struct timespec));

    clock_gettime(CLOCK_MONOTONIC, &ts_st);
    elapseFunc();
    clock_gettime(CLOCK_MONOTONIC, &ts_ed);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec)) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000 / 1000 / 1000);
    printf("clock_gettime CLOCK_MONOTONIC Elapse (s): %.3fs\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000 / 1000);
    printf("clock_gettime CLOCK_MONOTONIC Elapse (ms): %.3fms\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000 / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000);
    printf("clock_gettime CLOCK_MONOTONIC Elapse (us): %.3fus\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000 / 1000 / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec));
    printf("clock_gettime CLOCK_MONOTONIC Elapse (ns): %.3fns\n", elapseTime);
    
    // CLOCK_REALTIME
    memset(&ts_st, 0x0, sizeof(struct timespec));
    memset(&ts_ed, 0x0, sizeof(struct timespec));

    clock_gettime(CLOCK_REALTIME, &ts_st);
    elapseFunc();
    clock_gettime(CLOCK_REALTIME, &ts_ed);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec)) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000 / 1000 / 1000);
    printf("clock_gettime CLOCK_REALTIME Elapse (s): %.3fs\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000 / 1000);
    printf("clock_gettime CLOCK_REALTIME Elapse (ms): %.3fms\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000 / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec) / 1000);
    printf("clock_gettime CLOCK_REALTIME Elapse (us): %.3fus\n", elapseTime);
    elapseTime = ((float)(ts_ed.tv_sec - ts_st.tv_sec) / 1000 / 1000 / 1000) + ((float)(ts_ed.tv_nsec - ts_st.tv_nsec));
    printf("clock_gettime CLOCK_REALTIME Elapse (ns): %.3fns\n", elapseTime);

    /*  
     * 通过gettimeofday获取, 数据类型struct timeval
     */
    
    struct timeval tv_st;
    struct timeval tv_ed;
    struct timezone tz;

    memset(&tv_st, 0x0, sizeof(struct timeval));
    memset(&tv_ed, 0x0, sizeof(struct timeval));
    memset(&tz, 0x0, sizeof(struct timezone));

    gettimeofday(&tv_st, &tz);
    elapseFunc();
    gettimeofday(&tv_ed, &tz);
    elapseTime = ((float)(tv_ed.tv_sec - tv_st.tv_sec)) + ((float)(tv_ed.tv_usec - tv_st.tv_usec) / 1000 / 1000);
    printf("gettimeofday Elapse (s): %.3fs\n", elapseTime);
    elapseTime = ((float)(tv_ed.tv_sec - tv_st.tv_sec) / 1000) + ((float)(tv_ed.tv_usec - tv_st.tv_usec) / 1000);
    printf("gettimeofday Elapse (ms): %.3fms\n", elapseTime);
    elapseTime = ((float)(tv_ed.tv_sec - tv_st.tv_sec) / 1000 / 1000) + ((float)(tv_ed.tv_usec - tv_st.tv_usec));
    printf("gettimeofday Elapse (us): %.3fus\n", elapseTime);
    printf("gettimeofday Elapse (ns): unsupport us\n");

    return 0;
}