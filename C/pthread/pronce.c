#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* 静态初始化 */
//static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
//static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static pthread_once_t once = PTHREAD_ONCE_INIT;

static void once_run(void)
{
	printf("once_run in thread %lu\n", pthread_self());
}

static void* _t1(void* arg)
{
    printf("_t1 thread %lu in...\n", pthread_self());
	
	sleep(2);

    pthread_once(&once, once_run);

    printf("_t1 thread out...\n");

    return NULL;
}

static void* _t2(void* arg)
{
    printf("_t2 thread %lu in...\n", pthread_self());

    pthread_once(&once, once_run);

    printf("_t2 thread out...\n");

    return NULL;
}

int main(int argc, const char *argv[])
{
    printf("main thread in...\n");

    int ret = 0;
    pthread_t pid1, pid2;

    ret = pthread_create(&pid1, NULL, _t1, NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_create error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    ret = pthread_create(&pid2, NULL, _t2, NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_create error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    ret = pthread_join(pid1, NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_join error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    ret = pthread_join(pid2, NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_join error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    printf("main thread out...\n");

    return 0;
}